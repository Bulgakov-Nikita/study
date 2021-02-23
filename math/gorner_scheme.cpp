#include <iostream>
#include <vector>
#include <set>

void horner_scheme(std::vector<double>& answers, std::vector<double> coefficients);

std::vector<double> find_root(const std::vector<double>& coefficients, double& root);

void many_roots(std::set<double>& roots, const std::vector<int>& m, const std::vector<int>& l);

void divisors(std::vector<int>& div, int number);

void enter_coefficients(std::vector<double>& vector);

void print_vector(const std::vector<double>& vector);

inline int int_abs(int number);

int main() {
    int number_of_coefficients = 0;
    std::cout << "Enter the number of coefficients of the equation: ";
    std::cin >> number_of_coefficients;

    std::vector<double> coefficients(number_of_coefficients);
    std::cout << "Enter equation coefficients: ";
    enter_coefficients(coefficients);


    std::cout << "Rational roots: ";
    std::vector<double> answers;
    horner_scheme(answers, coefficients);
    print_vector(answers);

    system("pause>nul");
    return 0;
}

void horner_scheme(std::vector<double>& answers, std::vector<double> coefficients) {
    int coefficients_size = coefficients.size();
    for (unsigned int i = 0; i < coefficients_size-1; i++) {
        double root;
        coefficients = find_root(coefficients, root);
        if (root == 0) {
            break;
        }
        answers.push_back(root);
    }
}

std::vector<double> find_root(const std::vector<double>& coefficients, double& root) {
    std::vector<double> tmp_coefficients;
    std::set<double> roots;
    std::vector<int> m, l;
    int coefficients_size = coefficients.size();

    divisors(m, static_cast<int>(coefficients[0]));
    divisors(l, static_cast<int>(coefficients[coefficients_size - 1]));
    many_roots(roots, m, l);

    for (auto maybe_root : roots) {
        tmp_coefficients.push_back(coefficients[0]);
        for (unsigned int i = 1; i < coefficients_size; i++) {
            tmp_coefficients.push_back(coefficients[i] + tmp_coefficients[i-1] * maybe_root);
        }

        if (tmp_coefficients[coefficients_size - 1] == 0) {
            root = maybe_root;
            tmp_coefficients.pop_back();
            return tmp_coefficients;
        }
        tmp_coefficients.clear();
    }

    root = 0;
    return tmp_coefficients;
}

void many_roots(std::set<double>& roots, const std::vector<int>& m, const std::vector<int>& l) {
    for (int i : l) {
        for (int j : m) {
            roots.insert(static_cast<double>(i) / static_cast<double>(j));
            roots.insert(static_cast<double>(-i) / static_cast<double>(j));
        }
    }
}

void divisors(std::vector<int> &div, int number) {
    number = int_abs(number);

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            div.push_back(i);
        }
    }
}

int int_abs(int number) {
    return (number < 0) ? -number : number;
}

void print_vector(const std::vector<double>& vector) {
    for (auto i : vector) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void enter_coefficients(std::vector<double> &vector) {
    for (double & i : vector) {
        std::cin >> i;
    }
}
