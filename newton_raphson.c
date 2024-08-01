#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 0.00001

// Function to evaluate the equation f(x) = x^3 - 4x^2 - 7
double f(double x) {
    return x * x * x - 4 * x * x - 7;
    // return pow(x, 9) - 78;
}

// Derivative of the function f(x), f'(x) = 3x^2 - 8x
double f_prime(double x) {
    return 3 * x * x - 8 * x;
}

// Newton-Raphson Method to find the root
void newton_raphson(double x0) {
    double x1;
    printf("--------------------------------------------\n");
    printf("| Iteration |      x0      |     f(x0)     |\n");
    printf("--------------------------------------------\n");

    for (int i = 1; i <= MAX_ITER; i++) {
        // Compute the next approximation
        x1 = x0 - f(x0) / f_prime(x0);

        // Print the current iteration and values
        printf("|    %3d    | %10lf | %10lf |\n", i, x0, f(x0));

        // Check if the difference is small enough (convergence)
        if (fabs(x1 - x0) <= EPSILON) {
            printf("--------------------------------------------\n");
            printf("The root is: %lf\n", x1);
            return;
        }

        // Update the current value to the new approximation
        x0 = x1;
    }

    printf("--------------------------------------------\n");
    printf("The root after %d iterations is: %lf\n", MAX_ITER, x1);
}

int main() {
    double x0;
    
    // User input for the initial guess x0
    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    // Call Newton-Raphson method
    newton_raphson(x0);

    return 0;
}
