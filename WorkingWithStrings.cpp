#include <iostream>

using namespace std;

int main()
{
    string phrase = "Hello guys today is saturday";
    cout << phrase.length() << endl;
    cout << phrase[0] << endl;
    phrase[0] = 'B';
    cout << phrase << endl;
    cout << phrase.find("guys", 0) << endl;
    cout << phrase.substr(0, 4) << endl;
    return 0;
}
