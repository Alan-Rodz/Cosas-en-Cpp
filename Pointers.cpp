#include <iostream>

using namespace std;

int main()
{
    int age = 19;
    int *pAge = &age;

    double gpa = 2.7;
    double *pGpa = &gpa;

    string name = "Alan";
    string *pName = &name;

    //Printing the value inside the Pointers
    cout << "Values of the pointers: " << endl;
    cout << pName << endl;
    cout << pGpa << endl;
    cout << pName << endl;
    cout << endl;

    //Dereferencing the pointers
    cout << *pAge << endl;
    cout << *pGpa << endl;
    cout << *pName << endl;

    return 0;
}
