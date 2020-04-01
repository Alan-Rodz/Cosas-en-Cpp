#include <iostream>

using namespace std;

int getMax(int num1, int num2, int num3);

int main()
{
    cout << getMax(10, 20, 30) << endl;
    return 0;
}


int getMax(int num1, int num2, int num3){
    int result;

    if(num1 >= num2 && num1 >= num3){
        result = num1;
    }
    else if(num2 >= num1 && num2 >= num3){
        result = num2;
    }else{
        result = num3;
    }

    return result;
}
