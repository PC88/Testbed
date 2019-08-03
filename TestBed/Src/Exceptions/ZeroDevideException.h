#pragma once
#include "Exceptions\RuntimeException.h"
class ZeroDevideException :
	public RuntimeException
{
public:
	ZeroDevideException();
	virtual ~ZeroDevideException();
};

