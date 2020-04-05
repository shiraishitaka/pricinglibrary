#pragma once
#include "LibObject.h"
#include "../HelperLib/DataLoader.cpp"

namespace Lib {

	struct Results {
		double rhos;
		int expiry_time;
		std::vector<double> prices;
	};

	class Engine : public LibObject {
	public:
		enum ResultType {
			Corr_Price
		};
	protected:
		Engine() : LibObject() {};
		virtual ~Engine() {};

		virtual void calculate() = 0;
		virtual std::vector<Results> getResults() const = 0;
	};
}