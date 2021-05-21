/*
    Erkin Şahin
    150170025
*/

#ifndef PERSON_H
#define PERSON_H

// Declaring Person class
class Person {
    private:
        std::string name;
        std::string surname;

        friend class Owner;
        friend class Courier;
        friend class Business;
};

#endif