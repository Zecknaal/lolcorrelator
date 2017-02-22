#pragma once

#include <map>
enum class SERVER_REGION{NORTH_AMERICA, BRAZIL, EUROPE_NORTHEAST, JAPAN, KOREA, LATIN_AMERICA_NORTH,
						 LATHIN_AMERICA_SOUTH, OCEANIA, RUSSIA, TURKEY};

enum class APIType{Champion, ChampionMastery, CurrentGame, FeaturedGames, Game, League,
				   StaticData, Status, Match, MatchList, Stats, Summoner };

struct APIParameters{
	SERVER_REGION region;
	APIType api;
	std::map<std::string, std::string> parameters;
	std::string key;
};