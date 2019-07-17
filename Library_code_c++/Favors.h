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
	/// Сводка для Favors
	/// </summary>
	public ref class Favors : public System::Windows::Forms::Form
	{
	public:
		Favors(void)
		{
			InitializeComponent();
			BD^ obj = gcnew BD("Books");
			BD^ obj_2 = gcnew BD("Client");
			array<String^>^ data = obj->takeRec(0, ">");
			array<String^>^ data_2 = obj_2->takeRec(0, ">");

			if (data_2 != nullptr && data != nullptr)
			{
				curId = 0;
				obj = gcnew BD("Favors");
				data = obj->takeRec(0, ">");
				if (data != nullptr) set_form(data);
				else clear_form();
			}
			else 
			{
				MessageBox::Show("Для начала создайте хотя бы одну запись книги и клиента!", "Ошибка", MessageBoxButtons::OK);
				this->Close();
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Favors()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cmbClient;
	protected:

	protected:
	private: System::Windows::Forms::ComboBox^ cmbBook;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RadioButton^ rdBtnLose;
	private: System::Windows::Forms::RadioButton^ rdBtnReturn;
	private: System::Windows::Forms::DateTimePicker^ dtReturn;
	private: System::Windows::Forms::DateTimePicker^ dtGive;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
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
			this->cmbClient = (gcnew System::Windows::Forms::ComboBox());
			this->cmbBook = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->rdBtnLose = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtnReturn = (gcnew System::Windows::Forms::RadioButton());
			this->dtReturn = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtGive = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnToEnd = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnToStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cmbClient
			// 
			this->cmbClient->FormattingEnabled = true;
			this->cmbClient->Location = System::Drawing::Point(114, 136);
			this->cmbClient->Name = L"cmbClient";
			this->cmbClient->Size = System::Drawing::Size(302, 21);
			this->cmbClient->TabIndex = 107;
			// 
			// cmbBook
			// 
			this->cmbBook->FormattingEnabled = true;
			this->cmbBook->Location = System::Drawing::Point(114, 106);
			this->cmbBook->Name = L"cmbBook";
			this->cmbBook->Size = System::Drawing::Size(302, 21);
			this->cmbBook->TabIndex = 106;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(4, 136);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(47, 13);
			this->label10->TabIndex = 105;
			this->label10->Text = L"Клиент*";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 106);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 13);
			this->label9->TabIndex = 104;
			this->label9->Text = L"Книга*";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 188);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(105, 13);
			this->label8->TabIndex = 103;
			this->label8->Text = L"Потеряли/Порвали";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(4, 164);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 13);
			this->label7->TabIndex = 102;
			this->label7->Text = L"Вернули";
			// 
			// rdBtnLose
			// 
			this->rdBtnLose->AutoSize = true;
			this->rdBtnLose->Location = System::Drawing::Point(115, 188);
			this->rdBtnLose->Name = L"rdBtnLose";
			this->rdBtnLose->Size = System::Drawing::Size(14, 13);
			this->rdBtnLose->TabIndex = 101;
			this->rdBtnLose->TabStop = true;
			this->rdBtnLose->UseVisualStyleBackColor = true;
			// 
			// rdBtnReturn
			// 
			this->rdBtnReturn->AutoSize = true;
			this->rdBtnReturn->Location = System::Drawing::Point(115, 164);
			this->rdBtnReturn->Name = L"rdBtnReturn";
			this->rdBtnReturn->Size = System::Drawing::Size(14, 13);
			this->rdBtnReturn->TabIndex = 100;
			this->rdBtnReturn->TabStop = true;
			this->rdBtnReturn->UseVisualStyleBackColor = true;
			// 
			// dtReturn
			// 
			this->dtReturn->Location = System::Drawing::Point(115, 80);
			this->dtReturn->Name = L"dtReturn";
			this->dtReturn->Size = System::Drawing::Size(301, 20);
			this->dtReturn->TabIndex = 99;
			this->dtReturn->ValueChanged += gcnew System::EventHandler(this, &Favors::DtReturn_ValueChanged);
			// 
			// dtGive
			// 
			this->dtGive->Location = System::Drawing::Point(115, 54);
			this->dtGive->Name = L"dtGive";
			this->dtGive->Size = System::Drawing::Size(301, 20);
			this->dtGive->TabIndex = 98;
			this->dtGive->ValueChanged += gcnew System::EventHandler(this, &Favors::DtGive_ValueChanged);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(377, 8);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 97;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Favors::BtnBack_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 80);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 13);
			this->label6->TabIndex = 96;
			this->label6->Text = L"Дата возвращения*";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(216, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 95;
			this->label4->Text = L"Заказы";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 94;
			this->label3->Text = L"Дата выдачи*";
			// 
			// btnToEnd
			// 
			this->btnToEnd->Location = System::Drawing::Point(408, 220);
			this->btnToEnd->Name = L"btnToEnd";
			this->btnToEnd->Size = System::Drawing::Size(44, 23);
			this->btnToEnd->TabIndex = 93;
			this->btnToEnd->Text = L">>";
			this->btnToEnd->UseVisualStyleBackColor = true;
			this->btnToEnd->Click += gcnew System::EventHandler(this, &Favors::BtnToEnd_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(358, 220);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(44, 23);
			this->btnNext->TabIndex = 92;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &Favors::BtnNext_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(196, 220);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 91;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Favors::BtnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(115, 220);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 90;
			this->btnUpdate->Text = L"Обновить";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Favors::BtnUpdate_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(277, 220);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 89;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Favors::BtnAdd_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(65, 220);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(44, 23);
			this->btnPrevious->TabIndex = 88;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &Favors::BtnPrevious_Click);
			// 
			// btnToStart
			// 
			this->btnToStart->Location = System::Drawing::Point(15, 220);
			this->btnToStart->Name = L"btnToStart";
			this->btnToStart->Size = System::Drawing::Size(44, 23);
			this->btnToStart->TabIndex = 87;
			this->btnToStart->Text = L"<<";
			this->btnToStart->UseVisualStyleBackColor = true;
			this->btnToStart->Click += gcnew System::EventHandler(this, &Favors::BtnToStart_Click);
			// 
			// Favors
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 257);
			this->Controls->Add(this->cmbClient);
			this->Controls->Add(this->cmbBook);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rdBtnLose);
			this->Controls->Add(this->rdBtnReturn);
			this->Controls->Add(this->dtReturn);
			this->Controls->Add(this->dtGive);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnToEnd);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnToStart);
			this->Name = L"Favors";
			this->Text = L"Favors";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Идентификатор текущей записи
	private: int curId;
	private: array<int^>^ arrIdBooks;
	private: array<int^>^ arrIdClients;

			 //Установка значений формы
	private: System::Void set_form(array<String^>^ data)
	{
		dtGive->MinDate = DateTime(1753, 1, 2, 0, 0, 0);
		dtGive->MaxDate = DateTime(9997, 12, 31, 0, 0, 0);
		dtReturn->MinDate = DateTime(1753, 1, 2, 0, 0, 0);
		dtReturn->MaxDate = DateTime(9997, 12, 31, 0, 0, 0);

		curId = Convert::ToInt32(data[0]);



		dtGive->Value = Convert::ToDateTime(data[1]);
		dtReturn->Value = Convert::ToDateTime(data[2]);

		BD^ obj = gcnew BD("Client");
		arrIdClients = obj->massId();
		array<String^>^ data_client = obj->takeRec(Convert::ToInt32(data[3]), "=");
		String^ str = data_client[2]->Trim() + " " + data_client[1]->Trim() + " " + data_client[5]->Trim();
		cmbClient->DataSource = obj->FillCombobox();
		cmbClient->SelectedIndex = cmbClient->FindString(str);

		obj = gcnew BD("Books");
		arrIdBooks = obj->massId();
		array<String^>^ data_book = obj->takeRec(Convert::ToInt32(data[4]), "=");
		str = "Название - " + data_book[1]->Trim() + ", автор - " + data_book[2]->Trim();
		cmbBook->DataSource = obj->FillCombobox();
		cmbBook->SelectedIndex = cmbBook->FindString(str);

		rdBtnReturn->Checked = Convert::ToBoolean(data[5]);
		rdBtnLose->Checked = Convert::ToBoolean(data[6]);

		btnUpdate->Enabled = true;
		btnDelete->Enabled = true;
		btnAdd->Enabled = false;
		cmbBook->Enabled = false;
		cmbClient->Enabled = false;
		rdBtnReturn->Enabled = true;
		rdBtnLose->Enabled = true;

		if (Convert::ToBoolean(data[6]) + Convert::ToBoolean(data[5])) btnUpdate->Enabled = false;
	}

			 //Очистка значений формы
	private: System::Void clear_form()
	{
		
		dtGive->MinDate = (DateTime(DateTime::Now.Year - 5, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0));
		dtGive->MaxDate = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtReturn->MinDate = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtReturn->MaxDate = (DateTime(DateTime::Now.Year + 5, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0));

		curId = 0;

		dtGive->Value = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		dtReturn->Value = DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, 0, 0, 0);
		rdBtnReturn->Checked = false;
		rdBtnLose->Checked = false;

		BD^ obj = gcnew BD("Books");
		arrIdBooks = obj->massId();
		cmbBook->DataSource = obj->FillCombobox();
		cmbBook->SelectedIndex = 0;

		obj = gcnew BD("Client");
		arrIdClients = obj->massId();
		cmbClient->DataSource = obj->FillCombobox();
		cmbClient->SelectedIndex = 0;

		btnUpdate->Enabled = false;
		btnDelete->Enabled = false;
		btnAdd->Enabled = true;
		cmbBook->Enabled = true;
		cmbClient->Enabled = true;
		rdBtnReturn->Enabled = false;
		rdBtnLose->Enabled = false;
		
	}

			 //Переход к следующей записи
	private: System::Void BtnNext_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (curId)
		{
			BD^ obj = gcnew BD("Favors");
			array<String^>^ data;
			data = obj->takeRec(curId, ">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

			 //Переход к предыдущей записи
	private: System::Void BtnPrevious_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		BD^ obj = gcnew BD("Favors");
		array<String^>^ data;
		if (curId) data = obj->takeRec(curId, "<");
		else data = obj->endRec();
		if (data != nullptr) set_form(data);
	}

			 //Переход к последней записи
	private: System::Void BtnToEnd_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		BD^ obj = gcnew BD("Favors");
		array<String^>^ data;
		data = obj->endRec();
		if (data != nullptr) set_form(data);
		else clear_form();
	}

			 //Переход к первой записи
	private: System::Void BtnToStart_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		BD^ obj = gcnew BD("Favors");
		array<String^>^ data;
		data = obj->takeRec(0, ">");
		if (data != nullptr) set_form(data);
		else clear_form();
	}

			 //Добавление записи в бд
	private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (!curId)
		{
			if (cmbBook->FindString(cmbBook->Text)>=0 && cmbClient->FindString(cmbClient->Text) >= 0)
			{
				BD^ obj = gcnew BD("Books");
				array<String^>^ data = obj->takeRec(Convert::ToInt32(Convert::ToString(arrIdBooks[cmbBook->SelectedIndex])), "=");
				if (Convert::ToInt32(data[3]))
				{
					data[3] = Convert::ToString(Convert::ToInt32(data[3]) - 1);
					obj->updateRec(data);

					obj = gcnew BD("Favors");
					data = gcnew array<String^>(obj->countColNames - 1);
					data[0] = Convert::ToString(dtGive->Value);
					data[1] = Convert::ToString(dtReturn->Value);
					data[2] = Convert::ToString(arrIdClients[cmbClient->SelectedIndex]);
					data[3] = Convert::ToString(arrIdBooks[cmbBook->SelectedIndex]);
					data[4] = Convert::ToString(rdBtnReturn->Checked + 0);
					data[5] = Convert::ToString(rdBtnLose->Checked + 0);
					obj->insertRec(data);

					clear_form();
				}
				else MessageBox::Show("Недостаточно книг", "Ошибка", MessageBoxButtons::OK);
			}
			else MessageBox::Show("Неверное значение в поле со списком! Можно использовать только существующие значения!", "Ошибка", MessageBoxButtons::OK);
		}
	}

			 //Обновление записи в бд
	private: System::Void BtnUpdate_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (curId)
		{
			if (cmbBook->FindString(cmbBook->Text) >= 0 && cmbClient->FindString(cmbClient->Text) >= 0)
			{
				BD^ obj = gcnew BD("Favors");
				array<String^>^ data = gcnew array<String^>(obj->countColNames);
				data[0] = Convert::ToString(curId);
				data[1] = Convert::ToString(dtGive->Value);
				data[2] = Convert::ToString(dtReturn->Value);
				data[3] = Convert::ToString(arrIdClients[cmbClient->SelectedIndex]);
				data[4] = Convert::ToString(arrIdBooks[cmbBook->SelectedIndex]);
				data[5] = Convert::ToString(rdBtnReturn->Checked + 0);
				data[6] = Convert::ToString(rdBtnLose->Checked + 0);
				obj->updateRec(data);

				if (Convert::ToInt32(data[4]))
				{
					obj = gcnew BD("Books");
					data = obj->takeRec(Convert::ToInt32(Convert::ToString(arrIdBooks[cmbBook->SelectedIndex])), "=");
					data[3] = Convert::ToString(Convert::ToInt32(data[3]) + 1);
					obj->updateRec(data);
				}
			}
			else MessageBox::Show("Неверное значение в поле со списком! Можно использовать только существующие значения!", "Ошибка", MessageBoxButtons::OK);
		}
	}

			 //Удаление записи из бд
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (curId)
		{
			BD^ obj = gcnew BD("Favors");
			obj->deleteRec(curId);
			array<String^>^ data;
			data = obj->takeRec(curId, ">");
			if (data != nullptr) set_form(data);
			else clear_form();
		}
	}

			 //Возвращение в управляющее меню
	private: System::Void BtnBack_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}

	private: System::Void DtGive_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (curId)
		{
			dtGive->MaxDate = dtReturn->Value;
			dtReturn->MinDate = dtGive->Value;
		}
	}

	private: System::Void DtReturn_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (curId)
		{
			dtGive->MaxDate = dtReturn->Value;
			dtReturn->MinDate = dtGive->Value;
		}
	}
};
}
