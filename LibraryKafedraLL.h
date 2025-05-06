#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>  // Для функції transform
#include <msclr/marshal_cppstd.h>

namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	// Структура для зберігання інформації про видання
	struct Publication {
		string title;       // Назва
		string author;      // Автор
		string type;        // Тип видання
		string description; // Опис
		int pages;          // Кількість сторінок
		int year;           // Рік видання
		string publisher;   // Видавництво
	};

	// Глобальний вектор для зберігання всіх видань
	vector<Publication> publications;

	// Функція для перетворення System::String^ в std::string
	string toStdString(String^ str) {
		return msclr::interop::marshal_as<std::string>(str);
	}

	// Функція для перетворення std::string в System::String^
	String^ toSystemString(const string& str) {
		return gcnew String(str.c_str());
	}

	/// <summary>
	/// Електронна бібліотека кафедри
	/// </summary>
	public ref class LibraryForm : public System::Windows::Forms::Form
	{
	public:
		LibraryForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		~LibraryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;

		   // Элементы интерфейса - публичные для доступа из Library.cpp
	public: System::Windows::Forms::TabControl^ tabControl;
	public: System::Windows::Forms::TabPage^ tabPageAddRecord;
	public: System::Windows::Forms::TabPage^ tabPageStatistics;
	public: System::Windows::Forms::TabPage^ tabPageSearch;

		  // Додавання запису
	public: System::Windows::Forms::Label^ lblTitle;
	public: System::Windows::Forms::TextBox^ txtTitle;
	public: System::Windows::Forms::Label^ lblAuthor;
	public: System::Windows::Forms::TextBox^ txtAuthor;
	public: System::Windows::Forms::Label^ lblType;
	public: System::Windows::Forms::ComboBox^ cmbType;
	public: System::Windows::Forms::Label^ lblDescription;
	public: System::Windows::Forms::TextBox^ txtDescription;
	public: System::Windows::Forms::Label^ lblPages;
	public: System::Windows::Forms::NumericUpDown^ numPages;
	public: System::Windows::Forms::Label^ lblYear;
	public: System::Windows::Forms::NumericUpDown^ numYear;
	public: System::Windows::Forms::Label^ lblPublisher;
	public: System::Windows::Forms::TextBox^ txtPublisher;
	public: System::Windows::Forms::Button^ btnAddRecord;
	public: System::Windows::Forms::Button^ btnSaveToFile;

		  // Відображення записів (теперь в первой вкладке)
	public: System::Windows::Forms::DataGridView^ dgvRecords;
	public: System::Windows::Forms::Button^ btnLoadFromFile;

		  // Статистика
	public: System::Windows::Forms::Label^ lblStatistics;
	public: System::Windows::Forms::ListBox^ lstStatistics;
	public: System::Windows::Forms::Button^ btnCalculateStatistics;

		  // Пошук
	public: System::Windows::Forms::TabControl^ tabSearchCriteria;
	public: System::Windows::Forms::TabPage^ tabPageByAuthor;
	public: System::Windows::Forms::TabPage^ tabPageByTypeAndYear;

		  // Пошук за автором
	public: System::Windows::Forms::Label^ lblSearchAuthor;
	public: System::Windows::Forms::TextBox^ txtSearchAuthor;
	public: System::Windows::Forms::Button^ btnSearchByAuthor;
	public: System::Windows::Forms::DataGridView^ dgvAuthorResults;

		  // Пошук за типом і роком
	public: System::Windows::Forms::Label^ lblSearchType;
	public: System::Windows::Forms::ComboBox^ cmbSearchType;
	public: System::Windows::Forms::Label^ lblSearchYear;
	public: System::Windows::Forms::NumericUpDown^ numSearchYear;
	public: System::Windows::Forms::Button^ btnSearchByTypeAndYear;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::DataGridView^ dgvTypeYearResults;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageAddRecord = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->txtTitle = (gcnew System::Windows::Forms::TextBox());
			this->lblAuthor = (gcnew System::Windows::Forms::Label());
			this->txtAuthor = (gcnew System::Windows::Forms::TextBox());
			this->lblType = (gcnew System::Windows::Forms::Label());
			this->cmbType = (gcnew System::Windows::Forms::ComboBox());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblPages = (gcnew System::Windows::Forms::Label());
			this->numPages = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblYear = (gcnew System::Windows::Forms::Label());
			this->numYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblPublisher = (gcnew System::Windows::Forms::Label());
			this->txtPublisher = (gcnew System::Windows::Forms::TextBox());
			this->btnAddRecord = (gcnew System::Windows::Forms::Button());
			this->btnSaveToFile = (gcnew System::Windows::Forms::Button());
			this->dgvRecords = (gcnew System::Windows::Forms::DataGridView());
			this->btnLoadFromFile = (gcnew System::Windows::Forms::Button());
			this->tabPageStatistics = (gcnew System::Windows::Forms::TabPage());
			this->lblStatistics = (gcnew System::Windows::Forms::Label());
			this->lstStatistics = (gcnew System::Windows::Forms::ListBox());
			this->btnCalculateStatistics = (gcnew System::Windows::Forms::Button());
			this->tabPageSearch = (gcnew System::Windows::Forms::TabPage());
			this->tabSearchCriteria = (gcnew System::Windows::Forms::TabControl());
			this->tabPageByAuthor = (gcnew System::Windows::Forms::TabPage());
			this->lblSearchAuthor = (gcnew System::Windows::Forms::Label());
			this->txtSearchAuthor = (gcnew System::Windows::Forms::TextBox());
			this->btnSearchByAuthor = (gcnew System::Windows::Forms::Button());
			this->dgvAuthorResults = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageByTypeAndYear = (gcnew System::Windows::Forms::TabPage());
			this->lblSearchType = (gcnew System::Windows::Forms::Label());
			this->cmbSearchType = (gcnew System::Windows::Forms::ComboBox());
			this->lblSearchYear = (gcnew System::Windows::Forms::Label());
			this->numSearchYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnSearchByTypeAndYear = (gcnew System::Windows::Forms::Button());
			this->dgvTypeYearResults = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl->SuspendLayout();
			this->tabPageAddRecord->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPages))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecords))->BeginInit();
			this->tabPageStatistics->SuspendLayout();
			this->tabPageSearch->SuspendLayout();
			this->tabSearchCriteria->SuspendLayout();
			this->tabPageByAuthor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAuthorResults))->BeginInit();
			this->tabPageByTypeAndYear->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSearchYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTypeYearResults))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPageAddRecord);
			this->tabControl->Controls->Add(this->tabPageStatistics);
			this->tabControl->Controls->Add(this->tabPageSearch);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(7, 6);
			this->tabControl->Margin = System::Windows::Forms::Padding(2);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(1004, 457);
			this->tabControl->TabIndex = 0;
			// 
			// tabPageAddRecord
			// 
			this->tabPageAddRecord->BackColor = System::Drawing::SystemColors::Control;
			this->tabPageAddRecord->Controls->Add(this->label2);
			this->tabPageAddRecord->Controls->Add(this->label1);
			this->tabPageAddRecord->Controls->Add(this->lblTitle);
			this->tabPageAddRecord->Controls->Add(this->txtTitle);
			this->tabPageAddRecord->Controls->Add(this->lblAuthor);
			this->tabPageAddRecord->Controls->Add(this->txtAuthor);
			this->tabPageAddRecord->Controls->Add(this->lblType);
			this->tabPageAddRecord->Controls->Add(this->cmbType);
			this->tabPageAddRecord->Controls->Add(this->lblDescription);
			this->tabPageAddRecord->Controls->Add(this->txtDescription);
			this->tabPageAddRecord->Controls->Add(this->lblPages);
			this->tabPageAddRecord->Controls->Add(this->numPages);
			this->tabPageAddRecord->Controls->Add(this->lblYear);
			this->tabPageAddRecord->Controls->Add(this->numYear);
			this->tabPageAddRecord->Controls->Add(this->lblPublisher);
			this->tabPageAddRecord->Controls->Add(this->txtPublisher);
			this->tabPageAddRecord->Controls->Add(this->btnAddRecord);
			this->tabPageAddRecord->Controls->Add(this->btnSaveToFile);
			this->tabPageAddRecord->Controls->Add(this->dgvRecords);
			this->tabPageAddRecord->Controls->Add(this->btnLoadFromFile);
			this->tabPageAddRecord->Location = System::Drawing::Point(4, 22);
			this->tabPageAddRecord->Margin = System::Windows::Forms::Padding(2);
			this->tabPageAddRecord->Name = L"tabPageAddRecord";
			this->tabPageAddRecord->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tabPageAddRecord->Size = System::Drawing::Size(996, 431);
			this->tabPageAddRecord->TabIndex = 0;
			this->tabPageAddRecord->Text = L"Додати запис";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(259, 6);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(728, 34);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Перелік записів";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 6);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(239, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Інформація про запис";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &LibraryForm::label1_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTitle->Location = System::Drawing::Point(9, 42);
			this->lblTitle->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(129, 20);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Назва видання:";
			// 
			// txtTitle
			// 
			this->txtTitle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtTitle->Location = System::Drawing::Point(13, 64);
			this->txtTitle->Margin = System::Windows::Forms::Padding(2);
			this->txtTitle->Name = L"txtTitle";
			this->txtTitle->Size = System::Drawing::Size(234, 26);
			this->txtTitle->TabIndex = 1;
			// 
			// lblAuthor
			// 
			this->lblAuthor->AutoSize = true;
			this->lblAuthor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblAuthor->Location = System::Drawing::Point(13, 92);
			this->lblAuthor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblAuthor->Name = L"lblAuthor";
			this->lblAuthor->Size = System::Drawing::Size(60, 20);
			this->lblAuthor->TabIndex = 2;
			this->lblAuthor->Text = L"Автор:";
			// 
			// txtAuthor
			// 
			this->txtAuthor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtAuthor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtAuthor->Location = System::Drawing::Point(13, 114);
			this->txtAuthor->Margin = System::Windows::Forms::Padding(2);
			this->txtAuthor->Name = L"txtAuthor";
			this->txtAuthor->Size = System::Drawing::Size(234, 26);
			this->txtAuthor->TabIndex = 3;
			// 
			// lblType
			// 
			this->lblType->AutoSize = true;
			this->lblType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblType->Location = System::Drawing::Point(9, 142);
			this->lblType->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblType->Name = L"lblType";
			this->lblType->Size = System::Drawing::Size(109, 20);
			this->lblType->TabIndex = 4;
			this->lblType->Text = L"Тип видання:";
			// 
			// cmbType
			// 
			this->cmbType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cmbType->FormattingEnabled = true;
			this->cmbType->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Стаття", L"Тези", L"Довідник", L"Книга", L"Навчальний посібник",
					L"Монографія", L"Інше"
			});
			this->cmbType->Location = System::Drawing::Point(13, 165);
			this->cmbType->Margin = System::Windows::Forms::Padding(2);
			this->cmbType->Name = L"cmbType";
			this->cmbType->Size = System::Drawing::Size(235, 28);
			this->cmbType->TabIndex = 5;
			// 
			// lblDescription
			// 
			this->lblDescription->AutoSize = true;
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblDescription->Location = System::Drawing::Point(9, 203);
			this->lblDescription->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(51, 20);
			this->lblDescription->TabIndex = 6;
			this->lblDescription->Text = L"Опис:";
			// 
			// txtDescription
			// 
			this->txtDescription->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtDescription->Location = System::Drawing::Point(13, 225);
			this->txtDescription->Margin = System::Windows::Forms::Padding(2);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(234, 40);
			this->txtDescription->TabIndex = 7;
			// 
			// lblPages
			// 
			this->lblPages->AutoSize = true;
			this->lblPages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblPages->Location = System::Drawing::Point(10, 344);
			this->lblPages->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPages->Name = L"lblPages";
			this->lblPages->Size = System::Drawing::Size(140, 18);
			this->lblPages->TabIndex = 8;
			this->lblPages->Text = L"Кількість сторінок:";
			// 
			// numPages
			// 
			this->numPages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numPages->Location = System::Drawing::Point(154, 341);
			this->numPages->Margin = System::Windows::Forms::Padding(2);
			this->numPages->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numPages->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numPages->Name = L"numPages";
			this->numPages->Size = System::Drawing::Size(100, 26);
			this->numPages->TabIndex = 9;
			this->numPages->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lblYear
			// 
			this->lblYear->AutoSize = true;
			this->lblYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblYear->Location = System::Drawing::Point(10, 384);
			this->lblYear->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblYear->Name = L"lblYear";
			this->lblYear->Size = System::Drawing::Size(94, 18);
			this->lblYear->TabIndex = 10;
			this->lblYear->Text = L"Рік видання:";
			// 
			// numYear
			// 
			this->numYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numYear->Location = System::Drawing::Point(108, 381);
			this->numYear->Margin = System::Windows::Forms::Padding(2);
			this->numYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2025, 0, 0, 0 });
			this->numYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->numYear->Name = L"numYear";
			this->numYear->Size = System::Drawing::Size(100, 26);
			this->numYear->TabIndex = 11;
			this->numYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2024, 0, 0, 0 });
			// 
			// lblPublisher
			// 
			this->lblPublisher->AutoSize = true;
			this->lblPublisher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblPublisher->Location = System::Drawing::Point(9, 267);
			this->lblPublisher->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPublisher->Name = L"lblPublisher";
			this->lblPublisher->Size = System::Drawing::Size(116, 20);
			this->lblPublisher->TabIndex = 12;
			this->lblPublisher->Text = L"Видавництво:";
			// 
			// txtPublisher
			// 
			this->txtPublisher->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->txtPublisher->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPublisher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtPublisher->Location = System::Drawing::Point(13, 295);
			this->txtPublisher->Margin = System::Windows::Forms::Padding(2);
			this->txtPublisher->Name = L"txtPublisher";
			this->txtPublisher->Size = System::Drawing::Size(234, 26);
			this->txtPublisher->TabIndex = 13;
			// 
			// btnAddRecord
			// 
			this->btnAddRecord->Location = System::Drawing::Point(259, 377);
			this->btnAddRecord->Margin = System::Windows::Forms::Padding(2);
			this->btnAddRecord->Name = L"btnAddRecord";
			this->btnAddRecord->Size = System::Drawing::Size(240, 46);
			this->btnAddRecord->TabIndex = 14;
			this->btnAddRecord->Text = L"Додати запис";
			this->btnAddRecord->UseVisualStyleBackColor = true;
			this->btnAddRecord->Click += gcnew System::EventHandler(this, &LibraryForm::btnAddRecord_Click);
			// 
			// btnSaveToFile
			// 
			this->btnSaveToFile->Location = System::Drawing::Point(747, 377);
			this->btnSaveToFile->Margin = System::Windows::Forms::Padding(2);
			this->btnSaveToFile->Name = L"btnSaveToFile";
			this->btnSaveToFile->Size = System::Drawing::Size(240, 46);
			this->btnSaveToFile->TabIndex = 15;
			this->btnSaveToFile->Text = L"Зберегти в файл";
			this->btnSaveToFile->UseVisualStyleBackColor = true;
			this->btnSaveToFile->Click += gcnew System::EventHandler(this, &LibraryForm::btnSaveToFile_Click);
			// 
			// dgvRecords
			// 
			this->dgvRecords->AllowUserToAddRows = false;
			this->dgvRecords->AllowUserToDeleteRows = false;
			this->dgvRecords->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRecords->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvRecords->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRecords->Location = System::Drawing::Point(259, 42);
			this->dgvRecords->Margin = System::Windows::Forms::Padding(2);
			this->dgvRecords->Name = L"dgvRecords";
			this->dgvRecords->ReadOnly = true;
			this->dgvRecords->RowHeadersVisible = false;
			this->dgvRecords->RowHeadersWidth = 62;
			this->dgvRecords->RowTemplate->Height = 28;
			this->dgvRecords->Size = System::Drawing::Size(728, 331);
			this->dgvRecords->TabIndex = 16;
			// 
			// btnLoadFromFile
			// 
			this->btnLoadFromFile->Location = System::Drawing::Point(503, 377);
			this->btnLoadFromFile->Margin = System::Windows::Forms::Padding(2);
			this->btnLoadFromFile->Name = L"btnLoadFromFile";
			this->btnLoadFromFile->Size = System::Drawing::Size(240, 46);
			this->btnLoadFromFile->TabIndex = 17;
			this->btnLoadFromFile->Text = L"Завантажити з файлу";
			this->btnLoadFromFile->UseVisualStyleBackColor = true;
			this->btnLoadFromFile->Click += gcnew System::EventHandler(this, &LibraryForm::btnLoadFromFile_Click);
			// 
			// tabPageStatistics
			// 
			this->tabPageStatistics->BackColor = System::Drawing::SystemColors::Control;
			this->tabPageStatistics->Controls->Add(this->lblStatistics);
			this->tabPageStatistics->Controls->Add(this->lstStatistics);
			this->tabPageStatistics->Controls->Add(this->btnCalculateStatistics);
			this->tabPageStatistics->Location = System::Drawing::Point(4, 22);
			this->tabPageStatistics->Margin = System::Windows::Forms::Padding(2);
			this->tabPageStatistics->Name = L"tabPageStatistics";
			this->tabPageStatistics->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tabPageStatistics->Size = System::Drawing::Size(996, 431);
			this->tabPageStatistics->TabIndex = 2;
			this->tabPageStatistics->Text = L"Статистика";
			// 
			// lblStatistics
			// 
			this->lblStatistics->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblStatistics->Location = System::Drawing::Point(2, 6);
			this->lblStatistics->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStatistics->Name = L"lblStatistics";
			this->lblStatistics->Size = System::Drawing::Size(985, 36);
			this->lblStatistics->TabIndex = 0;
			this->lblStatistics->Text = L"Статистика за типами видань:";
			this->lblStatistics->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lstStatistics
			// 
			this->lstStatistics->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lstStatistics->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstStatistics->FormattingEnabled = true;
			this->lstStatistics->ItemHeight = 16;
			this->lstStatistics->Location = System::Drawing::Point(7, 44);
			this->lstStatistics->Margin = System::Windows::Forms::Padding(2);
			this->lstStatistics->Name = L"lstStatistics";
			this->lstStatistics->Size = System::Drawing::Size(985, 322);
			this->lstStatistics->TabIndex = 1;
			// 
			// btnCalculateStatistics
			// 
			this->btnCalculateStatistics->Location = System::Drawing::Point(378, 368);
			this->btnCalculateStatistics->Margin = System::Windows::Forms::Padding(2);
			this->btnCalculateStatistics->Name = L"btnCalculateStatistics";
			this->btnCalculateStatistics->Size = System::Drawing::Size(245, 61);
			this->btnCalculateStatistics->TabIndex = 2;
			this->btnCalculateStatistics->Text = L"Обчислити статистику";
			this->btnCalculateStatistics->UseVisualStyleBackColor = true;
			this->btnCalculateStatistics->Click += gcnew System::EventHandler(this, &LibraryForm::btnCalculateStatistics_Click);
			// 
			// tabPageSearch
			// 
			this->tabPageSearch->BackColor = System::Drawing::SystemColors::Control;
			this->tabPageSearch->Controls->Add(this->tabSearchCriteria);
			this->tabPageSearch->Location = System::Drawing::Point(4, 22);
			this->tabPageSearch->Margin = System::Windows::Forms::Padding(2);
			this->tabPageSearch->Name = L"tabPageSearch";
			this->tabPageSearch->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tabPageSearch->Size = System::Drawing::Size(996, 431);
			this->tabPageSearch->TabIndex = 3;
			this->tabPageSearch->Text = L"Пошук";
			// 
			// tabSearchCriteria
			// 
			this->tabSearchCriteria->Controls->Add(this->tabPageByAuthor);
			this->tabSearchCriteria->Controls->Add(this->tabPageByTypeAndYear);
			this->tabSearchCriteria->Location = System::Drawing::Point(13, 13);
			this->tabSearchCriteria->Margin = System::Windows::Forms::Padding(2);
			this->tabSearchCriteria->Name = L"tabSearchCriteria";
			this->tabSearchCriteria->SelectedIndex = 0;
			this->tabSearchCriteria->Size = System::Drawing::Size(974, 410);
			this->tabSearchCriteria->TabIndex = 0;
			// 
			// tabPageByAuthor
			// 
			this->tabPageByAuthor->BackColor = System::Drawing::SystemColors::Control;
			this->tabPageByAuthor->Controls->Add(this->lblSearchAuthor);
			this->tabPageByAuthor->Controls->Add(this->txtSearchAuthor);
			this->tabPageByAuthor->Controls->Add(this->btnSearchByAuthor);
			this->tabPageByAuthor->Controls->Add(this->dgvAuthorResults);
			this->tabPageByAuthor->Location = System::Drawing::Point(4, 22);
			this->tabPageByAuthor->Margin = System::Windows::Forms::Padding(2);
			this->tabPageByAuthor->Name = L"tabPageByAuthor";
			this->tabPageByAuthor->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tabPageByAuthor->Size = System::Drawing::Size(966, 384);
			this->tabPageByAuthor->TabIndex = 0;
			this->tabPageByAuthor->Text = L"Пошук за автором";
			// 
			// lblSearchAuthor
			// 
			this->lblSearchAuthor->AutoSize = true;
			this->lblSearchAuthor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSearchAuthor->Location = System::Drawing::Point(9, 22);
			this->lblSearchAuthor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSearchAuthor->Name = L"lblSearchAuthor";
			this->lblSearchAuthor->Size = System::Drawing::Size(99, 20);
			this->lblSearchAuthor->TabIndex = 0;
			this->lblSearchAuthor->Text = L"Ім\'я автора:";
			// 
			// txtSearchAuthor
			// 
			this->txtSearchAuthor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtSearchAuthor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSearchAuthor->Location = System::Drawing::Point(112, 20);
			this->txtSearchAuthor->Margin = System::Windows::Forms::Padding(2);
			this->txtSearchAuthor->Name = L"txtSearchAuthor";
			this->txtSearchAuthor->Size = System::Drawing::Size(234, 26);
			this->txtSearchAuthor->TabIndex = 1;
			// 
			// btnSearchByAuthor
			// 
			this->btnSearchByAuthor->Location = System::Drawing::Point(788, 13);
			this->btnSearchByAuthor->Margin = System::Windows::Forms::Padding(2);
			this->btnSearchByAuthor->Name = L"btnSearchByAuthor";
			this->btnSearchByAuthor->Size = System::Drawing::Size(169, 34);
			this->btnSearchByAuthor->TabIndex = 2;
			this->btnSearchByAuthor->Text = L"Пошук";
			this->btnSearchByAuthor->UseVisualStyleBackColor = true;
			this->btnSearchByAuthor->Click += gcnew System::EventHandler(this, &LibraryForm::btnSearchByAuthor_Click);
			// 
			// dgvAuthorResults
			// 
			this->dgvAuthorResults->AllowUserToAddRows = false;
			this->dgvAuthorResults->AllowUserToDeleteRows = false;
			this->dgvAuthorResults->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvAuthorResults->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvAuthorResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAuthorResults->Location = System::Drawing::Point(13, 52);
			this->dgvAuthorResults->Margin = System::Windows::Forms::Padding(2);
			this->dgvAuthorResults->Name = L"dgvAuthorResults";
			this->dgvAuthorResults->ReadOnly = true;
			this->dgvAuthorResults->RowHeadersVisible = false;
			this->dgvAuthorResults->RowHeadersWidth = 62;
			this->dgvAuthorResults->RowTemplate->Height = 28;
			this->dgvAuthorResults->Size = System::Drawing::Size(944, 324);
			this->dgvAuthorResults->TabIndex = 3;
			// 
			// tabPageByTypeAndYear
			// 
			this->tabPageByTypeAndYear->BackColor = System::Drawing::SystemColors::Control;
			this->tabPageByTypeAndYear->Controls->Add(this->lblSearchType);
			this->tabPageByTypeAndYear->Controls->Add(this->cmbSearchType);
			this->tabPageByTypeAndYear->Controls->Add(this->lblSearchYear);
			this->tabPageByTypeAndYear->Controls->Add(this->numSearchYear);
			this->tabPageByTypeAndYear->Controls->Add(this->btnSearchByTypeAndYear);
			this->tabPageByTypeAndYear->Controls->Add(this->dgvTypeYearResults);
			this->tabPageByTypeAndYear->Location = System::Drawing::Point(4, 22);
			this->tabPageByTypeAndYear->Margin = System::Windows::Forms::Padding(2);
			this->tabPageByTypeAndYear->Name = L"tabPageByTypeAndYear";
			this->tabPageByTypeAndYear->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tabPageByTypeAndYear->Size = System::Drawing::Size(966, 384);
			this->tabPageByTypeAndYear->TabIndex = 1;
			this->tabPageByTypeAndYear->Text = L"Пошук за типом і роком";
			// 
			// lblSearchType
			// 
			this->lblSearchType->AutoSize = true;
			this->lblSearchType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSearchType->Location = System::Drawing::Point(9, 19);
			this->lblSearchType->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSearchType->Name = L"lblSearchType";
			this->lblSearchType->Size = System::Drawing::Size(109, 20);
			this->lblSearchType->TabIndex = 0;
			this->lblSearchType->Text = L"Тип видання:";
			// 
			// cmbSearchType
			// 
			this->cmbSearchType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbSearchType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cmbSearchType->FormattingEnabled = true;
			this->cmbSearchType->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Стаття", L"Тези", L"Довідник", L"Книга",
					L"Навчальний посібник", L"Монографія", L"Інше"
			});
			this->cmbSearchType->Location = System::Drawing::Point(122, 16);
			this->cmbSearchType->Margin = System::Windows::Forms::Padding(2);
			this->cmbSearchType->Name = L"cmbSearchType";
			this->cmbSearchType->Size = System::Drawing::Size(135, 28);
			this->cmbSearchType->TabIndex = 1;
			// 
			// lblSearchYear
			// 
			this->lblSearchYear->AutoSize = true;
			this->lblSearchYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSearchYear->Location = System::Drawing::Point(261, 19);
			this->lblSearchYear->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSearchYear->Name = L"lblSearchYear";
			this->lblSearchYear->Size = System::Drawing::Size(156, 20);
			this->lblSearchYear->TabIndex = 2;
			this->lblSearchYear->Text = L"Рік видання (після):";
			// 
			// numSearchYear
			// 
			this->numSearchYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numSearchYear->Location = System::Drawing::Point(421, 16);
			this->numSearchYear->Margin = System::Windows::Forms::Padding(2);
			this->numSearchYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2025, 0, 0, 0 });
			this->numSearchYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->numSearchYear->Name = L"numSearchYear";
			this->numSearchYear->Size = System::Drawing::Size(80, 26);
			this->numSearchYear->TabIndex = 3;
			this->numSearchYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2010, 0, 0, 0 });
			// 
			// btnSearchByTypeAndYear
			// 
			this->btnSearchByTypeAndYear->Location = System::Drawing::Point(788, 13);
			this->btnSearchByTypeAndYear->Margin = System::Windows::Forms::Padding(2);
			this->btnSearchByTypeAndYear->Name = L"btnSearchByTypeAndYear";
			this->btnSearchByTypeAndYear->Size = System::Drawing::Size(169, 34);
			this->btnSearchByTypeAndYear->TabIndex = 4;
			this->btnSearchByTypeAndYear->Text = L"Пошук";
			this->btnSearchByTypeAndYear->UseVisualStyleBackColor = true;
			this->btnSearchByTypeAndYear->Click += gcnew System::EventHandler(this, &LibraryForm::btnSearchByTypeAndYear_Click);
			// 
			// dgvTypeYearResults
			// 
			this->dgvTypeYearResults->AllowUserToAddRows = false;
			this->dgvTypeYearResults->AllowUserToDeleteRows = false;
			this->dgvTypeYearResults->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTypeYearResults->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvTypeYearResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTypeYearResults->Location = System::Drawing::Point(13, 52);
			this->dgvTypeYearResults->Margin = System::Windows::Forms::Padding(2);
			this->dgvTypeYearResults->Name = L"dgvTypeYearResults";
			this->dgvTypeYearResults->ReadOnly = true;
			this->dgvTypeYearResults->RowHeadersVisible = false;
			this->dgvTypeYearResults->RowHeadersWidth = 62;
			this->dgvTypeYearResults->RowTemplate->Height = 28;
			this->dgvTypeYearResults->Size = System::Drawing::Size(944, 324);
			this->dgvTypeYearResults->TabIndex = 5;
			// 
			// LibraryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1018, 469);
			this->Controls->Add(this->tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"LibraryForm";
			this->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Електронна бібліотека кафедри";
			this->tabControl->ResumeLayout(false);
			this->tabPageAddRecord->ResumeLayout(false);
			this->tabPageAddRecord->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPages))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecords))->EndInit();
			this->tabPageStatistics->ResumeLayout(false);
			this->tabPageSearch->ResumeLayout(false);
			this->tabSearchCriteria->ResumeLayout(false);
			this->tabPageByAuthor->ResumeLayout(false);
			this->tabPageByAuthor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAuthorResults))->EndInit();
			this->tabPageByTypeAndYear->ResumeLayout(false);
			this->tabPageByTypeAndYear->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSearchYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTypeYearResults))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		// Методи для обробки подій
		System::Void btnAddRecord_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSaveToFile_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnLoadFromFile_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCalculateStatistics_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSearchByAuthor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSearchByTypeAndYear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};

	// Функція для очищення полів форми
	void ClearForm(Library::LibraryForm^ form) {
		form->txtTitle->Clear();
		form->txtAuthor->Clear();
		form->cmbType->SelectedIndex = 0;
		form->txtDescription->Clear();
		form->numPages->Value = 1;
		form->numYear->Value = 2024;
		form->txtPublisher->Clear();
	}

	// Функція для поновлення даних таблиці
	void UpdateDataGridView(DataGridView^ dgv) {
		dgv->Rows->Clear();
		dgv->Columns->Clear();

		// Додавання стовпців
		dgv->Columns->Add("title", "Назва");
		dgv->Columns->Add("author", "Автор");
		dgv->Columns->Add("type", "Тип");
		dgv->Columns->Add("description", "Опис");
		dgv->Columns->Add("pages", "Сторінок");
		dgv->Columns->Add("year", "Рік");
		dgv->Columns->Add("publisher", "Видавництво");

		// Налаштування стовпців
		dgv->Columns["description"]->Width = 200;

		// Додавання рядків з даними
		for (size_t i = 0; i < publications.size(); i++) {
			const Publication& pub = publications[i];
			dgv->Rows->Add(
				toSystemString(pub.title),
				toSystemString(pub.author),
				toSystemString(pub.type),
				toSystemString(pub.description),
				pub.pages,
				pub.year,
				toSystemString(pub.publisher)
			);
		}
	}

	// Обробник події натискання кнопки "Додати запис"
	System::Void LibraryForm::btnAddRecord_Click(System::Object^ sender, System::EventArgs^ e) {
		// Перевірка валідності введених даних
		if (txtTitle->Text->Trim() == "" || txtAuthor->Text->Trim() == "" || txtPublisher->Text->Trim() == "") {
			MessageBox::Show("Назва, автор та видавництво є обов'язковими полями!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Створення нового запису
		Publication pub;
		pub.title = toStdString(txtTitle->Text->Trim());
		pub.author = toStdString(txtAuthor->Text->Trim());
		pub.type = toStdString(cmbType->Text);
		pub.description = toStdString(txtDescription->Text->Trim());
		pub.pages = (int)numPages->Value;
		pub.year = (int)numYear->Value;
		pub.publisher = toStdString(txtPublisher->Text->Trim());

		// Додавання запису до вектора
		publications.push_back(pub);

		// Повідомлення про успішне додавання
		MessageBox::Show("Запис додано успішно!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Очищення полів форми
		ClearForm(this);

		// Поновлення таблиці з даними
		UpdateDataGridView(dgvRecords);
	}

	// Обробник події натискання кнопки "Зберегти в файл"
	System::Void LibraryForm::btnSaveToFile_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Створення діалогу збереження файлу
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Текстові файли (*.txt)|*.txt|Всі файли (*.*)|*.*";
			saveFileDialog->Title = "Зберегти бібліотеку";
			saveFileDialog->DefaultExt = "txt";
			saveFileDialog->AddExtension = true;

			// Якщо користувач вибрав файл
			if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				String^ fileName = saveFileDialog->FileName;
				std::ofstream file(toStdString(fileName));

				if (file.is_open()) {
					// Запис кількості публікацій
					file << publications.size() << endl;

					// Запис даних кожної публікації
					for (const auto& pub : publications) {
						file << pub.title << endl;
						file << pub.author << endl;
						file << pub.type << endl;
						file << pub.description << endl;
						file << pub.pages << endl;
						file << pub.year << endl;
						file << pub.publisher << endl;
					}

					file.close();
					MessageBox::Show("Дані успішно збережено у файл!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Помилка при відкритті файлу для запису!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при збереженні: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Обробник події натискання кнопки "Завантажити з файлу"
	System::Void LibraryForm::btnLoadFromFile_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Створення діалогу відкриття файлу
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Текстові файли (*.txt)|*.txt|Всі файли (*.*)|*.*";
			openFileDialog->Title = "Відкрити бібліотеку";

			// Якщо користувач вибрав файл
			if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				String^ fileName = openFileDialog->FileName;
				std::ifstream file(toStdString(fileName));

				if (file.is_open()) {
					// Очищення поточного вектора публікацій
					publications.clear();

					// Зчитування кількості публікацій
					int count;
					file >> count;
					file.ignore(); // Ігноруємо символ переходу на новий рядок

					// Зчитування даних кожної публікації
					for (int i = 0; i < count; i++) {
						Publication pub;

						// Зчитування даних з файлу
						getline(file, pub.title);
						getline(file, pub.author);
						getline(file, pub.type);
						getline(file, pub.description);
						file >> pub.pages;
						file.ignore();
						file >> pub.year;
						file.ignore();
						getline(file, pub.publisher);

						// Додавання публікації до вектора
						publications.push_back(pub);
					}

					file.close();

					// Поновлення таблиці з даними
					UpdateDataGridView(dgvRecords);

					MessageBox::Show("Дані успішно завантажено з файлу!", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Помилка при відкритті файлу для читання!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при завантаженні: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Обробник події натискання кнопки "Обчислити статистику"
	System::Void LibraryForm::btnCalculateStatistics_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Очищення списку статистики
			lstStatistics->Items->Clear();

			// Перевірка наявності даних
			if (publications.empty()) {
				lstStatistics->Items->Add("Немає даних для обчислення статистики.");
				return;
			}

			// Обчислення кількості видань кожного типу
			map<string, int> typeCount;
			for (const auto& pub : publications) {
				typeCount[pub.type]++;
			}

			// Додавання результатів до списку
			lstStatistics->Items->Add("Кількість видань за типами:");
			lstStatistics->Items->Add("----------------------------------");
			for (const auto& item : typeCount) {
				String^ type = toSystemString(item.first);
				String^ count = item.second.ToString();
				lstStatistics->Items->Add(String::Format("{0,-25} : {1,5}", type, count));
			}

			// Додавання загальної кількості видань
			lstStatistics->Items->Add("----------------------------------");
			lstStatistics->Items->Add(String::Format("Загальна кількість видань: {0}", publications.size()));
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при обчисленні статистики: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Обробник події натискання кнопки "Пошук за автором"
	System::Void LibraryForm::btnSearchByAuthor_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Очищення таблиці результатів
			dgvAuthorResults->Rows->Clear();
			dgvAuthorResults->Columns->Clear();

			// Додавання стовпців
			dgvAuthorResults->Columns->Add("title", "Назва");
			dgvAuthorResults->Columns->Add("type", "Тип");
			dgvAuthorResults->Columns->Add("year", "Рік");
			dgvAuthorResults->Columns->Add("pages", "Сторінок");
			dgvAuthorResults->Columns->Add("publisher", "Видавництво");

			// Отримання імені автора для пошуку
			String^ author = txtSearchAuthor->Text->Trim();

			// Перевірка валідності введених даних
			if (author == "") {
				MessageBox::Show("Введіть ім'я автора для пошуку!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Пошук видань за автором
			string searchAuthor = toStdString(author);
			bool found = false;

			for (const auto& pub : publications) {
				// Перевірка відповідності автора (ігноруючи регістр)
				string pubAuthor = pub.author;
				string searchAuthorLower = searchAuthor;

				// Перетворення до нижнього регістру для порівняння
				std::transform(pubAuthor.begin(), pubAuthor.end(), pubAuthor.begin(), ::tolower);
				std::transform(searchAuthorLower.begin(), searchAuthorLower.end(), searchAuthorLower.begin(), ::tolower);

				if (pubAuthor.find(searchAuthorLower) != string::npos) {
					dgvAuthorResults->Rows->Add(
						toSystemString(pub.title),
						toSystemString(pub.type),
						pub.year,
						pub.pages,
						toSystemString(pub.publisher)
					);
					found = true;
				}
			}

			// Повідомлення, якщо нічого не знайдено
			if (!found) {
				MessageBox::Show("Видань автора '" + author + "' не знайдено.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при пошуку: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Обробник події натискання кнопки "Пошук за типом і роком"
	System::Void LibraryForm::btnSearchByTypeAndYear_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Очищення таблиці результатів
			dgvTypeYearResults->Rows->Clear();
			dgvTypeYearResults->Columns->Clear();

			// Додавання стовпців
			dgvTypeYearResults->Columns->Add("title", "Назва");
			dgvTypeYearResults->Columns->Add("author", "Автор");
			dgvTypeYearResults->Columns->Add("year", "Рік");
			dgvTypeYearResults->Columns->Add("pages", "Сторінок");
			dgvTypeYearResults->Columns->Add("publisher", "Видавництво");

			// Отримання типу видання та року для пошуку
			String^ type = cmbSearchType->Text;
			int year = (int)numSearchYear->Value;

			// Пошук видань за типом і роком
			string searchType = toStdString(type);
			bool found = false;

			for (const auto& pub : publications) {
				// Перевірка відповідності типу та року
				if (pub.type == searchType && pub.year > year) {
					dgvTypeYearResults->Rows->Add(
						toSystemString(pub.title),
						toSystemString(pub.author),
						pub.year,
						pub.pages,
						toSystemString(pub.publisher)
					);
					found = true;
				}
			}

			// Повідомлення, якщо нічого не знайдено
			if (!found) {
				MessageBox::Show("Видань типу '" + type + "' після " + year.ToString() + " року не знайдено.", "Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при пошуку: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}