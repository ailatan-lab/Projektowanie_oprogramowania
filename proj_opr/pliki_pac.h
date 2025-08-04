#pragma once

#include <mysql.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <windows.h>


namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	namespace fs = std::filesystem;

	/// <summary>
	/// Summary for pliki_pac
	/// </summary>
	public ref class pliki_pac : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::Button^ powrot;

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ wiadomosci;
	private: System::Windows::Forms::Button^ otworz_plik;
	private: System::Windows::Forms::Button^ edytuj_text;
	public:
		System::String^ Login;
		pliki_pac(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		pliki_pac(System::String^ initialValue)
		{
			Login = initialValue;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void SetPreviousForm(Form^ previous)
		{
			previousForm = previous;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~pliki_pac()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::Windows::Forms::ListViewGroup^ listViewGroup5 = (gcnew System::Windows::Forms::ListViewGroup(L"nazwa pliku", System::Windows::Forms::HorizontalAlignment::Left));
			System::Windows::Forms::ListViewGroup^ listViewGroup6 = (gcnew System::Windows::Forms::ListViewGroup(L"typ pliku", System::Windows::Forms::HorizontalAlignment::Left));
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->otworz_plik = (gcnew System::Windows::Forms::Button());
			this->edytuj_text = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(298, 506);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(75, 23);
			this->powrot->TabIndex = 0;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &pliki_pac::powrot_Click);
			// 
			// listView1
			// 
			listViewGroup5->Header = L"nazwa pliku";
			listViewGroup5->Name = L"nazwa_pliku";
			listViewGroup6->Header = L"typ pliku";
			listViewGroup6->Name = L"typ_pliku";
			this->listView1->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(2) { listViewGroup5, listViewGroup6 });
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(96, 50);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(500, 332);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// wiadomosci
			// 
			this->wiadomosci->AutoSize = true;
			this->wiadomosci->Location = System::Drawing::Point(334, 434);
			this->wiadomosci->Name = L"wiadomosci";
			this->wiadomosci->Size = System::Drawing::Size(35, 13);
			this->wiadomosci->TabIndex = 2;
			this->wiadomosci->Text = L"label1";
			// 
			// otworz_plik
			// 
			this->otworz_plik->Location = System::Drawing::Point(172, 434);
			this->otworz_plik->Name = L"otworz_plik";
			this->otworz_plik->Size = System::Drawing::Size(75, 23);
			this->otworz_plik->TabIndex = 3;
			this->otworz_plik->Text = L"otworz_plik";
			this->otworz_plik->UseVisualStyleBackColor = true;
			this->otworz_plik->Click += gcnew System::EventHandler(this, &pliki_pac::otworz_plik_Click);
			// 
			// edytuj_text
			// 
			this->edytuj_text->Location = System::Drawing::Point(492, 433);
			this->edytuj_text->Name = L"edytuj_text";
			this->edytuj_text->Size = System::Drawing::Size(75, 23);
			this->edytuj_text->TabIndex = 4;
			this->edytuj_text->Text = L"edytuj_text";
			this->edytuj_text->UseVisualStyleBackColor = true;
			this->edytuj_text->Click += gcnew System::EventHandler(this, &pliki_pac::edytuj_text_Click);
			// 
			// pliki_pac
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 608);
			this->Controls->Add(this->edytuj_text);
			this->Controls->Add(this->otworz_plik);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->powrot);
			this->Name = L"pliki_pac";
			this->Text = L"pliki_pac";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &pliki_pac::pliki_pac_FormClosing);
			this->Load += gcnew System::EventHandler(this, &pliki_pac::pliki_pac_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pliki_pac_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		previousForm->Show();
	}
	private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
		previousForm->Show();
		this->Close();
	}
	private: System::Void pliki_pac_Load(System::Object^ sender, System::EventArgs^ e) {
		this->wiadomosci->Text = "";
		//"serwer\\foldery_pacjentow\\";
		//nie wiem po co to ale bez tego nie dziala
		System::String^ Login2 = Login;
		std::string Login_zwykly = marshal_as<std::string>(Login2);

		std::string folderPath = "serwer\\foldery_pacjentow\\";
		folderPath = folderPath + Login_zwykly + "\\";

		for (const auto& entry : fs::directory_iterator(folderPath)) {
			if (entry.is_regular_file()) {
				//entry.path().filename() 
				std::wstring wideFileName = entry.path().filename();
				System::String^ sysFileName = msclr::interop::marshal_as<System::String^>(wideFileName);
				ListViewItem^ item = gcnew ListViewItem(sysFileName);

				this->listView1->Items->Add(item);
			}
		}

	}
private: System::Void otworz_plik_Click(System::Object^ sender, System::EventArgs^ e) {
	ListViewItem^ selectedItem = listView1->SelectedItems[0];

	System::String^ plik = selectedItem->Text;
	this->wiadomosci->Text = plik;

	System::String^ folderPath = "serwer\\foldery_pacjentow\\"+Login+"\\"+plik;

	std::wstring filePath = msclr::interop::marshal_as<std::wstring>(folderPath);
	
	HINSTANCE result = ShellExecute(
		nullptr,
		L"open",
		filePath.c_str(),
		nullptr,
		nullptr,
		SW_SHOWNORMAL
		
	);

	if (reinterpret_cast<int>(result) <= 32) {
		this->wiadomosci->Text = "ShellExecute failed";
	}
	
}
private: System::Void edytuj_text_Click(System::Object^ sender, System::EventArgs^ e) {
	
	ListViewItem^ selectedItem = listView1->SelectedItems[0];

	System::String^ plik = selectedItem->Text;
	this->wiadomosci->Text = plik;

	System::String^ folderPath = "serwer\\foldery_pacjentow\\" + Login + "\\" + plik;

	std::wstring filePath = msclr::interop::marshal_as<std::wstring>(folderPath);

	HINSTANCE result = ShellExecute(
		nullptr,
		L"edit",
		filePath.c_str(),
		nullptr,
		nullptr,
		SW_SHOWNORMAL

	);

	if (reinterpret_cast<int>(result) <= 32) {
		this->wiadomosci->Text = "ShellExecute failed";
	}
	
}
};
}
