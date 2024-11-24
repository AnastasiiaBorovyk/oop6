#include "admin.h"
#include "person.h"
#include <iostream> 
using namespace::std;


Admin Admin::operator+(const Admin& other) const {
    string combinedRequestStatus = this->requestStatus + " & " + other.requestStatus;
    return Admin(
        this->getName() + " & " + other.getName(),  
        this->getAge() + other.getAge(),            
        this->getID(),                              
        this->getStatus(),                          
        this->getAddress(),                         
        this->getNumber(),                          
        combinedRequestStatus                       
    );
}

Admin Admin::operator-(const Admin& other) const {
    int newAge = this->getAge() > other.getAge() ? this->getAge() - other.getAge() : 0;

    string newRequestStatus = this->requestStatus + " (minus " + other.requestStatus + ")";
    return Admin(
        this->getName(),     
        newAge,                    
        this->getID(),             
        this->getStatus(),         
        this->getAddress(),        
        this->getNumber(),         
        newRequestStatus           
    );
}



// Перевантаження оператора =
Admin& Admin::operator=(const Admin& other) {
    if (this != &other) { // Перевірка на самоприсвоєння
        Person::operator=(other); // Виклик оператора присвоєння базового класу
        requestStatus = other.requestStatus;
    }
    return *this;
}

// Перевантаження оператора *=
Admin& Admin::operator*=(int multiplier) {
    // Розмножуємо статус запиту множником
    string originalStatus = requestStatus;
    for (int i = 1; i < multiplier; ++i) {
        requestStatus += " " + originalStatus;
    }
    return *this;
}

// Перевантаження оператора +=
Admin& Admin::operator+=(const Admin& other) {
    requestStatus += " & " + other.requestStatus;
    return *this;
}

// Перевантаження оператора -=
Admin& Admin::operator-=(const Admin& other) {
    size_t pos = requestStatus.find(other.requestStatus);
    if (pos != string::npos) {
        requestStatus.erase(pos, other.requestStatus.length());
    }
    return *this;
}

// Перевантаження оператора *
Admin Admin::operator*(int multiplier) const {
    Admin result = *this;
    string originalStatus = requestStatus;
    for (int i = 1; i < multiplier; ++i) {
        result.requestStatus += " " + originalStatus;
    }
    return result;
}