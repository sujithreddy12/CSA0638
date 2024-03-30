#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices, numColors;
void printSolution() {
    printf("Vertex Colors:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i + 1, colors[i]);
    }
}
bool isSafe(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}
bool graphColoringUtil(int vertex) {
    if (vertex == numVertices) {
        return true;
    }
    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, color)) {
            colors[vertex] = color;
            if (graphColoringUtil(vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}
void graphColoring() {
    if (!graphColoringUtil(0)) {
        printf("No solution exists for the graph coloring problem.\n");
    } else {
        printf("Solution found:\n");
        printSolution();
    }
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    graphColoring();
    return 0;
}
