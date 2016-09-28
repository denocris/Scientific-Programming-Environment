#ifndef __myexec_print_h_
#define __myexec_print_h_

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    size_t size;
    double * data;
} vector_t;


void allocate_v(vector_t *vect, unsigned int k);

void assign_zero_v(vector_t *vect);

void assign_i(const unsigned int i,
               const double elem, vector_t *vect);

void deallocate_v(vector_t *vect);

#endif
