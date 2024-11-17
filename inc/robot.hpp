#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>
#include <iostream>

class Robot 
{
private:
    std::string name;               
    std::string* currentTask;       
    int id;                         
    
    static int nextId;              

public:
    // Constructor
    Robot(const std::string& name, const std::string& task);

    // Destructor
    ~Robot();

    // Copy constructor
    Robot(const Robot& other);

    // Move constructor
    Robot(Robot&& other);

    void displayInfo() const;
    void changeTask(const std::string& newTask);
};

#endif