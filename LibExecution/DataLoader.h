#pragma once
#include "../Helper/AllStandardLib.h"

namespace Tools {

	class DataLoader {
	public:
		DataLoader() :record_(std::make_shared<Record>()){};
		struct Record;
		std::shared_ptr<Record> getConstantParameter() { return record_; };
		std::vector<double> getRhos() { return rhos_; }
	private:
		std::vector<double> rhos_{-1.0, -0.5, -0.25, 0.0, 0.25, 0.5, 1.0 };
		std::shared_ptr<Record> record_;
	};
}