#include "LibObject.h"

namespace Lib {

	void LibObject::initilize() {
		if (update_ == false) {
			update_ = true;
			initilize();
		}
	}

	//when call ->calculate()
	void LibObject::operator->() {
		this->initilize();
	}
}