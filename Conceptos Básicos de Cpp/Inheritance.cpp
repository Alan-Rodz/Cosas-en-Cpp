#include <iostream>

using namespace std;

class Chef{
    public:
        void makeChicken(){
            cout << "The chef makes chicken" << endl;
        }

        void makeSalad(){
            cout << "The chef makes salad" << endl;
        }

        void makeSpecialDish(){
            cout << "The chef makes a special dish" << endl;
        }


};

//Italian chef that makes everything the regular chef can do and other things
class ItalianChef : public Chef{
    public:
        void makePizza(){
            cout << "The chef makes pizza" << endl;
        }

        //Overwrite function for Italian Chef
        void makeSpecialDish(){
            cout << "The Italian chef makes Italian chicken" << endl;
        }
};

int main()
{
    Chef chef1;
    chef1.makeChicken();
    chef1.makeSpecialDish();

    ItalianChef Itchef1;
    Itchef1.makeChicken();
    Itchef1.makePizza();
    Itchef1.makeSpecialDish();
    return 0;
}
