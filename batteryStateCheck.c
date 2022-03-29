#include "batteryStateCheck.h"

int languageSelector = GERMAN;

batteryCondition batteryCond;

DiffLanguage alertNotes[2]= {{{"Temperature", "StateofCharge", "ChargeRate"},{"OK","LOW_WARNING","LOW_ERROR","HIGH_WARNING","HIGH_ERROR"}},{{"Temperatur","Ladezustand", "Ladestrom"},{"OK","NIEDRIG_WARNUNG","NIEDRIG_ERROR","HOCH_WARNUNG","HOCH_ERROR"}}};

int checkLowerLimit(float input, float lowLimit, float highLimit)       
{   int result = OK;
	if (input  < lowLimit)
	{
	result = LOWERROR;
	}
	else if(input < (WARNINGPERCENTAGE *  highLimit)+lowLimit)
	{
	  result = LOWWARNING;
	}

	
    return result;
}

int checkHigherLimit(float input, float highLimit)      
{  
    float highWarningLimit = highLimit - WARNINGPERCENTAGE * highLimit;
    
	int result = OK;
	if (input  > highLimit)
	{
	result = HIGHERROR;	 
	}
	else if(input > highWarningLimit)
	{
	  result = HIGHWARNING;
	}
	return result;
}

void printStatus( int parameter)
{
	printf(" %s : %s \n",batteryCond.parameter[parameter],batteryCond.status[parameter]);
	
}
void StatusStore(int parameter,int lowerResult,int higherResult)
{
strcpy((batteryCond.parameter[parameter]), alertNotes[languageSelector].parameter[parameter]);
strcpy(batteryCond.status[parameter], alertNotes[languageSelector].status[lowerResult + higherResult]);
}

bool limitCheck(float value, float *limit, int parameter)
{
	
int lowerResult = checkLowerLimit(value , limit[0] , limit[1]);
int higherResult = checkHigherLimit(value , limit[1]);
StatusStore(parameter,lowerResult,higherResult);
printStatus(parameter);
return (lowerResult || higherResult);
}

bool temperatureIsOk(float temperature, float *tempLimitArray)
{
bool result = limitCheck(temperature,tempLimitArray, 0);
  return result;
}

bool SOCIsOk(float soc, float *SOCLimitArray)
{
 
bool result = (limitCheck(soc, SOCLimitArray, 1));
return result;
  
}

bool chargeRateIsOk(float chargeRate, float *chargeRateLimitArray)
{  
bool result = limitCheck(chargeRate, chargeRateLimitArray, 2);
return result;
}

bool batteryIsOk(float temperature, float soc, float chargeRate, float *limitArray) 
{bool resultTemp,resultSoc,resultChargeRate;
resultTemp = temperatureIsOk(temperature,&limitArray[0]);
resultSoc = SOCIsOk(soc,&limitArray[2]);
resultChargeRate = chargeRateIsOk(chargeRate,&limitArray[4]);

return(!(resultTemp|| resultSoc||resultChargeRate));
	
}
