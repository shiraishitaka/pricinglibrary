#pragma once
#include "../LibExecution/DataLoader.cpp"
#include "LibObject.h"

namespace Lib {

	enum ResultType {
		Corr_Price
	};

	struct Results {
		int expiry_time;
		std::vector<double> prices;
	};

	class Engine : public LibObject {
	protected:
		Engine() : LibObject() {};
		virtual ~Engine() {};

		virtual void calculate() = 0;
		template<typename T>
		virtual T getResult() const = 0;
	};

	std::shared_ptr<Engine> generateEngine(ResultType result_type, std::shared_ptr<Tools::DataLoader::Record> record);
}
