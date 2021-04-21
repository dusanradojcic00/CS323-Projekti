#pragma once
#include <chrono>
#include <thread>

class Converter {
private:
public:
	static bool loading;	
	static double cryptoToFiat(const char* crypto,const char* fiat, double amount);
	static double fiatToCrypto(const char* fiat, const char* crypto, double amount);
	static double cryptoToCrypto(const char* crypto1, const char* crypto2, double amount);
};

