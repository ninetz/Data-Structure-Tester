#pragma once
using namespace std;
#include "../structures/table/sorted_sequence_table.h"
#include "../structures/table/binary_search_tree.h"
#include "../structures/table/treap.h"
#include "TabulkaTester.h"
#include "../structures/structure.h"
#include "../structures/ds_structure_types.h"
#include "../structures/table/hash_table.h"
#include "../ZdegenerovanyBVSTester/TabulkaTesterZBVS.h"
#include <map>
#include "MapTester.h"
#include <unordered_map>
#include "UnorderedMapTester.h"
#include "../ZdegenerovanyBVSTester/TabulkaTesterZMap.h"
#include "TabulkaTesterVector.h"
#include <execution>

class Vyber {
private:
	int pomocna;

public:

	void input() {
		int x;
		cout << "Vyberte ktoru strukturu chcete testovat" << endl;
		cout << "0 - Sekvencne utriedena tabulka" << endl;
		cout << "1 - BVS" << endl;
		cout << "2 - treap" << endl;
		cout << "3 - Hash" << endl;
		cout << "4 - ZBVS" << endl;
		cout << "5 - Map" << endl;
		cout << "6 - UnorderedMap" << endl;
		cout << "7 - Zdegenerovane kluce pre map" << endl;
		cout << "8 - Vector" << endl;

		cin >> x;
		switch (x) {
		case 0: {
			vytvorSKUTest();
			break;
		}
		case 1: {
			vytvorBVSTest();
			break;
		}
		case 2: {
			vytvorTreapTest();
			break;
		}
		case 3: {
			vytvorHashTest();
			break;
		}
		case 4: {
			vytvorZdegenerovanyBVSTest();
			break;
		}
		case 5: {
			vytvorMapTest();
			break;
		}
		case 6: {
			vytvorUnorderedMapTest();
			break;
		}
		case 7: {
			vytvorZMapTest();
			break;
		}
		case 8: {
			vytvorVectorTest();
			break;
		}
		default:

			cout << "Taku strukturu nepoznam" << endl;

			input();

			break;
		}
	}

	void vytvorSKUTest() {
		TabulkaTester<int, int>* test = new TabulkaTester<int, int>;
		structures::Table<int, int>* tabPreTest = new structures::SortedSequenceTable<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorTreapTest() {
		TabulkaTester<int, int>* test = new TabulkaTester<int, int>;
		structures::Table<int, int>* tabPreTest = new structures::Treap<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorHashTest() {
		TabulkaTester<int, int>* test = new TabulkaTester<int, int>;
		structures::Table<int, int>* tabPreTest = new structures::HashTable<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->nastavPocetOperacii(400000);
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}

	void vytvorZdegenerovanyBVSTest() {
		TabulkaTesterZBVS<int, int>* test = new TabulkaTesterZBVS<int, int>;
		structures::Table<int, int>* tabPreTest = new structures::BinarySearchTree<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorBVSTest() {
		TabulkaTester<int, int>* test = new TabulkaTester<int, int>;
		structures::Table<int, int>* tabPreTest = new structures::BinarySearchTree<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->nastavPocetOperacii(400000);
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorMapTest() {
		MapTester<int, int>* test = new MapTester<int, int>;
		std::map<int, int>* tabPreTest = new std::map<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->nastavPocetOperacii(400000);
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorUnorderedMapTest() {
		UnorderedMapTester<int, int>* test = new UnorderedMapTester<int, int>;
		std::unordered_map<int, int>* tabPreTest = new std::unordered_map<int, int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		test->nastavPocetOperacii(400000);
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
	void vytvorZMapTest() {
			TabulkaTesterZMap<int, int>* test = new TabulkaTesterZMap<int, int>;
			std::map<int, int>* tabPreTest = new std::map<int, int>;

			test->vytvorTab(tabPreTest);
			cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
			cin >> pomocna;
			if (pomocna > 0 && pomocna < 4) {
				test->nastavScenar(pomocna);
			}
			else {
				cout << "Zle zadane!";
				input();
			}
			test->nastavPocetOperacii(100000);
			test->zacniTest();
			delete tabPreTest;
			delete test;
	}
	void vytvorVectorTest() {
		TabulkaTesterVector<int, int>* test = new TabulkaTesterVector<int, int>(0);
		std::vector<int>* tabPreTest = new std::vector<int>;

		test->vytvorTab(tabPreTest);
		cout << "Scenar A = 1, scenar B = 2, scenar C = 3" << endl;
		cin >> pomocna;
		if (pomocna > 0 && pomocna < 4) {
			test->nastavScenar(pomocna);
		}
		else {
			cout << "Zle zadane!";
			input();
		}
		cout << "Paralelizovana verzia = 1, neparalizovat = 0" << endl;
		cin >> pomocna;
		if (pomocna == 0 || pomocna == 1)
		{
			test->nastavParalelizaciu(pomocna);
		}
		test->nastavPocetOperacii(100000);
		test->zacniTest();
		delete tabPreTest;
		delete test;
	}
};