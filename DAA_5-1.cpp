#include <stdio.h>

int compute_containers_filled(int N, int X) {
    int pyramid[N][N];
    int i, j, volume, count;

    // Initialize the pyramid with empty containers
    for (i = 0; i < N; i++) {
        for (j = 0; j < i+1; j++) {
            pyramid[i][j] = 0;
        }
    }

    // Fill the top container at each level
    for (i = 0; i < N; i++) {
        for (j = 0; j < i+1; j++) {
            volume = pyramid[i][j];

            // Check if the container overflows
            if (volume + 1 > X) {
                break;
            }

            // Fill the container
            pyramid[i][j] = volume + 1;

            // Check if the containers below are fully filled
            if (i+1 < N && pyramid[i+1][j] < X) {
                break;
            }
            if (i+1 < N && pyramid[i+1][j-1] < X) {
                break;
            }
        }
    }

    // Count the number of fully filled containers
    count = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < i+1; j++) {
            count += pyramid[i][j];
        }
    }

    return count;
}

int main() {
    int N, X;

    // Read input
    printf("Enter the number of levels (N): ");
    scanf("%d", &N);
    printf("Enter the target volume (X): ");
    scanf("%d", &X);

    // Print the result
    printf("Number of fully filled containers: %d\n", compute_containers_filled(N, X));

    return 0;
}