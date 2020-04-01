#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num = 5;
    double dnum = 5.5;
    num++;
    dnum--;
    num += 80;
    dnum -= 3;
    cout << num << endl;
    cout << dnum << endl;
    cout << num / dnum << endl;
    cout << pow(2,5) << endl;
    cout << sqrt(36) << endl;
    cout << round(4.3) << endl;
    cout << ceil(4.1) << endl;
    cout << floor(4.9) << endl;
    cout << fmax(3,10) << endl;
    cout << fmin(3,10) << endl;

    return 0;
}
