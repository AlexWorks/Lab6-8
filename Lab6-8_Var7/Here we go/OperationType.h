#pragma once

enum Operation_Type {RETURN, EXTRACT};

class OperationType {
private:
	Operation_Type type;
public:
	OperationType(Operation_Type t = RETURN);
	OperationType(const OperationType& p);

	Operation_Type getType() const;
	void setType(Operation_Type t);
};
