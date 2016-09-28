#include "matrix_tools.h"
#include "vector_tools.h"
#include "mat_vect_multy.h"



int main()
{
  matrix_t my_mat;
  vector_t my_vect;
  vector_t my_vect_out;

  int r = 2;
  int c = 3;

  int k = c;

  allocate_m(&my_mat,r,c);
  allocate_v(&my_vect,k);
  allocate_v(&my_vect_out,r);
  assign_zero_m(&my_mat);
  assign_zero_v(&my_vect);

  int i;
  int j;
  int elem_m;
  for (i = 0; i < my_mat.row; i++)
      for (j = 0; j < my_mat.col; j++)
      {
        elem_m = i+j;
        assign_ij(i,j,elem_m,&my_mat);
        //printf("M[%d,%d] = %e\n",i,j,assign_ij(i,j,elem,&my_mat));
      }
/*
  printf("my_mat[%d,%d] = %e\n",0,0,my_mat.data[0]);
  printf("my_mat[%d,%d] = %e\n",0,1,my_mat.data[1]);
  printf("my_mat[%d,%d] = %e\n",0,2,my_mat.data[2]);
  printf("my_mat[%d,%d] = %e\n",1,0,my_mat.data[3]);
  printf("my_mat[%d,%d] = %e\n",1,1,my_mat.data[4]);
  printf("my_mat[%d,%d] = %e\n",1,2,my_mat.data[5]);
*/
  int s;
  int elem_v;
  for (i = 0; i < my_vect.size; i++)
      {
        elem_v = i;
        assign_i(i,elem_v,&my_vect);
      }

  multiply_mat_vect(&my_mat,&my_vect,&my_vect_out);

  //printf("my_vect_out[%d] = %e\n",0,my_vect_out.data[0]);
  //printf("my_vect_out[%d] = %e\n",1,my_vect_out.data[1]);
  //printf("my_vect_out[%d] = %e\n",1,my_vect_out.data[2]);

  deallocate_m(&my_mat);
  deallocate_v(&my_vect);
  deallocate_v(&my_vect_out);


  printf("The product matrix - vector is done!\n");
}
