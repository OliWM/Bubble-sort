#include <ctype.h>
#include <sorting.h>
#include <stdio.h>

// bubble_sort(char arr, bool(pair_is_in_order *)(char a, char b)); samler bare
// de andre funktioner

// pair_is_in_order

/* letters_in_order /brug ASCII values?
letters_in_order('a', 'b'); // true
letters_in_order('a', 'B'), // true
letters_in_order('b', 'a'); // false
letters_in_order('a', 'A'), // true */

/*numbers_ascending
numbers_in_ascending_order(1, 2); // true
numbers_in_ascending_order(1, 1); // true
numbers_in_ascending_order(1, -1); // false*/

/*swap brug pointers til at ændre addresserne
char arr[] = {1, 2, 3};
swap(arr[0], arr[2]);
// Now is arr = {3, 2, 1}*/