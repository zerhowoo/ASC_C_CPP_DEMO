//PreciseTimer.h
#ifndef _PRECISETIMER_H_
#define _PRECISETIMER_H_


#include "LinuxDefs.h"
#include <chrono>

using namespace std;

#define LONGLONG long long
typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG  HighPart;
	};
	struct {
		DWORD LowPart;
		LONG  HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER;


// More precise Timer for measuring time intervals in MICROseconds.
// The performance of this Timer is dependent on the performance of the system.
class CPreciseTimer
{
public:
	//CONSTRUCTOR
	CPreciseTimer();

	void StartTimer();
	void StopTimer();
	double GetElapsedTime();
	double GetTime();

	// THIS FUNCTION IS CALLED FROM ANOTHER THREAD TO GET UPDATED TIME
	BOOL UpdateStartTime();

private:
	// Auxiliary Function
	BOOL UpdateElapsed();
	BOOL GetFrequency();
	BOOL Initialize();
	void RestartTimer();

	// Member variables
	bool m_bRunning;

	double m_i64Start;
	double m_i64Elapsed;

	// TEMPORARY VARIABLE
	LARGE_INTEGER m_liCount;

	// THOSE VARIABLES ARE UPDATED FROM ANOTHER THREAD
	//double UpdatedStartTime;
	double m_i64UpdatedStart;

	// Some auxiliary variables
	double m_i64Counts;
};

#endif // _PRECISETIMER_H_


