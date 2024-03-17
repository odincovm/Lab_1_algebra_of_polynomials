#include <stdio.h>
#include <LinearArrayTable.cpp>
#include <UserInterface.cpp>
#include <String>
using namespace std;

void main() {
	Userinteface Int;
	bool is_end = false;
	int user_ans;
	string tmp_name,tmp_polinom;
	//Выбор активной таблицы
	Int.chooseactiveTable();
	// Реализация меню
	while (is_end==false)
	{
		cout << "1 - Изменить активную таблицу\n";
		cout << "2 - Добавить полином в таблицы\n";
		cout << "3 - Удалить полином из таблиц\n";
		cout << "4 - Найти полином по имени\n";
		cout << "5 - Вывести все полиномы\n";
		cout << "6 - Вычислить полином в заданной точке\n";
		cout << "7 - Вычислить выражение из полиномов\n";
		cout << "8 - Выйти\n";
		cin >> user_ans;
		switch (user_ans)
		{
		case '1':
			Int.chooseactiveTable();
			break;
		case '2':
			cout << "Введите имя полинома\n";
			cin >> tmp_name;
			cout << "Введите полином\n";

		case '8':
			is_end = true;
			break;
		default:
			cout << "В меню нет такого номера\n";
			break;
		}
	}
	


}