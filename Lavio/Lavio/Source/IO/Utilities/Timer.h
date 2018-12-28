// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#define WINDOWS_TIMER 0
#if WINDOWS_TIMER
#include <Windows.h>

namespace Lavio
{
	class Timer
	{
	private:
		LARGE_INTEGER mStart;
		double mFrequency;
	public:
		Timer()
		{
			LARGE_INTEGER mLocalFreq;
			QueryPerformanceFrequency(&mLocalFreq);
			mFrequency = 1.0f / mLocalFreq.QuadPart;
			QueryPerformanceCounter(&mStart);
		}

		void Reset()
		{
			QueryPerformanceCounter(&mStart);
		}

		float Elapsed() const
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);

			unsigned __int64 cycles = current.QuadPart - mStart.QuadPart;

			return static_cast<float>(cycles * mFrequency * 1000.0f);
		}
	};
}

#else
#include <chrono>
namespace Lavio
{
	class Timer
	{
	private:
		typedef std::chrono::high_resolution_clock HighResolutionClock;
		typedef std::chrono::duration<float, std::milli> millisecondsType;

		std::chrono::time_point<HighResolutionClock> mStart;
	public:
		Timer()
		{
			Reset();
		}

		void Reset()
		{
			mStart = HighResolutionClock::now();
		}

		float Elapsed() const
		{
			return std::chrono::duration_cast<millisecondsType>(HighResolutionClock::now() - mStart).count();
		}
		
		float ElapsedSeconds() const
		{
			return Elapsed() / 1000.0f;
		}
	};
}
#endif