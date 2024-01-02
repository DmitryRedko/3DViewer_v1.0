#include "s21_parser.h"

ObjData parse_obj(const char *file_path) {
    ObjData objData;
    objData.vertexCount = 0;
    objData.textureCount = 0;
    objData.normalCount = 0;
    objData.faceCount = 0;

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char copied_line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        strcpy(copied_line, line);
        // printf("%s\n", line);
        char *token = strtok(copied_line, " ");        
        if (token != NULL) {
            if (strcmp(token, "v") == 0) {
                sscanf(line, "v %f %f %f", &objData.vertices[objData.vertexCount].x,
                    &objData.vertices[objData.vertexCount].y, &objData.vertices[objData.vertexCount].z);
                printf("%s\n",line);
                printf("v %f %f %f\n", objData.vertices[objData.vertexCount].x,
                        objData.vertices[objData.vertexCount].y, objData.vertices[objData.vertexCount].z);
                objData.vertexCount++;
            } else if (strcmp(token, "vt") == 0) {
                sscanf(line, "vt %f %f", &objData.textures[objData.textureCount].u,
                    &objData.textures[objData.textureCount].v);
                objData.textureCount++;
            } else if (strcmp(token, "vn") == 0) {
                sscanf(line, "vn %f %f %f", &objData.normals[objData.normalCount].x,
                    &objData.normals[objData.normalCount].y, &objData.normals[objData.normalCount].z);
                objData.normalCount++;
            } else if (strcmp(token, "f") == 0) {
                sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d",
                    &objData.faces[objData.faceCount].vIndex[0], &objData.faces[objData.faceCount].vtIndex[0],
                    &objData.faces[objData.faceCount].vnIndex[0], &objData.faces[objData.faceCount].vIndex[1],
                    &objData.faces[objData.faceCount].vtIndex[1], &objData.faces[objData.faceCount].vnIndex[1],
                    &objData.faces[objData.faceCount].vIndex[2], &objData.faces[objData.faceCount].vtIndex[2],
                    &objData.faces[objData.faceCount].vnIndex[2]);
                objData.faceCount++;
            }
        }
    }

    fclose(file);
    return objData;
}
