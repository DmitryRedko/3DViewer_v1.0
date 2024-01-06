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

#define MAX_LINE_LENGTH 256
#define MAX_VERTICES 10000
#define MAX_TEXTURES 10000
#define MAX_NORMALS 10000
#define MAX_FACES 10000

typedef struct {
    float x, y, z;
} Vertex;

typedef struct {
    float u, v;
} Texture;

typedef struct {
    float x, y, z;
} Normal;

typedef struct {
    int vIndex[3], vtIndex[3], vnIndex[3];
} Face;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    Texture textures[MAX_TEXTURES];
    Normal normals[MAX_NORMALS];
    Face faces[MAX_FACES];
    int vertexCount, textureCount, normalCount, faceCount;
} ObjData;



#define OK 0
#define ERROR_INVALID_MATRIX 1
#define ERROR_CALCULATION 2

#define SUCCESS 1
#define FAILURE 0

#include "operations/s21_arithmetic.h"
#include "operations/s21_common.h"
#include "parser/s21_parser.h"

#endif
