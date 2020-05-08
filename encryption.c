#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define INPUT_BUFFER_LEN 255
#define OFFSET 2

char *offsetEncrypt(char *inputStr, int offset);

int main(void)
{
   char inputText[INPUT_BUFFER_LEN];
   char *cipherText = malloc(sizeof(int) * INPUT_BUFFER_LEN);;


   printf("Enter text: ");
   scanf("%s", inputText);

   cipherText = offsetEncrypt(inputText, OFFSET);

   printf("%s\n", cipherText);

   return 0;
}

char *offsetEncrypt(char *inputStr, int offset)
{
   int i;

   char *encStr = malloc(sizeof(char) * INPUT_BUFFER_LEN);

   for (i = 0; i < INPUT_BUFFER_LEN; i++)
   {
      encStr[i] = inputStr[i] + offset;
   }  

   return encStr;
}
   
