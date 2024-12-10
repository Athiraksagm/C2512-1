/*Abstraction
Task: Create a class Car with abstracted functions
startEngine() and stopEngine(). Use these functions
in the main() to operate the car.*/
#include <iostream>
using namespace std;

// Abstract class
class Car {
    public:
        virtual void startEngine() = 0; // Pure virtual function
        virtual void stopEngine() = 0; // Pure virtual function
};

// Derived class
class Sedan : public Car {
    public:
        void startEngine() override {
            cout << "Sedan engine started." << endl;
        }

        void stopEngine() override {
            cout << "Sedan engine stopped." << endl;
        }
};

// Another derived class
class SUV : public Car {
    public:
        void startEngine() override {
            cout << "SUV engine started." << endl;
        }

        void stopEngine() override {
            cout << "SUV engine stopped." << endl;
        }
};

int main() {
    Car* myCar = new Sedan(); // Using base class pointer
    myCar->startEngine();     // Start the sedan engine
    myCar->stopEngine();      // Stop the sedan engine

    delete myCar;

    myCar = new SUV();        // Switch to SUV
    myCar->startEngine();     // Start the SUV engine
    myCar->stopEngine();      // Stop the SUV engine

    delete myCar;

    return 0;
}

