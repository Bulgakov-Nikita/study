#include <fstream>

/*
 * В функции insert_data используется сортировка вставками с асимптотикой О(n^2)
 * length_of_painted_parts работает за О(n)
 * поэтому О(n^2 + n), значит итоговое время О(n^2)
 */

void insert_data(int array[][2], int size, std::ifstream& input) {
    // Массив заполняется данными и сортируется с помощью сортировки вставками
    input >> array[0][0] >> array[0][1];
    for (int i = 1; i < size; i++) {
        input >> array[i][0] >> array[i][1];
        int j = i;
        while (array[j][0] < array[j-1][0] and j != 0) {
            std::swap(array[j][0], array[j-1][0]);
            std::swap(array[j][1], array[j-1][1]);
            j--;
        }
    }
}

int length_of_painted_parts(int segments[][2], int size) {
    // Находится длина закрашенной области
    int length = 0;
    int left = segments[0][0];
    int right = segments[0][1];

    for (int i = 0; i < size; i++) {
        length += right-left;
        if (segments[i][0] <= right) {
            left = right;
            right = segments[i][1];
        } else {
            left = segments[i][0];
            right = segments[i][1];
        }
    }
    length += right-left;

    return length;
}

int main() {
    std::ifstream input("input.txt");
    int n;
    input >> n;

    int segments[n][2];
    insert_data(segments, n, input);

    std::ofstream output("output.txt");
    output << length_of_painted_parts(segments, n);

    return 0;
}