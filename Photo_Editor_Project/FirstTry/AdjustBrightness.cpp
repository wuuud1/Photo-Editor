#include "MainForm.h"
#include "AdjustBrightness.h"
using namespace PhotoEditor;

// ������� ��� ������������ ��������� ����������
Bitmap^ AdjustBrightness(Bitmap^ image, int brightness)
{
    // ��������� ������ ���������� ��� ���������� �������� ����������
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // ����������� �� ������� ������ ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // ��������� ������� ������
            Color originalColor = image->GetPixel(x, y);
            // ���� ��������� ������� ������� (���������, ��������, �������)
            int red = Math::Min(255, Math::Max(0, originalColor.R + brightness));
            int green = Math::Min(255, Math::Max(0, originalColor.G + brightness));
            int blue = Math::Min(255, Math::Max(0, originalColor.B + brightness));
            // ��������� ������ ������� � ������ ���������� ���������
            Color newColor = Color::FromArgb(red, green, blue);
            // ������������ ������ ������� ��� ������ � �������� ���������
            adjustedImage->SetPixel(x, y, newColor);
        }
    }

    return adjustedImage;
}
