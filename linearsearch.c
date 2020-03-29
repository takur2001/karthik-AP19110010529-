#include <stdio.h>
 
long linear_search(long [], long, long);
 
int main()
{
   long array[100], search, b, n, position;
 
   printf("Enter number of elements in array\n");
   scanf("%ld", &n);
 
   printf("Input %d numbers\n", n);
 
   for (b = 0; b < n; b++)
      scanf("%ld", &array[b]);
 
   printf("Enter number to search\n");
   scanf("%ld", &search);
 
   position = linear_search(array, n, search);
 
   if (position == -1)
      printf("%d isn't present in the array.\n", search);
   else
      printf("%d is present at location %d.\n", search, position+1);
 
   return 0;
}
 
long linear_search(long a[], long n, long find) {
   long b;
 
   for (b = 0 ;b < n ; b++ ) {
      if (a[b] == find)
         return b;
   }
 
   return -1;
}