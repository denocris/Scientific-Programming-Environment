# Assignment

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

void assign_m(matrix_t *mat, double offset){
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

void assign_v(vector_t *vec, double offset);

void assign_i(const unsigned int  i, const double val, vector_t *vec);

void assign_zero_v(vector_t *vec);

void deallocate_v(vector_t *vec);

```