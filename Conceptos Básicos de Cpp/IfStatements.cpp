#include <iostream>

using namespace std;

int main()
{
    bool isMale = true;
    bool isHandsome = true;
    if(isMale && isHandsome){
        cout << "You are a handsome male" << endl;
    }

    else if(isMale && !isHandsome){
         cout << "You aren't a handsome male" << endl;
    }

    else if(!isMale && isHandsome){
        cout << "You are handsome alright, but not a male" << endl;
    }

    else{
        cout << "You are not male and not handsome lmfao" << endl;
    }
    return 0;
}
