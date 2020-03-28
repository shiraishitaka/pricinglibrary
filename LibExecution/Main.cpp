// Takahiro Shiraishi 2020/3/26

#include "Main.h"

int main()
{
	using namespace Lib;
	//market data 
	auto data_loader = std::make_shared<Tools::DataLoader>();
	auto constant_data = data_loader->getConstantParameter();
	auto rhos = data_loader->getRhos();

	//Lib‚É“n‚·
	auto engine = generateEngine(ResultType::Corr_Price, constant_data);
	auto pricer_engine = std::dynamic_pointer_cast<PricerEngine>(engine);//mainŠÖ”‚Å‚ÍƒLƒƒƒXƒg‚Í‹–‚·
	pricer_engine->setRhos(rhos);
	pricer_engine->calculate();

	//output result 
	auto prices = pricer_engine->getResult<std::unordered_map<double, std::shared_ptr<Results>>>();
	for (const auto& rho: rhos) {
		std::cout << "rho:" << rho
			<< "price:" << prices.at(rho)->prices[0]<< std::endl;
	}

	return 0;
}

