#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <cstdlib>

using namespace std;

int main();

double log_base(double number, double base) {
    return log(number) / log(base);
}

void is_correct() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Неправильный ввод!" << '\n' << endl;
        main();
    }
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


void task_2(double number) {
    int size = (number / log(number)) * 1.2;
    int* trivial_numbers = new int[size];
    trivial_numbers[0] = 2;

    cout << "Простые числа: 2 ";
    int count = 1;
    for (int i = 3; i <= number; i += 2) {
        bool flag = true;
        for (int j = 0; j < count; j++) {
            if (i % trivial_numbers[j] == 0) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            trivial_numbers[count] = i;
            cout << trivial_numbers[count] << " ";
            count++;
        }
    }

    
    for (int i = 0; i < size; ++i) {
        if (trivial_numbers[i] != 0) {
            
        }
    }

    delete[] trivial_numbers;
}

void task_2_1(double number) {
    bool* trivial_numbers = new bool[number + 1];
    for (int i = 0; i < number + 1; i++) {
        trivial_numbers[i] = false;
    }
    trivial_numbers[2] = true;

    int count = 1;
    for (int i = 3; i < number + 1; i += 2) {
        bool flag = true;
        for (int j = 0; j < count; j++) {
            if (trivial_numbers[j]  and i % j == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            trivial_numbers[i] = true;
            count++;
        }
    }

    cout << "Простые числа: ";
    for (int i = 0; i < number + 1; ++i) {
        if (trivial_numbers[i]) {
            cout << i << " ";
        }
        
    }

    delete[] trivial_numbers;
}

int* task_3() {
    string content, word;
    ofstream new_file("task_3.txt");

    cout << "Введите текст для записи в файл (<exit> для завершения ввода): " << endl;
    while (getline(cin, content)) {
        is_correct();
        if (content == "exit") {
            break;
        }
        new_file << content;
    }
    new_file.close();

    cout << "Введите слово, которое хотите найти в текстовом файле: ";
    cin >> word;
    is_correct();

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
    is_correct();
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
        is_correct();
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

void task_7_1(int N, int base) {
    int number;
    string content;
    ofstream new_file("task_7_1_before.txt");

    srand(time(0));
    for (int i = 0; i < N; i++) {
        number = rand() % 0xFFFF + 1;
        new_file << hex << number << endl;
    }
    new_file.close();

    int i = 0;
    string* numbers = new string[N];
    ifstream file("task_7_1_before.txt");
    while (getline(file, content)) {
        number = stoi(content, nullptr, 16);
        numbers[i] = convert(number, base);
        i++;
    }
    file.close();

    ofstream finish_file("task_7_1_after.txt");
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
    delete[] a;
    delete[] b;
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
            int number;
            cin >> number;
            is_correct();
            A[i][j] = number;
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
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;
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

void print_permutation(int* balls, int n, int& count) {
    bool flag = false;
    
    // Вывод массива и проверка на условие задачи
    for (int i = 0; i < n; ++i) {
        cout << balls[i] << " ";
        if (balls[i] == i + 1) {
            flag = true;
        }
    }

    // Ведение подсчёта при соблюдении условия
    if (flag) {
        count++;
    }
    cout << endl;
}
    

void perestanovka(int* balls, int m, int n, int& count) {
    // Вывод уникальных перестановок
    if (m == n) {
        print_permutation(balls, n, count);
        return;
    }

    // Создание новых перестановок
    for (int i = m; i <= n; ++i) {
        swap(balls[i - 1], balls[m - 1]);
        perestanovka(balls, m + 1, n, count);
        swap(balls[i - 1], balls[m - 1]);
    }
}

int task_13(int N) {
    // Создание массива с шаириками и заполнение этого массива
    int* balls = new int[N];
    for (int i = 0; i < N; i++) {
        balls[i] = i + 1;
    }

    // Запуск перестановок
    int count = 0;
    perestanovka(balls, 1, N, count);

    // Освобождение памяти
    delete[] balls;

    return count;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int number;
    cout << "Введите № задания: ";
    cin >> number;
    is_correct();

    cout << endl;
    if (number == 1) {
        int number_1, number_2;
        cout << "Введите первое число: ";
        cin >> number_1;
        is_correct();
        cout << "Введите второе число: ";
        cin >> number_2;
        is_correct();
        cout << "Наибольший общий делитель (делениями): " << task_1_1(number_1, number_2) << endl;
        cout << "Наибольший общий делитель (вычитаниями): " << task_1_2(number_1, number_2) << endl;
    }
    else if (number == 2) {
        int number;
        cout << "Введите число N: ";
        cin >> number;
        is_correct();
        task_2(number);
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
        is_correct();
        cout << "Введите подстроку: ";
        cin >> under_string;
        is_correct();
        int index = task_4(text, under_string);
        if (index != -1) {
            cout << "Подстрока найдена, позиция первого символа: " << index << endl;
        }
        else {
            cout << "Подстрока не найдена" << endl;
        }
    }
    else if (number == 5) {
        int number;
        cout << "Введите x: ";
        cin >> number;
        is_correct();

        cout << fixed << setprecision(6);
        cout << "Сумма: " << task_5(number) << endl;
    }
    else if (number == 6) {
        cout << "Обработка последовательности дробных чисел. После ввода каждого числа нажимайте <Enter>" << endl;
        task_6();
    }
    else if (number == 7) {
        int N, base;
        cout << "Введите число N: ";
        cin >> N;
        is_correct();
        cout << "Введите систему счисления: ";
        cin >> base;
        is_correct();

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
        int N;
        cout << "Введите N: ";
        cin >> N;
        is_correct();
        task_9(N);
    }
    else if (number == 10) {
        // Двумерные массивы #56
        int N;
        cout << "Введите N: ";
        cin >> N;
        is_correct();
        task_10(N);
    }
    else if (number == 11) {
        // Функции #66
        task_11();
    }
    else if (number == 12) {
        // Переборные задачи #88
        int N;
        cout << "Введите N: ";
        cin >> N;
        is_correct();
        task_12(N);
    }
    else if (number == 13) {
        // Шарики
        int N;
        cout << "Введите N: ";
        cin >> N;
        is_correct();
        int answer = task_13(N);
        cout << "Кол-во ситуаций: " << answer << endl;
    }
    cout << endl;
    main();
}