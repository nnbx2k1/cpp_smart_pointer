#include <iostream>
#include <cstdio>
#include "smtptr.h"

class Person {
    public:
     int x{};
     Person(int x=0): x{x}{}
};

int main(){

    std::cout << "hi";
    smtptr::shptr<Person> p1(new Person(3));


}