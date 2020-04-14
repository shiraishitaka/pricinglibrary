// Takahiro Shiraishi 2020/3/26

#include "Main.h"

int main()
{
	//market data 
	auto data_loader = std::make_shared<Tools::DataLoader>();
	const std::unique_ptr<Tools::DataLoader::Record>& constant_data = data_loader->getConstantParameter();
	auto rhos = data_loader->getRhos();

	//Lib‚É“n‚·
	auto engine = Lib::generateEngine(Lib::Engine::ResultType::Corr_Price, (std::unique_ptr<Tools::DataLoader::Record>&)constant_data);
	auto pricer_engine = std::dynamic_pointer_cast<Lib::PricerEngine>(engine);//mainŠÖ”‚Å‚ÍƒLƒƒƒXƒg‚Í‹–‚·
	pricer_engine->setRhos(rhos);
	//pricer_engine->initilize();
	pricer_engine->calculate();

	//output result 
	auto results = pricer_engine->getResults();
	for (const auto& result: results) {
		std::cout << "rho:" << result.rhos
			<< "price:" << result.prices[0]<< std::endl;
	}

	return 0;
}

