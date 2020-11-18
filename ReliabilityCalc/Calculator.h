#include "Data.h"

float failureRateFromMTBF(Data data);

float probabilityOfWorkingWithoutFailureInTime(Data data, int time);

int calculateFrPerNumber(int failures, int number);

float calculateFrPerTime(int failures, int tested, float operatingTime, float downtime);