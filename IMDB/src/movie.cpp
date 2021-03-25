#include "movie.hpp"
using namespace std;

bool check_add = true; // for checking all add option is successful

// Movie::Movie(string tempname, unsigned int tempscore, unsigned int tempyear, unsigned int temptime, string directortemp, string countrytemp)
// {
//     set_movie_name(tempname);
//     set_score(tempscore);
//     set_director(directortemp);
//     set_year(tempyear);
//     set_country(countrytemp);
//     set_random_id();
// }

// getting and validation name of movie start
void Movie::set_movie_name(string tempname)
{
    for (size_t i = 0; tempname[i] != '\0' ; i++)
    {
        // name of movie be must included letters and numbers
        if (!isalnum(tempname[i]))
        {
            check_add = false;
        }
    }
    try{
        //validation for invalid argument and printing error
        if (!check_add)
        {
            throw invalid_argument("The name of movie be must included letters and numbers, you entered invalid character's!");
        }
        movie_name = tempname;
    }
    catch(invalid_argument & moviename){
        cerr << "ERROR invalid argument:" << endl << moviename.what() << endl;
    }
}
// end

// for getting movie's name for print in main()
string Movie::get_movie_name() const
{
    return movie_name;
}
// getting and validation score of movie start
void Movie::set_score(float tempscore)
{
    try{
        if (tempscore > 10 || tempscore < 0)
        {
            check_add = false;
            throw invalid_argument("Score number be must between 0 and 10, you enterd invalid number!");
        }
        score = tempscore;
    }
    catch(invalid_argument & score)
    {
        cerr << "ERROR invalid argument:" << endl << score.what() << endl;
    }
}
// end

// for getitng movie's score for print in main()
float Movie::get_score() const
{
    return score;
}
// getting and validation for history of movie start
void Movie::set_year(unsigned int tempyear)
{
    try{
        if (tempyear > 2021 || tempyear < 1895)
        {
            check_add = false;
            throw invalid_argument("History of production of first movie was 1895 and now we are in 2021. So you must enter a year between 1895 and 2021 :)");
        }
        year = tempyear;
    }
    catch(invalid_argument & year){
        cerr << "ERROR invalid argument:" << endl << year.what() << endl;
    }
}
// end

// for getting movie's year for print in main()
unsigned int Movie::get_year() const
{
    return year;
}

// getting and validation for time of movie start
void Movie::set_time(unsigned int temptime)
{
    try{
        if (temptime < 1)
        {
            check_add = false;
            throw invalid_argument("Time of movie be must longer than 0 min");
        }
        time = temptime;
    }
    catch(invalid_argument & time){
        cerr << "ERROR invalid argument:" << endl << time.what() << endl;
    }
}
// end

// for getting movie's time for print in main()
unsigned int Movie::get_time() const
{
    return time;
}

// getting and validation for name of director of movie start
void Movie::set_director(string directortemp)
{
    for (size_t i = 0; directortemp[i] != '\0' ; i++)
    {
        // name of movie be must included letters
        if (!isalpha(directortemp[i]))
        {
            check_add = false;
        }
    }
    try{
        // validation for invalid argument and printing error
        if (!check_add)
        {
            throw invalid_argument("The name of director of movie be must included letters, you entered invalid character's!");
        }
        director = directortemp;
    }
    catch(invalid_argument & director){
        cerr << "ERROR invalid argument:" << endl << director.what() << endl;
    }
}
// end

// for getting name of director for print in main()
string Movie::get_director() const
{
    return director;
}

// getting and validation for name of country's production of movie start
void Movie::set_country(string countrytemp)
{
    for (size_t i = 0; countrytemp[i] != '\0' ; i++)
    {
        // name of country's movie be must included letters
        if (!isalpha(countrytemp[i]))
        {
            check_add = false;
        }
    }
    try{
        // validation for invalid argument and printing error
        if (!check_add)
        {
            throw invalid_argument("The name of country's production of movie be must included letters, you entered invalid character's!");
        }
        country = countrytemp;
    }
    catch(invalid_argument & country){
        cerr << "ERROR invalid argument:" << endl << country.what() << endl;
    }
}
// end

// for getting name of country of movie for print in main()
string Movie::get_country() const
{
    return country;
}
// random id start
void Movie::set_random_id()
{
    random_device dev;
    default_random_engine eng (dev());
    uniform_int_distribution <unsigned int> Myrand(1000, 3000);
    id = Myrand(eng);

    // this is better in random number ...

    // random_device dev;
    // std::mt19937 rng(dev());
    // uniform_int_distribution<int> Myrand(0, 1000000);

    // but i'am not using this because in this practice mentioned random engine

}
// end

// for getting id of movie for print in main()
unsigned int Movie::get_id() const
{
    return id;
}
void Movie::set_score_details()
{
    unsigned int numberx = 0 , numbery = 0;
    cin >> numberx >> numbery;
    score_details = new float * [numberx];
    for (size_t i = 0; i < numberx; i++)
    {
        score_details[i] = new float [numbery];
    }
    for (size_t i = 0; i < numberx; i++)
    {
        for (size_t j = 0; j < numbery; j++)
        {
            cin >> score_details[i][j];
            if(score_details[i][j] < 0 && score_details[i][j > 100])
            {
                throw invalid_argument("Score's can be between 0 and 100, you enterd invalid number!");
            }
        }
    }
}
void Movie::get_score_details()
{
    unsigned int i, j;
    cin >> i >> j;
    cout << score_details[i-1][j-1] << endl;
}