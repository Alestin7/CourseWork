#include "Functions.h"

/*
	���������� �����
	���
	���,�����,���� ��������
	���.�����
	����� ��������
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
	cout << sT << "������� ���-�� ������: ";
	cin >> n;

	// ������� ������
	d = new Data[n];

	for (int i = 0; i < n; i++)
	{

		cout << sT << "������� ���������� �����: ";
		cin >> d[i].info.accountNumber;

		////////////////////////////////////////////////////////////

		cout << sT << "������� ���: " << endl;
		cout << sT << "������� �������: ";
		cin >> d[i].fio.surname;

		cout << sT << "������� ���: ";
		cin >> d[i].fio.name;

		cout << sT << "������� ��������: ";
		cin >> d[i].fio.patronymic;

		///////////////////////////////////////////////////////////////////

		do
		{
			cout << sT << "������� ���� ��������: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].date.day >> d[i].date.month >> d[i].date.year;
		} while (!d[i].date.isCorrect());

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "������� �������� �����: " << endl;
		cout << sT << "������� �����: ";
		cin >> d[i].info.street;

		do
		{
			cin.clear();
			cout << sT << "������� ����� ����: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].info.home;
		} while (d[i].info.home < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << sT << "������� ����� ��������: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[i].info.flat;
		} while (d[i].info.flat < 1 || cin.get() != '\n');

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "� ��������� ���� ����� ��������? \n" << endl << sT << "���� ����, ������� (1), ���� ���, ������� (0)." << endl;
	tryagain:
		cout << sT << "����: ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << sT << "������� ����� �������� ";
			cin >> d[i].info.phonenumber;
		}
		else if (choice == 0)
		{
			d[i].info.phonenumber = "�����";
			cout << sT << "����� ��������: " << d[i].info.phonenumber << endl;
		}
		else
		{
			cout << sT << "������������ ����." << endl;
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

		// ������� ������
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

		cout << sT << "������ �������." << endl;
	}
	else
		cout << sT << "������ �������� �����." << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << sN;
		cout << sT << "�������� #" << i + 1 << ": " << endl;

		cout << sT << "���������� �����: " << d[i].info.accountNumber << endl;
		cout << sT << "���: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
		cout << sT << "���� ��������: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
		cout << sT << "�������� �����: \n" << sT << "�����: " << d[i].info.street << endl << sT << "����� ����: " << d[i].info.home << endl << sT << "����� ��������: " << d[i].info.flat << endl;
		cout << sT << "����� ��������: " << d[i].info.phonenumber << endl;


		cout << "___________________________________________________________________________________________________________________________ \n" << endl;

	}
}

void Print_month(Data* d, int n)
{
	cout << sT << "������� ����� ������: ";
	int month;
	cin >> month;

	for (int i = 0; i < n; i++)
	{
		if (d[i].date.month == month)
		{
			cout << sN;
			cout << sT << "�������� #" << i + 1 << ": " << endl;

			cout << sT << "���������� �����: " << d[i].info.accountNumber << endl;
			cout << sT << "���: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "���� ��������: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "�������� �����: \n" << sT << "�����: " << d[i].info.street << endl << sT << "����� ����: " << d[i].info.home << endl << sT << "����� ��������: " << d[i].info.flat << endl;
			cout << sT << "����� ��������: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void Print_phonenumber(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (d[i].info.phonenumber != "�����")
		{
			cout << sN;
			cout << sT << "�������� #" << i + 1 << ": " << endl;

			cout << sT << "���������� �����: " << d[i].info.accountNumber << endl;
			cout << sT << "���: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "���� ��������: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "�������� �����: \n" << sT << "�����: " << d[i].info.street << endl << sT << "����� ����: " << d[i].info.home << endl << sT << "����� ��������: " << d[i].info.flat << endl;
			cout << sT << "����� ��������: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void Print_operator(Data* d, int n)
{
	cout << sT << "������� ��� ���������: ";
	string _operator;
	cin >> _operator;

	for (int i = 0; i < n; i++)
	{
		if (d[i].info.phonenumber[0] == _operator[0] && d[i].info.phonenumber[1] == _operator[1] && d[i].info.phonenumber[2] == _operator[2])
		{
			cout << sN;
			cout << sT << "�������� #" << i + 1 << ": " << endl;

			cout << sT << "���������� �����: " << d[i].info.accountNumber << endl;
			cout << sT << "���: " << d[i].fio.surname << " " << d[i].fio.name << " " << d[i].fio.patronymic << endl;
			cout << sT << "���� ��������: " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << sT << "�������� �����: \n" << sT << "�����: " << d[i].info.street << endl << sT << "����� ����: " << d[i].info.home << endl << sT << "����� ��������: " << d[i].info.flat << endl;
			cout << sT << "����� ��������: " << d[i].info.phonenumber << endl;


			cout << "___________________________________________________________________________________________________________________________ \n" << endl;
		}
	}
}

void DataChange(Data* (&d), int n)
{
	int _n;

	cout << sN;
	cout << sT << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");


	if (_n >= 0 && _n < n) // �������� �� ������������ ��������
	{

		cout << sT << "������� ���������� �����: ";
		cin >> d[_n].info.accountNumber;

		////////////////////////////////////////////////////////////

		cout << sT << "������� ���: " << endl;
		cout << sT << "������� �������: ";
		cin >> d[_n].fio.surname;

		cout << sT << "������� ���: ";
		cin >> d[_n].fio.name;

		cout << sT << "������� ��������: ";
		cin >> d[_n].fio.patronymic;

		///////////////////////////////////////////////////////////////////

		do
		{
			cout << sT << "������� ���� ��������: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].date.day >> d[_n].date.month >> d[_n].date.year;
		} while (!d[_n].date.isCorrect());

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "������� �������� �����: " << endl;
		cout << sT << "������� �����: ";
		cin >> d[_n].info.street;

		do
		{
			cin.clear();
			cout << sT << "������� ����� ����: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].info.home;
		} while (d[_n].info.home < 1 || cin.get() != '\n');

		do
		{
			cin.clear();
			cout << sT << "������� ����� ��������: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> d[_n].info.flat;
		} while (d[_n].info.flat < 1 || cin.get() != '\n');

		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << sT << "� ��������� ���� ����� ��������? \n" << endl << sT << "���� ����, ������� (1), ���� ���, ������� (0)." << endl;
	_tryagain:
		cout << sT << "����: ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << sT << "������� ����� �������� ";
			cin >> d[_n].info.phonenumber;
		}
		else if (choice == 0)
		{
			d[_n].info.phonenumber = "�����";
			cout << sT << "����� ��������: " << d[_n].info.phonenumber << endl;
		}
		else
		{
			cout << sT << "������������ ����." << endl;
			goto _tryagain;
		}

		system("cls");

		cout << sT << "������ ��������!" << endl;
	}
	else
		cout << sT << "����� ������ �� �����!!!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << sN;
	cout << sT << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");


	if (_n >= 0 && _n < n) // �������� �� ������������ ��������
	{
		Data* buf = new Data[n];  // ��������� ������

		Copy(buf, d, n);

		// ��������� ����� ������
		--n;
		d = new Data[n];

		int q = 0;


		// ����������� ������ (����� �� �������)
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

		cout << sN << sT << "������ �������!" << endl;
	}
	else
		cout << sN << sT << "����� ������ �� �����!!!" << endl;
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
	// ��������� ������
	Data* buf;
	buf = new Data[n];

	Copy(buf, d, n); // ��������� ������ � ��������� ������

	// ��������� ����� ������
	n++;
	d = new Data[n];

	Copy(d, buf, --n); // ����������� ������

	cout << sN;
	cout << sT << "������� ���������� �����: ";
	cin >> d[n].info.accountNumber;

	////////////////////////////////////////////////////////////

	cout << sT << "������� ���: " << endl;
	cout << sT << "������� �������: ";
	cin >> d[n].fio.surname;

	cout << sT << "������� ���: ";
	cin >> d[n].fio.name;

	cout << sT << "������� ��������: ";
	cin >> d[n].fio.patronymic;

	///////////////////////////////////////////////////////////////////

	do
	{
		cout << sT << "������� ���� ��������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].date.day >> d[n].date.month >> d[n].date.year;
	} while (!d[n].date.isCorrect());

	/////////////////////////////////////////////////////////////////////////////////////////////

	cout << sT << "������� �������� �����: " << endl;
	cout << sT << "������� �����: ";
	cin >> d[n].info.street;

	do
	{
		cin.clear();
		cout << sT << "������� ����� ����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].info.home;
	} while (d[n].info.home < 1 || cin.get() != '\n');

	do
	{
		cin.clear();
		cout << sT << "������� ����� ��������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> d[n].info.flat;
	} while (d[n].info.flat < 1 || cin.get() != '\n');

	/////////////////////////////////////////////////////////////////////////////////////////////

	cout << sT << "� ��������� ���� ����� ��������? \n" << endl << sT << "���� ����, ������� (1), ���� ���, ������� (0)." << endl;
tryagain1:
	cout << sT << "����: ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << sT << "������� ����� �������� ";
		cin >> d[n].info.phonenumber;
	}
	else if (choice == 0)
	{
		d[n].info.phonenumber = "�����";
		cout << sT << "����� ��������: " << d[n].info.phonenumber << endl;
	}
	else
	{
		cout << sT << "������������ ����." << endl;
		goto tryagain1;
	}

	system("cls");

	cout << sN << sT << "������ ���������." << endl;

	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	// ��������� ����������
	Data buf;

	// ���������� ������� ��������
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// ������� ����������
			if (d[i].fio.surname > d[j].fio.surname)
			{
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	cout << sN;
	cout << sT << "������ ��������������." << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	ofstream record(fileName, ios::out);  // ����� ��� ������

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
		cout << sT << "������ �������� �����." << endl;

	record.close();
}
