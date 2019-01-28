// Cody Averett
// Gallimaufry HW_1

#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>

#include "service.h"

namespace nwacc
{

	service::service(	std::string customer_name, 
						std::string service_type, 
						double amount, 
						std::string date )
	{
		this->customer_name = customer_name;
		this->service_type = service_type;
		this->amount = amount;
		this->date = date;
	}

	void service::print_details() 
	{
		std::cout << this->customer_name << "\t"
					<< this->service_type << "\t"
					<< std::fixed << std::setprecision(2) << this->amount << "\t"
					<< this->date
					<< std::endl;
	}

}

