#include "BD.h"
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

BD::BD(String^ tblName)
{
	array<String^>^ columnNames;
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM dbo." + tblName;
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();
		columnNames = gcnew array<String^>(reader->FieldCount);

		for (int i = 0; i < reader->FieldCount; i++)
		{
			columnNames[i] = reader->GetName(i);
		}
		colNames = columnNames;
		tableName = tblName;
		countColNames = reader->FieldCount;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Соединение с бд
void BD::ConnectToDB()
{
	//Data Source=DESKTOP-D2RRHOK\SQLEXPRESS_NUM_1;Initial Catalog=Biblioteka;Integrated Security=True
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "DESKTOP-D2RRHOK\\SQLEXPRESS_NUM_1";
	connStringBuilder->InitialCatalog = "Biblioteka";
	connStringBuilder->IntegratedSecurity = true;
	conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
}

//Данные записи = > <
array<String^>^ BD::takeRec(int curId, String^ _operator)
{
	array<String^>^ data;
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM dbo." + tableName + " WHERE " + colNames[0] + _operator + curId;
		if (_operator == "<") cmdText += " ORDER BY " + colNames[0] + " DESC";
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		if (reader->Read())
		{
			data = gcnew array<String^>(reader->FieldCount);
			for (int i = 0; i < reader->FieldCount; i++)
			{
				data[i] = Convert::ToString(reader[i]);
			}
		}
		return data;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}
 
//Данные последней записи
array<String^>^ BD::endRec()
{
	array<String^>^ data;
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM dbo." + tableName + " ORDER BY " + colNames[0] + " DESC";
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		if (reader->Read())
		{
			data = gcnew array<String^>(reader->FieldCount);
			for (int i = 0; i < reader->FieldCount; i++)
			{
				data[i] = Convert::ToString(reader[i]);
			}
		}
		return data;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Добавление записи
void BD::insertRec(array<String^>^ data)
{
	try {
		ConnectToDB();
		String ^param = "", ^value = "";
		for (int i = 1; i < countColNames; i++)
		{
			param += colNames[i];
			value += "'" + data[i-1] + "'";
			if (i < countColNames - 1) {
				param += ",";
				value += ",";
			}
		}
		String^ cmdText = "INSERT INTO dbo." + tableName + "(" + param + ") VALUES(" + value + ")";
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Изменение записи
void BD::updateRec(array<String^>^ data)
{
	try {
		ConnectToDB();
		String^ param_value = "";
		for (int i = 1; i < countColNames; i++)
		{
			param_value += colNames[i] + "=" + "'" + data[i] + "'";
			if (i < countColNames - 1) param_value += ",";
		}
		String^ cmdText = "UPDATE dbo." + tableName + "  SET " + param_value + " WHERE " + colNames[0] + "=" + data[0];
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Удаление записи
void BD::deleteRec(int^ id)
{
	try {
		ConnectToDB();
		String^ cmdText = "DELETE FROM dbo." + tableName + " WHERE " + colNames[0] + "=" + id;
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Данные для заполнения комбобокса
ListBox::ObjectCollection^ BD::FillCombobox()
{
	try {
		ConnectToDB();

		ListBox^ ListWithNames = gcnew ListBox();

		String^ cmdText = "SELECT * FROM dbo." + tableName;
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			if(tableName=="Suppliers") ListWithNames->Items->Add(String::Format("{0} {1} {2}", Convert::ToString(reader[2])->Trim(), Convert::ToString(reader[1])->Trim(), Convert::ToString(reader[4])->Trim()));
			else if(tableName == "Books") ListWithNames->Items->Add(String::Format("Название - {0}, автор - {1}", Convert::ToString(reader[1])->Trim(), Convert::ToString(reader[2])->Trim()));
			else if(tableName == "Client") ListWithNames->Items->Add(String::Format("{0} {1} {2}", Convert::ToString(reader[2])->Trim(), Convert::ToString(reader[1])->Trim(), Convert::ToString(reader[5])->Trim()));
		}

		return ListWithNames->Items;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Данные идентификаторов таблицы
array<int^>^ BD::massId()
{
	array<int^>^ data;
	try {
		ConnectToDB();
		int recCount;
		String^ cmdText = "SELECT " + colNames[0] + " FROM dbo." + tableName;
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader_count = cmd->ExecuteReader();
		for(recCount = 0; reader_count->Read(); recCount++);
		reader_count->Close();
		if (recCount) {
			SqlDataReader^ reader = cmd->ExecuteReader();
			data = gcnew array<int^>(recCount);
			for (int i = 0; reader->Read(); i++) data[i] = Convert::ToInt32(reader[0]);
		}
		return data;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}

//Проверка наличия записи с данными критериями
bool BD::existRec(int colNameid, int Id, String^ _operator)
{
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM dbo." + tableName + " WHERE " + colNames[colNameid] + _operator + Id;
		SqlCommand^ cmd = gcnew  SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		if (reader->Read()) return true;
		return false;
	}
	finally{
		if (conn != nullptr)
		{
			conn->Close();
		}
	}
}
