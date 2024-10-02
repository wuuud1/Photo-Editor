#include "MainForm.h"
#include "AdjustContrast.h"
using namespace PhotoEditor;

// Функція для налаштування контрасту зображення
Bitmap^ AdjustContrast(Bitmap^ image, float contrast)
{
    // Створення нового зображення для збереження зміненого зображення
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // Розрахунок фактора контрастності
    float contrastFactor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    // Застосування контрастності до кожного пікселя зображення
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            Color originalColor = image->GetPixel(x, y);
            // Розрахунок нових значень кольорів з урахуванням контрастності
            int red = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.R - 128) + 128)));
            int green = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.G - 128) + 128)));
            int blue = Math::Min(255, Math::Max(0, (int)(contrastFactor * (originalColor.B - 128) + 128)));
            // Створення нового кольору з новими значеннями
            Color newColor = Color::FromArgb(red, green, blue);
            // Встановлення нового кольору для пікселя у зміненому зображенні
            adjustedImage->SetPixel(x, y, newColor);
        }
    }

    return adjustedImage;
}
