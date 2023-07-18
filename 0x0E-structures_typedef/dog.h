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

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

