#pragma once
#include "pacjenci_doktora.h"
#include "zmiana_hasla.h"

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Zalogowany_doktor
	/// </summary>
	public ref class Zalogowany_doktor : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	public:
		boolean zamykanie = true;
	private: System::Windows::Forms::Button^ zmien_haslo;
	private: System::Windows::Forms::Button^ usun_konto;
    private: System::Windows::Forms::Label^ informacjax;
    public:
		System::String^ Login;
		Zalogowany_doktor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Zalogowany_doktor(System::String^ initialValue)
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
		~Zalogowany_doktor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ pokaz_moich_pacjentów;
	protected:
	private: System::Windows::Forms::Button^ powrot;

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
            this->pokaz_moich_pacjentów = (gcnew System::Windows::Forms::Button());
            this->powrot = (gcnew System::Windows::Forms::Button());
            this->zmien_haslo = (gcnew System::Windows::Forms::Button());
            this->usun_konto = (gcnew System::Windows::Forms::Button());
            this->informacjax = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // pokaz_moich_pacjentów
            // 
            this->pokaz_moich_pacjentów->Location = System::Drawing::Point(132, 113);
            this->pokaz_moich_pacjentów->Name = L"pokaz_moich_pacjentów";
            this->pokaz_moich_pacjentów->Size = System::Drawing::Size(261, 23);
            this->pokaz_moich_pacjentów->TabIndex = 0;
            this->pokaz_moich_pacjentów->Text = L"pokaz_moich_pacjentów";
            this->pokaz_moich_pacjentów->UseVisualStyleBackColor = true;
            this->pokaz_moich_pacjentów->Click += gcnew System::EventHandler(this, &Zalogowany_doktor::pokaz_moich_pacjentów_Click);
            // 
            // powrot
            // 
            this->powrot->Location = System::Drawing::Point(224, 362);
            this->powrot->Name = L"powrot";
            this->powrot->Size = System::Drawing::Size(84, 23);
            this->powrot->TabIndex = 1;
            this->powrot->Text = L"powrot";
            this->powrot->UseVisualStyleBackColor = true;
            this->powrot->Click += gcnew System::EventHandler(this, &Zalogowany_doktor::powrot_Click);
            // 
            // zmien_haslo
            // 
            this->zmien_haslo->Location = System::Drawing::Point(203, 188);
            this->zmien_haslo->Name = L"zmien_haslo";
            this->zmien_haslo->Size = System::Drawing::Size(119, 26);
            this->zmien_haslo->TabIndex = 2;
            this->zmien_haslo->Text = L"zmien haslo";
            this->zmien_haslo->UseVisualStyleBackColor = true;
            this->zmien_haslo->Click += gcnew System::EventHandler(this, &Zalogowany_doktor::zmien_haslo_Click);
            // 
            // usun_konto
            // 
            this->usun_konto->Location = System::Drawing::Point(413, 435);
            this->usun_konto->Name = L"usun_konto";
            this->usun_konto->Size = System::Drawing::Size(84, 23);
            this->usun_konto->TabIndex = 3;
            this->usun_konto->Text = L"usun konto";
            this->usun_konto->UseVisualStyleBackColor = true;
            this->usun_konto->Click += gcnew System::EventHandler(this, &Zalogowany_doktor::usun_konto_Click);
            // 
            // informacjax
            // 
            this->informacjax->AutoSize = true;
            this->informacjax->Location = System::Drawing::Point(260, 292);
            this->informacjax->Name = L"informacjax";
            this->informacjax->Size = System::Drawing::Size(0, 13);
            this->informacjax->TabIndex = 4;
            // 
            // Zalogowany_doktor
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(540, 495);
            this->Controls->Add(this->informacjax);
            this->Controls->Add(this->usun_konto);
            this->Controls->Add(this->zmien_haslo);
            this->Controls->Add(this->powrot);
            this->Controls->Add(this->pokaz_moich_pacjentów);
            this->Name = L"Zalogowany_doktor";
            this->Text = L"Zalogowany_doktor";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Zalogowany_doktor::Zalogowany_doktor_FormClosing);
            this->Load += gcnew System::EventHandler(this, &Zalogowany_doktor::Zalogowany_doktor_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
		zamykanie = false;
		previousForm->Show();
		this->Close();
	}
	private: System::Void Zalogowany_doktor_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (zamykanie == true)
		{
			previousForm->Show();
		}
	}
	private: System::Void pokaz_moich_pacjentów_Click(System::Object^ sender, System::EventArgs^ e) {
		pacjenci_doktora^ lista = gcnew pacjenci_doktora(Login);
		this->Hide();
		lista->SetPreviousForm(this);
		lista->Show();
		zamykanie = true;
	}
    private: System::Void zmien_haslo_Click(System::Object^ sender, System::EventArgs^ e) {
        zmiana_hasla^ Zmien_haslo = gcnew zmiana_hasla(Login);
        this->Hide();
        Zmien_haslo->SetPreviousForm(this);
        Zmien_haslo->Show();
    }
private: System::Void Zalogowany_doktor_Load(System::Object^ sender, System::EventArgs^ e) {
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
