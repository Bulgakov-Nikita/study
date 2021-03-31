#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

class Calc {
private:
    int64_t number_in_10_number_system = 0;
    std::map<char, int> numbers = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
            {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 18},
            {'J', 19}, {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}, {'Q', 26}, {'R', 27},
            {'S', 28}, {'T', 29}, {'U', 30}, {'V', 31}, {'W', 32}, {'X', 33}, {'Y', 34}, {'Z', 35},
            {'a', 36}, {'b', 37}, {'c', 38}, {'d', 39}, {'e', 40}, {'f', 41}, {'g', 42}, {'h', 43}, {'i', 44},
            {'j', 45}, {'k', 46}, {'l', 47}, {'m', 48}, {'n', 49}, {'o', 50}, {'p', 51}, {'q', 52}, {'r', 53},
            {'s', 54}, {'t', 55}, {'u', 56}, {'v', 57}, {'w', 58}, {'x', 59}, {'y', 60}, {'z', 61},
            {128, 62}, {129, 63}, {130, 64}, {131, 65}, {132, 66}, {133, 67}, {134, 68}, {135, 69}, {136, 70},
            {137, 71}, {138, 72}, {139, 73}, {140, 74}, {141, 75}, {142, 76}, {143, 77}, {144, 78}, {145, 79},
            {146, 80}, {147, 81}, {148, 82}, {149, 83}, {150, 84}, {151, 85}, {152, 86}, {153, 87}, {154, 88},
            {155, 89}, {156, 90}, {157, 91}, {158, 92}, {159, 93}, {160, 94}, {161, 95}, {162, 96}, {163, 97},
            {164, 98}, {165, 99}, {166, 100}
    };
    std::map<int, char> reverse_numbers = {
            {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
            {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}, {16, 'G'}, {17, 'H'}, {18, 'I'},
            {19, 'J'}, {20, 'K'}, {21, 'L'}, {22, 'M'}, {23, 'N'}, {24, 'O'}, {25, 'P'}, {26, 'Q'}, {27, 'R'},
            {28, 'S'}, {29, 'T'}, {30, 'U'}, {31, 'V'}, {32, 'W'}, {33, 'X'}, {34, 'Y'}, {35, 'Z'},
            {36, 'a'}, {37, 'b'}, {38, 'c'}, {39, 'd'}, {40, 'e'}, {41, 'f'}, {42, 'g'}, {43, 'h'}, {44, 'i'},
            {45, 'j'}, {46, 'k'}, {47, 'l'}, {48, 'm'}, {49, 'n'}, {50, 'o'}, {51, 'p'}, {52, 'q'}, {53, 'r'},
            {54, 's'}, {55, 't'}, {56, 'u'}, {57, 'v'}, {58, 'w'}, {59, 'x'}, {60, 'y'}, {61, 'z'},
            {62, 128}, {63, 129}, {64, 130}, {65, 131}, {66, 132}, {67, 133}, {68, 134}, {69, 135}, {70, 136},
            {71, 137}, {72, 138}, {73, 139}, {74, 140}, {75, 141}, {76, 142}, {77, 143}, {78, 144}, {79, 145},
            {80, 146}, {81, 147}, {82, 148}, {83, 149}, {84, 150}, {85, 151}, {86, 152}, {87, 153}, {88, 154},
            {89, 155}, {90, 156}, {91, 157}, {92, 158}, {93, 159}, {94, 160}, {95, 161}, {96, 162}, {97, 163},
            {98, 164}, {99, 165}, {100, 166}
    };
public:
    Calc(int number_system, std::string& number) {
        // число переводчится в 10-ю СС
        int power = number.size() - 1;

        for (auto & ch : number) {
            number_in_10_number_system += numbers[ch] * std::pow(number_system, power--);
        }
    }

    std::string to_number_system(int number_system) {
        // число переводится в заданную СС из 10-й
        std::string result;
        int remainder;
        do {
            remainder = number_in_10_number_system / number_system;
            if (remainder != 0) {
                result.push_back(reverse_numbers[number_in_10_number_system % (remainder * number_system)]);
                number_in_10_number_system = remainder;
            }
        } while (number_in_10_number_system >= number_system);

        result.push_back(reverse_numbers[remainder]);
        std::reverse(result.begin(), result.end());

        return result;
    }
};


int main() {
    int a, b;
    std::string number;
    std::cout << "Enter initial and final number system: ";
    std::cin >> a >> b;
    if (a < 2 or b < 2 or a > 100 or b > 100) {
        std::cout << "There is no such number system";
        exit(0);
    }
    std::cout << "Enter your number: ";
    std::cin >> number;

    Calc obj(a, number);
    std::cout << "\nNumber " << number << " in " << b << " number system is: " << obj.to_number_system(b);

    return 0;
}