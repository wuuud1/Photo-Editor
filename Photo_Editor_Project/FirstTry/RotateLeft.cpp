#include "MainForm.h"
#include "RotateLeft.h"
using namespace PhotoEditor;

// ������� ��� �������� ���������� �� 90 ������� ����
Bitmap^ RotateLeft(Bitmap^ image)
{
    // ��������� ������ ���������� ��� ���������� ����������� ����������
    Bitmap^ rotatedImage = gcnew Bitmap(image->Height, image->Width);

    // ������ �� ������� ������ �������� ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // ��������� ������� ������ � �������� ����������
            Color originalColor = image->GetPixel(x, y);
            // ������������ ������� ������ � ����������� ���������, ����������� �� 90 ������� ����
            rotatedImage->SetPixel(y, image->Width - 1 - x, originalColor);
        }
    }

    return rotatedImage; // ���������� ����������� ����������
}
