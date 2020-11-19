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
/*California Instruments, Inc., produces 3,000 computer chips per day. Three hundred are tested for a
period of 500 operating hours each. During the test, six failed: two after 50 hours, two at 100 hours,
one at 300 hours, and one at 400 hours.
Find FR(%) and FR(N).*/
float calculateFrPerNumber(float failures,float tested) {
	return (failures / tested) * 100;
}
float calculateFrPerTime(int failures, int tested, float operatingTime, float downtime) {
	float totalTime = tested * operatingTime;
	float totalOperatingTime = totalTime - downtime;
	return failures / totalOperatingTime;
}

//Jakub Kowalewski