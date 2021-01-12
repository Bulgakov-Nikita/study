#include <iostream>

class MyClass {
	private: // ����� ������
	   int number_one;
	   int number_two;		
	   int sum() {
        return number_one + number_two;
	   }
	   
	public:   
	MyClass() { // ����������� ��-���������
	    number_one = 0;
		number_two = 0;	
		std::cout << "������ ������ ������, ����� �����: " << sum() << "\n\n";
	}
	
	MyClass(int first, int second) { // ����������� � ����� �����������
	    number_one = first;
	    number_two = second;
		std::cout << "������ ������ � �������: " << first << ", " << second
		          << "\n�� ����� �����: " << sum() << "\n\n"; 
	}
	
    ~MyClass() { // ����������
		std::cout << "�������� ������� � ������ �����: ";
		showSum(); 
	    std::cout << "\n\n"; 
	}
	// ����� ������
	void showSum() {
		std::cout << sum(); 
	}
};

	void one_and_two() { // �������
		MyClass C(1, 2);
	}

int main() {
    system("chcp 1251>nul"); 
	
	MyClass A;
	MyClass B(5, 10);
	one_and_two();
	MyClass *C = new MyClass();
	
	delete C; 
	system("pause>nul");
	/*
	 * � ����� ����� ��������� ��������� ���������� � ������� B,
	 * �� ��-�� ����, ��� ������� ������ �����������, ������ �������
	 * ��� �� �������
	*/ 
    return 0;
}
