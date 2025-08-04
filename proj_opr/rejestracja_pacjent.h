#pragma once

#include <string.h>
#include <string>
#include <mysql.h>
#include <msclr/marshal_cppstd.h>
#include <direct.h>

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for rejestracja_pacjent
	/// </summary>
	public ref class rejestracja_pacjent : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::NumericUpDown^ pesel;

	public:
		System::String^ Login;

		rejestracja_pacjent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		rejestracja_pacjent(System::String^ initialValue)
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
		~rejestracja_pacjent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ zarejestruj;
	private: System::Windows::Forms::Button^ powrot;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ wiadomosci;


	private: System::Windows::Forms::TextBox^ imie;
	private: System::Windows::Forms::TextBox^ nazwisko;
	private: System::Windows::Forms::TextBox^ adres;




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
			this->zarejestruj = (gcnew System::Windows::Forms::Button());
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->imie = (gcnew System::Windows::Forms::TextBox());
			this->nazwisko = (gcnew System::Windows::Forms::TextBox());
			this->adres = (gcnew System::Windows::Forms::TextBox());
			this->pesel = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel))->BeginInit();
			this->SuspendLayout();
			// 
			// zarejestruj
			// 
			this->zarejestruj->Location = System::Drawing::Point(37, 375);
			this->zarejestruj->Name = L"zarejestruj";
			this->zarejestruj->Size = System::Drawing::Size(75, 23);
			this->zarejestruj->TabIndex = 0;
			this->zarejestruj->Text = L"zarejestruj";
			this->zarejestruj->UseVisualStyleBackColor = true;
			this->zarejestruj->Click += gcnew System::EventHandler(this, &rejestracja_pacjent::zarejestruj_Click);
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(313, 375);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(75, 23);
			this->powrot->TabIndex = 1;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &rejestracja_pacjent::powrot_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"pesel";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(154, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"imie";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(154, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"nazwisko";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(154, 249);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"adres";
			// 
			// wiadomosci
			// 
			this->wiadomosci->AutoSize = true;
			this->wiadomosci->Location = System::Drawing::Point(154, 326);
			this->wiadomosci->Name = L"wiadomosci";
			this->wiadomosci->Size = System::Drawing::Size(35, 13);
			this->wiadomosci->TabIndex = 6;
			this->wiadomosci->Text = L"label5";
			// 
			// imie
			// 
			this->imie->Location = System::Drawing::Point(157, 106);
			this->imie->Name = L"imie";
			this->imie->Size = System::Drawing::Size(120, 20);
			this->imie->TabIndex = 8;
			// 
			// nazwisko
			// 
			this->nazwisko->Location = System::Drawing::Point(157, 188);
			this->nazwisko->Name = L"nazwisko";
			this->nazwisko->Size = System::Drawing::Size(120, 20);
			this->nazwisko->TabIndex = 9;
			// 
			// adres
			// 
			this->adres->Location = System::Drawing::Point(157, 265);
			this->adres->Name = L"adres";
			this->adres->Size = System::Drawing::Size(120, 20);
			this->adres->TabIndex = 10;
			// 
			// pesel
			// 
			this->pesel->Location = System::Drawing::Point(157, 41);
			this->pesel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1215752191, 23, 0, 0 });
			this->pesel->Name = L"pesel";
			this->pesel->Size = System::Drawing::Size(120, 20);
			this->pesel->TabIndex = 11;
			// 
			// rejestracja_pacjent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 447);
			this->Controls->Add(this->pesel);
			this->Controls->Add(this->adres);
			this->Controls->Add(this->nazwisko);
			this->Controls->Add(this->imie);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->powrot);
			this->Controls->Add(this->zarejestruj);
			this->Name = L"rejestracja_pacjent";
			this->Text = L"rejestracja_pacjent";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &rejestracja_pacjent::rejestracja_pacjent_FormClosing);
			this->Load += gcnew System::EventHandler(this, &rejestracja_pacjent::rejestracja_pacjent_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rejestracja_pacjent_Load(System::Object^ sender, System::EventArgs^ e) {
		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";
		this->wiadomosci->Text = "";
	}
private: System::Void zarejestruj_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string Pesel = marshal_as<std::string>(this->pesel->Text);
	std::string Imie = marshal_as<std::string>(this->imie->Text);
	std::string Nazwisko = marshal_as<std::string>(this->nazwisko->Text);
	std::string Adres = marshal_as<std::string>(this->adres->Text);
	if (Pesel.length() != 11)
	{
		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";
		this->wiadomosci->Text = "Pesel nieprawidlowy";
	}
	else if (Imie == "")
	{
		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";
		this->wiadomosci->Text = "Nie podano imienia";
	}
	else if (Nazwisko == "")
	{
		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";
		this->wiadomosci->Text = "Nie podano nazwiska";
	}
	else if (Adres == "")
	{
		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";
		this->wiadomosci->Text = "Nie podano adresu";
	}
	else
	{
		marshal_context context;
		std::string login_zwykly = context.marshal_as<std::string>(Login);

		this->pesel->Text = "";
		this->imie->Text = "";
		this->nazwisko->Text = "";
		this->adres->Text = "";

		MYSQL mysql;
		mysql_init(&mysql); // incjalizacja

		if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{

			std::string zapytanie = "insert into pacjenci values('" + Pesel + "', '" + Imie + "', '" + Nazwisko + "', '" + Adres + "','" + login_zwykly + "')";


			if (mysql_query(&mysql, zapytanie.c_str()) == 0)
			{
				this->wiadomosci->Text = "Dodano do bazy";
				std::string sciezka = "serwer\\foldery_pacjentow\\";
				sciezka = sciezka + login_zwykly;
				_mkdir(sciezka.c_str());

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
private: System::Void rejestracja_pacjent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	previousForm->Show();
}
};
}
