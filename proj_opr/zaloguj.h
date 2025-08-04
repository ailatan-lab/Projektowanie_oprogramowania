#pragma once

#include <string.h>
#include <string>
#include <mysql.h>
#include <msclr/marshal_cppstd.h>
#include "Zalogowany_upowazniony.h"
#include "Zalogowany_pacjent.h"
#include "Zalogowany_doktor.h"

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;

	/// <summary>
	/// Summary for zaloguj
	/// </summary>
    public ref class zaloguj : public System::Windows::Forms::Form
	{
	private:
		bool zamkniete = true;



		   Form^ previousForm;
	public:
		zaloguj(void)
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
		~zaloguj()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ wiadomosci;

	private: System::Windows::Forms::TextBox^ Login;
	private: System::Windows::Forms::TextBox^ Haslo;
	private: System::Windows::Forms::Button^ zaloguj_b;
	private: System::Windows::Forms::Button^ powrot;




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
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->wiadomosci = (gcnew System::Windows::Forms::Label());
            this->Login = (gcnew System::Windows::Forms::TextBox());
            this->Haslo = (gcnew System::Windows::Forms::TextBox());
            this->zaloguj_b = (gcnew System::Windows::Forms::Button());
            this->powrot = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(229, 31);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(55, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"logowanie";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(205, 109);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(33, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Login";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(205, 191);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(34, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Haslo";
            // 
            // wiadomosci
            // 
            this->wiadomosci->AutoSize = true;
            this->wiadomosci->Location = System::Drawing::Point(205, 288);
            this->wiadomosci->Name = L"wiadomosci";
            this->wiadomosci->Size = System::Drawing::Size(35, 13);
            this->wiadomosci->TabIndex = 3;
            this->wiadomosci->Text = L"label4";
            // 
            // Login
            // 
            this->Login->Location = System::Drawing::Point(208, 125);
            this->Login->Name = L"Login";
            this->Login->Size = System::Drawing::Size(100, 20);
            this->Login->TabIndex = 4;
            // 
            // Haslo
            // 
            this->Haslo->Location = System::Drawing::Point(208, 207);
            this->Haslo->Name = L"Haslo";
            this->Haslo->Size = System::Drawing::Size(100, 20);
            this->Haslo->TabIndex = 5;
            // 
            // zaloguj_b
            // 
            this->zaloguj_b->Location = System::Drawing::Point(88, 365);
            this->zaloguj_b->Name = L"zaloguj_b";
            this->zaloguj_b->Size = System::Drawing::Size(75, 23);
            this->zaloguj_b->TabIndex = 6;
            this->zaloguj_b->Text = L"zaloguj";
            this->zaloguj_b->UseVisualStyleBackColor = true;
            this->zaloguj_b->Click += gcnew System::EventHandler(this, &zaloguj::zaloguj_b_Click);
            // 
            // powrot
            // 
            this->powrot->Location = System::Drawing::Point(373, 365);
            this->powrot->Name = L"powrot";
            this->powrot->Size = System::Drawing::Size(75, 23);
            this->powrot->TabIndex = 7;
            this->powrot->Text = L"powrot";
            this->powrot->UseVisualStyleBackColor = true;
            this->powrot->Click += gcnew System::EventHandler(this, &zaloguj::powrot_Click);
            // 
            // zaloguj
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(528, 426);
            this->Controls->Add(this->powrot);
            this->Controls->Add(this->zaloguj_b);
            this->Controls->Add(this->Haslo);
            this->Controls->Add(this->Login);
            this->Controls->Add(this->wiadomosci);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"zaloguj";
            this->Text = L"zaloguj";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &zaloguj::zaloguj_FormClosing);
            this->Load += gcnew System::EventHandler(this, &zaloguj::zaloguj_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	
private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	previousForm->Show();
}
private: System::Void zaloguj_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (zamkniete == true)
	{
		previousForm->Show();
	}
}
    private: System::Void zaloguj_b_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string Login = marshal_as<std::string>(this->Login->Text);
        std::string Haslo = marshal_as<std::string>(this->Haslo->Text);
        if (Login == "")
        {
            this->Login->Text = "";
            this->Haslo->Text = "";
            this->wiadomosci->Text = "Nie podano Loginu";
        }
        else if (Haslo == "")
        {
            this->Login->Text = "";
            this->Haslo->Text = "";
            this->wiadomosci->Text = "Nie podano Hasla";
        }
        else
        {
            this->Login->Text = "";
            this->Haslo->Text = "";

            MYSQL mysql;
            mysql_init(&mysql); // incjalizacja
            //std::string zapytanie = "SELECT login,haslo,typ_konta FROM mydb.uzytkownicy where login Like '" + Login + "' and haslo like '" + Haslo + "'";

            if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
            {
                std::string zapytanie = "SELECT login,haslo,typ_konta FROM mydb.uzytkownicy where login Like '" + Login + "' and haslo like '" + Haslo + "'";

                if (mysql_query(&mysql, zapytanie.c_str()) == 0)
                {
                    MYSQL_RES* result = mysql_store_result(&mysql);
                    if (result)
                    {
                        MYSQL_ROW row = mysql_fetch_row(result);
                        // Sprawdzenie, czy coś zostało zwrócone
                        if (row != NULL)
                        {
                            int typ_konta = atoi(row[2]);
                            if (typ_konta == 0)
                            {
                                String^ Login2 = gcnew String(Login.c_str());
                                Zalogowany_pacjent^ logowanie = gcnew Zalogowany_pacjent(Login2);
                                logowanie->Show();

                                zamkniete = false;
                                this->Close();
                                logowanie->SetPreviousForm(previousForm);
                                logowanie->Show();
                            }
                            else if (typ_konta == 1)
                            {
                                String^ Login2 = gcnew String(Login.c_str());
                                Zalogowany_upowazniony^ logowanie = gcnew Zalogowany_upowazniony(Login2);

                                zamkniete = false;
                                this->Close();
                                logowanie->SetPreviousForm(previousForm);
                                logowanie->Show();
                            }
                            else if (typ_konta == 2)
                            {
                                String^ Login2 = gcnew String(Login.c_str());
                                Zalogowany_doktor^ logowanie = gcnew Zalogowany_doktor(Login2);

                                zamkniete = false;
                                this->Close();
                                logowanie->SetPreviousForm(previousForm);
                                logowanie->Show();
                            }

                        }
                        else
                        {

                            this->wiadomosci->Text = "niepoprawny login lub haslo";
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
private: System::Void zaloguj_Load(System::Object^ sender, System::EventArgs^ e) {
	this->Login->Text = "";
	this->Haslo->Text = "";
	this->wiadomosci->Text = "";
}
    
};
}
