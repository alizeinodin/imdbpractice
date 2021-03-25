#include"movie.hpp"
#include"func.hpp"
using namespace std;

int main() {

    int n = 0; // if user adding a new movie, in add function length of array will increse but for saving space i try consider least space
    Movie * array;
    array = new Movie[n];
    string select;
    cout << "--> help: showing manuals of program" << endl
    << "--> exit: exiting the program" << endl;
    while (select != "exit")
    {
        cin >> select;
        Command_Separator(select, array, n);
    }
    
    
    delete[] array;
    return 0;
}