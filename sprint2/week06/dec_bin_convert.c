// convert decimal to binary
// see https://www.programiz.com/c-programming/examples/binary-decimal-convert
#include <stdio.h>
#include <math.h>

// function prototype
long convert(int);

int main() 
{
    
  int n;
  long bin;
  
  printf("Enter a decimal number: ");
  scanf("%d", &n);
  
  // convert to binary using the convert() function
  bin = convert(n);
  
  printf("%d in decimal =  %ld in binary", n, bin);

  return 0;
}

// function definition - convert decimal to binary
long convert(int n) 
{

  // variable to store the result
  long bin = 0;

  int rem, i = 1;

  // loop to convert to binary
  while (n != 0) {
    
    // get remainder of n divided by 2
    rem = n % 2;
    
    // divide n by 2
    n /= 2;
    
    // multiply remainder by i
    // add the product to bin
    bin += rem * i;
    
    // multiply i by 10
    i *= 10;
  }

  return bin;
}