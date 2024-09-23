#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
	const char* name;
	int age;

public:
	Student() {
		this->name = "Unknown";
		this->age = 0;
	};
	Student(const char* n, int a) {
		this->name = n;
		this->age = a;
	};
	string getName() {
		return this->name;
	};
	int getAge() {
		return this->age;
	};
    void setName(const char* name) {
        this->name = name;
    }

};



int square(const int& x) {
    return x * x;
}


void set(Student& s) {};
void set(Student&& s) {};

class A {
    int xyz;
public:
    A() { std::cout << "Class-A Default constructor" << std::endl; xyz = 1; };
    A(int num) : xyz(num) {};
    A(const A& src) {
        xyz = src.xyz;
        cout << "Copy constructor A L-VALUE" << endl;
    }
    A(const A&& src) noexcept{
        xyz = src.xyz;
        cout << "MOVE constructor A r-VALUE" << endl;
    }
    A& operator=(const A& src) {
        cout << "operator A L-VALUE" << endl;
        return *this;
    }
    A& operator=(const A&& src)noexcept {
        cout << " operator A R-VALUE" << endl;
        return *this;
    }

};

class X {
    int ddd;
public:
    X(int num) : ddd(num) {};
    X() {
        ddd = 0;
        cout << "X Default constructor" << endl;
    }
    X(const X& src) {
        ddd = 0;
        cout << "Copy constructor X L-VALUE" << endl;
    }
    X(const X&& src) noexcept{
        ddd = 0;
        cout << "MOVE constructor X R-VALUE" << endl;
    }
    X& operator=(const X& src) {
        cout << "operator X L-VALUE" << endl;
    }
    X& operator=(const X&& src) noexcept {
        cout << "OPERATOR X R-VALUE" << endl;
        return *this;
    }
    A bb;
};

A b;
A s;
 
A foo() { return b; };

A& bar() { return s; };


void print(int &a) {
    cout <<"L VALUE" <<  a;
}
void print(int&& a) {
    cout << a;
}

int main(void) {
   
    int x = 2;
    print(x);
    print(x + 2);
 





/*

    const int size = 15;
    int arr[size] = { 12,19,7,2,1,99,2,21,33,91,23,1,12,17 };
    int comp[3] = { 0,0,0 };
    int first = 0, second = 0, third = 0;
    int sum = 0;






   

    int a = 4;
    int& b = a;
    b = 13;
    int* p = &a;

    cout << *p << endl;
    cout << a << endl;
    cout << b << endl;
    cout <<  p << endl;
    cout << &a << endl;
    cout << &b << endl;


    
    for (int i = 0; i < size; i++)
    {
        if (i == 0) {
            first = arr[i];
            second = arr[i + 1];
            third = arr[i + 2];
            cout << first << " - " << second << " - " << third << endl;
        }
        else {
            cout << "ARR: " << arr[i] << endl;
            if (arr[i] > first) {
                first = arr[i];
            }
            else if (arr[i] > second && second  < third) {
                second = arr[i];
            }
            else if (arr[i] > third) {
                third = arr[i];
            }
            cout << first << " - " << second << " - " << third << endl;

        }

    }


    
    for (int i = 0; i < size; i++)
    {
        if (i == 0) {
            comp[0] = arr[i];
            comp[1] = arr[i + 1];
            comp[2] = arr[i + 2];
            cout << comp[0] << " - " << comp[1] << " - " << comp[2] << endl;
        }
        else {
            cout << "ARR: " << arr[i] << endl;
            if (arr[i] > comp[0]) {
                comp[0] = arr[i];
            }
            else if (arr[i] > comp[1]) {
                comp[1] = arr[i];
            }
            else if (arr[i] > comp[2]) {
                comp[2] = arr[i];
            }
            cout << comp[0] << " - " << comp[1] << " - " << comp[2] << endl;

        } 
        
    }
    

    for (int i = 0; i < 3; i++)
    {
        cout << "Highest numbers are: " << endl;
        cout << "#" << i+1 << "-     " << comp[i] << endl;
    }
    */

    /*
    cout << "Type " << size << " numbers" << endl;
    
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Type " << size << " more numbers" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> comp[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (comp[i] > comp[j]) {
                int temp = comp[j];
                comp[j] = comp[i];
                comp[i] = temp;
            }
        }
    }


    cout << "First Numbers typed: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "#" << i+1 << "----" << arr[i] << endl;
        sum += arr[i];
    }
    cout << "The sum is: " << sum << endl;
    sum = 0;
    
    cout << "Second group numbers typed:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "#" << i + 1 << "----" << comp[i] << endl;
        sum += comp[i];
    }

    cout << "The sum is: " << sum << endl;

    
    
    
    
    fstream test("file.txt");
	string line;

    while (std::getline(test, line)) {
        // Create a stringstream object from the line
        std::stringstream ss(line);

        // Define variables to hold parsed data
        char orderType;
        std::string name;
        std::string desc;
        double price;
        char special;

        // Parse the line using commas as delimiters
        ss >> orderType; // Read the single character for orderType
        ss.ignore(); // Skip the comma

        std::getline(ss, name, ','); // Read the name until a comma
        std::getline(ss, desc, ','); // Read the description until a comma

        ss >> price; // Read the price
        ss.ignore(); // Skip the comma

        ss >> special; // Read the special character

        // Output the parsed data
        std::cout << "Order Type: " << orderType << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Description: " << desc << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Special: " << special << std::endl;
    }

    */
	
	return 0;
}