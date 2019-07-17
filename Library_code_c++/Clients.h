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

	/// <summary>
	/// Сводка для Clients
	/// </summary>
	public ref class Clients : public System::Windows::Forms::Form
	{
	public:
		Clients(void)
		{
			InitializeComponent();

			curId = 0;

			BD^ obj = gcnew BD("Client");
			array<String^>^ data;
			data = obj->takeRec(0, ">");
			if (data != nullptr) set_form(data);
			else clear_form();

			txtName->MaxLength = 20;
			txtSurname->MaxLength = 20;
			txtPatronimyc->MaxLength = 20;
			txtPassport->MaxLength = 10;
			txtNumber->MaxLength = 15;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Clients()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ btnToEnd;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnPrevious;
	private: System::Windows::Forms::Button^ btnToStart;
	private: System::Windows::Forms::TextBox^ txtSurname;
	private: System::Windows::Forms::TextBox^ txtPatronimyc;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtNumber;
	private: System::Windows::Forms::TextBox^ txtPassport;
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->btnToEnd = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnToStart = (gcnew System::Windows::Forms::Button());
			this->txtSurname = (gcnew System::Windows::Forms::TextBox());
			this->txtPatronimyc = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtNumber = (gcnew System::Windows::Forms::TextBox());
			this->txtPassport = (gcnew System::Windows::Forms::TextBox());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(220, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Клиенты";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Имя*";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(114, 54);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(298, 20);
			this->txtName->TabIndex = 21;
			// 
			// btnToEnd
			// 
			this->btnToEnd->Location = System::Drawing::Point(418, 196);
			this->btnToEnd->Name = L"btnToEnd";
			this->btnToEnd->Size = System::Drawing::Size(44, 23);
			this->btnToEnd->TabIndex = 20;
			this->btnToEnd->Text = L">>";
			this->btnToEnd->UseVisualStyleBackColor = true;
			this->btnToEnd->Click += gcnew System::EventHandler(this, &Clients::BtnToEnd_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(368, 196);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(44, 23);
			this->btnNext->TabIndex = 19;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &Clients::BtnNext_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(206, 196);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 18;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Clients::BtnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(125, 196);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 17;
			this->btnUpdate->Text = L"Обновить";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Clients::BtnUpdate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(287, 196);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 16;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Clients::BtnAdd_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(75, 196);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(44, 23);
			this->btnPrevious->TabIndex = 15;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &Clients::BtnPrevious_Click);
			// 
			// btnToStart
			// 
			this->btnToStart->Location = System::Drawing::Point(25, 196);
			this->btnToStart->Name = L"btnToStart";
			this->btnToStart->Size = System::Drawing::Size(44, 23);
			this->btnToStart->TabIndex = 14;
			this->btnToStart->Text = L"<<";
			this->btnToStart->UseVisualStyleBackColor = true;
			this->btnToStart->Click += gcnew System::EventHandler(this, &Clients::BtnToStart_Click);
			// 
			// txtSurname
			// 
			this->txtSurname->Location = System::Drawing::Point(114, 81);
			this->txtSurname->Name = L"txtSurname";
			this->txtSurname->Size = System::Drawing::Size(298, 20);
			this->txtSurname->TabIndex = 22;
			// 
			// txtPatronimyc
			// 
			this->txtPatronimyc->Location = System::Drawing::Point(114, 108);
			this->txtPatronimyc->Name = L"txtPatronimyc";
			this->txtPatronimyc->Size = System::Drawing::Size(298, 20);
			this->txtPatronimyc->TabIndex = 23;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Фамилия";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Отчество";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Телефон*";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 134);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 13);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Данные паспорта*";
			// 
			// txtNumber
			// 
			this->txtNumber->Location = System::Drawing::Point(114, 161);
			this->txtNumber->Name = L"txtNumber";
			this->txtNumber->Size = System::Drawing::Size(298, 20);
			this->txtNumber->TabIndex = 29;
			// 
			// txtPassport
			// 
			this->txtPassport->Location = System::Drawing::Point(114, 134);
			this->txtPassport->Name = L"txtPassport";
			this->txtPassport->Size = System::Drawing::Size(298, 20);
			this->txtPassport->TabIndex = 28;
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(391, 12);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 32;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Clients::BtnBack_Click);
			// 
			// Clients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 246);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtNumber);
			this->Controls->Add(this->txtPassport);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPatronimyc);
			this->Controls->Add(this->txtSurname);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->btnToEnd);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnToStart);
			this->Name = L"Clients";
			this->Text = L"Clients";
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
		txtSurname->Text = (data[2]->Trim());
		txtPatronimyc->Text = (data[3]->Trim());
		txtPassport->Text = (data[4]->Trim());
		txtNumber->Text = (data[5]->Trim());
		btnUpdate->Enabled = true;
		btnDelete->Enabled = true;
		btnAdd->Enabled = false;
	}

	//Очистка значений формы
	private: System::Void clear_form()
	{
		curId = 0;
		txtName->Clear();
		txtSurname->Clear();
		txtPatronimyc->Clear();
		txtPassport->Clear();
		txtNumber->Clear();
		btnUpdate->Enabled = false;
		btnDelete->Enabled = false;
		btnAdd->Enabled = true;
	}

	//Переход к следующей записи
	private: System::Void BtnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj = gcnew BD("Client");
			array<String^>^ data;
			data = obj->takeRec(curId,">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

	//Переход к предыдущей записи
	private: System::Void BtnPrevious_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Client");
		array<String^>^ data;
		if (curId) data = obj->takeRec(curId, "<");
		else data = obj->endRec();
		if (data != nullptr) set_form(data);
	}

	//Переход к последней записи
	private: System::Void BtnToEnd_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Client");
		array<String^>^ data;
		data = obj->endRec();
		if (data != nullptr) set_form(data);
		else clear_form();
	}

	//Переход к первой записи
	private: System::Void BtnToStart_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Client");
		array<String^>^ data;
		data = obj->takeRec(0, ">");
		if (data != nullptr) set_form(data);
		else clear_form();
	}

	//Добавление записи в бд
	private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtPassport->Text->Trim() != "" && txtNumber->Text->Trim() != "") 
		{
			try {
				if (!curId)
				{
					int n = Convert::ToInt32(txtPassport->Text);
					BD^ obj = gcnew BD("Client");
					array<String^>^ data = gcnew array<String^>(obj->countColNames - 1);
					data[0] = txtName->Text->Trim();
					data[1] = txtSurname->Text->Trim();
					data[2] = txtPatronimyc->Text->Trim();
					data[3] = txtPassport->Text->Trim();
					data[4] = txtNumber->Text->Trim();
					obj->insertRec(data);
					clear_form();
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить пасспортные данные", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

	//Обновление записи в бд
	private: System::Void BtnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtPassport->Text->Trim() != "" && txtNumber->Text->Trim() != "") 
		{
			try {
				if (curId)
				{
					int n = Convert::ToInt32(txtPassport->Text);
					BD^ obj = gcnew BD("Client");
					array<String^>^ data = gcnew array<String^>(obj->countColNames);
					data[0] = Convert::ToString(curId);
					data[1] = txtName->Text->Trim();
					data[2] = txtSurname->Text->Trim();
					data[3] = txtPatronimyc->Text->Trim();
					data[4] = txtPassport->Text->Trim();
					data[5] = txtNumber->Text->Trim();
					obj->updateRec(data);
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить пасспортные данные", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

	//Удаление записи из бд
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj_favors = gcnew BD("Favors");
			if (!obj_favors->existRec(3, curId, "="))
			{
				BD^ obj = gcnew BD("Client");
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
