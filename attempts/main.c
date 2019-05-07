#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include "test/test.h"

void testSprintf();
void printSizes();
void registerVarTest();
long getMicrotime();

int main() {
  printf("global variable: %d\n", foo);
  printSizes();
  testSprintf();
  /*registerVarTest();*/
  return 0;
}

void testSprintf() {
  char buff[11];
  sprintf(buff, "hello %corld", 'W');
  printf("buff: %s\n", buff);
}

void registerVarTest() {
  register int i = 1;
  long startTime = getMicrotime();
  while(i < 1000000) {
    ++i;
    printf("%i - > ", i);
  }
  printf("\nLoop takes %lu microseconds\n", getMicrotime() - startTime);
}

void printSizes() {
  printf("sizeof(int): %lu\n", sizeof(int));
  printf("sizeof(unsigned int): %lu\n", sizeof(unsigned int));
  printf("INT_MAX: %d\n", INT_MAX);
  printf("INT_MIN: %d\n", INT_MIN);
  printf("INT_MAX - INT_MIN: %i\n", (INT_MAX - INT_MIN));
  printf("UINT_MAX: %u\n", UINT_MAX);
}

long getMicrotime() {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

