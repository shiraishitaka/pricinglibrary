#include "DataLoader.h"

namespace Tools {

	struct DataLoader::Record {
		double gamma = 0.2807;
		double years = 5.0;
		double actual_vol = 0.1;
		double underlying_vol = 0.062;
		double mu = 0.02;
		double alpha = 0.08;
		double strike = 1.0;
		double actual_init_notional = 1.0;
		double underlying_init_notional = 1.0;
	};
}