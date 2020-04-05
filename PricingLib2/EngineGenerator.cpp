#include "EngineGenerator.h"

namespace Lib {

	std::shared_ptr<Engine> generateEngine(ResultType result_type, std::shared_ptr<Tools::DataLoader::Record> record)
	{		
		switch (result_type) {
		case ResultType::Corr_Price: {
			auto engine_ptr = std::make_shared<PricerEngine>(record);
			return engine_ptr;
		}
		default:
			std::cout << "unknown_result_type" << std::endl;
		}
	};
}