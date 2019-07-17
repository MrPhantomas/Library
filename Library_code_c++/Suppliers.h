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
	/// Сводка для Suppliers
	/// </summary>
	public ref class Suppliers : public System::Windows::Forms::Form
	{
	public:
		Suppliers(void)
		{
			InitializeComponent();
			
			curId = 0;

			BD^ obj = gcnew BD("Suppliers");
			array<String^>^ data;
			data = obj->takeRec(0, ">");
			if (data != nullptr) set_form(data);
			else clear_form();

			txtName->MaxLength = 20;
			txtSurname->MaxLength = 20;
			txtPatronimyc->MaxLength = 20;
			txtNumber->MaxLength = 15;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Suppliers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtNumber;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPatronimyc;
	private: System::Windows::Forms::TextBox^ txtSurname;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ btnToEnd;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnPrevious;
	private: System::Windows::Forms::Button^ btnToStart;

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
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtNumber = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPatronimyc = (gcnew System::Windows::Forms::TextBox());
			this->txtSurname = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->btnToEnd = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnToStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(389, 6);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 51;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Suppliers::BtnBack_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 50;
			this->label5->Text = L"Телефон*";
			// 
			// txtNumber
			// 
			this->txtNumber->Location = System::Drawing::Point(112, 128);
			this->txtNumber->Name = L"txtNumber";
			this->txtNumber->Size = System::Drawing::Size(298, 20);
			this->txtNumber->TabIndex = 48;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(218, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 46;
			this->label4->Text = L"Поставщик";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 45;
			this->label3->Text = L"Отчество";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Фамилия";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 43;
			this->label1->Text = L"Имя*";
			// 
			// txtPatronimyc
			// 
			this->txtPatronimyc->Location = System::Drawing::Point(112, 102);
			this->txtPatronimyc->Name = L"txtPatronimyc";
			this->txtPatronimyc->Size = System::Drawing::Size(298, 20);
			this->txtPatronimyc->TabIndex = 42;
			// 
			// txtSurname
			// 
			this->txtSurname->Location = System::Drawing::Point(112, 75);
			this->txtSurname->Name = L"txtSurname";
			this->txtSurname->Size = System::Drawing::Size(298, 20);
			this->txtSurname->TabIndex = 41;
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(112, 48);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(298, 20);
			this->txtName->TabIndex = 40;
			// 
			// btnToEnd
			// 
			this->btnToEnd->Location = System::Drawing::Point(416, 163);
			this->btnToEnd->Name = L"btnToEnd";
			this->btnToEnd->Size = System::Drawing::Size(44, 23);
			this->btnToEnd->TabIndex = 39;
			this->btnToEnd->Text = L">>";
			this->btnToEnd->UseVisualStyleBackColor = true;
			this->btnToEnd->Click += gcnew System::EventHandler(this, &Suppliers::BtnToEnd_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(366, 163);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(44, 23);
			this->btnNext->TabIndex = 38;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &Suppliers::BtnNext_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(204, 163);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 37;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Suppliers::BtnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(123, 163);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 36;
			this->btnUpdate->Text = L"Обновить";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Suppliers::BtnUpdate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(285, 163);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 35;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Suppliers::BtnAdd_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(73, 163);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(44, 23);
			this->btnPrevious->TabIndex = 34;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &Suppliers::BtnPrevious_Click);
			// 
			// btnToStart
			// 
			this->btnToStart->Location = System::Drawing::Point(23, 163);
			this->btnToStart->Name = L"btnToStart";
			this->btnToStart->Size = System::Drawing::Size(44, 23);
			this->btnToStart->TabIndex = 33;
			this->btnToStart->Text = L"<<";
			this->btnToStart->UseVisualStyleBackColor = true;
			this->btnToStart->Click += gcnew System::EventHandler(this, &Suppliers::BtnToStart_Click);
			// 
			// Suppliers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 196);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtNumber);
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
			this->Name = L"Suppliers";
			this->Text = L"Suppliers";
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
		txtNumber->Text = (data[4]->Trim());
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
		txtNumber->Clear();
		btnUpdate->Enabled = false;
		btnDelete->Enabled = false;
		btnAdd->Enabled = true;
	}

			 //Переход к следующей записи
	private: System::Void BtnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj = gcnew BD("Suppliers");
			array<String^>^ data;
			data = obj->takeRec(curId, ">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

			 //Переход к предыдущей записи
	private: System::Void BtnPrevious_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Suppliers");
		array<String^>^ data;
		if (curId) data = obj->takeRec(curId, "<");
		else data = obj->endRec();
		if (data != nullptr) set_form(data);
	}

			 //Переход к последней записи
	private: System::Void BtnToEnd_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Suppliers");
		array<String^>^ data;
		data = obj->endRec();
		if (data != nullptr) set_form(data);
		else clear_form();
	}

			 //Переход к первой записи
	private: System::Void BtnToStart_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Suppliers");
		array<String^>^ data;
		data = obj->takeRec(0, ">");
		if (data != nullptr) set_form(data);
		else clear_form();
	}

			 //Добавление записи в бд
	private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtNumber->Text->Trim() != "")
		{
			if (!curId)
			{
				BD^ obj = gcnew BD("Suppliers");
				array<String^>^ data = gcnew array<String^>(obj->countColNames - 1);
				data[0] = txtName->Text->Trim();
				data[1] = txtSurname->Text->Trim();
				data[2] = txtPatronimyc->Text->Trim();
				data[3] = txtNumber->Text->Trim();
				obj->insertRec(data);
				clear_form();
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

			 //Обновление записи в бд
	private: System::Void BtnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtName->Text->Trim() != "" && txtNumber->Text->Trim() != "")
		{
			if (curId)
			{

				BD^ obj = gcnew BD("Client");
				array<String^>^ data = gcnew array<String^>(obj->countColNames);
				data[0] = Convert::ToString(curId);
				data[1] = txtName->Text->Trim();
				data[2] = txtSurname->Text->Trim();
				data[3] = txtPatronimyc->Text->Trim();
				data[4] = txtNumber->Text->Trim();
				obj->updateRec(data);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK);
	}

			 //Удаление записи из бд
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj_orders = gcnew BD("Orders");
			if (!obj_orders->existRec(7, curId, "="))
			{
				BD^ obj = gcnew BD("Suppliers");
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
