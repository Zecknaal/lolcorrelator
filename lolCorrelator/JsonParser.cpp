#include "JsonParser.h"

std::string JsonParser::parseJson(const char * json){
	std::map<std::string, std::string[]>* jsonMap = new std::map<std::string, std::string[]>;
	jsonData = json::parse(json);
	
	return std::string();
}

std::string JsonParser::operator[](const std::string &element){
	return read(element);
}

std::string JsonParser::read(std::string element){
	return jsonData[element].dump();
}

std::string JsonParser::dump(){
	return jsonData.dump();
}

//JsonParser JsonParser::operator=(const char * json){
//	jsonData = json::parse(json);
//	return *this;
//}
