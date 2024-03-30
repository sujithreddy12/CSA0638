#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int numVertices;
void printSolution() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", path[i] + 1);
    }
    printf("%d\n", path[0] + 1);
}
bool isSafe(int vertex, int pos) {
    if (!graph[path[pos - 1]][vertex]) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == vertex) {
            return false;
        }
    }
    return true;
}
bool hamiltonianCircuitUtil(int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]]) {
            return true;
        }
        return false;
    }
    for (int vertex = 1; vertex < numVertices; vertex++) {
        if (isSafe(vertex, pos)) {
            path[pos] = vertex;
            if (hamiltonianCircuitUtil(pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
void findHamiltonianCircuit() {
    for (int i = 0; i < numVertices; i++) {
        path[i] = -1;
    }
    path[0] = 0;
    if (!hamiltonianCircuitUtil(1)) {
        printf("No Hamiltonian circuit exists.\n");
    } else {
        printf("Hamiltonian circuit found:\n");
        printSolution();
    }
}
int main() {
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    findHamiltonianCircuit();
    return 0;
}
