/**
 * @file my_cos.c
 * @brief A C program implementing the calculation of the cosine of an angle
 * using the Taylor series expansion with a configurable error limit.
 *
 * This program defines a function, my_cos, which approximates the cosine of a given
 * angle using the Taylor series expansion. It also includes a main function that
 * takes user input for the angle and displays the computed cosine values using both
 * the custom my_cos function and the standard library cos function for comparison.
 *
 * @author yehonatanke
 * @date 12/2023
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 /**< The mathematical constant Pi */
#define ERROR_LIMIT 0.000001      /**< desired maximum error */


/**
 * @brief Calculates the cosine of a given angle using the Taylor series expansion.
 *
 * This function takes an angle in radians and uses the Taylor series expansion
 * to compute an approximation of the cosine value.
 *
 * @param x The angle in radians for which the cosine is to be calculated.
 * @return The cosine of the given angle.
 */
double my_cos(double);

double sum;                    /**< the final result, the sum of the Taylor series of cos(x) */
double term;                   /**< the value of Taylor series to be added */
double factorial;              /**< The current factorial value */
double i;                      /**< The iterator for the Taylor series expansion */

double my_cos(double x) {
    factorial = 1;
    term = 1;
    sum = 0;
    i = 0;

    /* Reduce the angle to the range [0, 2*PI) */
    while (x < 0) {
        x += 2 * PI;
    }
    while (x >= 2 * PI) {
        x -= 2 * PI;
    }

    /* Taylor series expansion */
    while (ERROR_LIMIT <= fabs(term)) {
        term = (pow((-1), i) * (pow(x, 2 * i) / (factorial)));
        sum += term;
        i++;
        factorial *= (2 * i) * (2 * i - 1);
    }
    return sum;
}


/**
 * @brief The main function that takes user input for the angle and prints
 * the computed cosine using both the custom my_cos function and the standard cos function.
 *
 * This function prompts the user to enter a value for the angle (in radians),
 * computes the cosine using the custom my_cos function, and compares it with
 * the cosine calculated using the standard library cos function. The results
 * are then displayed for comparison.
 *
 * @return The exit status of the program.
 */
int main() {
    double x;

    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("The input value is: x = %f\n", x);

    /* Computing and displaying cosine using the custom function my_cos */
    printf("The cos of x using 'my_cos' is: %f\n", my_cos(x));

    /* Computing and displaying cosine using the standard library cos function */
    printf("The cos of x using the standard library cos(x) is: %f\n", cos(x));

    return 0;
}