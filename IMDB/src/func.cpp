#include "movie.hpp"
#include "func.hpp"
using namespace std;
extern bool check_add;

// add new movie
// -----------------------------
inline void add(Movie temp, Movie *&array, int &n)
{
    // for checking available moive's in list to adding name to list
    int i;
    string nameofmovie = temp.get_movie_name();
    if (checkmovie(nameofmovie, array, n, i))
    {
        throw invalid_argument("ERROR: The name with you enter is available in movie's list, please enter another name for your movie");
    }

    // increase length of array for adding new element
    if (check_add)
    {
        Movie *newarray;
        newarray = new Movie[n + 1];
        for (int j = 0; j < n; j++)
        {
            newarray[j] = array[j];
        }
        newarray[n] = temp;
        array = new Movie[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            array[j] = newarray[j];
        }
        delete[] newarray;
        n++; // size of array in next call add's function be must assign size of newarray
        cout << "--> " << array[n - 1].get_movie_name() << " added" << endl;
    }
}
// -----------------------------

// remove movies
// -----------------------------
void remove(string name_movie_selected, Movie *&array, int &n)
{
    if (n < 1)
    {
        throw invalid_argument("ERROR: no movies added!");
    }
    // for checking available moive's in list to adding name to list
    int i;
    if (!checkmovie(name_movie_selected, array, n, i))
    {
        throw invalid_argument("ERROR 404: your name's of movie that you entered, was not found!");
    }
    Movie *newarray;
    // because we are removing an element of array so we must be reduse size of array (n - 1)
    newarray = new Movie[n - 1];
    int j, h = 0;
    for (j = 0; j < n; j++)
    {
        if (j != i)
        {
            newarray[h] = array[j];
            h++;
        }
    }
    array = new Movie[n - 1];
    for (j = 0; j < n - 1; j++)
    {
        array[j] = newarray[j];
    }
    delete[] newarray;
    n--; // length of array decrease
}
// -----------------------------

// for showing a movies details
// -----------------------------
void show(string tempname, Movie *&array, int &n)
{
    int i = 0;
    if (checkmovie(tempname, array, n, i))
    {
        cout << "| " << setw(4) << left  << array[i].get_id() << " | " << setw(12)<< array[i].get_movie_name() << " | " << setw(5) << array[i].get_score() << " | " << setw(8) << array[i].get_director() << " | " << setw(4) << array[i].get_year() << " | " << setw(8) << array[i].get_country() << " | " << endl;
    }
    else
    {
        cerr << "ERROR: Your entered movie's name was not found!!!" << endl;
    }
}
// -----------------------------

// for showing all movies details
// -----------------------------
void show_all(Movie *&array, int &n)
{
    bool check = false;
    cout << "| " << setw(4) << left  << "ID"
         << " | " << setw(12) << "NAME"
         << " | " << setw(4) << "SCORE"
         << " | " << setw(8) << "DIRECTOR"
         << " | " << setw(4) << "YEAR"
         << " | " << setw(8) << "COUNTRY"
         << " | " << endl;

    for (size_t i = 0; i < n; i++)
    {
        check = true;
        show(array[i].get_movie_name(), array, n);
    }
    if (!check)
    {
        cerr << "ERROR: There are no movies to show!!!" << endl;
    }
}
// -----------------------------

// for sorting array
// -----------------------------

// helping to sort array by name or score
bool help_sort(Movie *&array, string select, int j)
{
    order_adjust(select);
    if (select == "name")
    {
        if (array[j].get_movie_name() > array[j + 1].get_movie_name())
        {
            return true;
        }
        return false;
    }
    else if (select == "score")
    {
        if (array[j].get_score() < array[j + 1].get_score())
        {
            return true;
        }
        return false;
    }
    else
    {
        throw invalid_argument("ERROR: Movies only can order by name's or score's!");
    }
    return false;
}
// sorting function
void sort_by(Movie *&array, string select, int &n, bool (*function)(Movie *&, string, int))
{
    bool check = true /* for optimizing bubble sort */, sort = false;
    if (n > 0)
    {
        try
        {
            for (size_t i = 0; i < n && check; i++)
            {
                check = false;
                for (size_t j = 0; j < n - i - 1; j++)
                {
                    if (function(array, select, j))
                    {
                        Movie temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                        check = true;
                        sort = true;
                    }
                }
            }
        }
        catch (invalid_argument &errorselected)
        {
            cerr << "ERROR: " << errorselected.what() << " you entered \"" << select << "\"!" << endl;
        }
    }
    else
    {
        cerr << "--> ERROR: " << endl
             << "No exist any movies for sorting!" << endl;
    }
    if (sort)
    {
        cout << "--> Movies sorted by " << select << endl;
    }
}
// -----------------------------

// average-score function
// -----------------------------
void avg_score(Movie *array, int n)
{
    if (n > 0)
    {
        float avg = 0;
        for (size_t i = 0; i <= n; i++)
        {
            avg += array[i].get_score();
        }
        float result = avg / n;
        cout << "Average Score: " << result << endl;
    }
    else
    {
        throw invalid_argument("No moives added!");
    }
}
// -----------------------------

// help function
// -----------------------------
void help()
{
    cout << endl
         << "-----------------------------------" << endl;
    cout << "Add Movie: "
         << "add < movie name > < score > < production Year > < directory name > < time > < production country > " << endl;
    cout << "--> Gauide:" << endl
         << "The name of movie be must included letters and numbers" << endl
         << "Score number be must between 0 and 10" << endl
         << "History of production of first movie was 1895 and now we are in 2021. So you must enter a year between 1895 and 2021" << endl
         << "Time of movie be must longer than 0 min" << endl
         << "The name of director of movie be must included letters, you entered invalid character's!" << endl
         << "The name of country's production of movie be must included letters"
         << "--> Example : ‫‪add‬‬ ‫‪SpiderMan3‬‬ ‫‪10‬‬ ‫‪2014‬‬ ‫‪nolan 120‬‬ ‫‪Iran‬‬"
         << endl
         << endl;

    cout << "Remove Movie: "
         << "remove < movie name >" << endl
         << "--> Example: remove SpiderMan3"
         << endl
         << endl;

    cout << "Sort Movie's: "
         << "sort_by < score/name >" << endl;
    cout << "--> Gauide:" << endl
         << "Movies can sorted by \" name \" or \" score \""
         << "--> Example: sort_by name"
         << endl
         << endl;

    cout << "Show Movie: "
         << "show < movie name >" << endl
         << "--> Gauide:" << endl
         << "showing data of a movie in a line"
         << "--> Example: show SpiderMan3"
         << endl
         << endl;

    cout << "Show All Movie's: "
         << "show-all" << endl
         << "--> Gauide:" << endl
         << "showing data's of all movie with added !" << endl
         << "--> Example:  show-all"
         << "--> be attention to - in order of show-all"
         << endl
         << endl;

    cout << "Average Score Of Movie's: "
         << "average-score" << endl
         << "--> Gauide:" << endl
         << "calculates average score of all of movies with added" << endl
         << "--> Example: average-score "
         << endl
         << endl;

    cout << "Score Details Of Movie's: "
         << "score-details" << endl
         << "--> Gauide:" << endl
         << "score details get two argument. get and set" << endl
         << "set getting two number. first number is number of reviewer and second number is score's of them!" << endl
         << "and next enter score's" << endl
         << "get getting two number. first number is number of reviewer and second number is score's number" << endl
         << "--> Example:" << endl
         << "score-details spIderMan3 set 3 2 100 85 80 73 60 70" << endl
         << "score-details SpiderMan3 get 2 2 \t"
         << " print --> 73" << endl;

    cout << "Help: "
         << "help" << endl
         << "--> Gauide:" << endl
         << "showing this list"
         << endl
         << endl;
    cout << "-----------------------------------" << endl;
}
// -----------------------------

// checking movie's list for available movie's
// -----------------------------
bool checkmovie(string temp, Movie *array, int n, int &i /* in show function we use i for showing data */)
{
    for (i = 0; i < n; i++)
    {
        if (temp.length() == array[i].get_movie_name().length()) // if name's were similar length of them is equal
        {
            string tempname = temp;
            string namemovie = array[i].get_movie_name();
            for (size_t q = 0; tempname[q] != '\0'; q++)
            {
                if (isupper(tempname[q]))
                {
                    tempname[q] = tolower(tempname[q]);
                }
                if (isupper(namemovie[q]))
                {
                    namemovie[q] = tolower(namemovie[q]);
                }
            }
            if (tempname == namemovie)
            {
                return true;
            }
        }
    }
    return false;
}
// -----------------------------

// score details function: add many score for a movie
// -----------------------------
void score_details(string tempname, Movie *array, int &n)
{
    int i = 0;
    if (!checkmovie(tempname, array, n, i))
    {
        throw invalid_argument("ERROR: The name with you entered is not available in list of movie's!, please enter a valid name");
    }
    string select_score;
    cin >> select_score;
    order_adjust(select_score);
    if (select_score == "set")
    {
        array[i].set_score_details();
        cout << "Score's added for " << array[i].get_movie_name() << endl;
    }
    else if (select_score == "get")
    {
        cout << "Score " << i-1 << " & " << i-1 << " for " << array[i].get_movie_name() << " --> ";
        array[i].get_score_details();
    }
    else
    {
        throw invalid_argument("ERROR: You enter invalid argument. Score-Details can get two value, get and set!");
    }
}
// -----------------------------

// adjusting order (lower and upper case)

void order_adjust(string &select)
{
    // for no sensitive select to lower or upper case
    for (size_t q = 0; select[q] != '\0'; q++)
    {
        if (isupper(select[q]))
        {
            select[q] = tolower(select[q]);
        }
    }
}
// navigator and separator of program
// -----------------------------
void Command_Separator(string select, Movie *&array, int &n)
{
    order_adjust(select);

    if (select == "add")
    {
        Movie film;
        string tempname, directortemp, countrytemp;
        unsigned int temptime, tempyear;
        float tempscore;
        cin >> tempname >> tempscore >> tempyear >> directortemp >> temptime >> countrytemp;
        film.set_movie_name(tempname);
        film.set_score(tempscore);
        film.set_director(directortemp);
        film.set_year(tempyear);
        film.set_country(countrytemp);
        film.set_random_id();
        // Movie film(tempname, tempscore, tempyear, directortemp, temptime, countrytemp);

        // cout << tempname << "\t" << tempscore << "\t" << directortemp << "\t" << tempyear << "\t" << countrytemp << endl;
        try
        {
            add(film, array, n);
        }
        catch (invalid_argument &nameofmovie)
        {
            cerr << "ERROR: " << nameofmovie.what() << endl;
        }
    }
    else if (select == "remove")
    {
        string tempname;
        cin >> tempname;
        try
        {
            remove(tempname, array, n);
            cout << tempname << " Removed!" << endl;
        }
        catch (invalid_argument &remove)
        {
            cerr << remove.what() << endl;
        }
    }
    else if (select == "sort-by")
    {
        string select;
        cin >> select;
        sort_by(array, select, n, &help_sort);
    }
    else if (select == "show")
    {
        string tempname;
        cin >> tempname;
        show(tempname, array, n);
    }
    else if (select == "show-all")
    {
        show_all(array, n);
    }
    else if (select == "average-score")
    {
        try
        {
            avg_score(array, n);
        }
        catch (invalid_argument &avg)
        {
            cerr << "ERROR: " << avg.what() << endl;
        }
    }
    else if (select == "help")
    {
        help();
    }
    else if (select == "score-details")
    {
        string tempname;
        cin >> tempname;
        score_details(tempname, array, n);
    }else if(select == "exit")
    {
        cout << "exiting..." << endl;
    }
    else
    {
        cerr << "ERROR input data" << endl
             << "You Enter: " << select << endl
             << "Plsase Enter \" help \" to show manuals of program! " << endl;
    }
}
// -----------------------------
