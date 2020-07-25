#ifndef graph_h
#define graph_h

#include <stdlib.h>

#include "../LinkedLists/LinkedList/linkedlist.h"
#include "../Sets/set.h"

typedef struct AdjList_
{
	void* vertex;
	Set adjacent;
} AdjList;

typedef struct Graph_
{
	int vcount;
	int ecount;

	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);

	List* adjlists;
} Graph;

typedef enum VertexColor_ { white, gray, black } VertexColor;

void graph_init(Graph* graph, int (*match)(const void* key1, const void* key2), 
		void (*destroy)(void* data));

void graph_destroy(Graph* graph);
int graph_insert_vertex(Graph* graph, const void* data);
int graph_insert_edge(Graph* graph, const void* data1, const void* data2);
int graph_remove_vertex(Graph* graph, void** data);
int graph_remove_edge(Graph* graph, void** data1, void** data2);
int graph_adjlist(const Graph* graph, const void* data, AdjList** adjlist);
int graph_is_adjacent(const Graph* graph, const void* data1, const void* data2);

#define graph_adjlists(graph) ((graph)->adjlists)
#define graph_vcount(graph) ((graph)->vcount)
#define graph_ecount(graph) ((graph)->ecount)

#endif
