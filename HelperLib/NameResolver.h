#pragma once
#include "AllStandardLib.h"

//function factory
#define NameResolver(func_name, ret) std::string name##func_name() { return ret;} 

namespace Helper {

	namespace Param {
		NameResolver(Gamma, "GAMMA");
		NameResolver(Time, "TIME");
		NameResolver(Volatility, "VOLATILITY");
		NameResolver(Mu, "MU");
		NameResolver(Strike, "STRIKE");
		NameResolver(InitialActualNotional, "INITIALACTUALNOTIONAL");
		NameResolver(InitialUnderlyingNotional, "INITIALUNDERLYINGNOTIONAL");
	}

	namespace Path {
		NameResolver(Actual, "ACTUAL");
		NameResolver(Underlying, "UNDERLYING");
	}

	namespace Result {
		NameResolver(Corr, "CORR");
		NameResolver(Price, "PRICE");
	}
}

