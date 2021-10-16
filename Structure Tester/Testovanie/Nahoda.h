#pragma once
#include <random>
#include "structures/heap_monitor.h"
class Nahoda {
public:
	// http://www.cplusplus.com/reference/random/discrete_distribution/
	// http://www.cplusplus.com/reference/random/uniform_int_distribution/
	// https://en.cppreference.com/w/cpp/numeric/random/random_device
	// 	https://www.cplusplus.com/reference/random/default_random_engine/
	//void testFuncknosti() {
	//	const int nrolls = 100000; // number of experiments
	//

	//	std::default_random_engine generatorr;
	//	std::discrete_distribution<int> distributionn{50,10,20,20};
	//	int vloz = 0;
	//	int zrus = 0;
	//	int nastav = 0;
	//	int index = 0;
	//	for (int i = 0; i < nrolls; i++)
	//	{
	//		int c = distributionn(generatorr);
	//		switch (c) {
	//		case 0:
	//			vloz++;
	//			break;
	//		case 1:
	//			zrus++;
	//			break;
	//		case 2:
	//			nastav++;
	//			break;
	//		case 3:
	//			index++;
	//			break;
	//
	//		}
	//	}

	//
	//	cout << vloz << endl;
	//	cout << zrus << endl;
	//	cout << nastav << endl;
	//	cout << index << endl;
	//}

	Nahoda() {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		e = 0;
		f = 0;
		g = 0;
		h = 0;
		j = 0;
		generator.seed(s());
	};
	~Nahoda() {
	}
	void nastavVazPrav(double pa, double pb, double pc, double pd, double pe, double pf, double pg, double ph, double pj) {
		a = pa / 3;
		b = pb / 3;
		c = pc / 3;
		d = pd / 3;
		e = pe / 3;
		f = pf / 3;
		g = pg / 2;
		h = ph / 2;
		j = pj / 1;
		distributionn = { a,b,c,d,e,f,g,h,j };
	}
	void nastavVazPrav(double pa, double pb, double pc, double pd, double pe, double pf, double pg, double ph) {
		a = pa;
		b = pb;
		c = pc;
		d = pd;
		e = pe;
		f = pf;
		g = pg;
		h = ph;

		distributionn = { a,b,c,d,e,f,g,h };
	}
	void nastavVazPrav(double pa, double pb, double pc) {
		a = pa;
		b = pb;
		c = pc;
		distributionn = { a,b,c };
	}
	void nastavVazPrav(double pa, double pb) {
		a = pa;
		b = pb;

		distributionn = { a,b };
	}
	int vygenerujKtoruMetodu() {
		return distributionn(generator);
	}
	int vratBetween(int pa, int pb) {
		if (pb <= 0) {
			return 0;
		}
		std::uniform_int_distribution<int> dist(pa, pb);
		return dist(s);
	}
	void zapisData(Zapisovac* z) {
		z->zapisDoSuboru(".\\vysledky\\pocNemoznych.csv", s());
	}
private:
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	double g;
	double h;
	double j;
	std::discrete_distribution<int> distributionn;
	std::default_random_engine generator;
	std::random_device s;
};