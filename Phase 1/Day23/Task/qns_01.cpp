/*
Question 13: `Healthcare System`
- `Base Class:` MedicalProfessional `{field: name, behavior: work()}`
- `Derived Class 1:` Doctor `{field: specialization, behavior: diagnose()}`
- `Derived Class 2:` Nurse `{field: department, behavior: assist()}`
- `Final Derived Class:` PhysicianAssistant `{field: certifications, behavior: treat()}`
=============================================================
These class structures represent the diamond problem,
where the `final derived class` 
inherits ambiguously 
from two intermediate classes 
that share a common base class.
=============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes 

*/ 

#include <iostream>
#include <string>

using namespace std;

// Base Class
class MedicalProfessional {
public:
    string name;

    // Constructor
    MedicalProfessional(string n) : name(n) {
        cout << "MedicalProfessional Constructor called!" << endl;
    }

    // Destructor
    virtual ~MedicalProfessional() {
        cout << "MedicalProfessional Destructor called!" << endl;
    }

    // Behavior
    void work() {
        cout << name << " is working." << endl;
    }
};

// Derived Class 1: Doctor
class Doctor : virtual public MedicalProfessional {
public:
    string specialization;

    // Constructor
    Doctor(string n, string spec) : MedicalProfessional(n), specialization(spec) {
        cout << "Doctor Constructor called!" << endl;
    }

    // Destructor
    virtual ~Doctor() {
        cout << "Doctor Destructor called!" << endl;
    }

    // Behavior
    void diagnose() {
        cout << name << " is diagnosing with specialization in " << specialization << "." << endl;
    }
};

// Derived Class 2: Nurse
class Nurse : virtual public MedicalProfessional {
public:
    string department;

    // Constructor
    Nurse(string n, string dep) : MedicalProfessional(n), department(dep) {
        cout << "Nurse Constructor called!" << endl;
    }

    // Destructor
    virtual ~Nurse() {
        cout << "Nurse Destructor called!" << endl;
    }

    // Behavior
    void assist() {
        cout << name << " is assisting in the " << department << " department." << endl;
    }
};

// Final Derived Class: PhysicianAssistant
class PhysicianAssistant : public Doctor, public Nurse {
public:
    string certifications;

    // Constructor
    PhysicianAssistant(string n, string spec, string dep, string cert) 
        : MedicalProfessional(n), Doctor(n, spec), Nurse(n, dep), certifications(cert) {
        cout << "PhysicianAssistant Constructor called!" << endl;
    }

    // Destructor
    ~PhysicianAssistant() {
        cout << "PhysicianAssistant Destructor called!" << endl;
    }

    // Behavior
    void treat() {
        cout << name << " is treating with certifications in " << certifications << "." << endl;
    }
};

int main() {
    // Static Object for Final Derived Class
    PhysicianAssistant pa1("John Doe", "Cardiology", "Emergency", "Advanced Care Certification");
    pa1.work();
    pa1.diagnose();
    pa1.assist();
    pa1.treat();

    cout << endl;

    // Dynamic Object for Final Derived Class
    MedicalProfessional* pa2 = new PhysicianAssistant("Jane Smith", "Neurology", "ICU", "Surgical Certification");
    pa2->work(); // Polymorphic call
    delete pa2;  // Destructor will be called automatically

    return 0;
}
