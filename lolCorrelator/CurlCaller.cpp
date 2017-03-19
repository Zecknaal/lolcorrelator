#include "CurlCaller.h"

size_t CurlCaller::writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

CurlCaller::CurlCaller(){
}

const char* CurlCaller::sendCurl(const char* url) {
	readBuffer.clear();
	curl_easy_cleanup(curl);
	setupCurl(httpProxy.c_str());
	CURLcode curlResult;
	if (url == nullptr || curl == nullptr)
		return nullptr;

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curlResult = curl_easy_perform(curl);
	return readBuffer.c_str();
}

void CurlCaller::setupCurl(const char * proxy){
	httpProxy = proxy;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlCaller::writeCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	if (proxy)
		curl_easy_setopt(curl, CURLOPT_PROXY, proxy);
}
