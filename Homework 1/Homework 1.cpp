#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int number;
	cout << "Введите № задания" << endl;
	cin >> number;
	cout << endl;
	if (number == 1) {
		cout << "Антон" << endl;
	}
	else if (number == 2) {
		float a, b;
		cout << "Введите первое число" << endl;
		cin >> a;
		cout << "Введите второе число" << endl;
		cin >> b;
		cout << endl;
		cout << "Сумма = " << a + b << endl;
		cout << "Разность = " << a - b << endl;
		cout << "Произведение = " << a * b << endl;
		if (b == 0) {
			cout << "Частное посчитать невозможно, т.к. b = 0" << endl;
		}
		else {
			cout << "Частное = " << a / b << endl;
		}
	}
	else if (number == 3) {
		float b, c;
		cout << "Введите число b" << endl;
		cin >> b;
		cout << "Введите число c" << endl;
		cin >> c;
		cout << endl;
		if (c == 0 and b == 0) {
			cout << "Бесконечное кол-во решений" << endl;
		}
		else if (b == 0 and c != 0) {
			cout << "Решений нет" << endl;
		}
		else {
			int sum;
			sum = -(c / b);
			cout << "Ответ: x = " << sum << endl;
		}
	}
	else if (number == 4) {
		float a, b, c;
		cout << "Введите число a" << endl;
		cin >> a;
		cout << "Введите число b" << endl;
		cin >> b;
		cout << "Введите число c" << endl;
		cin >> c;
		cout << endl;
		float D;
		D = ((b * b) - (4 * a * c));

		if (a == 0) {
			if (c == 0 and b == 0) {
				cout << "Бесконечное кол-во решений" << endl;
			}
			else if (b == 0 and c != 0) {
				cout << "Решений нет" << endl;
			}
			else {
				int sum;
				sum = -(c / b);
				cout << "Ответ: x = " << sum << endl;
			}
		}
		else if (D < 0) {
			cout << "Решений нет" << endl;
		}
		else if (D == 0) {
			int x;
			x = -b / (2 * a);
			cout << "Ответ: x = " << x << endl;
		}
		else if (D > 0) {
			float x1, x2, sqrt_d;
			sqrt_d = sqrt(D);
			x1 = (-b + sqrt_d) / (2 * a);
			x2 = (-b - sqrt_d) / (2 * a);
			cout << "Ответ:" << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else if (number == 5) {
		bool day, cur, lamp;
		cout << "На улице день?" << endl;
		cin >> day;
		cout << "Шторы раздвинуты?" << endl;
		cin >> cur;
		cout << "Лампа включена?" << endl;
		cin >> lamp;
		cout << endl;
		if (lamp or (day and cur)) {
			cout << "В комнате светло" << endl;
		}
		else {
			cout << "В комнате темно" << endl;
		}
	}
}