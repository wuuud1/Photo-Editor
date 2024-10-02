#include "MainForm.h"
#include "Sepia.h"
using namespace PhotoEditor;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

Bitmap^ ApplySepia(Bitmap^ image) {
    // Отримання ширини та висоти зображення
    int width = image->Width;
    int height = image->Height;
    // Створення нового зображення для ефекту сепії
    Bitmap^ sepiaImage = gcnew Bitmap(width, height);

    // Прохід по кожному пікселю зображення
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Color pixel = image->GetPixel(x, y);

            // Обчислення нових значень RGB
            int tr = (int)(0.393 * pixel.R + 0.769 * pixel.G + 0.189 * pixel.B);
            int tg = (int)(0.349 * pixel.R + 0.686 * pixel.G + 0.168 * pixel.B);
            int tb = (int)(0.272 * pixel.R + 0.534 * pixel.G + 0.131 * pixel.B);

            // Обмеження значень в межах від 0 до 255
            int r = Math::Min(255, tr);
            int g = Math::Min(255, tg);
            int b = Math::Min(255, tb);

            // Встановлення нового кольору пікселя у зображенні сепії
            sepiaImage->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }

    return sepiaImage; // Повернення зображення з ефектом сепії
}
