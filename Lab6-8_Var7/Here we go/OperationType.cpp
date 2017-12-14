#include "OperationType.h"

OperationType::OperationType(Operation_Type t) : type(t) {}
OperationType::OperationType(const OperationType& p) { type = p.type; }

Operation_Type OperationType::getType() const {
	return type;
}

void OperationType::setType(Operation_Type t) {
	type = t;
}