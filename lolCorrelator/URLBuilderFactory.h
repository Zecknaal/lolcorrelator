#pragma once

//Stuff that I am gonna build in the factory
#include "URLBuilderWrapper.h"
#include "ChampionMasteryURLBuilder.h"
#include "ChampionURLBuilder.h"
#include "CurrentGameURLBuilder.h"
#include "FeaturedGamesURLBuilder.h"
#include "GameURLBuilder.h"
#include "LeagueURLBuilder.h"
#include "MatchListURLBuilder.h"
#include "MatchURLBuilder.h"
#include "StaticDataURLBuilder.h"
#include "StatsURLBuilder.h"
#include "StatusURLBuilder.h"
#include "SummonerURLBuilder.h"

class URLBuilderFactory {
	URLBuilderWrapper* createURLBuilder(APIParameters parameters);
	protected:
		URLConstantBuilder* constantBuilder;
};