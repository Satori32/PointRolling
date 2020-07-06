#include <iostream>
#include <cmath>
#include <tuple>
#include <thread>

#include "EscapeSequence.h"

template<class T>
std::tuple<T, T> Rolling(const std::tuple<T,T>& Origin,const T& L, const T& Angle) {
	T Rad = 3.141592 / 180.0;

	T X = std::sin(Rad * Angle)*L;
	T Y = std::cos(Rad * Angle)*L;

	return { X + std::get<0>(Origin),Y + std::get<1>(Origin) };
}

int main() {

	SetDisplayMode();

	ESS::ClearShow();

	for (std::size_t i = 0; i < 360*3; i++) {
		auto P = Rolling<double>({ 16,16 }, 8, i);
		ESS::ClearShow();
		ESS::Locate(1, 1);
		std::cout << std::get<0>(P) << ":" << std::get<1>(P);
		ESS::Locate(std::get<0>(P), std::get<1>(P));
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000/360));
	}

	return 0;

}
