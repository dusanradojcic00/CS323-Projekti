#pragma once
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <iostream>

#include "Converter.h"
using namespace std;
class Util {
private:
	const static string API_KEY;
	const static string DEFAULT_URL;
public:
	static double cryptoToFiat(string crypto, string fiat);
	static double cryptoToCrypto(string crypto1, string crypto2);
};

