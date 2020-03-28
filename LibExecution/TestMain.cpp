// Takahiro Shiraishi 2020/3/26

#include "TestMain.h"
#include "../PricingLib/PricingEngine.h"
#include "../

int main()
{
	//market data 
	auto data_loader = std::make_shared<Tools::DataLoader>();
	auto constant_data = data_loader->getConstantParameter();

	//Lib‚É“n‚·
	auto result = calculateResult(Lib::ResultType::Corr_Prices, constant_data);

	//output result 
	for (size_t i = -100; i <= 100; i++) {
		auto corr = ((double)i) / 100.0;
		std::cout<<"corr:"<< corr
			<< "price:"<<result->corr_prices.at(corr)<<std::endl;
	}

	return 0;
}

