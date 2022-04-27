#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS

#include "array_helpers.h"

int min_temp(WeatherTable a);

void max_temp_per_year(WeatherTable a, int max_temps[YEARS]);

void max_prec_month(WeatherTable a, month_t max_prec[YEARS]);

#endif