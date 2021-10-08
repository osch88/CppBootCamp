#include <iostream>
#include <string>
#include <stdio.h>


struct humanStruct
{
    std::string name;
    int age;
    bool married;
    static std::string race;
};

std::string humanStruct::race;

void print(std::string *_ptrStr){
    std::cout << *_ptrStr << std::endl;
}

void print(int *_ptrInt){
    std::cout << *_ptrInt << std::endl;
}

void print(bool *_ptrMarried){
    if(*_ptrMarried) std::cout << "False" << std::endl;
    else std::cout << "True" << std::endl;
}

int main(){
    /*
        Creating the first person
    */

    humanStruct::race = "human";

    struct humanStruct *person = new struct humanStruct;

    person->name = "oscar";
    person->age = 33;
    person->married = false;

    print( &(person->name) );
    print( &(person->age) );
    print( &(person->married) );
    print( &(person->race) );

    /*
        Creating the second person
    */

    struct humanStruct *person2 = new struct humanStruct;

    person2->name = "tea";

    print( &(person2->name) );
    print( &(person2->race) );



    delete person;

    return 0;
}