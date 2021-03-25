#include "sensor-validate.h"

bool isValueDiffAccepted(double value, double nextValue, double maxDelta) {
    if (nextValue - value > maxDelta) {
        return false;
    }
    return true;
}

bool checkValidInput(double* values,int numOfValues)
{
    if (values == nullptr || numOfValues <= 1) return false;
    else return true;
}

bool validateReadings(double* values, int numOfValues, double maxDelta) {
    bool isValidInput = checkValidInput(values, numOfValues);
    if (isValidInput) {
        int lastButOneIndex = numOfValues - 1;
        for (int i = 0; i < lastButOneIndex; i++) {
            if (!isValueDiffAccepted(values[i], values[i + 1], maxDelta)) {
                return false;
            }
        }
        return true;
    }
    else return false;

}

bool validateSOCreadings(double* values, int numOfValues) {
    double maxDeltaSOC = 0.05;
    return validateReadings(values, numOfValues, maxDeltaSOC);
}

bool validateCurrentreadings(double* values, int numOfValues) {
    double maxDeltaCurrent = 0.1;
    return validateReadings(values, numOfValues, maxDeltaCurrent);
}
