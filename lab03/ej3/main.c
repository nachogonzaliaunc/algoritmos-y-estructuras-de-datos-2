/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */

   // declaro los punteros
   int *int_pointer = NULL;
   char *char_pointer = NULL;

	/*
		Para cambiar los datos;
		1) le asigno a la variable _pointer la direccion de memoria a cambiar (ej: int_pointer = &x)
		2) cambio el valor de la direccion (ej: *int_pointer = 9)
	*/

	// cambio el valor de x
	int_pointer = &x;
	*int_pointer = 9;

	// cambio el valor de m.age
	int_pointer = &m.age;
	*int_pointer = 100;

	// cambio el valor de m.name_initial
	char_pointer = &m.name_initial;
	*char_pointer = 'F';

	// cambio el valor de a[1]
	int_pointer = &a[1];
	*int_pointer = 42;


    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);
}
