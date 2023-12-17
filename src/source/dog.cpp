#include "../include/dog.h"
#include <iostream>

Dog::~Dog()
{}

void Dog::printInfo()
{
   std::cout << "Dog's name is: " << this->getName() << std::endl;
}