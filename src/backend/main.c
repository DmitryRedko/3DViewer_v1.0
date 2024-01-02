// #include "backend.h"
// #include "operations/s21_arithmetic.h"
// #include "operations/s21_common.h"


// int main(){

//     //Матрица поворота
//     matrix_t round_matrix;
// 
    
//     matrix_t vector1, vector2;

//     s21_create_matrix(3,1,&vector1);
//     s21_create_matrix(3,1,&vector2);
//     vector1.matrix[0][0] = 1.0;
//     vector1.matrix[1][0] = 2.0;
//     vector1.matrix[2][0] = 1.0;
//     printf("\n");
//     print_matix(&vector1);

//     s21_mult_matrix(round_matrix,vector1,&vector2);
//     printf("\n");
//     print_matix(&vector2);

//     return 0;
// }

#include <stdio.h>
#include "./parser/s21_parser.h"

int main() {
    // const char *file_path = "/home/dmitry/Desktop/School21/Viewer/src/models/model1.obj";
    const char *file_path = "../models/model1.obj";
    ObjData objData = parse_obj(file_path);

    // Используем данные, собранные из файла .obj
    printf("Vertices:\n");
    for (int i = 0; i < objData.vertexCount; ++i) {
        printf("v %f %f %f\n", objData.vertices[i].x, objData.vertices[i].y, objData.vertices[i].z);
    }

    printf("\nTextures:\n");
    for (int i = 0; i < objData.textureCount; ++i) {
        printf("vt %f %f\n", objData.textures[i].u, objData.textures[i].v);
    }

    printf("\nNormals:\n");
    for (int i = 0; i < objData.normalCount; ++i) {
        printf("vn %f %f %f\n", objData.normals[i].x, objData.normals[i].y, objData.normals[i].z);
    }

    printf("\nFaces:\n");
    for (int i = 0; i < objData.faceCount; ++i) {
        printf("f %d/%d/%d %d/%d/%d %d/%d/%d\n",
            objData.faces[i].vIndex[0], objData.faces[i].vtIndex[0], objData.faces[i].vnIndex[0],
            objData.faces[i].vIndex[1], objData.faces[i].vtIndex[1], objData.faces[i].vnIndex[1],
            objData.faces[i].vIndex[2], objData.faces[i].vtIndex[2], objData.faces[i].vnIndex[2]);
    }

    return 0;
}
