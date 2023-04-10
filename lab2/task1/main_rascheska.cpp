



// README: файл для измерения асимптотики сортировки расческой
// в целом коды в исполняемых файлах типа main_*** работают аналогично, поэтому 
// Не требуют комментирования



// библиотека для чтения файла
#include <fstream>
// библиотека для работы с консолью (терминалом)
#include <iostream>
// добавляем написанные нами алгоритмы сортировки
#include "sort_func.h"
#include <cstdlib>
#include <chrono>
#include <limits>

// for common behaviour of files
#include "settings.h"

int main()
{
    // задаем начальные условия генератора случайных чисел
    // сохраняем системное время
    int seed = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    srand(seed);
    
    // объект файлового потока для записи
    std::ofstream data;

    // открываем файл
    // если файла не существует, то создается автоматически
    // если файл существует, то он перезаписывается
    data.open("data_rascheska.csv");


    // если что-то случилось, закрываем файл и завершаем программу с ошибкой
    if (!data.is_open())
    {
        data.close();
        return -1;
    }

    // вводим заголовок
    data << "size" << " " << "time" << " " << "perm" << std::endl;

    // в консоль выводим промежуточные результаты сортировки
    std::cout << "rascheska sort: " << std::endl;

    // в цикле проходим по размерам массива от 1 до max_size (определяется в settings.h)
    for (int size = 1; size < max_size; size++)
    {
        // в эту переменную записывается число перестановок, которое произойдет при сортировке
        long permutations = 0;

        // штуки с chrono списаны с методички для лабы 1. Можно не особо вдаваться в подробности.
        // сохраняем начало работы теста
        auto begin = std::chrono::steady_clock::now();
        // для усреднения результатов создаем и сортируем массив несколько (много) раз
        for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        {
            // выделяем память из кучи под массив
            unsigned int* array = new unsigned int[size];

            // записываем в него рандомные данные, лежащие в промежутке [min, max] (определены в settings.h)
            for (int i = 0; i < size; i++)
            {
                array[i] = rand() % (max + min + 1) + min;
            }

            // записывает в общее число перестановок
            permutations += rascheska_sort(array, size);
            // освобождаем память
            delete[] array;
            // на всякий случай обнуляем
            array = nullptr;
        }
        // сохраняем конец работы теста
        auto end = std::chrono::steady_clock::now();
        // сохраняем промежуток времени
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        // записываем результаты измерений в файл
        data << size << " " << time_span.count() << " " << permutations << std::endl;

        // для контроля выводим в консоль каждое десятое измерение
        if (size % 10 == 0)
        {
            std::cout << size << " " << time_span.count() << " " << permutations << std::endl;
        }
    }

    // закрываем файл
    data.close();
    
    return 0;
}