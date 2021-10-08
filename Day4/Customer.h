#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<string>
#include<vector>

/*
    Date the customer visited
    Services performed ( at least 2 differnt services )
    Parts changed ( at least 2 different parts )
    Payment ( methods & amount )
*/

class Customer
{
    private:
        std::string name;
        std::string date;
        std::vector<std::string> services;
        std::vector<std::string> parts;
        std::vector<std::string> methods;
        std::vector<double> amount;
    public:
        Customer();
        ~Customer();
        void setCustomer(std::string _name, std::string _date);
        void setService(std::string _services);
        void setParts(std::string _parts);
        void setPayment(std::string _methods, double _amount);
        void print();

};

#endif