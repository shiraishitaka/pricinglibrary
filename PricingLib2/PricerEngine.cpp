#include "PricerEngine.h"
#include "RandomNumber.h"
#include "Math.h"
#include "../HelperLib/NameResolver.h"

namespace Lib {

	PricerEngine::PricerEngine(std::shared_ptr<Tools::DataLoader::Record> constant_param)
		:Engine(),
		gamma_(constant_param->gamma),
		mu_(constant_param->mu),
		alpha_(constant_param->alpha),
		actual_vol_(constant_param->actual_vol),
		underlying_vol_(constant_param->underlying_vol),
		strike_(constant_param->strike),
		actual_init_notional_(constant_param->actual_init_notional),
		underlying_init_notional_(constant_param->underlying_init_notional)
	{
		using namespace Random;
		auto random_param = std::make_shared<RandomParameter>();
		random_param->iteration_num = 1000;
		random_param->years = years_;
		random_param->separate_per_year = 365;
		random_param->dt = 1.0 / ((double)random_param->separate_per_year);
		random_parameter_ = random_param;
	}

	void PricerEngine::initialize() {
		//using namespace Helper::Path;
		////random path
		//auto random_numbers1 = Random::createPath(random_parameter_);
		//auto random_numbers2 = Random::createPath(random_parameter_);
		//double dt = random_parameter_->dt;

		//for (const auto& vec_randompath :random_numbers1) {//iteration
		//	std::vector<double> temp_vec;
		//	double path = actual_init_notional_;
		//	for (const auto& random :vec_randompath) {//time
		//		path += mu_*dt + actual_vol_*std::sqrt(path)*random;//integrate SDE
		//		temp_vec.emplace_back(path);
		//	}
		//	random_actual_paths_.emplace_back(temp_vec);
		//}

		//for (const auto& rho: rhos_) {//rho
		//	std::vector<std::vector<double>> temp_matrix;
		//	for (size_t i = 0; i < random_parameter_->iteration_num; i++) {//iteration
		//		std::vector<double> temp_vec;
		//		double path = underlying_init_notional_;
		//		for (size_t t = 0; t < random_parameter_->separate_per_year* random_parameter_->years; t++) {//time
		//			auto dw1 = random_numbers1[i][t];
		//			auto dw2 = random_numbers2[i][t];
		//			auto dw = rho*dw1 + (1-rho*rho)*dw2;
		//			path += alpha_*dt + underlying_vol_*std::sqrt(path)*dw;//integrate SDE
		//			temp_vec.emplace_back(path);
		//		}
		//		temp_matrix.emplace_back(temp_vec);
		//	}
		//	random_underlying_paths_.emplace_back(temp_matrix);
		//}
	
	}

	void PricerEngine::calculate() {

//		for (const auto& rho : rhos_) {
//			auto random_under_path = random_underlying_paths_[rho];
//			std::vector<double> prices;
//			for (size_t t = years_ * random_parameter_->separate_per_year; t >= 0; t--) {//Œã‘Þ
//				for (size_t i = 0; i < random_parameter_->iteration_num ; i++) {
//
//					/*auto wait_value = ;
//					auto exe_value = Math::max(random_under_path[t][i] - strike_, 0.0);
//					prices[t] = (exe_value > wait_value) ? exe_value : wait_value;
//*/
//				}
//			}
			//Results result;
			//result.rhos = rho;
			////result.expiry_time = expiry_time;
			//result.prices = prices;
			//results_.emplace_back(result);
		//}
	}

}