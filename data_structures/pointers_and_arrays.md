# Pointers and arrays

We edit and explain this piece of code:

```c
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
```

try to run:

```
valgrind --leak-check=yes ./array.x
```

now comment `free(b)` and try again:

```
valgrind --leak-check=yes ./array.x
```




We learn by mistakes: 

```c
void arraytest(int a[])
{
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}

void main()
{
    int arr[]={1,2};
    printf("%d \t %d",arr[0],arr[1]);
    arraytest(arr);
    printf("\n After calling fun arr contains: %d\t %d",arr[0],arr[1]);
}
```
In this code the non educated user expects the 
compiler to copy the aray into the `araytest` scope and manipulate the memory
inside the scope. 

Now comes a question: "How the compile nows at run time, what's the size of the
memory he has to copy?". We already know the answer: he does not know. 

This is why the compiler substitutes the original function
`void arraytest(int a[])` with:

```c
void arraytest(int *a)
{
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}
```
