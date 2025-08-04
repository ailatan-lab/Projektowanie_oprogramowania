#pragma once

#include <mysql.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "sql_manager.h"

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for lista_przypisanych_pac
	/// </summary>


	public ref class lista_przypisanych_pac : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Button^ powrot;
	public:
		bool zamkniete = true;
	private: System::Windows::Forms::Label^ wiadomosci;
	private: System::Windows::Forms::ColumnHeader^ imie;
	private: System::Windows::Forms::ColumnHeader^ nazwisko;
	private: System::Windows::Forms::ColumnHeader^ specjalizacja;
	public:


		System::String^ Login;
		lista_przypisanych_pac(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		lista_przypisanych_pac(System::String^ initialValue)
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
		~lista_przypisanych_pac()
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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->imie = (gcnew System::Windows::Forms::ColumnHeader());
			this->nazwisko = (gcnew System::Windows::Forms::ColumnHeader());
			this->specjalizacja = (gcnew System::Windows::Forms::ColumnHeader());
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->imie, this->nazwisko,
					this->specjalizacja
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(74, 28);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(520, 320);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// imie
			// 
			this->imie->Text = L"imie";
			this->imie->Width = 98;
			// 
			// nazwisko
			// 
			this->nazwisko->Text = L"nazwisko";
			this->nazwisko->Width = 156;
			// 
			// specjalizacja
			// 
			this->specjalizacja->Text = L"specjalizacja";
			this->specjalizacja->Width = 175;
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(74, 517);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(182, 23);
			this->powrot->TabIndex = 3;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &lista_przypisanych_pac::powrot_Click);
			// 
			// wiadomosci
			// 
			this->wiadomosci->AutoSize = true;
			this->wiadomosci->Location = System::Drawing::Point(469, 452);
			this->wiadomosci->Name = L"wiadomosci";
			this->wiadomosci->Size = System::Drawing::Size(35, 13);
			this->wiadomosci->TabIndex = 4;
			this->wiadomosci->Text = L"label1";
			// 
			// lista_przypisanych_pac
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 646);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->powrot);
			this->Controls->Add(this->listView1);
			this->Name = L"lista_przypisanych_pac";
			this->Text = L"lista_upowaznionych";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &lista_przypisanych_pac::lista_upowaznionych_FormClosing);
			this->Load += gcnew System::EventHandler(this, &lista_przypisanych_pac::lista_upowaznionych_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lista_upowaznionych_Load(System::Object^ sender, System::EventArgs^ e) {
		this->wiadomosci->Text = "";
		MySqlConnectionManager::InitializeConnection();

		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string zapytanie = "select doktorzy.imie, doktorzy.nazwisko, doktorzy.specjalizacja from doktorzy join przypisania_doktorow on przypisania_doktorow.id_doktora = doktorzy.iddoktorzy join pacjenci on przypisania_doktorow.pesel_pacjenta = pacjenci.numer_pesel where pacjenci.login like '"+ Login_zwykly +"'";
			if (mysql_query(mysql, zapytanie.c_str()) == 0)
			{
				MYSQL_RES* result = mysql_store_result(mysql);
				if (result)
				{
					while (MYSQL_ROW row = mysql_fetch_row(result)) {
						// Access individual columns by index
						std::string column1 = row[0] ? row[0] : "-";
						std::string column2 = row[1] ? row[1] : "-";
						std::string column3 = row[2] ? row[2] : "-";

						System::String^ sysColumn1 = gcnew String(column1.c_str());
						System::String^ sysColumn2 = gcnew String(column2.c_str());
						System::String^ sysColumn3 = gcnew String(column3.c_str());

						ListViewItem^ item = gcnew ListViewItem(sysColumn1);  // Text for the first column

						item->SubItems->Add(sysColumn2);  // Text for the second column
						item->SubItems->Add(sysColumn3);

						this->listView1->Items->Add(item);


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

	}
	private: System::Void lista_upowaznionych_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (zamkniete == true)
		{
			previousForm->Show();
		}
	}
	private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
		MySqlConnectionManager::CloseConnection();

		zamkniete = false;
		previousForm->Show();
		this->Close();
	}
	
};
}