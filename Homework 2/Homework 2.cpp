#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


float f(float x)
{
	return (x * x - 2 * x + 2) / (x - 1);
}


int main()
{
	setlocale(LC_ALL, "rus");
	int number;
	cout << "Введите № задания" << endl;
	cin >> number;
	cout << endl;
	if (number == 1) {
		double r, R, l, h;
		cout << "Введите значение r: ";
		cin >> r;
		cout << "Введите значение R: ";
		cin >> R;
		cout << "Введите значение l: ";
		cin >> l;
		cout << "Введите значение h: ";
		cin >> h;
		cout << endl;

		if ((r == 0 or R == 0 or h == 0) or (r > R)) {
			cout << "Такого конуса не может быть" << endl;
		}
		else if (r == R) {
			cout << "Это не усечённый конус" << endl;
		}
		else {
			double V, S;
			V = ((1.0 / 3.0) * M_PI * h * ((R * R) + (R * r) + (r * r)));
			S = M_PI * (R * R + (R + r) * l + (r * r));
			cout << "Ответ:" << endl << "Объём = " << V << endl << "Площадь поверхности = " << S << endl;
		}
	}
	else if (number == 2) {
		double x, a, w;
		cout << "Введите значение x: ";
		cin >> x;
		cout << "Введите значение a: ";
		cin >> a;
		cout << endl;
		if (abs(x) < 1) {
			if (x <= 0) {
				cout << "Функция не определена" << endl;
			}
			else {
				w = a * log(abs(x));
				cout << "W = " << w << endl;
			}
		}
		else {
			if (a < (x * x)) {
				cout << "Функция не определена" << endl;
			}
			else {
				w = sqrt(a - (x * x));
				cout << "W = " << w << endl;
			}

		}
	}
	else if (number == 3) {
		double x, y, b, z;
		cout << "Введите значение x: ";
		cin >> x;
		cout << "Введите значение y: ";
		cin >> y;
		cout << "Введите значение b: ";
		cin >> b;
		cout << endl;
		if ((b <= y) or (b < x) or ((b - y) < 0) or ((b - x) < 0)) {
			cout << "Функция не определена" << endl;
		}
		else {
			z = log(b - y) * sqrt(b - x);
			cout << "z = " << z << endl;
		}
	}
	else if (number == 4) {
		double N;
		cout << "Введите значение N: ";
		cin >> N;
		cout << endl;
		N = ceil(N);
		for (int i = N; i < N + 10; i++)
		{
			cout << i << endl;
		}
	}
	else if (number == 5) {
		for (double x = -4; x <= 4; x += 0.5) 
		{
			if (x != 1) {
				cout << "f(" << x << ") = " << f(x) << endl;
			}
			else {
				cout << "f(1) не определён" << endl;
			}
		}
	}
}