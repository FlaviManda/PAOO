#include "../inc/robot.hpp"

int Robot::nextId = 1;

Robot::Robot(const std::string& name, const std::string& task)
    : name(name), currentTask(std::make_shared<std::string>(task)), id(nextId++) 
    {
    std::cout << "Robot constructor called for: " << this->name << std::endl;
}
void Robot::displayInfo() const 
{
    std::cout << "Robot Name: " << name
              << ", Task: " << *currentTask
              << ", ID: " << id << std::endl;
}

void Robot::changeTask(const std::string& newTask) 
{
    *currentTask = newTask;
    std::cout << name << " has a new task: " << newTask << std::endl;
}

void Robot::useRobotResource() 
{
    resourceManager.useResource();
    std::cout << name << " successfully used the resource.\n";
}
