#include "BaldoTimer.h"

using namespace std::chrono;

BaldoTimer::BaldoTimer() noexcept
{
	last = steady_clock::now();
}

float BaldoTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float BaldoTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
