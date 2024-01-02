#ifndef OBJ_PARSER
#define OBJ_PARSER

#define MAX_LINE_LENGTH 256
#define MAX_VERTICES 1000
#define MAX_TEXTURES 1000
#define MAX_NORMALS 1000
#define MAX_FACES 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

ObjData parse_obj(const char *file_path);

#endif 
