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

void v1_equal_v2(vector_t *vect1,vector_t *vect2)
{
  int i;

  for (i = 0; i < (vect1->size); i++)
      {
        vect1->data[i]=vect2->data[i];
        //printf("V[%e]\n", vect->data[i]);
      }
}

void assign_i(const unsigned int i,
               const double elem, vector_t *vect)
{
  vect -> data[i]= elem;
  //printf("V[%d] = %e\n",i,elem);
}

double scalar_prod(vector_t* v1,vector_t* v2)
{
  int k;
  double scalarp = 0;
  for (k = 0; k < (v1->size); k++)
  {
    scalarp += v1->data[k]*v2->data[k];
  }
  return scalarp;
}

void sum_two_vectors(vector_t* v1,vector_t* v2,vector_t* v_out)
{
  int k;
  for (k = 0; k < (v1->size); k++)
  {
    v_out->data[k] = v1->data[k] + v2->data[k];
  }
}

void deallocate_v(vector_t *vect)
{
  free(vect->data);
  vect->size=0;
}
