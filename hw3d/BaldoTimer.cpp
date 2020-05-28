#include "BaldoTimer.h"

using namespace std::chrono;

BaldoTimer::BaldoTimer()
{
	last = steady_clock::now();
}

float BaldoTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float BaldoTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
