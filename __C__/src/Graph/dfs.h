#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include "../LinkedLists/LinkedList/linkedlist.h"

typedef struct DfsVertex_
{
	void* data;
	VertexColor color;
} DfsVertex;

int dfs(Graph* graph, List* ordered);

#endif
