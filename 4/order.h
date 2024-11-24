#pragma once
#include"client.h"
#include"car.h"
#include<iostream>
#include <string>


using namespace std;


class order: public Car, public Person
{
public:
    order(const string& clientName, int age, int id, const string& status, const string& address, int number,
        int insuranceOption, bool confirmOrder, int damageLiability, const string& carModel, const string& idCar, int rentalPrice)
 : Person(clientName, age, id, status, address, number),
        Car(insuranceOption, confirmOrder, damageLiability, carModel, idCar, rentalPrice) {}

    // Метод для виводу інформації про замовлення
    void printOrderInfo() const {
        cout << "Order Information:" << endl; 
        Person::printInfo(); 
        Car::printCarInfo(); 

    }

    // Конструктор копіювання
    order(const order& other)
        : Person(other), Car(other) {}

    // Деструктор
    ~order() {
        cout << "Order destructor called for client: " << getName() << endl;
    }

    virtual void calculateTotalCost(int rentalDays) const {
        int totalCost = rentalDays * getRentalPrice();
        cout << "Total cost for " << rentalDays << " days is: " << totalCost << endl;
    }
    order operator+(const order& other) const;
    order operator-(const order& other) const;
    order& operator=(const order& other);
    order& operator*=(int multiplier);
    order& operator+=(const order& other);
    order& operator-=(const order& other);

    order operator*(int multiplier) const;
   
};

