#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>


int binary_search(std::vector<int>& array, int number) {
    // бинарный поиск
    int size = array.size();
    int l = 0;
    int r = size;
    int middle;

    while (true) {
        middle = (l + r) / 2;

        if (number < array[middle]) {
            r = middle - 1;
        } else if (number > array[middle]){
            l = middle + 1;
        } else {
            return middle;
        }

        if (r <= l) {
            return -1;
        }
    }
}

int main() {
    std::srand(std::time(nullptr));

    // заполнение вектора и его сортировка
    std::vector<int> array;
    for (int i = 0; i < 50; i++) {
        array.push_back(rand() % 100);
    }
    std::sort(array.begin(), array.end());

    // вывод вектора
    std::cout << "Array: ";
    for (auto i : array) {
        std::cout << i << " ";
    }

    // ввод и вывод искомого числа
    int n;
    std::cout << "\nEnter finding element: ";
    std::cin >> n;
    int index = binary_search(array, n);
    if (index == -1) {
        std::cout << "\nNumber not found";
    } else {
        std::cout << "\nIndex finding number: " << index << "; Number: " << array[index];
    }

    return 0;
}