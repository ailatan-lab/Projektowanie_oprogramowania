#pragma once

#include "zarejestruj.h"
#include "zaloguj.h"


namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for start_programu
	/// </summary>
	public ref class start_programu : public System::Windows::Forms::Form
	{
	public:
		start_programu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~start_programu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ zaloguj_but;
	private: System::Windows::Forms::Button^ zarejestruj_but;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->zaloguj_but = (gcnew System::Windows::Forms::Button());
			this->zarejestruj_but = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Constantia", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(86, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(433, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj w systemie dokumentacji medycznej";
			this->label1->Click += gcnew System::EventHandler(this, &start_programu::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(188, 283);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(199, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Chcesz sie zalogowac czy zarejestrowac";
			this->label2->Click += gcnew System::EventHandler(this, &start_programu::label2_Click);
			// 
			// zaloguj_but
			// 
			this->zaloguj_but->Location = System::Drawing::Point(162, 325);
			this->zaloguj_but->Name = L"zaloguj_but";
			this->zaloguj_but->Size = System::Drawing::Size(75, 23);
			this->zaloguj_but->TabIndex = 4;
			this->zaloguj_but->Text = L"zaloguj";
			this->zaloguj_but->UseVisualStyleBackColor = true;
			this->zaloguj_but->Click += gcnew System::EventHandler(this, &start_programu::zaloguj_but_Click);
			// 
			// zarejestruj_but
			// 
			this->zarejestruj_but->Location = System::Drawing::Point(336, 325);
			this->zarejestruj_but->Name = L"zarejestruj_but";
			this->zarejestruj_but->Size = System::Drawing::Size(75, 23);
			this->zarejestruj_but->TabIndex = 5;
			this->zarejestruj_but->Text = L"zarejestruj";
			this->zarejestruj_but->UseVisualStyleBackColor = true;
			this->zarejestruj_but->Click += gcnew System::EventHandler(this, &start_programu::zarejestruj_but_Click);
			// 
			// start_programu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 469);
			this->Controls->Add(this->zarejestruj_but);
			this->Controls->Add(this->zaloguj_but);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"start_programu";
			this->Text = L"start_programu";
			this->Load += gcnew System::EventHandler(this, &start_programu::start_programu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void start_programu_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void zaloguj_but_Click(System::Object^ sender, System::EventArgs^ e) {
		
		zaloguj^ Zaloguj = gcnew zaloguj;

		Zaloguj->SetPreviousForm(this);
		Zaloguj->Show();
		this->Hide();
		
	}
	private: System::Void zarejestruj_but_Click(System::Object^ sender, System::EventArgs^ e) {
		
		zarejestruj^ rejestracja = gcnew zarejestruj();
		
		rejestracja->SetPreviousForm(this);
		rejestracja->Show();
		this->Hide();
		
	}

};
}
