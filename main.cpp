#include <iostream>
#include <cstdio>
#include "smtptr.h"

using std::cout;

class Person {
    public:
     int x{};
     Person(int x=0): x{x}{}
};

int main(){

    cout << "hi" << "\n";
    smtptr::shptr<Person> p1(new Person(3));

    cout << "here is the object mapped by the smart pointer:" << p1->x << "\n";

    smtptr::shptr<Person> p2 = p1;

    cout << "here is the oject mapped by the second smart pointer:"<< p2->x << "\n";

    cout << "here is the count: " << p1.getCount() << "\n";


}