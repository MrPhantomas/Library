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

	//������ ������ = > <
	array<String^>^ takeRec(int curId, String^ _operator);

	//������ ��������� ������
	array<String^>^ endRec();

	//���������� ������
	void insertRec(array<String^>^ data);

	//��������� ������
	void updateRec(array<String^>^ data);

	//�������� ������
	void deleteRec(int^ id);

	//������ ��� ���������� ����������
	ListBox::ObjectCollection^ FillCombobox();

	//������ ��������������� �������
	array<int^>^ massId();

	//�������� ������� ������ � ������� ����������
	bool existRec(int colNameid, int Id, String^ _operator);

private:
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStringBuilder;

	//���������� � ��
	void ConnectToDB();

};

