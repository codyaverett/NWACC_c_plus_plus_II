// Cody Averett
// Gallimaufry HW_1

#ifndef SERVICES_H_
#define SERVICES_H_

#include <map>
#include <string>
#include <vector>

#include "service.h"

namespace nwacc 
{

	class services 
	{
	public:
		services() {};
		// filter_data();
			// a.Min sale
			// b.Max sale
			// c.Range of sales
			// d.Average of sales
		// get_stats();
		// ect.	
		void services::add_service_record(service service_record);

		template<typename K, typename V>
		std::vector<K> get_map_keys(std::map<K, V> const& input_map) {
			std::vector<K> retval;
			for (auto const& element : input_map) {
				std::cout << element.first << std::endl;
				retval.push_back(element.first);
			}
			return retval;
		}

		/**
		*  services::create_reports_by_service_type
		*  The intention of this function is to create a maps by their service type
		*/
		void services::create_reports_by_service_type();

		service services::parse_csv_line(std::string& line);

		void services::read_file(std::string file_name);

		void services::purge_touch_file(std::string file_name);
		void services::append_to_file(std::string file_name, std::string content);

	private:
		std::vector<service> service_records;
	};

}
#endif // SERVICES_H_