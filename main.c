#include <stdio.h>

int main(int, char **) {
  char userMove[30];

  printf("Enter your move: \n");
  scanf("%s", userMove);

  printf("user move: %s", userMove);
}
