#include "Converter.h"
#include "Util.h"

bool Converter::loading = false;

double Converter::cryptoToFiat(const char* crypto,const char* fiat, double amount)
{
    Converter::loading = true;
    double rate = Util::cryptoToFiat(crypto, fiat);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Converter::loading = false;
    return amount * rate;
}

double Converter::fiatToCrypto(const char* fiat, const char* crypto, double amount)
{
    Converter::loading = true;
    double rate = Util::cryptoToFiat(crypto, fiat);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Converter::loading = false;
    return amount / rate;
}

double Converter::cryptoToCrypto(const char* crypto1, const char* crypto2, double amount)
{
    Converter::loading = true;
    double rate = Util::cryptoToCrypto(crypto1, crypto2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Converter::loading = false;
    return amount * rate;
}
