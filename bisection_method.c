
#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 0.00001

// Function to evaluate the equation f(x) = x^3 - 4x^2 - 7
double f(double x) {
    return x * x * x - 4 * x * x - 7;
    // return pow(x, 9) - 78;
}

// Bisection Method to find the root
void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c;
    printf("-------------------------------------------------------------\n");
    printf("| Iteration |      a      |      b      |      c      | f(c) |\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 1; i <= MAX_ITER; i++) {
        // Find midpoint
        c = (a + b) / 2;

        // Print the current iteration and values
        printf("|    %3d    | %10lf | %10lf | %10lf | %10lf |\n", i, a, b, c, f(c));

        // Check if we've found the root or the interval is small enough
        if (fabs(f(c)) <= EPSILON) {
            printf("-------------------------------------------------------------\n");
            printf("The root is: %lf\n", c);
            return;
        }

        // Decide the side to repeat the steps
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("-------------------------------------------------------------\n");
    printf("The root after %d iterations is: %lf\n", MAX_ITER, c);
}

int main() {
    double a, b;
    
    // User input for the interval [a, b]
    printf("Enter the value of a (initial guess 1): ");
    scanf("%lf", &a);
    
    printf("Enter the value of b (initial guess 2): ");
    scanf("%lf", &b);

    // Call bisection method
    bisection(a, b);

    return 0;
}
