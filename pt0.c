#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define ARRAY_SIZE 2000000
#define STRING_SIZE 16

int array_size;
char **char_array; //[ARRAY_SIZE][STRING_SIZE];
int char_counts[26];
struct timeval t1, t2;
double elapsedTime;
char hostname[1024];

char getRandomChar()
{
    int randNum = 0;
    char randChar = ' ';

    randNum = 26 * (rand() / (RAND_MAX + 1.0));     // pick number 0 < # < 25
    randNum = randNum + 97;             // scale to 'a'
    randChar = (char) randNum;

    // printf("%c", randChar);
    return randChar;
}

void init_arrays()
{
  int i, j, randNum;
  char randChar;

  char_array = (char **)malloc(sizeof(char *) * array_size);
  char_array[0] = (char *)malloc(sizeof(char) * array_size * STRING_SIZE);

  for(i = 0; i < array_size; i++) {
    char_array[i] = (*char_array + i * STRING_SIZE);
  }

  for ( i = 0; i < array_size; i++) {
    for ( j = 0; j < STRING_SIZE; j++ ) {
         char_array[i][j] = getRandomChar();
    }
  }

  for ( i = 0; i < 26; i++ ) {
    char_counts[i] = 0;
  }
}

void free_arrays()
{
  free(char_array[0]);
  free(char_array);
}

void count_array()
{
  char theChar;
  int i, j, charLoc;

  for ( i = 0; i < array_size; i++) {
    for ( j = 0; j < STRING_SIZE; j++ ) {
             theChar = char_array[i][j];
         charLoc = ((int) theChar) - 97;
         char_counts[charLoc]++;
    }
  }
}

void print_results()
{
  int i, total = 0;

  for ( i = 0; i < 26; i++ ) {
     total += char_counts[i];
     printf(" %c %d\n", (char) (i + 97), char_counts[i]);
  }
  // DATA <hostname> <array size> <total characters> <elapsed time> <version>
  printf("DATA\t%s\t%d\t%d\t%f\t%s\n", hostname, array_size, total, elapsedTime, "default");
}

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: pt0 <array_size>");
        exit(1);
    }

    gethostname(hostname, 1023);

    array_size = atoi(argv[1]);

    printf("DEBUG: starting loop on %s\n", hostname);

    init_arrays();

    gettimeofday(&t1, NULL);

    count_array();

    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; //sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

    print_results();

    return 0;
}

