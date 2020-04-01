#include <iostream>

using namespace std;

class Movie{
    private:
        string rating;

    public:
        string title;
        string director;
        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }

    //Make sure the rating is a valid rating
    void setRating(string aRating){
        if(aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R" || aRating == "NR"){
            rating = aRating;
        }else{
            rating = "NR";
        }
    }

    //Function to return the rating of a movie
    string getRating(){
        return rating;
    }

};
int main()
{
    Movie avengers("The Avengers", "Joss Whedon", "PG-13");

    //Enter an invalid rating for demonstration purposes
    avengers.setRating("Dog");
    cout << avengers.getRating();


    return 0;
}
