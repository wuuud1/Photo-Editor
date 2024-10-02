#include "MainForm.h"
#include "FlipY.h"
using namespace PhotoEditor;

// ������� ��� ����������� ���������� ������������� (�� �� X)
Bitmap^ FlipX(Bitmap^ image)
{
    // ��������� ������ ���������� ��� ���������� ������������ ����������
    Bitmap^ flippedImage = gcnew Bitmap(image->Width, image->Height);

    // ������ �� ������� ������ �������� ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // ��������� ������� ������ � �������� ����������
            Color originalColor = image->GetPixel(x, y);
            // ������������ ������� ������ � ������������ ���������, ������������� �� �� X
            flippedImage->SetPixel(image->Width - 1 - x, y, originalColor);
        }
    }

    return flippedImage; // ���������� ������������ ����������
}
