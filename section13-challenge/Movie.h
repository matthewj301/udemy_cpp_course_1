/******************************************************************
 * Section 13 Challenge
 * Movie.h
 * 
 * Models a Movie with the following attributes
 * 
 * std::string name - the name of the movie 
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 * ***************************************************************/
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <utility>

class Movie {
private:
    std::string name;   // the name of the movie
    std::string rating;   // the movie rating G,PG, PG-13, R
    int watched;          // the number of times you've watched the movie
public:
    // Constructor - expects all 3 movie attributes
    Movie(std::string name, std::string rating, int watched);

    // Copy constructor 
    Movie(const Movie &source);

    // Destructor
    ~Movie();

    // Basic getters and setters for private attributes
    // implement these inline and watch your const-correctness

    void set_name(std::string name_val);

    std::string get_name() const;

    void set_rating(std::string rating_val);

    std::string get_rating() const;

    void set_watched(int watched_val);

    int get_watched() const;

    // Simply increment the watched attribute by 1
    void increment_watched();

    // simply displays the movie information ex.) Big, PG-13, 2
    void display() const;
};

#endif // _MOVIE_H_
