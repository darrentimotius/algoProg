#include <stdio.h>
#include <string.h>

int main(void) {
   char simonPattern[50];
   char userPattern[50];
   int userScore;
   int i;

   userScore = 0;

   scanf("%s", simonPattern);
   scanf("%s", userPattern);

   /* Your solution goes here  */
   int l = strlen(simonPattern);
   for (int i = 0; i < l; i++) {
    if (simonPattern[i] == userPattern[i]) userScore++;
    else break;
   }

   printf("userScore: %d\n", userScore);

   return 0;
}