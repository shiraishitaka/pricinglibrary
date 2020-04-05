#pragma once
#include "LibObject.h"

namespace Lib {

	enum ResultType {
		Corr_Price
	};

	struct Results {
		double rhos;
		int expiry_time;
		std::vector<double> prices;
	};

	class Engine : public LibObject {
	protected:
		Engine() : LibObject() {};
		virtual ~Engine() {};

		virtual void calculate() = 0;
		virtual std::vector<Results> getResults() const = 0;
	};
}