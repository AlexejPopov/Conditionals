#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "--------------------------------------------------Программа определения способа передвижения!----------------------------------------------------" << endl;
	int Cash = 0, Bus = 25, Metro = 50, Taxi = 150, Car = 500;
	cout << "Введите сумму имеющихся денежных средств: ";
	cin >> Cash;

	if (Cash < 0)
	{
		cout << "Введена некорректная сумма!" << endl;
		system("pause");
		exit(1);
	}

	if (Cash < 25)
		cout << "Придется пойти пешком!" << endl;
	else
		cout << "Можем использовать транспорт: " << endl;

	if (Cash >= Bus)
		cout << "Можем поехать на автобусе!" << endl;

	if (Cash >= Metro)
		cout << "Можем поехать на метро!" << endl;

	if (Cash >= Taxi)
		cout << "Можем поехать на такси!" << endl;

	if (Cash >= Car)
		cout << "Можем поехать на машине! Не забудьте ключи и документы!" << endl;
	else
		cout << "Ключи от машины и документы не берем!" << endl;
}