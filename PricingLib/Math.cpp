#include "Math.h"

namespace Lib {
	namespace Math {

		double fabs(double num) {
			return (num > 0.0) ? num : -num;
		}

		double max(double num1, double num2) {
			return (num1 > num2) ? num1 : num2;
		}

	}
}