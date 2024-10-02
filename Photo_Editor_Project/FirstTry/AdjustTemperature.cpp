#include "MainForm.h"
#include "AdjustTemperature.h"
using namespace PhotoEditor;

// ������� ��� ������������ ��������� ����������� ����������
Bitmap^ AdjustTemperature(Bitmap^ image, int temperature)
{
    // ��������� ������ ���������� ��� ���������� �������� ����������
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // �������� �� ����������� ����� 0 (�������� ������) ��� ����� 0 (������ ������)
    if (temperature < 0) {
        // ���� ����������� ����� 0, ������� ������� ������� ��������
        for (int y = 0; y < image->Height; y++) {
            for (int x = 0; x < image->Width; x++) {
                Color originalColor = image->GetPixel(x, y);
                // �������� �������� �� �������� ���� ������
                int red = Math::Max(0, originalColor.R - 10);
                int blue = Math::Min(255, originalColor.B + 10);
                // ��������� ������ ������� � ������ ����������
                Color newColor = Color::FromArgb(red, originalColor.G, blue);
                // ������������ ������ ������� ��� ������ � �������� ���������
                adjustedImage->SetPixel(x, y, newColor);
            }
        }
    }
    else {
        // ���� ����������� ����� 0, ������� ������� ������� ������
        for (int y = 0; y < image->Height; y++) {
            for (int x = 0; x < image->Width; x++) {
                Color originalColor = image->GetPixel(x, y);
                // �������� �������� �� �������� ���� ������
                int red = Math::Min(255, originalColor.R + temperature);
                int blue = Math::Max(0, originalColor.B - temperature);
                // ��������� ������ ������� � ������ ����������
                Color newColor = Color::FromArgb(red, originalColor.G, blue);
                // ������������ ������ ������� ��� ������ � �������� ���������
                adjustedImage->SetPixel(x, y, newColor);
            }
        }
    }

    return adjustedImage;
}


