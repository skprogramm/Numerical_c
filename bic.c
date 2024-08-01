// #include <stdio.h>
// #include <math.h>

// // Function prototypes
// double equation1(double x);
// double equation2(double x);
// double equation3(double x);
// void bisection(double (*func)(double), double a, double b, double tol, int max_iter);

// int main() {
//     int max_iter = 1000;  // Maximum number of iterations
//     double tol = 1e-6;    // Tolerance

//     // Finding root for equation 1: x^3 - 4x + 1 = 0
//     printf("Finding root for equation 1: x^3 - 4x + 1 = 0\n");
//     bisection(equation1, 0.0, 2.0, tol, max_iter);

//     // Finding root for equation 2: x^4 + 0.5x^3 - 8.5x^2 - 0.5x + 7.5 = 0
//     printf("\nFinding root for equation 2: x^4 + 0.5x^3 - 8.5x^2 - 0.5x + 7.5 = 0\n");
//     bisection(equation2, 2.0, 3.0, tol, max_iter);

//     // Finding the value of (78)^(1/9)
//     printf("\nFinding the value of (78)^(1/9)\n");
//     bisection(equation3, 1.5, 2.0, tol, max_iter);

//     return 0;
// }

// // Definition of equation 1: x^3 - 4x + 1
// double equation1(double x) {
//     return x * x * x - 4 * x + 1;
// }

// // Definition of equation 2: x^4 + 0.5x^3 - 8.5x^2 - 0.5x + 7.5
// double equation2(double x) {
//     return pow(x, 4) + 0.5 * pow(x, 3) - 8.5 * pow(x, 2) - 0.5 * x + 7.5;
// }

// // Definition of equation for (78)^(1/9) - x = 0
// double equation3(double x) {
//     return pow(x, 9) - 78;
// }

// // Bisection method implementation
// void bisection(double (*func)(double), double a, double b, double tol, int max_iter) {
//     double c;
//     int iter = 0;

//     printf("%-10s%-12s%-12s%-12s%-12s\n", "Iteration", "a", "b", "c", "f(c)");
    
//     while (iter < max_iter) {
//         c = (a + b) / 2.0;
//         double fc = func(c);

//         printf("%-10d%-12.6f%-12.6f%-12.6f%-12.6f\n", iter + 1, a, b, c, fc);

//         if (fabs(fc) < tol || (b - a) / 2.0 < tol) {
//             printf("Root found: %.6f\n", c);
//             return;
//         }

//         if (fc * func(a) > 0) {
//             a = c;
//         } else {
//             b = c;
//         }

//         iter++;
//     }

//     printf("Max iterations reached. Approximate root: %.6f\n", c);
// }
