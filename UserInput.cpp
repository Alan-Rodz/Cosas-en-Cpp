#include <iostream>

using namespace std;

int main()
{
    /*
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;

    cout << "You are " << age << " Years old." << endl;
    */

    string name;
    cout << "Enter your name: " << endl;
    getline(cin, name);
    cout << "Hello, " << name << endl;

    return 0;
}
