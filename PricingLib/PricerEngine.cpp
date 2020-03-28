#include "PricerEngine.h"
#include "RandomNumber.h"
#include "Math.h"
#include "../Helper/NameResolver.h"

namespace Lib {

	void PricerEngine::initialize() {
		using namespace Random;
		using namespace Helper::Path;
		//random path
		RandomParameter random_param;
		random_param.iteration_num = 1000;
		random_param.years = years_;
		random_param.separate_per_year = 365;
		auto random_numbers1 = createPath(random_param);
		auto random_numbers2 = createPath(random_param);

		for (const auto& vec_randompath :random_numbers1) {//iteration
			std::vector<double> temp_vec;
			double path = actual_init_notional_;
			for (const auto& random :vec_randompath) {//time
				path += mu_+ actual_vol_*random;
				temp_vec.emplace_back(path);
			}
			random_actual_paths_.emplace_back(temp_vec);
		}

		for (const auto& rho: rhos_) {//rho
			std::vector<std::vector<double>> temp_matrix;
			for (const auto& vec_randompath : random_numbers1) {//iteration
				std::vector<double> temp_vec;
				double path = underlying_init_notional_;
				for (const auto& random : vec_randompath) {//time
					auto dw = ;
					path += alpha_*dt + underlying_vol_*dw;
					temp_vec.emplace_back(path);
				}
				temp_matrix.emplace_back(temp_vec);
			}
			random_underlying_paths_.emplace_back(temp_matrix);
		}
	
	}

	void PricerEngine::calculate() {

		for (const auto& rho : rhos_) {
			auto random_under_path = random_underlying_paths_[rho];
			for (size_t t = ; t >= 0; t--) {

				auto wait_value = ;
				auto exe_value = Math::max(random_under_path[t][i] - strike_, 0.0);
				(exe_value > wait_value) ? exe_value : wait_value;



			}

			result->corr_prices
			results_.emplace(rho, result);
		}
	}

}