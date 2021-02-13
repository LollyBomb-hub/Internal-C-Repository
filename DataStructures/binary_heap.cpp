#include<cstdlib>
#include<iostream>

// Используем поле имен std для удобства вывода
using namespace std;

// Объявляем прототипы функций
void build_max_heap(double*, int);
void build_min_heap(double*, int);
void _heapify_min(double*, int, int);
void _heapify_max(double*, int, int);

// Вспомогательные функции для работы с массивом
void init_array(double*, int);   // Инициализация значениями
void show(double*, int);         // Вывод в консоль


int main()
{
    int length_array = 10;
    double* arr_ptr;
    arr_ptr = new double[length_array];

    init_array(arr_ptr, length_array);
    show(arr_ptr, length_array);

    cout << endl << "Min binary heap:" << endl;
    build_min_heap(arr_ptr, length_array);
    show(arr_ptr, length_array);

    cout << endl << "Max binary heap:" << endl;
    build_max_heap(arr_ptr, length_array);
    show(arr_ptr, length_array);

    return EXIT_SUCCESS;
}


void build_min_heap(double* arr, int N)
{
    /*
     *
     * Алгоритм построения min кучи из массива.
     * Принимает на вход:
     *      double* arr - Указатель на область памяти изменяемого массива.
     *      int N       - Длинна массива
     *
     */


    for(int i = N / 2 - 1; i >= 0; i--)
    {
        _heapify_min(arr, i, N);   // Переупорядочивание поддерева
    }
}


void _heapify_min(double* arr, int idx, int n)
{
    /*
     *
     * Функция переупорядочивающая поддерево с корнем в узле idx и минимальным номером
     * элемента не больше n
     * Принимает на вход:
     *      double* arr   - Указатель на область памяти изменяемого массива.
     *      int idx       - Индекс корневого узла поддерева
     *      int n         - Минимальный элемент поддерева
     *
     */


    int largest = idx;        // Индекс наименьшего элемента
    int left = 2 * idx + 1;   // Индекс левого потомка
    int right = 2 * idx + 2;  // Индекс правого потомка

    // Если индекс левого потомка не превышает индекс максимального элемента
    // и значение в левом узле меньше, чем значение в корневом узле, то присваиваем largest индекс левого узла
    if ((left < n) and (arr[left] < arr[idx])) largest = left;

    // Если индекс правого потомка не превышает индекс максимального элемента
    // и значение в правом узле меньше, чем значение в корневом узле, то присваиваем largest индекс правого узла
    if ((right < n) and (arr[right] < arr[largest])) largest = right;

    // Если индекс минимального элемента не совпадает с индексом корневого производим замену позиций idx & largest
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);        // Замена позиций
        _heapify_min(arr, largest, n);             // Рекурсивный проход по поддереву потомка
    }
}


void build_max_heap(double* arr, int N)
{
    /*
     *
     * Алгоритм построения max кучи из массива.
     * Принимает на вход:
     *      double* arr - Указатель на область памяти изменяемого массива.
     *      int N       - Длинна массива
     *
     */


    for(int i = N / 2 - 1; i >= 0; i--)
    {
        _heapify_max(arr, i, N);   // Переупорядочивание поддерева
    }
}


void _heapify_max(double* arr, int idx, int n)
{
    /*
     *
     * Функция переупорядочивающая поддерево с корнем в узле idx и максимальным номером
     * элемента не больше n
     * Принимает на вход:
     *      double* arr   - Указатель на область памяти изменяемого массива.
     *      int idx       - Индекс корневого узла поддерева
     *      int n         - Максимальный элемент поддерева
     *
     */


    int largest = idx;        // Индекс наибольшего элемента
    int left = 2 * idx + 1;   // Индекс левого потомка
    int right = 2 * idx + 2;  // Индекс правого потомка

    // Если индекс левого потомка не превышает индекс максимального элемента
    // и значение в левом узле больше, чем значение в корневом узле, то присваиваем largest индекс левого узла
    if ((left < n) and (arr[left] > arr[idx])) largest = left;

    // Если индекс правого потомка не превышает индекс максимального элемента
    // и значение в правом узле больше, чем значение в корневом узле, то присваиваем largest индекс правого узла
    if ((right < n) and (arr[right] > arr[largest])) largest = right;

    // Если индекс максимального элемента не совпадает с индексом корневого производим замену позиций idx & largest
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);    // Замена позиций
        _heapify_max(arr, largest, n);             // Рекурсивный проход по поддереву потомка
    }
}


void init_array(double* ptr, int N)
{
    /*
     * Функция инициализирующая массив.
     *
     * Принимает на вход:
     *      double* ptr - указатель на первый элемент массива.
     */

    // Массив который мы копируем по адресам переданным указателем.
    double new_arr[10] = {1., 42., -20., -5.2, -6.43, 2.3, 2.5, 0.0, 0.24, -0.54};
    // Цикл по массиву для инициализации данных.
    for(int i = 0; i < N; i++)
    {
        ptr[i] = new_arr[i];
    }
}


void show(double* arr, int N)
{
    /*
     * Функция вывода массива в консоль.
     * Принимает на вход:
     *      double* arr - Указатель на область памяти массива.
     */

    cout << "Array: [";

    for(int i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[N - 1] << "]\n";
}