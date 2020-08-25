#pragma once

#include <iostream>  // Для работы ввода и вывода
#include <fstream>   // Для работы с файлами
#include <string>    // Для работы с строками
#include <Windows.h> // Для работы с функциями системы
#include <conio.h>

using namespace std;

/*
	Порядковый номер
	фио
	год,месяц,день рождения
	дом.адрес
	номер телефона
*/

struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

struct FIO  // Структура ФИО
{
	string surname,
		name,
		patronymic;
};

struct Info // Структура доп.данных
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

void DataEntry(Data* (&d), int& n);						// Ввод данных вручную
void ReadingData(Data* (&d), int& n, string fileName);  // Чтение данных из файла
void Print(Data* d, int n);								// Вывод даных
void Print_month(Data* d, int n);                       // Выдача сведений о знакомых, родившихся в указанном месяце
void Print_phonenumber(Data* d, int n);                 // Выдача сведений о знакомых, имеющих телефон
void Print_operator(Data* d, int n);                    // Выдача сведений о знакомых с кодом телефона указанного оператора
void DataChange(Data* (&d), int n);						// Изменение 
void DeleteData(Data* (&d), int& n);					// Удаление
void Copy(Data* (&d_n), Data* (&d_o), int n);			// Копия данных
void Copy(Data& d_n, Data& d_o);						// Копия даных элемента
void AddData(Data* (&d), int& n);						// Добавление
void DataSorting(Data* d, int n);						// Сортировка
void SavingData(Data* d, int n, string fileName);		// Сохранение 