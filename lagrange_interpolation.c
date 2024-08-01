#include <stdio.h>

// Function to perform Lagrange Interpolation
double lagrangeInterpolation(double x[], double fx[], int n, double x_val) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = fx[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (x_val - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Given table of values
    double x[] = {-3, 1, 0, 3, 5};
    double fx[] = {-30, -22, -12, 330, 3458};
    int n = sizeof(x) / sizeof(x[0]);
    
    // The value at which we need to find f(x)
    double x_val = 2.5;

    // Calculate f(x) using Lagrange Interpolation
    double result = lagrangeInterpolation(x, fx, n, x_val);

    // Print the result
    printf("The value of f(x) at x = %.1lf is %.2lf\n", x_val, result);

    return 0;
}
