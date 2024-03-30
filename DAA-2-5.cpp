#include <stdio.h>
#include <stdlib.h>

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int P1[half][half], P2[half][half], P3[half][half], P4[half][half], P5[half][half], P6[half][half], P7[half][half];
    int temp1[half][half], temp2[half][half];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = B12[i][j] - B22[i][j];
        }
    }
    strassen(half, A11, temp1, P1);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A11[i][j] + A12[i][j];
        }
    }
    strassen(half, temp1, B22, P2);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A21[i][j] + A22[i][j];
        }
    }
    strassen(half, temp1, B11, P3);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = B21[i][j] - B11[i][j];
        }
    }
    strassen(half, A22, temp1, P4);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A11[i][j] + A22[i][j];
            temp2[i][j] = B11[i][j] + B22[i][j];
        }
    }
    strassen(half, temp1, temp2, P5);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A12[i][j] - A22[i][j];
            temp2[i][j] = B21[i][j] + B22[i][j];
        }
    }
    strassen(half, temp1, temp2, P6);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A11[i][j] - A21[i][j];
            temp2[i][j] = B11[i][j] + B12[i][j];
        }
    }
    strassen(half, temp1, temp2, P7);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C12[i][j] = P1[i][j] + P2[i][j];
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C21[i][j] = P3[i][j] + P4[i][j];
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C22[i][j] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C
