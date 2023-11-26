#include "backend.h"
#include "operations/s21_arithmetic.h"
#include "operations/s21_common.h"


int main(){

    //Матрица поворота
    matrix_t round_matrix;
\
    
    matrix_t vector1, vector2;

    s21_create_matrix(3,1,&vector1);
    s21_create_matrix(3,1,&vector2);
    vector1.matrix[0][0] = 1.0;
    vector1.matrix[1][0] = 2.0;
    vector1.matrix[2][0] = 1.0;
    printf("\n");
    print_matix(&vector1);

    s21_mult_matrix(round_matrix,vector1,&vector2);
    printf("\n");
    print_matix(&vector2);

    return 0;
}