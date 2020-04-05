#pragma once
#include "PricerEngine.cpp"

namespace Lib {

	std::shared_ptr<Engine> generateEngine(Engine::ResultType result_type, std::shared_ptr<Tools::DataLoader::Record> record);
}
