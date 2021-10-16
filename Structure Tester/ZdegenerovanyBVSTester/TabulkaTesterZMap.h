#pragma once
#include "../Testovanie/Merac.h"
#include "../Testovanie/Zapisovac.h"
#include "../Testovanie/Nahoda.h"
#include "../structures/structure.h"
#include "../structures/list/linked_list.h"
template <typename K, typename T>
// Tester kde BVS zdegeneruje.
class TabulkaTesterZMap {
private:

	std::map<K, T>* tab;
	structures::ArrayList<int>* kluce;
	Merac* merac;
	Zapisovac* zap;
	Nahoda* nahoda;
	int pocOp = 100000;
	int pocNemoznychOperacii = 0;
	int kluceIndex = 1;


public:
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
	void vytvorTab(std::map<K, T>* pTab) {
		tab = pTab;
	}

	TabulkaTesterZMap() {
		kluce = new structures::ArrayList<int>;
		tab = nullptr;
		merac = new Merac();
		zap = new Zapisovac();
		nahoda = new Nahoda();
	}
	~TabulkaTesterZMap() {

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
					ukaz();
				}
				break;
			case 2:
				if (maPrvokPreMetodu() ) {
					vyber();
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
		tab->insert({ kluceIndex, kluceIndex });
		merac->merajKon();
		pridajKluceDoAL();
		zap->zapisDoSuboru(".\\vysledky\\insert.csv", merac->celkovyCas(), tab->size());

	}
	void vyber() {
		int vymaz = vratKlucZAL();
			merac->merajZac();
			tab->erase(vymaz);
			merac->merajKon();
			vymazKlucZAL(vymaz);
			zap->zapisDoSuboru(".\\vysledky\\remove.csv", merac->celkovyCas(), tab->size());
	}
	
	void ukaz() {
		T* a = new T;
		int klucNaUkaz = vratKlucZAL();
		merac->merajZac();
		tab->find(klucNaUkaz);
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
	