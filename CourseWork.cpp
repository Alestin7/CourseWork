#include "Functions.h"

int _stateMenu;

string spaceN = "\n\n\n\n\n\n\n\n\n";
string spaceT = "\t\t\t\t ";

void MENU()
{
	int pass;
	bool Pass = true;

	cout << spaceN;
	cout << spaceT << "Введите пароль:" << endl;
	cout << spaceT << "Пароль - ";
	cin >> pass;



	while (Pass == true)
	{
		if (pass == 1111)
		{
			bool passOk = true;
			Pass = false;
			system("cls");
			cout << spaceN;
			cout << spaceT << "Выберите Действие: " << endl;
			cout << spaceT << "(1) Ввод данных" << endl;
			cout << spaceT << "(2) Вывод данных" << endl;
			cout << spaceT << "(3) Вывод сведений о знакомых, родившихся в указанном месяце" << endl;
			cout << spaceT << "(4) Выдача сведений о знакомых, имеющих телефон" << endl;
			cout << spaceT << "(5) Выдача сведений о знакомых с кодом телефона указанного оператора" << endl;
			cout << spaceT << "(6) Изменение" << endl;
			cout << spaceT << "(7) Удаление" << endl;
			cout << spaceT << "(8) Добавление" << endl;
			cout << spaceT << "(9) Сортировка" << endl;
			cout << spaceT << "(10) Сохранение" << endl;
			cout << spaceT << "(0) Выход из программы" << endl;
			cout << spaceT << "Ваш выбор: ";
			cin >> _stateMenu;
		}
		else
		{
			system("cls");
			cout << spaceN;
			cout << spaceT << "Введен неправильный пароль. " << endl;
			cout << spaceT << "Пароль - ";
			cin >> pass;
		}
	}

}






void main()
{
	SetConsoleCP(1251);  // Рус для ввода
	SetConsoleOutputCP(1251); // рус для вывода

	MENU();


	int _actions;
	int amountOfData = 0;
	string fileName;


	Data* d = new Data[amountOfData]; // массив данных



	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");
			cout << spaceN;
			cout << spaceT << "Ввод вручную или из файла?: " << endl;
			cout << spaceT << "Ввод вручную - 1 " << endl;
			cout << spaceT << "Ввод из файла - 2 " << endl;
			cout << spaceT << "Ваш выбор: ";
			cin >> _actions;

			system("cls");




			if (_actions == 1)
			{
				DataEntry(d, amountOfData);
			}
			else if (_actions == 2)
			{
				cout << spaceN;
				cout << spaceT << "Введите название файла: ";
				cin >> fileName;

				ReadingData(d, amountOfData, fileName);
			}
			else
			{

				system("cls");
				cout << spaceN;
				cout << spaceT << "Не введен номер действия!" << endl;;

				cout << spaceT << "Ввод вручную или из файла?: " << endl;
				cout << spaceT << "Ввод вручную - 1 " << endl;
				cout << spaceT << "Ввод из файла - 2 " << endl;
				cin >> _actions;

				system("cls");

			}


			system("pause");
			system("cls");
			MENU();
			break;

			///////////////////////////////////////////////////

		case 2:
			system("cls");

			if (amountOfData != 0)
			{
				Print(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 3:
			system("cls");

			if (amountOfData != 0)
			{
				Print_month(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 4:
			system("cls");

			if (amountOfData != 0)
			{
				Print_phonenumber(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 5:
			system("cls");

			if (amountOfData != 0)
			{
				Print_operator(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 6:
			system("cls");

			if (amountOfData != 0)
			{
				DataChange(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 7:
			system("cls");

			if (amountOfData != 0)
			{
				DeleteData(d, amountOfData);
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 8:
			system("cls");

			if (amountOfData != 0)
			{
				AddData(d, amountOfData);
				amountOfData++;
			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 9:
			system("cls");

			if (amountOfData != 0)
			{
				DataSorting(d, amountOfData);

			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		case 10:
			system("cls");
			cout << spaceN;
			cout << spaceT << "Введите название файла: ";
			cin >> fileName;

			if (amountOfData != 0)
			{
				SavingData(d, amountOfData, fileName);

			}
			else
			{
				cout << spaceN;
				cout << spaceT << "Данные пусты!!!" << endl;
			}

			system("pause");
			system("cls");
			MENU();
			break;

			//////////////////////////////////////////////////

		default:
			cout << spaceN;
			cout << spaceT << "Не введен номер действия!!!" << endl;
			system("pause");
			system("cls");
			MENU();
			break;
		}

	}

}