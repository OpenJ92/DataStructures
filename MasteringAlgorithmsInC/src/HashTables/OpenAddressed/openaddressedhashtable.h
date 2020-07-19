#ifndef OHTBL_H
#define OHTBL_H

#include <string.h>
#include <stdlib.h>

typedef struct OHTbl_
{  
	int positions;
	void* vacated;

	int (*h1)(const void* key);
	int (*h2)(const void* key);
	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);

	int size;
	void** table;
} OHTbl;

int ohtbl_init(OHTbl* ohtbl, int positions, int (*h1)(const void* key), 
		int (*h2)(const void* key), int (*match)(const void* key1,
			const void* key2), void (*destroy)(void* data));

void ohtbl_destroy(OHTbl* ohtbl);
int ohtbl_insert(OHTbl* ohtbl, const void* data);
int ohtbl_remove(OHTbl* ohtbl, void** data);
int ohtbl_lookup(OHTbl* ohtbl, void** data);

#define ohtbl_size(ohtbl) ((ohtbl)->size)

#endif
