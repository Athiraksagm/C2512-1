/*


Problem 13: Tool and PowerDrill
- Base Class: Tool  
  - Fields: brand, weight  
  - Pure Virtual Behaviors: useTool(), maintainTool().  
- Derived Class: PowerDrill  
  - Fields: drillSpeed, bitType  
===========================================================
single inheritance with dynamic binding
=============================================================
one two dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class 

If you use string, use c-string (don't use string class)
        ie. dynamic c-string [dynamic char array]
*/

#include <iostream>
#include <cstring> // For C-string operations
using namespace std;

// Base Class
class Tool {
protected:
    char* brand;
    float* weight;

public:
    // Constructor
    Tool(const char* brandName, float w) {
        brand = new char[strlen(brandName) + 1];
        strcpy(brand, brandName);
        weight = new float(w);
        cout << "Tool Constructor called." << endl;
    }

    // Virtual Destructor
    virtual ~Tool() {
        delete[] brand;
        delete weight;
        cout << "Tool Destructor called." << endl;
    }

    // Pure virtual functions
    virtual void useTool() = 0;
    virtual void maintainTool() = 0;

    // Display Base fields
    virtual void displayToolInfo() {
        cout << "Brand: " << brand << ", Weight: " << *weight << " kg" << endl;
    }
};

// Derived Class
class PowerDrill : public Tool {
private:
    float* drillSpeed;   // Dynamic field
    char* bitType;       // Dynamic field

public:
    // Constructor
    PowerDrill(const char* brandName, float w, float speed, const char* type)
        : Tool(brandName, w) {
        drillSpeed = new float(speed);
        bitType = new char[strlen(type) + 1];
        strcpy(bitType, type);
        cout << "PowerDrill Constructor called." << endl;
    }

    // Destructor
    ~PowerDrill() override {
        delete drillSpeed;
        delete[] bitType;
        cout << "PowerDrill Destructor called." << endl;
    }

    // Overriding Tool behaviors
    void useTool() override {
        cout << "Using the power drill with speed " << *drillSpeed << " RPM and bit type " << bitType << "." << endl;
    }

    void maintainTool() override {
        cout << "Maintaining the power drill: cleaning and lubricating the parts." << endl;
    }

    // Display Derived fields
    void displayToolInfo() override {
        Tool::displayToolInfo();
        cout << "Drill Speed: " << *drillSpeed << " RPM, Bit Type: " << bitType << endl;
    }
};

// Main function
int main() {
    // Create dynamic objects of the Derived class pointed by Base class pointers
    Tool* tool1 = new PowerDrill("Bosch", 2.5, 1500, "Metal");
    Tool* tool2 = new PowerDrill("DeWalt", 3.0, 2000, "Wood");

    // Call behaviors using Base class pointers
    tool1->useTool();
    tool1->maintainTool();
    tool1->displayToolInfo();

    cout << endl;

    tool2->useTool();
    tool2->maintainTool();
    tool2->displayToolInfo();

    // Free allocated memory
    delete tool1;
    delete tool2;

    return 0;
}
