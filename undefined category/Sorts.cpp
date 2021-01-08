#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void print_array(int mas[], int N) {
	for (int i = 0; i < N; i++) {
		cout << mas[i] << '\t';
	}
	cout << '\n';
}

void sorting_by_inserts(int mas[], int N) {
	for (int i = 1; i < N; i++) {
		while (mas[i]<mas[i-1] and i!=0) {
			int tmp = mas[i - 1];
			mas[i - 1] = mas[i];
			mas[i] = tmp;
			i--;
		}
	}
}

void sorting_by_count(int mas[], int N, int max) {
	int* count = new int[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		count[mas[i]]++;
	}
	
	int counter = 0;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			mas[counter++] = i;
		}
	}
	
	cout << "Статистика: ";
	print_array(count, max);
	cout << endl;
	
	delete[] count;
}

int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251>nul");
	
	const int max=10;
	const int size_file=100000;
	char BD[size_file];
	
	ifstream date;
	date.open("date.txt");
	date.getline(BD, size_file);
	date.close();
	
	int array_of_date[size_file-1];
	for (int i=0; i<size_file-1; i++) {
		array_of_date[i] = int(BD[i])-48;
	}
	
	sorting_by_inserts(array_of_date, size_file-1);
	print_array(array_of_date, size_file-1);
	cout << "end";
    system("pause>nul");
	return 0;
}

