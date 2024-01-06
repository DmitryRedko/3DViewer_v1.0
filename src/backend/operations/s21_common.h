#ifndef S21_COMMON_H
#define S21_COMMON_H

#include "../backend.h"
void s21_init_matrix(double value, matrix_t *A);
void s21_fill_matrix(matrix_t *A, double value);
void s21_fill_matrix_by_list(matrix_t *matrix, double *list);
int diag(matrix_t *A, double *det);
int check_for_zero(matrix_t *A, int k, double *det);
void do_zero(matrix_t *A, int i, int j);
void swap(matrix_t *A, int i, int j);
double det(matrix_t *A);

int diag_invert(matrix_t *matrix, matrix_t *eye, double *det);
int check_for_zero_invert(matrix_t *matrix, matrix_t *eye, int k, double *det);
void invert_invert(matrix_t *matrix, matrix_t *eye);
void do_diag_invert(matrix_t *matrix, matrix_t *eye);
void reset_eye_invert(matrix_t *matrix);
void create_eye(matrix_t *matrix);
void print_matix(matrix_t *matrix);

#endif