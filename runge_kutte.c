#include <stdio.h>

// Function to evaluate dy/dx
double f(double x, double y) {
    return -x * y;
}

// Runge-Kutta 2nd Order Method
void rungeKutta2(double x0, double y0, double h, double x) {
    double k1, k2, y;

    printf("Runge-Kutta 2nd Order Method:\n");
    printf("  x\t\t y\n");
    while (x0 < x) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h, y0 + k1);

        y = y0 + 0.5 * (k1 + k2);

        x0 = x0 + h;
        y0 = y;

        printf("%0.5lf\t     %0.5lf\n", x0, y0);
    }
    printf("\n");
}

// Runge-Kutta 4th Order Method
void rungeKutta4(double x0, double y0, double h, double x) {
    double k1, k2, k3, k4, y;

    printf("Runge-Kutta 4th Order Method:\n");
    printf("  x\t\t y\n");
    while (x0 < x) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2);
        k4 = h * f(x0 + h, y0 + k3);

        y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        x0 = x0 + h;
        y0 = y;

        printf("%0.5lf\t     %0.5lf\n", x0, y0);
    }
    printf("\n");
}

int main() {
    double x0 = 0, y0 = 1; // Initial conditions: y(0) = 1
    double h = 0.01;       // Step size
    double x = 0.25;       // Point to which we need to solve the equation

    rungeKutta2(x0, y0, h, x);
    rungeKutta4(x0, y0, h, x);

    return 0;
}
