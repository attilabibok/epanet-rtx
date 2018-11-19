#if (_MSC_PLATFORM_TOOLSET > 100)
#include <cmath>
#elif (_MSC_PLATFORM_TOOLSET <= 100)
#include <math.h>
#endif

#include "SineTimeSeries.h"

#define M_PI 3.141592653589793

using namespace RTX;
using namespace std;

SineTimeSeries::SineTimeSeries() {
  Clock::sharedPointer clock(new Clock(600));
  setClock(clock);
}


Point SineTimeSeries::point(time_t time) {
  if ( !(clock()->isValid(time)) ) {
    // if the time is not valid, rewind until a valid time is reached.
    time = clock()->timeBefore(time);
  }
  
  double value = std::sin((double)time * M_PI * 2 / (24*60*60));
  return Point(time, value);
  
}