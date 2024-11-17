#include "../inc/robot.hpp"

int main() 
{
    // creare robot
    Robot robot1("Atlas", "Pick up objects");
    robot1.displayInfo();
    // modificam sarcina robotului
    robot1.changeTask("Sort items");
    robot1.displayInfo();
    // demonstrare copy contructor
    Robot robot2 = robot1;
    robot2.displayInfo();
    // demonstratre move constructor
    Robot robot3 = std::move(robot1);
    robot3.displayInfo();

    return 0;
}
