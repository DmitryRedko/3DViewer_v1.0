#ifndef S21_ARITHMETIC
#define S21_ARITHMETIC

#include "../backend.h"
#include <math.h> // Include math library for trigonometric functions

void rotate_operation(double round_x, double round_y, double round_z, ObjData *data, ObjData base_data);
void zoom_operation(double zoom_x, double zoom_y, double zoom_z, ObjData *data, ObjData base_data);
void move_operation(double x, double y, double z, ObjData *data, ObjData base_data);

#endif
