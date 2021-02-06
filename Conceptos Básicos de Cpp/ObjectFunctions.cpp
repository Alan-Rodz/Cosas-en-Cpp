#include <iostream>

using namespace std;

class Student{
    public:
        string name;
        string major;
        double gpa;

        //Constructor
        Student(string aName, string aMajor, double aGpa){
            name = aName;
            major = aMajor;
            gpa = aGpa;
        }

        //Function that checks if a student has honors or not
        bool hasHonors(){
            if(gpa >= 3.5){
                return true;
            } else{
                return false;
            }
        }
};

int main()
{
    Student student1("Jim", "Business", 2.4);
    Student student2("Pam", "Art", 3.6);

    cout << student1.hasHonors() << endl;
    cout << student2.hasHonors() << endl;
    return 0;
}
