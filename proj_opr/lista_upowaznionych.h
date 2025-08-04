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
	/// Summary for lista_upowaznionych
	/// </summary>

	
	public ref class lista_upowaznionych : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::ListView^ listView1;

	private: System::Windows::Forms::Button^ zmien_upowaz;
	private: System::Windows::Forms::Button^ zmien_upowaznienie;

	private: System::Windows::Forms::Button^ powrot;
	public:
			bool zamkniete = true;
	private: System::Windows::Forms::Label^ wiadomosci;
	private: System::Windows::Forms::ColumnHeader^ imie;
	private: System::Windows::Forms::ColumnHeader^ nazwisko;
	private: System::Windows::Forms::ColumnHeader^ adres;
	private: System::Windows::Forms::ColumnHeader^ pesel;
	private: System::Windows::Forms::ColumnHeader^ czy_upowazniony;
	public:

		bool upowaznieni = true;
		System::String^ Login;
		lista_upowaznionych(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		lista_upowaznionych(System::String^ initialValue)
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
		~lista_upowaznionych()
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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->imie = (gcnew System::Windows::Forms::ColumnHeader());
			this->nazwisko = (gcnew System::Windows::Forms::ColumnHeader());
			this->adres = (gcnew System::Windows::Forms::ColumnHeader());
			this->pesel = (gcnew System::Windows::Forms::ColumnHeader());
			this->czy_upowazniony = (gcnew System::Windows::Forms::ColumnHeader());
			this->zmien_upowaz = (gcnew System::Windows::Forms::Button());
			this->zmien_upowaznienie = (gcnew System::Windows::Forms::Button());
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->imie, this->nazwisko,
					this->adres, this->pesel, this->czy_upowazniony
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(74, 28);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(520, 320);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &lista_upowaznionych::listView1_SelectedIndexChanged);
			// 
			// imie
			// 
			this->imie->Text = L"imie";
			// 
			// nazwisko
			// 
			this->nazwisko->Text = L"nazwisko";
			// 
			// adres
			// 
			this->adres->Text = L"adres";
			// 
			// pesel
			// 
			this->pesel->Text = L"pesel";
			// 
			// czy_upowazniony
			// 
			this->czy_upowazniony->Text = L"czy_upowazniony";
			// 
			// zmien_upowaz
			// 
			this->zmien_upowaz->Location = System::Drawing::Point(74, 383);
			this->zmien_upowaz->Name = L"zmien_upowaz";
			this->zmien_upowaz->Size = System::Drawing::Size(182, 23);
			this->zmien_upowaz->TabIndex = 1;
			this->zmien_upowaz->Text = L"pokaz nie upowaznionych";
			this->zmien_upowaz->UseVisualStyleBackColor = true;
			this->zmien_upowaz->Click += gcnew System::EventHandler(this, &lista_upowaznionych::zmien_upowaz_Click);
			// 
			// zmien_upowaznienie
			// 
			this->zmien_upowaznienie->Location = System::Drawing::Point(74, 447);
			this->zmien_upowaznienie->Name = L"zmien_upowaznienie";
			this->zmien_upowaznienie->Size = System::Drawing::Size(182, 23);
			this->zmien_upowaznienie->TabIndex = 2;
			this->zmien_upowaznienie->Text = L"usun upowaznienie";
			this->zmien_upowaznienie->UseVisualStyleBackColor = true;
			this->zmien_upowaznienie->Click += gcnew System::EventHandler(this, &lista_upowaznionych::zmien_upowaznienie_Click);
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(74, 517);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(182, 23);
			this->powrot->TabIndex = 3;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &lista_upowaznionych::powrot_Click);
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
			// lista_upowaznionych
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1025, 646);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->powrot);
			this->Controls->Add(this->zmien_upowaznienie);
			this->Controls->Add(this->zmien_upowaz);
			this->Controls->Add(this->listView1);
			this->Name = L"lista_upowaznionych";
			this->Text = L"lista_upowaznionych";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &lista_upowaznionych::lista_upowaznionych_FormClosing);
			this->Load += gcnew System::EventHandler(this, &lista_upowaznionych::lista_upowaznionych_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lista_upowaznionych_Load(System::Object^ sender, System::EventArgs^ e) {
		upowaznieni = true;
		this->zmien_upowaz->Text = "Pokaz nieupowaznionych";
		this->zmien_upowaznienie->Text = "usun z upowaznionych";

		this->wiadomosci->Text = "";
		MySqlConnectionManager::InitializeConnection();

		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string zapytanie = "Select upowaznieni.imie,upowaznieni.nazwisko,upowaznieni.adres,upowaznieni.idupowaznieni_pesel, upowaznienia.czy_upowaznione from upowaznieni join upowaznienia on upowaznienia.pesel_upowazniony = upowaznieni.idupowaznieni_pesel join pacjenci on upowaznienia.pesel_pacjent = pacjenci.numer_pesel where pacjenci.login like '"+ Login_zwykly +"' and upowaznienia.czy_upowaznione = true";
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
							std::string column4 = row[3] ? row[3] : "-";
							std::string column5 = row[4] ? row[4] : "-";

							System::String^ sysColumn1 = gcnew String(column1.c_str());
							System::String^ sysColumn2 = gcnew String(column2.c_str());
							System::String^ sysColumn3 = gcnew String(column3.c_str());
							System::String^ sysColumn4 = gcnew String(column4.c_str());
							System::String^ sysColumn5 = gcnew String(column5.c_str());

							ListViewItem^ item = gcnew ListViewItem(sysColumn1);  // Text for the first column

							item->SubItems->Add(sysColumn2);  // Text for the second column
							item->SubItems->Add(sysColumn3);  // Text for the third column
							item->SubItems->Add(sysColumn4);
							item->SubItems->Add(sysColumn5);

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
			mysql_close(mysql);
		}

	}
	private: System::Void lista_upowaznionych_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (zamkniete == true)
		{
			previousForm->Show();
		}
	}
	private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
		
		zamkniete = false;
		previousForm->Show();
		this->Close();
	}
private: System::Void zmien_upowaz_Click(System::Object^ sender, System::EventArgs^ e) {
	if(upowaznieni==true)
	{
		upowaznieni = false;
		this->zmien_upowaz->Text = "Pokaz upowaznionych";
		this->zmien_upowaznienie->Text = "dodaj do upowaznionych";

		this->listView1->Items->Clear();

		MySqlConnectionManager::InitializeConnection();

		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string zapytanie = "Select upowaznieni.imie,upowaznieni.nazwisko,upowaznieni.adres,upowaznieni.idupowaznieni_pesel, upowaznienia.czy_upowaznione from upowaznieni join upowaznienia on upowaznienia.pesel_upowazniony = upowaznieni.idupowaznieni_pesel join pacjenci on upowaznienia.pesel_pacjent = pacjenci.numer_pesel where pacjenci.login like '" + Login_zwykly + "' and upowaznienia.czy_upowaznione = false";
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
						std::string column4 = row[3] ? row[3] : "-";
						std::string column5 = row[4] ? row[4] : "-";

						System::String^ sysColumn1 = gcnew String(column1.c_str());
						System::String^ sysColumn2 = gcnew String(column2.c_str());
						System::String^ sysColumn3 = gcnew String(column3.c_str());
						System::String^ sysColumn4 = gcnew String(column4.c_str());
						System::String^ sysColumn5 = gcnew String(column5.c_str());

						ListViewItem^ item = gcnew ListViewItem(sysColumn1);  // Text for the first column

						item->SubItems->Add(sysColumn2);  // Text for the second column
						item->SubItems->Add(sysColumn3);  // Text for the third column
						item->SubItems->Add(sysColumn4);
						item->SubItems->Add(sysColumn5);

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
		mysql_close(mysql);

	}

	else
	{
		upowaznieni = true;
		this->zmien_upowaz->Text = "Pokaz nieupowaznionych";
		this->zmien_upowaznienie->Text = "usun z upowaznionych";

		this->listView1->Items->Clear();

		MySqlConnectionManager::InitializeConnection();

		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string zapytanie = "Select upowaznieni.imie,upowaznieni.nazwisko,upowaznieni.adres,upowaznieni.idupowaznieni_pesel, upowaznienia.czy_upowaznione from upowaznieni join upowaznienia on upowaznienia.pesel_upowazniony = upowaznieni.idupowaznieni_pesel join pacjenci on upowaznienia.pesel_pacjent = pacjenci.numer_pesel where pacjenci.login like '" + Login_zwykly + "' and upowaznienia.czy_upowaznione = true";
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
						std::string column4 = row[3] ? row[3] : "-";
						std::string column5 = row[4] ? row[4] : "-";

						System::String^ sysColumn1 = gcnew String(column1.c_str());
						System::String^ sysColumn2 = gcnew String(column2.c_str());
						System::String^ sysColumn3 = gcnew String(column3.c_str());
						System::String^ sysColumn4 = gcnew String(column4.c_str());
						System::String^ sysColumn5 = gcnew String(column5.c_str());

						ListViewItem^ item = gcnew ListViewItem(sysColumn1);  // Text for the first column

						item->SubItems->Add(sysColumn2);  // Text for the second column
						item->SubItems->Add(sysColumn3);  // Text for the third column
						item->SubItems->Add(sysColumn4);
						item->SubItems->Add(sysColumn5);

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
		mysql_close(mysql);
	}


}
private: System::Void zmien_upowaznienie_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = 0;
	for each (ListViewItem ^ selectedItem in listView1->SelectedItems)
	{
		System::String^ pesel = selectedItem->SubItems[2]->Text;

		MySqlConnectionManager::InitializeConnection();

		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{
			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string pesel_zwykly = marshal_as<std::string>(pesel);
			std::string zapytanie;

			if (upowaznieni == true)
			{
				zapytanie = "update upowaznienia join pacjenci on pacjenci.numer_pesel = upowaznienia.pesel_pacjent set czy_upowaznione = false where pacjenci.login like '"+Login_zwykly+"' and upowaznienia.pesel_upowazniony = '" + pesel_zwykly + "'";
			}
			else
			{
				zapytanie = "update upowaznienia join pacjenci on pacjenci.numer_pesel = upowaznienia.pesel_pacjent set czy_upowaznione = true where pacjenci.login like '" + Login_zwykly + "' and upowaznienia.pesel_upowazniony = '" + pesel_zwykly + "'";
			}

			if (mysql_query(mysql, zapytanie.c_str()) == 0)
			{
				i++;
			}
			else
			{
				this->wiadomosci->Text = "mysql_query() failed";
			}
		}
		mysql_close(mysql);

		
	}
	this->wiadomosci->Text = "zmieniono status "+i+" osob";
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
