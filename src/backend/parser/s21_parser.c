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

    objData.vertices = malloc(sizeof(float));
    objData.faces = malloc(sizeof(unsigned int));


    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // printf("line: %s", line);
        char *token = strtok(line, " ");
        if (token != NULL) {
            if (strcmp(token, "v") == 0) {
                // Vertex parsing
                char *next = strtok(NULL, " ");

                while (next != NULL) {
                    objData.vertices[objData.vertexCount] = atof(next);
                    objData.vertexCount++;
                    objData.vertices = realloc(objData.vertices, (objData.vertexCount + 1) * sizeof(float));
                    next = strtok(NULL, " ");
                }
           } else if (strcmp(token, "f") == 0) {
               // Faces parsing
               // int indices[3][3]; // vIndex/vtIndex/vnIndex
               unsigned int vertex;
               char *next = strtok(NULL, " ");

//               printf("vertex %s\n", next);

               while (next != NULL) {
//                   printf("vertex %s\n", next);
                   vertex = atoi(next);

//                   printf("faces %d\n", objData.faces[objData.faceCount]);
                   objData.faces[objData.faceCount] = vertex - 1;
                   objData.faceCount++;
                   objData.faces = realloc(objData.faces, (objData.faceCount + 1) * sizeof(unsigned int));
//                   objData.faces[objData.faceCount] = vertex;

                   // next = strtok(NULL, "/");
                   next = strtok(NULL, " ");
               }
            }
        }
    }
    // printf("vertex array size %d %d\n", sizeof(objData.vertices), sizeof(Vertex));
    // printf("faces array size %d %d\n", sizeof(objData.faces), sizeof(unsigned int));

//    printf("\n%d Verticies from index 1\n", objData.vertexCount/3);
//    for (unsigned int i = 0; i < objData.vertexCount; i++) {
//        printf("%f ", objData.vertices[i]);
//        // printf("%f ", objData.vertices[i].y);
//        // printf("%f\n", objData.vertices[i].z);
//        // objData.faceCount[i] = objData.faceCount[i - 1];
//    }

//    printf("\n%d Faces from index 1\n", objData.faceCount);
//    for (unsigned int i = 0; i < objData.faceCount; i++) {
//        printf("%d ", objData.faces[i]);/
//    }

    objData.vertexCount = objData.vertexCount/3;

    fclose(file);
//    objData.vertices[0] = 0.0;
    return objData;
}

void model_destructor(ObjData *objData) {
    if (objData != NULL) {
        if (objData->vertices != NULL) {
            free(objData->vertices);
            // objData->vertices = NULL;
        }
        if (objData->faces != NULL) {
            free(objData->faces);
            // objData->faces = NULL;
        }
    }
}
