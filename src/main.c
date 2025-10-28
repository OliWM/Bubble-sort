#include <sorting.h>
#include <stdbool.h>
#include <stdio.h>

char letter_arr1[] = {'z', 'S', 's', 'a'};
// aSsz
char number_arr1[] = {4, -1, 2, 9};
// -1, 2, 4, 9
// overven at gør så det er et userinput

// bubble_sort(char arr, bool(pair_is_in_order *)(char a, char b)); samler bare
// de andre funktioner

// pair_is_in_order

// tjek hvordan du beslutter om du skal bruge letter eller number

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
  return in_order;
}

bool numbers_in_ascending_order(char *numbers, int n) {
  bool numbers_in_order = numbers[n] < numbers[n + 1] ? true : false;
  return numbers_in_order;
}

/*swap brug pointers til at ændre addresserne
char arr[] = {1, 2, 3};
swap(arr[0], arr[2]);
// Now is arr = {3, 2, 1}*/

int main() {
  int n = 0;
  bool letter_in_order = letters_in_order(letter_arr1, n);

  printf("Is %c before %c? \n%s", letter_arr1[n], letter_arr1[n + 1],
         letter_in_order ? "True \n" : "False\n");

  bool number_in_order = numbers_in_ascending_order(number_arr1, n);

  printf("Is %d before %d? \n%s", number_arr1[n], number_arr1[n + 1],
         number_in_order ? "True\n" : "False\n");
  return 0;
}
