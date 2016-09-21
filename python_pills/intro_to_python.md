# Why Python

The best way to test a tool is to try it...

```python
import antigravity
```
Try asking python about itself...

```python
import this
```

```
The Zen of Python, by Tim Peters

Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.
Special cases aren't special enough to break the rules.
Although practicality beats purity.
Errors should never pass silently.
Unless explicitly silenced.
In the face of ambiguity, refuse the temptation to guess.
There should be one-- and preferably only one --obvious way to do it.
Although that way may not be obvious at first unless you're Dutch.
Now is better than never.
Although never is often better than *right* now.
If the implementation is hard to explain, it's a bad idea.
If the implementation is easy to explain, it may be a good idea.
Namespaces are one honking great idea -- let's do more of those!
```

This two little jokes where intended to demonstrate that programming can be fun, using the right tool for the right task. We had fun, meanwhile, and we already learned something:
```python
import module_name as give_it_an_handy_name
```
A python *Module* is, ~~is a file containing Python definitions and statements.~~ Sorry about that, sofware documentation can be criptic...

Let's try again. A python *Module* is a collection of functionalities that some good soul wrote for you. It is also a very handy way to collect your own code. It is such a smart idea that you only need to `import` it and `give_it_an_handy_name`

# Tutorial

The first program you want to write is usually called `'Hello World'`. The programmer usually asks the computer to `print` a *string* (a series of characters) containing the message `'Hello World!'`. Try guessing how to do that in python:

```
print('Hello World!')
```

Not that we still need to convince you, about the beauty of python, but let's see the `'Hello World'` program in different languages. Start with C:

```c
#include <stdio.h>
int main()
{
  printf("Hello world\n");
  return 0;
}
```
Now C++

```c++
#include <iostream>
int main()
{
  std::cout << "Hello World!";
}
```
Last, but not least, the good old fortran:

```fortran
program hello
write(*,*) "Hello World!"
end program hello
```

Of course, if you ever want to run any of the above, you have to save the program to a file, compile it, see if works, work your way through `segmentation fault`s...


The first thing beginners will be surprised of, is the amount of in formation you can get from the computer, So why not asking Python, some help about the function `print`:

```python
print(?)
```

## Variables
Variables are simply names which point to any value or object. They can be of different types:

```python
a_string = "hello, world"
an_integer = 12
a_float = 3.14
a_boolean = True
nothing = None
```
The experienced programmer may have already noticed one Python feature: dynamic typing. The value or type of a variable may be changed at any time. The situation is different in C++ where you need to declare variables:

```C++
std::string  a_string = "hello, world";
int an_integer = 12;
float a_float = 3.14;
bool a_boolean = true;
```
Defining `nothing` in C++ isn't difficult but a little delicate... Why bother now?

Next natural step is to print and control those variables, and some other expressions:

```python
print(a_string)
print(an_integer)
print(a_float)
print(a_boolean)
print(nothing)
print(12)
print((5+3)/2)
```

## Strings

Strings are treated in a very natural, and elegant way by python: 

```python
string_single_quotes = 'abc'
string_double_quotes = "abc"
string_triple_quotes = """this is
a multiline
string."""
print(string_single_quotes)
print(string_double_quotes)
print(string_triple_quotes)
```

This is useful when needed to include quotes in a string:

```
string1 = 'hello "world"'
string2 = "don't"
print(string1)
print(string2)
```

The other option is to use backslashes:

```python
string2 = 'don\'t'
print(string2)
```

Be careful about backslashes in paths:
```
Win_path = 'C:\\Windows\\System32'
```

Strings are objects which support many operations:

```python
strings = string1 + " : " + string2
print(strings)
print(len(strings))
strings_uppercase = strings.upper()
print(strings_uppercase)
```

In Python you will notice that it will be very common the sintax `object.some_method()`. This is typical in object oriented programming. The string object is no exeption. Take the `string = ' abdefghiabc '`, and first `strip` out the opening and closing spaces. Then `replace` the string `abc` with `123`

```python
string = ' abcdefghiabc '
print(string)
string = string.strip()
print(string)
string = string.replace('abc','123')
print(string)
```

```python
i = 12
s = str(i)
print(s+' I am a string')
s = '23'
i = int(s)
print(i, 'I am a number')
```

Exercise: in the last line change the comma to `+`, why are you getting an error?

## Lists

A list is a dynamic array of any objects. It is declared with square
brackets:

```python
mylist = [1, 2, 3, 'abc', 'def']
print(mylist)
```

Access a specific element by index (index starts at zero):

```python
third_item = mylist[2]
print(third_item)
```

List operations:

```python
mylist[2] = 'new value' 
print(mylist)
mylist.append('another value')
print(mylist)
mylist.remove('abc')
print(mylist)
length = len(mylist)
longlist = mylist + [4,5,6]
print(longlist)
```

Slicing is extracting a sublist from a list:

```python
first_two_items = mylist[0:2] 
print(first_two_items)
third_and_fourth = mylist[2:4]
print(third_and_fourth)
fourth_up_to_end = mylist[3:]
print(fourth_up_to_end)
last_two_items = mylist[-2:]
print(last_two_items)
first_two_items2 = mylist[:2]
print(first_two_items2)
```

Lists may contain lists (it works like a 2d array):

```python
mylist2 = [mylist, 'abc', mylist, [1, 2, 3]]
print(mylist2)
item1 = mylist2[3][2]
print(item1)
item2 = mylist2[0][4]
print(item2)
```

## Touples

A tuple is similar to a list but it is a fixed-size, immutable
array: once a tuple has been created, its elements may not be changed,
removed, appended or inserted.  It is declared using parentheses and
comma-separated values,

```python
a_tuple = (1, 2, 3, 'abc', 'def') 
print(a_tuple)
```

but parentheses are optional:

```python
a_tuple = 1, 2, 3, 'abc', 'def'
print(a_tuple)
```

## Blocks and Indentation (control flow)
* Blocks of code are delimited using indentation, either spaces or tabs at the beginning of lines.

  * This is one of the main differences of Python over other
    languages, and usually the main reason why people love it or hate
    it. ;-) 
  * Tip: NEVER mix tabs and spaces in a script, it may result in
    tricky bugs.  

* From my experience, the safest solution is to always use 4-spaces 
  (or 2-spaces) indents, never tabs. (because each editor may convert
  tabs either to 2, 4 or 8 spaces)
* Alternatively, use ipython notebooks, like this one, which automatically indent for you...

```python
a = 'test'

if a == 3:
    print('The value of a is:')
    print('a=3')
if a != 'test':
    print('a is not "test"' )
    test_mode = False
else:
    print('The value of a is:')
    print('a="test"')
    test_mode = True
```

## While and for loops

```python
a=1
while a<10:
    print('while loop, a= :', a)
    a += 1

for a in range(10): 
    print('for loop, a= :', a)

my_list = [2, 4, 8, 16, 32]
for a in my_list:
    print('iterate over a list, a= :', a)


newlist = [10**i for i in range(-10,1)]
print(newlist)
```

## Function definitions

```python
def mysum(a, b):
    return a+b

def my_eval(f, x):
    return f(x)

print(mysum(1, 2))
print(mysum('Ciao ', 'mondo'))

print(my_eval(float, 1))
print(my_eval(sorted, 'ciao'))
```

## Importing external packages: Plotting

```python
%matplotlib inline
# This is a comment...
# Import some packages to plot and work with arrays of floats
import numpy as np # Now all numpy classes are available as np.name
import matplotlib.pylab as pl # same as above

# Alternatively, you could use 
# %pylab inline
# which would import all graphics, matplotlib and numpy in the current
# namespace, as if you typed 
# from numpy import *

# Make equidistant linear space between 0 and 1 with 101 points
x = np.linspace(0,1,101);
y = np.sin(x*(2*np.pi))

pl.plot(x,y)
```

# Numpy

Numpy provides a very powerful array container. The first line of this ipython notebook has imported all of numpy functionalities in your notebook, just as if you typed:

```python
from numpy import *
```

    
Create a numpy array whith entries that range form 0 to 64. Use the correct numpy function to do so. Call it `x`.

```python
x = np.arange(0,64)
```

Reshape the one dimensional array, to become a 4 rows 2 dimensional array, let numpy evaluate the correct number of culumns. Call it `y`.

```python
y = x.reshape(4,-1)
```

Get the following *slices* of `y`:

* All the rows and the first three colums. Name it `sl1`.
* All the colums and the first three rows. Name it `sl2`.
* Third to sixth (included) columns and all the rows. Name it `sl3`.
* The last three columns and all the rows. Name it `sl4`.

```python
sl1 = y[:,:3]
sl2 = y[:3,:]
sl3 = y[:,3:7]
sl4 = y[:,-3:]
```

Now reshape the array, as if you wanted to feed it to a fortran routine. Call it `z`.

```python
z = x.reshape((4,-1),order='F')
```

Comment on the result, what has changed with respect to `y`? 

Notice that in the first case the array has been ordered row-wise, while in the second case column wise, because that's the default array ordering in fortran.

```
x[3] = 666666
print(x)
print(y)
print(z)
```

Any variable in python, except built in types, are pointers to addresses in memory. When we assigned y=x,  z=x, we asked python to setup a pointer called y to the memory pointed by x. We did exactely the same thing when we assigned z=x. Result: x, y, and z are pointing to the same mememory. When we changed one value inside the memory of x, yand z where still poiting to the same memory. Consequence: changing one entry of x, changed the corresponding value in y and z.
Cons: This behaviour might seem misleading, and sometimes it is. The programmer should be aware of what he is doing.
Pros: Memory saving.

## Arrays and Matrices

Define 2 arrays, `A` of dimensions (2,3) and `B` of dimension (3,4).

* Perform the operation `C = A.dot(B)`. Comment the result, or the error you get.

```python
A = array([[1,2,3],[4,5,6]])
B = array([[1,2,3,4],[5,6,7,8],[9,10,11,12]])
C = A.dot(B)
```

I perform the matrix-matrix multiplication between two dimensional arrays.

* Perform the operation `C = A*(B)`. Comment the result, or the error you get.

In the second I multiply element by element the two and I get an error.

 * Convert A and B, from arrays to matrices and perform `A*B`. Comment the result.

```python
A = asmatrix(A)
B = asmatrix(B)
C = A*B
```