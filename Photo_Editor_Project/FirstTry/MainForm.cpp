#include "MainForm.h"
#include "AdjustContrast.h"
#include "AdjustBrightness.h"
#include "FlipY.h"
#include "FlipX.h"
#include "RotateLeft.h"
#include "RotateRight.h"
#include "Sepia.h"
#include "Vignette.h"
#include "AdjustTemperature.h"

using namespace PhotoEditor;

//Зберігає поточний стан зображення у стек undoStack для можливості скасування (Undo). 
//Також очищує redoStack, оскільки нова дія перериває послідовність можливих повторень (Redo).
System::Void MainForm::SaveImageState() {
    // Перевірка, чи є зображення в pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Перетворення поточного зображення на об'єкт Bitmap
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // Якщо ми знаходимося в середині історії, видаляємо майбутні стани
        while (imageHistory->Count > currentHistoryIndex + 1) {
            imageHistory->RemoveAt(imageHistory->Count - 1);
        }

        // Додавання поточного стану зображення до списку історії
        imageHistory->Add(currentImage);
        currentHistoryIndex++;

        // Обмеження розміру списку історії максимум до 10 станів
        if (imageHistory->Count > 10) {
            imageHistory->RemoveAt(0); // Видаляємо найстаріший стан
            currentHistoryIndex--;
        }
    }
}


//Відкриває діалогове вікно для вибору зображення з файлової системи. 
//Завантажує вибране зображення та відображає його у PictureBox
System::Void MainForm::openItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // Збереження поточного стану зображення перед відкриттям нового
    SaveImageState();

    // Створення та налаштування діалогового вікна для вибору файлу
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.png;*.gif"; // Фільтр для файлів зображень
    openFileDialog->Multiselect = false; // Дозволити вибір лише одного файлу

    // Відображення діалогового вікна і перевірка, чи було обрано файл
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Отримання шляху до обраного файлу
        String^ selectedFile = openFileDialog->FileName;
        // Отримання шляху до папки, в якій знаходиться обраний файл
        String^ folderPath = System::IO::Path::GetDirectoryName(selectedFile);

        // Використання Directory::GetFiles для отримання всіх файлів зображень у папці
        array<String^>^ extensions = gcnew array<String^> { "*.bmp", "*.jpg", "*.jpeg", "*.png", "*.gif" };
        array<String^>^ tempFiles = gcnew array<String^>(0);

        // Перебір всіх розширень і додавання відповідних файлів у список
        for each (String ^ extension in extensions) {
            array<String^>^ files = System::IO::Directory::GetFiles(folderPath, extension);
            array<String^>::Resize(tempFiles, tempFiles->Length + files->Length);
            Array::Copy(files, 0, tempFiles, tempFiles->Length - files->Length, files->Length);
        }

        // Збереження списку файлів зображень і встановлення індексу поточного зображення
        imageFiles = tempFiles;
        currentImageIndex = Array::IndexOf(imageFiles, selectedFile);

        // Завантаження обраного зображення і відображення його у pictureBox
        Bitmap^ loadedImage = gcnew Bitmap(selectedFile);
        pictureBox1->Image = loadedImage;
        pictureBox1->SizeMode = PictureBoxSizeMode::Zoom; // Встановлення режиму масштабування для pictureBox
    }
}




//Відкриває діалогове вікно для збереження поточного зображення у вказане користувачем місце на файловій системі.
System::Void MainForm::saveAsItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Створення та налаштування діалогового вікна для збереження файлу
        SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
        saveFileDialog->Filter = "JPEG Image|*.jpg|PNG Image|*.png|Bitmap Image|*.bmp"; // Фільтри для файлів зображень
        saveFileDialog->Title = "Save Edited Image"; // Заголовок діалогового вікна

        // Відображення діалогового вікна і перевірка, чи користувач вибрав місце для збереження файлу
        if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Збереження зображення з pictureBox1 у вибране місце
            pictureBox1->Image->Save(saveFileDialog->FileName);
        }
    }
}



//Застосовує ефект градацій сірого (grayscale) до поточного зображення.
System::Void MainForm::bGrayScale_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення для можливості відкату (undo)
        SaveImageState();

        // Створення об'єкта Bitmap на основі поточного зображення в pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);
        // Створення нового порожнього Bitmap для збереження зображення в відтінках сірого
        Bitmap^ grayscaleImage = gcnew Bitmap(originalImage->Width, originalImage->Height);

        // Перебір кожного пікселя оригінального зображення
        for (int y = 0; y < originalImage->Height; y++) {
            for (int x = 0; x < originalImage->Width; x++) {
                // Отримання кольору поточного пікселя
                Color originalColor = originalImage->GetPixel(x, y);
                // Обчислення значення сірого відтінку з використанням формули лінійного перетворення
                int grayScale = (int)((originalColor.R * 0.3) + (originalColor.G * 0.59) + (originalColor.B * 0.11));
                // Створення нового кольору з однаковими значеннями для R, G та B, що дає відтінок сірого
                Color newColor = Color::FromArgb(grayScale, grayScale, grayScale);
                // Установка нового кольору пікселя в зображення в відтінках сірого
                grayscaleImage->SetPixel(x, y, newColor);
            }
        }
        // Відображення зображення в відтінках сірого в pictureBox1
        pictureBox1->Image = grayscaleImage;
    }
}


//Зменшує колірну температуру зображення, що призводить до збільшення синіх відтінків.
System::Void MainForm::bTemperature_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення для можливості відкату (undo)
        SaveImageState();

        // Створення об'єкта Bitmap на основі поточного зображення в pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Виклик функції AdjustTemperature для зменшення температури зображення
        // В даному випадку, зменшення температури на 10 одиниць
        Bitmap^ temperatureImage = AdjustTemperature(originalImage, -10);

        // Відображення зображення із зменшеною температурою в pictureBox1
        pictureBox1->Image = temperatureImage;
    }
}

//Збільшує колірну температуру зображення, що призводить до збільшення червоних і жовтих відтінків.
System::Void MainForm::bTemperature_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення для можливості відкату (undo)
        SaveImageState();

        // Створення об'єкта Bitmap на основі поточного зображення в pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Виклик функції AdjustTemperature для зменшення температури зображення
        // В даному випадку, збільшення температури на 10 одиниць
        Bitmap^ temperatureImage = AdjustTemperature(originalImage, 10);

        // Відображення зображення із збільшеною температурою в pictureBox1
        pictureBox1->Image = temperatureImage;
    }
}



//Зменшує контрастність зображення.
System::Void MainForm::bContrast_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення для можливості відкату (undo)
        SaveImageState();

        // Створення об'єкта Bitmap на основі поточного зображення в pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Виклик функції AdjustContrast для збільшення контрастності зображення
        // В даному випадку, збільшення контрастності на 10 одиниць
        Bitmap^ contrastImage = AdjustContrast(originalImage, 10.0f);

        // Відображення зображення із збільшеною контрастністю в pictureBox1
        pictureBox1->Image = contrastImage;
    }
}

//Збільшує контрастність зображення.
System::Void MainForm::bContrast_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи є зображення у pictureBox1
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення для можливості відкату (undo)
        SaveImageState();

        // Створення об'єкта Bitmap на основі поточного зображення в pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Виклик функції AdjustContrast для зменшення контрастності зображення
        // В даному випадку, зменшення контрастності на 10 одиниць
        Bitmap^ contrastImage = AdjustContrast(originalImage, -10.0f);

        // Відображення зображення із зменшеною контрастністю в pictureBox1
        pictureBox1->Image = contrastImage;
    }
}



//Відміняє останню дію користувача, відновлюючи попередній стан зображення зі стеку undoStack.
System::Void MainForm::bUndo_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи можливо виконати дію "Undo"
    if (currentHistoryIndex > 0) {
        // Зменшення індексу історії, щоб повернутися до попереднього стану зображення
        currentHistoryIndex--;

        // Встановлення зображення у pictureBox1 відповідно до поточного індексу історії
        pictureBox1->Image = gcnew Bitmap(imageHistory[currentHistoryIndex]);
    }
}


//Повторює останню скасовану дію користувача, відновлюючи стан зображення зі стеку redoStack.
System::Void MainForm::bRedo_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи можливо виконати дію "Redo"
    if (currentHistoryIndex < imageHistory->Count - 1) {
        // Збільшення індексу історії, щоб перейти до наступного стану зображення
        currentHistoryIndex++;

        // Встановлення зображення у pictureBox1 відповідно до поточного індексу історії
        pictureBox1->Image = gcnew Bitmap(imageHistory[currentHistoryIndex]);
    }
}

//Збільшує яскравість зображення
System::Void MainForm::bBrightness_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Збільшення яскравості на 20 одиниць
        Bitmap^ brightnessImage = AdjustBrightness(originalImage, 20);

        // Встановлення зображення з новою яскравістю
        pictureBox1->Image = brightnessImage;
    }
}

//Зменшує яскравість зображення
System::Void MainForm::bBrightness_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Зменшення яскравості на 20 одиниць
        Bitmap^ brightnessImage = AdjustBrightness(originalImage, -20);

        // Встановлення зображення з новою яскравістю
        pictureBox1->Image = brightnessImage;
    }
}

//Дзеркально відображає зображення по вертикалі(осі У)
System::Void MainForm::bFlipY_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Відображення зображення по вертикалі
        Bitmap^ flippedImage = FlipY(originalImage);

        // Встановлення зображення з відображенням по вертикалі
        pictureBox1->Image = flippedImage;
    }
}

//Дзеркально відображає зображення по горизонталі(осі Х)
System::Void MainForm::bFlipX_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Відображення зображення по горизонталі
        Bitmap^ flippedImage = FlipX(originalImage);

        // Встановлення зображення з відображенням по горизонталі
        pictureBox1->Image = flippedImage;
    }
}


// Функція для повороту зображення вліво на 90 градусів
System::Void MainForm::bRotate_left_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Поворот зображення вліво
        Bitmap^ rotatedImage = RotateLeft(originalImage);

        // Встановлення зображення з поворотом вліво
        pictureBox1->Image = rotatedImage;
    }
}


// Функція для повороту зображення вправо на 90 градусів
System::Void MainForm::bRotate_right_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // Поворот зображення вправо на 90 градусів
        Bitmap^ rotatedImage = RotateRight(originalImage);

        // Встановлення зображення з поворотом вправо на 90 градусів
        pictureBox1->Image = rotatedImage;
    }
}




// Функція для застосування ефекту сепії до зображення
System::Void MainForm::bSepia_effect_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // Застосування ефекту сепії до зображення
        Bitmap^ sepiaImage = ApplySepia(currentImage);

        // Встановлення зображення з ефектом сепії
        pictureBox1->Image = sepiaImage;
    }
}


// Функція для застосування ефекту віньєту до зображення
System::Void MainForm::bVigentte_effect_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи зображення існує
    if (pictureBox1->Image != nullptr) {
        // Збереження поточного стану зображення перед змінами
        SaveImageState();

        // Створення копії зображення для обробки
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // Застосування ефекту віньєту до зображення
        Bitmap^ vignetteImage = ApplyVignette(currentImage);

        // Встановлення зображення з ефектом віньєту
        pictureBox1->Image = vignetteImage;
    }
}

// Функція для завантаження наступного зображення з папки
System::Void MainForm::bNext_image_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи масив файлів існує і чи не досягнуто кінця масиву
    if (imageFiles != nullptr && currentImageIndex < imageFiles->Length - 1) {
        // Збільшення індексу поточного зображення
        currentImageIndex++;

        // Завантаження наступного зображення з масиву файлів
        Bitmap^ nextImage = gcnew Bitmap(imageFiles[currentImageIndex]);

        // Встановлення зображення в PictureBox
        pictureBox1->Image = nextImage;
    }
}


// Функція для завантаження попереднього зображення з папки
System::Void MainForm::bPrevious_image_Click(System::Object^ sender, System::EventArgs^ e) {
    // Перевірка, чи масив файлів існує і чи не досягнуто початку масиву
    if (imageFiles != nullptr && currentImageIndex > 0) {
        // Зменшення індексу поточного зображення
        currentImageIndex--;

        // Завантаження попереднього зображення з масиву файлів
        Bitmap^ previousImage = gcnew Bitmap(imageFiles[currentImageIndex]);

        // Встановлення зображення в PictureBox
        pictureBox1->Image = previousImage;
    }
}

// Обробник події для натискання кнопки "Допомога"
System::Void MainForm::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // Текстове повідомлення із інструкціями користування програмою
    String^ helpMessage =
        "PhotoEditor - Допомога\n\n" +
        "Для того, щоб завантажити зображення у фоторедактор, необхідно перейти у вкладку File->Open\n" +
        "Також там ви зможете знайти функцію для збереження відредагованої фотографії(File->Save as)\n\n" +
        "У вкладці Action, ви можете відзеркалити фотографію по осі X та Y, а також повернути її за годинниковою стрілкою та проти неї.\n\n" +
        "У тій же смузі вам доступний вибір трьох заготовлених фільтрів для використання їх до фотографії\n\n" +
        "Справа, у вас є можливість змінити три показники:\n" +
        "Колірну температуру, контраст та яскравість фотографії\n\n" +
        "Справа внизу, знаходять дві кнопки, які дадуть вам можливість переміщатися між фотографіями, з директорії, з якої завантажена певна фотографія\n";

    // Показ вікна з інформацією
    MessageBox::Show(helpMessage, "Help", MessageBoxButtons::OK, MessageBoxIcon::Information);
}


// Обробник події для натискання кнопки "Про програму"
System::Void MainForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // Текстове повідомлення із інформацією про програму та автора
    String^ AboutMessage =
        "PhotoEditor - Про фоторедактор\n\n" +
        "Курсовий проект з предмету Системне програмне забезпечення.\n\n" +
        "Ця програма дозволяє виконувати різні базові дії з обробкою фотографій, та дає можливість зберегти змінену фотографію у вибране місце.\n\n" +
        "Проект зроблений з використанням .NET складавої для відображення користувацького інтерфейсу, та використовує C++ для виконання обчислень з матрицями(фотографіями)\n\n" +
        "Автор - студент групи КІ-305: Гнідець Володимир.\n";

    // Показ вікна з інформацією
    MessageBox::Show(AboutMessage, "About", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

