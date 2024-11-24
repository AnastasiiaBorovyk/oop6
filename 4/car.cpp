#include "car.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include<fstream>

using namespace std;

Car::Car(int iO, bool cO, int dL, string cM, string IdCar, int rP) :
    insuranceOption(iO), confirmOrder(cO), damageLiability(dL), carModel(cM), IdCar(IdCar), rentalPrice(rP) {
};
Car::Car() : insuranceOption(2004588), confirmOrder(0), damageLiability(1000), carModel("Skoda Oktavia"), IdCar("BX1991BX"), rentalPrice(500) {
};
Car::Car(const Car& other)
    : insuranceOption(other.insuranceOption), confirmOrder(other.confirmOrder),
    damageLiability(other.damageLiability), carModel(other.carModel),
    IdCar(other.IdCar), rentalPrice(other.rentalPrice) {
    cout << carModel << endl;
}

int Car::getInsuranceOption() const {
    if (insuranceOption == 1) {
        return 200; // Вартість страхування для варіанту 1
    }
    else if (insuranceOption == 2) {
        return 500; // Вартість страхування для варіанту 2
    }
    else {
        return 0; // Якщо варіант не визначений
    }
};
bool Car::getConfirmOrder() const {
    return confirmOrder;
};
int Car::getDamageLiability()const {
    return damageLiability;
};
string Car::getCarModel()const {
    return carModel;
};
string Car::getIdCar()const {
    return IdCar;
};
int Car::getRentalPrice()const {
    return rentalPrice;
};

void Car::printCarInfo() const {
    cout << "Car model: " << carModel << ", Id car: " << IdCar
        << ", Rental price: " << rentalPrice << " " << endl;
};

Car Car::operator+(const Car& other) const { 
    return Car(
        insuranceOption,
        confirmOrder,
        damageLiability,
        carModel + " & " + other.carModel,
        IdCar + "_" + other.IdCar,
        rentalPrice + other.rentalPrice
    );
}

// Перевантаження оператора -
Car Car::operator-(const Car& other) const {
    return Car(
        insuranceOption,
        confirmOrder,
        damageLiability,
        carModel + " - " + other.carModel,
        IdCar + "-" + other.IdCar,
        abs(rentalPrice - other.rentalPrice)
    );
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        insuranceOption = other.insuranceOption;
        confirmOrder = other.confirmOrder;
        damageLiability = other.damageLiability;
        carModel = other.carModel;
        IdCar = other.IdCar;
        rentalPrice = other.rentalPrice;
    }
    return *this;
}

// Перевантаження оператора *=
Car& Car::operator*=(int multiplier) {
    rentalPrice *= multiplier;
    return *this;
}

// Перевантаження оператора +=
Car& Car::operator+=(const Car& other) {
    rentalPrice += other.rentalPrice;
    carModel += " & " + other.carModel;
    IdCar += "_" + other.IdCar;
    return *this;
}

// Перевантаження оператора -=
Car& Car::operator-=(const Car& other) {
    rentalPrice -= other.rentalPrice;
    if (rentalPrice < 0) rentalPrice = 0; // Запобігання негативній ціні
    carModel += " - " + other.carModel;
    IdCar += "-" + other.IdCar;
    return *this;
}

// Перевантаження оператора []
int Car::operator[](size_t index) const {
    switch (index) {
    case 0: return insuranceOption;
    case 1: return damageLiability;
    case 2: return rentalPrice;
    default: throw out_of_range("Invalid index");
    }
}

// Перевантаження оператора *
Car Car::operator*(int multiplier) const {
    return Car(
        insuranceOption,
        confirmOrder,
        damageLiability,
        carModel,
        IdCar,
        rentalPrice * multiplier
    );
}