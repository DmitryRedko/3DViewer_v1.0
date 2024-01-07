#include "../backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ObjData parse_obj(const char *file_path, int *parse_flag) {
    ObjData objData;
    objData.vertexCount = 0;
    objData.textureCount = 0;
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
        // printf("line: %s", line);
        char *token = strtok(line, " ");
        if (token != NULL) {
            if (strcmp(token, "v") == 0) {
                // Vertex parsing
                char *next = strtok(NULL, " ");
                // if (next != NULL) {
                //     objData.vertices[objData.vertexCount] = atof(next);
                //     next = strtok(NULL, " ");
                //     // objData.vertices[objData.vertexCount] = atof(next);
                //     // next = strtok(NULL, " ");
                //     // objData.vertices[objData.vertexCount] = atof(next);
                //     objData.vertexCount++;
                //     objData.vertices = realloc(objData.vertices, (objData.vertexCount + 1) * sizeof(float));
                //     // printf("objData.vertexCount %d\n", objData.vertexCount);
                // }
                while (next != NULL) {
                    objData.vertices[objData.vertexCount] = atof(next);
                    objData.vertexCount++;
                    objData.vertices = realloc(objData.vertices, (objData.vertexCount + 1) * sizeof(float));
                    next = strtok(NULL, " ");
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

               char *next = strtok(NULL, " ");
               while (next != NULL) {
                       // printf("vertex %s\n", next);
                       vertex = atoi(next);

                       objData.faces[objData.faceCount] = vertex;
                       // printf("faces %d\n", objData.faces[objData.faceCount]);
                       objData.faceCount++;
                       objData.faces = realloc(objData.faces, (objData.faceCount + 1) * sizeof(unsigned int));

                       // next = strtok(NULL, "/");
                       next = strtok(NULL, " ");
               }
            }
        }
    }

    for (int i = objData.faceCount; i > 0; i--) {
        // printf("%d ", objData.faces[i]);
        objData.faces[i] = objData.faces[i - 1];
    }

    for (int i = objData.vertexCount; i > 0; i--) {
        // printf("%d ", objData.faces[i]);
        objData.vertices[i] = objData.vertices[i - 1];
        // objData.vertices[i].y = objData.vertices[i - 1].y;
        // objData.vertices[i].z = objData.vertices[i - 1].z;
    }

    // printf("vertex array size %d %d\n", sizeof(objData.vertices), sizeof(Vertex));
    // printf("faces array size %d %d\n", sizeof(objData.faces), sizeof(unsigned int));

    printf("\n%d Verticies from index 1\n", objData.vertexCount);
    for (int i = 1; i <= objData.vertexCount; i++) {
        printf("%f ", objData.vertices[i]);
        if (i % 3 == 0) printf("\n");
        // printf("%f ", objData.vertices[i].y);
        // printf("%f\n", objData.vertices[i].z);
        // objData.faceCount[i] = objData.faceCount[i - 1];
    }

    printf("\n%d Faces from index 1\n", objData.faceCount);
    for (int i = 1; i <= objData.faceCount; i++) {
        printf("%d ", objData.faces[i]);
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
