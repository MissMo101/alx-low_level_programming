#ifndef DOG_H
#define DOG_H

/**
 * struct dog - data type that represents a dog's information
 * @name: pointer to a character array
 * @age: floating-point number representing the age
 * @owner: pointer to a character array
 */

struct dog
{
        char *name;
        float age;
        char *owner;
};

#endif

#include <stdlib.h>
#include "dog.h"
/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to initialize
 * @age: age to initialize
 * @owner: owner to initialize
 */
void init_dog(struct dog *d, char  *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
