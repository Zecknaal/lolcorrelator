#include "JsonParser.h"

void JsonParser::parseJson(const char * json){
	std::map<std::string, std::string[]>* jsonMap = new std::map<std::string, std::string[]>;
	jsonData = json::parse(json);
	
	//return jsonData.dump();
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

std::vector<std::string> JsonParser::dumpByElement(std::string element){
	std::vector<std::string> elements;
	for (auto& element : jsonData[element]) {
		elements.push_back(element.dump());
	}
	return elements;
}

std::map<std::string, std::string> JsonParser::extractValuesByElement(std::string element, std::vector<std::string> key){
	std::map<std::string, std::string> data;
	for (auto& entry : key) {
		data[key.data()->c_str()] = jsonData[key.data()->c_str()].dump();
	}
	return data;
}

//JsonParser JsonParser::operator=(const char * json){
//	jsonData = json::parse(json);
//	return *this;
//}
