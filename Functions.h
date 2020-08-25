#pragma once

#include <iostream>  // ��� ������ ����� � ������
#include <fstream>   // ��� ������ � �������
#include <string>    // ��� ������ � ��������
#include <Windows.h> // ��� ������ � ��������� �������
#include <conio.h>

using namespace std;

/*
	���������� �����
	���
	���,�����,���� ��������
	���.�����
	����� ��������
*/

struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

struct FIO  // ��������� ���
{
	string surname,
		name,
		patronymic;
};

struct Info // ��������� ���.������
{
	string	accountNumber,
		phonenumber,
		street;

	unsigned int home, flat;
};

struct Data
{
	FIO fio;
	Info info;
	Date date;
};

void DataEntry(Data* (&d), int& n);						// ���� ������ �������
void ReadingData(Data* (&d), int& n, string fileName);  // ������ ������ �� �����
void Print(Data* d, int n);								// ����� �����
void Print_month(Data* d, int n);                       // ������ �������� � ��������, ���������� � ��������� ������
void Print_phonenumber(Data* d, int n);                 // ������ �������� � ��������, ������� �������
void Print_operator(Data* d, int n);                    // ������ �������� � �������� � ����� �������� ���������� ���������
void DataChange(Data* (&d), int n);						// ��������� 
void DeleteData(Data* (&d), int& n);					// ��������
void Copy(Data* (&d_n), Data* (&d_o), int n);			// ����� ������
void Copy(Data& d_n, Data& d_o);						// ����� ����� ��������
void AddData(Data* (&d), int& n);						// ����������
void DataSorting(Data* d, int n);						// ����������
void SavingData(Data* d, int n, string fileName);		// ���������� 