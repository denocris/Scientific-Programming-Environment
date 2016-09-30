#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* #if defined(NDEBUG) */
/* #define my_assertion(ignore) (void *) 0 */
/* #else */

/* #define my_assertion(expr) \ */
/*   if (!(expr)){ \ */
/*   printf("ciao from assert\n"); \ */
/*   } */

/* #endif */



int main()
{
  int a = 3;
  int b = 5;

  assert(a==b);

  printf("ciao\n");
  return 0;
}
