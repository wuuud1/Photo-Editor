#include "MainForm.h"
#include "AdjustBrightness.h"
using namespace PhotoEditor;

// Функція для налаштування яскравості зображення
Bitmap^ AdjustBrightness(Bitmap^ image, int brightness)
{
    // Створення нового зображення для збереження зміненого зображення
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // Проходження по кожному пікселю зображення
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // Отримання кольору пікселя
            Color originalColor = image->GetPixel(x, y);
            // Зміна яскравості кожного кольору (червоного, зеленого, синього)
            int red = Math::Min(255, Math::Max(0, originalColor.R + brightness));
            int green = Math::Min(255, Math::Max(0, originalColor.G + brightness));
            int blue = Math::Min(255, Math::Max(0, originalColor.B + brightness));
            // Створення нового кольору з новими значеннями яскравості
            Color newColor = Color::FromArgb(red, green, blue);
            // Встановлення нового кольору для пікселя у зміненому зображенні
            adjustedImage->SetPixel(x, y, newColor);
        }
    }

    return adjustedImage;
}
