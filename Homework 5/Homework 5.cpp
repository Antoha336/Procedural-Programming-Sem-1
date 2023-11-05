#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <cstdlib>

using namespace std;

double log_base(double number, double base) {
    return log(number) / log(base);
}

bool is_number(string number) {
    for (char c : number) {
        if (!isdigit(c) and c != '-' and c != ',') {
            return 0;
        }
    }
    return 1;
}

bool is_trivial_number(int number) {
    int number_sqrt = sqrt(number);
    for (int i = 2; i < number_sqrt + 1; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

string convert(double N, int base) {
    string result = "";
    int tipon = N;
    double tfpon = modf(N, &N);
    while (tipon > 0) {
        result = to_string(tipon % base) + result;
        tipon /= base;
    }

    result += ".";

    int m;
    for (int i = 1; i <= 6; i++) {
        if (tfpon * pow(10, i) == (int) (tfpon * pow(10, i))) {
            m = -i;
            break;
        }
        else {
            m = -4;
        }
    }

    int L = -log_base(pow(10, m) / 2, base);
    for (int i = 0; i < L; i++) {
        tfpon *= base;
        result = result + to_string((int)tfpon);
        tfpon = modf(tfpon, &tfpon);
    }
    return result;
}

int task_1_1(int a, int b) {
    int number_1, number_2, new_remain, remain;

    if (a == 0 and b == 0) {
        return -1;
    }
    else if (a == 0 or b == 0){
        return a + b;
    }

    if (a > b) {
        number_1 = a; number_2 = b;
    }
    else {
        number_1 = b; number_2 = a;
    }

    remain = number_1 % number_2;
    if (remain == 0) {
        return number_2;
    }

    while (number_2 % remain != 0 and number_2 > 0) {
        new_remain = number_2 % remain;
        number_2 = remain;
        remain = new_remain;
    }
    return remain;
}

int task_1_2(int a, int b) {
    if (a == 0 and b == 0) {
        return -1;
    }
    else if (a == 0 or b == 0) {
        return a + b;
    }

    while (a > 0 and b > 0) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a + b;
}


string task_2(int number) {
    string result = "";
    for (int i = 2; i <= number; i++) {
        if (is_trivial_number(i)) {
            result += to_string(i) + " ";
        }
    }
    return result;
}

int* task_3() {
    string content, word;
    ofstream new_file("task_3.txt");

    cout << "Введите текст для записи в файл (<exit> для завершения ввода): " << endl;
    while (getline(cin, content)) {
        if (content == "exit") {
            break;
        }
        new_file << content;
    }
    new_file.close();

    cout << "Введите слово, которое хотите найти в текстовом файле: ";
    cin >> word;

    ifstream file("task_3.txt");
    int line = 0, index;
    while (getline(file, content)) {
        line++;
        index = content.find(word);
        if (index != -1) {
            int* answer = new int[2];
            answer[0] = index; answer[1] = line;
            return answer;
        }
    }
    int* answer = new int[1];
    answer[0] = -1;
    return answer;
}

int task_4(string text, string under_string) {
    return text.find(under_string);
}

double task_5(int x) {
    double sum = 0;
    for (int i = 0; i <= 10; i++) {
        sum += ((tgamma(2 * i + 2) / (pow(i + 1, i) * pow(x, 4 * i))));
    }
    return sum;
}

void task_6() {
    string input = " ";
    int k = 0;
    double x, sum = 0, ar = 0;
    cin >> input;
    while (input != "exit") {
        if (!is_number(input)) {
            cout << "Неправильное число!" << endl;
            continue;
        }
        x = stod(input);
        sum += x;
        k++;
        ar = sum / k;
        cout << "Введено чисел: " << k << " Сумма: " << sum << " Сред. арифметическое: " << ar << endl;
        cin >> input;
    } 
}

void task_7(int N, int base) {
    double number;
    string content;
    ofstream new_file("task_7_before.txt");

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 10.0);

    new_file.imbue(locale(""));
    
    for (int i = 0; i < N; i++) {
        number = distribution(gen);
        new_file << fixed << number << endl;
    }
    new_file.close();

    int i = 0;
    string* numbers = new string[N];
    ifstream file("task_7_before.txt");
    while (getline(file, content)) {
        number = stod(content);
        numbers[i] = convert(number, base);
        i++;
    }
    file.close();

    ofstream finish_file("task_7_after.txt");
    for (int i = 0; i < N; i++) {
        finish_file << numbers[i] << endl;
    }
    new_file.close();

    delete[] numbers;
}

void task_8() {
    // Одномерные массивы #33

    // Создание одномерного массива и заполнение его элементами
    int* A = new int[10];
    cout << "Изначальный массив: ";
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100 + 1;
        cout << to_string(A[i]) + " ";
    }
    cout << endl;

    // Поиск необходимого элемента
    for (int i = 1; i < 9; i++) {
        if (A[0] < A[i] and A[i] < A[9]) {
            cout << "Номер элемента: " << i + 1 << endl;
            break;
        }
    }

    // Освобождение памяти
    delete[] A;
}

void task_9(int N) {
    // Задачи сортировки #43

    // Создание одномерного массива и заполнение его элементами
    int* A = new int[N];
    cout << "Изначальный массив: ";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100 + 1;
        cout << to_string(A[i]) + " ";
    }

    // "Переворачивание" массива
    int temp = 0;
    for (int i = 0; i < N / 2; i++) {
        temp = A[N - 1 - i];
        A[N - 1 - i] = A[i];
        A[i] = temp;
    }

    // Вывод обновлённого массива
    cout << endl << "Обновлённый массив: ";
    for (int i = 0; i < N; i++) {
        cout << to_string(A[i]) + " ";
    }

    // Освобождение памяти
    delete[] A;
}

void task_10(int N) {
    // Двумерные массивы #56
    // Создание массива для хранения данных чисел (в данном случае рандомных)
    int* a = new int[N];
    cout << "Данные числа: ";
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100 + 1;
        cout << to_string(a[i]) + " ";
    }

    // Создание двумерного массива (т.е. матрицы)
    int** b = new int* [N];
    for (int i = 0; i < N; ++i) {
        b[i] = new int[N];
    }

    // Заполнение матрицы по заданной формуле
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = a[i] - 3 * a[j];
        }
    }

    // Вывод матрицы
    cout << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < N; ++i) {
        delete[] b[i];
    }
    delete[] a, b;
}

void print_matrix(int** matrix, int rows, int cols) {
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void task_11() {
    int M = 2, N = 5;

    // Создание матриц
    int** A = new int* [N];
    int** B = new int* [N];
    int** C = new int* [N];
    int** D = new int* [N];
    int** E = new int* [N];
    for (int i = 0; i < M; ++i) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
        D[i] = new int[N];
        E[i] = new int[N];
    }

    // Заполнение матрицы A
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            A[i][j] = input;
        }
    }

    // Заполнение матрицы B (по формуле)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = i * j - (5 - i - j);
        }
    }

    // Заполнение матрицы С (случайные числа на отрезке [-3; 6])
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = rand() % (6 - (-3) + 1) + (-3);
        }
    }

    // Заполнение матрицы E (единицы)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            E[i][j] = 1;
        }
    }

    // Заполнение матрицы D (D=6E-C-2B-3A)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = 6 - C[i][j] - 2 * B[i][j] - 3 * A[i][j];
        }
    }

    // Вывод матрицы A
    cout << endl << "Матрица A:";
    print_matrix(A, M, N);
    cout << endl << "Матрица B:";
    print_matrix(B, M, N);
    cout << endl << "Матрица C:";
    print_matrix(C, M, N);
    cout << endl << "Матрица E:";
    print_matrix(E, M, N);
    cout << endl << "Матрица D:";
    print_matrix(D, M, N);

    // Освобождение памяти
    for (int i = 0; i < M; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
        delete[] D[i];
        delete[] E[i];
    }
    delete[] A, B, C, D, E;
}

void task_12(int N) {
    // Переборные задачи #88

    // Создание массива и заполнение его значениеями (в данном случае рандомными)
    int* sequence = new int[N];
    cout << "Данная последовательность: ";
    for (int i = 0; i < N; i++) {
        sequence[i] = rand() % 10 + 1;
        cout << to_string(sequence[i]) + " ";
    }

    // Вычисление самой длинной возрастающей последовательности
    cout << endl;
    int count = 1, max_count = 1;
    string subsequence, max_subsequence;
    subsequence = to_string(sequence[0]) + " ";
    for (int i = 0; i < N - 1; i++) {
        if (sequence[i] < sequence[i+1]) {
            count += 1;
            subsequence += to_string(sequence[i + 1]) + " ";
        }
        else {
            if (count > max_count) {
                max_count = count;
                max_subsequence = subsequence;
            }
            count = 1;
            subsequence = to_string(sequence[i + 1]) + " ";
        }
    }
    cout << "Максимальная длинна возрастающей последовательности: " << max_count << endl;
    cout << "Последовательность: " << max_subsequence << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cout << "Введите № задания: ";
    cin >> number;
    cout << endl;
    if (number == 1) {
        string input_1, input_2;
        cout << "Введите первое число: ";
        cin >> input_1;
        cout << "Введите второе число: ";
        cin >> input_2;
        if (!is_number(input_1) or !is_number(input_2)) {
            cout << "Неправильный ввод!";
            return 0;
        }
        cout << "Наибольший общий делитель (делениями): " << task_1_1(stoi(input_1), stoi(input_2)) << endl;
        cout << "Наибольший общий делитель (вычитаниями): " << task_1_2(stoi(input_1), stoi(input_2)) << endl;
    }
    else if (number == 2) {
        string input;
        cout << "Введите число: ";
        cin >> input;
        if (!is_number(input)) {
            cout << "Неправильный ввод!";
            return 0;
        }
        cout << "Простые числа: " << task_2(stoi(input)) << endl;
    }
    else if (number == 3) {
        int* index = task_3();
        if (index[0] != -1) {
            cout << "Слово найдено, линия: " << index[1] << ", позиция первого символа: " << index[0] << endl;
        }
        else {
            cout << "Слово не найдено" << endl;
        }

        delete[] index;
    }
    else if (number == 4) {
        string text, under_string;
        cout << "Введите строку: ";
        cin >> text;
        cout << "Введите подстроку: ";
        cin >> under_string;
        int index = task_4(text, under_string);
        if (index != -1) {
            cout << "Подстрока найдена, позиция первого символа: " << index << endl;
        }
        else {
            cout << "Подстрока не найдена" << endl;
        }
    }
    else if (number == 5) {
        string input;
        cout << "Введите x: ";
        cin >> input;
        if (!is_number(input)) {
            cout << "Неправильный ввод!";
            return 0;
        }
        int x = stoi(input);
        cout << fixed << setprecision(6);
        cout << "Сумма: " << task_5(x) << endl;
    }
    else if (number == 6) {
        cout << "Обработка последовательности дробных чисел. После ввода каждого числа нажимайте <Enter>" << endl;
        task_6();
    }
    else if (number == 7) {
        string input_1, input_2;
        cout << "Введите число N: ";
        cin >> input_1;
        cout << "Введите систему счисления: ";
        cin >> input_2;
        if (!is_number(input_1) or !is_number(input_2)) {
            cout << "Неправильный ввод!";
            return 0;
        }
        int N = stoi(input_1);
        int base = stoi(input_2);

        if (2 > base or base > 9) {
            cout << "Система счисления должна быть в пределах от двочиной до девятеричной" << endl;
            return 0;
        }
        task_7(N, base);
    }
    else if (number == 8) {
        // Одномерные массивы #33
        task_8();
    }
    else if (number == 9) {
        // Задачи сортировки #43
        string input;
        cout << "Введите N: ";
        cin >> input;
        if (!is_number(input)) {
            cout << "Неправильный ввод!" << endl;
            return 0;
        }
        int N = stoi(input);
        task_9(N);
    }
    else if (number == 10) {
        // Двумерные массивы #56
        string input;
        cout << "Введите N: ";
        cin >> input;
        if (!is_number(input)) {
            cout << "Неправильный ввод!" << endl;
            return 0;
        }
        int N = stoi(input);
        task_10(N);
    }
    else if (number == 11) {
        // Функции #66
        task_11();
    }
    else if (number == 12) {
        // Переборные задачи #88
        string input;
        cout << "Введите N: ";
        cin >> input;
        if (!is_number(input)) {
            cout << "Неправильный ввод!" << endl;
            return 0;
        }
        int N = stoi(input);
        task_12(N);
    }
    cout << endl;
    main();
}