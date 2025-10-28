#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

/*error codes

-1 = input is not a letter or a number

*/

char letter_arr1[] = {'z', 'S', 's', 'a'};

char number_arr1[] = {
    4, -1, 2, 9}; // kept number_arr1 as char instead of as int so that the
                  // whole programme should in theory work w. user input wether
                  // they put in an array of letters or numbers

enum letter_number {
  LETTER = 1,
  NUMBER = 2
}; // left at 1 and 2 because if we had an error it might be harder to catch if
   // LETTER = 0, as a failed int function might also end up as 0.

int letter_or_number(char a) {
  if (a > 64 && a < 91 || a > 96 && a < 123) {
    return LETTER;
  }
  if (a > 48 && a < 58) {
    return NUMBER;
  } else {
    return -1;
  }
}

int n = 0;

int convert_lowercaseletters(char letter) {
  if (letter < 65 || (90 < letter && letter < 97) || letter > 122) {
    puts("Invalid input, non-letter detected");
    return -1;
  }
  if (96 < letter && letter < 123) {
    // convert lowercase letter value to equivalent uppercase value for
    // comparison
    return letter - 32;
  } else {
    return letter;
  }
}

bool letters_in_order(char a, char b) {

  int first_letter = convert_lowercaseletters(a);
  int second_letter = convert_lowercaseletters(b);

  bool letter_is_in_order = first_letter < second_letter ? true : false;
  return letter_is_in_order;
}

bool numbers_in_ascending_order(char a, char b) {
  bool number_is_in_order = a < b ? true : false;
  return number_is_in_order;
}

bool pair_is_in_order(char a, char b) {
  if (letter_or_number(a) == LETTER) {
    return letters_in_order(a, b);
  };
  if (letter_or_number(a) == NUMBER) {
    return numbers_in_ascending_order(a, b);
  };
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
};

int values_in_number_array = sizeof(number_arr1) / sizeof(number_arr1[0]);
int values_in_letter_array = sizeof(letter_arr1) / sizeof(letter_arr1[0]);
// dividing by first value because sizeof measures memory,
// so by dividing we get the number of values in the array
// no matter the size of each value in bytes

void bubble_sort(char arr[], int len, bool (*pair_is_in_order)(char, char)) {

  if (letter_or_number(arr[0]) == LETTER) {
    len = values_in_letter_array;
  } else if (letter_or_number(arr[0]) == NUMBER) {
    len = values_in_number_array;
  }

  while (true) {
    bool did_swap = false;
    for (size_t i = 0; i < len - 1; i++) { // len -1 because we compare one
                                           // ahead
      if (!pair_is_in_order(arr[i], arr[i + 1])) {
        swap(&arr[i], &arr[i + 1]);
        did_swap = true;
      }
    }
    if (!did_swap) {
      break;
    };
  }
};

int main() {
  for (int i = 0; i < sizeof(letter_arr1) / sizeof(letter_arr1[0]); i++) {
    printf("%c ", letter_arr1[i]);
  }
  bubble_sort(letter_arr1, pair_is_in_order);
  for (int i = 0; i < sizeof(letter_arr1) / sizeof(letter_arr1[0]); i++) {
    printf("%c ", letter_arr1[i]);
  }

  return 0;
}
