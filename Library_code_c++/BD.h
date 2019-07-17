#pragma once
#include <vector>
#include <string>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class BD
{
public:
	array<String^>^ colNames;
	int countColNames;
	String^ tableName;

	BD(String^ tblName);

	//Данные записи = > <
	array<String^>^ takeRec(int curId, String^ _operator);

	//Данные последней записи
	array<String^>^ endRec();

	//Добавление записи
	void insertRec(array<String^>^ data);

	//Изменение записи
	void updateRec(array<String^>^ data);

	//Удаление записи
	void deleteRec(int^ id);

	//Данные для заполнения комбобокса
	ListBox::ObjectCollection^ FillCombobox();

	//Данные идентификаторов таблицы
	array<int^>^ massId();

	//Проверка наличия записи с данными критериями
	bool existRec(int colNameid, int Id, String^ _operator);

private:
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStringBuilder;

	//Соединение с бд
	void ConnectToDB();

};

