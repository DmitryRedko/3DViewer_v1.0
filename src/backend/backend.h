#ifndef S21_BACKEND
#define S21_BACKEND

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#define OK 0
#define ERROR_INVALID_MATRIX 1
#define ERROR_CALCULATION 2

#define SUCCESS 1
#define FAILURE 0

#include "operations/s21_arithmetic.h"
#include "operations/s21_common.h"
#include "parser/s21_parser.h"

#endif
