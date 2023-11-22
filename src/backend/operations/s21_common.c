#include "s21_common.h"

#include <math.h>

void s21_init_matrix(double value, matrix_t *A) {
  // if (A == NULL || A->rows <= 0 || A->columns <= 0) {
  //   return;
  // }

  int count = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = value + count;
      count++;
      if (count == A->rows * A->columns) {
        return;
      }
    }
  }
}

void s21_fill_matrix(matrix_t *A, double value) {
  // if (A == NULL || A->rows <= 0 || A->columns <= 0) {
  //   return;
  // }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = value;
    }
  }
}

void s21_fill_matrix_by_list(matrix_t *matrix, double *list) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = list[i * matrix->columns + j];
    }
  }
}

void swap(matrix_t *A, int i, int j) {
  double temp;
  for (int k = 0; k < A->columns; k++) {
    temp = A->matrix[i][k];
    A->matrix[i][k] = A->matrix[j][k];
    A->matrix[j][k] = temp;
  }
}

int check_for_zero(matrix_t *A, int k, double *det) {
  int rows = k, cols = k;
  while (rows < A->rows - 1 && A->matrix[rows][cols] == 0) {
    rows++;
  }
  if (k != A->rows - 1 && A->matrix[rows][cols] != 0 && A->matrix[k][k] == 0) {
    swap(A, k, rows);
    *det *= (-1);
  }

  if (rows == A->rows - 1) {
    return 0;
  } else {
    return 0;
  }
}

void do_zero(matrix_t *A, int i, int j) {
  double mass[A->columns], temp1, temp2;
  if (A->matrix[j][i] != 0) {
    temp1 = A->matrix[i][i];
    temp2 = A->matrix[j][i];
    for (int k = 0; k < A->columns; k++) {
      mass[k] = A->matrix[i][k] / temp1 * temp2;
    }
    for (int k = 0; k < A->columns; k++) {
      A->matrix[j][k] -= mass[k];
    }
  }
}

int diag(matrix_t *A, double *det) {
  int flag = 0;
  for (int i = 0; i < A->rows - 1; i++) {
    flag = check_for_zero(A, i, det);
    if (flag == 1) {
      *det = 0.000000;
    } else {
      for (int j = i + 1; j < A->rows; j++) {
        do_zero(A, i, j);
      }
    }
  }
  return flag;
}

double det(matrix_t *A) {
  double det = 1;
  for (int i = 0; i < A->rows; i++) {
    det *= A->matrix[i][i];
  }
  return det;
}

void swap_invert(matrix_t *a, matrix_t *eye, int i, int j) {
  for (int k = 0; k < a->columns; k++) {
    double temp;
    temp = a->matrix[i][k];
    a->matrix[i][k] = a->matrix[j][k];
    a->matrix[j][k] = temp;
    temp = eye->matrix[i][k];
    eye->matrix[i][k] = eye->matrix[j][k];
    eye->matrix[j][k] = temp;
  }
}

int check_for_zero_invert(matrix_t *matrix, matrix_t *eye, int k, double *det) {
  int raws = k, cols = k;
  while (matrix->matrix[raws][cols] == 0 && raws < matrix->rows - 1) {
    raws++;
  }
  if (k != matrix->rows - 1 && matrix->matrix[raws][cols] != 0 &&
      matrix->matrix[k][k] == 0) {
    swap_invert(matrix, eye, k, raws);
    *det *= (-1);
  }
  if (raws == matrix->rows - 1) {
    return 1;
  } else {
    return 0;
  }
}

void do_zero_invert(matrix_t *a, matrix_t *eye, int i, int j) {
  if (a->matrix[j][i] != 0) {
    double mass[a->columns], mass_eye[a->columns], temp1, temp2;
    temp1 = a->matrix[i][i];
    temp2 = a->matrix[j][i];
    for (int k = 0; k < a->columns; k++) {
      mass[k] = a->matrix[i][k] / temp1 * temp2;
      mass_eye[k] = eye->matrix[i][k] / temp1 * temp2;
    }
    for (int k = 0; k < a->columns; k++) {
      a->matrix[j][k] -= mass[k];
      eye->matrix[j][k] -= mass_eye[k];
    }
  }
}

int diag_invert(matrix_t *matrix, matrix_t *eye, double *det) {
  int flag = 0;
  for (int i = 0; i < matrix->rows - 1; i++) {
    flag = check_for_zero_invert(matrix, eye, i, det);
    if (flag == 1) {
      *det = 0.000000;
    } else {
      for (int j = i + 1; j < matrix->rows; j++) {
        do_zero_invert(matrix, eye, i, j);
      }
    }
  }
  return flag;
}

void do_zero_full_invert(matrix_t *a, matrix_t *eye, int i, int j) {
  if (a->matrix[j][i] != 0) {
    double mass[a->columns], mass_eye[a->columns], temp1, temp2;
    temp1 = a->matrix[i][i];
    temp2 = a->matrix[j][i];
    for (int k = a->columns - 1; k >= 0; k--) {
      mass[k] = a->matrix[i][k] / temp1 * temp2;
      mass_eye[k] = eye->matrix[i][k] / temp1 * temp2;
    }
    for (int k = a->columns - 1; k >= 0; k--) {
      a->matrix[j][k] -= mass[k];
      eye->matrix[j][k] -= mass_eye[k];
    }
  }
}

void do_diag_invert(matrix_t *matrix, matrix_t *eye) {
  for (int i = matrix->rows - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      do_zero_full_invert(matrix, eye, i, j);
    }
  }
}

void reset_eye_invert(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != j) {
        matrix->matrix[i][j] = 0;
      } else {
        matrix->matrix[i][j] = 1;
      }
    }
  }
}

void invert_invert(matrix_t *matrix, matrix_t *eye) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      eye->matrix[i][j] /= matrix->matrix[i][i];
    }
  }
}

void create_eye(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != j) {
        matrix->matrix[i][j] = 0;
      } else {
        matrix->matrix[i][j] = 1;
      }
    }
  }
}

void print_matix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      printf("%f ", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}