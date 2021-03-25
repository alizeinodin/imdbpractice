#ifndef FUNK_H
#define FUNK_H

void add(Movie, Movie * &, int &);
void remove(std::string, Movie * &, int &);
void show(std::string, Movie * &, int &);
void show_all(Movie * &, int &);
void sort_by(Movie * &, std::string, int &, bool (*function)(Movie * &, std::string, int));
void avg_score(Movie *, int);
void help();
bool checkmovie(std::string, Movie *, int, int &); // check for available movie's in list
void score_details(std::string, Movie*, int &); 
void order_adjust(std::string &);
void Command_Separator(std::string, Movie * &, int &);
bool help_sort(Movie * & array, std::string select, int j); // passing this funcion to sort_by for sorting by name's or score's

#endif // !FUNK_H
