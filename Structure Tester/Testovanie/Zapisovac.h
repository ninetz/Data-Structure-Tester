#pragma once
#include <cstdio>
#include <string>
#include <fstream>
#include "structures/heap_monitor.h"
using namespace std;
class Zapisovac {
private:
	ofstream zap;
	ifstream citac;
	fstream stream;
	int index{};
public:
	Zapisovac() = default;
	void zapisDoSuboru(string nazov, double totalCas, double pocetPrvkov) {
		zap.open(nazov, ios::app);
		zap << totalCas << "," << pocetPrvkov << endl;
		zap.close();
	}
	void zapisDoSuboru(string nazov, double totalCas, double pocetPrvkov, double index) {
		zap.open(nazov, ios::app);
		zap << totalCas << "," << pocetPrvkov << "," << index << endl;
		zap.close();
	}
	void zapisDoSuboru(string nazov, double cislo) {
		zap.open(nazov, ios::app);
		zap << cislo << endl;
		zap.close();
	}
	void zapisDoSuboru(string nazov, string veci, double cislo) {
		zap.open(nazov, ios::app);
		zap << veci << cislo << endl;
		zap.close();
	}
	void zapisScenar(int pocet, double pa, double pb, double pc, double pd, double pe, double pf, double pg, double ph, double pj) {
		zap.open(".\\testy\\uzivatelskeScenare.csv", ios::app);
		zap << pocet << "," << pa << "," << pb << "," << pc << "," << pd << "," << pe << "," << pf << "," << pg << "," << ph << "," << pj << endl;
		zap.close();
	}
	void vypisScenare() {
		index = 1;
		citac.open(".\\testy\\uzivatelskeScenare.csv");
		string line;
		while (getline(citac, line)) {
			cout << line << index << endl;
			index++;
		}
		citac.close();
	}
	vector<int>* posliScenar(int pIndex) {
		vector<int>* vysledny = new vector<int>;
		string cislo;
		index = 1;
		citac.open(".\\testy\\uzivatelskeScenare.csv");
		string line;
		while (getline(citac, line)) {
			if (index = pIndex) {
				stringstream ss(line);
				while (getline(ss, cislo, ',')) {
					vysledny->push_back(stoi(cislo));
				}
			}
			index++;
		}
		return vysledny;
		citac.close();
	}
	bool suborScenareNeexistuje() {
		stream.open(".\\testy\\uzivatelskeScenare.csv");
		return stream.fail();
	}
	~Zapisovac() {
	}
};