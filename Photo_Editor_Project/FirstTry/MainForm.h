#pragma once

namespace PhotoEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			SetProgramIcon();
			InitializeImageHistory();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private: System::Windows::Forms::Button^ bTemperature_increase;

	private: System::Windows::Forms::Button^ bTemperature_decrease;

	private: System::Windows::Forms::Button^ bGrayScale;

	private: System::Windows::Forms::Button^ bContrast_decrease;
	private: System::Windows::Forms::Button^ bContrast_increase;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::Button^ bUndo;
	private: System::Windows::Forms::Button^ bRedo;

	private: System::Collections::Generic::List<Bitmap^>^ imageHistory; //оголошення змінних для збереження історії змін виконаних для фотографії 
	private: int currentHistoryIndex;                                   //



	private: System::Windows::Forms::Button^ bBrightness_decrease;
	private: System::Windows::Forms::Button^ bBrightness_increase;
	private: System::Windows::Forms::ToolStripMenuItem^ scaleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ flipToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^ rotateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bRotate_right;

	private: System::Windows::Forms::ToolStripMenuItem^ bRotate_left;


	private: System::Windows::Forms::ToolStripMenuItem^ bFlipX;
	private: System::Windows::Forms::ToolStripMenuItem^ bFlipY;
	private: System::Windows::Forms::Label^ lFilters;


	private: System::Windows::Forms::Button^ bNext_image;
	private: System::Windows::Forms::Button^ bPrevious_image;

	private: cli::array<String^>^ imageFiles; //оголошення змінних для відслідковування фотофайлів і поточного індексу фотографії
	private: int currentImageIndex;           //
	private: System::Windows::Forms::Button^ bSepia_effect;

	private: System::Windows::Forms::Button^ bVigentte_effect;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lBrightness;
	private: System::Windows::Forms::Label^ label4;





	protected:











	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->bTemperature_increase = (gcnew System::Windows::Forms::Button());
			this->bTemperature_decrease = (gcnew System::Windows::Forms::Button());
			this->bGrayScale = (gcnew System::Windows::Forms::Button());
			this->bContrast_decrease = (gcnew System::Windows::Forms::Button());
			this->bContrast_increase = (gcnew System::Windows::Forms::Button());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->scaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bFlipX = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bFlipY = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bRotate_right = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bRotate_left = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bUndo = (gcnew System::Windows::Forms::Button());
			this->bRedo = (gcnew System::Windows::Forms::Button());
			this->bBrightness_decrease = (gcnew System::Windows::Forms::Button());
			this->bBrightness_increase = (gcnew System::Windows::Forms::Button());
			this->lFilters = (gcnew System::Windows::Forms::Label());
			this->bNext_image = (gcnew System::Windows::Forms::Button());
			this->bPrevious_image = (gcnew System::Windows::Forms::Button());
			this->bSepia_effect = (gcnew System::Windows::Forms::Button());
			this->bVigentte_effect = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lBrightness = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox1->Location = System::Drawing::Point(16, 63);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(727, 531);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// bTemperature_increase
			// 
			this->bTemperature_increase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bTemperature_increase->AutoSize = true;
			this->bTemperature_increase->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bTemperature_increase->Location = System::Drawing::Point(920, 84);
			this->bTemperature_increase->Margin = System::Windows::Forms::Padding(4);
			this->bTemperature_increase->Name = L"bTemperature_increase";
			this->bTemperature_increase->Size = System::Drawing::Size(121, 31);
			this->bTemperature_increase->TabIndex = 5;
			this->bTemperature_increase->Text = L"+";
			this->bTemperature_increase->UseVisualStyleBackColor = true;
			this->bTemperature_increase->Click += gcnew System::EventHandler(this, &MainForm::bTemperature_increase_Click);
			// 
			// bTemperature_decrease
			// 
			this->bTemperature_decrease->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bTemperature_decrease->AutoSize = true;
			this->bTemperature_decrease->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bTemperature_decrease->Location = System::Drawing::Point(789, 84);
			this->bTemperature_decrease->Margin = System::Windows::Forms::Padding(4);
			this->bTemperature_decrease->Name = L"bTemperature_decrease";
			this->bTemperature_decrease->Size = System::Drawing::Size(121, 31);
			this->bTemperature_decrease->TabIndex = 6;
			this->bTemperature_decrease->Text = L"-";
			this->bTemperature_decrease->UseVisualStyleBackColor = true;
			this->bTemperature_decrease->Click += gcnew System::EventHandler(this, &MainForm::bTemperature_decrease_Click);
			// 
			// bGrayScale
			// 
			this->bGrayScale->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bGrayScale->Location = System::Drawing::Point(360, 0);
			this->bGrayScale->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bGrayScale->Name = L"bGrayScale";
			this->bGrayScale->Size = System::Drawing::Size(86, 28);
			this->bGrayScale->TabIndex = 7;
			this->bGrayScale->Text = L"GrayScale";
			this->bGrayScale->UseVisualStyleBackColor = true;
			this->bGrayScale->Click += gcnew System::EventHandler(this, &MainForm::bGrayScale_Click);
			// 
			// bContrast_decrease
			// 
			this->bContrast_decrease->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bContrast_decrease->AutoSize = true;
			this->bContrast_decrease->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bContrast_decrease->Location = System::Drawing::Point(789, 158);
			this->bContrast_decrease->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bContrast_decrease->Name = L"bContrast_decrease";
			this->bContrast_decrease->Size = System::Drawing::Size(121, 31);
			this->bContrast_decrease->TabIndex = 9;
			this->bContrast_decrease->Text = L"-";
			this->bContrast_decrease->UseVisualStyleBackColor = true;
			this->bContrast_decrease->Click += gcnew System::EventHandler(this, &MainForm::bContrast_decrease_Click);
			// 
			// bContrast_increase
			// 
			this->bContrast_increase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bContrast_increase->AutoSize = true;
			this->bContrast_increase->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bContrast_increase->Location = System::Drawing::Point(920, 158);
			this->bContrast_increase->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bContrast_increase->Name = L"bContrast_increase";
			this->bContrast_increase->Size = System::Drawing::Size(121, 31);
			this->bContrast_increase->TabIndex = 10;
			this->bContrast_increase->Text = L"+";
			this->bContrast_increase->UseVisualStyleBackColor = true;
			this->bContrast_increase->Click += gcnew System::EventHandler(this, &MainForm::bContrast_increase_Click);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openItem,
					this->saveAsItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(43, 22);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fileToolStripMenuItem_Click);
			// 
			// openItem
			// 
			this->openItem->Name = L"openItem";
			this->openItem->Size = System::Drawing::Size(136, 26);
			this->openItem->Text = L"Open";
			this->openItem->Click += gcnew System::EventHandler(this, &MainForm::openItem_Click);
			// 
			// saveAsItem
			// 
			this->saveAsItem->Name = L"saveAsItem";
			this->saveAsItem->Size = System::Drawing::Size(136, 26);
			this->saveAsItem->Text = L"Save as";
			this->saveAsItem->Click += gcnew System::EventHandler(this, &MainForm::saveAsItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(51, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(60, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->scaleToolStripMenuItem, this->helpToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1080, 26);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// scaleToolStripMenuItem
			// 
			this->scaleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->flipToolStripMenuItem,
					this->rotateToolStripMenuItem
			});
			this->scaleToolStripMenuItem->Name = L"scaleToolStripMenuItem";
			this->scaleToolStripMenuItem->Size = System::Drawing::Size(62, 22);
			this->scaleToolStripMenuItem->Text = L"Action";
			// 
			// flipToolStripMenuItem
			// 
			this->flipToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->bFlipX,
					this->bFlipY
			});
			this->flipToolStripMenuItem->Name = L"flipToolStripMenuItem";
			this->flipToolStripMenuItem->Size = System::Drawing::Size(135, 26);
			this->flipToolStripMenuItem->Text = L"Flip";
			// 
			// bFlipX
			// 
			this->bFlipX->Name = L"bFlipX";
			this->bFlipX->Size = System::Drawing::Size(122, 26);
			this->bFlipX->Text = L"Flip X";
			this->bFlipX->Click += gcnew System::EventHandler(this, &MainForm::bFlipX_Click);
			// 
			// bFlipY
			// 
			this->bFlipY->Name = L"bFlipY";
			this->bFlipY->Size = System::Drawing::Size(122, 26);
			this->bFlipY->Text = L"Flip Y";
			this->bFlipY->Click += gcnew System::EventHandler(this, &MainForm::bFlipY_Click);
			// 
			// rotateToolStripMenuItem
			// 
			this->rotateToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->bRotate_right,
					this->bRotate_left
			});
			this->rotateToolStripMenuItem->Name = L"rotateToolStripMenuItem";
			this->rotateToolStripMenuItem->Size = System::Drawing::Size(135, 26);
			this->rotateToolStripMenuItem->Text = L"Rotate ";
			// 
			// bRotate_right
			// 
			this->bRotate_right->Name = L"bRotate_right";
			this->bRotate_right->Size = System::Drawing::Size(164, 26);
			this->bRotate_right->Text = L"Rotate right";
			this->bRotate_right->Click += gcnew System::EventHandler(this, &MainForm::bRotate_right_Click);
			// 
			// bRotate_left
			// 
			this->bRotate_left->Name = L"bRotate_left";
			this->bRotate_left->Size = System::Drawing::Size(164, 26);
			this->bRotate_left->Text = L"Rotate left";
			this->bRotate_left->Click += gcnew System::EventHandler(this, &MainForm::bRotate_left_Click);
			// 
			// bUndo
			// 
			this->bUndo->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bUndo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bUndo->Font = (gcnew System::Drawing::Font(L"Candara", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->bUndo->Location = System::Drawing::Point(12, 31);
			this->bUndo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bUndo->Name = L"bUndo";
			this->bUndo->Size = System::Drawing::Size(77, 26);
			this->bUndo->TabIndex = 12;
			this->bUndo->Text = L"Undo";
			this->bUndo->UseVisualStyleBackColor = false;
			this->bUndo->Click += gcnew System::EventHandler(this, &MainForm::bUndo_Click);
			// 
			// bRedo
			// 
			this->bRedo->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bRedo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bRedo->Font = (gcnew System::Drawing::Font(L"Candara", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->bRedo->Location = System::Drawing::Point(95, 31);
			this->bRedo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bRedo->Name = L"bRedo";
			this->bRedo->Size = System::Drawing::Size(77, 26);
			this->bRedo->TabIndex = 13;
			this->bRedo->Text = L"Redo";
			this->bRedo->UseVisualStyleBackColor = false;
			this->bRedo->Click += gcnew System::EventHandler(this, &MainForm::bRedo_Click);
			// 
			// bBrightness_decrease
			// 
			this->bBrightness_decrease->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bBrightness_decrease->AutoSize = true;
			this->bBrightness_decrease->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bBrightness_decrease->Location = System::Drawing::Point(789, 234);
			this->bBrightness_decrease->Margin = System::Windows::Forms::Padding(4);
			this->bBrightness_decrease->Name = L"bBrightness_decrease";
			this->bBrightness_decrease->Size = System::Drawing::Size(121, 31);
			this->bBrightness_decrease->TabIndex = 15;
			this->bBrightness_decrease->Text = L"-";
			this->bBrightness_decrease->UseVisualStyleBackColor = true;
			this->bBrightness_decrease->Click += gcnew System::EventHandler(this, &MainForm::bBrightness_decrease_Click);
			// 
			// bBrightness_increase
			// 
			this->bBrightness_increase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bBrightness_increase->AutoSize = true;
			this->bBrightness_increase->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bBrightness_increase->Location = System::Drawing::Point(920, 234);
			this->bBrightness_increase->Margin = System::Windows::Forms::Padding(4);
			this->bBrightness_increase->Name = L"bBrightness_increase";
			this->bBrightness_increase->Size = System::Drawing::Size(121, 31);
			this->bBrightness_increase->TabIndex = 16;
			this->bBrightness_increase->Text = L"+";
			this->bBrightness_increase->UseVisualStyleBackColor = true;
			this->bBrightness_increase->Click += gcnew System::EventHandler(this, &MainForm::bBrightness_increase_Click);
			// 
			// lFilters
			// 
			this->lFilters->AutoSize = true;
			this->lFilters->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->lFilters->Font = (gcnew System::Drawing::Font(L"Candara", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lFilters->Location = System::Drawing::Point(288, 4);
			this->lFilters->Name = L"lFilters";
			this->lFilters->Size = System::Drawing::Size(57, 21);
			this->lFilters->TabIndex = 17;
			this->lFilters->Text = L"Filters:";
			// 
			// bNext_image
			// 
			this->bNext_image->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bNext_image->AutoSize = true;
			this->bNext_image->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bNext_image->Location = System::Drawing::Point(920, 566);
			this->bNext_image->Margin = System::Windows::Forms::Padding(4);
			this->bNext_image->Name = L"bNext_image";
			this->bNext_image->Size = System::Drawing::Size(121, 31);
			this->bNext_image->TabIndex = 19;
			this->bNext_image->Text = L"Next";
			this->bNext_image->UseVisualStyleBackColor = true;
			this->bNext_image->Click += gcnew System::EventHandler(this, &MainForm::bNext_image_Click);
			// 
			// bPrevious_image
			// 
			this->bPrevious_image->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bPrevious_image->AutoSize = true;
			this->bPrevious_image->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bPrevious_image->Location = System::Drawing::Point(789, 566);
			this->bPrevious_image->Margin = System::Windows::Forms::Padding(4);
			this->bPrevious_image->Name = L"bPrevious_image";
			this->bPrevious_image->Size = System::Drawing::Size(121, 31);
			this->bPrevious_image->TabIndex = 20;
			this->bPrevious_image->Text = L"Previous";
			this->bPrevious_image->UseVisualStyleBackColor = true;
			this->bPrevious_image->Click += gcnew System::EventHandler(this, &MainForm::bPrevious_image_Click);
			// 
			// bSepia_effect
			// 
			this->bSepia_effect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bSepia_effect->Location = System::Drawing::Point(452, 0);
			this->bSepia_effect->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bSepia_effect->Name = L"bSepia_effect";
			this->bSepia_effect->Size = System::Drawing::Size(86, 28);
			this->bSepia_effect->TabIndex = 21;
			this->bSepia_effect->Text = L"Sepia";
			this->bSepia_effect->UseVisualStyleBackColor = true;
			this->bSepia_effect->Click += gcnew System::EventHandler(this, &MainForm::bSepia_effect_Click);
			// 
			// bVigentte_effect
			// 
			this->bVigentte_effect->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bVigentte_effect->Location = System::Drawing::Point(544, 0);
			this->bVigentte_effect->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bVigentte_effect->Name = L"bVigentte_effect";
			this->bVigentte_effect->Size = System::Drawing::Size(86, 28);
			this->bVigentte_effect->TabIndex = 22;
			this->bVigentte_effect->Text = L"Vignette";
			this->bVigentte_effect->UseVisualStyleBackColor = true;
			this->bVigentte_effect->Click += gcnew System::EventHandler(this, &MainForm::bVigentte_effect_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Candara", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(852, 56);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 24);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Temperature";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Candara", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(870, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 24);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Contrast";
			// 
			// lBrightness
			// 
			this->lBrightness->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lBrightness->AutoSize = true;
			this->lBrightness->Font = (gcnew System::Drawing::Font(L"Candara", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lBrightness->Location = System::Drawing::Point(861, 206);
			this->lBrightness->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lBrightness->Name = L"lBrightness";
			this->lBrightness->Size = System::Drawing::Size(99, 24);
			this->lBrightness->TabIndex = 26;
			this->lBrightness->Text = L"Brightness";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Candara", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(888, 538);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 24);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Image";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(1080, 610);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lBrightness);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bVigentte_effect);
			this->Controls->Add(this->bSepia_effect);
			this->Controls->Add(this->bPrevious_image);
			this->Controls->Add(this->bNext_image);
			this->Controls->Add(this->lFilters);
			this->Controls->Add(this->bBrightness_increase);
			this->Controls->Add(this->bBrightness_decrease);
			this->Controls->Add(this->bRedo);
			this->Controls->Add(this->bUndo);
			this->Controls->Add(this->bContrast_increase);
			this->Controls->Add(this->bContrast_decrease);
			this->Controls->Add(this->bGrayScale);
			this->Controls->Add(this->bTemperature_decrease);
			this->Controls->Add(this->bTemperature_increase);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"PhotoEditor-Volodymyr Gnidec";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeImageHistory(void) {
		
			this->imageHistory = gcnew System::Collections::Generic::List<Bitmap^>();
			this->currentHistoryIndex = -1;
		}
		void SetProgramIcon(void)
		{
			// Load the icon from the project's source files
			this->Icon = gcnew System::Drawing::Icon("Icon.ico");
		}
#pragma endregion
	




private: System::Void openItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void bGrayScale_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void saveAsItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bTemperature_decrease_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bTemperature_increase_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bContrast_decrease_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bContrast_increase_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void SaveImageState();
private: System::Void bUndo_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bRedo_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void bBrightness_decrease_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bBrightness_increase_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void bFlipY_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bFlipX_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void bRotate_left_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bRotate_right_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void bPrevious_image_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bNext_image_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void bSepia_effect_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bVigentte_effect_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

};
}
