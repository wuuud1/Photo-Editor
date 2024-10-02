#include "MainForm.h"
#include "RotateRight.h"
using namespace PhotoEditor;

// ������� ��� �������� ���������� �� 90 ������� ������
Bitmap^ RotateRight(Bitmap^ image)
{
    // ��������� ������ ���������� ��� ���������� ����������� ����������
    Bitmap^ rotatedImage = gcnew Bitmap(image->Height, image->Width);

    // ������ �� ������� ������ �������� ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // ��������� ������� ������ � �������� ����������
            Color originalColor = image->GetPixel(x, y);
            // ������������ ������� ������ � ����������� ���������, ����������� �� 90 ������� ������
            rotatedImage->SetPixel(image->Height - 1 - y, x, originalColor);
        }
    }

    return rotatedImage; // ���������� ����������� ����������
}
