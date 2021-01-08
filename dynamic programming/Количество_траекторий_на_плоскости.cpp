#include <iostream>
#include <iomanip>

void print_2d_array(int **options, int high, int width) {
	std::cout << std::setw(3) << "N";
	for (int i = 1; i < width; i++) {
		std::cout << std::setw(6) << i << ")";
	}
	std::cout << '\n';
	
	for (int i = 1; i < high; i++) {
		std::cout << std::setw(3) << i << ") ";
		for (int j = 1; j < width; j++) {
			std::cout << std::setw(6) << options[i][j] << " ";
		}
		std::cout << std::setw(6) << '\n';
	}
}

void numbers_of_patchs(int high, int width) {
	int **options = new int *[high+1];
	options[0] = new int[(high+1)*(width+1)];
	for (int i = 1; i <= high; i++) {
		options[i] = options[0] + i*width;
	}
	
	for (int i = 1; i <= high; i++) {
		options[i][1] = 1;
	}
	for (int j = 1; j <= width; j++) {
		options[1][j] = 1;
	}
	
	for (int i = 2; i <= high; i++) {
		for (int j = 2; j <= width; j++) {
			options[i][j] = options[i-1][j] + options[i][j-1];
		}
	}
	
	print_2d_array(options, high+1, width+1);
	std::cout << '\n' << "Value in the desired cell: " << options[high][width];
}

int main() {
	int M, N;
	std::cout << "Enter the number high and width: ";
	std::cin >> N >> M;
	std::cout << '\n';
	
	numbers_of_patchs(N, M);
	
	system("pause>nul");
	return 0;
}
