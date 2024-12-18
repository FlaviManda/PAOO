#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <memory>  //std::shared_ptr
#include <mutex>   //std::mutex
#include <string>

class ResourceManager 
{
private:
    std::shared_ptr<std::mutex> resourceMutex; // mutex gestionat prin shared_ptr

public:
    
    ResourceManager() : resourceMutex(std::make_shared<std::mutex>()) 
    {
        std::cout << "ResourceManager created\n";
    }

    
    ~ResourceManager() 
    {
        std::cout << "ResourceManager destroyed\n";
    }

    
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) noexcept = delete;
    ResourceManager& operator=(ResourceManager&&) noexcept = delete;

    
    void useResource() {
        std::lock_guard<std::mutex> lock(*resourceMutex);
        std::cout << "Using resource safely\n";
    }
};

// Clasa Robot
class Robot 
{
private:
    std::string name;                         
    std::shared_ptr<std::string> currentTask; 
    int id;                                   
    static int nextId;                        

    ResourceManager resourceManager;          

public:
    
    Robot(const std::string& name, const std::string& task);

    ~Robot() = default;

    Robot(const Robot& other) = delete;

    Robot(Robot&& other) noexcept = delete;

    Robot& operator=(const Robot& other) = delete;

    Robot& operator=(Robot&& other) noexcept = delete;

    void displayInfo() const;
    void changeTask(const std::string& newTask);

    void useRobotResource();
};

#endif
