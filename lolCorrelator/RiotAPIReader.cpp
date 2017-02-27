#include "RiotAPIReader.h"

RiotAPIReader::RiotAPIReader(SERVER_REGION region, CurlWrapper* curlWrapper, JsonWrapper* jsonWrapper){
	apiServerRegion = region;
	curl = curlWrapper;
	json = jsonWrapper;
}

RiotAPIReader::RiotAPIReader(SERVER_REGION region, const char * proxy){
	apiServerRegion = region;
	if (proxy != nullptr)
		curl = CurlFactory().createCurl(proxy);
	else
		curl = CurlFactory().createCurl();

	json = JsonFactory().createJson(JsonParserType::Lohmann);
}

std::string RiotAPIReader::callAPI(std::string url){
	json->parseJson(curl->sendCurl(url.c_str()));
	//std::cout << json->read("zecknaal") << std::endl;
	//return curl->sendCurl(url.c_str());
	return json->dump();
}
