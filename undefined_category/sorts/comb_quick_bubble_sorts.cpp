#include <iostream>

const int SIZE = 8;

void bubble_sort(int* array) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j < SIZE; j++) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

int partition(int* array, int left, int right) {
    int p = array[right];
    int j = left-1;

    for (int i = left; i <= right-1; i++) {
        if (array[i] <= p) {
            j++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[j+1], array[right]);

    return j+1;
}

void quick_sort(int* array, int left, int right) {
    if (left < right) {
        int p = partition(array, left, right);

        quick_sort(array, left, p-1);
        quick_sort(array, p+1, right);
    }
}

void comb_sort(int* array) {
    double factor = 1.247;
    int step = SIZE-1;

    while (step >= 1) {
        for (int i = 0; i + step < SIZE; i++) {
            if (array[i] > array[i + step]) {
                std::swap(array[i], array[i + step]);
            }
        }
        step /= factor;
    }
}

void print_array(int* array) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int array[SIZE] = {2, -2, 34, 3, 2, 45, 1, 6};
    std::cout << "Array: ";
    print_array(array);

    std::cout << "Bubble sort: ";
    bubble_sort(array);
    print_array(array);

    int array2[SIZE] = {2, -2, 34, 3, 2, 45, 1, 6};
    std::cout << "Quick sort: ";
    quick_sort(array2, 0, SIZE-1);
    print_array(array2);

    int array3[SIZE] = {2, -2, 34, 3, 2, 45, 1, 6};
    std::cout << "Comb sort: ";
    comb_sort(array3);
    print_array(array3);

    return 0;
}
