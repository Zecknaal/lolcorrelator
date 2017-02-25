#pragma once

#include <map>
#include <vector>
enum class SERVER_REGION{NORTH_AMERICA, BRAZIL, EUROPE_NORTHEAST, JAPAN, KOREA, LATIN_AMERICA_NORTH,
						 LATHIN_AMERICA_SOUTH, OCEANIA, RUSSIA, TURKEY};

enum class APIType{Champion, ChampionMastery, CurrentGame, FeaturedGames, Game, League,
				   StaticData, Status, Match, MatchList, Stats, Summoner };

typedef std::vector<std::string> apiParam;
typedef std::map<std::string, apiParam > urlParameters;

struct APIParameters{
	SERVER_REGION region;
	APIType api;
	urlParameters parameters;
	std::string key;
};