#include "electroCar.h"


electroCar electroCar::operator+(const electroCar& other) const {
    return electroCar(
        getInsuranceOption(),
        getConfirmOrder(),
        getDamageLiability(),
        getCarModel(),
        getIdCar(),
        getRentalPrice(),
        batteryCapacity + other.batteryCapacity, 
        range + other.range 
    );
}

// Реалізація оператора віднімання
electroCar electroCar::operator-(const electroCar& other) const {
    return electroCar(
        getInsuranceOption(),
        getConfirmOrder(),
        getDamageLiability(),
        getCarModel(),
        getIdCar(),
        getRentalPrice(),
        batteryCapacity - other.batteryCapacity,
        range - other.range 
    );
}