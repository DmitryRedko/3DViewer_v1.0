#ifndef OBJ_PARSER
#define OBJ_PARSER

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#define MAX_LINE_LENGTH 256
#define MAX_VERTICES 1000000
#define MAX_TEXTURES 10
#define MAX_NORMALS 10
#define MAX_FACES 10

typedef struct {
    float x, y, z;
} Vertex;

typedef struct {
    float u, v;
} Texture;

typedef struct {
    float x, y, z;
} Normal;

// typedef struct {
//     int vIndex[3], vtIndex[3], vnIndex[3];
// } Face;

typedef struct {
    Vertex *vertices;
    // Texture textures[MAX_TEXTURES];
    // Normal normals[MAX_NORMALS];
    unsigned int *faces;
    unsigned int vertexCount, faceCount;
} ObjData;

void rotate_operation(double round_x, double round_y, double round_z, ObjData *data, ObjData *base_data);
void zoom_operation(double zoom_x, double zoom_y, double zoom_z, ObjData *data, ObjData *base_data);
void move_operation(double x, double y, double z, ObjData *data, ObjData *base_data);
ObjData parse_obj(const char *file_path, int *parse_flag);

#endif
