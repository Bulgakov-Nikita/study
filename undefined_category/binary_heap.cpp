#include <iostream>
#include <vector>

class Heap {
public:
    static void make_heap(std::vector<int>& vector) {
        for (int i = 1; i < vector.size(); i++) {
            repair(vector, i);
        }
    }

    static void insert(std::vector<int>& vector, int number) {
        vector.push_back(number);
        repair(vector, vector.size() - 1);
    }

    static void erase(std::vector<int>& vector, int index) {
        std::swap(vector[index], vector[vector.size() - 1]);
        vector.pop_back();
        repair_erase(vector, index);
    }

    static void show(std::vector<int>& vector) {
        for (auto & i : vector) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

private:
    static void repair(std::vector<int>& vector, int index) {
        int parent = (index - 1) / 2;
        if (vector[parent] < vector[index] and index > 0) {
            std::swap(vector[parent], vector[index]);
            repair(vector, parent);
        }
    }

    static void repair_erase(std::vector<int>& vector, int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < vector.size() and right < vector.size()) {
            if (vector[left] > vector[right]) {
                std::swap(vector[left], vector[index]);
                repair_erase(vector, left);
            } else {
                std::swap(vector[right], vector[index]);
                repair_erase(vector, right);
            }
        }
    }
};

int main() {
    std::vector<int> vec = {3, 1, 9, 45, 31, 12, 234, 2, 5, 7, 9};
    Heap::make_heap(vec);
    Heap::insert(vec, 999);
    Heap::show(vec);
    Heap::erase(vec, 2);
    Heap::show(vec);

    return 0;
}
