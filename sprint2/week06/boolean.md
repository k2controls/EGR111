## Boolean values
In C, the bool data type is not natively supported in the language itself prior to C99 (the 1999 standard), but it is commonly used through the inclusion of the header <stdbool.h>, which defines bool as a macro.

```C
#include <stdbool.h> 
#include <stdio.h>
int main() 
{ 
  // review - true and false values
  int x;
  if (x)
    printf("true");
  x = -99;
  if (x)
    printf("true");
  x = 0;
  if (x)
    printf("true");
  else
    printf("false");

  bool a = true;
  bool b = false;
  if(a == 1)
    printf("It is true");
  if(b == 0)
    printf("B is false");
  if(a)
    printf("It is true");
  if(!b)
    printf("B is false");
  if(a && !b)
    printf("Is it true");
  return 0; 
}
``` 