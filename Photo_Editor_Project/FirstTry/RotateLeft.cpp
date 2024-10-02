#include "MainForm.h"
#include "RotateLeft.h"
using namespace PhotoEditor;

// Функція для повороту зображення на 90 градусів вліво
Bitmap^ RotateLeft(Bitmap^ image)
{
    // Створення нового зображення для збереження повернутого зображення
    Bitmap^ rotatedImage = gcnew Bitmap(image->Height, image->Width);

    // Прохід по кожному пікселю вхідного зображення
    for (int y = 0; y < image->Height; y++) {
        for (int x = 0; x < image->Width; x++) {
            // Отримання кольору пікселя з вхідного зображення
            Color originalColor = image->GetPixel(x, y);
            // Встановлення кольору пікселя у повернутому зображенні, повернутому на 90 градусів вліво
            rotatedImage->SetPixel(y, image->Width - 1 - x, originalColor);
        }
    }

    return rotatedImage; // Повернення повернутого зображення
}
