#pragma once
#include <stdbool.h>

//Constants to be adjusted for specific needs

#define TARGET_TEMP 0               //Adjust to set ideal temperature
#define TEMP_THRESHOLD 0            //Adjust to increase ideal temperature range
#define LOW_TEMP 0                  //Adjust to set critically low temperature
#define HIGH_TEMP 0                 //Adjust to set critically high temperature
#define TARGET_WIND 0               //Adjust to set ideal wind speed
#define WIND_THRESHOLD 0            //Adjust to increase ideal wind speed range
#define LOW_WIND 0                  //Adjust to set critically low wind speed
#define HIGH_WIND 0                 //Adjust to set critically high wind speed
#define POWER_USAGE 0               //Adjust to set the power usage by the car while driving
#define TARGET_HUMIDITY 0           //Adjust to set the ideal humidity level
#define HUMIDITY_THRESHOLD 0        //Adjust to increase ideal humidity level range
#define LOW_HUMIDITY 0              //Adjust to set critically low humidity level
#define HIGH_HUMIDITY 0             //Adjust to set critically high humidity level
#define TARGET_PRESSURE 0           //Adjust to set ideal athmospheric pressure
#define PRESSURE_THRESHOLD 0        //Adjust to increase ideal athmospheric pressure range
#define LOW_PRESSURE 0              //Adjust to set critically low athmospheric pressure
#define HIGH_PRESSURE 0             //Adjust to set critically high athmospheric pressure

typedef enum unit_type {            //Use to set temperature units
    cels = 0,
    fahr = 1,
    kelv = 2
} temp_t;

typedef struct station_data {       //Use to combine typical wether station data
    temp_t temperature_units;
    double temperature;
    double pressure;
    double humidity;
    double solar_radiation;
    double wind_speed;
} station_t;


//Temperature Interface

double f_to_c(double fahrenheit);                   //Converts Fahrenheit to Celsius
double c_to_f(double celsius);                      //Converts Celsius to Fahrenheit
double k_to_c(double kelvin);                       //Converts Kelvin to Celsius
double c_to_k(double celsius);                      //Converts Celsius to Kelvin
double average_temp(double* temps, int size);       //Computes averate temperature from list
double max_temp(double* temps, int size);           //Computes maximum recorded temperature
double min_temp(double* temps, int size);           //Computes minimum recorded temperature
bool too_hot(double temp);                          //Indicates whether temperature hit critically high value
bool too_cold(double temp);                         //Indicates whether temperature hit critically low value

//Solar Radiation Interface

bool enough_solar_radiation(double radiation);              //Indicates whether current solar radiation is bigger than car consumes
double average_radiation(double* radiations, int size);     //Computes average solar radiation in the list
double max_radiation(double* radiations, int size);         //Computes maximum recorded solar radiation
double min_radiation(double* radiations, int size);         //Computes minimum recorded solar radiation

//Wind Speed Interface

bool too_windy(double wind_speed);                          //Indicates whether current wind hit critically high value
double average_wind_speed(double* winds, int size);         //Computes average wind speed in the list
double max_wind(double* winds, int size);                   //Computes maximum recorded wind speed
double min_wind(double* winds, int size);                   //Computes minimum recorded wind speed

//Humidity Interface

bool too_humid(double humidity);                            //Indicates whether current humidity hit critically high value 
double average_humidity(double* humidities, int size);      //Computes avevrage humidity in the list
double max_humidity(double* humidities, int size);          //Computes maximum recorded humidity
double min_humidity(double* humidities, int size);          //Computes minimum recorded humidity

//Pressure Interface

bool pressure_too_high(double pressure);                    //Indicates whether current pressure hit critically high value
bool pressure_too_low(double pressure);                     //Indicates whether current pressure hit critically low value
double average_pressure(double* pressures, int size);       //Computes average pressure in the list
double max_pressure(double* pressures, int size);           //Computes maximum recorded pressure
double min_pressure(double* pressures, int size);           //Computes minimum recorded pressure

//Universal Interface

char* get_temp_unit(station_t* current_data);               //Returns string value of temperature units used
bool are_conditions_ideal(station_t* current_data);         //Indicates whether all conditions are in ideal range
bool critical_conditions(station_t* current_data);          //Indocates whether any condition hit a critical value
bool expect_discharge(station_t* current_data);             //Indicates if solar radiation is less than car consumes
