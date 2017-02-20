#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "RiotAPIReader.h"

using json = nlohmann::json;

#pragma once

int main() {
	std::string url = "https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/Zecknaal?api_key=cf493893-d798-47e2-997f-adced88d62b9";

	CURL* curl;
	CURLcode res;
	curl = curl_easy_init();
	std::string readBuffer;

	if (1 == 2) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		//Gotta find a better way to do this so home/work development don't kill each other. Probably non-replicated config file
		curl_easy_setopt(curl, CURLOPT_PROXY, "http://proxy.cat.com:80");

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		json j = json::parse(readBuffer.c_str());
		for (auto& element : j["zecknaal"]) {
			std::cout << element << std::endl;
		}

		RiotAPIReader apiReader(SERVER_REGION::NORTH_AMERICA);
	}
	RiotAPIReader api(SERVER_REGION::NORTH_AMERICA, "http://proxy.cat.com:80");
	std::cout << api.callAPI(url.c_str());
	std::cin.get();
	return 0;
}