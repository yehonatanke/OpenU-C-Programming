/**
 * @file message_utility.h
 * @brief Header file containing message constants for a matrix processing program.
 *
 * This header file defines constants for messages used in a matrix processing program.
 * These messages include an opening message, an exit message, a message for empty lines,
 * and a message for undefined command names.
 *
 * @remark
 * This file provides essential constants for displaying messages in a matrix processing program.
 * It includes an opening message to prompt user input, an exit message upon successful program
 * termination, a message for empty input lines, and a message for undefined command names.
 *
 * @note
 * These constants are designed to enhance the user experience by providing clear and informative
 * messages during program execution.
 *
 * @overview
 * - [Macro]  OPENING_MESSAGE: Opening message displayed at the start of the program.
 * - [Macro]  EXIT_MESSAGE: Exit message displayed upon successful program termination.
 * - [Macro]  EMPTY_LINE: Message indicating that the input line is empty.
 * - [Macro]  UNDEFINED_CMD: Message indicating an undefined command name error.
 *
 * @author Yehonatan Keypur
 */

#ifndef MESSAGE_UTILITY_H
#define MESSAGE_UTILITY_H

/**
 * @brief Opening message displayed at the start of the program.
 */
#define OPENING_MESSAGE "\nHello,\nPlease enter a command.\n"

/**
 * @brief Exit message displayed upon successful program termination.
 */
#define EXIT_MESSAGE "\nThank you for using the program. You have successfully processed the input. \nHave a great day!\n"

/**
 * @brief Message indicating that the input line is empty.
 */
#define EMPTY_LINE "The line is empty.\n"

/**
 * @brief Message indicating an undefined command name error.
 */
#define UNDEFINED_CMD "Undefined command name"

#endif /**< MESSAGE_UTILITY_H */
