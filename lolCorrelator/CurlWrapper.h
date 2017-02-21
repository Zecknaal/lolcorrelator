#pragma once

//The purpose of this interface is to allow me to abstract out the
//exact curl library that I use going forward, in case this project
//eventually needs to use a different library.
class CurlWrapper {
	public:
		virtual const char* sendCurl(const char* url) = 0;
		virtual void setupCurl(const char* proxy = nullptr) = 0;
};