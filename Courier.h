/*
    Erkin Şahin
    150170025
*/

#ifndef COURIER_H
#define COURIER_H

#include "Person.h"

// Declaring Courier class (inheriting Person)
class Courier : public Person {
    private:
        std::string vehicle;
        int capacity;

        friend class Business;
        friend class CourierNode;
    public:
        Courier(std::string, std::string, std::string);
        bool operator==(Courier);
};

// Constructor function of Courier class w/ error checking for vehicle_type
Courier::Courier(std::string name, std::string surname, std::string vehicle_type) {

    if(vehicle_type.compare("bicycle") == 0) {
        this->capacity = 10;
    } else if(vehicle_type.compare("motorcycle") == 0) {
        this->capacity = 35;
    } else if(vehicle_type.compare("car") == 0) {
        this->capacity = 200;
    } else {
        std::cout << "Vehicle not found!" << std::endl;
        this->name = "-";
        this->surname = "-";
        this->capacity = 0;
        this->vehicle = "-";
        return;
    }

    this->name = name;
    this->surname = surname;
    this->vehicle = vehicle_type;
   
}

// Operator overloading for "=="
bool Courier::operator==(Courier courier) {    
    return (courier.name.compare(this->name) == 0 && courier.surname.compare(this->surname) == 0 && courier.vehicle.compare(this->vehicle) == 0);
}


// Declaring CourierNode class for linked list implementation
// w/o changing Courier class
class CourierNode {
    private:
        Courier* courier;
        CourierNode* next;
        friend class Business;
    public:
        CourierNode(Courier*);
};

// Constructor function of CourierNode class
CourierNode::CourierNode(Courier* courier) {
    this->courier = courier;
    this->next = NULL;
}

#endif