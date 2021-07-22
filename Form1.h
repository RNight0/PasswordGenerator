#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	/// 
	struct passwordinfo
	{
		int specialcaracters, numbers, uppercases, lowercases;
		bool repetitivecharacters;
	}pwdinfo, counter;


	char lowercaseletters[50] = "abcdefghijklmnopqrstuvwxyz";
	char uppercaseletters[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char specialcharacters[50] = "!#$%&'()*+-./:;<=>?@[\]^-`{|}~";
	char numbers[11] = "0123456789";
	char passwordformcharracters[5] = "Aans";
	int passwordlength, c = 0, emptyplaces[2050], numberofemptyplaces;
	char password[2050];
	char passwordform[2050];


	void removeemptyplace(int x)
	{

		int j;

		for (j = x; j < numberofemptyplaces; j++)
		{
			emptyplaces[j] = emptyplaces[j + 1];
		}
		emptyplaces[numberofemptyplaces] = 0;
		numberofemptyplaces -= 1;

	}


	void generateform()
	{
		srand(time(0));
		int RandIndex;
		int p;
		counter.numbers = 0;
		counter.specialcaracters = 0;
		counter.lowercases = 0;
		counter.uppercases = 0;
		numberofemptyplaces = passwordlength;
		//generam o forma doar cu caractere e(empty)
		int generatelocations = 1, checkpwdform = 0;
		int maxupercases, maxlowercases;
		//generam locurile pentru caracterele speciale
		memset(passwordform, 0, 2050);
		for (c = 0; c < passwordlength; c++)
		{
			passwordform[c] = 'e';
		}

		//generam un array in care pastram toate locurile libere
		for (c = 0; c < passwordlength; c++)
		{
			emptyplaces[c] = c + 1;
		}
		int remainingcharacters = passwordlength - pwdinfo.numbers - pwdinfo.specialcaracters;
		maxupercases = rand() % remainingcharacters / 2 + remainingcharacters / 4;
		do
		{
			RandIndex = rand() % numberofemptyplaces;
			switch (generatelocations) {
			case 1: if (counter.specialcaracters < pwdinfo.specialcaracters) {
				passwordform[emptyplaces[RandIndex] - 1] = 's';


				counter.specialcaracters += 1;
				removeemptyplace(RandIndex);
			}
				  else generatelocations += 1;
				break;
			case 2:  if (counter.numbers < pwdinfo.numbers) {
				passwordform[emptyplaces[RandIndex] - 1] = 'n';
				counter.numbers += 1;
				removeemptyplace(RandIndex);
			}
				  else generatelocations += 1;
				break;
			case 3:  if (counter.uppercases < maxupercases) {
				passwordform[emptyplaces[RandIndex] - 1] = 'A';
				counter.uppercases += 1;
				removeemptyplace(RandIndex);
			}
				  else generatelocations += 1;
				break;
			case 4:  for (counter.lowercases = 0; counter.lowercases < passwordlength; counter.lowercases++)
			{
				if (passwordform[counter.lowercases] == 'e') passwordform[counter.lowercases] = 'a';
			}
				  generatelocations += 1;
				  break;
			case 5: checkpwdform = 1;
				break;
			}
		} while (checkpwdform == 0);


	}


	void generatepassword()
	{
		generateform();
		int c;
		int dim;
		strcpy_s(password, passwordform);

		char l[50], prec[50] = " ";
		for (c = 0; c < passwordlength; c++)
		{
		retry:
			if (password[c] == 'A') { 
			dim = strlen(uppercaseletters) - 1;
			l[0] = uppercaseletters[rand() % dim];
			}

			else if (password[c] == 'a') {
				dim = strlen(lowercaseletters) - 1;
				l[0] = lowercaseletters[rand() % dim];
			}
			else if (password[c] == 's') { 
				dim = strlen(specialcharacters) ;
				if (dim > 1) l[0] = specialcharacters[rand() % dim];
				else l[0] = specialcharacters[0];
			}
			else { dim = strlen(numbers) - 1; l[0] = numbers[rand() % dim]-1; }
			if (l[0] == prec[0])
				if (strlen(specialcharacters) == 1 && l[0] == prec[0]) {}
				else
				goto retry;

			password[c] = l[0];
			prec[0] = l[0];
		}
	}

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ pwd;
	private: System::Windows::Forms::Button^ saveas;
	protected:

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ specialcharacterslist;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ maxspecialcharacters;
	private: System::Windows::Forms::NumericUpDown^ maxnumbers;
	private: System::Windows::Forms::NumericUpDown^ pwdlength;
	private: System::Windows::Forms::Button^ GeneratePassword;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pwd = (gcnew System::Windows::Forms::TextBox());
			this->saveas = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->specialcharacterslist = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->maxspecialcharacters = (gcnew System::Windows::Forms::NumericUpDown());
			this->maxnumbers = (gcnew System::Windows::Forms::NumericUpDown());
			this->pwdlength = (gcnew System::Windows::Forms::NumericUpDown());
			this->GeneratePassword = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxspecialcharacters))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxnumbers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pwdlength))->BeginInit();
			this->SuspendLayout();
			// 
			// pwd
			// 
			this->pwd->Location = System::Drawing::Point(19, 382);
			this->pwd->Name = L"pwd";
			this->pwd->ReadOnly = true;
			this->pwd->Size = System::Drawing::Size(508, 22);
			this->pwd->TabIndex = 48;
			// 
			// saveas
			// 
			this->saveas->Location = System::Drawing::Point(287, 410);
			this->saveas->Name = L"saveas";
			this->saveas->Size = System::Drawing::Size(240, 41);
			this->saveas->TabIndex = 47;
			this->saveas->Text = L"Save as...";
			this->saveas->UseVisualStyleBackColor = true;
			this->saveas->Click += gcnew System::EventHandler(this, &Form1::saveas_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(191, 348);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(170, 22);
			this->label6->TabIndex = 46;
			this->label6->Text = L"Generated Password:";
			// 
			// specialcharacterslist
			// 
			this->specialcharacterslist->AccessibleName = L"specialcharacterslist";
			this->specialcharacterslist->Location = System::Drawing::Point(287, 242);
			this->specialcharacterslist->Name = L"specialcharacterslist";
			this->specialcharacterslist->Size = System::Drawing::Size(240, 22);
			this->specialcharacterslist->TabIndex = 45;
			this->specialcharacterslist->Text = L"!#$%&\'()*+-./:;<=>\?@[\\]^-`{|}~";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(17, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(153, 22);
			this->label5->TabIndex = 44;
			this->label5->Text = L"Special Characters:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 410);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(240, 41);
			this->button1->TabIndex = 43;
			this->button1->Text = L"Copy to clipboard";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// maxspecialcharacters
			// 
			this->maxspecialcharacters->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->maxspecialcharacters->Location = System::Drawing::Point(287, 197);
			this->maxspecialcharacters->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 512, 0, 0, 0 });
			this->maxspecialcharacters->Name = L"maxspecialcharacters";
			this->maxspecialcharacters->Size = System::Drawing::Size(240, 27);
			this->maxspecialcharacters->TabIndex = 42;
			this->maxspecialcharacters->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// maxnumbers
			// 
			this->maxnumbers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maxnumbers->Location = System::Drawing::Point(287, 144);
			this->maxnumbers->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 512, 0, 0, 0 });
			this->maxnumbers->Name = L"maxnumbers";
			this->maxnumbers->Size = System::Drawing::Size(240, 27);
			this->maxnumbers->TabIndex = 41;
			this->maxnumbers->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// pwdlength
			// 
			this->pwdlength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pwdlength->Location = System::Drawing::Point(287, 89);
			this->pwdlength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2048, 0, 0, 0 });
			this->pwdlength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->pwdlength->Name = L"pwdlength";
			this->pwdlength->Size = System::Drawing::Size(240, 27);
			this->pwdlength->TabIndex = 40;
			this->pwdlength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// GeneratePassword
			// 
			this->GeneratePassword->AllowDrop = true;
			this->GeneratePassword->Location = System::Drawing::Point(19, 290);
			this->GeneratePassword->Name = L"GeneratePassword";
			this->GeneratePassword->Size = System::Drawing::Size(508, 41);
			this->GeneratePassword->TabIndex = 39;
			this->GeneratePassword->Text = L"Generate";
			this->GeneratePassword->UseVisualStyleBackColor = true;
			this->GeneratePassword->Click += gcnew System::EventHandler(this, &Form1::GeneratePassword_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(72, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(394, 42);
			this->label3->TabIndex = 38;
			this->label3->Text = L"Password Generator";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(16, 199);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 22);
			this->label2->TabIndex = 37;
			this->label2->Text = L"Maximum of special characters :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(15, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 22);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Maximum Numbers:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(15, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 22);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Password Length:";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 468);
			this->Controls->Add(this->pwd);
			this->Controls->Add(this->saveas);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->specialcharacterslist);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->maxspecialcharacters);
			this->Controls->Add(this->maxnumbers);
			this->Controls->Add(this->pwdlength);
			this->Controls->Add(this->GeneratePassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Password Generator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxspecialcharacters))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxnumbers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pwdlength))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void GeneratePassword_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ spcharacters = specialcharacterslist->Text;
		char *str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(spcharacters);
		strcpy(specialcharacters, str2);
		int check = 1;
		passwordlength = int(pwdlength->Value);
		pwdinfo.specialcaracters = int(maxspecialcharacters->Value);
		pwdinfo.numbers = int(maxnumbers->Value);
		int maxcharacters = passwordlength / 4;
		String^ error;
		if (pwdinfo.specialcaracters > passwordlength / 4)
		{
			error = "The maximum number of special characters allowed must be less than 1/4 of the password length.\nFor your password, the  maximum is: " + maxcharacters.ToString();
			MessageBox::Show(error, "Error");
			check = 0;
		}	
		
			if (pwdinfo.specialcaracters>0&&strlen(specialcharacters) == 0) {
				error = "Enter at least one special character ";
				MessageBox::Show(error, "Error");
				check = 0;
			}

			if (pwdinfo.numbers > passwordlength / 4)
			{
				error = "The maximum number of numbers allowed must be less than 1/4 of the password length.\nFor your password, the  maximum is: " + maxcharacters.ToString();
				MessageBox::Show(error, "Error");
				check = 0;
			}
		
	if(check==1) {

	generatepassword();
	String^ Convert = gcnew String(password);
	pwd->Text = Convert;
	}
	

}
private: System::Void saveas_Click(System::Object^ sender, System::EventArgs^ e) {
	if (strlen(password) > 0) {
		saveFileDialog1->InitialDirectory = "C:";
		saveFileDialog1->Title = "Save Text File";
		saveFileDialog1->FileName = "password";
		saveFileDialog1->Filter = "Text Files|.*txt";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
			sw->WriteLine(pwd->Text);
			sw->Close();
		}
	}
	else
	{
		String ^error = "First time generate a password!";
		MessageBox::Show(error, "Error");
	}
}
private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (strlen(password) == 0)
		{
			String ^ error = "First time generate a password!";
			MessageBox::Show(error, "Error");
		}
		else
		{
			String^ error = "The password was copied to clipboard!";
			MessageBox::Show(error, "Info");
		Clipboard::SetText(pwd->Text);
	}
}
};
}
