#include "../inc/robot.hpp"

int Robot::nextId = 1;

// Constructor robot
Robot::Robot(const std::string& name, const std::string& task) 
{
    this->name = name;
    this->currentTask = new std::string(task);
    this->id = this->nextId++;
    std::cout << "Robot constructor called for: " <<this->name<< std::endl;
}

// Destructor
Robot::~Robot() 
{
    if (this->currentTask) {
        delete this->currentTask;
        std::cout << "Robot destructor called for: "<<this->name<<std::endl;
    }
}

// Copy constructor
Robot::Robot(const Robot& other) 
{
    this->name = other.name;
    this->currentTask = new std::string(*other.currentTask);
    this->id = other.id;
    std::cout << "Robot copy constructor called for: "<<this->name<<std::endl;
}

// Move constructor
Robot::Robot(Robot&& other)
{
    this->name = std::move(other.name);
    this->currentTask = other.currentTask;
    this->id = other.id;
    other.currentTask = nullptr;
    std::cout << "Robot move constructor called for: "<<this->name<<std::endl;
}

void Robot::displayInfo() const 
{
    std::cout<< "Robot Name: "<<this->name
            << ", Task: "<<(this->currentTask ? *this->currentTask : "None")
            << ", ID: " <<this->id << std::endl;
}

void Robot::changeTask(const std::string& newTask) 
{
    *this->currentTask = newTask;
    std::cout<<this->name<<" has a new task: "<<newTask<<std::endl;
}
