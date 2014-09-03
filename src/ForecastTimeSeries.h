//
//  ForecastTimeSeries.h
//  epanet-rtx
//
//  Created by Sam Hatchett on 8/26/14.
//
//

#ifndef __epanet_rtx__ForecastTimeSeries__
#define __epanet_rtx__ForecastTimeSeries__

#include <iostream>

#include "ModularTimeSeries.h"

namespace RTX {
  class ForecastTimeSeries : public ModularTimeSeries {
  public:
    RTX_SHARED_POINTER(ForecastTimeSeries);
    ForecastTimeSeries();
    
    Clock::sharedPointer fitWindow();
    void setFitWindow(Clock::sharedPointer clock);
    
    Clock::sharedPointer refitClock();
    void setRefitClock(Clock::sharedPointer clock);
    
    
    
    
  protected:
    virtual std::vector<Point> filteredPoints(TimeSeries::sharedPointer sourceTs, time_t fromTime, time_t toTime);
    
  private:
    time_t _fitTime; // last time the model was fit
    int _ar, _ma; // model order
    Clock::sharedPointer _fitWindow, _refitClock;
    
    
  };
}


#endif /* defined(__epanet_rtx__ForecastTimeSeries__) */