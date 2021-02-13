cmake_minimum_required(VERSION 3.17)
project(TestProject)

set(CMAKE_CXX_STANDARD 17)

#  Files:

#
#  main.cpp                                      - Основной файл для теста
#  Algorithms/Sorting/bubble_sort.cpp            - Алгоритм сортировки пузырьком
#  Algorithms/Sorting/insertion_sort.cpp         - Сортировка вставками
#  Algorithms/Sorting/selection_sort.cpp         - Сортировка выбором
#  Algorithms/Sorting/heap_sort.cpp              - Сортировка кучей (Пирамидальная сортировка)
#  Algorithms/Sorting/quick_sort.cpp             - Быстрая сортировка (Разделяй и влавствуй)
#

add_executable(TestProject main.cpp)