#ifndef OBJ_PARSER
#define OBJ_PARSER

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
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

void rotate_operation(double round_x, double round_y, double round_z,
                      ObjData *data, ObjData *base_data);
void zoom_operation(double zoom_x, double zoom_y, double zoom_z, ObjData *data,
                    ObjData *base_data);
void move_operation(double x, double y, double z, ObjData *data,
                    ObjData *base_data);
ObjData parse_obj(const char *file_path, double *parse_flag);
void model_destructor(ObjData *objData)

#endif
