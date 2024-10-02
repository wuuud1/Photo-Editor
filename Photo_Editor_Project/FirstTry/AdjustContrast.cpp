#include "MainForm.h"
#include "AdjustContrast.h"
using namespace PhotoEditor;

// ������� ��� ������������ ��������� ����������
Bitmap^ AdjustContrast(Bitmap^ image, float contrast)
{
    // ��������� ������ ���������� ��� ���������� �������� ����������
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // ���������� ������� ������������
    float contrastFactor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    // ������������ ������������ �� ������� ������ ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            Color originalColor = image->GetPixel(x, y);
            // ���������� ����� ������� ������� � ����������� ������������
            int red = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.R - 128) + 128)));
            int green = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.G - 128) + 128)));
            int blue = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.B - 128) + 128)));
            // ��������� ������ ������� � ������ ����������
            Color newColor = Color::FromArgb(red, green, blue);
            // ������������ ������ ������� ��� ������ � �������� ���������
            adjustedImage->SetPixel(x, y, newColor);
        }
    }

    return adjustedImage;
}
