#include<iostream>
#include<cctype>
#include<stdexcept>
#include<random>
#include<cstring>
#include<ctime>
#include<iomanip>

#ifndef MOVIE_H
#define MOVIE_H 

class Movie
    {
    public:
        //set data
        // Movie(std::string tempname, unsigned int tempscore, unsigned int tempyear, unsigned int temptime, std::string directortemp, std::string countrytemp); // constructor
        void set_movie_name(std::string);
        void set_score(float);
        void set_year(unsigned int);
        void set_time(unsigned int);
        void set_director(std::string);
        void set_country(std::string);
        void set_random_id(); // assign an random id for any movie
        void set_score_details();
        // end set

        //get data
        std::string get_movie_name() const;
        float get_score() const;
        unsigned int get_year() const;
        unsigned int get_time() const;
        std::string get_director() const;
        std::string get_country() const;
        unsigned int get_id() const;
        void get_score_details();
        //end get

    private:
        //data variable
        std::string movie_name;
        float score = 0; // default score for every movie is 0 unless user enter any number for score
        unsigned int year = 1895; // default history for every movie is 1895 (time of production of first movie) unless user enter any number for year
        unsigned int time = 0; // default time for every movie is 0 unless user enter any time for movie
        std::string director; // the name of director of movie
        std::string country; // name of production country of movie's
        unsigned int id = 0; // maximum random number expected 3000 and start at 0
        float ** score_details;
    };

#endif // !MOVIE_H
