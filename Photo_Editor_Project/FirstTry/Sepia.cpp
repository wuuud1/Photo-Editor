#include "MainForm.h"
#include "Sepia.h"
using namespace PhotoEditor;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

Bitmap^ ApplySepia(Bitmap^ image) {
    // ��������� ������ �� ������ ����������
    int width = image->Width;
    int height = image->Height;
    // ��������� ������ ���������� ��� ������ ��ﳿ
    Bitmap^ sepiaImage = gcnew Bitmap(width, height);

    // ������ �� ������� ������ ����������
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Color pixel = image->GetPixel(x, y);

            // ���������� ����� ������� RGB
            int tr = (int)(0.393 * pixel.R + 0.769 * pixel.G + 0.189 * pixel.B);
            int tg = (int)(0.349 * pixel.R + 0.686 * pixel.G + 0.168 * pixel.B);
            int tb = (int)(0.272 * pixel.R + 0.534 * pixel.G + 0.131 * pixel.B);

            // ��������� ������� � ����� �� 0 �� 255
            int r = Math::Min(255, tr);
            int g = Math::Min(255, tg);
            int b = Math::Min(255, tb);

            // ������������ ������ ������� ������ � ��������� ��ﳿ
            sepiaImage->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    return sepiaImage; // ���������� ���������� � ������� ��ﳿ
}
