cmake_minimum_required(VERSION 3.17)
project(Internal-C-Repository)

set(CMAKE_CXX_STANDARD 17)

#  Files: (insert PATH in "add_executable(Internal-C-Repository PATH)" function)

#  ::::Algorithms::::
#
#  main.cpp                                      - Основной файл для теста
#  Algorithms/Sorting/bubble_sort.cpp            - Алгоритм сортировки пузырьком
#  Algorithms/Sorting/insertion_sort.cpp         - Сортировка вставками
#  Algorithms/Sorting/selection_sort.cpp         - Сортировка выбором
#  Algorithms/Sorting/heap_sort.cpp              - Сортировка кучей (Пирамидальная сортировка)
#  Algorithms/Sorting/quick_sort.cpp             - Быстрая сортировка (Разделяй и влавствуй)
#

#  ::::Data Structures::::
#
#  DataStructures/binary_heap.cpp                - Min/Max Binary Heap
#

add_executable(Internal-C-Repository main.cpp)