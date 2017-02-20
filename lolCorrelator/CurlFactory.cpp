#include "CurlFactory.h"
#pragma once

CurlWrapper* CurlFactory::createCurl(const char * proxy){
	CurlWrapper* curl = new CurlCaller();
	curl->setupCurl(proxy);

	return curl;
}
