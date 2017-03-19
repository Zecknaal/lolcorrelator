#pragma once
#include <string>
#include <vector>

struct MatchListSingleData {
	std::string timestamp;
	int champion;
	std::string region;
	std::string queue;
	std::string season;
	std::string matchId;
	std::string role;
	std::string platformId;
	std::string lane;
};

struct MatchListData {
	int endIndex;
	std::vector<MatchListSingleData> matches;
	int startIndex;
	int	totalGames;
};