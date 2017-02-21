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

std::string RiotAPIReader::callAPI(const char * url){
	json->parseJson(curl->sendCurl(url));
	//return nullptr;
	//for (auto& a : json->parseJson(curl->sendCurl(url)))
		//std::cout << a.second << std::endl;
	//std::string str = json["test"];
	std::cout << json->read("zecknaal") << std::endl;
	//std::string str = json[*t];
	//std::cout << str << std::endl;
	return curl->sendCurl(url);
}
