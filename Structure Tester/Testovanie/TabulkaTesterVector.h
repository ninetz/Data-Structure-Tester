#pragma once
#include "../Testovanie/Merac.h"
#include "../Testovanie/Zapisovac.h"
#include "../Testovanie/Nahoda.h"
#include "../structures/structure.h"
#include "../structures/list/linked_list.h"
#include <execution>
template <typename K, typename T>
class TabulkaTesterVector {
private:

	std::vector<int>* tab;
	structures::ArrayList<int>* kluce;
	Merac* merac;
	Zapisovac* zap;
	Nahoda* nahoda;
	int pocOp = 100000;
	int pocNemoznychOperacii = 0;
	int kluceIndex = 1;
	int idemParalelizovat = 0;
	//void(TabulkaTesterVector::*vyberPtr)(void) = &TabulkaTesterVector::vyber;
	void(TabulkaTesterVector::* vyberPtr)(void);
	void(TabulkaTesterVector::* ukazPtr)(void);



public:
	void nastavParalelizaciu(int a) {
		idemParalelizovat = a;
		nastavPtrNaFunkcie();
	}
	void nastavPtrNaFunkcie() {
		if (idemParalelizovat == 0)
		{
			vyberPtr = &TabulkaTesterVector::vyber;
			ukazPtr = &TabulkaTesterVector::ukaz;
		}
		else {
			vyberPtr = &TabulkaTesterVector::vyberP;
			ukazPtr = &TabulkaTesterVector::ukazP;
		}

	}
	void pridajKluceDoAL() {
		kluce->add(kluceIndex);
		kluceIndex++;
	}
	void vymazKlucZAL(int ktory) {
		kluce->tryRemove(ktory);
	}
	int vratKlucZAL() {
		return kluce->operator[](nahoda->vratBetween(0, kluce->size() - 1));
	}
	void vytvorTab(std::vector<K>* pTab) {
		tab = pTab;
	}

	TabulkaTesterVector(int paralelizovane) {
		idemParalelizovat = paralelizovane;
		kluce = new structures::ArrayList<int>;
		tab = nullptr;
		merac = new Merac();
		zap = new Zapisovac();
		nahoda = new Nahoda();
		nastavPtrNaFunkcie();
	}
	~TabulkaTesterVector() {

		delete merac;
		delete zap;
		delete nahoda;
		delete kluce;
	}

	bool maPrvokPreMetodu() {

		if (tab->size() > 0 && kluce->size() > 0) {
			return true;
		}
		else {
			pocNemoznychOperacii++;
			return false;

		}
	}
	void zacniTest() {	
		merac->merajZacTestu();
		for (int i = 0; i < pocOp; i++)
		{

			switch (nahoda->vygenerujKtoruMetodu())
			{
			case 0:
				vloz();
				break;
			case 1:
				if (maPrvokPreMetodu()) {
					(this->*ukazPtr)();
				}
				break;
			case 2:
				if (maPrvokPreMetodu() ) {
					(this->*vyberPtr)();
				}
				break;
			default:
				break;
			}
		}
		merac->merajKonTestu();
		zap->zapisDoSuboru(".\\vysledky\\celkovycas.csv", merac->celkovyCasTestu());
		zap->zapisDoSuboru(".\\vysledky\\pocNemoznych.csv", pocOp, pocNemoznychOperacii);

	}
	void vloz() {
		merac->merajZac();
		tab->push_back(kluceIndex);
		merac->merajKon();
		pridajKluceDoAL();
		zap->zapisDoSuboru(".\\vysledky\\insert.csv", merac->celkovyCas(), tab->size());

	}
	void vyber() {
		int vymaz = vratKlucZAL();
		merac->merajZac();
		tab->erase(std::remove(tab->begin(),tab->end(),vymaz));
		merac->merajKon();
		vymazKlucZAL(vymaz);
		zap->zapisDoSuboru(".\\vysledky\\remove.csv", merac->celkovyCas(), tab->size());
	}
	void vyberP() {
		int vymaz = vratKlucZAL();
		merac->merajZac();
		tab->erase(std::remove(std::execution::par,tab->begin(), tab->end(), vymaz));
		merac->merajKon();
		vymazKlucZAL(vymaz);
		zap->zapisDoSuboru(".\\vysledky\\remove.csv", merac->celkovyCas(), tab->size());
	}
	
	void ukaz() {
		T* a = new T;
		int klucNaUkaz = vratKlucZAL();
		merac->merajZac();
		std::find(tab->begin(), tab->end(), klucNaUkaz);
		merac->merajKon();
		zap->zapisDoSuboru(".\\vysledky\\peek.csv", merac->celkovyCas(), tab->size());
		delete a;
	}
	void ukazP() {
		T* a = new T;
		int klucNaUkaz = vratKlucZAL();
		merac->merajZac();
		std::find(std::execution::par, tab->begin(), tab->end(), klucNaUkaz);
		merac->merajKon();
		zap->zapisDoSuboru(".\\vysledky\\peek.csv", merac->celkovyCas(), tab->size());
		delete a;
	}

	void nastavScenar(int ktory) {
		switch (ktory) {
		case 1:
			nahoda->nastavVazPrav(30, 60, 10);
			break;
		case 2:
			nahoda->nastavVazPrav(45, 10, 45);
			break;
		case 3:
			nahoda->nastavVazPrav(10, 85, 5);
			break;
		}
	}

	void nastavPocetOperacii(int p) {
		pocOp = p;
	}
};
	