#pragma once

#include "RiotAPIReaderTypes.h"
#include "CurlWrapper.h"
#include "CurlFactory.h"
#include "JsonFactory.h"

class RiotAPIReader {
	public:
		RiotAPIReader(SERVER_REGION region, CurlWrapper* curlWrapper, JsonWrapper* jsonWrapper);
		RiotAPIReader(SERVER_REGION region, const char*  proxy = nullptr);

		std::string callAPI(const char* url);
	protected:
		CurlWrapper* curl;
		JsonWrapper* json;
		SERVER_REGION apiServerRegion;
};