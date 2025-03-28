#include "central.hpp"

/* Constructor
    - prints initialization
    status to the console */
    Root::Root(std::string name){
        std::cout << "Initializing " << &name << "..." << std::endl;
        GetSetName(name);
        GetSetAddress();
        std::cout << "----------------------------------------" << std::endl;
        std::cout << this->name << " initialized at address: " << this->address << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    };
    /* virtual ~Root()

    - Free's memory
    - Used to ensure that the correct destructor 
    is called when an object of a derived class 
    is deleted via a pointer to the base class


    NOTE: 
    - Objects of derived classes will call.
    both the base class destructor and
    their own destructor when deleted
    through polymorphism.

    - e.g: Root* exampleObj = new Derived();
    */
    Root::~Root(){

    };

    /* GetName()
    - Sets the name of the object
    - returns the name of the object, as string
    */
    std::string* Root::GetSetName(std::string setName){

        this->name = &setName;
        return this->name;
    };

    /* GetAddress()
    - returns the address of the object, as string*/
    std::string Root::GetSetAddress(){
        this->address = std::to_string(reinterpret_cast<std::uintptr_t>(this));
        return this->address;
    };