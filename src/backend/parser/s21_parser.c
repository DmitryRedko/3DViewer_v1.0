#include "../backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ObjData parse_obj(const char *file_path, int *parse_flag) {
    ObjData objData;
    objData.vertexCount = 0;
    // objData.textureCount = 0;
    // objData.normalCount = 0;
    objData.faceCount = 0;

    objData.vertices = malloc(sizeof(Vertex));
    objData.faces = malloc(sizeof(unsigned int));

    if (strstr(file_path, ".obj") == NULL) {
        fprintf(stderr, "File does not have .obj extension.\n");
        *parse_flag = 1;
        return objData;
    }

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        *parse_flag = 1;
        return objData;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // printf("line: %s", line);e
        char *token = strtok(line, " ");
        if (token != NULL) {
            if (strcmp(token, "v") == 0) {
                // Vertex parsing
                char *next = strtok(NULL, " ");
                if (next != NULL) {
                    objData.vertices[objData.vertexCount].x = atof(next);
                    next = strtok(NULL, " ");
                    objData.vertices[objData.vertexCount].y = atof(next);
                    next = strtok(NULL, " ");
                    objData.vertices[objData.vertexCount].z = atof(next);
                    objData.vertexCount++;
                    objData.vertices = realloc(objData.vertices, (objData.vertexCount + 1) * sizeof(Vertex));
                    // printf("objData.vertexCount %d\n", objData.vertexCount);
                }
//            } else if (strcmp(token, "vt") == 0) {
//                // Texture coordinates parsing
//                char *next = strtok(NULL, " ");
//                if (next != NULL) {
//                    objData.textures[objData.textureCount].u = atof(next);
//                    next = strtok(NULL, " ");
//                    objData.textures[objData.textureCount].v = atof(next);
//                    objData.textureCount++;
//                }
//            } else if (strcmp(token, "vn") == 0) {
//                // Normals parsing
//                char *next = strtok(NULL, " ");
//                if (next != NULL) {
//                    objData.normals[objData.normalCount].x = atof(next);
//                    next = strtok(NULL, " ");
//                    objData.normals[objData.normalCount].y = atof(next);
//                    next = strtok(NULL, " ");
//                    objData.normals[objData.normalCount].z = atof(next);
//                    objData.normalCount++;
//                }
           } else if (strcmp(token, "f") == 0) {
               // Faces parsing
               // int indices[3][3]; // vIndex/vtIndex/vnIndex
               unsigned int vertex, texture, normal;

               for (int i = 0; i < 3; ++i) {
                   char *next = strtok(NULL, " ");
                   sscanf(next, "%d/%d/%d", &vertex, &texture, &normal);
               }

               objData.faces[objData.faceCount] = vertex;
               objData.faceCount++;
               objData.faces = realloc(objData.faces, (objData.faceCount + 1) * sizeof(unsigned int));
            }
        }
    }

    fclose(file);
    return objData;
}

void model_destructor(ObjData *objData) {
    if (objData != NULL) {
        if (objData->vertices != NULL) {
            free(objData->vertices);
            objData->vertices = NULL;
        }
        if (objData->faces != NULL) {
            free(objData->faces);
            objData->faces = NULL;
        }
    }
}
