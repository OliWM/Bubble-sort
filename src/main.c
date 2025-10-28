#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

char letter_arr1[] = {'z', 'S', 's', 'a'};

char number_arr1[] = {4, -1, 2, 9};

enum letter_number {
  LETTER = 1,
  NUMBER = 2
}; // left at 1 and 2 because if we had an error it might be harder to catch if
   // LETTER = 0, as a failed int function might also end up as 0.

int letter_or_number(
    char a) { // no built in safety to check if we are really fed either a
              // number or letter and not something else.
  if (a > 64 && a < 91 || a > 96 && a < 123) {
    return LETTER;
  } else {
    return NUMBER;
  }
}

int n = 0;

int convert_lowercaseletters(char letter) {
  if (letter < 65 || (90 < letter && letter < 97) ||
      letter > 122) { // in *letter because we take the ASCII values
    // check om den er i store bogstaver eller små bogstaver range
    puts("Invalid input, non-letter detected");
    return -1;
  }
  if (97 < letter && letter < 122) {
    // convert lowercase letter value to equivalent uppercase value for
    // comparison
    return letter - 32;
  } else {
    return letter;
  }
}
// convert second letter too? but only temporarily

bool letters_in_order(char *letters, int n) {
  int j = n;
  int first_letter = convert_lowercaseletters(letters[j]);
  j++;
  int second_letter = convert_lowercaseletters(letters[j]);

  bool letter_is_in_order = first_letter < second_letter ? true : false;
  return letter_is_in_order;
}

bool numbers_in_ascending_order(char *numbers, int n) {
  bool number_is_in_order = numbers[n] < numbers[n + 1] ? true : false;
  return number_is_in_order;
}

bool pair_is_in_order(char a, char b) {
  if (letter_or_number(a) == LETTER) {
  };
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
};

void bubble_sort(char arr, bool (*pair_is_in_order)(char a, char b)) {

};

int main() {
  swap(&number_arr1[0], &number_arr1[1]);
  printf("%d, %d", number_arr1[0], number_arr1[1]);
  return 0;
}
