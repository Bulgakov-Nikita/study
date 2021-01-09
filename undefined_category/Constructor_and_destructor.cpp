#include <iostream>

class MyClass {
	private: // члены классы
	   int number_one;
	   int number_two;		
	   int sum() {
        return number_one + number_two;
	   }
	   
	public:   
	MyClass() { // конструктор по-умолчанию
	    number_one = 0;
		number_two = 0;	
		std::cout << "Создан пустой объект, сумма равна: " << sum() << "\n\n";
	}
	
	MyClass(int first, int second) { // конструктор с двумя аргументами
	    number_one = first;
	    number_two = second;
		std::cout << "Создан объект с числами: " << first << ", " << second
		          << "\nИх сумма равна: " << sum() << "\n\n"; 
	}
	
    ~MyClass() { // деструктор
		std::cout << "Удаление объекта с суммой чисел: ";
		showSum(); 
	    std::cout << "\n\n"; 
	}
	// метод класса
	void showSum() {
		std::cout << sum(); 
	}
};

	void one_and_two() { // функция
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
	 * в самом конце программы вызывется деструктор у объекта B,
	 * но из-за того, что консоль быстро закрывается, нельзя увидеть
	 * что он выводит
	*/ 
    return 0;
}
