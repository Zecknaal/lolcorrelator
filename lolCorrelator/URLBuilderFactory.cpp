#pragma once

#include "URLBuilderFactory.h"

URLBuilderWrapper * URLBuilderFactory::createURLBuilder(APIParameters parameters){
	URLBuilderWrapper* urlBuilder;
	if(parameters.api == APIType::Champion){
		urlBuilder = new ChampionURLBuilder(parameters);
	}
	else if (parameters.api == APIType::ChampionMastery) {
		urlBuilder = new ChampionMasteryURLBuilder(parameters);
	}
	else if (parameters.api == APIType::CurrentGame) {
		urlBuilder = new CurrentGameURLBuilder(parameters);
	}
	else if (parameters.api == APIType::FeaturedGames) {
		urlBuilder = new FeaturedGamesURLBuilder(parameters);
	}
	else if (parameters.api == APIType::Game) {
		urlBuilder = new GameURLBuilder(parameters);
	}
	else if (parameters.api == APIType::League) {
		urlBuilder = new LeagueURLBuilder(parameters);
	}
	else if (parameters.api == APIType::Match) {
		urlBuilder = new MatchURLBuilder(parameters);
	}
	else if (parameters.api == APIType::MatchList) {
		urlBuilder = new MatchListURLBuilder(parameters);
	}
	else if (parameters.api == APIType::StaticData) {
		urlBuilder = new StaticDataURLBuilder(parameters);
	}
	else if (parameters.api == APIType::Stats) {
		urlBuilder = new StatsURLBuilder(parameters);
	}
	else if (parameters.api == APIType::Status) {
		urlBuilder = new StatusURLBuilder(parameters);
	}
	else if (parameters.api == APIType::Summoner) {
		urlBuilder = new SummonerURLBuilder(parameters);
	}
	else{
		urlBuilder = new SummonerURLBuilder(parameters);
	}
	return urlBuilder;
}
