#include <iostream>
#include "service.h"

using namespace std;

Service::Service(string new_client_name, string new_service_type, double new_amount, string new_date) {
    client_name = new_client_name;
    service_type = new_service_type;
    amount = new_amount;
    date = new_date;
}

string Service::to_string() {
    return client_name + "\t" + service_type + "\t" + amount + "\t" + date;
}