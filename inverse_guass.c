#include <stdio.h>

#define N 3  // Define the size of the matrix (N x N)

// Function to perform the Gaussian elimination with partial pivoting
void gaussElimination(double matrix[N][N], double inverse[N][N]) {
    for (int i = 0; i < N; i++) {
        // Partial pivoting
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap the rows in both the matrix and the inverse matrix
        for (int k = 0; k < N; k++) {
            double temp = matrix[maxRow][k];
            matrix[maxRow][k] = matrix[i][k];
            matrix[i][k] = temp;

            temp = inverse[maxRow][k];
            inverse[maxRow][k] = inverse[i][k];
            inverse[i][k] = temp;
        }

        // Make the diagonal contain all 1's
        double diagElement = matrix[i][i];
        for (int k = 0; k < N; k++) {
            matrix[i][k] /= diagElement;
            inverse[i][k] /= diagElement;
        }

        // Make the elements below and above the diagonal 0
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < N; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
}

int main() {
    double matrix[N][N] = {
        {2, 1, 1},
        {1, 3, 2},
        {1, 0, 0}
    };

    double inverse[N][N] = {0};  // Initialize the inverse matrix as an identity matrix
    for (int i = 0; i < N; i++) {
        inverse[i][i] = 1;
    }

    gaussElimination(matrix, inverse);

    // Print the inverse matrix
    printf("The inverse of the given matrix is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%0.3lf ", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
