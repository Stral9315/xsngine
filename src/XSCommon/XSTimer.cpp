#include "XSCommon/XSCommon.h"
#include "XSCommon/XSTimer.h"

// Author: Lourens Elzinga, Kieren McDevitt

namespace XS {

	Timer::Timer() {
	#if defined(XS_OS_WINDOWS)
		QueryPerformanceCounter( &start );
	#elif defined(XS_OS_LINUX)
		gettimeofday( &start, nullptr );
	#endif
	}

	void Timer::Stop( void ) {
	#if defined(XS_OS_WINDOWS)
		QueryPerformanceCounter( &stop );
	#elif defined(XS_OS_LINUX)
		gettimeofday( &stop, nullptr );
	#endif
	}

	double Timer::GetTiming( bool restart, Resolution resolution ) {
		double startTime = 0.0, stopTime = 0.0;

		Stop();

	#if defined(XS_OS_WINDOWS)
		TimeVal frequency;
		QueryPerformanceFrequency( &frequency );

		startTime = start.QuadPart * (1000000.0 / frequency.QuadPart);
		stopTime = stop.QuadPart * (1000000.0 / frequency.QuadPart);
	#elif defined(XS_OS_LINUX)
		startTime = (start.tv_sec * 1000000.0) + start.tv_usec;
		stopTime = (stop.tv_sec * 1000000.0) + stop.tv_usec;
	#endif

		if ( restart ) {
		#if defined(XS_OS_WINDOWS)
			QueryPerformanceCounter( &start );
		#elif defined(XS_OS_LINUX)
			gettimeofday( &start, nullptr );
		#endif
		}

		switch ( resolution ) {
		case Resolution::SECONDS:
			return (stopTime - startTime) * 0.000001;
		case Resolution::MILLISECONDS:
			return (stopTime - startTime) * 0.001;
		case Resolution::MICROSECONDS:
			return (stopTime - startTime);
		default:
			// should not happen
			return 0.0;
		}
	}

} // namespace XS
