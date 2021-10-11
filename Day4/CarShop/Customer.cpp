#include<iostream>
#include<string>
#include<vector>

#include"Customer.h"

Customer::Customer()
{
    name = "John Doe";
    date = "2020-10-07";
}
void Customer::setCustomer(std::string _name, std::string _date){
    _name = name;
    _date = date;
}
void Customer::setService(std::string _services){
    services.push_back(_services);
}
void Customer::setParts(std::string _parts){
    parts.push_back(_parts);
}
void Customer::setPayment(std::string _methods, double _amount){
    methods.push_back(_methods);
    amount.push_back(_amount);
}

void Customer::print(){
    std::cout << "Name: " << name << "\nDate: " << date << std::endl;
}

