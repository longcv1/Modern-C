#include <iostream>
#include <memory>
#include "headers/dog.hpp"

int main(int, char**){
    std::cout << "Welcome to Modern C++ in advanced!\n";
    Dog *d1 = new Dog("DOG 01");
    d1->printInfo();
}
