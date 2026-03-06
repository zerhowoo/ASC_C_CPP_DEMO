//PreciseTimer.cpp

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "PreciseTimer.h"


// CONSTRUCTOR
CPreciseTimer::CPreciseTimer()
{
	Initialize();
}

BOOL CPreciseTimer::Initialize()
{
	m_i64Start = 0;
	m_i64Elapsed = 0;
	m_bRunning = false;

	// CLEAR VARIABLES THAT ARE UPDATED FROM ANOTHER THREAD
	m_i64UpdatedStart = 0;

	// CLEAR TEMPORARY VARIABLE
	memset(&m_liCount, 0, sizeof(LARGE_INTEGER));

	return TRUE;
}

void CPreciseTimer::StartTimer()
{
	auto clk = std::chrono::high_resolution_clock::now();
	m_i64UpdatedStart = clk.time_since_epoch().count() / 1000.0;
	//return TRUE;

	// INITIALIZE VARIABLE THAT IS UPDATED FROM ANOTHER THREAD
	m_i64Start = m_i64UpdatedStart;

	// CLEAR COUNTERS
	m_i64Elapsed = m_i64Counts = 0;

	// IN ORDER TO GET ELAPSED TIME NEXT TIME
	m_bRunning = true;
}

void CPreciseTimer::StopTimer()
{
	if (m_bRunning)	// Get STOP time
	{
		auto clk = std::chrono::high_resolution_clock::now();
		m_i64Counts = clk.time_since_epoch().count() / 1000.0;
		m_i64Elapsed = m_i64Counts - m_i64Start;
	}

	// IN ORDER TO GET NEW START TIME NEXT TIME
	m_bRunning = false;

}

double CPreciseTimer::GetTime()
{
	//if (m_bRunning == true)
	//	UpdateElapsed();

	return (m_i64Elapsed);
}
