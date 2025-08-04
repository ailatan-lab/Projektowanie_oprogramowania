#pragma once

#include <mysql.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "sql_manager.h"
#include "pliki_pac.h"

namespace projopr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for pacjenci_doktora
	/// </summary>
	public ref class pacjenci_doktora : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm;
	private: System::Windows::Forms::Button^ powrot;
	private: System::Windows::Forms::Button^ zobacz_pliki;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ wiadomosci;
	private: System::Windows::Forms::ColumnHeader^ imie;
	public:
	private: System::Windows::Forms::ColumnHeader^ nazwisko;
	private: System::Windows::Forms::ColumnHeader^ adres;
	private: System::Windows::Forms::ColumnHeader^ pesel;
	public:
		bool zamykanie = true;

	public:
		System::String^ Login;
		pacjenci_doktora(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		pacjenci_doktora(System::String^ initialValue)
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
		~pacjenci_doktora()
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
			this->powrot = (gcnew System::Windows::Forms::Button());
			this->zobacz_pliki = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->imie = (gcnew System::Windows::Forms::ColumnHeader());
			this->nazwisko = (gcnew System::Windows::Forms::ColumnHeader());
			this->adres = (gcnew System::Windows::Forms::ColumnHeader());
			this->pesel = (gcnew System::Windows::Forms::ColumnHeader());
			this->wiadomosci = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// powrot
			// 
			this->powrot->Location = System::Drawing::Point(369, 388);
			this->powrot->Name = L"powrot";
			this->powrot->Size = System::Drawing::Size(75, 23);
			this->powrot->TabIndex = 0;
			this->powrot->Text = L"powrot";
			this->powrot->UseVisualStyleBackColor = true;
			this->powrot->Click += gcnew System::EventHandler(this, &pacjenci_doktora::powrot_Click);
			// 
			// zobacz_pliki
			// 
			this->zobacz_pliki->Location = System::Drawing::Point(111, 388);
			this->zobacz_pliki->Name = L"zobacz_pliki";
			this->zobacz_pliki->Size = System::Drawing::Size(75, 23);
			this->zobacz_pliki->TabIndex = 1;
			this->zobacz_pliki->Text = L"zobacz_pliki";
			this->zobacz_pliki->UseVisualStyleBackColor = true;
			this->zobacz_pliki->Click += gcnew System::EventHandler(this, &pacjenci_doktora::zobacz_pliki_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->imie, this->nazwisko,
					this->adres, this->pesel
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(91, 47);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(317, 268);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// wiadomosci
			// 
			this->wiadomosci->AutoSize = true;
			this->wiadomosci->Location = System::Drawing::Point(253, 340);
			this->wiadomosci->Name = L"wiadomosci";
			this->wiadomosci->Size = System::Drawing::Size(35, 13);
			this->wiadomosci->TabIndex = 3;
			this->wiadomosci->Text = L"label1";
			// 
			// pacjenci_doktora
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 452);
			this->Controls->Add(this->wiadomosci);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->zobacz_pliki);
			this->Controls->Add(this->powrot);
			this->Name = L"pacjenci_doktora";
			this->Text = L"pacjenci_doktora";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &pacjenci_doktora::pacjenci_doktora_FormClosing);
			this->Load += gcnew System::EventHandler(this, &pacjenci_doktora::pacjenci_doktora_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pacjenci_doktora_Load(System::Object^ sender, System::EventArgs^ e) {

		this->wiadomosci->Text = "";
		MySqlConnectionManager::InitializeConnection();
		MYSQL* mysql = MySqlConnectionManager::mysql;

		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
		{

			//nie wiem po co to ale bez tego nie dziala
			System::String^ Login2 = Login;
			std::string Login_zwykly = marshal_as<std::string>(Login2);
			std::string zapytanie = "SELECT pacjenci.imie,pacjenci.nazwisko,pacjenci.adres,pacjenci.numer_pesel from pacjenci join przypisania_doktorow on przypisania_doktorow.pesel_pacjenta = pacjenci.numer_pesel join doktorzy on doktorzy.iddoktorzy = przypisania_doktorow.id_doktora where doktorzy.login like '"+Login_zwykly+"'";
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

						System::String^ sysColumn1 = gcnew String(column1.c_str());
						System::String^ sysColumn2 = gcnew String(column2.c_str());
						System::String^ sysColumn3 = gcnew String(column3.c_str());
						System::String^ sysColumn4 = gcnew String(column4.c_str());

						ListViewItem^ item = gcnew ListViewItem(sysColumn1);  // Text for the first column

						item->SubItems->Add(sysColumn2);  // Text for the second column
						item->SubItems->Add(sysColumn3);
						item->SubItems->Add(sysColumn4);

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
		MySqlConnectionManager::CloseConnection();
	}
	private: System::Void pacjenci_doktora_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (zamykanie = true)
		{
			previousForm->Show();
		}
	}
	private: System::Void zobacz_pliki_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->SelectedItems->Count > 0)
		{
			ListViewItem^ selectedItem = listView1->SelectedItems[0];

			System::String^ Pesel = selectedItem->SubItems[3]->Text;
			std::string Login_pac;

			MySqlConnectionManager::InitializeConnection();
			MYSQL* mysql = MySqlConnectionManager::mysql;

			if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "mydb", 4306, NULL, 0))
			{
				std::string Pesel_zwykly = marshal_as<std::string>(Pesel);
				std::string zapytanie = "SELECT login from pacjenci where numer_pesel = " + Pesel_zwykly;
				if (mysql_query(mysql, zapytanie.c_str()) == 0)
				{
					MYSQL_RES* result = mysql_store_result(mysql);
					if (result)
					{
						MYSQL_ROW row = mysql_fetch_row(result);

						if (row)
						{
							Login_pac = row[0] ? row[0] : "";
						}
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
			MySqlConnectionManager::CloseConnection();

			zamykanie = false;
			System::String^ Login_pacS = msclr::interop::marshal_as<System::String^>(Login_pac);
			pliki_pac^ lista = gcnew pliki_pac(Login_pacS);
			this->Hide();
			lista->SetPreviousForm(this);
			lista->Show();
			zamykanie = true;
		}
	}
	private: System::Void powrot_Click(System::Object^ sender, System::EventArgs^ e) {
		zamykanie = false;
		previousForm->Show();
		this->Close();
	}
	};
}
