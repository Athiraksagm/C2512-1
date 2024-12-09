/*

Problem 13: Healthcare System
- Create a base class Hospital with fields hospitalName and capacity, and a behavior admitPatient().
- Derive a class Clinic with fields doctorSpecialization and a behavior scheduleAppointment().
============================================================
single inheritance using static binding:
=============================================================
Create two static objects for Both Base and Derived class
and call all behaviours
and 
one two dynamic objects for Base and Derived class 
and call all behaviours

Define constructors and destructors for all the classes 


*/

#include <iostream>
#include <string>
using namespace std;

// Base class: Hospital
class Hospital {
protected:
    string hospitalName;
    int capacity;

public:
    // Constructor
    Hospital(string name, int cap) : hospitalName(name), capacity(cap) {
        cout << "Hospital constructor called for: " << hospitalName << endl;
    }

    // Destructor
    ~Hospital() {
        cout << "Hospital destructor called for: " << hospitalName << endl;
    }

    // Behavior: Admit a patient
    void admitPatient() {
        cout << "Admitting a patient to " << hospitalName << " with capacity: " << capacity << endl;
    }
};

// Derived class: Clinic
class Clinic : public Hospital {
private:
    string doctorSpecialization;

public:
    // Constructor
    Clinic(string name, int cap, string specialization)
        : Hospital(name, cap), doctorSpecialization(specialization) {
        cout << "Clinic constructor called for: " << hospitalName << endl;
    }

    // Destructor
    ~Clinic() {
        cout << "Clinic destructor called for: " << hospitalName << endl;
    }

    // Behavior: Schedule an appointment
    void scheduleAppointment() {
        cout << "Scheduling an appointment with a " << doctorSpecialization
             << " specialist at " << hospitalName << endl;
    }
};

int main() {
    // Static objects
    cout << "Static Object Creation:" << endl;
    Hospital hospitalStatic("City Hospital", 100);
    Clinic clinicStatic("Downtown Clinic", 20, "Cardiologist");

    // Call behaviors on static objects
    hospitalStatic.admitPatient();
    clinicStatic.admitPatient(); // Base class behavior
    clinicStatic.scheduleAppointment(); // Derived class behavior

    cout << "\nDynamic Object Creation:" << endl;
    // Dynamic objects
    Hospital* hospitalDynamic = new Hospital("Metro Hospital", 150);
    Clinic* clinicDynamic = new Clinic("Uptown Clinic", 30, "Dermatologist");

    // Call behaviors on dynamic objects
    hospitalDynamic->admitPatient();
    clinicDynamic->admitPatient(); // Base class behavior
    clinicDynamic->scheduleAppointment(); // Derived class behavior

    // Cleanup
    delete hospitalDynamic;
    delete clinicDynamic;

    return 0;
}
