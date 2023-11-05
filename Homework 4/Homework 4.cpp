#include <iostream>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;


char sign(int number) {
    if (number < 0) {
        return '-';
    }
    else if (number == 0) {
        return '0';
    }
    else {
        return '+';
    }
}

bool is_number(string number) {
    for (int i = 0; i < number.length(); i++)
    {
        if ((!isdigit(number.at(i))) * (!(number.at(i) == '-')) * (!(number.at(i) == '+'))) {
            return 0;
        }
    }
    return 1;
}

int rectangle_area(int a, int b) {
    return (a * b);
}

int triangle_area(int c, int h) {
    return (0.5 * c * h);
}

int circle_area(int r) {
    return (M_PI * pow(r, 2));
}

string to_rim_number(int number) {
    const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const char* numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    std::string result = "";

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        while (number >= values[i]) {
            number -= values[i];
            result += numerals[i];
        }
    }

    return result;
}

int to_arab_number(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (i > 0 && romanMap[s[i]] > romanMap[s[i - 1]]) {
            result += romanMap[s[i]] - 2 * romanMap[s[i - 1]];
        }
        else {
            result += romanMap[s[i]];
        }
    }

    return result;
}

int random(int s) {
    int m = 37, b = 3, c = 64;
    // int m = 25173, b = 13849, c = 65537;
    if (s == 0) {
        return 0;
    }
    return ((m * random(s - 1) + b) % c);
}

const int rows1 = 3;
const int cols1 = 4;
const int rows2 = 4;
const int cols2 = 1;

void dot(float m1[rows1][cols1], float m2[cols1][cols2], float res[rows1][cols2])
{
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            float sum = 0;
            for (int x = 0; x < cols1; ++x)
            {
                sum += m1[i][x] * m2[x][j];
            }
            res[i][j] = sum;
        }
    }
}

int findMaxSeller(float sum[rows1][cols2], int size)
{
    int mx = 0;

    for (int i = 0; i < size; ++i)
    {
        if (sum[mx][0] <= sum[i][0])
        {
            mx = i;
        }
    }
    return mx + 1;
}

int findMinSeller(float sum[rows1][cols2], int size)
{
    int mx = 0;
    for (int i = 0; i < size; ++i)
    {
        if (sum[mx][0] >= sum[i][0])
        {
            mx = i;
        }
    }
    return mx + 1;
}

float findSum(float sum[rows1][cols2], int size)
{
    float sm = 0;
    for (int i = 0; i < size; ++i)
    {
        sm += sum[i][0];
    }
    return sm;
}


string convert(string old_number, int old_base, int new_base) {
    int number = 0, order;
    string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", result = "";

    for (char digit : old_number) {
        if (alphabet.find(digit) >= old_base) {
            return "-1";
        }
    }

    if (old_base != 10) {
        order = old_number.size() - 1;
        for (int i = order; i != -1; i--)
        {
            if (isdigit(old_number.at(i))) {
                int num = (old_number.at(i) - '0') * pow(old_base, order - i);
                number += num;
            }
            else {
                int num = (old_number.at(i) - '7') * pow(old_base, order - i);
                number += num;
            }
        }
    }
    else {
        number = stoi(old_number);
    }

    if (new_base == 10) {
        return to_string(number);
    }
    
    while (number > 0)
    {
        result += alphabet.at(number % new_base);
        number /= new_base;
    }
    reverse(result.begin(), result.end());
    return result;

}

int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cout << "Введите № задания: ";
    cin >> number;
    cout << endl;
    if (number == 1) {
        string content;
        ofstream outFile("test.txt");

        if (!outFile.is_open()) {
            cout << "Не удалось открыть файл" << endl;
            return 1;
        }

        cout << "Введите текст для записи в файл (exit для завершения ввода): ";
        while (getline(cin, content)) {
            if (content == "exit") {
                break;
            }
            outFile << content << endl;
        }
        outFile.close();

        ifstream Opfile("test.txt");
        if (!Opfile.is_open()) {
            cout << "Не удалось открыть файл" << endl;
            return 1;
        }

        int summa = 0;
        while (getline(Opfile, content)) {
            if (content == "") {
                continue;
            }

            for (int i = 0; i < content.length(); i++) {
                if (!isdigit(content.at(i))) {
                    cout << "В строке должны быть только числа!" << endl;
                    return 1;
                }
                summa += int(content.at(i)) - 48;
            }

            cout << summa << endl;
        }
    }
    else if (number == 2) {
        string str_number;

        cout << "Введите число: ";
        cin >> str_number;

        if (!is_number(str_number)) {
            cout << "В строке должны быть только числа!" << endl;
            return 1;
        }

        int num = stoi(str_number);

        cout << sign(num) << endl;
    }
    else if (number == 3) {
        int a, b, c, h, r;
        cout << "Введите длинну прямоугольника: " << endl;
        cin >> a;
        cout << "Введите ширину прямоугольника: " << endl;
        cin >> b;
        cout << "Введите длинну стороны треугольника: " << endl;
        cin >> c;
        cout << "Введите высоту треугольника: " << endl;
        cin >> h;
        cout << "Введите радиус круга: " << endl;
        cin >> r;

        if (a > 0 and b > 0) {
            cout << "Площадь прямоугольника: " << rectangle_area(a, b) << endl;
        }
        else {
            cout << "Площадь прямоугольника: не определена" << endl;
        }
        if (c > 0 and h > 0) {
            cout << "Площадь треугольника: " << triangle_area(c, h) << endl;
        }
        else {
            cout << "Площадь треугольника: не определена" << endl;
        }
        if (r > 0) {
            cout << "Площадь круга: " << circle_area(r) << endl;
        }
        else {
            cout << "Площадь круга: не определена" << endl;
        }

    }
    else if (number == 4) {
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 17; j++) {
                if (i < 8 and j < 6) {
                    cout << "*  ";
                }
                else {
                    cout << "---";
                }
            }
            cout << endl;
        }
    }
    else if (number == 5) {
        const int width = 120;
        const int height = 30;

        const float amplitude = 10.0f;
        const float frequency = 0.1f;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float sineValue = amplitude * sin(frequency * x);
                int pixelY = static_cast<int>(sineValue) + height / 2;

                if (y == pixelY) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
                    
            }
            cout << '\n';
        }

        return 0;
    }
    else if (number == 6) {
        string num;
        cout << "Введите римское число: ";
        cin >> num;
        
        int arab_number = to_arab_number(num);
        if (num != to_rim_number(arab_number)) {
            cout << "Неправильное римское число!";
        }
        else {
            cout << arab_number;
        }
    }
    else if (number == 7) {
        cout << random(1) << endl;
        cout << random(2) << endl;
        cout << random(3) << endl;
        cout << random(4) << endl;
    }
    else if (number == 8) {
        float sales[rows1][cols1] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0} };

        float costs[cols1][cols2] = {
            {1.2},
            {2.8},
            {5.0},
            {2.0} };

        float comission[cols1][cols2] = {
            {0.5},
            {0.4},
            {1.0},
            {1.5} };

        float sumSales[rows1][cols2];
        float sumComission[rows1][cols2];

        dot(sales, costs, sumSales);
        dot(sales, comission, sumComission);

        cout << "Max sales made seller: " << findMaxSeller(sumSales, rows1) << endl;
        cout << "Min sales made seller: " << findMinSeller(sumSales, rows1) << endl;

        cout << "Max comiss. made seller: " << findMaxSeller(sumComission, rows1) << endl;
        cout << "Min comiss. made seller: " << findMinSeller(sumComission, rows1) << endl;

        cout << "Sum: " << findSum(sumSales, rows1) - findSum(sumComission, rows1) << endl;
        cout << "Sum of comiss: " << findSum(sumComission, rows1) << endl;
        cout << "Sum through sales: " << findSum(sumSales, rows1) << endl;

        return 0;
    }
    else if (number == 9) {
        int old_base = 0, new_base = 0;
        string old_number, new_number, sold_base, snew_base;

        cout << "Введите число, которое необходимо перевести: ";
        cin >> old_number;
        cout << "Введите систему счисления числа, которое нужно перевести: ";
        cin >> sold_base;
        cout << "Введите систему счисления, в которую вы хотите перевести число: ";
        cin >> snew_base;

        if (!(is_number(sold_base)) or !(is_number(snew_base))) {
            cout << "Неправильный формат ввода данных" << endl;
            return 1;
        }

        old_base = stoi(sold_base);
        new_base = stoi(snew_base);

        if ((old_base > 36) or (old_base < 2) or (new_base > 36) or (new_base < 2)) {
            cout << "Система счисления должна быть в диапозоне от 2 до 36!" << endl;
            return 1;
        }

        new_number = convert(old_number, old_base, new_base);
        if (new_number == "-1") {
            cout << "Неправильное число!" << endl;
        }
        else {
            cout << new_number << endl;
        }
    }
}