#pragma once
#include "GeneralEngine.h"

namespace Lib {

	namespace Random {//‘O•ûéŒ¾
		struct RandomParameter;
	}

	class PricerEngine : public Engine {
	public:

		PricerEngine(const std::unique_ptr<Tools::DataLoader::Record>& constant_param);
		~PricerEngine() {};

		void setRhos(const std::vector<double> rhos) { rhos_ = rhos; };
		void calculate() override;
		
		std::vector<Results> getResults() const override { return results_; };
	private:
		void initialize();

		std::shared_ptr<Random::RandomParameter> random_parameter_;
		std::vector<double> rhos_;
		std::vector<Results> results_;
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