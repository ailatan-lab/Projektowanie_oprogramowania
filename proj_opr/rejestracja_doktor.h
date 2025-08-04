#pragma once
#include <string.h>
#include <string>
#include <mysql.h>
#include <msclr/marshal_cppstd.h>

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;


	/// <summary>
	/// Summary for rejestracja_doktor
	/// </summary>
	public ref class rejestracja_doktor : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	public:
		System::String^ Login;

		rejestracja_doktor()
		{
			InitializeComponent();
			// ... inne inicjalizacje
		}

		rejestracja_doktor(System::String^ initialValue)
		{
			InitializeComponent();
			Login = initialValue; // Ustawienie wartości za pomocą właściwości
			// ... inne inicjalizacje
		}

		void SetPreviousForm(Form^ previous)
		{
			previousForm = previous;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rejestracja_doktor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ imie;
	private: System::Windows::Forms::TextBox^ nazwisko;
	private: System::Windows::Forms::TextBox^ specjalizacja;
	private: System::Windows::Forms::Button^ zarejestruj;
	private: System::Windows::Forms::Button^ powrot;

	private: System::Windows::Forms::Label^ wiadomosci;




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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->imie = (gcnew System::Windows::Forms::TextBox());
			this->nazwisko = (gcnew System::Windows::Forms::TextBox());
			this->specjalizacja = (gcnew System::Windows::Forms::TextBox());
			this->zarejestruj = (gcnew System::Windows::Forms::Button());
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(157, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"imie";
			this->label1->Click += gcnew System::EventHandler(this, &rejestracja_doktor::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(157, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"nazwisko";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(157, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"specjalizacja";
			// 
			// imie
			// 
			this->imie->Location = System::Drawing::Point(160, 54);
			this->imie->Name = L"imie";
			this->imie->Size = System::Drawing::Size(100, 20);
			this->imie->TabIndex = 3;
			// 
			// nazwisko
			// 
			this->nazwisko->Location = System::Drawing::Point(160, 132);
			this->nazwisko->Name = L"nazwisko";
			this->nazwisko->Size = System::Drawing::Size(100, 20);
			this->nazwisko->TabIndex = 4;
			// 
			// specjalizacja
			// 
			this->specjalizacja->Location = System::Drawing::Point(160, 201);
			this->specjalizacja->Name = L"specjalizacja";
			this->specjalizacja->Size = System::Drawing::Size(100, 20);
			this->specjalizacja->TabIndex = 5;
			// 
			// zarejestruj
			// 
			this->zarejestruj->Location = System::Drawing::Point(45, 311);
			this->zarejestruj->Name = L"zarejestruj";
			this->zarejestruj->Size = System::Drawing::Size(75, 23);
			this->zarejestruj->TabIndex = 6;
			this->zarejestruj->Text = L"zarejestruj";
			this->zarejestruj->UseVisualStyleBackColor = true;
			this->zarejestruj->Click += gcnew System::EventHandler(this, &rejestracja_doktor::zarejestruj_Click);
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(345, 311);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(75, 23);
			this->powrot->TabIndex = 7;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &rejestracja_doktor::powrot_Click);
			// 
			// wiadomosci
			// 
			this->wiadomosci->AutoSize = true;
			this->wiadomosci->Location = System::Drawing::Point(157, 264);
			this->wiadomosci->Name = L"wiadomosci";
			this->wiadomosci->Size = System::Drawing::Size(35, 13);
			this->wiadomosci->TabIndex = 8;
			this->wiadomosci->Text = L"label4";
			// 
			// rejestracja_doktor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(458, 401);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->powrot);
			this->Controls->Add(this->zarejestruj);
			this->Controls->Add(this->specjalizacja);
			this->Controls->Add(this->nazwisko);
			this->Controls->Add(this->imie);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"rejestracja_doktor";
			this->Text = L"rejestracja_doktor";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &rejestracja_doktor::rejestracja_doktor_FormClosing);
			this->Load += gcnew System::EventHandler(this, &rejestracja_doktor::rejestracja_doktor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rejestracja_doktor_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ Imie = "";
		String^ Nazwisko = "";
		String^ Specjalizacja = "";
		this->wiadomosci->Text = "";
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void zarejestruj_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ Imie = this->imie->Text;
	String^ Nazwisko = this->nazwisko->Text;
	String^ Specjalizacja = this->specjalizacja->Text;
	

	if (Imie == nullptr || Imie == "")
	{
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->specjalizacja->Text = "";
		this->wiadomosci->Text = "Nie podano imienia";

	}
	else if (Nazwisko == nullptr || Nazwisko == "")
	{
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->specjalizacja->Text = "";
		this->wiadomosci->Text = "Nie podano nazwisko";
	}
	else if (Specjalizacja == nullptr || Specjalizacja == "")
	{
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->specjalizacja->Text = "";
		this->wiadomosci->Text = "Nie podano specjalizacji";
	}
	else
	{
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->specjalizacja->Text = "";

		MYSQL mysql;
		mysql_init(&mysql); // incjalizacja

		if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			string Imie_zwykly = marshal_as<std::string>(Imie);
			string Nzwisko_zwykly = marshal_as<std::string>(Nazwisko);
			string Specjalizacja_zwykly = marshal_as<std::string>(Specjalizacja);
			marshal_context context;
			string login_zwykly = context.marshal_as<std::string>(Login);
			

			string zapytanie = "insert into doktorzy values(default, '"+Imie_zwykly+"', '"+ Nzwisko_zwykly +"', '"+ Specjalizacja_zwykly +"', '"+ login_zwykly + "')";

			if (mysql_query(&mysql, zapytanie.c_str()) == 0)
			{
				this->wiadomosci->Text = "Dodano do bazy";

			}
			else
			{
				this->wiadomosci->Text = "mysql_query() failed";
			}
		}
		mysql_close(&mysql);
	}
}
private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
	previousForm->Show();
	this->Close();
}
private: System::Void rejestracja_doktor_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	previousForm->Show();
}
};
}
