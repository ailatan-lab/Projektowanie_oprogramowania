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
	using namespace msclr::interop;

	/// <summary>
	/// Summary for rejestracja_pacjent
	/// </summary>
	public ref class rejestracja_upowazniony : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ pesel;
	private: System::Windows::Forms::NumericUpDown^ pesel_pacjenta;




	public:
		System::String^ Login;

		rejestracja_upowazniony(void)
		{
			InitializeComponent();


			//
			//TODO: Add the constructor code here
			//
		}
		rejestracja_upowazniony(System::String^ initialValue)
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
		~rejestracja_upowazniony()
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
		System::ComponentModel::Container^ components;

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
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->pesel = (gcnew System::Windows::Forms::NumericUpDown());
            this->pesel_pacjenta = (gcnew System::Windows::Forms::NumericUpDown());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel_pacjenta))->BeginInit();
            this->SuspendLayout();
            // 
            // zarejestruj
            // 
            this->zarejestruj->Location = System::Drawing::Point(42, 484);
            this->zarejestruj->Name = L"zarejestruj";
            this->zarejestruj->Size = System::Drawing::Size(75, 23);
            this->zarejestruj->TabIndex = 0;
            this->zarejestruj->Text = L"zarejestruj";
            this->zarejestruj->UseVisualStyleBackColor = true;
            this->zarejestruj->Click += gcnew System::EventHandler(this, &rejestracja_upowazniony::zarejestruj_Click);
            // 
            // powrot
            // 
            this->powrot->Location = System::Drawing::Point(308, 484);
            this->powrot->Name = L"powrot";
            this->powrot->Size = System::Drawing::Size(75, 23);
            this->powrot->TabIndex = 1;
            this->powrot->Text = L"powrot";
            this->powrot->UseVisualStyleBackColor = true;
            this->powrot->Click += gcnew System::EventHandler(this, &rejestracja_upowazniony::powrot_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(159, 32);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(32, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"pesel";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(159, 99);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(25, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"imie";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(159, 168);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(51, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"nazwisko";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(161, 248);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(33, 13);
            this->label4->TabIndex = 5;
            this->label4->Text = L"adres";
            // 
            // wiadomosci
            // 
            this->wiadomosci->AutoSize = true;
            this->wiadomosci->Location = System::Drawing::Point(161, 428);
            this->wiadomosci->Name = L"wiadomosci";
            this->wiadomosci->Size = System::Drawing::Size(35, 13);
            this->wiadomosci->TabIndex = 6;
            this->wiadomosci->Text = L"label5";
            // 
            // imie
            // 
            this->imie->Location = System::Drawing::Point(162, 115);
            this->imie->Name = L"imie";
            this->imie->Size = System::Drawing::Size(120, 20);
            this->imie->TabIndex = 8;
            // 
            // nazwisko
            // 
            this->nazwisko->Location = System::Drawing::Point(162, 184);
            this->nazwisko->Name = L"nazwisko";
            this->nazwisko->Size = System::Drawing::Size(120, 20);
            this->nazwisko->TabIndex = 9;
            // 
            // adres
            // 
            this->adres->Location = System::Drawing::Point(162, 264);
            this->adres->Name = L"adres";
            this->adres->Size = System::Drawing::Size(120, 20);
            this->adres->TabIndex = 10;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(159, 329);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(76, 13);
            this->label5->TabIndex = 11;
            this->label5->Text = L"pesel pacjenta";
            // 
            // pesel
            // 
            this->pesel->Location = System::Drawing::Point(162, 48);
            this->pesel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1215752191, 23, 0, 0 });
            this->pesel->Name = L"pesel";
            this->pesel->Size = System::Drawing::Size(120, 20);
            this->pesel->TabIndex = 13;
            // 
            // pesel_pacjenta
            // 
            this->pesel_pacjenta->Location = System::Drawing::Point(162, 345);
            this->pesel_pacjenta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1215752191, 23, 0, 0 });
            this->pesel_pacjenta->Name = L"pesel_pacjenta";
            this->pesel_pacjenta->Size = System::Drawing::Size(120, 20);
            this->pesel_pacjenta->TabIndex = 14;
            // 
            // rejestracja_upowazniony
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(445, 537);
            this->Controls->Add(this->pesel_pacjenta);
            this->Controls->Add(this->pesel);
            this->Controls->Add(this->label5);
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
            this->Name = L"rejestracja_upowazniony";
            this->Text = L"rejestracja_pacjent";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &rejestracja_upowazniony::rejestracja_upowazniony_FormClosing);
            this->Load += gcnew System::EventHandler(this, &rejestracja_upowazniony::rejestracja_upowazniony_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pesel_pacjenta))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void rejestracja_upowazniony_Load(System::Object^ sender, System::EventArgs^ e) {
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
		std::string Pesel_pacjenta = marshal_as<std::string>(this->pesel_pacjenta->Text);
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
		else if (Pesel_pacjenta == "")
		{
			this->pesel->Text = "";
			this->imie->Text = "";
			this->nazwisko->Text = "";
			this->adres->Text = "";
			this->wiadomosci->Text = "Nie podano peselu pacjenta";
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

				std::string zapytanie = "select * from pacjenci where numer_pesel like '"+Pesel_pacjenta+"'";

				if (mysql_query(&mysql, zapytanie.c_str()) == 0)
				{
					MYSQL_RES* result = mysql_store_result(&mysql);
					if (result)
					{
						MYSQL_ROW row = mysql_fetch_row(result);
						// Sprawdzenie, czy coś zostało zwrócone
						if (row != NULL)
						{
							std::string zapytanie1 = "insert into upowaznieni values('" + Pesel + "', '" + Imie + "', '" + Nazwisko + "', '" + Adres + "','" + login_zwykly + "')";
							std::string zapytanie2 = "insert into upowaznienia values(default, '" + Pesel + "', '" + Pesel_pacjenta + "', false)";

							if ((mysql_query(&mysql, zapytanie1.c_str()) == 0) && (mysql_query(&mysql, zapytanie2.c_str()) == 0))
							{
								this->wiadomosci->Text = "Dodano do bazy";
							}
							else if (mysql_query(&mysql, zapytanie2.c_str()) == 0)
							{
								this->wiadomosci->Text = "Drugie sie zesralo";
							}
							else
							{
								this->wiadomosci->Text = "mysql_query() failed";
							}
						}
						else
						{
							this->wiadomosci->Text = "nie ma pacjenta z tym peselem";

						}

						// Zwolnienie wyników
						mysql_free_result(result);
					}
					else
					{
						this->wiadomosci->Text = "mysql_store_result() failed";
					}
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
	private: System::Void rejestracja_upowazniony_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		previousForm->Show();
	}
};
}
