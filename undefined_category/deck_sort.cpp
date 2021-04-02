#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

const int DECK_SIZE = 52;

std::map<int, std::string> suits = {
        {0, "peaks"}, {1, "crosses"}, {2, "diamonds"}, {3, "worms"}
};
std::map<int, std::string> cards {
        {1, "ace"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"},
        {8, "8"}, {9, "9"}, {10, "10"}, {11, "jack"}, {12, "queen"}, {13, "king"}
};

struct card {
    int suit;
    int nominal;
};

void show_cards(card *deck) {
    // Печать колоды
    for (int i = 1; i <= DECK_SIZE; i++) {
        std::cout << i << ") " << suits[deck[i - 1].suit] << "-"
                  << cards[deck[i - 1].nominal] << "; ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------";
    std::cout << std::endl;
}

bool find(std::vector<int>& v, int n) {
    for (auto & i : v) {
        if (i == n) {
            return true;
        }
    }
    return false;
}

void bubble_sort(card deck[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (deck[i].nominal > deck[j].nominal) {
                std::swap(deck[i], deck[j]);
            }
        }
    }
}

void bubble_sort_2(card deck[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            if (deck[i].suit > deck[j].suit) {
                std::swap(deck[i], deck[j]);
            }
        }
    }
}

void sort_deck(card deck[]) {
    bubble_sort(deck, DECK_SIZE);
    for (int i = 0; i < 14; i++) {
        bubble_sort_2(deck, i * 4, i * 4 + 4);
    }
}

int main () {
    std::srand(std::time(nullptr));

    card deck[DECK_SIZE];

    std::vector<int> s;
    while (s.size() < 4) {
        int n = rand() % 4;
        if (!find(s, n)) {
            s.push_back(n);
        }
    }
    // для перемешивания колода можно было использовать swap на рандомных элементах
    int top = 0;
    for (auto & i : s) {
        std::vector<int> nom;
        while (nom.size() < 13) {
            int n = 1 + rand() % 13;
            if (!find(nom, n)) {
                nom.push_back(n);
            }
        }
        for (auto & j : nom) {
            deck[top].suit = i;
            deck[top].nominal = j;
            top++;
        }
    }

    show_cards(deck);
    sort_deck(deck);
    show_cards(deck);

    return 0;
}
