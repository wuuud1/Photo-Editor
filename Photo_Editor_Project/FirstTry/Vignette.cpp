#include "MainForm.h"
#include "Vignette.h"
using namespace PhotoEditor;

Bitmap^ ApplyVignette(Bitmap^ image) {
    // ��������� ������ �� ������ ����������
    int width = image->Width;
    int height = image->Height;
    // ��������� ������ ���������� ��� �������
    Bitmap^ vignetteImage = gcnew Bitmap(width, height);

    // ����� ����������
    int centerX = width / 2;
    int centerY = height / 2;

    // ����������� ������� �� ������
    double maxDistance = Math::Sqrt(centerX * centerX + centerY * centerY);

    // ������ �� ������� ������ ����������
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Color pixel = image->GetPixel(x, y);

            // ³������ �� ������
            double distance = Math::Sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));

            // ������ ������� �� ����� ������
            double vignetteFactor = 1.2 - (distance / maxDistance);
            vignetteFactor = Math::Pow(vignetteFactor, 1); // �������� ����� �������

            // ������������ ������� �� ������� ������
            int r = Math::Max(0, Math::Min(255, static_cast<int>(pixel.R * vignetteFactor)));
            int g = Math::Max(0, Math::Min(255, static_cast<int>(pixel.G * vignetteFactor)));
            int b = Math::Max(0, Math::Min(255, static_cast<int>(pixel.B * vignetteFactor)));

            // ������������ ������ ������� ������ � ��������� �������
            vignetteImage->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    return vignetteImage; // ���������� ���������� � ��������
}
