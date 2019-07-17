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
	/// Сводка для Orders
	/// </summary>
	public ref class Orders : public System::Windows::Forms::Form
	{
	public:
		Orders(void)
		{
			InitializeComponent();

			BD^ obj = gcnew BD("Books");
			BD^ obj_2 = gcnew BD("Suppliers");
			array<String^>^ data = obj->takeRec(0, ">");
			array<String^>^ data_2 = obj_2->takeRec(0, ">");

			if (data_2 != nullptr && data != nullptr)
			{
				curId = 0;
				obj = gcnew BD("Orders");
				data = obj->takeRec(0, ">");
				if (data != nullptr) set_form(data);
				else clear_form();
				txtCount->MaxLength = 10;
				txtCosts->MaxLength = 10;
			}
			else
			{
				MessageBox::Show("Для начала создайте хотя бы одну запись книги и поставщика!", "Ошибка", MessageBoxButtons::OK);
				this->Close();
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Orders()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnBack;

	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtCosts;

	private: System::Windows::Forms::TextBox^ txtCount;

	private: System::Windows::Forms::Button^ btnToEnd;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnPrevious;
	private: System::Windows::Forms::Button^ btnToStart;
	private: System::Windows::Forms::DateTimePicker^ dtOrder;
	private: System::Windows::Forms::DateTimePicker^ dtEnd;

	private: System::Windows::Forms::RadioButton^ rdBtnReady;
	private: System::Windows::Forms::RadioButton^ rdBtnCancel;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ cmbBook;
	private: System::Windows::Forms::ComboBox^ cmbSuppliers;



	protected:

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtCosts = (gcnew System::Windows::Forms::TextBox());
			this->txtCount = (gcnew System::Windows::Forms::TextBox());
			this->btnToEnd = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnToStart = (gcnew System::Windows::Forms::Button());
			this->dtOrder = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->rdBtnReady = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtnCancel = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->cmbBook = (gcnew System::Windows::Forms::ComboBox());
			this->cmbSuppliers = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(383, 9);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 51;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Orders::BtnBack_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 131);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 13);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Дата завершения*";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(212, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 46;
			this->label4->Text = L"Заказы";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 45;
			this->label3->Text = L"Дата заказа*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Стоимость*";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 43;
			this->label1->Text = L"Количество*";
			// 
			// txtCosts
			// 
			this->txtCosts->Location = System::Drawing::Point(106, 78);
			this->txtCosts->Name = L"txtCosts";
			this->txtCosts->Size = System::Drawing::Size(298, 20);
			this->txtCosts->TabIndex = 41;
			// 
			// txtCount
			// 
			this->txtCount->Location = System::Drawing::Point(106, 51);
			this->txtCount->Name = L"txtCount";
			this->txtCount->Size = System::Drawing::Size(298, 20);
			this->txtCount->TabIndex = 40;
			// 
			// btnToEnd
			// 
			this->btnToEnd->Location = System::Drawing::Point(405, 285);
			this->btnToEnd->Name = L"btnToEnd";
			this->btnToEnd->Size = System::Drawing::Size(44, 23);
			this->btnToEnd->TabIndex = 39;
			this->btnToEnd->Text = L">>";
			this->btnToEnd->UseVisualStyleBackColor = true;
			this->btnToEnd->Click += gcnew System::EventHandler(this, &Orders::BtnToEnd_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(355, 285);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(44, 23);
			this->btnNext->TabIndex = 38;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &Orders::BtnNext_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(193, 285);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 37;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Orders::BtnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(112, 285);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 36;
			this->btnUpdate->Text = L"Обновить";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Orders::BtnUpdate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(274, 285);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 35;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Orders::BtnAdd_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(62, 285);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(44, 23);
			this->btnPrevious->TabIndex = 34;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &Orders::BtnPrevious_Click);
			// 
			// btnToStart
			// 
			this->btnToStart->Location = System::Drawing::Point(12, 285);
			this->btnToStart->Name = L"btnToStart";
			this->btnToStart->Size = System::Drawing::Size(44, 23);
			this->btnToStart->TabIndex = 33;
			this->btnToStart->Text = L"<<";
			this->btnToStart->UseVisualStyleBackColor = true;
			this->btnToStart->Click += gcnew System::EventHandler(this, &Orders::BtnToStart_Click);
			// 
			// dtOrder
			// 
			this->dtOrder->Location = System::Drawing::Point(106, 105);
			this->dtOrder->Name = L"dtOrder";
			this->dtOrder->Size = System::Drawing::Size(298, 20);
			this->dtOrder->TabIndex = 52;
			this->dtOrder->ValueChanged += gcnew System::EventHandler(this, &Orders::DtOrder_ValueChanged);
			// 
			// dtEnd
			// 
			this->dtEnd->Location = System::Drawing::Point(106, 131);
			this->dtEnd->Name = L"dtEnd";
			this->dtEnd->Size = System::Drawing::Size(298, 20);
			this->dtEnd->TabIndex = 53;
			this->dtEnd->ValueChanged += gcnew System::EventHandler(this, &Orders::DtEnd_ValueChanged);
			// 
			// rdBtnReady
			// 
			this->rdBtnReady->AutoSize = true;
			this->rdBtnReady->Location = System::Drawing::Point(106, 223);
			this->rdBtnReady->Name = L"rdBtnReady";
			this->rdBtnReady->Size = System::Drawing::Size(14, 13);
			this->rdBtnReady->TabIndex = 54;
			this->rdBtnReady->TabStop = true;
			this->rdBtnReady->UseVisualStyleBackColor = true;
			// 
			// rdBtnCancel
			// 
			this->rdBtnCancel->AutoSize = true;
			this->rdBtnCancel->Location = System::Drawing::Point(106, 247);
			this->rdBtnCancel->Name = L"rdBtnCancel";
			this->rdBtnCancel->Size = System::Drawing::Size(14, 13);
			this->rdBtnCancel->TabIndex = 55;
			this->rdBtnCancel->TabStop = true;
			this->rdBtnCancel->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(4, 223);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 13);
			this->label7->TabIndex = 56;
			this->label7->Text = L"Готово";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 247);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 57;
			this->label8->Text = L"Отказано";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 165);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 13);
			this->label9->TabIndex = 58;
			this->label9->Text = L"Книга*";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(4, 190);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(69, 13);
			this->label10->TabIndex = 59;
			this->label10->Text = L"Поставщик*";
			// 
			// cmbBook
			// 
			this->cmbBook->FormattingEnabled = true;
			this->cmbBook->Location = System::Drawing::Point(106, 157);
			this->cmbBook->Name = L"cmbBook";
			this->cmbBook->Size = System::Drawing::Size(302, 21);
			this->cmbBook->TabIndex = 60;
			// 
			// cmbSuppliers
			// 
			this->cmbSuppliers->FormattingEnabled = true;
			this->cmbSuppliers->Location = System::Drawing::Point(106, 187);
			this->cmbSuppliers->Name = L"cmbSuppliers";
			this->cmbSuppliers->Size = System::Drawing::Size(302, 21);
			this->cmbSuppliers->TabIndex = 61;
			// 
			// Orders
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(462, 313);
			this->Controls->Add(this->cmbSuppliers);
			this->Controls->Add(this->cmbBook);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rdBtnCancel);
			this->Controls->Add(this->rdBtnReady);
			this->Controls->Add(this->dtEnd);
			this->Controls->Add(this->dtOrder);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtCosts);
			this->Controls->Add(this->txtCount);
			this->Controls->Add(this->btnToEnd);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnToStart);
			this->Name = L"Orders";
			this->Text = L"Orders";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Идентификатор текущей записи
	private: int curId;
	private: array<int^>^ arrIdBooks;
	private: array<int^>^ arrIdSupplers;

			 //Установка значений формы
	private: System::Void set_form(array<String^>^ data)
	{
		dtOrder->MinDate = DateTime(1753, 1, 2, 0, 0, 0);
		dtOrder->MaxDate = DateTime(9997, 12, 31, 0, 0, 0);
		dtEnd->MinDate = DateTime(1753, 1, 2, 0, 0, 0);
		dtEnd->MaxDate = DateTime(9997, 12, 31, 0, 0, 0);

		curId = Convert::ToInt32(data[0]);
		txtCount->Text = (data[1]->Trim());
		txtCosts->Text = (data[2]->Trim());
		dtOrder->Value = Convert::ToDateTime(data[3]);
		dtEnd->Value = Convert::ToDateTime(data[4]);
		rdBtnReady->Checked = Convert::ToBoolean(data[5]);
		rdBtnCancel->Checked = Convert::ToBoolean(data[6]);

		BD^ obj = gcnew BD("Books");
		arrIdBooks = obj->massId();
		array<String^>^ data_book = obj->takeRec(Convert::ToInt32(data[8]), "=");
		String^ str = "Название - " + data_book[1]->Trim() + ", автор - " + data_book[2]->Trim();
		cmbBook->DataSource = obj->FillCombobox();
		cmbBook->SelectedIndex = cmbBook->FindString(str);

		obj = gcnew BD("Suppliers");
		arrIdSupplers = obj->massId();
		array<String^>^ data_supplier = obj->takeRec(Convert::ToInt32(data[7]), "=");
		str = data_supplier[2]->Trim() + " " + data_supplier[1]->Trim() + " " + data_supplier[4]->Trim();
		cmbSuppliers->DataSource = obj->FillCombobox();
		cmbSuppliers->SelectedIndex = cmbSuppliers->FindString(str);

		btnUpdate->Enabled = true;
		btnDelete->Enabled = true;
		btnAdd->Enabled = false;
		rdBtnCancel->Enabled = true;
		rdBtnReady->Enabled = true;
		cmbBook->Enabled = false;
		cmbSuppliers->Enabled = false;
		if (Convert::ToBoolean(data[6]) + Convert::ToBoolean(data[5])) btnUpdate->Enabled = false;
	}

			 //Очистка значений формы
	private: System::Void clear_form()
	{
		dtOrder->MinDate = (DateTime(DateTime::Now.Year - 5, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0));
		dtOrder->MaxDate = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtEnd->MinDate = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtEnd->MaxDate = (DateTime(DateTime::Now.Year + 5, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0));

		curId = 0;

		txtCount->Clear();
		txtCosts->Clear();
		dtOrder->Value = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtEnd->Value = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		rdBtnReady->Checked = false;
		rdBtnCancel->Checked = false;

		BD^ obj = gcnew BD("Books");
		arrIdBooks = obj->massId();
		cmbBook->DataSource = obj->FillCombobox();
		cmbBook->SelectedIndex = 0;

		obj = gcnew BD("Suppliers");
		arrIdSupplers = obj->massId();
		cmbSuppliers->DataSource = obj->FillCombobox();
		cmbSuppliers->SelectedIndex = 0;

		btnUpdate->Enabled = false;
		btnDelete->Enabled = false;
		btnAdd->Enabled = true;
		rdBtnCancel->Enabled = false;
		rdBtnReady->Enabled = false;
		cmbBook->Enabled = true;
		cmbSuppliers->Enabled = true;

	}

			 //Переход к следующей записи
	private: System::Void BtnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj = gcnew BD("Orders");
			array<String^>^ data;
			data = obj->takeRec(curId, ">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

			 //Переход к предыдущей записи
	private: System::Void BtnPrevious_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Orders");
		array<String^>^ data;
		if (curId) data = obj->takeRec(curId, "<");
		else data = obj->endRec();
		if (data != nullptr) set_form(data); 
	}

			 //Переход к последней записи
	private: System::Void BtnToEnd_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Orders");
		array<String^>^ data;
		data = obj->endRec();
		if (data != nullptr) set_form(data);
		else clear_form(); 
	}

			 //Переход к первой записи
	private: System::Void BtnToStart_Click(System::Object^ sender, System::EventArgs^ e) {
		BD^ obj = gcnew BD("Orders");
		array<String^>^ data;
		data = obj->takeRec(0, ">");
		if (data != nullptr) set_form(data);
		else clear_form(); 
	}

			 //Добавление записи в бд
	private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtCount->Text->Trim() != "" && txtCosts->Text->Trim() != "")
		{
			try {
				if (!curId)
				{
					if (cmbBook->FindString(cmbBook->Text) >= 0 && cmbSuppliers->FindString(cmbSuppliers->Text) >= 0)
					{
						int is_number = Convert::ToInt32(txtCount->Text->Trim());
						is_number = Convert::ToInt32(txtCosts->Text->Trim());
						BD^ obj = gcnew BD("Orders");
						array<String^>^ data = gcnew array<String^>(obj->countColNames - 1);
						data[0] = Convert::ToString(abs(Convert::ToInt32(txtCount->Text->Trim())));
						data[1] = Convert::ToString(abs(Convert::ToInt32(txtCosts->Text->Trim())));
						data[2] = Convert::ToString(dtOrder->Value);
						data[3] = Convert::ToString(dtEnd->Value);
						data[4] = Convert::ToString(rdBtnReady->Checked + 0);
						data[5] = Convert::ToString(rdBtnCancel->Checked + 0);
						data[6] = Convert::ToString(arrIdSupplers[cmbSuppliers->SelectedIndex]);
						data[7] = Convert::ToString(arrIdBooks[cmbBook->SelectedIndex]);
						obj->insertRec(data);
						clear_form();
					}
					else MessageBox::Show("Неверное значение в поле со списком! Можно использовать только существующие значения!", "Ошибка", MessageBoxButtons::OK);
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить числа в числовых полях", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK); 
	} 

			 //Обновление записи в бд
	private: System::Void BtnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtCount->Text->Trim() != "" && txtCosts->Text->Trim() != "")
		{
			try {
				if (curId)
				{
					if (cmbBook->FindString(cmbBook->Text) >= 0 && cmbSuppliers->FindString(cmbSuppliers->Text) >= 0)
					{
						int is_number = Convert::ToInt32(txtCount->Text->Trim());
						is_number = Convert::ToInt32(txtCosts->Text->Trim());
						BD^ obj = gcnew BD("Orders");
						array<String^>^ data = gcnew array<String^>(obj->countColNames);
						data[0] = Convert::ToString(curId);
						data[1] = Convert::ToString(abs(Convert::ToInt32(txtCount->Text->Trim())));
						data[2] = Convert::ToString(abs(Convert::ToInt32(txtCosts->Text->Trim())));
						data[3] = Convert::ToString(dtOrder->Value);
						data[4] = Convert::ToString(dtEnd->Value);
						data[5] = Convert::ToString(rdBtnReady->Checked + 0);
						data[6] = Convert::ToString(rdBtnCancel->Checked + 0);
						data[7] = Convert::ToString(arrIdSupplers[cmbSuppliers->SelectedIndex]);
						data[8] = Convert::ToString(arrIdBooks[cmbBook->SelectedIndex]);
						obj->updateRec(data);

						if (Convert::ToInt32(data[5]))
						{
							obj = gcnew BD("Books");
							data = obj->takeRec(Convert::ToInt32(Convert::ToString(arrIdBooks[cmbBook->SelectedIndex])), "=");
							data[3] = Convert::ToString(Convert::ToInt32(data[3]) + Convert::ToInt32(txtCount->Text->Trim()));
							obj->updateRec(data);
						}
					}
					else MessageBox::Show("Неверное значение в поле со списком! Можно использовать только существующие значения!", "Ошибка", MessageBoxButtons::OK);
				}
			}
			catch (...) {
				MessageBox::Show("Не удалось получить числа в числовых полях", "Ошибка", MessageBoxButtons::OK);
			}
		}
		else MessageBox::Show("Заполните все необходимые поля", "Ошибка", MessageBoxButtons::OK); 
	}

			 //Удаление записи из бд
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			BD^ obj = gcnew BD("Orders");
			obj->deleteRec(curId);
			array<String^>^ data;
			data = obj->takeRec(curId, ">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

			 //Возвращение в управляющее меню
	private: System::Void BtnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void DtOrder_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			dtOrder->MaxDate = dtEnd->Value;
			dtEnd->MinDate = dtOrder->Value;
		}
	}
	private: System::Void DtEnd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (curId)
		{
			dtOrder->MaxDate = dtEnd->Value;
			dtEnd->MinDate = dtOrder->Value;
		}
	}

};
}
