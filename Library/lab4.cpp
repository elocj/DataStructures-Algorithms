#include <iostream>
#include "manager.h"

int main() {
    Manager* manager = new Manager();
    manager->execute();
    delete manager;
    manager = nullptr;

//    Manager manager;
//    manager.execute();
    return 0;
}