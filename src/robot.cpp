#include "../inc/robot.hpp"

int Robot::nextId = 1;

// Constructor
Robot::Robot(const std::string& name, const std::string& task) 
    : name(name), currentTask(new std::string(task)), id(nextId++) {
    std::cout << "Robot constructor called for: " << this->name << std::endl;
}

// Destructor
Robot::~Robot() {
    if (currentTask) {
        delete currentTask;
        std::cout << "Robot destructor called for: " << this->name << std::endl;
    }
}

// Copy constructor
Robot::Robot(const Robot& other) 
    : name(other.name), currentTask(new std::string(*other.currentTask)), id(other.id) 
    {
    std::cout << "Robot copy constructor called for: " << this->name << std::endl;
}

// Move constructor
Robot::Robot(Robot&& other) noexcept
    : name(std::move(other.name)), currentTask(other.currentTask), id(other.id) 
    {
    other.currentTask = nullptr; 
    std::cout << "Robot move constructor called for: " << this->name << std::endl;
}

// Copy assignment operator
Robot& Robot::operator=(const Robot& other) 
{
    if (this == &other) {
        return *this;
    }

    delete currentTask;

    name = other.name;
    currentTask = new std::string(*other.currentTask);
    id = other.id;

    std::cout << "Copy assignment operator called for: " << this->name << std::endl;
    return *this; 
}

// Move assignment operator
Robot& Robot::operator=(Robot&& other) noexcept 
{
    // Verificare auto-atribuire
    if (this == &other) {
        return *this;
    }
    delete currentTask;

    // Mutăm membrii din obiectul sursa
    name = std::move(other.name);
    currentTask = other.currentTask;
    id = other.id;

    // Resetăm pointerul sursa
    other.currentTask = nullptr;

    std::cout << "Move assignment operator called for: " << this->name << std::endl;
    return *this; 
}

void Robot::displayInfo() const 
{
    std::cout << "Robot Name: " << name
              << ", Task: " << (currentTask ? *currentTask : "None")
              << ", ID: " << id << std::endl;
}

void Robot::changeTask(const std::string& newTask) 
{
    *currentTask = newTask;
    std::cout << name << " has a new task: " << newTask << std::endl;
}
