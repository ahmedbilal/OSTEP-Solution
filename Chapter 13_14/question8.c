#include <stdio.h>
#include "abk_vector.h"

int main(int argc, char * argv[])
{
	// Create and Init Vector
	struct Vector vec;
	vector_init(&vec);

	// Insert Into Vector
	vec.insert(&vec, 1);
	vec.insert(&vec, 2);
	vec.insert(&vec, 3);
	vec.insert(&vec, 4);

	// Print content of vector
	vec.print(&vec);
	
	// Delete vector
	vec.destroy(&vec);

	// Nothing should be printed
	vec.print(&vec);
}

