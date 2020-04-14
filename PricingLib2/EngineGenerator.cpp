#include "EngineGenerator.h"

namespace Lib {

	std::shared_ptr<Engine> generateEngine(const Engine::ResultType result_type, const std::unique_ptr<Tools::DataLoader::Record>& record)
	{		
		switch (result_type) {
		case Engine::ResultType::Corr_Price: {
			auto engine_ptr = std::make_shared<PricerEngine>((std::unique_ptr<Tools::DataLoader::Record>&)record);
			return engine_ptr;
		}
		default:
			std::cout << "unknown_result_type" << std::endl;
		}
	};
}