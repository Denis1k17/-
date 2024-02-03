#include <iostream>
#include <cstdlib> 
#include <ctime>   

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1; 
    }
}

void printArray(const int* arr, int size) {
    std::cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void findAndPrintPairs(const int* arr, int size, int difference) {
    bool found = false;
    for (int i = 0; i < size - 1; ++i) { 
        for (int j = i + 1; j < size; ++j) { 
            if (abs(arr[i] - arr[j]) == difference || abs(arr[j] - arr[i]) == difference ) {
                std::cout << "Пара элементов с индексами [" << i << "] и ["<< j
                          << "] имеют разность равную заданной: "
                          << arr[i] << " и " << arr[j] << "\n";
                found = true;
            }
        }
    }

    if (!found)
        std::cout << "Не найдено ни одной пары с разностью равной "
                  << difference <<" .\n";
}

int main() {
     srand(static_cast<unsigned>(time(0))); 

     const int SIZE = 10;
     int* myArray = new int[SIZE]; 

     fillArray(myArray, SIZE);
     printArray(myArray, SIZE);

     std::cout <<"Введите число для поиска пар с его разностью: ";
     int diff;
     std::cin >> diff;

     findAndPrintPairs(myArray, SIZE, diff);

     delete[] myArray; 

   return 0;
}
