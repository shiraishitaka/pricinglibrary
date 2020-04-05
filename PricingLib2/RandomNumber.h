#pragma once
#include "LibObject.h"

namespace Lib {
	namespace Random {
		
		struct RandomParameter {
			int separate_per_year;
			int years;
			int iteration_num;
			double dt;
		};

		std::vector<std::vector<double>> createPath(std::shared_ptr<RandomParameter> random_parameter);
	}
}