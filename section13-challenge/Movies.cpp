/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

/*************************************************************************
   Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

/*************************************************************************
  add_movie expects the name of the move, rating and watched count

  It will search the movies vector to see if a movie object already exists
  with the same name.

  If it does then return false since the movie already exists
  Otherwise, create a movie object from the provided information
  and add that movie object to the movies vector and return true
  *********************************************************************/
bool Movies::add_movie(std::string name_val, std::string rating_val, int watched_val) {
    if (Movies::movie_already_exists(name_val)) {
        return false;
    } else {
        Movie new_movie{name_val, rating_val, watched_val};
        movies.push_back(new_movie);
        return true;
    }
}

bool Movies::movie_already_exists(std::string name_val) const {
    for (auto movie: movies) {
        if (movie.get_name() == name_val) {
            return true;
        }
    }
    return false;
}

bool Movies::increment_watched(std::string name_val) {
    for (auto movie: movies) {
        if (movie.get_name() == name_val) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}
void Movies::display() const {
    for (auto movie: movies) {
        movie.display();
    }
}