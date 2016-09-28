#include "vector_tools.h"

void allocate_v(vector_t *vect, unsigned int k)
{
  vect->size=k;

  vect->data = (double *)malloc(k*sizeof(double));
}

void assign_zero_v(vector_t *vect)
{
  int i;

  for (i = 0; i < (vect->size); i++)
      {
        vect->data[i]=0;
        //printf("V[%e]\n", vect->data[i]);
      }
}

void assign_i(const unsigned int i,
               const double elem, vector_t *vect)
{
  vect -> data[i]= elem;
  //printf("V[%d] = %e\n",i,elem);
}

void deallocate_v(vector_t *vect)
{
  free(vect->data);
  vect->size=0;
}
