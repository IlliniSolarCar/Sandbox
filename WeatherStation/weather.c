#include "weather.h"

double f_to_c(double fahrenheit)
{
    double celsius = fahrenheit - 32.0;
    celsius = celsius * 5.0 / 9.0;
    return celsius;
}

double c_to_f(double celsius)
{
    double fahrenheit = celsius / 5.0 * 9.0;
    fahrenheit = fahrenheit + 32.0;
    return fahrenheit;
}

double k_to_c(double kelvin)
{
    double celsius = kelvin - 273.15;
    return celsius;
}

double c_to_k(double celsius)
{
    double kelvin = celsius + 273.15;
    return kelvin;
}

double average_temp(double* temps, int size)
{
    double total_temp = 0;
    
    for(int i = 0; i < size; i++)
    {
        total_temp += temps[i];
    }

    return total_temp / (double)size;
}

double max_temp(double* temps, int size)
{
    double max = temps[0];
    
    for(int i = 0; i < size; i++)
    {
        if(temps[i] > max)
            max = temps[i];
    }

    return max;
}

double min_temp(double* temps, int size)
{
    double min = temps[0];
    
    for(int i = 0; i < size; i++)
    {
        if(temps[i] < min)
            min = temps[i];
    }

    return min;
}

bool too_hot(double temp)
{
    return temp > HIGH_TEMP;
}

bool too_cold(double temp)
{
    return temp < LOW_TEMP;
}

bool enough_solar_radiation(double radiation)
{
    return radiation >= POWER_USAGE;
}

bool too_windy(double wind_speed)
{
    return wind_speed > HIGH_WIND;
}

bool too_humid(double humidity)
{
    return humidity > HIGH_HUMIDITY;
}

double average_radiation(double* radiations, int size)
{
    return average_temp(radiations, size);
}

double max_radiation(double* radiations, int size)
{
    return max_temp(radiations, size);
}

double min_radiation(double* radiations, int size)
{
    return min_temp(radiations, size);
}

double average_wind_speed(double* winds, int size)
{
    return average_temp(winds, size);
}

double max_wind(double* winds, int size)
{
    return max_temp(winds, size);
}

double min_wind(double* winds, int size)
{
    return min_temp(winds, size);
}

double average_humidity(double* humidities, int size)
{
    return average_temp(humidities, size);
}

double max_humidity(double* humidities, int size)
{
    return max_temp(humidities, size);
}

double min_humidity(double* humidities, int size)
{
    return min_temp(humidities, size);
}

bool pressure_too_high(double pressure)
{
    return pressure > HIGH_PRESSURE;
}

bool pressure_too_low(double pressure)
{
    return pressure < LOW_PRESSURE;
}

double average_pressure(double* pressures, int size)
{
    return average_temp(pressures, size);
}

double max_pressure(double* pressures, int size)
{
    return max_temp(pressures, size);
}

double min_pressure(double* pressures, int size)
{
    return min_temp(pressures, size);
}

char* get_temp_unit(station_t* current_data)
{
    if (current_data->temperature_units == cels)
        return "Celsius";
    else if (current_data->temperature_units == fahr)
        return "Fahrenheit";
    else if (current_data->temperature_units == kelv)
        return "Kelvin";
    else
        return "UNDEFINED";
}

bool are_conditions_ideal(station_t* current_data)
{
    return current_data->temperature <= (TARGET_TEMP + TEMP_THRESHOLD)
    && current_data->temperature >= (TARGET_TEMP - TEMP_THRESHOLD)
    && current_data->pressure <= (TARGET_PRESSURE + PRESSURE_THRESHOLD)
    && current_data->pressure >= (TARGET_PRESSURE - PRESSURE_THRESHOLD)
    && current_data->humidity <= (TARGET_HUMIDITY + HUMIDITY_THRESHOLD)
    && current_data->humidity >= (TARGET_HUMIDITY - HUMIDITY_THRESHOLD)
    && current_data->solar_radiation >= POWER_USAGE
    && current_data->wind_speed <= (TARGET_WIND + WIND_THRESHOLD)
    && current_data->wind_speed >= (TARGET_WIND - WIND_THRESHOLD);
}

bool critical_conditions(station_t* current_data)
{
    return current_data->temperature > HIGH_TEMP
    || current_data->temperature < LOW_TEMP
    || current_data->pressure > HIGH_PRESSURE
    || current_data->pressure < LOW_PRESSURE
    || current_data->humidity > HIGH_HUMIDITY
    || current_data->humidity < LOW_HUMIDITY
    || current_data->wind_speed > HIGH_WIND
    || current_data->wind_speed < LOW_WIND;
}

bool expect_discharge(station_t* current_data)
{
    return current_data->solar_radiation <= POWER_USAGE;
}
