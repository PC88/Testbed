#pragma once
#include "Exceptions\RuntimeException.h"
class NegativeRootException :
	public RuntimeException
{
public:
	NegativeRootException();
	virtual ~NegativeRootException();
};

