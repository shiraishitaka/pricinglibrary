#pragma once
#include "EngineGenerator.h"

namespace Lib {

	class PricerEngine : public Engine {
	public:
		PricerEngine(std::shared_ptr<Tools::DataLoader::Record> constant_param)
			: Engine(), 
			gamma_(constant_param->gamma),
			mu_(constant_param->mu),
			alpha_(constant_param->alpha),
			actual_vol_(constant_param->actual_vol),
			underlying_vol_(constant_param->underlying_vol),
			strike_(constant_param->strike),
			actual_init_notional_(constant_param->actual_init_notional),
			underlying_init_notional_(constant_param->underlying_init_notional){};
		~PricerEngine(){};

		void setRhos(std::vector<double> rhos) { rhos_ = rhos; };
		void calculate() override;
		template<typename T>
		T getResult() const override { return results_; };
	private:
		void initialize();

		std::vector<double> rhos_;
		std::unordered_map<double, std::shared_ptr<Results>> results_;
		std::vector<std::vector<double>> random_actual_paths_;
		std::vector<std::vector<std::vector<double>>> random_underlying_paths_;
		int years_;
		double alpha_;
		double mu_;
		double actual_vol_;
		double underlying_vol_;
		double strike_;
		double actual_init_notional_;
		double underlying_init_notional_;
		double gamma_;
	};

}