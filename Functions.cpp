#include "Functions.h"

/*
	Порядковый номер
	фио
	год,месяц,день рождения
	дом.адрес
	номер телефона
*/

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

string sN = "\n\n\n\n\n\n\n\n\n";
string sT = "\t\t\t\t ";

void DataEntry(Data* (&d), int& n)
{
	cout << sN;
	cout << sT << "Введите кол-во данных: ";
	cin >> n;

	// Выделяю память
	d = new Data[n];

	for (int i = 0; i < n; i++)
	{

		cout << sT << "Введите порядковый номер: ";
		cin >> d[i].info.accountNumber;

		////////////////////////////////////////////////////////////

		cout << sT << "Введите ФИО: " << endl;
		cout << sT << "Введите фамилию: ";
		cin >> d[i].fio.surname;

		cout << sT << "Введите имя: ";
		cin >> d[i].fio.name;

		cout << sT << "Введите отчество: ";
		cin >> d[i].fio.patronymic;

		///////////////////////////////////////////////////////////////////

		do
		{
			cout << sT << "Введите дату рождения: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].date.day >> d[i].date.month >> d[i].date.year;
		} while (!d[i].date.isCorrect());

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "Введите домашний адрес: " << endl;
		cout << sT << "Введите улицу: ";
		cin >> d[i].info.street;

		do
		{
			cin.clear();
			cout << sT << "Введите номер дома: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].info.home;
		} while (d[i].info.home < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << sT << "Введите номер квартиры: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].info.flat;
		} while (d[i].info.flat < 1 || cin.get() != '\n');

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "У знакомого есть номер телефона? \n" << endl << sT << "Если есть, введите (1), если нет, введите (0)." << endl;
	tryagain:
		cout << sT << "Ввод: ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << sT << "Введите номер телефона ";
			cin >> d[i].info.phonenumber;
		}
		else if (choice == 0)
		{
			d[i].info.phonenumber = "пусто";
			cout << sT << "Номер телефона: " << d[i].info.phonenumber << endl;
		}
		else
		{
			cout << sT << "Неправильный ввод." << endl;
			goto tryagain;
		}

		cout << "___________________________________________________________________________________________________________________________ \n" << endl;
	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);

	if (reading)
	{
		reading >> n;

		// Выделяю память
		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reading >> d[i].fio.surname;
			reading >> d[i].fio.name;
			reading >> d[i].fio.patronymic;

			reading >> d[i].date.day;
			reading >> d[i].date.month;
			reading >> d[i].date.year;

			reading >> d[i].info.accountNumber;
			reading >> d[i].info.phonenumber;

			reading >> d[i].info.street;
			reading >> d[i].info.home;
			reading >> d[i].info.flat;
		}

		cout << sT << "Данные считаны." << endl;
	}
	else
		cout << sT << "Ошибка открытия файла." << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << sN;
		cout << sT << "Знакомый #" << i + 1 << ": " << endl;

		cout << sT << "Порядковый номер: " << d[i].info.accountNumber << endl;
		cout << sT << "ФИО: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
		cout << sT << "Дата рождения: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
		cout << sT << "Домашний адрес: \n" << sT << "Улица: " << d[i].info.street << endl << sT << "Номер дома: " << d[i].info.home << endl << sT << "Номер квартиры: " << d[i].info.flat << endl;
		cout << sT << "Номер телефона: " << d[i].info.phonenumber << endl;


		cout << "___________________________________________________________________________________________________________________________ \n" << endl;

	}
}

void Print_month(Data* d, int n)
{
	cout << sT << "Введите номер месяца: ";
	int month;
	cin >> month;

	for (int i = 0; i < n; i++)
	{
		if (d[i].date.month == month)
		{
			cout << sN;
			cout << sT << "Знакомый #" << i + 1 << ": " << endl;

			cout << sT << "Порядковый номер: " << d[i].info.accountNumber << endl;
			cout << sT << "ФИО: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "Дата рождения: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "Домашний адрес: \n" << sT << "Улица: " << d[i].info.street << endl << sT << "Номер дома: " << d[i].info.home << endl << sT << "Номер квартиры: " << d[i].info.flat << endl;
			cout << sT << "Номер телефона: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void Print_phonenumber(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (d[i].info.phonenumber != "пусто")
		{
			cout << sN;
			cout << sT << "Знакомый #" << i + 1 << ": " << endl;

			cout << sT << "Порядковый номер: " << d[i].info.accountNumber << endl;
			cout << sT << "ФИО: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "Дата рождения: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "Домашний адрес: \n" << sT << "Улица: " << d[i].info.street << endl << sT << "Номер дома: " << d[i].info.home << endl << sT << "Номер квартиры: " << d[i].info.flat << endl;
			cout << sT << "Номер телефона: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void Print_operator(Data* d, int n)
{
	cout << sT << "Введите код оператора: ";
	string _operator;
	cin >> _operator;

	for (int i = 0; i < n; i++)
	{
		if (d[i].info.phonenumber[0] == _operator[0] && d[i].info.phonenumber[1] == _operator[1] && d[i].info.phonenumber[2] == _operator[2])
		{
			cout << sN;
			cout << sT << "Знакомый #" << i + 1 << ": " << endl;

			cout << sT << "Порядковый номер: " << d[i].info.accountNumber << endl;
			cout << sT << "ФИО: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "Дата рождения: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "Домашний адрес: \n" << sT << "Улица: " << d[i].info.street << endl << sT << "Номер дома: " << d[i].info.home << endl << sT << "Номер квартиры: " << d[i].info.flat << endl;
			cout << sT << "Номер телефона: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void DataChange(Data* (&d), int n)
{
	int _n;

	cout << sN;
	cout << sT << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");


	if (_n >= 0 && _n < n) // Проверка на правильность значения
	{

		cout << sT << "Введите порядковый номер: ";
		cin >> d[_n].info.accountNumber;

		////////////////////////////////////////////////////////////

		cout << sT << "Введите ФИО: " << endl;
		cout << sT << "Введите фамилию: ";
		cin >> d[_n].fio.surname;

		cout << sT << "Введите имя: ";
		cin >> d[_n].fio.name;

		cout << sT << "Введите отчество: ";
		cin >> d[_n].fio.patronymic;

		///////////////////////////////////////////////////////////////////

		do
		{
			cout << sT << "Введите дату рождения: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].date.day >> d[_n].date.month >> d[_n].date.year;
		} while (!d[_n].date.isCorrect());

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "Введите домашний адрес: " << endl;
		cout << sT << "Введите улицу: ";
		cin >> d[_n].info.street;

		do
		{
			cin.clear();
			cout << sT << "Введите номер дома: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].info.home;
		} while (d[_n].info.home < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << sT << "Введите номер квартиры: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].info.flat;
		} while (d[_n].info.flat < 1 || cin.get() != '\n');

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "У знакомого есть номер телефона? \n" << endl << sT << "Если есть, введите (1), если нет, введите (0)." << endl;
	_tryagain:
		cout << sT << "Ввод: ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << sT << "Введите номер телефона ";
			cin >> d[_n].info.phonenumber;
		}
		else if (choice == 0)
		{
			d[_n].info.phonenumber = "пусто";
			cout << sT << "Номер телефона: " << d[_n].info.phonenumber << endl;
		}
		else
		{
			cout << sT << "Неправильный ввод." << endl;
			goto _tryagain;
		}

		system("cls");

		cout << sT << "Данные изменены!" << endl;
	}
	else
		cout << sT << "Номер введен не верно!!!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << sN;
	cout << sT << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");


	if (_n >= 0 && _n < n) // проверка на правильность значения
	{
		Data* buf = new Data[n];  // Временный массив

		Copy(buf, d, n);

		// Выделение новой памяти
		--n;
		d = new Data[n];

		int q = 0;


		// Запоминание данных (кроме не нужного)
		for (int i = 0; i <= n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << sN << sT << "Данные удалены!" << endl;
	}
	else
		cout << sN << sT << "Номер введен не верно!!!" << endl;
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n.fio.surname = d_o.fio.surname;
	d_n.fio.name = d_o.fio.name;
	d_n.fio.patronymic = d_o.fio.patronymic;

	d_n.date.day = d_o.date.day;
	d_n.date.month = d_o.date.month;
	d_n.date.year = d_o.date.year;

	d_n.info.accountNumber = d_o.info.accountNumber;
	d_n.info.phonenumber = d_o.info.phonenumber;

	d_n.info.street = d_o.info.street;
	d_n.info.home = d_o.info.home;
	d_n.info.flat = d_o.info.flat;

}

void AddData(Data* (&d), int& n)
{
	// Временный массив
	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n); // сохраняем данные в временный массив

	// Выделение новой памяти
	n++;
	d = new Data[n];

	Copy(d, buf, --n); // Возвращение данных

	cout << sN;
	cout << sT << "Введите порядковый номер: ";
	cin >> d[n].info.accountNumber;

	////////////////////////////////////////////////////////////

	cout << sT << "Введите ФИО: " << endl;
	cout << sT << "Введите фамилию: ";
	cin >> d[n].fio.surname;

	cout << sT << "Введите имя: ";
	cin >> d[n].fio.name;

	cout << sT << "Введите отчество: ";
	cin >> d[n].fio.patronymic;

	///////////////////////////////////////////////////////////////////

	do
	{
		cout << sT << "Введите дату рождения: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].date.day >> d[n].date.month >> d[n].date.year;
	} while (!d[n].date.isCorrect());

	/////////////////////////////////////////////////////////////////////////////////////////////

	cout << sT << "Введите домашний адрес: " << endl;
	cout << sT << "Введите улицу: ";
	cin >> d[n].info.street;

	do
	{
		cin.clear();
		cout << sT << "Введите номер дома: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].info.home;
	} while (d[n].info.home < 1 || cin.get() != '\n');

	do
	{
		cin.clear();
		cout << sT << "Введите номер квартиры: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].info.flat;
	} while (d[n].info.flat < 1 || cin.get() != '\n');

	/////////////////////////////////////////////////////////////////////////////////////////////

	cout << sT << "У знакомого есть номер телефона? \n" << endl << sT << "Если есть, введите (1), если нет, введите (0)." << endl;
tryagain1:
	cout << sT << "Ввод: ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << sT << "Введите номер телефона ";
		cin >> d[n].info.phonenumber;
	}
	else if (choice == 0)
	{
		d[n].info.phonenumber = "пусто";
		cout << sT << "Номер телефона: " << d[n].info.phonenumber << endl;
	}
	else
	{
		cout << sT << "Неправильный ввод." << endl;
		goto tryagain1;
	}

	system("cls");

	cout << sN << sT << "Данные добавлены." << endl;

	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	// Временная переменная
	Data buf;

	// сортировка методом пузырька
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// условие сортировки
			if (d[i].fio.surname > d[j].fio.surname)
			{
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	cout << sN;
	cout << sT << "Данные отсортированны." << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	ofstream record(fileName, ios::out);  // поток для записи

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].fio.surname << endl;
			record << d[i].fio.name << endl;
			record << d[i].fio.patronymic << endl;

			record << d[i].date.day << endl;
			record << d[i].date.month << endl;
			record << d[i].date.year << endl;

			record << d[i].info.accountNumber << endl;
			record << d[i].info.phonenumber << endl;

			record << d[i].info.street << endl;
			record << d[i].info.home << endl;

			if (i < n - 1)
				record << d[i].info.flat << endl;
			else
				record << d[i].info.flat;

		}
	}
	else
		cout << sT << "Ошибка открытия файла." << endl;

	record.close();
}
