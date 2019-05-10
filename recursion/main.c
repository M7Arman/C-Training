#include <stdlib.h>
#include <stdio.h>

unsigned int fibonacci(int n);

unsigned int fibonacciLoop(int n);

long long factorial(unsigned int n);

long long factorialLoop(unsigned int n);

int main(){
  printf("factorial --> \t\t%llu\n", factorial(15));
  printf("factorialLoop --> \t%llu\n", factorialLoop(15));
  printf("fibonacci --> \t\t%u\n", fibonacci(15));
  printf("fibonacciLoop --> \t%u\n", fibonacciLoop(15));
  return 0;
}

unsigned int fibonacci(int n) {
  if(n < 2) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned int fibonacciLoop(int n) {
  int i;
  int n1 = 0, n2 = 1;
  unsigned int sum = 1;
  while(n > 2) {
    n1 = n2;
    n2 = sum;
    sum = n1 + n2;
    n--;
  }
  return sum;
}

long long factorial(unsigned int n) {
  if(n < 2) {
    return 1;
  }
  return factorial(n - 1) * n;
}

long long factorialLoop(unsigned int n) {
  int i;
  long long p = 1;
  for(i = 1; i <= n; i++) {
    p = p * i;
  }
  return p;
}
