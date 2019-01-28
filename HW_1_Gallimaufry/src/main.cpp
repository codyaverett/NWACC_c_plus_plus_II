// Cody Averett
// Gallimaufry HW_1

#include <iostream>
#include <fstream>
#include <string>

#include "services.h"
#include "service.h"

using namespace std;

const string INPUT_FILE = "../Data.csv";

int main() {

	nwacc::services service_console; 

    service_console.read_file(INPUT_FILE);
	service_console.create_reports_by_service_type();

    return 0;
}