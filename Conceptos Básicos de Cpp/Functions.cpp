#include <iostream>

using namespace std;

void sayHi(string name, int age);

double cube(double num);

int main()
{
    double number;

    sayHi("Alan", 20);
    sayHi("Tom", 29);
    sayHi("Ana", 15);


    cout << "Give me a number to cube it:" << endl;
    cin >> number;
    cout << "The cubed number is:" << endl;
    cout << cube(number);

    return 0;

}

void sayHi(string name, int age){
    cout << "Hello " << name << "!" << " You are " << age << " Years old!" << endl;
}

double cube(double num){
    double result = num * num * num;
    return result;
}
