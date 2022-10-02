/******************************************************************
 * Section 13 Challenge
 * Movie.cpp
 * 
 * Models a Movie with the following atttributes
 * 
 * std::string name - the name of the movie 
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 * ***************************************************************/
#include <iostream>
#include "Movie.h"

// Implemention of the construcor

Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
    : name{name_val}, rating{rating_val}, watched{watched_val}  {
}

//Implemention of the copy constructor
Movie::Movie(const Movie &source) 
    : Movie{source.name, source.rating, source.watched} {
}

// Implementation of the destructor
Movie::~Movie() {
}

// Implementation of the display method
void Movie::display() const {
    std::cout << name << ", " << rating <<  ", " << watched  <<   std::endl;
}

void Movie::set_name(std::string name_val) {
    name = std::move(name_val);
}

std::string Movie::get_name() const {
    return name;
}

void Movie::set_rating(std::string rating_val) {
    rating = std::move(rating_val);
}

std::string Movie::get_rating() const {
    return rating;
}

void Movie::set_watched(int watched_val) {
    watched = watched_val;
}

int Movie::get_watched() const {
    return watched;
}

void Movie::increment_watched() {
    ++watched;
}