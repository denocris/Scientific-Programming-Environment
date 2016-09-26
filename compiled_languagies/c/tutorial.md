# Compiling C

## Compiling and linking

Building an application is a two steps process:

Compile every `.c` file in a `.o` file:

```
gcc -c a.c -o a.o
gcc -c b.c -o b.o
```
compile source file in machine language. 

Link every `.o` into an executable:

```
gcc a.o b.o -o myprog
```

Say in `a.c` I call a function in `b.c` the linker will find a reference to this function in `a.o` and the function itself in `b.o` and it replaces the reference with the concrete address of this function.

It is important to stress that this is a two phases process. This is the same no matter the operating system. 

Start a new file a.c:

```c
#include<stdio.h>

void foo()
{
    printf("Ciao Bello\n");
}

```
The `main` file:

```c
int main()
{
foo();
return 0;
}
```

Compile with:

```
gcc -c a.c -o a.o
gcc -c b.c -o b.o
```
what happens if it was `c++`? Check the code...

Now I have the object files `a.o` and `b.o`. I link the two guys together:

```
gcc b.o a.o -o myprog
``` 

Linking is the stage where I resolve calls from one object file to the other.

## Errors

- Compiler errors:
    - Your code does not follow the C "syntax".
    - You reference a variable that has not been "declared".
    - You call a function that has not been "declared" (c++).

- Linker errors:
    - You call a function that has been "declared" but not "implemented". 
      in `b.c` try to declare `foo2` and compile works, linking not.

- Important: When figuring out what's wrong, need to know which "phase" you're in.

- Errors often "cascade" start at the top (i.e., the first error message)

- If there are many error messages, use the command
```
gcc -c a.cc -o a.o 2>&1 | less
```
Here, `2>&1` "redirects" stderr to stdout, (pipe only works on stdout), 
so that it can
serve as input to ``less``.

- Linker errors can only happen once everything has been
compiled.

### Makefile

Archaic, confiusing...

```
a.o: a.c
	gcc -c a.c -o a.o

b.o: b.c
	gcc -c b.c -o b.o

myprog: a.o b.o
	gcc a.o b.o -o myprog

clean:
	rm *.o *~
```

Chek that it compiles ony modified stuff.
