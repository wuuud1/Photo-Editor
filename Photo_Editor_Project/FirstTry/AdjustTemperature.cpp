#include "MainForm.h"
#include "AdjustTemperature.h"
using namespace PhotoEditor;

// Функція для налаштування кольорової температури зображення
Bitmap^ AdjustTemperature(Bitmap^ image, int temperature)
{
    // Створення нового зображення для збереження зміненого зображення
    Bitmap^ adjustedImage = gcnew Bitmap(image->Width, image->Height);

    // Перевірка чи температура менше 0 (холодний фільтр) або більше 0 (теплий фільтр)
    if (temperature < 0) {
        // Якщо температура менше 0, змінюємо кольори відтінком холодніше
        for (int y = 0; y < image->Height; y++) {
            for (int x = 0; x < image->Width; x++) {
                Color originalColor = image->GetPixel(x, y);
                // Зменшуємо червоний та збільшуємо синій відтінки
                int red = Math::Max(0, originalColor.R - 10);
                int blue = Math::Min(255, originalColor.B + 10);
                // Створення нового кольору з новими значеннями
                Color newColor = Color::FromArgb(red, originalColor.G, blue);
                // Встановлення нового кольору для пікселя у зміненому зображенні
                adjustedImage->SetPixel(x, y, newColor);
            }
        }
    }
    else {
        // Якщо температура більше 0, змінюємо кольори відтінком тепліше
        for (int y = 0; y < image->Height; y++) {
            for (int x = 0; x < image->Width; x++) {
                Color originalColor = image->GetPixel(x, y);
                // Збільшуємо червоний та зменшуємо синій відтінки
                int red = Math::Min(255, originalColor.R + temperature);
                int blue = Math::Max(0, originalColor.B - temperature);
                // Створення нового кольору з новими значеннями
                Color newColor = Color::FromArgb(red, originalColor.G, blue);
                // Встановлення нового кольору для пікселя у зміненому зображенні
                adjustedImage->SetPixel(x, y, newColor);
            }
        }
    }

    return adjustedImage;
}


