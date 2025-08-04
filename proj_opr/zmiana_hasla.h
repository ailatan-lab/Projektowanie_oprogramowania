#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <mysql.h>
#include <sstream>
#include <msclr/marshal_cppstd.h>

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
	/// Podsumowanie informacji o zmien_haslo
	/// </summary>
    public ref class zmiana_hasla : public System::Windows::Forms::Form
    {
    private:
        Form^ previousForm;
        System::String^ login;
    private: System::Windows::Forms::Label^ wiadomosci;
    private: System::Windows::Forms::Label^ informacja;
    private: System::Windows::Forms::Button^ zh_w_zmianie_hasla;
           // bool zamkniete = true;
    public:
        System::String^ Login;
        zmiana_hasla(System::String^ initialValue)
        {
            InitializeComponent();
            this->login = initialValue;
            //
            //TODO: W tym miejscu dodaj kod konstruktora
            //
        }
        void SetPreviousForm(Form^ previous)
        {
            previousForm = previous;
        }



    protected:
        /// <summary>
        /// Wyczyœæ wszystkie u¿ywane zasoby.
        /// </summary>
        ~zmiana_hasla()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    protected:

    protected:


    private: System::Windows::Forms::TextBox^ wprowadz_obecne_haslo;
    private: System::Windows::Forms::TextBox^ potwierdz_nowe_haslo;


    private: System::Windows::Forms::TextBox^ wprowadz_nowe_haslo;

    private: System::Windows::Forms::Button^ powrot;

    private:
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
        /// jej zawartoœci w edytorze kodu.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->wprowadz_obecne_haslo = (gcnew System::Windows::Forms::TextBox());
            this->potwierdz_nowe_haslo = (gcnew System::Windows::Forms::TextBox());
            this->wprowadz_nowe_haslo = (gcnew System::Windows::Forms::TextBox());
            this->powrot = (gcnew System::Windows::Forms::Button());
            this->wiadomosci = (gcnew System::Windows::Forms::Label());
            this->informacja = (gcnew System::Windows::Forms::Label());
            this->zh_w_zmianie_hasla = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(146, 25);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(122, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"wprowadz obecne haslo";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(146, 85);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(112, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"wprowadz nowe haslo";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(146, 148);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(109, 13);
            this->label3->TabIndex = 2;
            this->label3->Text = L"potwierdz nowe haslo";
            // 
            // wprowadz_obecne_haslo
            // 
            this->wprowadz_obecne_haslo->Location = System::Drawing::Point(149, 41);
            this->wprowadz_obecne_haslo->Name = L"wprowadz_obecne_haslo";
            this->wprowadz_obecne_haslo->Size = System::Drawing::Size(153, 20);
            this->wprowadz_obecne_haslo->TabIndex = 3;
            // 
            // potwierdz_nowe_haslo
            // 
            this->potwierdz_nowe_haslo->Location = System::Drawing::Point(149, 164);
            this->potwierdz_nowe_haslo->Name = L"potwierdz_nowe_haslo";
            this->potwierdz_nowe_haslo->Size = System::Drawing::Size(153, 20);
            this->potwierdz_nowe_haslo->TabIndex = 4;
            // 
            // wprowadz_nowe_haslo
            // 
            this->wprowadz_nowe_haslo->Location = System::Drawing::Point(149, 101);
            this->wprowadz_nowe_haslo->Name = L"wprowadz_nowe_haslo";
            this->wprowadz_nowe_haslo->Size = System::Drawing::Size(153, 20);
            this->wprowadz_nowe_haslo->TabIndex = 5;
            // 
            // powrot
            // 
            this->powrot->Location = System::Drawing::Point(189, 344);
            this->powrot->Name = L"powrot";
            this->powrot->Size = System::Drawing::Size(81, 23);
            this->powrot->TabIndex = 6;
            this->powrot->Text = L"powrot";
            this->powrot->UseVisualStyleBackColor = true;
            this->powrot->Click += gcnew System::EventHandler(this, &zmiana_hasla::powrot_Click);
            // 
            // wiadomosci
            // 
            this->wiadomosci->AutoSize = true;
            this->wiadomosci->Location = System::Drawing::Point(146, 232);
            this->wiadomosci->Name = L"wiadomosci";
            this->wiadomosci->Size = System::Drawing::Size(0, 13);
            this->wiadomosci->TabIndex = 7;
            // 
            // informacja
            // 
            this->informacja->AutoSize = true;
            this->informacja->Location = System::Drawing::Point(146, 208);
            this->informacja->Name = L"informacja";
            this->informacja->Size = System::Drawing::Size(10, 13);
            this->informacja->TabIndex = 8;
            this->informacja->Text = L" ";
            // 
            // zh_w_zmianie_hasla
            // 
            this->zh_w_zmianie_hasla->Location = System::Drawing::Point(189, 251);
            this->zh_w_zmianie_hasla->Name = L"zh_w_zmianie_hasla";
            this->zh_w_zmianie_hasla->Size = System::Drawing::Size(81, 23);
            this->zh_w_zmianie_hasla->TabIndex = 9;
            this->zh_w_zmianie_hasla->Text = L"zmien haslo";
            this->zh_w_zmianie_hasla->UseVisualStyleBackColor = true;
            this->zh_w_zmianie_hasla->Click += gcnew System::EventHandler(this, &zmiana_hasla::zh_w_zmianie_hasla_Click);
            // 
            // zmiana_hasla
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(475, 408);
            this->Controls->Add(this->zh_w_zmianie_hasla);
            this->Controls->Add(this->informacja);
            this->Controls->Add(this->wiadomosci);
            this->Controls->Add(this->powrot);
            this->Controls->Add(this->wprowadz_nowe_haslo);
            this->Controls->Add(this->potwierdz_nowe_haslo);
            this->Controls->Add(this->wprowadz_obecne_haslo);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"zmiana_hasla";
            this->Text = L"zmien_haslo";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &zmiana_hasla::zmien_haslo_FormClosing);
            this->Load += gcnew System::EventHandler(this, &zmiana_hasla::zmien_haslo_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
   private: System::Void zh_w_zmianie_hasla_Click(System::Object^ sender, System::EventArgs^ e) {
      
       std::string Haslo = marshal_as<std::string>(this->wprowadz_obecne_haslo->Text);


       


        String^ Wprowadz_obecne_haslo = this->wprowadz_obecne_haslo->Text;
        String^ Wprowadz_nowe_haslo = this->wprowadz_nowe_haslo->Text;
        String^ Potwierdz_nowe_haslo = this->potwierdz_nowe_haslo->Text;

        if (Wprowadz_obecne_haslo == nullptr || Wprowadz_obecne_haslo == "")
        {
            this->wprowadz_obecne_haslo->Text = "";
            this->informacja->Text = "Nie podano hasla";
        }
        else if (Wprowadz_nowe_haslo == nullptr || Wprowadz_nowe_haslo == "")
        {
            this->wprowadz_nowe_haslo->Text = "";
            this->informacja->Text = "Nie podano nowego hasla";
        }
        else if (Potwierdz_nowe_haslo == nullptr || Potwierdz_nowe_haslo == "")
        {
            this->potwierdz_nowe_haslo->Text = "";
            this->informacja->Text = "Nie potwierdzono hasla";
        }
        else if (Potwierdz_nowe_haslo != Wprowadz_nowe_haslo)
        {
            this->informacja->Text = "Hasla siê nie zgadzaj¹";
        }
        else if (Wprowadz_nowe_haslo == Wprowadz_obecne_haslo)
        {
            this->informacja->Text = "Nowe haslo nie moze byc takie samo jak stare";
        }
        ///*else if (Wprowadz_obecne_haslo != haslo)
        //* {
        //* this->informacja->Text = "Bledne obecne haslo";
        //* }
        //*/
        else
        {

            this->informacja->Text = "Haslo zostalo zmienione";



                MYSQL mysql;
                mysql_init(&mysql); // incjalizacja

                if (mysql_real_connect(&mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
                {
                    System::String^ Login2 = this->login;
                    std::string Login_zwykly = marshal_as<std::string>(Login2);
                    std::string Wprowadz_nowe_haslo = marshal_as<std::string>(this->wprowadz_nowe_haslo->Text);
                    std::string zapytanie = "SELECT haslo FROM uzytkownicy WHERE login='" + Login_zwykly + "'";
                    if (mysql_query(&mysql, zapytanie.c_str()) == 0)
                    {
                        MYSQL_RES* result = mysql_store_result(&mysql);
                        if (result)
                        {
                            MYSQL_ROW row = mysql_fetch_row(result);
                             //Sprawdzenie, czy coœ zosta³o zwrócone
                            if (row != NULL)
                            {
                                std::string Obecne_haslo = row[0];

                                if (Haslo == Obecne_haslo)
                                {
                                    std::string zapytanie = "UPDATE uzytkownicy SET haslo='" + Wprowadz_nowe_haslo +"' WHERE login = '" + Login_zwykly + "'";
                                    if (mysql_query(&mysql, zapytanie.c_str()) == 0)
                                        this->informacja->Text = "Haslo zostalo zmienione";
                                    this->wprowadz_obecne_haslo->Text = "";
                                    this->wprowadz_nowe_haslo->Text = "";
                                    this->potwierdz_nowe_haslo->Text = "";
                                }
                                else
                                {
                                    this->informacja->Text = "Obecne haslo siê nie zgadza";
                                }

                            }
                            else
                            {
                                this->informacja->Text = "Blad!!!!";

                            }
                        }
                    }
                }
                mysql_close(&mysql);
            


            }
        }




    private: System::Void zmien_haslo_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
     //   if (zamkniete == true)
        {
          //  previousForm->Show();
        }
    }
    private: System::Void zmien_haslo_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
      //  zamkniete = false;
        previousForm->Show();
        this->Close();
       // zamkniete = true;
    }
    };
}
