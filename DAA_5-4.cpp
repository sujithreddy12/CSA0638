#include <stdio.h>
#include <limits.h>

#define N 4

// Function to find the minimum element in a row
int find_min(int cost[][N], int row, int assigned[], int n)
{
    int min = INT_MAX;
    int min_index = -1;

    for (int j = 0; j < n; j++)
    {
        if (assigned[j] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    min_index = j;
                }
            }
        }
    }

    return min_index;
}

// Function to find the maximum bipartite matching using the Hungarian algorithm
void hungarian(int cost[][N], int assign[], int n)
{
    int i, j, min_index;

    // Initialize all assignments as 0
    for (i = 0; i < n; i++)
        assign[i] = 0;

    // Assign the minimum cost worker to the minimum cost job
    for (i = 0; i < n; i++)
    {
        min_index = find_min(cost, i, assign, n);
        assign[min_index] = 1;
    }

    // Print the assignments
    printf("Assignments: ");
    for (j = 0; j < n; j++)
        printf("%d ", assign[j]);
    printf("\n");

    // Calculate the cost of the assignments
    int total_cost =alreadyAssignedCost(cost, assign, n);
    printf("Total cost: %d\n", total_cost);
}

// Function to calculate cost of already assigned jobs
int alreadyAssignedCost(int cost[][N], int assign[], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (assign[i] == j)
                sum += cost[i][j];

    return sum;
}

// Driver function to test the program
int main()
{
    int cost[N][N] = {
        {1, 3, 5, 9},
        {2, 1, 4, 6},
        {3, 2, 2, 4},
        {4, 3, 3, 1}
    };

    int assign[N];

    hungarian(cost, assign, N);

    return 0;
}