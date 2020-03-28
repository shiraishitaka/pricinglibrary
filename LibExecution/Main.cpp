// Takahiro Shiraishi 2020/3/26

#include "Main.h"

int main()
{
	using namespace Lib;
	//market data 
	auto data_loader = std::make_shared<Tools::DataLoader>();
	auto constant_data = data_loader->getConstantParameter();
	auto rhos = data_loader->getRhos();

	//Libに渡す
	auto engine = generateEngine(ResultType::Corr_Price, constant_data);
	auto pricer_engine = std::dynamic_pointer_cast<PricerEngine>(engine);//main関数ではキャストは許す
	pricer_engine->setRhos(rhos);
	pricer_engine->calculate();

	//output result 
	auto prices = pricer_engine->getResult<std::unordered_map<double, std::shared_ptr<Results>>>();
	for (const auto& rho: rhos) {
		std::cout << "rho:" << rho
			<< "price:" << prices.at(rho)<< std::endl;
	}

	return 0;
}

