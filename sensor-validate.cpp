#include "sensor-validate.h"

bool _give_me_a_good_name(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return false;
  }
  return true;
}

bool validateReadings(double* values, int numOfValues,double maxDelta){
      int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!_give_me_a_good_name(values[i], values[i + 1], maxDelta)) {
      return false;
    }
  }
  return true;
}

bool validateSOCreadings(double* values, int numOfValues) {
    double maxDeltaSOC = 0.05 ;
    return validateReadings(values,numOfValues,maxDeltaSOC) ;
}

bool validateCurrentreadings(double* values, int numOfValues) {
    double maxDeltaCurrent = 0.1 ;
    return validateReadings(values,numOfValues,maxDeltaCurrent) ;
}
