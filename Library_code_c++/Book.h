#pragma once
#include "BD.h"
#include <string>
namespace Biblio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;

	/// <summary>
	/// Сводка для Book
	/// </summary>
	public ref class Book : public System::Windows::Forms::Form
	{
	public:
		Book(void)
		{
			InitializeComponent();

			curId = 0;

			BD^ obj = gcnew BD("Books");
			array<String^>^ data;
			data = obj->takeRec(0, ">");
			if (data != nullptr) set_form(data);
			else clear_form();

			txtName->MaxLength = 20;
			txtAuthor->MaxLength = 20;
			txtCount->MaxLength = 10;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Book()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnToStart;
	private: System::Windows::Forms::Button^ btnPrevious;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnToEnd;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::TextBox^ txtAuthor;
	private: System::Windows::Forms::TextBox^ txtCount;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnBack;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnToStart = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnToEnd = (gcnew System::Windows::Forms::Button());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtAuthor = (gcnew System::Windows::Forms::TextBox());
			this->txtCount = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnToStart
			// 
			this->btnToStart->Location = System::Drawing::Point(23, 154);
			this->btnToStart->Name = L"btnToStart";
			this->btnToStart->Size = System::Drawing::Size(44, 23);
			this->btnToStart->TabIndex = 0;
			this->btnToStart->Text = L"<<";
			this->btnToStart->UseVisualStyleBackColor = true;
			this->btnToStart->Click += gcnew System::EventHandler(this, &Book::BtnToStart_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(73, 154);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(44, 23);
			this->btnPrevious->TabIndex = 1;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &Book::BtnPrevious_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(285, 154);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Book::BtnAdd_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(123, 154);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Обновить";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Book::BtnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(204, 154);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Book::BtnDelete_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(366, 154);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(44, 23);
			this->btnNext->TabIndex = 5;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &Book::BtnNext_Click);
			// 
			// btnToEnd
			// 
			this->btnToEnd->Location = System::Drawing::Point(416, 154);
			this->btnToEnd->Name = L"btnToEnd";
			this->btnToEnd->Size = System::Drawing::Size(44, 23);
			this->btnToEnd->TabIndex = 6;
			this->btnToEnd->Text = L">>";
			this->btnToEnd->UseVisualStyleBackColor = true;
			this->btnToEnd->Click += gcnew System::EventHandler(this, &Book::BtnToEnd_Click);
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(111, 49);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(298, 20);
			this->txtName->TabIndex = 7;
			// 
			// txtAuthor
			// 
			this->txtAuthor->Location = System::Drawing::Point(111, 76);
			this->txtAuthor->Name = L"txtAuthor";
			this->txtAuthor->Size = System::Drawing::Size(298, 20);
			this->txtAuthor->TabIndex = 8;
			// 
			// txtCount
			// 
			this->txtCount->Location = System::Drawing::Point(111, 103);
			this->txtCount->Name = L"txtCount";
			this->txtCount->Size = System::Drawing::Size(298, 20);
			this->txtCount->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Название*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Автор*";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Количество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(224, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Книги";
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(392, 10);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 14;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Book::BtnBack_Click);
			// 
			// Book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(479, 192);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtCount);
			this->Controls->Add(this->txtAuthor);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->btnToEnd);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnToStart);
			this->Name = L"Book";
			this->Text = L"Book";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Идентификатор текущей записи
	private: int curId;

	//Установка значений формы
	private: System::Void set_form(array<String^>^ data)
		{
			curId = Convert::ToInt32(data[0]);
			txtName->Text = (data[1]->Trim());
			txtAuthor->Text = (data[2]->Trim());
			txtCount->Text = (data[3]->ToString());
			btnUpdate->Enabled = true;
			btnDelete->Enabled = true;
			btnAdd->Enabled = false;
		}

	//Очистка значений формы
	private: System::Void clear_form()
		{
			curId = 0;
			txtName->Clear();
			txtAuthor->Clear();
			txtCount->Clear();
			btnUpdate->Enabled = false;
			btnDelete->Enabled = false;
			btnAdd->Enabled = true;
		}
	
	//Переход к следующей записи
	private: System::Void BtnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj = gcnew BD("Books");
			array<String^>^ data;
			data = obj->takeRec(curId,">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

	//Переход к предыдущей записи
	private: System::Void BtnPrevious_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Books");
		array<String^>^ data;
 		if (curId) data = obj->takeRec(curId,"<");
		else data = obj->endRec();
		if (data != nullptr) set_form(data);
	}

	//Переход к последней записи
	private: System::Void BtnToEnd_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Books");
		array<String^>^ data;
		data = obj->endRec();
		if (data != nullptr) set_form(data);
		else clear_form();
	}

	//Переход к первой записи
	private: System::Void BtnToStart_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Books");
		array<String^>^ data;
		data = obj->takeRec(0, ">");
		if (data != nullptr) set_form(data);
		else clear_form();
	}

	//Добавление записи в бд
	private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtAuthor->Text->Trim() != "")
		{
			try {
				if (!curId)
				{
					if (txtCount->Text != "") int n = Convert::ToInt32(txtCount->Text);
					BD^ obj = gcnew BD("Books");
					array<String^>^ data = gcnew array<String^>(obj->countColNames - 1);
					data[0] = txtName->Text->Trim();
					data[1] = txtAuthor->Text->Trim();
					data[2] = Convert::ToString(abs(Convert::ToInt32(txtCount->Text->Trim())));
					obj->insertRec(data);
					clear_form();
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить число", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

	//Обновление записи в бд
	private: System::Void BtnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtAuthor->Text->Trim() != "")
		{
			try {
				if (curId)
				{
					if (txtCount->Text != "") int n = Convert::ToInt32(txtCount->Text);
					BD^ obj = gcnew BD("Books");
					array<String^>^ data = gcnew array<String^>(obj->countColNames);
					data[0] = Convert::ToString(curId);
					data[1] = txtName->Text->Trim();
					data[2] = txtAuthor->Text->Trim();
					data[3] = Convert::ToString(abs(Convert::ToInt32(txtCount->Text->Trim())));
					obj->updateRec(data);
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить число", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

	//Удаление записи из бд
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{	
			BD^ obj_favors = gcnew BD("Favors");
			BD^ obj_orders = gcnew BD("Orders");
			if (!obj_favors->existRec(4,curId,"=") && !obj_orders->existRec(8, curId, "="))
			{
				BD^ obj = gcnew BD("Books");
				obj->deleteRec(curId);
				array<String^>^ data;
				data = obj->takeRec(curId, ">");
				if (data != nullptr) set_form(data);
				else clear_form();
			}
			else MessageBox::Show("Удалите связанные записи в других таблицах", "Ошибка", MessageBoxButtons::OK);
		}
	}
			 
	//Возвращение в управляющее меню
	private: System::Void BtnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

};
}
