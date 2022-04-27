#include <stdio.h>

#include "weather_utils.h"

int min_temp(WeatherTable a) {
  int min = a[0][0][0]._min_temp;

  for(unsigned int year = 0u; year < YEARS; year++) {
    for(month_t month = january; month < MONTHS; month++) {
      for(unsigned int day = 0u; day < DAYS; day++) {
        if(a[year][month][day]._min_temp < min) {
          min = a[year][month][day]._min_temp;
        }
      }
    }
  }

  printf("\nLa menor temperatura registrada en la ciudad de Cordoba fue de %d°C\n\n", min);

  return min;
}


void max_temp_per_year(WeatherTable a, int output[YEARS]) {
	int max_temp;

	for(unsigned int year = 0u; year < YEARS; year++) {
		max_temp = a[year][january][0]._max_temp;
    	for(month_t month = january; month < MONTHS; month++) {
      		for(unsigned int day = 0u; day < DAYS; day++) {
        		if(max_temp < a[year][month][day]._max_temp) {
          			max_temp = a[year][month][day]._max_temp;
        		}
      		}
    	}

    	output[year] = max_temp;
		printf("La temperatura maxima registrada en %u fue de %d°C\n", year+1980, max_temp / 10);
  	}
}


void print_array(month_t array[YEARS]) {
	//Imprimo el array
    for (unsigned int year = 0u; year < YEARS; year++) {
        if (array[year] == january) {
            printf("\nMes con mayor precipitaciones de %d es enero.", year + 1980);
        } else if (array[year] == february) {
            printf("\nMes con mayor precipitaciones de %d es febrero.", year + 1980);
        } else if (array[year] == march) {
            printf("\nMes con mayor precipitaciones de %d es marzo.", year + 1980);
        } else if (array[year] == april) {
            printf("\nMes con mayor precipitaciones de %d es abril.", year + 1980);
        } else if (array[year] == may) {
            printf("\nMes con mayor precipitaciones de %d es mayo.", year + 1980);
        } else if (array[year] == june) {
            printf("\nMes con mayor precipitaciones de %d es junio.", year + 1980);
        } else if (array[year] == july) {
            printf("\nMes con mayor precipitaciones de %d es julio.", year + 1980);
        } else if (array[year] == august) {
            printf("\nMes con mayor precipitaciones de %d es agosto.", year + 1980);
        } else if (array[year] == september) {
            printf("\nMes con mayor precipitaciones de %d es septiembre.", year + 1980);
        } else if (array[year] == october) {
            printf("\nMes con mayor precipitaciones de %d es octubre.", year + 1980);
        } else if (array[year] == november) {
            printf("\nMes con mayor precipitaciones de %d es noviembre.", year + 1980);
        } else if (array[year] == december) {
            printf("\nMes con mayor precipitaciones de %d es diciembre.", year + 1980);
        }
    }
}


void max_prec_month(WeatherTable a, month_t output[YEARS]) {
	
    int fst = 0;
    int scn = 0;

    month_t max = january;

    for (unsigned int year = 0u; year < YEARS; year++){
        int tmp_max = 0;
        for(month_t month = january; month < MONTHS; month++){
            for(unsigned int day = 0u; day < DAYS; day++){
                fst = fst + a[year][month][day]._rainfall; //Cuento la precipitacion del primer mes
            }

            month++; //Avanzo al siguiente mes

            for(unsigned int day = 0u; day < DAYS; day++){
                scn = scn + a[day][month][year]._rainfall; //Cuento la precipitacion del siguiente mes
            }

			if(tmp_max < fst && scn < fst) {
				tmp_max = fst;
				max = month--;
			} else if(tmp_max < scn && fst < scn) {
				tmp_max = scn;
				max = month;
			}

            //Reseteo los contadores de prec de los meses
            fst = 0;
            scn = 0;
        }
        output[year] = max;
    }
    print_array(output);
}