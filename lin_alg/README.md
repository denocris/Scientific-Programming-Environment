# Linear Algebra References

[Douglas N. Arnold Lecture Notes](https://www.ima.umn.edu/~arnold/8445-8446.14-15/notes.pdf)

[THE LINEAR ALGEBRA BOOK!](http://bookstore.siam.org/ot50/)

[Do you feel bad if I tell you that there's a lod of good material on the Conjugate Gradient Wikipedia Page?](https://en.wikipedia.org/wiki/Conjugate_gradient_method)

## Linear Algebra Assignemnt

Develop the interface `solver.h` and the implementation `solver.c`. Use the developed library to implenet the conjugate gradient algorithm to solve a test linear system.

![cg_algorithm](https://wikimedia.org/api/rest_v1/media/math/render/svg/e300dfefdbd374cdee765397528a65a5736a50d3)

The interface for `solver.h` is extremely sophisticated:

```
void conjugate_gradient(matrix_t *a, vector_t *x, vector_t *b);
```

# Implementation Assignment

**One Dimensional arrays are DYNAMICALLY allocated!**

Write the matrix vector multiplication for these two data structures:

```c
typedef struct{
    size_t m, n;
    double * data;
} matrix_t;
```

```c
typedef struct{
    size_t size;
    double * data;
} vector_t;
```

The key function to be implemented is the matrix - vector multiplication:

```c
void vmult(matrix_x * m, vector_t * v_in, vector_t * v_out)
```

In my opinion useful functions for the matrix are:

```c
void allocate_m(matrix_t *mat, unsigned int m, unsigned int n);

void assign_m(matrix_t *mat){
Mij = n*i + j;
}

void assign_zero_m(matrix_t *mat);

void assign_ij(const unsigned int i, const unsigned int j, 
               const double val, matrix_t *mat);

void deallocate_m(matrix_t *mat);

void print_m( matrix_t *mat);

void vmult( matrix_t *mat, vector_t *v_in, vector_t *v_out );
```

In my opinion useful functions for the vector are:

```c
void allocate_v(vector_t *vec, unsigned int m);

void assign_v(vector_t *vec, double value);

void assign_i(const unsigned int  i, const double val, vector_t *vec);

double sum_prod(vector_t *a_in, vector_t *b_in){
sum += v_i * w_i}

void assign_zero_v(vector_t *vec);

void prod(vector_t *a_in, vector_t *b_in, vector_t *c_out){
c_i = a_i * b_i}

void diff(vector_t *a_in, vector_t *b_in, vector_t *c_out);
// c_out = a_in - b_in

void dump_b_into_a(vector_t *a_in, vector_t *b_in);
// a_in <- b_in

void deallocate_v(vector_t *vec);

void print_v(vector_t *vec);

void scale(vector_t *a_in, double val);

void a_equals_a_minus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha);

void a_equals_a_plus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha);
```

# Configuration Assignment

*Minimal:*

 - Split implementation and declaration for the functions you created into `.c` files and `.h` files.
 - Write a simple `Makefile` to compile your library and and a main file that tests the functionalities you implemented.
 
*(Optional)*

 - Oganize the library in diffferent folders: `include` and `src`.
 
*(Just in case...)* a very much appriciated case actually...
 
 - Use `cmake` to configure your libray.
