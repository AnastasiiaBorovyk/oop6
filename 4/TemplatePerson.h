#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename TName, typename TAge, typename TID, typename TStatus, typename TAddress>
class PersonTemplate {
private:
    TName name;
    TAge age;
    TID ID;
    TStatus status;
    TAddress address;

public:
    // Конструктор із параметрами
    PersonTemplate(TName n, TAge a, TID id, TStatus s, TAddress addr)
        : name(n), age(a), ID(id), status(s), address(addr) {}

    // Методи доступу
    TName getName() const { return name; }
    void setName(TName n) { name = n; }

    TAge getAge() const { return age; }
    void setAge(TAge a) { age = a; }

    TID getID() const { return ID; }
    void setID(TID id) { ID = id; }

    TStatus getStatus() const { return status; }
    void setStatus(TStatus s) { status = s; }

    TAddress getAddress() const { return address; }
    void setAddress(TAddress addr) { address = addr; }

    // Метод для виводу інформації
    void printInfo() const {
        cout << "Name: " << name
            << ", Age: " << age
            << ", ID: " << ID
            << ", Status: " << status
            << ", Address: " << address << endl;
    }

    // Метод для зміни статусу
    void updateStatus(const TStatus& newStatus) {
        status = newStatus;
        cout << "Status updated to: " << status << endl;
    }

    // Метод для перевірки віку
    bool isOlderThan(const TAge& threshold) const {
        return age > threshold;
    }

    // Метод для зміни адреси
    void relocate(const TAddress& newAddress) {
        address = newAddress;
        cout << "Address updated to: " << address << endl;
    }
};
