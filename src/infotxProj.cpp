//============================================================================
// Name        : infotxProj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<unistd.h>
#include<fstream>
#include<string>
#include<sstream>
#include <math.h>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;
#define TEMP_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define SLOTS "/sys/devices/bone_capemgr.9/slots" //This line can be added in case SLOTS not set up on BBB.
const int B =4275;
/*int readAnalog(int number){
   stringstream ss;
   ss << TEMP_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
return number;
							}*/
using namespace std;
int main() {
//	float temp =27.33;
	if(system("echo BB-ADC > $SLOTS"))
	{
		cout << "BB-ADC DTO already loaded" << endl;
	}
/*	while(1)
	{
		cout << "Starting the readTHermistor program" << endl;
		usleep(1000000);
		int value = readAnalog(0);
		float R= 4095.0/((float)value)-1.0;
		R = 100000.0*R;
		float temperature =1.0/(log(R/100000.0)/B+1/298.15)-263.15;// convert an val to temp C.
		R = 100000.0*R;
		cout << "Temperature is : " << temperature << "Degrees Celcius" << endl;
		usleep(50000);
		//float temperature to string
		stringstream stream;
		stream << fixed<< setprecision(1) << temperature;//temp to 1 dec place as a string
		string s = stream.str();
		// Getting the local time
		time_t now = time(0);
		struct tm * timeinfo;
		string result;
		ostringstream temp;
		time(&now);
		timeinfo = localtime(&now);*/
		//update tech data
	float temp = 33.6;
	char * data;
		sprintf(data,"curl -H \'Content-Type: application/json\' -X POST  \'http://mary:B00024992@178.62.29.184/db/mary_temp' -d \'{\"tempval\":\"\%f\",\"timestamp\":\"13.23\",\"unitid\":\"maryBB\"}\'",temp);
		system(data);
		system ("curl -H 'Content-Type: application/json'\
				 -X POST  'http://mary:B00024992@178.62.29.184/db/mary_temp' \
				-d '{\"status\":\"ON\",\"unitid\":\"maryBB\"}'");
		//update temp date


	return 0;
}
