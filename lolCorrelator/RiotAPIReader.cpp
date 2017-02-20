#include "RiotAPIReader.h"

RiotAPIReader::RiotAPIReader(SERVER_REGION region, CurlWrapper* curlWrapper){
	apiServerRegion = region;
	if (curlWrapper != nullptr)
		curl = curlWrapper;
	else
		curl = CurlFactory().createCurl();
}

RiotAPIReader::RiotAPIReader(SERVER_REGION region, const char * proxy){
	apiServerRegion = region;
	if (proxy != nullptr)
		curl = CurlFactory().createCurl(proxy);
	else
		curl = CurlFactory().createCurl();
}

const char * RiotAPIReader::callAPI(const char * url){
	return curl->sendCurl(url);
}
