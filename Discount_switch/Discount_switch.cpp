#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/* switch ��� ���� �������, ������� ����� ������������ � else ��� ��������. � ������ switch ������ �������� ������������, ����� ������ ��������� � ������ ������ ����-
   ��������. ��� ����������� ���������� ������ ����� ��������� ���� ������.

        ������ �������������� ��������������:
           0....1000    ->  0
        1000....2000    ->  1
        2000....3000    ->  2
        3000....4000    ->  3
        4000....5000    ->  4
        5000........    ->  default

����� �������� ��� ����� ����� ��������� �� 1000 � ����� ����� �����. ����� ����� ����� �����, ����������� ���������� ����� ������, � ������ �������� (int) ����� ����-
������ summa.

1-� �����������: ����� ������� ��������� ���������� key (���������� ����� � �����) � ��������� ���� ���� ����������: int key = summa / 1000
                                                                  (��� ��������� ���.����� � ��� ������ int, ������� ����� ����� ���������).

2-� �����������: switch � ����� ������� ��������� ����� ��������� �� ������ �������� ������-�� �������, �� � ��������� ����������. ������� ����� ��������� ����� �����-
����� ��� ������� ���� ������ char ���� ����� ����� (int, short, long, long long). */

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "-----------------------------------------------------------��������� ������� ������!-------------------------------------------------------------" << endl;
    float summa = 0.0F;
    cout << "������� ����� �������: "; cin >> summa;
    if (summa <= 0)
    {
        cout << "������������ �����!" << endl;
    }
    else
        switch ((int)summa / 1000)                                                                       // ��������� ���������� � ������� ����� �������� � ������ ����
        {
        case 2:
            cout << "���� ������ 10%, �� ������ 15% �� ������� "
                << 3000 - summa << " ���. � ������: " << summa * 0.9 << " ���." << endl;
            break;
        case 0:
            cout << "���� ������ 0%, �� ������ 5% �� ������� "
                << 1000 - summa << " ���. � ������: " << summa << " ���." << endl;
            break;
        case 3:
            cout << "���� ������ 15%, �� ������ 20% �� ������� "
                << 4000 - summa << " ���. � ������: " << summa * 0.85 << " ���." << endl;
            break;
        case 1:
            cout << "���� ������ 5%, �� ������ 10% �� ������� "
                << 2000 - summa << " ���. � ������: " << summa * 0.95 << " ���." << endl;
            break;
        case 4:
            cout << "���� ������ 20%, �� ������ 25% �� ������� "
                << 5000 - summa << " ���. � ������: " << summa * 0.8 << " ���." << endl;
            break;
        default:
            cout << "���� ������ 25%. ��� ������������ ������! � ������ "
                << summa * 0.75 << " ���." << endl;
            break;
        }
    system("pause");
}