#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
//#include "C:/Users/Zeck/Documents/Visual Studio 2015/Projects/lolCorrelator/External Libraries/curl/include/curl/curl.h"
#include "curl/include/curl/curl.h"
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
#include "jsonlohmann/json.hpp"
#include "RiotAPIReader.h"

using json = nlohmann::json;

#pragma once

size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}//

int main() {
	std::string url = "https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/Zecknaal?api_key=cf493893-d798-47e2-997f-adced88d62b9";

	CURL* curl;
	CURLcode res;
	curl = curl_easy_init();
	std::string readBuffer;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		json j = json::parse(readBuffer.c_str());
		for (auto& element : j["zecknaal"]) {
			std::cout << element << std::endl;
		}

		RiotAPIReader apiReader;
	}
	std::cin.get();
	return 0;
}