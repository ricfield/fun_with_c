#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM_NUMBER 250
#define REPORTING_VERBOSITY 10
#define ARGUMENT_COUNT 3
#define ARRAY_SIZE_LIMIT 50000

int main(int argc, char *argv[])
{
   time_t beginning_time = time(NULL);
   time_t ending_time;
   time_t current_time;
   int rows = atoi(argv[1]);
   int columns = atoi(argv[2]);

   if (argc != ARGUMENT_COUNT)
   {
      printf("\nUSAGE: matrix_addition <rows> <columns>\n\n");
      exit(-1);
   }

   if (rows > ARRAY_SIZE_LIMIT || columns > ARRAY_SIZE_LIMIT)
   {
      printf("\nArray size limit exceeded.\n\n");
      printf("%d rows exceeds size limit of %d.\n", rows, ARRAY_SIZE_LIMIT);
      printf("%d columns exceeds size limit of %d.\n", columns, ARRAY_SIZE_LIMIT);
      exit(-2);
   }


   int array_a[rows][columns];
   int array_b[rows][columns];
   int array_c[rows][columns];

   int i = 0;
   int j = 0;

   srand((unsigned) time(&current_time));
   
   printf("\n");


   // Fill array with random numbers

   printf("\nFilling array with random numbers and performing addition...\n");
   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < columns; j++)
      {
         array_a[i][j] = rand() % MAX_RANDOM_NUMBER;
         array_b[i][j] = rand() % MAX_RANDOM_NUMBER;
         array_c[i][j] = array_a[i][j] + array_b[i][j];
         printf("Row %d, Column %d done.\r", i + 1, j + 1);
         
      }
   }

   printf("\n");
   ending_time = time(NULL);

   printf("\nTotal program runtime: %f seconds\n\n", difftime(ending_time, beginning_time));
}

     
   
