#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

char letter_arr1[] = {'z', 'S', 's', 'a'};

char number_arr1[] = {4, -1, 2, 9};

// bubble_sort(char arr, bool(pair_is_in_order *)(char a, char b)); samler bare
// de andre funktioner

// pair_is_in_order

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

  bool in_order = first_letter < second_letter ? true : false;
  return in_order; // ændres til pair_is_in_order
}

bool numbers_in_ascending_order(char *numbers, int n) {
  bool numbers_in_order = numbers[n] < numbers[n + 1] ? true : false;
  return numbers_in_order; // ændres til pair_is_in_order
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
};

void swap_int(int *a, int *b) { // tror vi skal bruge en til fordi int fylder
                                // mere end char? Prøver lige uden
  int temp = *a;
  *a = *b;
  *b = temp;
};

int main() {
  swap(&number_arr1[0], &number_arr1[1]);
  printf("%d, %d", number_arr1[0], number_arr1[1]);
  return 0;
}
