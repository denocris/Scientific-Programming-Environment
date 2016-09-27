#include <stdio.h>

int n =10; // global variable

void print_array(int *a)
{
    int i=0;

    for (i=0 ; i < n; i+=1)
        printf("entry %d value %d\n",i,a[i]);
}

void assign_zero_value(int* a)
{
    int i=0;

    for (i=0 ; i < n; i+=1)
        a[i] = 0;
}

int main()
{
    int * a[n]; // statically allocated array

    print_array(a);
    assign_zero_value(a);
    print_array(a);

    int * b;

    b = (int*) malloc(n*sizeof(int));

    assign_zero_value(b);
    print_array(b);

    free(b);
}
