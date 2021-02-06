#include <iostream>

using namespace std;

int power(int baseNum, int powNum);

int main()
{
    /*
    //While Loop
    int index = 1;
    while(index <= 5){
        cout << index << endl;
        index++;
    }*/


    /*
    //Do while loop
    int index = 1;
    do{
        cout << index << endl;
        index++;
    }while(index <= 5);
    */


    /*
    //For Loop
    int nums[] = {1,2,3,4,5}
    for(int i = 0; i <= 5; i++){
        cout << nums[0] << endl;
    }
    */

    cout << power(3,4);

    return 0;
}

int power(int baseNum, int powNum){
    int result = 1;
    for(int i = 0; i < powNum; i++){
        result = result * baseNum;
    }
    return result;
};

