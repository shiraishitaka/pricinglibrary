#pragma once
#include "../Helper/AllStandardLib.h"

namespace Lib {

	class LibObject {
	protected:
		LibObject() : update_(false) {};
		virtual ~LibObject() {};

		void operator->();
		bool update_;
	public:
		void initilize();
	};
}
