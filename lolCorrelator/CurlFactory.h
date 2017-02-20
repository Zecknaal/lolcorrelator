#pragma once

#include "CurlCaller.h"

class CurlFactory {
public:
	CurlWrapper* createCurl(const char* proxy = nullptr);
};