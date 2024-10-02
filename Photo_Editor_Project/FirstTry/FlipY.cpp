#include "MainForm.h"
#include "FlipY.h"
using namespace PhotoEditor;

// Функція для відображення зображення вертикально (по осі Y)
Bitmap^ FlipY(Bitmap^ image)
{
    // Створення нового зображення для збереження відображеного зображення
    Bitmap^ flippedImage = gcnew Bitmap(image->Width, image->Height);

    // Прохід по кожному пікселю вхідного зображення
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // Отримання кольору пікселя з вхідного зображення
            Color originalColor = image->GetPixel(x, y);
            // Встановлення кольору пікселя у відображеному зображенні, перевернутому по осі Y
            flippedImage->SetPixel(x, image->Height - 1 - y, originalColor);
        }
    }

    return flippedImage; // Повернення відображеного зображення
}
