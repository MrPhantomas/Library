#pragma once
#include "Book.h"
#include "Clients.h"
#include "Suppliers.h"
#include "Orders.h"
#include "Favors.h"
namespace Biblio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace::System;
	using namespace::System::Windows::Forms;

	/// <summary>
	/// Сводка для Uchet_knig
	/// </summary>
	public ref class Uchet_knig : public System::Windows::Forms::Form
	{
	public:
		Uchet_knig(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Uchet_knig()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnGiveReturnBook;
	private: System::Windows::Forms::Button^ btnUpdateClient;
	private: System::Windows::Forms::Button^ btnUpdateSup;
	private: System::Windows::Forms::Button^ btnOrderMarkBook;
	private: System::Windows::Forms::Button^ btnUpdateBooks;
	private: System::Windows::Forms::Button^ btnClose;

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
			this->btnGiveReturnBook = (gcnew System::Windows::Forms::Button());
			this->btnUpdateClient = (gcnew System::Windows::Forms::Button());
			this->btnUpdateSup = (gcnew System::Windows::Forms::Button());
			this->btnOrderMarkBook = (gcnew System::Windows::Forms::Button());
			this->btnUpdateBooks = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnGiveReturnBook
			// 
			this->btnGiveReturnBook->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnGiveReturnBook->Location = System::Drawing::Point(12, 204);
			this->btnGiveReturnBook->Name = L"btnGiveReturnBook";
			this->btnGiveReturnBook->Size = System::Drawing::Size(323, 58);
			this->btnGiveReturnBook->TabIndex = 19;
			this->btnGiveReturnBook->Text = L"Выдать/Вернуть книгу";
			this->btnGiveReturnBook->UseVisualStyleBackColor = true;
			this->btnGiveReturnBook->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnGiveReturnBook_Click);
			// 
			// btnUpdateClient
			// 
			this->btnUpdateClient->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnUpdateClient->Location = System::Drawing::Point(12, 140);
			this->btnUpdateClient->Name = L"btnUpdateClient";
			this->btnUpdateClient->Size = System::Drawing::Size(323, 58);
			this->btnUpdateClient->TabIndex = 18;
			this->btnUpdateClient->Text = L"Добавить/Изменить данные о клиентах";
			this->btnUpdateClient->UseVisualStyleBackColor = true;
			this->btnUpdateClient->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnUpdateClient_Click);
			// 
			// btnUpdateSup
			// 
			this->btnUpdateSup->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnUpdateSup->Location = System::Drawing::Point(12, 76);
			this->btnUpdateSup->Name = L"btnUpdateSup";
			this->btnUpdateSup->Size = System::Drawing::Size(323, 58);
			this->btnUpdateSup->TabIndex = 17;
			this->btnUpdateSup->Text = L"Добавить/Изменить данные поставщика";
			this->btnUpdateSup->UseVisualStyleBackColor = true;
			this->btnUpdateSup->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnUpdateSup_Click);
			// 
			// btnOrderMarkBook
			// 
			this->btnOrderMarkBook->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnOrderMarkBook->Location = System::Drawing::Point(12, 268);
			this->btnOrderMarkBook->Name = L"btnOrderMarkBook";
			this->btnOrderMarkBook->Size = System::Drawing::Size(323, 58);
			this->btnOrderMarkBook->TabIndex = 15;
			this->btnOrderMarkBook->Text = L"Заказать книги/Отметить выполнение заказа";
			this->btnOrderMarkBook->UseVisualStyleBackColor = true;
			this->btnOrderMarkBook->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnOrderMarkBook_Click);
			// 
			// btnUpdateBooks
			// 
			this->btnUpdateBooks->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnUpdateBooks->Location = System::Drawing::Point(12, 12);
			this->btnUpdateBooks->Name = L"btnUpdateBooks";
			this->btnUpdateBooks->Size = System::Drawing::Size(323, 58);
			this->btnUpdateBooks->TabIndex = 13;
			this->btnUpdateBooks->Text = L"Добавить/Изменить данные книг";
			this->btnUpdateBooks->UseVisualStyleBackColor = true;
			this->btnUpdateBooks->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnUpdateBooks_Click);
			// 
			// btnClose
			// 
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnClose->Location = System::Drawing::Point(12, 332);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(323, 58);
			this->btnClose->TabIndex = 20;
			this->btnClose->Text = L"Выйти";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Uchet_knig::BtnClose_Click);
			// 
			// Uchet_knig
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(342, 397);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnGiveReturnBook);
			this->Controls->Add(this->btnUpdateClient);
			this->Controls->Add(this->btnUpdateSup);
			this->Controls->Add(this->btnOrderMarkBook);
			this->Controls->Add(this->btnUpdateBooks);
			this->Name = L"Uchet_knig";
			this->Text = L"Мини библиотека";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnUpdateBooks_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Book^ Obj = gcnew Book();
		Obj->Show();
	}

	private: System::Void BtnUpdateClient_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Clients^ Obj = gcnew Clients();
		Obj->Show();
	}
	private: System::Void BtnUpdateSup_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Suppliers^ Obj = gcnew Suppliers();
		Obj->Show();
	}
	private: System::Void BtnOrderMarkBook_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Orders^ Obj = gcnew Orders();
		Obj->Show();
	}

	private: System::Void BtnClose_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Application::Exit();
	}
	private: System::Void BtnGiveReturnBook_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Favors^ Obj = gcnew Favors();
		Obj->Show();
	}
};
}
