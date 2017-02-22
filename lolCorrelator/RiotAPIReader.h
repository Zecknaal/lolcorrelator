#pragma once

#include "RiotAPIReaderTypes.h"
#include "CurlWrapper.h"
#include "CurlFactory.h"
#include "JsonFactory.h"
#include "RiotAPIReaderWrapper.h"

class RiotAPIReader : public RiotAPIReaderWrapper {
	public:
		RiotAPIReader(SERVER_REGION region, CurlWrapper* curlWrapper, JsonWrapper* jsonWrapper);
		RiotAPIReader(SERVER_REGION region, const char*  proxy = nullptr);

		virtual std::string callAPI(const char* url) override;
	protected:
		CurlWrapper* curl;
		JsonWrapper* json;
		SERVER_REGION apiServerRegion;
};