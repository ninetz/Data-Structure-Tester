#pragma once
#include <chrono>
#include <iostream>

// http://www.cplusplus.com/reference/chrono/steady_clock/now/
class Merac {
private:
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;
	std::chrono::high_resolution_clock::time_point f1;
	std::chrono::high_resolution_clock::time_point f2;

public:
	void merajZacTestu() {
		f1 = std::chrono::high_resolution_clock::now();
	}
	void merajZac() {
		t1 = std::chrono::high_resolution_clock::now();
	}
	void merajKon() {
		t2 = std::chrono::high_resolution_clock::now();
	}
	void merajKonTestu() {
		f2 = std::chrono::high_resolution_clock::now();
	}
	double celkovyCasTestu() {
		auto f3 = std::chrono::duration_cast<std::chrono::nanoseconds>(f2 - f1);
		return std::chrono::duration<double>(f3).count();
	}
	double celkovyCas() {
		auto t3 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
		return std::chrono::duration<double>(t3).count();
	}
};
