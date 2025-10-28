#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

/*error codes

-1 = input is not a letter or a number

*/

char letter_arr1[] = {'z', 'S', 's', 'a'};

int number_arr1[] = {4, -1, 2, 9};

// enum letter_number {
//   LETTER = 1,
//   NUMBER = 2
// }; // left at 1 and 2 because if we had an error it might be harder to catch
// if
//    // LETTER = 0, as a failed int function might also end up as 0.

// int letter_or_number(char a) {
//   if (a > 64 && a < 91 || a > 96 && a < 123) {
//     return LETTER;
//   }
//   if (a > 48 && a < 58) {
//     return NUMBER;
//   } else {
//     return -1;
//   }
// }

int n = 0;

int convert_lowercaseletters(char letter) {
  if ('a' <= letter && letter <= 'z') { // changed to taking 'a' instead of 97
                                        // as you can apparently just do that
    return letter - 32;
  } else if ('A' <= letter && letter <= 'Z') {
    return letter;
  } else {
    puts("Invalid input (convert)");
    return -1;
  }
}

bool letters_in_order(char a, char b) {

  int first_letter = convert_lowercaseletters(a);
  int second_letter = convert_lowercaseletters(b);

  bool is_letter_in_order = first_letter <= second_letter ? true : false;
  return is_letter_in_order;
}

bool numbers_in_order(int a, int b) {
  bool is_number_in_order = a <= b ? true : false;
  return is_number_in_order;
}

// bool pair_is_in_order(char a, char b) {
//   if (letter_or_number(a) == LETTER) {
//     return letters_in_order(a, b);
//   };
//   if (letter_or_number(a) == NUMBER) {
//     return numbers_in_ascending_order(a, b);
//   };
// }

void letter_swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
};

void number_swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};

int values_in_number_array = sizeof(number_arr1) / sizeof(number_arr1[0]);
int values_in_letter_array = sizeof(letter_arr1) / sizeof(letter_arr1[0]);
// dividing by first value because sizeof measures memory,
// so by dividing we get the number of values in the array
// no matter the size of each value in bytes

void letter_bubble_sort(char arr[], int len,
                        bool (*letters_in_order)(char, char)) {

  while (true) {
    bool did_swap = false;
    for (size_t i = 0; i < len - 1; i++) { // len -1 because we compare one
                                           // ahead
      if (!letters_in_order(arr[i], arr[i + 1])) {
        letter_swap(&arr[i], &arr[i + 1]);
        did_swap = true;
      }
    }
    if (!did_swap) {
      break;
    };
  }
};

void number_bubble_sort(int arr[], int len,
                        bool (*numbers_in_order)(int, int)) {

  while (true) {
    bool did_swap = false;
    for (size_t i = 0; i < len - 1; i++) { // len -1 because we compare one
                                           // ahead
      if (!numbers_in_order(arr[i], arr[i + 1])) {
        number_swap(&arr[i], &arr[i + 1]);
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
  puts("\n"),
      letter_bubble_sort(letter_arr1, values_in_letter_array, letters_in_order);
  for (int i = 0; i < sizeof(letter_arr1) / sizeof(letter_arr1[0]); i++) {
    printf("%c ", letter_arr1[i]);
  }

  return 0;
}
