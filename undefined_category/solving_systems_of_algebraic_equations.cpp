#include <iostream>
#include <vector>

double rounding_to_2_decimal_places(double number) {
	if (number >= 0) {
		return double(int((number + 0.005) * 100)) / 100.;
	}
	else {
		return double(int((number - 0.005) * 100)) / 100.;
	}
}

void print_vector(std::vector<double> vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout.width(4);
		std::cout << rounding_to_2_decimal_places(vector[i]) << " ";
	}
	std::cout << '\n';
}

void print_2d_vector(std::vector<std::vector<double>> vector) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		for (unsigned int j = 0; j < vector.size(); j++) {
			std::cout.width(4);
			std::cout << rounding_to_2_decimal_places(vector[i][j]) << " ";
		}
		std::cout << '\n';
	}
}

void print_2d_vector_and_free_members(std::vector<std::vector<double>> vector, std::vector<double> free_members) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		for (unsigned int j = 0; j < vector.size(); j++) {
			std::cout.width(6);
			std::cout << rounding_to_2_decimal_places(vector[i][j]) << " ";
		}
		std::cout.width(4);
		std::cout << "| " << rounding_to_2_decimal_places(free_members[i]) <<  '\n';
	}
}

void enter_coefficients(std::vector<std::vector<double>>& vector) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		for (unsigned int j = 0; j < vector.size(); j++) {
			std::cin >> vector[i][j];
		}
	}
}

double determinant_of_a_matrix(std::vector<std::vector<double>> matrix, int matrix_size) {
	if (matrix_size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		double determinant = 0;

		for (int i = 0; i < matrix_size; i++) {
			std::vector<std::vector<double>> tmp_matrix(matrix_size - 1, std::vector<double>(matrix_size - 1));

			for (int matrix_j = 1, tmp_matrix_j = 0; matrix_j < matrix_size; matrix_j++, tmp_matrix_j++) {
				for (int matrix_k = i+1, tmp_matrix_k = 0; matrix_k < matrix_size + i; matrix_k++, tmp_matrix_k++) {
					tmp_matrix[tmp_matrix_j][(tmp_matrix_k+i)%(matrix_size-1)] = matrix[matrix_j % (matrix_size)][matrix_k % (matrix_size)];
				}
			}

			int sign;
			if (i % 2 == 0) { sign = 1; }
			else { sign = -1; }
			determinant += + matrix[0][i] * determinant_of_a_matrix(tmp_matrix, matrix_size - 1) * sign;
		}
		return determinant;
	}
}

std::vector<std::vector<double>> matrix_of_minors(std::vector<std::vector<double>> matrix, int matrix_size) {
	std::vector<std::vector<double>> minors(matrix.size(), std::vector<double>(matrix.size()));

	if (matrix.size() == 2) {
		minors[0][0] = matrix[1][1];
		minors[0][1] = matrix[1][0];
		minors[1][0] = matrix[0][1];
		minors[1][1] = matrix[0][0];
		return minors;
	}
	else {
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				std::vector<std::vector<double>> tmp_matrix(matrix_size - 1, std::vector<double>(matrix_size - 1));

				for (int matrix_i = i + 1, tmp_matrix_i = 0; matrix_i < matrix_size + i; matrix_i++, tmp_matrix_i++) {
					for (int matrix_j = j + 1, tmp_matrix_j = 0; matrix_j < matrix_size + j; matrix_j++, tmp_matrix_j++) {
						tmp_matrix[(tmp_matrix_i + j) % (matrix_size - 1)][(tmp_matrix_j + i) % (matrix_size - 1)] = matrix[matrix_i % (matrix_size)][matrix_j % (matrix_size)];
					}
				}

				minors[i][j] = determinant_of_a_matrix(tmp_matrix, matrix_size-1);
			}
		}
		return minors;
	}
}

void algebraic_complements(std::vector<std::vector<double>>& matrix, int matrix_size) {
	int swth;
	for (int i = 0; i < matrix_size; i++) {
		if (i % 2 == 0) { swth = 0; }
		else { swth = 1; }
		for (int j = 0; j < matrix_size; j++) {
			if ((j + swth) % 2 == 1) { matrix[i][j] *= -1; }
		}
	}
}

void transposed_matrix(std::vector<std::vector<double>>& matrix, int matrix_size) {
	std::vector<std::vector<double>> tmp_matrix(matrix_size, std::vector<double>(matrix_size));

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			tmp_matrix[i][j] = matrix[j][i];
		}
	}

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			matrix[i][j] = tmp_matrix[i][j];
		}
	}
}

std::vector<double> multiplication_matrix(std::vector<std::vector<double>> tr_matrix_alg_comp, std::vector<double> free_members, int determinant, int matrix_size) {
	std::vector<double> tmp_matrix(matrix_size);

	for (int i = 0; i < matrix_size; i++) {
		double tmp_number = 0;
		for (int j = 0; j < matrix_size; j++) {
			tmp_number += tr_matrix_alg_comp[i][j] * free_members[j];
		}
		tmp_matrix[i] = tmp_number/determinant;
	}

	return tmp_matrix;
}

int main() {
	int matrix_size = 0;
	std::cout << "Enter the number of unknowns: ";
	std::cin >> matrix_size;

	std::vector<std::vector<double>> coefficients_matrix(matrix_size, std::vector<double>(matrix_size));
	std::cout << "Enter the matrix of coefficients for unknowns: ";
	enter_coefficients(coefficients_matrix);

	std::vector<double> free_members(matrix_size);
	std::cout << "Enter the matrix of the free members: ";
	for (int i = 0; i < matrix_size; i++) {
		std::cin >> free_members[i];
	}
	std::cout << '\n';

	std::cout << "The resulting matrix: \n";
	print_2d_vector_and_free_members(coefficients_matrix, free_members);
	std::cout << '\n';

	std::cout << "Solution of the system of equations: \n";

	double determinant = determinant_of_a_matrix(coefficients_matrix, matrix_size);
	std::cout << "Determinant: " <<  determinant << '\n';
	if (!determinant) {
		std::cout << "The system has infinitely many solutions or is incompatible\n";
		return 0;
	}

	std::cout << "\nMatrix of minors: \n";
	std::vector<std::vector<double>> transon_matrix_of_algebraic_complements = matrix_of_minors(coefficients_matrix, matrix_size);
	print_2d_vector(transon_matrix_of_algebraic_complements);

	std::cout << "\nAlgebraic complements: \n";
	algebraic_complements(transon_matrix_of_algebraic_complements, matrix_size);
	print_2d_vector(transon_matrix_of_algebraic_complements);
	
	std::cout << "\nTranspose matrix: \n";
	transposed_matrix(transon_matrix_of_algebraic_complements, matrix_size);
	print_2d_vector(transon_matrix_of_algebraic_complements);

	std::vector<double> answers(matrix_size);
	answers = multiplication_matrix(transon_matrix_of_algebraic_complements, free_members, determinant, matrix_size);
	std::cout << "\nUnknown members: ";
	print_vector(answers);

	system("pause>nul");
	return 0;
}