// Cody Averett
// Gallimaufry HW_1

#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>

namespace nwacc {

	class service {
	public:
		service(std::string customer_name, std::string service_type, double amount, std::string date);
		
		void print_details();

		std::string customer_name = "", service_type = "", date = "";
		double amount = 0.00;
	};

}
#endif // SERVICE_H_
