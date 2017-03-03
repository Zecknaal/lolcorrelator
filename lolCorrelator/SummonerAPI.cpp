#include "SummonerAPI.h"
#include "RiotAPIReader.h"
SummonerAPI::SummonerAPI(URLBuilderWrapper * builder){
}

std::map<std::string, std::string> SummonerAPI::getSummonerName(APIParameters params){
	RiotAPIReader api(SERVER_REGION::NORTH_AMERICA, "http://proxy.cat.com:80");
	//RiotAPIReader api(SERVER_REGION::NORTH_AMERICA);

	SummonerURLBuilder url(params);
	
	
	//return api.callAPI(url.getURL());
	return map<string, string>();
}
