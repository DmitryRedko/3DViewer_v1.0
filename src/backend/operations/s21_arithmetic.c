#include <math.h>

#include "s21_common.h"


void move_operation(double x, double y, double z, ObjData *data, ObjData base_data){
    for (int i = 0; i < data->vertexCount; ++i) {
        data->vertices[i].x = base_data.vertices[i].x + x;
        data->vertices[i].y = base_data.vertices[i].y + y;
        data->vertices[i].z = base_data.vertices[i].z + z;
    }
}



void zoom_operation(double zoom_x, double zoom_y, double zoom_z, ObjData *data, ObjData base_data){
    for (int i = 0; i < data->vertexCount; ++i) {
        data->vertices[i].x = base_data.vertices[i].x * zoom_x/100;
        data->vertices[i].y = base_data.vertices[i].y * zoom_y/100;
        data->vertices[i].z = base_data.vertices[i].z * zoom_z/100;
    }
}

void rotate_operation(double round_x, double round_y, double round_z, ObjData *data, ObjData base_data) {
    // Convert angles from degrees to radians
    double rad_round_x = round_x * 3.14 / 180.0;
    double rad_round_y = round_y * 3.14 / 180.0;
    double rad_round_z = round_z * 3.14 / 180.0;
//    printf("\n\n%f %f %f %f\n",rad_round_x,round_x,cos(rad_round_x),cos(round_x));

    // Rotation matrix around x-axis
    double rot_x[3][3] = {
        {1, 0, 0},
        {0, cos(rad_round_x), -sin(rad_round_x)},
        {0, sin(rad_round_x), cos(rad_round_x)}
    };

    // Rotation matrix around y-axis
    double rot_y[3][3] = {
        {cos(rad_round_y), 0, sin(rad_round_y)},
        {0, 1, 0},
        {-sin(rad_round_y), 0, cos(rad_round_y)}
    };

    // Rotation matrix around z-axis
    double rot_z[3][3] = {
        {cos(rad_round_z), -sin(rad_round_z), 0},
        {sin(rad_round_z), cos(rad_round_z), 0},
        {0, 0, 1}
    };

//    printf("Rotation Matrix X:\n");
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            printf("%f\t", rot_x[i][j]);
//        }
//        printf("\n");
//    }

printf("\nOriginal: %f %f %f\n", data->vertices[0].x, data->vertices[0].y, data->vertices[0].z);
    // Apply rotations to each vertex in ObjData
    for (int i = 0; i < data->vertexCount; ++i) {
        double x = base_data.vertices[i].x;
        double y = base_data.vertices[i].y;
        double z = base_data.vertices[i].z;

        // Apply rotation matrices to the vertex coordinates
        double new_x = rot_x[0][0] * x + rot_x[0][1] * y + rot_x[0][2] * z;
        double new_y = rot_x[1][0] * x + rot_x[1][1] * y + rot_x[1][2] * z;
        double new_z = rot_x[2][0] * x + rot_x[2][1] * y + rot_x[2][2] * z;

        x = new_x;
        y = new_y;
        z = new_z;

        new_x = rot_y[0][0] * x + rot_y[0][1] * y + rot_y[0][2] * z;
        new_y = rot_y[1][0] * x + rot_y[1][1] * y + rot_y[1][2] * z;
        new_z = rot_y[2][0] * x + rot_y[2][1] * y + rot_y[2][2] * z;

        x = new_x;
        y = new_y;
        z = new_z;

        new_x = rot_z[0][0] * x + rot_z[0][1] * y + rot_z[0][2] * z;
        new_y = rot_z[1][0] * x + rot_z[1][1] * y + rot_z[1][2] * z;
        new_z = rot_z[2][0] * x + rot_z[2][1] * y + rot_z[2][2] * z;

        // Update the vertex coordinates in ObjData
        data->vertices[i].x = new_x;
        data->vertices[i].y = new_y;
        data->vertices[i].z = new_z;
    }
    printf("\nChanged: %f %f %f\n", data->vertices[0].x, data->vertices[0].y, data->vertices[0].z);
}
