#ifndef SERVICE_H
#define SERVICE_H
#endif

#include <iostream>

using namespace std;

class Service {

public:
    Service( string new_client_name, string new_service_type, double new_amount, string new_date);
    string to_string();

private:
    string client_name;
    string service_type;
    double amount;
    string date;

};