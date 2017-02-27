#pragma once

#include "JsonWrapper.h"
#include "jsonlohmann/json.hpp"

using json = nlohmann::json;

class JsonParser : public JsonWrapper{
	public:
		virtual std::string parseJson(const char* json) override;
		virtual std::string operator[](const std::string &element) override;
		virtual std::string read(std::string element) override;
		virtual std::string dump() override;
		//virtual JsonParser operator=(const char* json) override;
	protected:
		json jsonData;
};