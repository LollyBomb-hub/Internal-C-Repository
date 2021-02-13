#include <iostream>
#include <cstdlib>

// Определяем длину массива в виде вставки LN со значением 10
#define LN 10


// Используем поле имен std для удобства вывода
using namespace std;


// Объявляем прототипы функций
void show(double*);
void bubble_sort(double*);
void init_array(double*);


int main()
{
    // Указатель на массив типа double
    double* arr;
    arr = new double[LN];

    // Инициализируем массив числами заданными в функции
    init_array(arr);

    // Выводим массив на экран, сортируем и снова выводим на экран
    show(arr);
    bubble_sort(arr);
    show(arr);

    delete[] arr;
    return EXIT_SUCCESS;
}


void init_array(double* ptr)
{
    /*
     * Функция инициализирующая массив.
     *
     * Принимает на вход:
     *      double* ptr - указатель на первый элемент массива.
     */

    // Массив который мы копируем по адресам переданным указателем.
    double new_arr[LN] = {1., 42., -20., -5.2, -6.43, 2.3, 2.5, 0.0, 0.24, -0.54};
    // Цикл по массиву для инициализации данных.
    for(int i = 0; i < LN; i++)
    {
        ptr[i] = new_arr[i];
    }
}


void bubble_sort(double* arr)
{
    /*
     * Функция сортировки пузырьком.
     * Принимает на вход:
     *      double* arr - указатель на область памяти массива.
     */

    bool stop_flag = true;         // Флаг который следит за сменой элементов на каждой итерации главного цикла

    while(stop_flag)
    {
        stop_flag = false;
        for(int i=0; i < LN; i++)
        {
            if(arr[i-1] > arr[i])
            {
                // Тут происходит смена элементов в позиции i и i - 1 местами.
                swap(arr[i], arr[i-1]);
                stop_flag = true;
            }
        }
    }
}


void show(double* arr)
{
    /*
     * Функция вывода массива в консоль.
     * Принимает на вход:
     *      double* arr - Указатель на область памяти массива.
     */

    cout << "Array: [";

    for(int i=0; i < LN - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[LN - 1] << "]\n";
}
