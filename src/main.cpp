#include "../inc/robot.hpp"

int main() 
{

    Robot robot1("Atlas", "Pick up objects");
    Robot robot2("Helper", "Clean the floor");

    robot1.displayInfo();
    robot2.displayInfo();

    robot1.changeTask("Organize warehouse");
    robot1.displayInfo();

    std::cout << "\nTesting resource usage:\n";
    robot1.useRobotResource();
    robot2.useRobotResource();

    return 0;
}
