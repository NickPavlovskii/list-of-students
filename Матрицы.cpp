// курсовая.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//Общая часть задания

//Программа должна оперировать тремя массивами (А, В и С), размерность которых задается(или определяется) на фазе работы программы.
//Необходимо:

//1) реализовать динамические структуры данных и алгоритмы их обработки, позволяющие поддерживать выполнение следующих функций :
// a)-консольный ввод / вывод данных о массивах А, В и С;
// б)-файловый ввод / вывод данных о массивах А, В и С;
// с)-интерактивное редактирование элементов матриц;
// 2)записать в матрицу С сумму матриц A и B заменяя все отрицательные числа нулями.
// 3) Определить является ли матрица С результатом возведения матрицы А или В в квадрат


#include <iostream>;
#include <fstream>;
#include <fstream>;
#include <windows.h>;

using namespace std;
int sizeC, sizeB, sizeA, ** A, ** B, ** C, ** D, ** K;
string name; ofstream out;
ifstream in;

void Matrix(int** array, int size)
{
    cout << "Ввод матрицы : \n";
    for (int i = 0; i < size; i++)         //Заполнение динамической матрицы 
    {
        for (int j = 0; j < size; j++)
        {
            cin >> array[i][j];
        }
    }
}
int Size()        // Функция которая считает размерность введенной матрицы
{
    system("cls");
    char* str = new char[1024];
    int i = 0;
    cout << "Введите название файла, из которого вы хотите извлечь матрицу: ";
    name = "name.txt";
    cin >> name;
    in.open(name);
    while (!in.eof())
    {
        in.getline(str, 1024, '\n');
        i++;
    }
    in.close();
    delete str;
    return i;
}
void Matrix_file(int** array, int size)             // Функция ввода матрицы
{
    system("cls");
    cout << "Введите название файла, из которого вы хотите извлечь матрицу: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            in.open(name);
            in >> array[i][j];
            in.close();
        }
    }
}
void InputMatrix()                                        // Ввод матриц
{
    int choice1;
    char N = 'n';
    char choice2 = 'n';
    do
    {

        do
        {
            system("cls");
            cout << "Как вы хотите ввести матрицу: \n";
            cout << "1 - Через консоль\n";
            cout << "2 - Через файл\n";
            cin >> choice1;
            cout << "\n";
        } while (choice1 != 1 && choice1 != 2);
        if (choice1 == 1)                                                    
        {
            do
            {
                system("cls");
                cout << "Выберите матрицу, которую хотите ввести [A/B/C]: \n";
                cin >> choice2;
            }
 while (choice2 != 'A' && choice2 != 'B' && choice2 != 'C');
           
            switch (choice2)
            {
                system("cls");
            case 'A':
                sizeA = 0;
                cout << "\nВведите размерность квадратной матрицы : ";         //Ввод размерности квадратной матрицы 
                cin >> sizeA;
                A = new int* [sizeA];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeA; i++)
                    A[i] = new int[sizeA];
                Matrix(A, sizeA);                                           // Функция заполнения динамической матрицы
                break;
            case 'B':
                sizeB = 0;
                cout << "\nВведите размерность квадратной матрицы : ";         //Ввод размерности квадратной матрицы 
                cin >> sizeB;
                B = new int* [sizeB];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeB; i++)
                    B[i] = new int[sizeB];
                Matrix(B, sizeB);
                break;
            case 'C':
                sizeC = 0;
                cout << "\nВведите размерность квадратной матрицы : ";         //Ввод размерности квадратной матрицы 
                cin >> sizeC;
                C = new int* [sizeC];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeC; i++)
                    C[i] = new int[sizeC];
                Matrix(C, sizeC);
                break;
            }
        }
        else if (choice1 == 2)
        {
            do
            {
                cout << "Выберите матрицу, которую хотите ввести [A/B/C]: \n";
                cin >> choice2;
            } while (choice2 != 'A' && choice2 != 'B' && choice2 != 'C');
            switch (choice2)
            {
            case 'A':
                sizeA = Size();
                A = new int* [sizeA];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeA; i++)
                    C[i] = new int[sizeA];
                Matrix_file(A, sizeA);
                break;
            case 'B':
                sizeC = Size();
                B = new int* [sizeB];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeB; i++)
                    B[i] = new int[sizeB];
                Matrix_file(B, sizeB);
                break;
            case 'C':
                sizeC = Size();
                C = new int* [sizeC];                                         //Создание динамической матрицы 
                for (int i = 0; i < sizeC; i++)
                    C[i] = new int[sizeC];
                Matrix_file(C, sizeC);
                break;
            }
        }
        cout << "Вы хотите ввести еще одну из матриц ? [y/n]: ";
        cin >> N;
    } while (N == 'y');
}
void OutputMatrix(int** array, int size)                             //Создание функции для вывода матрицы в консоль 
{
    cout << "\nИтоговая матрица : " << endl;
    for (int i = 0; i < size; i++)                                         //Вывод динамической Матрицы 
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void OutputMatrix_file(int** array, int size)                        //Создание функции для вывода матрицы в консоль 
{
    cout << "Введите название файла, в который вы хотите сохранить матрицу: ";
    string name = "name.txt";
    cin >> name;
    out.open(name);
    for (int i = 0; i < size; i++)                                     //Запись динамической Матрицы в файл
    {
        for (int j = 0; j < size; j++)
        {
            out << array[i][j] << "\t";
        }
        out << "\n";
    }
    out.close();
}
void OutputMatrixS()                              // Функция вывода матриц
{
    int choice1;
    char N = 'n';
    char choice2 = 'n';
    do {

        do
        {
            cout << "Как вы хотите вывести матрицу: \n";
            cout << "1 - В консоль?\n";
            cout << "2 - В Файл?\n";
            cin >> choice1;
            cout << "\n";
        } while (choice1 != 1 && choice1 != 2);
        do
        {
            cout << "Выберите матрицу, которую хотите вывести [A/B/C]: \n";
            cin >> choice2;
        } while (choice2 != 'A' && choice2 != 'B' && choice2 != 'C');
        if (choice1 == 1)
        {
            switch (choice2)
            {
            case 'A': OutputMatrix(A, sizeA); break;
            case 'B': OutputMatrix(B, sizeB); break;
            case 'C': OutputMatrix(C, sizeC); break;
            }
        }
        else if (choice1 == 2)
        {
            switch (choice2)
            {
            case 'A': OutputMatrix_file(A, sizeA); break;
            case 'B': OutputMatrix_file(B, sizeB); break;
            case 'C': OutputMatrix_file(C, sizeC); break;
            }
        }
        cout << "Вы хотите вывести еще одну из матриц ? [y/n]: ";
        cin >> N;
    } while (N == 'y');
}
void Edit(int** array, int size)                                      //Функция редактирования матриц
{
    int i, j, NewE;
    for (i = 0; i < size; i++)                                                         // Осуществление выбора редактирования
    {                                                                                   // необходимого элемента матрицы 
        for (j = 0; j < size; j++)
        {
            cout << "[" << i << "]" << "[" << j << "] =" << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    if ((size - 1) <= i || (size - 1) <= j)
    {
        cout << "Введите положение элемента в матрице, который необходимо поменять: \n";        //замена элемента матрицы 
        cin >> i >> j;
        cout << "Введите новый элемент: ";
        cin >> NewE;
        A[i][j] = NewE;
    }
    else
    {
        cout << "Неправильно ввод элемента матрицы!\n";
    }
}
void EditMatrixs()      // Функция в которой происходит редактирование матрицы
{
    char choose = 'n';
    do
    {
        do
        {
            cout << "Выберите матрицу, которую хотите отредактировать [A/B/C]: \n";
            cin >> choose;
            cout << "\n";
        } while (choose != 'A' && choose != 'B' && choose != 'C');
        switch (choose)
        {
        case 'A': Edit(A, sizeA); break;
        case 'B': Edit(B, sizeB); break;
        case 'C': Edit(C, sizeC); break;
        }
        cout << "Вы хотите отредактировать еще одну из матриц ? [y/n]: ";
        cin >> choose;
    } while (choose == 'y');
}
void task3()
{
    system("cls");
    int j, n = 0, i, l = 0, k = 0;

    if (sizeA == sizeB)                    
    {
        for (i = 0; i < sizeA; i++)          
        {
            for (j = 0; j < sizeA; j++)
            {
                C[i][j] += A[i][k] + B[k][j];
                if (C[i][j] < 0)
                {
                    C[i][j] = 0;
                }
            }
        }
        cout << "C: " << C[i][j] <<endl;
        cout << "----------------";
    }
    else
    {
        cout << "Невозможно сложить матрицы: Разные размеры матриц";
    }

}
void task17()                                                           
{
    int i, j, k, n;
    n = 1;
    
        D = new int* [sizeA];                                       //Создание динамической матрицы D
        for (int i = 0; i < sizeA; i++)
            D[i] = new int[sizeA];
        for (i = 0; i < sizeA; i++)
        {
            for (j = 0; j < sizeA; ++j)
            {
                D[i][j] = 0;
                for (k = 0; k < sizeA; k++)
                {
                    D[i][j] += A[i][k] * A[k][j];                   
                }
            }
        }
        for (i = 0; i < sizeA; i++)             
        {
            for (j = 0; j < sizeA; j++)
            {
                if (C[i][j] == D[i][j])
                {
                    n++;
                }
            }
        }
        if (n == (sizeA))                                                       
            cout << "Возведение матрицы А в квадрат равно Матрице С\n";
        else
        {
            cout << "Возведение матрицы А в квадрат НЕ равно Матрице С\n";
        }
    
        for (int i = 0; i < sizeB; i++)
            D[i] = new int[sizeB];
        for (i = 0; i < sizeB; i++)
        {
            for (j = 0; j < sizeB; ++j)
            {
                K[i][j] = 0;
                for (k = 0; k < sizeB; k++)
                {
                    K[i][j] += B[i][k]*B[k][j];                   
                }
            }
        }
        for (i = 0; i < sizeB; i++)              
        {
            for (j = 0; j < sizeB; j++)
            {
                if (C[i][j] == K[i][j])
                {
                    n++;
                }
            }
        }
        if (n == (sizeB))                                                       
            cout << "Возведение матрицы B в квадрат равно Матрице С\n";
        else
        {
            cout << "Возведение матрицы B в квадрат НЕ равно Матрице С\n";
        }
}
void help()
{
    system("cls");

    puts("\n\n Данная программа предназначена для работы с массивами");

    puts(" вы можете вывессти/ввести матрицу с помощью консоли или файла, ");

    puts(" редактировать каждый элемент массивов, ");

    puts(" сравнить массив С с квадратом массива А и В,");

    puts(" заменить массив С на сумму массивов А и В, при этом заменить отрицательные элементы на 0");



    puts(" Если возникли проблемы обращайтесь, пожалуйста, на электронную почту:");

    puts(" o_oniklad0_0.ru\n");

    system("pause");


}
void menu()                                         // внешний вид меню
{
    cout << "\n===============================" << endl;
    cout << "MENU" << endl;
    cout << "1 - Ввод матриц : " << endl;
    cout << "2 - Вывод матриц : " << endl;
    cout << "3 - Заменить матрицу С на сумму матриц А и В  : " << endl;
    cout << "4 - Сравнить матрицу С с квадратами  матриц А и В : " << endl;
    cout << "5 - Редактирование матриц : " << endl;
    cout << "6 - Справка" << endl;
    cout << "===============================" << endl;
    cout << "0 - Exit" << endl;
    cout << "Enter your choose (0-6): \n";
}
int main()
{
    setlocale(LC_ALL, "rus");                   //подключение русского языка
    int choice;
    choice = 0;                                 // Благодаря "Choice" происходит выбор пункта меню
    do
    {
        menu();
        choice = 0;
        cin >> choice;
        switch (choice)                         // Способ реализации меню 
        {
        case 1:
            InputMatrix();
            break;
        case 2:
            OutputMatrixS();
            break;
        case 3:
            task3();
            break;
        case 4:
            task17();
            break;
        case 5:
            EditMatrixs();
            break;
        case 6:
            help();
            break;
        default:

            printf("Что-то пошло не так, введите пункт меню повторно\n");
            system("pause");
        }
    } while (choice > 0);
    system("pause");

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
