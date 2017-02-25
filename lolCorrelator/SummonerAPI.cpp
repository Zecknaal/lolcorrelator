#include "SummonerAPI.h"
SummonerAPI::SummonerAPI(URLBuilderWrapper * builder){
}

std::string SummonerAPI::getSummonerName(APIParameters params){

	SummonerURLBuilder url(params);
	return url.getURL();
}
