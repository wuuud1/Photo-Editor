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

//������ �������� ���� ���������� � ���� undoStack ��� ��������� ���������� (Undo). 
//����� ����� redoStack, ������� ���� �� �������� ����������� �������� ��������� (Redo).
System::Void MainForm::SaveImageState() {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ������������ ��������� ���������� �� ��'��� Bitmap
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // ���� �� ����������� � ������� �����, ��������� ������� �����
        while (imageHistory->Count > currentHistoryIndex + 1) {
            imageHistory->RemoveAt(imageHistory->Count - 1);
        }

        // ��������� ��������� ����� ���������� �� ������ �����
        imageHistory->Add(currentImage);
        currentHistoryIndex++;

        // ��������� ������ ������ ����� �������� �� 10 �����
        if (imageHistory->Count > 10) {
            imageHistory->RemoveAt(0); // ��������� ���������� ����
            currentHistoryIndex--;
        }
    }
}


//³������ �������� ���� ��� ������ ���������� � ������� �������. 
//��������� ������� ���������� �� �������� ���� � PictureBox
System::Void MainForm::openItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // ���������� ��������� ����� ���������� ����� ��������� ������
    SaveImageState();

    // ��������� �� ������������ ���������� ���� ��� ������ �����
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.png;*.gif"; // Գ���� ��� ����� ���������
    openFileDialog->Multiselect = false; // ��������� ���� ���� ������ �����

    // ³���������� ���������� ���� � ��������, �� ���� ������ ����
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // ��������� ����� �� �������� �����
        String^ selectedFile = openFileDialog->FileName;
        // ��������� ����� �� �����, � ��� ����������� ������� ����
        String^ folderPath = System::IO::Path::GetDirectoryName(selectedFile);

        // ������������ Directory::GetFiles ��� ��������� ��� ����� ��������� � �����
        array<String^>^ extensions = gcnew array<String^> { "*.bmp", "*.jpg", "*.jpeg", "*.png", "*.gif" };
        array<String^>^ tempFiles = gcnew array<String^>(0);

        // ������ ��� ��������� � ��������� ��������� ����� � ������
        for each (String ^ extension in extensions) {
            array<String^>^ files = System::IO::Directory::GetFiles(folderPath, extension);
            array<String^>::Resize(tempFiles, tempFiles->Length + files->Length);
            Array::Copy(files, 0, tempFiles, tempFiles->Length - files->Length, files->Length);
        }

        // ���������� ������ ����� ��������� � ������������ ������� ��������� ����������
        imageFiles = tempFiles;
        currentImageIndex = Array::IndexOf(imageFiles, selectedFile);

        // ������������ �������� ���������� � ����������� ���� � pictureBox
        Bitmap^ loadedImage = gcnew Bitmap(selectedFile);
        pictureBox1->Image = loadedImage;
        pictureBox1->SizeMode = PictureBoxSizeMode::Zoom; // ������������ ������ ������������� ��� pictureBox
    }
}




//³������ �������� ���� ��� ���������� ��������� ���������� � ������� ������������ ���� �� ������� ������.
System::Void MainForm::saveAsItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ��������� �� ������������ ���������� ���� ��� ���������� �����
        SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
        saveFileDialog->Filter = "JPEG Image|*.jpg|PNG Image|*.png|Bitmap Image|*.bmp"; // Գ����� ��� ����� ���������
        saveFileDialog->Title = "Save Edited Image"; // ��������� ���������� ����

        // ³���������� ���������� ���� � ��������, �� ���������� ������ ���� ��� ���������� �����
        if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // ���������� ���������� � pictureBox1 � ������� ����
            pictureBox1->Image->Save(saveFileDialog->FileName);
        }
    }
}



//��������� ����� �������� ����� (grayscale) �� ��������� ����������.
System::Void MainForm::bGrayScale_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ��� ��������� ������ (undo)
        SaveImageState();

        // ��������� ��'���� Bitmap �� ����� ��������� ���������� � pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);
        // ��������� ������ ���������� Bitmap ��� ���������� ���������� � ������� �����
        Bitmap^ grayscaleImage = gcnew Bitmap(originalImage->Width, originalImage->Height);

        // ������ ������� ������ ������������ ����������
        for (int y = 0; y < originalImage->Height; y++) {
            for (int x = 0; x < originalImage->Width; x++) {
                // ��������� ������� ��������� ������
                Color originalColor = originalImage->GetPixel(x, y);
                // ���������� �������� ����� ������ � ������������� ������� ������� ������������
                int grayScale = (int)((originalColor.R * 0.3) + (originalColor.G * 0.59) + (originalColor.B * 0.11));
                // ��������� ������ ������� � ���������� ���������� ��� R, G �� B, �� �� ������ �����
                Color newColor = Color::FromArgb(grayScale, grayScale, grayScale);
                // ��������� ������ ������� ������ � ���������� � ������� �����
                grayscaleImage->SetPixel(x, y, newColor);
            }
        }
        // ³���������� ���������� � ������� ����� � pictureBox1
        pictureBox1->Image = grayscaleImage;
    }
}


//������ ������ ����������� ����������, �� ���������� �� ��������� ���� ������.
System::Void MainForm::bTemperature_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ��� ��������� ������ (undo)
        SaveImageState();

        // ��������� ��'���� Bitmap �� ����� ��������� ���������� � pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������ ������� AdjustTemperature ��� ��������� ����������� ����������
        // � ������ �������, ��������� ����������� �� 10 �������
        Bitmap^ temperatureImage = AdjustTemperature(originalImage, -10);

        // ³���������� ���������� �� ��������� ������������ � pictureBox1
        pictureBox1->Image = temperatureImage;
    }
}

//������ ������ ����������� ����������, �� ���������� �� ��������� �������� � ������ ������.
System::Void MainForm::bTemperature_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ��� ��������� ������ (undo)
        SaveImageState();

        // ��������� ��'���� Bitmap �� ����� ��������� ���������� � pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������ ������� AdjustTemperature ��� ��������� ����������� ����������
        // � ������ �������, ��������� ����������� �� 10 �������
        Bitmap^ temperatureImage = AdjustTemperature(originalImage, 10);

        // ³���������� ���������� �� ��������� ������������ � pictureBox1
        pictureBox1->Image = temperatureImage;
    }
}



//������ ������������ ����������.
System::Void MainForm::bContrast_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ��� ��������� ������ (undo)
        SaveImageState();

        // ��������� ��'���� Bitmap �� ����� ��������� ���������� � pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������ ������� AdjustContrast ��� ��������� ������������ ����������
        // � ������ �������, ��������� ������������ �� 10 �������
        Bitmap^ contrastImage = AdjustContrast(originalImage, 10.0f);

        // ³���������� ���������� �� ��������� ������������ � pictureBox1
        pictureBox1->Image = contrastImage;
    }
}

//������ ������������ ����������.
System::Void MainForm::bContrast_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� � ���������� � pictureBox1
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ��� ��������� ������ (undo)
        SaveImageState();

        // ��������� ��'���� Bitmap �� ����� ��������� ���������� � pictureBox1
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������ ������� AdjustContrast ��� ��������� ������������ ����������
        // � ������ �������, ��������� ������������ �� 10 �������
        Bitmap^ contrastImage = AdjustContrast(originalImage, -10.0f);

        // ³���������� ���������� �� ��������� ������������ � pictureBox1
        pictureBox1->Image = contrastImage;
    }
}



//³����� ������� �� �����������, ���������� ��������� ���� ���������� � ����� undoStack.
System::Void MainForm::bUndo_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ������� �������� �� "Undo"
    if (currentHistoryIndex > 0) {
        // ��������� ������� �����, ��� ����������� �� ������������ ����� ����������
        currentHistoryIndex--;

        // ������������ ���������� � pictureBox1 �������� �� ��������� ������� �����
        pictureBox1->Image = gcnew Bitmap(imageHistory[currentHistoryIndex]);
    }
}


//�������� ������� ��������� �� �����������, ���������� ���� ���������� � ����� redoStack.
System::Void MainForm::bRedo_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ������� �������� �� "Redo"
    if (currentHistoryIndex < imageHistory->Count - 1) {
        // ��������� ������� �����, ��� ������� �� ���������� ����� ����������
        currentHistoryIndex++;

        // ������������ ���������� � pictureBox1 �������� �� ��������� ������� �����
        pictureBox1->Image = gcnew Bitmap(imageHistory[currentHistoryIndex]);
    }
}

//������ ��������� ����������
System::Void MainForm::bBrightness_increase_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ��������� ��������� �� 20 �������
        Bitmap^ brightnessImage = AdjustBrightness(originalImage, 20);

        // ������������ ���������� � ����� ���������
        pictureBox1->Image = brightnessImage;
    }
}

//������ ��������� ����������
System::Void MainForm::bBrightness_decrease_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ��������� ��������� �� 20 �������
        Bitmap^ brightnessImage = AdjustBrightness(originalImage, -20);

        // ������������ ���������� � ����� ���������
        pictureBox1->Image = brightnessImage;
    }
}

//���������� �������� ���������� �� ��������(�� �)
System::Void MainForm::bFlipY_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ³���������� ���������� �� ��������
        Bitmap^ flippedImage = FlipY(originalImage);

        // ������������ ���������� � ������������ �� ��������
        pictureBox1->Image = flippedImage;
    }
}

//���������� �������� ���������� �� ����������(�� �)
System::Void MainForm::bFlipX_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ³���������� ���������� �� ����������
        Bitmap^ flippedImage = FlipX(originalImage);

        // ������������ ���������� � ������������ �� ����������
        pictureBox1->Image = flippedImage;
    }
}


// ������� ��� �������� ���������� ���� �� 90 �������
System::Void MainForm::bRotate_left_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������� ���������� ����
        Bitmap^ rotatedImage = RotateLeft(originalImage);

        // ������������ ���������� � ��������� ����
        pictureBox1->Image = rotatedImage;
    }
}


// ������� ��� �������� ���������� ������ �� 90 �������
System::Void MainForm::bRotate_right_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ originalImage = gcnew Bitmap(pictureBox1->Image);

        // ������� ���������� ������ �� 90 �������
        Bitmap^ rotatedImage = RotateRight(originalImage);

        // ������������ ���������� � ��������� ������ �� 90 �������
        pictureBox1->Image = rotatedImage;
    }
}




// ������� ��� ������������ ������ ��ﳿ �� ����������
System::Void MainForm::bSepia_effect_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // ������������ ������ ��ﳿ �� ����������
        Bitmap^ sepiaImage = ApplySepia(currentImage);

        // ������������ ���������� � ������� ��ﳿ
        pictureBox1->Image = sepiaImage;
    }
}


// ������� ��� ������������ ������ ������ �� ����������
System::Void MainForm::bVigentte_effect_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ���������� ����
    if (pictureBox1->Image != nullptr) {
        // ���������� ��������� ����� ���������� ����� ������
        SaveImageState();

        // ��������� ��ﳿ ���������� ��� �������
        Bitmap^ currentImage = gcnew Bitmap(pictureBox1->Image);

        // ������������ ������ ������ �� ����������
        Bitmap^ vignetteImage = ApplyVignette(currentImage);

        // ������������ ���������� � ������� ������
        pictureBox1->Image = vignetteImage;
    }
}

// ������� ��� ������������ ���������� ���������� � �����
System::Void MainForm::bNext_image_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ����� ����� ���� � �� �� ��������� ���� ������
    if (imageFiles != nullptr && currentImageIndex < imageFiles->Length - 1) {
        // ��������� ������� ��������� ����������
        currentImageIndex++;

        // ������������ ���������� ���������� � ������ �����
        Bitmap^ nextImage = gcnew Bitmap(imageFiles[currentImageIndex]);

        // ������������ ���������� � PictureBox
        pictureBox1->Image = nextImage;
    }
}


// ������� ��� ������������ ������������ ���������� � �����
System::Void MainForm::bPrevious_image_Click(System::Object^ sender, System::EventArgs^ e) {
    // ��������, �� ����� ����� ���� � �� �� ��������� ������� ������
    if (imageFiles != nullptr && currentImageIndex > 0) {
        // ��������� ������� ��������� ����������
        currentImageIndex--;

        // ������������ ������������ ���������� � ������ �����
        Bitmap^ previousImage = gcnew Bitmap(imageFiles[currentImageIndex]);

        // ������������ ���������� � PictureBox
        pictureBox1->Image = previousImage;
    }
}

// �������� ��䳿 ��� ���������� ������ "��������"
System::Void MainForm::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // �������� ����������� �� ������������ ������������ ���������
    String^ helpMessage =
        "PhotoEditor - ��������\n\n" +
        "��� ����, ��� ����������� ���������� � ������������, ��������� ������� � ������� File->Open\n" +
        "����� ��� �� ������� ������ ������� ��� ���������� ������������ ����������(File->Save as)\n\n" +
        "� ������� Action, �� ������ ����������� ���������� �� �� X �� Y, � ����� ��������� �� �� ������������ ������� �� ����� ��.\n\n" +
        "� �� �� ���� ��� ��������� ���� ����� ������������ ������� ��� ������������ �� �� ����������\n\n" +
        "������, � ��� � ��������� ������ ��� ���������:\n" +
        "������ �����������, �������� �� ��������� ����������\n\n" +
        "������ �����, ��������� �� ������, �� ������ ��� ��������� ����������� �� ������������, � ��������, � ��� ����������� ����� ����������\n";

    // ����� ���� � �����������
    MessageBox::Show(helpMessage, "Help", MessageBoxButtons::OK, MessageBoxIcon::Information);
}


// �������� ��䳿 ��� ���������� ������ "��� ��������"
System::Void MainForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    // �������� ����������� �� ����������� ��� �������� �� ������
    String^ AboutMessage =
        "PhotoEditor - ��� ������������\n\n" +
        "�������� ������ � �������� �������� ��������� ������������.\n\n" +
        "�� �������� �������� ���������� ��� ����� 䳿 � �������� ����������, �� �� ��������� �������� ������ ���������� � ������� ����.\n\n" +
        "������ ��������� � ������������� .NET �������� ��� ����������� ��������������� ����������, �� ����������� C++ ��� ��������� ��������� � ���������(������������)\n\n" +
        "����� - ������� ����� ʲ-305: ������ ���������.\n";

    // ����� ���� � �����������
    MessageBox::Show(AboutMessage, "About", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

