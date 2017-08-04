/*
    Written by Ahmed Bilal Khalid
    BSCS15015 - Information Technology University

    Error Fixed using Valgrind
    ---------------------------------------------
    You can use it but let this comment block stays
    here
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
struct Vector;

void vector_init(struct Vector * self);
void vector_destroy(struct Vector * self);
void vector_insert(struct Vector * self, char * str);
void vector_print(struct Vector * self);
char * vector_get(struct Vector * self, int index);

// Definations
struct Vector
{
	// Data Fields
	char ** data; // array of strings or pointer to pointers
	int capacity;
	int size;

	// Functions/Methods
	void (* init)(struct Vector * self);
	void (* destroy)(struct Vector * self);
	void (* insert)(struct Vector * self, char * str);
	void (* print)(struct Vector * const self);
	char* (* get)(struct Vector * const self, int index);
};


void vector_init(struct Vector * self)
{
	self->size = 0;
	self->data = NULL;

	self->init = vector_init;
	self->destroy = vector_destroy;
	self->insert = vector_insert;
	self->print = vector_print;
	self->get = vector_get;
}

void vector_destroy(struct Vector * self)
{
	// Free the internal structure
	for (int i = 0; i < self->size; i++)
	{
		free(self->data[i]);
	}
	
	// Then Free the whole structure
	free(self->data);

	self->size = 0;
}

void vector_insert(struct Vector * self, char * str)
{
	
    self->data = (char **) realloc(self->data, sizeof(char *) * (self->size + 1));
	self->data[self->size] = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(self->data[self->size], str);
	self->size++;
}

void vector_print(struct Vector * self)
{
	for (int i = 0; i < self->size; i++)
	{
		printf("%s", self->data[i]);
        if (i == self->size - 1)
            printf("\n");
	}
	
}

char * vector_get(struct Vector * self, int index)
{
	return self->data[index];
}