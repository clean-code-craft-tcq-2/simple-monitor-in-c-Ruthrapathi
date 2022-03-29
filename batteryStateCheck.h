#ifndef batteryStateCheck_h
#define batteryStateCheck_h
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define ENGLISH 0
#define GERMAN  1

#define WARNINGPERCENTAGE 0.05

#define OK 0
#define LOWWARNING 1
#define LOWERROR 2
#define HIGHWARNING 3
#define HIGHERROR 4

typedef struct batterycondition
{
	char parameter[3][20];
	char status[5][20];
		
}batteryCondition;

typedef struct paramInDiffLanguage
{
    char parameter[3][20];
	char status[5][20];
}DiffLanguage;

extern batteryCondition batteryCond;
extern DiffLanguage alertNotes[2];


int checkLowerLimit(float input, float lowLimit, float highLimit) ;
int checkHigherLimit(float input, float highLimit);
void StatusStore(int parameter,int lowerResult,int higherResult);
void printStatus(int parameter);
bool limitCheck(float value, float *limit, int parameter);
bool temperatureIsOk(float temperature, float *tempLimitArray);
bool SOCIsOk(float soc, float *SOCLimitArray);
bool chargeRateIsOk(float chargeRate, float *chargeRateLimitArray);
bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) ;

#endif
