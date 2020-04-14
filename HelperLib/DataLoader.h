#pragma once
#include "AllStandardLib.h"

namespace Tools {

	class DataLoader {
	public:
		struct Record;
		DataLoader();
		~DataLoader() {};

		const std::unique_ptr<Record>& getConstantParameter();
		std::vector<double> getRhos() { return rhos_; }
	private:
		std::vector<double> rhos_{ -1.0, -0.5, -0.25, 0.0, 0.25, 0.5, 1.0 };
		std::unique_ptr<Record> record_;
	};

}