#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "RiotAPIReaderTypes.h"
#include "CurlWrapper.h"
#include "CurlFactory.h"
#include "jsonlohmann/json.hpp"

class RiotAPIReader {
	public:
		RiotAPIReader(SERVER_REGION region, CurlWrapper* curlWrapper);
		RiotAPIReader(SERVER_REGION region, const char*  proxy = nullptr);

		const char* callAPI(const char* url);
	protected:
		CurlWrapper* curl;
		SERVER_REGION apiServerRegion;
};