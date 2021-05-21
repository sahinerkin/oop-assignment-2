/*
    Erkin Şahin
    150170025
*/

#ifndef OWNER_H
#define OWNER_H

#include "Person.h"

// Declaring Owner class (inheriting Person)
class Owner : public Person {
    private:
        int ownership;
        
        friend class Business;
    public:
        Owner();
        Owner(std::string, std::string);
        void print_info();
};

// Constructor functions of Owner class
Owner::Owner() {}

Owner::Owner(std::string name, std::string surname) {
    this->name = name;
    this->surname = surname;
}

// Printing info for Owner class
void Owner::print_info() {
    std::cout << name << " " << surname << " " << ownership;
}


#endif