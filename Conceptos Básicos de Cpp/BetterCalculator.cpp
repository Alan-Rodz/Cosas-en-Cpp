#include <iostream>

using namespace std;

int main()
{
    double num1, num2;
    char op;

    cout << "Enter first number" << endl;
    cin >> num1;

    cout << "Enter the operator" << endl;
    cin >> op;

    cout << "Enter second number" << endl;
    cin >> num2;

    double result;

    if(op == '+'){
        result = num1 + num2;
    }
    else if(op == '-'){
        result = num1 - num2;
    }
    else if(op == '/'){
        result = num1 / num2;
    }
    else if (op == '*'){
            result = num1 * num2;
    }
    else{
        cout << "Invalid operation" << endl;
    }

    cout << "The result of the operation is: " << result << endl;
    return 0;
}
