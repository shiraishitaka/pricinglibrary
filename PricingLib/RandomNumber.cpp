#include "RandomNumber.h"
#include "../Helper/AllStandardLib.h"

namespace Lib {
	namespace Random {

		std::vector<std::vector<double>> createPath(RandomParameter random_parameter) {
			std::vector<std::vector<double>> ret;
			std::vector<double> temp_vec;

			auto time_iteration_num = random_parameter.years*random_parameter.separate_per_year;
			for (size_t i = 0; i < random_parameter.iteration_num; i++) {
				for (size_t j = 0; j < time_iteration_num; j++) {
					double ran = ((double)rand() + 0.5) / (RAND_MAX + 1.0);
					temp_vec.emplace_back(ran);
				}
				ret.emplace_back(temp_vec);
			}
			return ret;
		}
	}
}