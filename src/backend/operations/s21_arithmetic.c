#include <math.h>

#include "s21_common.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (rows <= 0 || columns <= 0) {
    flag = ERROR_INVALID_MATRIX;
  }

  if (flag == OK) {
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
      if (result->matrix[i] == NULL) {
        for (int j = 0; j < i; j++) {
          free(result->matrix[j]);
        }
        free(result->matrix);
        flag = ERROR_INVALID_MATRIX;
      }
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0.0;
      }
    }
    result->rows = rows;
    result->columns = columns;
  }

  return flag;
}

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return;
  }

  for (int i = 0; i < A->rows; i++) {
    if (A->matrix[i] != NULL) {
      free(A->matrix[i]);
    }
  }
  if (A != NULL) {
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;

  if (A == NULL || B == NULL || A->rows != B->rows ||
      A->columns != B->columns) {
    flag = FAILURE;
  }
  if (flag == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          flag = FAILURE;
          break;
        }
      }
      if (flag == FAILURE) break;
    }
  }

  return flag;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A->rows != B->rows || A->columns != B->columns) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    // s21_remove_matrix(result);
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A->rows != B->rows || A->columns != B->columns) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    // s21_remove_matrix(result);
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;

  if (A == NULL) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    // s21_remove_matrix(result);
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return flag;
}

int s21_mult_matrix(matrix_t A, matrix_t B, matrix_t *result) {
  int flag = OK;

  if (A.columns != B.rows) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    // s21_remove_matrix(result);
    flag = s21_create_matrix(A.rows, B.columns, result);
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < B.columns; j++) {
        double sum = 0.0;
        for (int k = 0; k < A.columns; k++) {
          sum += A.matrix[i][k] * B.matrix[k][j];
        }
        result->matrix[i][j] = sum;
      }
    }
  }

  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = SUCCESS;

  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    flag = FAILURE;
  }

  // s21_remove_matrix(result);
  flag = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return flag;
}

void s21_remove_row_and_column(matrix_t *A, int row, int col,
                               matrix_t *result) {
  int curr_row = 0, curr_col = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != col) {
          result->matrix[curr_row][curr_col] = A->matrix[i][j];
          curr_col++;
        }
      }
      curr_col = 0;
      curr_row++;
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    flag = ERROR_INVALID_MATRIX;
  }
  if (A->rows != A->columns) {
    flag = ERROR_CALCULATION;
  }
  if (A->rows == 1 && A->columns == 1) {
    if (flag == OK) {
      flag = s21_create_matrix(A->columns, A->rows, result);
      result->columns = 1;
      result->rows = 1;
      result->matrix[0][0] = A->matrix[0][0];
    }
  } else {
    if (flag == OK) {
      flag = s21_create_matrix(A->columns, A->rows, result);
      matrix_t minor;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor.rows = A->rows - 1;
          minor.columns = A->columns - 1;
          minor.matrix = (double **)malloc(minor.rows * sizeof(double *));
          if (minor.matrix == NULL) {
            flag = FAILURE;
            break;
          }
          for (int k = 0; k < minor.rows; k++) {
            minor.matrix[k] = (double *)malloc(minor.columns * sizeof(double));
            if (minor.matrix[k] == NULL) {
              flag = FAILURE;
              s21_remove_matrix(&minor);
              break;
            }
          }
          if (flag == OK) {
            s21_remove_row_and_column(A, i, j, &minor);
            // s21_print_matrix(&minor);
            double determinant = 0;
            s21_determinant(&minor, &determinant);
            // printf("det: %f\n", determinant);
            // printf("\n\n");

            double complement = determinant * pow(-1, i + j);
            result->matrix[i][j] = complement;
            s21_remove_matrix(&minor);
          } else {
            break;
          }
        }
      }
    }
  }

  return flag;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    return ERROR_INVALID_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALCULATION;
  }

  double determinant = 1;

  if (A->rows > 0 && A->columns > 0) {
    if (diag(A, &determinant) == 1) {
      *result = 0.000000;
    } else {
      determinant = determinant * det(A);
      *result = determinant;
    }
  } else {
    *result = 0.000000;
  }

  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double determinant = 1;
  int flag = OK;

  if (A->rows != A->columns) {
    flag = ERROR_CALCULATION;  // Matrices are not square, so inverse is not
                               // possible
  }

  if (flag == OK && s21_create_matrix(A->rows, A->columns, result) != OK) {
    flag =
        ERROR_INVALID_MATRIX;  // Memory allocation failed for the result matrix
  }

  matrix_t eye;
  if (flag == OK && s21_create_matrix(A->rows, A->columns, &eye) != OK) {
    s21_remove_matrix(result);
    flag = ERROR_INVALID_MATRIX;  // Memory allocation failed for the eye matrix
  }

  if (flag == OK) {
    reset_eye_invert(&eye);

    if (diag_invert(A, &eye, &determinant) == 1) {
      s21_remove_matrix(&eye);
      s21_remove_matrix(result);
      flag =
          ERROR_CALCULATION;  // Diagonalization failed, inverse does not exist
    } else {
      determinant = determinant * det(A);
      if (determinant <= 0.0000004 && determinant >= -0.0000004) {
        s21_remove_matrix(&eye);
        s21_remove_matrix(result);
        flag = ERROR_CALCULATION;  // Determinant is close to zero, inverse does
                                   // not exist
      } else {
        do_diag_invert(A, &eye);
        invert_invert(A, &eye);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = eye.matrix[i][j];
          }
        }
      }
    }
    s21_remove_matrix(&eye);
  }
  return flag;
}

// void move_operation(double x, double y, double z, matrix_t *vector) {
//   matrix_t move_matrix;
//   s21_create_matrix(4, 4, &move_matrix);
//   create_eye(&move_matrix);

//   move_matrix.matrix[0][3] = x;
//   move_matrix.matrix[1][3] = y;
//   move_matrix.matrix[2][3] = z;

//   matrix_t homo_vector_coords;
//   s21_create_matrix(4,1, &homo_vector_coords);
//   homo_vector_coords.matrix[0][0] = vector->matrix[0][0];
//   homo_vector_coords.matrix[1][0] = vector->matrix[1][0];
//   homo_vector_coords.matrix[2][0] = vector->matrix[2][0];
//   homo_vector_coords.matrix[3][0] = 1;
  
//   s21_mult_matrix(move_matrix,homo_vector_coords,&homo_vector_coords);

//   vector->matrix[0][0] = homo_vector_coords.matrix[0][0];
//   vector->matrix[1][0] = homo_vector_coords.matrix[1][0];
//   vector->matrix[2][0] = homo_vector_coords.matrix[2][0];

//   s21_remove_matrix(&homo_vector_coords);
//   s21_remove_matrix(&move_matrix);
// }

// void round_operation(double round_x, double round_y, double round_z, matrix_t *vector) {
//   matrix_t round_matrix;
//   s21_create_matrix(3, 3, &round_matrix);

//   create_eye(&round_matrix);
//   round_matrix.matrix[1][1] = cos(round_x);
//   round_matrix.matrix[1][2] = -sin(round_x);
//   round_matrix.matrix[2][1] = sin(round_x);
//   round_matrix.matrix[2][2] = cos(round_x);

//   s21_mult_matrix(round_matrix,*vector,vector);

//   create_eye(&round_matrix);
//   round_matrix.matrix[0][0] = cos(round_y);
//   round_matrix.matrix[0][2] = sin(round_y);
//   round_matrix.matrix[2][0] = -sin(round_y);
//   round_matrix.matrix[2][2] = cos(round_y);

//   s21_mult_matrix(round_matrix,*vector,vector);

//   create_eye(&round_matrix);
//   round_matrix.matrix[0][0] = cos(round_z);
//   round_matrix.matrix[0][1] = -sin(round_z);
//   round_matrix.matrix[1][0] = sin(round_z);
//   round_matrix.matrix[1][1] = cos(round_z);

//   s21_mult_matrix(round_matrix,*vector,vector);
//   s21_remove_matrix(&round_matrix);
// }

// void zoom_operation(double zoom_x, double zoom_y, double zoom_z, matrix_t *vector) {
//   matrix_t zoom_matrix;
//   s21_create_matrix(4, 4, &zoom_matrix);
//   create_eye(&zoom_matrix);

//   zoom_matrix.matrix[0][0] =zoom_x;
//   zoom_matrix.matrix[1][1] =zoom_y;
//   zoom_matrix.matrix[2][2] =zoom_z;

//   matrix_t homo_vector_coords;
//   s21_create_matrix(4,1, &homo_vector_coords);
//   homo_vector_coords.matrix[0][0] = vector->matrix[0][0];
//   homo_vector_coords.matrix[1][0] = vector->matrix[1][0];
//   homo_vector_coords.matrix[2][0] = vector->matrix[2][0];
//   homo_vector_coords.matrix[3][0] = 1;
  
//   s21_mult_matrix(zoom_matrix,homo_vector_coords,&homo_vector_coords);

//   vector->matrix[0][0] = homo_vector_coords.matrix[0][0];
//   vector->matrix[1][0] = homo_vector_coords.matrix[1][0];
//   vector->matrix[2][0] = homo_vector_coords.matrix[2][0];

//   s21_remove_matrix(&homo_vector_coords);
//   s21_remove_matrix(&zoom_matrix);
// }


void move_operation(double x, double y, double z, ObjData *data, ObjData base_data){
    for (int i = 0; i < data->vertexCount; ++i) {
        data->vertices[i].x = base_data.vertices[i].x + x;
        data->vertices[i].y = base_data.vertices[i].y + y;
        data->vertices[i].z = base_data.vertices[i].z + z;
    }
}



void zoom_operation(double zoom_x, double zoom_y, double zoom_z, ObjData *data, ObjData base_data){
    for (int i = 0; i < data->vertexCount; ++i) {
        data->vertices[i].x = base_data.vertices[i].x * zoom_x;
        data->vertices[i].y = base_data.vertices[i].y * zoom_y;
        data->vertices[i].z = base_data.vertices[i].z * zoom_z;
    }
}

void rotate_operation(double round_x, double round_y, double round_z, ObjData *data, ObjData base_data) {
    // Convert angles from degrees to radians
    double rad_round_x = round_x * 3.14 / 180.0;
    double rad_round_y = round_y * 3.14 / 180.0;
    double rad_round_z = round_z * 3.14 / 180.0;
    printf("\n\n%f %f %f %f\n",rad_round_x,round_x,cos(rad_round_x),cos(round_x));

    // Rotation matrix around x-axis
    double rot_x[3][3] = {
        {1, 0, 0},
        {0, cos(rad_round_x), -sin(rad_round_x)},
        {0, sin(rad_round_x), cos(rad_round_x)}
    };

    // Rotation matrix around y-axis
    double rot_y[3][3] = {
        {cos(rad_round_y), 0, sin(rad_round_y)},
        {0, 1, 0},
        {-sin(rad_round_y), 0, cos(rad_round_y)}
    };

    // Rotation matrix around z-axis
    double rot_z[3][3] = {
        {cos(rad_round_z), -sin(rad_round_z), 0},
        {sin(rad_round_z), cos(rad_round_z), 0},
        {0, 0, 1}
    };

    printf("Rotation Matrix X:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%f\t", rot_x[i][j]);
        }
        printf("\n");
    }

printf("\nOriginal: %f %f %f\n", data->vertices[0].x, data->vertices[0].y, data->vertices[0].z);
    // Apply rotations to each vertex in ObjData
    for (int i = 0; i < data->vertexCount; ++i) {
        double x = base_data.vertices[i].x;
        double y = base_data.vertices[i].y;
        double z = base_data.vertices[i].z;

        // Apply rotation matrices to the vertex coordinates
        double new_x = rot_x[0][0] * x + rot_x[0][1] * y + rot_x[0][2] * z;
        double new_y = rot_x[1][0] * x + rot_x[1][1] * y + rot_x[1][2] * z;
        double new_z = rot_x[2][0] * x + rot_x[2][1] * y + rot_x[2][2] * z;

        x = new_x;
        y = new_y;
        z = new_z;

        new_x = rot_y[0][0] * x + rot_y[0][1] * y + rot_y[0][2] * z;
        new_y = rot_y[1][0] * x + rot_y[1][1] * y + rot_y[1][2] * z;
        new_z = rot_y[2][0] * x + rot_y[2][1] * y + rot_y[2][2] * z;

        x = new_x;
        y = new_y;
        z = new_z;

        new_x = rot_z[0][0] * x + rot_z[0][1] * y + rot_z[0][2] * z;
        new_y = rot_z[1][0] * x + rot_z[1][1] * y + rot_z[1][2] * z;
        new_z = rot_z[2][0] * x + rot_z[2][1] * y + rot_z[2][2] * z;

        // Update the vertex coordinates in ObjData
        data->vertices[i].x = new_x;
        data->vertices[i].y = new_y;
        data->vertices[i].z = new_z;
    }
    printf("\nChanged: %f %f %f\n", data->vertices[0].x, data->vertices[0].y, data->vertices[0].z);
}
