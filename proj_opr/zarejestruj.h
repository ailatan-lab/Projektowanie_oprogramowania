#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include <mysql.h>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "rejestracja_pacjent.h"
#include "rejestracja_doktor.h"
#include "rejestracja_upowazniony.h"

namespace projopr {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for zarejestruj
	/// </summary>
	public ref class zarejestruj : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	public:
		bool zamkniete = true;
		zarejestruj(void)
		{
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
		~zarejestruj()
		{
			if (components)
			{
				delete components; 
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ zarejestruj_sie;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ login;
	private: System::Windows::Forms::TextBox^ haslo;
	private: System::Windows::Forms::Label^ wiadomosci;
	private: System::Windows::Forms::ComboBox^ typ_konta;
	private: System::Windows::Forms::Label^ label4;




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
            this->zarejestruj_sie = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->login = (gcnew System::Windows::Forms::TextBox());
            this->haslo = (gcnew System::Windows::Forms::TextBox());
            this->wiadomosci = (gcnew System::Windows::Forms::Label());
            this->typ_konta = (gcnew System::Windows::Forms::ComboBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(196, 22);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(54, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"zarejestruj";
            // 
            // zarejestruj_sie
            // 
            this->zarejestruj_sie->Location = System::Drawing::Point(44, 373);
            this->zarejestruj_sie->Name = L"zarejestruj_sie";
            this->zarejestruj_sie->Size = System::Drawing::Size(75, 23);
            this->zarejestruj_sie->TabIndex = 1;
            this->zarejestruj_sie->Text = L"zarejestruj sie";
            this->zarejestruj_sie->UseVisualStyleBackColor = true;
            this->zarejestruj_sie->Click += gcnew System::EventHandler(this, &zarejestruj::zarejestruj_sie_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(317, 373);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 2;
            this->button2->Text = L"button2";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &zarejestruj::button2_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(163, 85);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(29, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"login";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(163, 154);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(32, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"haslo";
            // 
            // login
            // 
            this->login->Location = System::Drawing::Point(166, 101);
            this->login->Name = L"login";
            this->login->Size = System::Drawing::Size(100, 20);
            this->login->TabIndex = 5;
            // 
            // haslo
            // 
            this->haslo->Location = System::Drawing::Point(166, 170);
            this->haslo->Name = L"haslo";
            this->haslo->Size = System::Drawing::Size(100, 20);
            this->haslo->TabIndex = 6;
            // 
            // wiadomosci
            // 
            this->wiadomosci->AutoSize = true;
            this->wiadomosci->Location = System::Drawing::Point(163, 306);
            this->wiadomosci->Name = L"wiadomosci";
            this->wiadomosci->Size = System::Drawing::Size(35, 13);
            this->wiadomosci->TabIndex = 7;
            this->wiadomosci->Text = L"label4";
            // 
            // typ_konta
            // 
            this->typ_konta->FormattingEnabled = true;
            this->typ_konta->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"pacjent", L"upowazniony", L"doktor" });
            this->typ_konta->Location = System::Drawing::Point(166, 246);
            this->typ_konta->Name = L"typ_konta";
            this->typ_konta->Size = System::Drawing::Size(100, 21);
            this->typ_konta->TabIndex = 8;
            this->typ_konta->SelectedIndexChanged += gcnew System::EventHandler(this, &zarejestruj::typ_konta_SelectedIndexChanged);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(163, 230);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(51, 13);
            this->label4->TabIndex = 9;
            this->label4->Text = L"typ konta";
            // 
            // zarejestruj
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(445, 441);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->typ_konta);
            this->Controls->Add(this->wiadomosci);
            this->Controls->Add(this->haslo);
            this->Controls->Add(this->login);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->zarejestruj_sie);
            this->Controls->Add(this->label1);
            this->Name = L"zarejestruj";
            this->Text = L"zarejestruj";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &zarejestruj::zarejestruj_FormClosing);
            this->Load += gcnew System::EventHandler(this, &zarejestruj::zarejestruj_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
		private: System::Void typ_konta_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		previousForm->Show();
		this->Close();
	}

private: System::Void zarejestruj_sie_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ Login = this->login->Text;
	String^ Haslo = this->haslo->Text;
	//String^ konto_typ = safe_cast<String^>(this->typ_konta->SelectedItem);
	INT konto_typ = this->typ_konta->SelectedIndex;

	if (Login == nullptr || Login=="")
	{
		this->login->Text = "";
		this->haslo->Text = "";
		this->typ_konta->SelectedIndex = -1;
		this->wiadomosci->Text = "Nie podano loginu";
		
	}
	else if (Haslo == nullptr || Haslo == "")
	{
		this->login->Text = "";
		this->haslo->Text = "";
		this->typ_konta->SelectedIndex = -1;
		this->wiadomosci->Text = "Nie podano hasla";
	}
	else if (konto_typ == -1)
	{
		this->login->Text = "";
		this->haslo->Text = "";
		this->typ_konta->SelectedIndex = -1;
		this->wiadomosci->Text = "Nie podano typu konta";
	}
	else
	{
		this->login->Text = "";
		this->haslo->Text = "";
		this->typ_konta->SelectedIndex = -1;

		


		//sprawdzanie czy jest w bazie taki uzywkownik
		
		MYSQL mysql;
		mysql_init(&mysql); // incjalizacja
		
		if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//std::ostringstream query;
			string Login_zwykly = marshal_as<std::string>(Login);
			//query << "SELECT * FROM uzytkownicy WHERE login='" << Login_zwykly << "'";
			//string zapytanie = query.str();
			string zapytanie = "SELECT * FROM uzytkownicy WHERE login='" + Login_zwykly + "'";

			if (mysql_query(&mysql, zapytanie.c_str()) == 0)
			{
				MYSQL_RES* result = mysql_store_result(&mysql);
				if (result)
				{
					MYSQL_ROW row = mysql_fetch_row(result);
					// Sprawdzenie, czy coś zostało zwrócone
					if (row != NULL)
					{
						this->wiadomosci->Text = "konto juz istnieje";
					}
					else
					{
						string haslo_zwykly = marshal_as<std::string>(Haslo);
						string zapytanie = "insert into uzytkownicy values(Default,'" + Login_zwykly + "', '" + haslo_zwykly + "', false,'"+ std::to_string(konto_typ) +"')";
						if (mysql_query(&mysql, zapytanie.c_str()) == 0)
						{
							if (konto_typ == 0)
							{
								rejestracja_pacjent^ rejestracja = gcnew rejestracja_pacjent(Login);

								zamkniete = false;
								this->Close();
								rejestracja->SetPreviousForm(previousForm);
								rejestracja->Show();
							}
							else if (konto_typ == 1)
							{
								rejestracja_upowazniony^ rejestracja = gcnew rejestracja_upowazniony();

								zamkniete = false;
								this->Close();
								rejestracja->SetPreviousForm(previousForm);
								rejestracja->Show();

							}
							else
							{
								rejestracja_doktor^ rejestracja = gcnew rejestracja_doktor(Login);

								zamkniete = false;
								this->Close();
								rejestracja->SetPreviousForm(previousForm);
								rejestracja->Show();
							}
						}
						else
						{
							this->wiadomosci->Text = "Zesralo sie";
						}
						
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

			/* stary tryb na pliki tekstowe

			StreamWriter^ sprawdzenie = gcnew StreamWriter("serwer\\uzytkownicy.txt", true);
			sprawdzenie->WriteLine(Login + " " + Haslo + " "+ konto_typ + "\r");
			sprawdzenie->Close();
			*/
		
		
		
	}
}
private: System::Void zarejestruj_Load(System::Object^ sender, System::EventArgs^ e) {
	this->login->Text = "";
	this->haslo->Text = "";
	this->wiadomosci->Text = "";
	this->typ_konta->SelectedIndex = -1;
}


private: System::Void zarejestruj_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (zamkniete == true)
	{
		previousForm->Show();
	}
}
};
}
