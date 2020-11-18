#include "Calculator.h"
#include "Data.h"
//Aleksander Mielczarek
float failureRateFromMTBF(Data data) {
	return 1 / data.MTBF;
}
float probabilityOfWorkingWithoutFailureInTime(Data data, int time) {
	data.FailureRate = failureRateFromMTBF(data);
	float WorkRate = 1 - data.FailureRate;
	float probabilityOfWorking = WorkRate;
	for (int i = 0; i < time; i++) {
		probabilityOfWorking *= WorkRate;
	}
	return probabilityOfWorking;
}

//Jakub Kowalewski