#pragma once
#include "PricerEngine.cpp"

namespace Lib {

	std::shared_ptr<Engine> generateEngine(const Engine::ResultType result_type, const std::unique_ptr<Tools::DataLoader::Record>& record);
}
