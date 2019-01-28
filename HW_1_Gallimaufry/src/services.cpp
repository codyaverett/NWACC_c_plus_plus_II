// Cody Averett
// Gallimaufry HW_1

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "services.h"

namespace nwacc 
{

	void services::read_file(std::string file_name) 
	{
		std::ifstream file;

		try {

			file.open(file_name, std::ios_base::in);
			
			if(file.is_open()) 
			{
				std::cout << "file opened" << std::endl;
				std::string text;

				// Was used to count lines of the file and such.
				// Likely should be moved somewhere else.
				// int line_tally = 0;

				while(file.good()) 
				{

					std::getline(file, text);
					add_service_record(parse_csv_line(text));					
                
				}

			} else {

				throw "Could not open file: " + file_name;

			}

		} catch(std::string error) {

			std::cout << "ERROR: " + error << std::endl;

		}

		std::cout << "Finished reading file " << std::endl;
		file.close();
	}

	// TODO: share more code with purge_touch_file
	void services::append_to_file(std::string file_name, std::string content)
	{
		std::ofstream file;

		try {

			file.open(file_name, std::ios_base::app);

			if (file.is_open())
			{
				file << content << std::endl;
			}
			else {
				throw "Could not open file: " + file_name;
			}

		}
		catch (std::string error) {

			std::cout << "ERROR: " << error << std::endl;

		}

		file.close();
	}

	/**
	*  services::purge_touch_file
	*  
	*  Removes file contents if file exists, creates file if it doesn't exist
	*
	*  @params file_name : Name of file to be cleansed
	*/
	void services::purge_touch_file(std::string file_name)
	{
		std::ofstream file;

		try {

			file.open(file_name, std::ios_base::out);

			if (file.is_open()) 
			{
				file << "" << std::endl;
				std::cout << "Created File: " << file_name << std::endl;
			}
			else {
				throw "Could not open file: " + file_name;
			}

		}
		catch (std::string error) {

			std::cout << "ERROR: " << error << std::endl;

		}
		
		file.close();
	}

	service services::parse_csv_line(std::string& line)
	{
		std::istringstream ss(line);
		std::string token;

		std::string customer_name = "", service_type = "", date = "";
		double amount = 0.00;

		try
		{
			int index = 0;
			while (std::getline(ss, token, ',')) {
				
				switch (index++) 
				{

				case 0: // customer_name
					customer_name = token;
					break;

				case 1: // service_type
					service_type = token;
					break;

				case 3:	//date
					date = token;
					break;

				case 2: // amount
					amount = std::stod(token);
					break;

				case 4:
					throw "Malformed line from file: " + line;
				}
			}

			std::cout << token << std::endl;

		}
		catch (std::string error) {
			std::cout << error << std::endl;
		}


		return service( customer_name,
						service_type, 
						amount,
						date);

	}

	void services::add_service_record(service service_record) 
	{
		this->service_records.push_back(service_record);
	}

	/**
	*  services::create_reports_by_service_type
	*  The intention of this function is to create a maps by their service type
	*/
	void services::create_reports_by_service_type()	
	{
		std::map<std::string , std::vector<service>> services_map;
		int unique_service_count = 0;

		for (service s : this->service_records) {
			
			// Check if key already exists in the map
			if( services_map.find(s.service_type) == services_map.end() )
			{
				// Key was found
				services_map[s.service_type].push_back(s);
				unique_service_count++;
			}
			else {
				// Key was not found
				// Create the key and append the service
				services_map[s.service_type].push_back(s);

				// File should be cleansed for future additions
				purge_touch_file(s.service_type);
			}
			  
		}

		std::cout << "Unique Services : " << unique_service_count << std::endl;

		// Vector list of the unique service keys
		std::vector<std::string> service_types = get_map_keys(services_map);


		// WIP: Iterate over all files and generate report statistics
		for (std::string s : service_types)
		{
			std::cout << s;
			// append_to_file(s + ".txt", services_map[s]
				
				// TODO: Itterate over service vector to get all of a specific 
				// service type's data

				/*+ "\t"
				<< this->service_type << "\t"
				<< std::fixed << std::setprecision(2) << this->amount << "\t"
				<< this->date)*/
		}

		std::cout << "DONE reporting!" << std::endl;

	};

}