#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 0.00001

// Function to evaluate the polynomial f(x) = x^3 - 6x^2 + 11x - 6
double f(double x) {
    return x * x * x - 6 * x * x + 11 * x - 6;
}

// Birge-Vieta Method to find the root of the polynomial
void birge_vieta(double coefficients[], int degree, double initial_guess) {
    double x = initial_guess;
    double b[degree + 1];
    double c[degree];
    int iter;

    printf("--------------------------------------------\n");
    printf("| Iteration |      x       |     f(x)      |\n");
    printf("--------------------------------------------\n");

    for (iter = 1; iter <= MAX_ITER; iter++) {
        // Step 1: Compute b coefficients
        b[degree] = coefficients[degree];
        for (int i = degree - 1; i >= 0; i--) {
            b[i] = coefficients[i] + x * b[i + 1];
        }

        // Step 2: Compute c coefficients (derivative)
        c[degree - 1] = b[degree];
        for (int i = degree - 2; i >= 0; i--) {
            c[i] = b[i + 1] + x * c[i + 1];
        }

        // Step 3: Update x using Newton's method formula
        double f_x = b[0];
        double f_prime_x = c[0];

        printf("|    %3d    | %10lf | %10lf |\n", iter, x, f_x);

        if (fabs(f_x) <= EPSILON) {
            printf("--------------------------------------------\n");
            printf("The root is: %lf\n", x);
            return;
        }

        // Update x using the formula: x = x - f(x)/f'(x)
        x = x - f_x / f_prime_x;
    }

    printf("--------------------------------------------\n");
    printf("The root after %d iterations is: %lf\n", MAX_ITER, x);
}

int main() {
    double coefficients[] = {-6, 11, -6, 1}; // Coefficients of x^3 - 6x^2 + 11x - 6
    int degree = 3;
    double initial_guess = 2.0;

    birge_vieta(coefficients, degree, initial_guess);

    return 0;
}
