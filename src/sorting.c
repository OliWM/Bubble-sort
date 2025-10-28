#include <ctype.h>
#include <sorting.h>
#include <stdio.h>

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