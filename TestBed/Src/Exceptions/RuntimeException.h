#pragma once
#include "string"

class RuntimeException  // generic run-time exception
{

private:
	std::string errorMsg;
public:

	RuntimeException() {};
	RuntimeException(const std::string& err) { errorMsg = err; };
	std::string getMessage() const { return errorMsg; }

	virtual ~RuntimeException() { };
};

