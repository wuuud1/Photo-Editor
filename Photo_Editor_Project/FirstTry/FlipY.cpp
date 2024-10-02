#include "MainForm.h"
#include "FlipY.h"
using namespace PhotoEditor;

// ������� ��� ����������� ���������� ����������� (�� �� Y)
Bitmap^ FlipY(Bitmap^ image)
{
    // ��������� ������ ���������� ��� ���������� ������������ ����������
    Bitmap^ flippedImage = gcnew Bitmap(image->Width, image->Height);

    // ������ �� ������� ������ �������� ����������
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // ��������� ������� ������ � �������� ����������
            Color originalColor = image->GetPixel(x, y);
            // ������������ ������� ������ � ������������ ���������, ������������� �� �� Y
            flippedImage->SetPixel(x, image->Height - 1 - y, originalColor);
        }
    }

    return flippedImage; // ���������� ������������ ����������
}
