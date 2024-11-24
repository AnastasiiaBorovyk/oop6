#include <iostream>
#include<fstream>
#include <cstring>
#include "car.h"
#include "admin.h"
#include "client.h"
#include "electroCar.h"
#include "order.h"
#include"TemplatePerson.h" 
using namespace std;

//void printAbc(Car* c) {
//    c->abc();
//}

void printAdminInfo(Person* p) {
    p->printInfo(); // Поліморфний виклик
}

void processRequest(Person* p, const string& request) {
    p->approveRequest(request); // Поліморфний виклик
}




void displayMenu() {
    cout << "\n==== MENU ====\n";
    cout << "1. Show static persons\n";
    cout << "2. Show dynamic persons\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void Service(Person& person, const string& filename, bool writeMode) {
    try {
        if (writeMode) {
            // Запис у файл
            ofstream file(filename, ios::out | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for writing.");
            }

            file << person.getName() << endl
                << person.getAge() << endl
                << person.getID() << endl
                << person.getStatus() << endl
                << person.getAddress() << endl
                << person.getNumber() << endl;

            if (file.fail()) {
                throw runtime_error("Error occurred while writing to file.");
            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            // Читання з файлу
            ifstream file(filename, ios::in | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for reading.");
            }

            string name, status, address;
            int age, id, number;

            if (!(getline(file, name) && file >> age && file >> id && file.ignore() &&
                getline(file, status) && getline(file, address) && file >> number)) {
                throw runtime_error("Invalid data format in file.");
            }

            if (file.fail()) {
                throw runtime_error("Error occurred while reading from file.");
            }

            file.close();

            // Оновлення даних об'єкта
            person.setName(name);
            person.setAge(age);
            person.setID(id);
            person.setStatus(status);
            person.setAddress(address);
            person.setNumber(number);

            cout << "Data read from file successfully." << endl; 
        }
    }
    catch (const exception& e) {
        cerr << "Service error: " << e.what() << endl;
        throw;
    }
}

int main() {

    Car car1(1, true, 1000, "Toyota Camry", "TX1234TX", 400);
    Car car2(2, false, 2000, "Honda Civic", "HC5678HC", 600);

    Car combinedCar = car1 + car2;
    cout << "Combined car info:" << endl;
    combinedCar.printCarInfo();

    Car differenceCar = car1 - car2;
    cout << "Difference car info:" << endl;
    differenceCar.printCarInfo();

    // Об'єкти класу Person
    Person personA("John", 35, 101, "Active", "123 Main St", 5551234);
    Person personB("Jane", 28, 102, "Inactive", "456 Elm St", 5555678);

    Person combined = personA + personB;
    combined.printInfo();

    Person difference = personA - personB;
    difference.printInfo();

    Admin admin1("Alice", 30, 101, "Active", "123 Street", 123456789, "Pending");
    Admin admin2("Bob", 40, 102, "Inactive", "456 Avenue", 987654321, "Approved");
    Admin combinedAdmin = admin1 + admin2;
    combinedAdmin.printAdminInfo();
    Admin reducedAdmin = admin1 - admin2;
    reducedAdmin.printAdminInfo();

    // Об'єкт шаблонного класу PersonTemplate
    PersonTemplate<string, int, int, string, string> templatePerson(
        "Alice", 30, 101, "Active", "123 Main St");

    // Виклик методу updateStatus
    templatePerson.printInfo(); 
    templatePerson.updateStatus("Inactive"); // Оновлення статусу 



    return 0;
}