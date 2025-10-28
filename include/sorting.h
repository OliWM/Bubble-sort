/**
 * @file sorting.h
 * @brief Header file for sorting functions.
 *
 * Provides functions to bubble sort arrays of either letters or numbers.
 * Includes helper functions for comparison, conversion, and element swapping.
 */

#ifndef SORTING_H
#define SORTING_H

#include <stdbool.h>

/**
 * @brief Converts a lowercase letter to its uppercase ASCII value.
 *
 * If the input character is already uppercase, it remains unchanged.
 * If the input is not an alphabetical character, the function prints
 * an error message and returns -1.
 *
 * @param letter The letter to be converted.
 * @return The uppercase ASCII value of the letter, or -1 on invalid input.
 */
int convert_lowercaseletters(char letter);

/**
 * @brief Checks if two letters are in alphabetical order.
 *
 * Both letters are converted to uppercase before comparison, ensuring
 * case-insensitive sorting.
 *
 * @param a The first letter.
 * @param b The second letter.
 * @return true if 'a' comes before or is equal to 'b' alphabetically, false
 * otherwise.
 */
bool letters_in_order(char a, char b);

/**
 * @brief Checks if two numbers are in ascending order.
 *
 * @param a The first number.
 * @param b The second number.
 * @return true if 'a' is less than or equal to 'b', false otherwise.
 */
bool numbers_in_order(int a, int b);

/**
 * @brief Swaps the values of two letters.
 *
 * @param a Pointer to the first letter.
 * @param b Pointer to the second letter.
 */
void letter_swap(char *a, char *b);

/**
 * @brief Swaps the values of two integers.
 *
 * @param a Pointer to the first number.
 * @param b Pointer to the second number.
 */
void number_swap(int *a, int *b);

/**
 * @brief Performs a bubble sort on an array of letters.
 *
 * Sorting is case-insensitive (via conversion to uppercase for comparison).
 * The comparison function is passed as a function pointer to allow flexibility.
 *
 * @param arr The array of letters to sort.
 * @param len The length of the array.
 * @param letters_in_order Function pointer to the comparison function.
 */
void letter_bubble_sort(char arr[], int len,
                        bool (*letters_in_order)(char, char));

/**
 * @brief Performs a bubble sort on an array of integers.
 *
 * The comparison function is passed as a function pointer to allow flexibility.
 *
 * @param arr The array of integers to sort.
 * @param len The length of the array.
 * @param numbers_in_order Function pointer to the comparison function.
 */
void number_bubble_sort(int arr[], int len, bool (*numbers_in_order)(int, int));

#endif /* SORTING_H */
