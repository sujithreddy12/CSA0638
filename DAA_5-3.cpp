#include <stdio.h>

// Number of jobs and workers
#define N 4

// A Utility function to find minimum element
// in cost[][]
int min(int cost[][N])
{
    int min = 999;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cost[i][j] < min)
                min = cost[i][j];
    return min;
}

// A Utility function to find maximum element
// in cost[][]
int max(int cost[][N])
{
    int max = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cost[i][j] > max)
                max = cost[i][j];
    return max;
}

// A utility function to calculate cost of already
// assigned jobs
int alreadyAssignedCost(int cost[][N], int assign[], 
                          int n)
{
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (assign[i] == j)
                sum += cost[i][j];
    return sum;
}

// A utility function to calculate cost and assign jobs
// to minimum available worker
void assign(int cost[][N], int assign[], 
            int start, int n)
{
    // Initialize min as minimum cost of a cell
    int min = 999;

    // To keep track of minimum value
    int min_index = -1;

    // Check each cell in the current row
    for (int j = 0; j < n; j++)
    {
        // If current cell has more value than
        // matrix[i][j]
        if (assign[j] == 0 && cost[start][j] < min)
        {
            // Set min to current cell
            min = cost[start][j];

            // Set index of cost to j
            min_index = j;
        }
    }

    // Assign minimum available worker
    assign[min_index] = 1;

    // Print minimum value for debugging
    printf("%d ", min);

    // Call for each available worker
    for (int k = 0; k < n; k++)
    {
        if (assign[k] == 0)
            assign(cost, assign, k, n);
    }
}

// Finds the assignment with minimum cost
int findMinCost(int cost[][N])
{
    // Variables for storing the minimum cost
    int i, j;
    int min_cost = INT_MAX;

    // Arrays for rows and columns to keep
    // track of assigned workers
    int assign[N], rowAssign[N], colAssign[N];

    // Initialise rowAssign[] and colAssign[] to 2
    // because a cell is assigned only once
    for (i = 0; i < N; i++)
    {
        rowAssign[i] = 2;
        colAssign[i] = 2;
    }

    // Iterate for all possible assignments
    for (i = 0; i < (1 << N); i++)
    {
        // For every assignment, assign ith
        // worker to the first availability

        for (j = 0; j < N; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                rowAssign[j] = 0;
                colAssign[j] = 1;

                // Stop processing other bits
                break;
            }
        }

        // For every assignment, check for the
        // first available column

        for (j = 0; j < N; j++)
        {
            if (rowAssign[j] == 1 && colAssign[j] != 0)
            {
                assign[j] = 0;

                // Stop processing other columns
               break;
            }
        }

        // Calculate total cost for the current assignment
        int tmp = alreadyAssignedCost(cost, assign, N);

        // Update the minimum cost found so far
        if (tmp < min_cost)
        {
            min_cost = tmp;

            // Copy the assignment
            for (int i = 0; i < N; i++)
            {
                rowAssign[i] = assign[i];
            }
        }
    }

    // Print the minimum cost
    printf("\nMinimum cost is : %d", min_cost);

    // Print the assignment
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (rowAssign[i] == 1 && colAssign[j] == 0)
                printf("Worker %d -> Job %d\n", i + 1, j + 1);
        }
    }

    // Return the minimum cost
    return min_cost;
}

// Driver code
int main()
{
    int cost[N][N] = {
        {7, 3, 5, 10},
        {1, 2, 6, 4},
        {9, 8, 12, 15},
        {20, 13, 11, 16}
    };

    // Calculate and print the minimum cost
    findMinCost(cost);

    return 0;
}