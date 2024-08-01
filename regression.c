#include <stdio.h>

int main() {
    // Given data points
    double X[] = {-4, -3, -2, -1, 0, 1, 2, 4, 5};
    double Y[] = {21, 12, 4, 1, 2, 7, 15, 30, 45, 67};
    int n = sizeof(X) / sizeof(X[0]);
    
    //store the sums
    double sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0, sumX3 = 0, sumX2Y = 0, sumX4 = 0;
    
    // Calculating the required sums
    for (int i = 0; i < n; i++) {
        sumX += X[i];
        sumY += Y[i];
        sumX2 += X[i] * X[i];
        sumXY += X[i] * Y[i];
        sumX3 += X[i] * X[i] * X[i];
        sumX2Y += X[i] * X[i] * Y[i];
        sumX4 += X[i] * X[i] * X[i] * X[i];
    }
    
    // Creating the augmented matrix for the normal equations
    double a[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };
    
    // Applying Gaussian elimination to solve the equations
    for (int i = 0; i < 3; i++) {
        // Partial pivoting
        for (int k = i + 1; k < 3; k++) {
            if (a[i][i] < a[k][i]) {
                for (int j = 0; j <= 3; j++) {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
        
        // Make the elements below the pivot elements equal to zero
        for (int k = i + 1; k < 3; k++) {
            double t = a[k][i] / a[i][i];
            for (int j = 0; j <= 3; j++) {
                a[k][j] -= t * a[i][j];
            }
        }
    }
    
    // Back substitution to find the values of a, b, and c
    double c = a[2][3] / a[2][2];
    double b = (a[1][3] - a[1][2] * c) / a[1][1];
    double a_coeff = (a[0][3] - a[0][2] * c - a[0][1] * b) / a[0][0];
    
    // Print the coefficients
    printf("The fitted quadratic equation is: y = %.4lfx^2 + %.4lfx + %.4lf\n", a_coeff, b, c);
    
    return 0;
}
