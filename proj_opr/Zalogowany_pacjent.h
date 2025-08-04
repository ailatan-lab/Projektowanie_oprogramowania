#pragma once

#include "lista_upowaznionych.h"
#include "lista_przypisanych_pac.h"
#include "pliki_pac.h"
#include "zmiana_hasla.h"
#include <windows.h>
#include <filesystem>


namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Zalogowany_pacjent
	/// </summary>
	public ref class Zalogowany_pacjent : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::Button^ zobacz_moich_lekarzy;
	private: System::Windows::Forms::Button^ zobacz_moje_pliki;
	private: System::Windows::Forms::Button^ zaktualizuj_liste_upowaznionych;
	public:
		bool zamkniete = true;
	private: System::Windows::Forms::Button^ wyloguj;
    private: System::Windows::Forms::Button^ zmien_haslo;
	private: System::Windows::Forms::Button^ usun_konto;
    private: System::Windows::Forms::Label^ informacjax;






	public:

	public:
		System::String^ Login;
		Zalogowany_pacjent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Zalogowany_pacjent(System::String^ initialValue)
		{
			InitializeComponent();
			Login = initialValue;
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
		~Zalogowany_pacjent()
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
            this->zobacz_moich_lekarzy = (gcnew System::Windows::Forms::Button());
            this->zobacz_moje_pliki = (gcnew System::Windows::Forms::Button());
            this->zaktualizuj_liste_upowaznionych = (gcnew System::Windows::Forms::Button());
            this->wyloguj = (gcnew System::Windows::Forms::Button());
            this->zmien_haslo = (gcnew System::Windows::Forms::Button());
            this->usun_konto = (gcnew System::Windows::Forms::Button());
            this->informacjax = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // zobacz_moich_lekarzy
            // 
            this->zobacz_moich_lekarzy->Location = System::Drawing::Point(140, 39);
            this->zobacz_moich_lekarzy->Name = L"zobacz_moich_lekarzy";
            this->zobacz_moich_lekarzy->Size = System::Drawing::Size(208, 23);
            this->zobacz_moich_lekarzy->TabIndex = 0;
            this->zobacz_moich_lekarzy->Text = L"zobacz moich lekarzy";
            this->zobacz_moich_lekarzy->UseVisualStyleBackColor = true;
            this->zobacz_moich_lekarzy->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::zobacz_moich_lekarzy_Click);
            // 
            // zobacz_moje_pliki
            // 
            this->zobacz_moje_pliki->Location = System::Drawing::Point(140, 101);
            this->zobacz_moje_pliki->Name = L"zobacz_moje_pliki";
            this->zobacz_moje_pliki->Size = System::Drawing::Size(208, 23);
            this->zobacz_moje_pliki->TabIndex = 1;
            this->zobacz_moje_pliki->Text = L"zobacz moje pliki";
            this->zobacz_moje_pliki->UseVisualStyleBackColor = true;
            this->zobacz_moje_pliki->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::zobacz_moje_pliki_Click);
            // 
            // zaktualizuj_liste_upowaznionych
            // 
            this->zaktualizuj_liste_upowaznionych->Location = System::Drawing::Point(140, 166);
            this->zaktualizuj_liste_upowaznionych->Name = L"zaktualizuj_liste_upowaznionych";
            this->zaktualizuj_liste_upowaznionych->Size = System::Drawing::Size(208, 38);
            this->zaktualizuj_liste_upowaznionych->TabIndex = 2;
            this->zaktualizuj_liste_upowaznionych->Text = L"zaktualizuj liste upowaznionych";
            this->zaktualizuj_liste_upowaznionych->UseVisualStyleBackColor = true;
            this->zaktualizuj_liste_upowaznionych->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::zaktualizuj_liste_upowaznionych_Click);
            // 
            // wyloguj
            // 
            this->wyloguj->Location = System::Drawing::Point(198, 381);
            this->wyloguj->Name = L"wyloguj";
            this->wyloguj->Size = System::Drawing::Size(88, 23);
            this->wyloguj->TabIndex = 3;
            this->wyloguj->Text = L"powrot";
            this->wyloguj->UseVisualStyleBackColor = true;
            this->wyloguj->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::powrot_Click);
            // 
            // zmien_haslo
            // 
            this->zmien_haslo->Location = System::Drawing::Point(198, 247);
            this->zmien_haslo->Name = L"zmien_haslo";
            this->zmien_haslo->Size = System::Drawing::Size(88, 23);
            this->zmien_haslo->TabIndex = 4;
            this->zmien_haslo->Text = L"zmien haslo";
            this->zmien_haslo->UseVisualStyleBackColor = true;
            this->zmien_haslo->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::zmien_haslo_Click);
            // 
            // usun_konto
            // 
            this->usun_konto->Location = System::Drawing::Point(389, 450);
            this->usun_konto->Name = L"usun_konto";
            this->usun_konto->Size = System::Drawing::Size(88, 23);
            this->usun_konto->TabIndex = 5;
            this->usun_konto->Text = L"usun konto";
            this->usun_konto->UseVisualStyleBackColor = true;
            this->usun_konto->Click += gcnew System::EventHandler(this, &Zalogowany_pacjent::usun_konto_Click);
            // 
            // informacjax
            // 
            this->informacjax->AutoSize = true;
            this->informacjax->Location = System::Drawing::Point(251, 391);
            this->informacjax->Name = L"informacjax";
            this->informacjax->Size = System::Drawing::Size(0, 13);
            this->informacjax->TabIndex = 6;
            // 
            // Zalogowany_pacjent
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(515, 505);
            this->Controls->Add(this->informacjax);
            this->Controls->Add(this->usun_konto);
            this->Controls->Add(this->zmien_haslo);
            this->Controls->Add(this->wyloguj);
            this->Controls->Add(this->zaktualizuj_liste_upowaznionych);
            this->Controls->Add(this->zobacz_moje_pliki);
            this->Controls->Add(this->zobacz_moich_lekarzy);
            this->Name = L"Zalogowany_pacjent";
            this->Text = L"Zalogowany_pacjent";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Zalogowany_pacjent::Zalogowany_pacjent_FormClosing);
            this->Load += gcnew System::EventHandler(this, &Zalogowany_pacjent::Zalogowany_pacjent_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void Zalogowany_pacjent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (zamkniete == true)
		{
			previousForm->Show();
		}
	}
private: System::Void Zalogowany_pacjent_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void zobacz_moich_lekarzy_Click(System::Object^ sender, System::EventArgs^ e) {
	lista_przypisanych_pac^ lista = gcnew lista_przypisanych_pac(Login);
	this->Hide();
	lista->SetPreviousForm(this);
	lista->Show();
}
private: System::Void zobacz_moje_pliki_Click(System::Object^ sender, System::EventArgs^ e) {
	pliki_pac^ lista = gcnew pliki_pac(Login);
	this->Hide();
	lista->SetPreviousForm(this);
	lista->Show();
}
private: System::Void zaktualizuj_liste_upowaznionych_Click(System::Object^ sender, System::EventArgs^ e) {

	lista_upowaznionych^ lista = gcnew lista_upowaznionych(Login);
	this->Hide();
	lista->SetPreviousForm(this);
	lista->Show();
}
private: System::Void zmien_haslo_Click(System::Object^ sender, System::EventArgs^ e) {
    zmiana_hasla^ Zmien_haslo = gcnew zmiana_hasla(Login);
    this->Hide();
    Zmien_haslo->SetPreviousForm(this);
    Zmien_haslo->Show();
}
private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
	zamkniete = false;
	previousForm->Show();
	this->Close();
	zamkniete = true;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void usun_konto_Click(System::Object^ sender, System::EventArgs^ e) {


    MYSQL mysql;
    mysql_init(&mysql); // incjalizacja

    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
    {
        System::String^ Login2 = Login;
        std::string Login_zwykly = marshal_as<std::string>(Login2);
        std::string zapytanie = "DELETE FROM uzytkownicy WHERE login='" + Login_zwykly + "'";
        if (mysql_query(&mysql, zapytanie.c_str()) == 0)
        {

            System::String^ folderPath = "serwer\\foldery_pacjentow\\" + Login + "";
            System::IO::Directory::Delete(folderPath, true);


            String^ komunikat = "Konto usuniete";
           MessageBox::Show(komunikat);
        }
        else
        {
            this->informacjax->Text = "Blad";

        }
    }
    mysql_close(&mysql);
    previousForm->Show();
    this->Close();
}
};
}
