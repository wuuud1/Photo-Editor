#include "MainForm.h"
#include "Vignette.h"
using namespace PhotoEditor;

Bitmap^ ApplyVignette(Bitmap^ image) {
    // Отримання ширини та висоти зображення
    int width = image->Width;
    int height = image->Height;
    // Створення нового зображення для віньєтки
    Bitmap^ vignetteImage = gcnew Bitmap(width, height);

    // Центр зображення
    int centerX = width / 2;
    int centerY = height / 2;

    // Максимальна відстань від центру
    double maxDistance = Math::Sqrt(centerX * centerX + centerY * centerY);

    // Прохід по кожному пікселю зображення
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Color pixel = image->GetPixel(x, y);

            // Відстань від центру
            double distance = Math::Sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));

            // Фактор віньєтки на основі відстані
            double vignetteFactor = 1.2 - (distance / maxDistance);
            vignetteFactor = Math::Pow(vignetteFactor, 1); // Посилити ефект віньєтки

            // Застосування віньєтки до кольорів пікселя
            int r = Math::Max(0, Math::Min(255, static_cast<int>(pixel.R * vignetteFactor)));
            int g = Math::Max(0, Math::Min(255, static_cast<int>(pixel.G * vignetteFactor)));
            int b = Math::Max(0, Math::Min(255, static_cast<int>(pixel.B * vignetteFactor)));

            // Встановлення нового кольору пікселя у зображенні віньєтки
            vignetteImage->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    return vignetteImage; // Повернення зображення з віньєткою
}
