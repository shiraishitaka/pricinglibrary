#include "EngineGenerator.h"
#include "PricerEngine.h"

namespace Lib {

	std::shared_ptr<Engine> generateEngine(ResultType result_type, std::shared_ptr<Tools::DataLoader::Record> record) {
		std::shared_ptr<Engine> ret;
		
		switch (result_type) {
		case ResultType::Corr_Price: {
			ret = std::make_shared<PricerEngine>(record);
		}
		default:
			std::cout << "unknown_result_type" << std::endl;
		}
		return ret;
	};
}