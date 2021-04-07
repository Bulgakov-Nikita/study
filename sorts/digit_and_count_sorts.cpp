#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

const int SIZE = 8;
const int SIZE1 = 20;
const int DIGITS = 3;

void print_array(int* array, int aSize);

inline int get_digit (int n, int d) {
    return (n % static_cast < int >(std::pow (10, d))) / std::pow (10, d - 1);
}

void digit_sort (int *array, int size, int digits) {
    for (int digit = 1; digit <= digits; digit++) {
        for (int i = 1; i < size; i++) {
            int j = i;
            while (j > 0 and get_digit(array[j - 1], digit) > get_digit(array[j], digit)) {
                std::swap (array[j], array[j - 1]);
                j--;
            }
        }
    }
}

void
counting_sort (int *array, int size) {
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    int count_array[max - min + 1] = {0};

    for (int i = 0; i < size; i++) {
        count_array[array[i] - min]++;
    }

    int j = 0;
    for (int i = 0; i < max - min + 1; i++) {
        for (int k = 0; k < count_array[i]; k++) {
            array[j++] = i + min;
        }
    }
}

void print_array (int *array, int aSize) {
    for (int i = 0; i < aSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main () {
    int array1[SIZE] = { 432, 123, 532, 102, 103, 321, 555, 999 };
    std::cout << "Array: ";
    print_array (array1, SIZE);

    digit_sort (array1, SIZE, DIGITS);
    std::cout << "Digit sort: ";
    print_array (array1, SIZE);


    int* a = new int[SIZE1];
    for (int i = 0; i < SIZE1; i++) {
        a[i] = 1 + rand()%10;
    }
    std::cout << "Rand array: ";
    print_array (a, SIZE1);

    counting_sort (a, SIZE1);
    std::cout << "Counting sort: ";
    print_array (a, SIZE1);

    return 0;
}
