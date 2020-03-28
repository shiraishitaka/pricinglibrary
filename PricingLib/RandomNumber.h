#pragma once
#include "LibObject.h"

namespace Lib {
	namespace Random {
		
		struct RandomParameter {
			int separate_per_year;
			int years;
			int iteration_num;
		};

		std::vector<std::vector<double>> createPath(RandomParameter random_parameter);
	}
}