#include "Data.h"

float failureRateFromMTBF(Data data);

float probabilityOfWorkingWithoutFailureInTime(Data data, int time);

float calculateFrPerNumber(float failures, float number);

float calculateFrPerTime(int failures, int tested, float operatingTime, float downtime);