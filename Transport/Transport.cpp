#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "--------------------------------------------------��������� ����������� ������� ������������!----------------------------------------------------" << endl;
	int Cash = 0, Bus = 25, Metro = 50, Taxi = 150, Car = 500;
	cout << "������� ����� ��������� �������� �������: ";
	cin >> Cash;

	if (Cash < 0)
	{
		cout << "������� ������������ �����!" << endl;
		system("pause");
		exit(1);
	}

	if (Cash < 25)
		cout << "�������� ����� ������!" << endl;
	else
		cout << "����� ������������ ���������: " << endl;

	if (Cash >= Bus)
		cout << "����� ������� �� ��������!" << endl;

	if (Cash >= Metro)
		cout << "����� ������� �� �����!" << endl;

	if (Cash >= Taxi)
		cout << "����� ������� �� �����!" << endl;

	if (Cash >= Car)
		cout << "����� ������� �� ������! �� �������� ����� � ���������!" << endl;
	else
		cout << "����� �� ������ � ��������� �� �����!" << endl;
}