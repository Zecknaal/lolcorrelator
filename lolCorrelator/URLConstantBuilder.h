#pragma once

#include "URLConstantBuilderWrapper.h"
class URLConstantBuilder : public URLConstantBuilderWrapper {
	public:
		std::string mapRegionToPrefix(SERVER_REGION region) override{
			if (region == SERVER_REGION::BRAZIL)
				return std::string("br.api.pvp.net");
			else if (region == SERVER_REGION::EUROPE_NORTHEAST)
				return std::string("eune.api.pvp.net");
			else if (region == SERVER_REGION::JAPAN)
				return std::string("jp.api.pvp.net");
			else if (region == SERVER_REGION::KOREA)
				return std::string("kr.api.pvp.net");
			else if (region == SERVER_REGION::LATHIN_AMERICA_SOUTH)
				return std::string("las.api.pvp.net");
			else if (region == SERVER_REGION::LATIN_AMERICA_NORTH)
				return std::string("lan.api.pvp.net");
			else if (region == SERVER_REGION::NORTH_AMERICA)
				return std::string("na.api.pvp.net");
			else if (region == SERVER_REGION::OCEANIA)
				return std::string("oce.api.pvp.net");
			else if (region == SERVER_REGION::RUSSIA)
				return std::string("ru.api.pvp.net");
			else if (region == SERVER_REGION::TURKEY)
				return std::string("tr.api.pvp.net");
			else
				return std::string("regionnotfound");
		}

		std::string getPrefix() override{
			return "https://";
		}
};