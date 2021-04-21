#include <stdio.h>
#include <iostream>
#include "Converter.h"
#include "Consts.h"
#include <thread>
#include <future>
#include <iomanip>
#include <locale>
using namespace std;

void cryptoToFiat();
void fiatToCrypto();
void cryptoToCrypto();
const char* getCrypto();
const char* getFiat();

int main() {
	int n = 0;
	while (n != -1) {
		cout << "_______________________\n" << endl;
		cout << "Odaberite opciju:" << endl;
		cout << "1\tKripto u fiat" << endl;
		cout << "2\tFiat u kripto" << endl;
		cout << "3\tKripto u kripto" << endl;
		cout << "_______________________" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cryptoToFiat();
			break;
		case 2:
			fiatToCrypto();
			break;
		case 3:
			cryptoToCrypto();
			break;
		default:
			n = -1;
			break;
		}
	}

	return 0;
}

void cryptoToFiat() {
	const char* cryptoSymbol = getCrypto();
	const char* fiatSymbol = getFiat();
	
	int kolicina;
	cout << "Unesite kolicinu koju zelite da promenite: ";
	cin >> kolicina;

	auto future = async(Converter::cryptoToFiat, cryptoSymbol, fiatSymbol, kolicina);
	double result = -1.0;
	cout << "Vas rezultat je:" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	while (Converter::loading) {
		printf("\rLoading...         ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading......      ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading.........   ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	printf("\r                        \n");
	result = future.get();
	cout.imbue(locale(""));
	cout << fixed << setprecision(2) << result << endl;
	
}

void fiatToCrypto()
{
	const char* fiatSymbol = getFiat();
	const char* cryptoSymbol = getCrypto();
	

	int kolicina;
	cout << "Unesite kolicinu koju zelite da promenite: ";
	cin >> kolicina;


	auto future = async(Converter::fiatToCrypto, fiatSymbol, cryptoSymbol, kolicina);
	double result = -1.0;
	cout << "Vas rezultat je:" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	while (Converter::loading) {
		printf("\rLoading...         ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading......      ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading.........   ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	printf("\r                        \n");

	result = future.get();
	cout << result << endl;
}

void cryptoToCrypto()
{
	const char* cryptoSymbol1 = getCrypto();
	const char* cryptoSymbol2 = getCrypto();

	int kolicina;
	cout << "Unesite kolicinu koju zelite da promenite: ";
	cin >> kolicina; 

	auto future = async(Converter::cryptoToCrypto, cryptoSymbol1, cryptoSymbol2, kolicina);
	double result = -1.0;
	cout << "Vas rezultat je:" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	while (Converter::loading) {
		printf("\rLoading...         ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading......      ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		printf("\rLoading.........   ");
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	printf("\r                        \n");

	result = future.get();
	cout.imbue(locale(""));
	cout << fixed << setprecision(2) << result << endl;
}

const char* getCrypto()
{
	int i = 0;
	cout << "Odaberite kripto valutu: " << endl;
	cout << "1\tBTC" << endl << "2\tETH" << endl << "3\tBNB" << endl << "4\tXRP" << endl << "5\tLTC" << endl;
	cin >> i;
	const char* cryptoSymbol = new char[4];
	switch (i)
	{
	case 1:
		cryptoSymbol = crypto::BTC;
		break;
	case 2:
		cryptoSymbol = crypto::ETH;
		break;
	case 3:
		cryptoSymbol = crypto::BNB;
		break;
	case 4:
		cryptoSymbol = crypto::XRP;
		break;
	case 5:
		cryptoSymbol = crypto::LTC;
		break;
	default:
		break;
	}
	return cryptoSymbol;
}

const char* getFiat()
{
	int i = 0;
	cout << "Odaberite fiat valutu: " << endl;
	cout << "1\tUSD" << endl << "2\tEUR" << endl << "3\tRSD" << endl;
	cin >> i;
	const char* fiatSymbol = new char[4];
	switch (i)
	{
	case 1:
		fiatSymbol = fiat::USD;
		break;
	case 2:
		fiatSymbol = fiat::EUR;
		break;
	case 3:
		fiatSymbol = fiat::RSD;
		break;;
	default:
		break;
	}
	return fiatSymbol;
}
