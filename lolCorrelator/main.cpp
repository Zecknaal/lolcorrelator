#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "RiotAPIReader.h"
#include "RiotAPIManager.h"

#pragma once

int main() {
	RiotAPIManager apiapi = RiotAPIManager();
	apiapi.readSummonerData();
	std::cin.get();
	return 0;
}