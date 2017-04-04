#include "SummonerAPI.h"
#include "RiotAPIReader.h"
SummonerAPI::SummonerAPI(RiotAPIReaderWrapper* reader){
	if (reader == nullptr)
		apiReader = new RiotAPIReader(SERVER_REGION::NORTH_AMERICA , "http://proxy.cat.com:80");
	else
		apiReader = reader;
}

std::map<std::string, SummonerData> SummonerAPI::getSummonerName(APIParameters params, URLBuilderWrapper* urlBuilder){
	URLBuilderWrapper* url;
	if (urlBuilder == nullptr)
		url = new SummonerURLBuilder(params);
	else
		url = urlBuilder;
	
	auto apiResponse = apiReader->callAPI(url->getURL());
	JsonWrapper* json = JsonFactory().createJson(JsonParserType::Lohmann);
	json->parseJson(apiResponse.c_str());
	return apiReader->parseData<SummonerAPI, SummonerData>(apiResponse, params.parameters["summonerNames"], this, &SummonerAPI::parseJsonIntoSummonerData);
}

APIParameters SummonerAPI::setupByNameParams(){
	APIParameters params;
	std::vector<std::string> vec;

	vec.push_back("ByName");
	params.api = APIType::Summoner;
	params.parameters["Type"] = vec;

	return params;
}

SummonerData SummonerAPI::parseJsonIntoSummonerData(JsonWrapper * json){
	SummonerData summonerData;

	summonerData.id = stoi(json->read("id"));
	summonerData.name = json->read("name");
	summonerData.profileIconId = stoi(json->read("profileIconId"));
	summonerData.revisionDate = json->read("revisionDate");
	summonerData.summonerLevel = stoi(json->read("summonerLevel"));
	return summonerData;
}
