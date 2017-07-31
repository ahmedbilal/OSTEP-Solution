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

// Prototypes
struct Vector;

void vector_init(struct Vector * self);
void vector_destroy(struct Vector * self);
void vector_insert(struct Vector * self, int n);
void vector_print(struct Vector * self);


// Definations
struct Vector
{
	// Data Fields
	int * data;
	int capacity;
	int size;

	// Functions/Methods
	void (* init)(struct Vector * self);
	void (* destroy)(struct Vector * self);
	void (* insert)(struct Vector * self, int n);
	void (* print)(struct Vector * const self);
};


void vector_init(struct Vector * self)
{
	self->size = 0;
	self->capacity = 0;
	self->data = NULL;

	self->init = vector_init;
	self->destroy = vector_destroy;
	self->insert = vector_insert;
	self->print = vector_print;
}

void vector_destroy(struct Vector * self)
{
	self->size = 0;
	free(self->data);
}

void vector_insert(struct Vector * self, int n)
{
    self->data = (int *)realloc(self->data, sizeof(int) * self->capacity + sizeof(int));
    self->capacity++;
	self->data[self->size] = n;
	self->size++;
}

void vector_delete(struct Vector * self, int i)
{
    
}
void vector_print(struct Vector * self)
{
	for (int i = 0; i < self->size; i++)
	{
		printf("%d ", self->data[i]);
        if (i == self->size - 1)
            printf("\n");
	}
	
}