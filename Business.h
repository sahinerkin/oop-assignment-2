/*
    Erkin Şahin
    150170025
*/

#ifndef BUSINESS_H
#define BUSINESS_H

#include "Owner.h"
#include "Courier.h"

// Declaring Business class
class Business {
    private:
        std::string name;
        std::string address;
        CourierNode* courier_array;
        Owner* owner_array;
        int number_of_owners;
        int number_of_couriers;
    public: 
        Business(std::string, std::string, Owner*, int);
        void hire_courier(Courier&);
        void fire_courier(Courier);
        void list_couriers();
        void list_owners();
        int calculate_shipment_capacity();
        void operator()();
        Courier & operator[](int);
};

// Constructor function of Business class
Business::Business(std::string name, std::string address, Owner* owner_array, int number_of_owners) {
    this->name = name;
    this->address = address;
    this->owner_array = owner_array;
    this->number_of_owners = number_of_owners;

    // Calculating ownership percentages and assigning them
    for(int i = 0; i < number_of_owners; i++) {
        owner_array[i].ownership = 100.0/number_of_owners;
    }

    this->courier_array = NULL;
    this->number_of_couriers = 0;
}

// Error check and adding a Courier to the linked list
void Business::hire_courier(Courier& courier) {

    if(courier.name.compare("-") == 0) {
        std::cout << "Invalid courier. Cannot be hired." << std::endl;
        return;
    }

    CourierNode* node = new CourierNode(&courier);

    if(number_of_couriers == 0) {
        courier_array = node;
    } else {
        CourierNode* traverse = courier_array;
        while(traverse->next) {
            traverse=traverse->next;
        }
        traverse->next = node;
    }

    number_of_couriers++;
}

// Removing a Courier from the linked list
void Business::fire_courier(Courier courier) {

    if(courier_array->courier->operator==(courier)) {
        CourierNode* temp = courier_array;
        if(courier_array->next) courier_array = courier_array->next;
        delete temp;
        number_of_couriers--;
        return;
    }

    CourierNode* traverse = courier_array;
    while(traverse->next) {
        if(traverse->next->courier->operator==(courier)) {
            CourierNode* temp = traverse->next->next;
            delete traverse->next;
            traverse->next = temp;
            number_of_couriers--;
            return;
        }
        traverse = traverse->next;
    }

    std::cout << "Courier not found!" << std::endl;
}

// Listing all Couriers
void Business::list_couriers() {
    for(int i = 0; i < number_of_couriers; i++) {
        std::cout << this->operator[](i).name << " " << this->operator[](i).surname << " " << this->operator[](i).vehicle << std::endl;
    }
}

// Listing all Owners
void Business::list_owners() {
    for(int i = 0; i < number_of_owners; i++) {
        owner_array[i].print_info();
        std::cout << std::endl;
    }
}

// Iterating over the list and summing up the capacity
int Business::calculate_shipment_capacity() {
    int total_capacity = 0;
    CourierNode* node = courier_array;

    while(node) {
        total_capacity += node->courier->capacity;
        node = node->next;
    }

    return total_capacity;
}

// Operator overloading for "()"
void Business::operator()() {
    std::cout << name << " " << address << std::endl;
    list_owners();
    list_couriers();
}

// Operator overloading for "[]"
Courier & Business::operator[](int index) {
    if(index < 0 || index > number_of_couriers-1) {
        std::cout << "Invalid index." << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;
    CourierNode* node = courier_array;

    while(i < index) {
        node = node->next;
        i++;
    }

    return *node->courier;
}

#endif