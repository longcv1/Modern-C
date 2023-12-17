#include <iostream>
#include <memory>
#include "src/include/dog.h"

int main(int, char**){
    std::cout << "Welcome to Modern C++ in advanced!\n";
    Dog d("ABC");
    d.printInfo();
    std::unique_ptr<Dog> d2 = std::make_unique<Dog>();
    d2->setName("NEW NAME");
    d2->printInfo();
}
