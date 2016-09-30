#include "matrix_tools.h"
#include "vector_tools.h"
#include "mat_vect_multy.h"
#include "solver.h"

int main()
{
  matrix_t my_mat;
  vector_t my_vect;
  vector_t my_vect_out;

  int r = 2;
  int c = 2;

  int k = c;

  allocate_m(&my_mat,r,c);
  allocate_v(&my_vect,k);
  allocate_v(&my_vect_out,r);
  assign_zero_m(&my_mat);
  assign_zero_v(&my_vect);

// Construct the matrix
  assign_ij(0,0,4,&my_mat);
  assign_ij(0,1,1,&my_mat);
  assign_ij(1,0,1,&my_mat);
  assign_ij(1,1,3,&my_mat);

  printf("%e   ",my_mat.data[0]);
  printf("%e\n",my_mat.data[1]);
  printf("%e   ",my_mat.data[2]);
  printf("%e\n",my_mat.data[3]);

// Construct the vector
  assign_i(0,1,&my_vect);
  assign_i(1,2,&my_vect);

  printf("%e\n",my_vect.data[0]);
  printf("%e",my_vect.data[1]);


  multiply_mat_vect(&my_mat,&my_vect,&my_vect_out);
  //sum_two_vectors(&my_vect,&my_vect2,&my_vect)

  int i;
  for (i = 0; i < my_vect.size; i++)
  {
    printf("________ main ______ b[%d] = %e\n",i,my_vect_out.data[i]);
  }


  //printf("main alpha = %e \n",compute_alpha(&my_mat, &my_vect, &my_vect));
  //printf("scalar product = %e \n",scalar_prod(&my_vect, &my_vect));

  vector_t x_sol = conj_grad_method(&my_mat,&my_vect);

  for (i = 0; i < my_vect.size; i++)
  {
    printf("________ main ______ x[%d] = %e \n",i,x_sol.data[i]);
  }


  deallocate_m(&my_mat);
  deallocate_v(&my_vect);
  deallocate_v(&my_vect_out);


  printf("The product matrix - vector is done!\n");
}
