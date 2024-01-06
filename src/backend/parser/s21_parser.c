#include "../backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ObjData parse_obj(const char *file_path, double *parse_flag) {
    ObjData objData;
    objData.vertexCount = 0;
    objData.textureCount = 0;
    objData.normalCount = 0;
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

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
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
//            } else if (strcmp(token, "f") == 0) {
//                // Faces parsing
//                int indices[3][3]; // vIndex/vtIndex/vnIndex
//                for (int i = 0; i < 3; ++i) {
//                    char *next = strtok(NULL, " ");
//                    sscanf(next, "%d/%d/%d", &indices[i][0], &indices[i][1], &indices[i][2]);
//                }

//                for (int i = 0; i < 3; ++i) {
//                    objData.faces[objData.faceCount].vIndex[i] = indices[i][0];
//                    objData.faces[objData.faceCount].vtIndex[i] = indices[i][1];
//                    objData.faces[objData.faceCount].vnIndex[i] = indices[i][2];
//                }
//                objData.faceCount++;

            }
        }
    }

    fclose(file);
    return objData;
}
