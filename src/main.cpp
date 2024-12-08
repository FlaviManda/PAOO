#include "../inc/robot.hpp"

int main() 
{
    // Creare roboti
    Robot robot1("Atlas", "Pick up objects");
    Robot robot2("Helper", "Clean the floor");

    robot1.displayInfo();
    robot2.displayInfo();

    // Copy assignment operator
    std::cout << "\nTesting copy assignment operator:\n";
    robot2 = robot1;
    robot2.displayInfo();

    // Move assignment operator
    std::cout << "\nTesting move assignment operator:\n";
    Robot robot3("Cleaner", "Vacuum");
    robot3 = std::move(robot1);
    robot3.displayInfo();

    std::cout << "\nTesting self-assignment:\n";
    robot3 = robot3; 
    robot3.displayInfo();

    return 0;
}
