#include <iostream>
#include <vector>
#include <set>

void enter_coefficients(std::vector<double>& vector) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		std::cin >> vector[i];
	}
}

void print_vector(std::vector<double> vector) {
	std::vector<double>::const_iterator it;
	it = vector.begin();
	while (it != vector.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << '\n';
}

void print_set(std::set<double> set) {
	std::set<double>::const_iterator it;
	it = set.begin();
	while (it != set.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << '\n';
}

void print_equation(std::vector<double> vector) {
	unsigned int size = vector.size();
	std::cout << vector[0] << "x^" << size - 1;
	for (unsigned int i = 1; i < size -1; i++) {
		if (vector[i] < 0) {
			std::cout << vector[i] << "x^" << size - i - 1;
		}
		else if (vector[i] > 0) {
			std::cout << "+" << vector[i] << "x^" << size - i - 1;
		}
	}
	if (vector[size - 1] < 0) {
		std::cout << vector[size - 1] << "=0";
	}
	else {
		std::cout << "+" << vector[size - 1] << "=0";
	}
	std::cout << std::endl;
}

int int_abs(int number) {
	if (number < 0) {
		return -number;
	}
	else {
		return number;
	}
}

std::vector<int> divisors(int number) {
	std::vector<int> div;
	number = int_abs(number);

	for (int i = 1; i <= number; i++) {
		if (number % i == 0) {
			div.push_back(i);
		}
	}
	return div;
}

std::set<double> many_roots(std::vector<int> m, std::vector<int> l) {
	std::set<double> roots;
	for (unsigned int i = 0; i < l.size(); i++) {
		for (unsigned int j = 0; j < m.size(); j++) {
			roots.insert(static_cast<double>(l[i]) / static_cast<double>(m[j]));
			roots.insert(static_cast<double>(-l[i]) / static_cast<double>(m[j]));
		}
	}
	return roots;
}

std::vector<double> find_root(std::vector<double> coefficients) {
	std::vector<double> tmp_coefficients;
	// TODO если один из коэффициентов дробь - завершить поиск корней
	std::set<double> roots = many_roots(divisors(static_cast<int>(coefficients[0])), divisors(static_cast<int>(coefficients[coefficients.size()-1])));

	std::set<double>::const_iterator it = roots.begin();
	while (it != roots.end()) {
		tmp_coefficients.push_back(coefficients[0]);
		for (unsigned int i = 1; i < coefficients.size(); i++) {
			tmp_coefficients.push_back(coefficients[i]+tmp_coefficients[i-1]*(*it));
		}

		if (tmp_coefficients[tmp_coefficients.size() - 1] == 0) {
			tmp_coefficients[tmp_coefficients.size() - 1] = *it;
			return tmp_coefficients;
		}

		tmp_coefficients.clear();
		tmp_coefficients.reserve(coefficients.size());
		it++;
	}

	tmp_coefficients.push_back(0. / 1.);
	return tmp_coefficients;
}

std::vector<double> horner_scheme(std::vector<double> coefficients) {
	std::vector<double> answers;
	std::vector<double> new_coefficients = coefficients;
	bool irrational_root = false;

	for (unsigned int i = 0; i < coefficients.size()-1; i++) {
		new_coefficients = find_root(new_coefficients);
		if (new_coefficients[new_coefficients.size()-1] == 0. / 1.) {
			irrational_root = true;
			break;
		}
		answers.push_back(new_coefficients[new_coefficients.size()-1]);
		new_coefficients.pop_back();
	}

	if (irrational_root) {
		answers.push_back(0. / 1.);
	}
	return answers;
}

int main() {
	int number_of_coeff = 0;
	std::cout << "Enter the number of coefficints of the equation: ";
	std::cin >> number_of_coeff;

	std::vector<double> coefficients(number_of_coeff);
	std::cout << "Enter equation coefficients: ";
	enter_coefficients(coefficients);

	std::cout << "Your equation: ";
	print_equation(coefficients);

	std::cout << "Rational roots: ";
	std::vector<double> answers = horner_scheme(coefficients);
	print_vector(answers);

	system("pause>nul");
	return 0;
}