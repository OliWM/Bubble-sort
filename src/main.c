#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

char letter_arr1[] = {'z', 'S', 's', 'a'};

int number_arr1[] = {4, -1, 2, 9};

int values_in_number_array = sizeof(number_arr1) / sizeof(number_arr1[0]);
int values_in_letter_array = sizeof(letter_arr1) / sizeof(letter_arr1[0]);
// dividing by first value because sizeof measures memory,
// so by dividing we get the number of values in the array
// no matter the size of each value in bytes

int main() {
  puts("If we bubble sort the array: ");

  for (int i = 0; i < sizeof(letter_arr1) / sizeof(letter_arr1[0]); i++) {
    printf("%c ", letter_arr1[i]);
  }
  puts("\n"),
      letter_bubble_sort(letter_arr1, values_in_letter_array, letters_in_order);
  puts("We get the array:");
  for (int i = 0; i < sizeof(letter_arr1) / sizeof(letter_arr1[0]); i++) {
    printf("%c ", letter_arr1[i]);
  }
  puts("\n\nIf we bubble sort the array: ");
  for (int i = 0; i < sizeof(number_arr1) / sizeof(number_arr1[0]); i++) {
    printf("%d ", number_arr1[i]);
  }
  puts("\n"),
      number_bubble_sort(number_arr1, values_in_number_array, numbers_in_order);
  puts("We get the array:");
  for (int i = 0; i < sizeof(number_arr1) / sizeof(number_arr1[0]); i++) {
    printf("%d ", number_arr1[i]);
  }

  return 0;
}
