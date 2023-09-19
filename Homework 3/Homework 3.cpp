#include <iostream>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(std::vector<char>& arr) {
	int n = arr.size();

	const int numBuckets = 26;
	std::vector<std::vector<char>> buckets(numBuckets);

	for (int i = 0; i < n; i++) {
		int index = arr[i] - 'A';
		buckets[index].push_back(arr[i]);
	}

	int index = 0;
	for (int i = 0; i < numBuckets; i++) {
		for (char letter : buckets[i]) {
			arr[index++] = letter;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int number;
	cout << "Введите № задания" << endl;
	cin >> number;
	cout << endl;
	if (number == 1) {
		double m, S, n, p, r;
		cout << "Введите значение S: ";
		cin >> S;
		cout << "Введите значение p: ";
		cin >> p;
		cout << "Введите значение n: ";
		cin >> n;
		cout << endl;
		if (p == 0 or S >= 1000 or p >= 1000 or n >= 1000) {
			cout << "Не определено" << endl;
		}
		else {
			r = p / 100.0;
			m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
			cout << "m = " << m << endl;
		}
	}
	else if (number == 2) {
		double m, m1, S, n, p, r;
		cout << "Введите значение S: ";
		cin >> S;
		cout << "Введите значение m: ";
		cin >> m;
		cout << "Введите значение n: ";
		cin >> n;
		cout << endl;

		for (int p = 1; p < 100; p++) {
			r = p / 100.0;
			m1 = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
			m1 = round(m1 * pow(10, 2)) / pow(10, 2);
			if (m1 == m) {
				cout << "p = " << p << endl;
				break;
			}
		}
	}
	else if (number == 3) {
		string content, c;
		ofstream outFile("test.txt");

		if (!outFile.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			return 1;
		}

		cout << "Введите текст для записи в файл (Ctrl+Z для завершения ввода): ";
		while (getline(cin, content)) {
			outFile << content << endl;
		}
		outFile.close();

		ifstream Opfile("test.txt");
		if (!Opfile.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			return 1;
		}

		while (getline(Opfile, content)) {
			cout << content << endl;
		}
	}
	else if (number == 4) {
		string fileContent;
		ifstream file;
		string line;

		file.open("test.txt");
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			return 1;
		}

		while (getline(file, line))
		{
			fileContent += line + " ";
		}

		string numberString = "";
		for (int i = 0; i < fileContent.length(); i++)
		{
			if (isdigit(fileContent.at(i)))
			{
				numberString += fileContent.at(i);
			}
			else if (fileContent.at(i) == ' ') {
				numberString += "\n";
			}
		}

		if (numberString != "")
		{
			cout << numberString << endl;
		}
		numberString = "";

		file.close();
	}
	else if (number == 5) {
		string stroka;

		cin >> stroka;
		if (stroka.length() != 30)
		{
			cout << "Введена строка длинной не 30 символов!" << endl;
			return 1;
		}
		cout << endl;

		vector<char> arr;
		for (int i = 0; i < stroka.length(); i++)
		{
			if (stroka.at(i) != ' ')
			{
				arr.push_back(stroka.at(i));
			}
		}

		cout << "Исходная строка: ";
		cout << stroka;
		cout << endl;

		bucketSort(arr);

		string sorted = "";
		cout << "Отсортированная строка: ";
		for (int i = 0; i < arr.size(); i++) {
			sorted += arr[i];
		}
		cout << sorted;
	}
}
