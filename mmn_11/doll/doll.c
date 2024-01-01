/**
 * @file main.c
 * @brief A program to convert shekel amounts to dollars based on a given dollar rate.
 *
 * This program takes user input for a dollar rate and shekel amounts, then calculates and displays
 * the corresponding dollar amounts and their sum.
 *
 * The first value to be entered is the dollar rate in relation to the shekel, and the following
 * values are representations of shekel amounts in dollars.
 *
 * @remark General Description
 * The program will go through the input until it ends, and will print in a table format,
 * for each dollar value, the equivalent shekel value.
 * In the bottom row of the table, there will be printed the total amount of all the dollars
 * and the total amount of all the shekels that have been printed.
 *
 * @note The program assumes the correctness of the input.
 *
 * @author yehonatanke
 * @date 12/2023
 */

#include <stdio.h>

#define MAX_INPUT 1000 /**< The maximum input size for user input */

/**
 * @brief Main function of the program.
 * @details The program prompts the user to enter a dollar rate and shekel amounts,
 * then calculates and displays the corresponding dollar amounts and their sum.
 * @return 0 indicating successful execution.
 */
int main() {

    double shekelRates[MAX_INPUT];        /**< Array to store shekel rates in dollars. */
    int shekelCount = 0;                  /**< Counter for shekel amounts. */
    int dollarCount = 1;                  /**< Counter for dollar amounts. */
    double totalShekels = 0;              /**< Total sum of shekel amounts. */
    double totalDollars = 0;              /**< Total sum of dollar amounts. */
    double inputAmount;                   /**< Temporary variable to store user input. */
    double equivalentDollars[MAX_INPUT];  /**< Array to store calculated equivalent dollar amounts. */

    /* User prompt */
    printf("Please enter the following information:\n");
    printf("1. Dollar rate in relation to the shekel.\n2. Shekel amounts in dollars (enter Ctrl-D, EOF, or insert any non-integer to finish).\n");
    printf("Note:\n- The first value should be the dollar rate in relation to the shekel.\n");
    printf("- The following values are representations of shekel amounts in dollars.\n");


    /* Input loop for shekel amounts */
    while (shekelCount < MAX_INPUT && scanf("%lf", &inputAmount) == 1) {
        shekelRates[shekelCount] = inputAmount; /**< Storing shekel rate in dollars */
        shekelCount++; /**< Incrementing shekel counter */
    }

    /* Calculation loop for dollar amounts */
    while (dollarCount < shekelCount) {
        equivalentDollars[dollarCount - 1] = shekelRates[0] * shekelRates[dollarCount]; /**< Calculating equivalent dollar amounts */

        /* Storing the sum of the money values */
        totalShekels += equivalentDollars[dollarCount - 1]; /**< Updating sum of shekel amounts */
        totalDollars += shekelRates[dollarCount]; /**< Updating sum of dollar amounts */
        dollarCount++; /**< Incrementing dollar counter */
    }

    /* Resetting counter for display loop */
    dollarCount = 1; /**< Resetting dollar counter */

    /* Displaying the results */
    printf("%-12s%-12s\n", "$", "IS");

    /* Display loop */
    while (dollarCount < shekelCount) {
        printf("%-12.2f%-12.2f\n", shekelRates[dollarCount], equivalentDollars[dollarCount - 1]); /**< Displaying amounts */
        dollarCount++; /**< Incrementing display counter */
    }

    /* Displaying the sum */
    printf("%-12.2f%-12.2f\n", totalDollars, totalShekels);

    return 0;
}
