#include <check.h>
#include <math.h>
#include <stdio.h>

#include "backend/operations/s21_arithmetic.h"
#include "backend/parser/s21_parser.h"

#define SUCCESS 0
#define FAIL 1
#define EPS 0.0000000001

// move model by x test
START_TEST(test_1) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float x_offset = 25;
  float y_offset = 0;
  float z_offset = 0;

  float moved_objData[24] = {1.25,  1.00,  -1.00, 1.25,  -1.00, -1.00,
                             1.25,  -1.00, 1.00,  1.25,  1.00,  -1.00,
                             1.25,  1.00,  -1.00, -0.75, 1.00,  -1.00,
                             -0.75, -1.00, 1.00,  -0.75, 1.00,  -1.00};
  move_operation(x_offset, y_offset, z_offset, &objData, &baseData);

  // printf("Original matrix\n");
  // for (unsigned int i = 0; i < baseData.vertexCount; i=i+3) {
  //     printf ("%f ", baseData.vertices[i]);
  //     printf ("%f ", baseData.vertices[i+1]);
  //     printf ("%f\n", baseData.vertices[i+2]);
  // }

  // printf("\nMoved matrix\n");
  // for (unsigned int i = 0; i < objData.vertexCount; i=i+3) {
  //     printf ("%f ", objData.vertices[i]);
  //     printf ("%f ", objData.vertices[i+1]);
  //     printf ("%f\n", objData.vertices[i+2]);
  // }

  // printf("\nDiffs\n");
  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    // if (diff == 2) {
    //   printf("\n\n %f --- %f\n", moved_objData[i], objData.vertices[i]);
    // }
    // printf("%f ", moved_objData[i] - objData.vertices[i]);
    // printf("%f ", moved_objData[i+1] - objData.vertices[i+1]);
    // printf("%f\n", moved_objData[i+2] - objData.vertices[i+2]);
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// move model by y test
START_TEST(test_2) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float x_offset = 0, y_offset = 87, z_offset = 0;

  float moved_objData[24] = {1.00,  1.87,  -1.00, 1.00,  -0.13, -1.00,
                             1.00,  -0.13, 1.00,  1.00,  1.87,  -1.00,
                             1.00,  1.87,  -1.00, -1.00, 1.87,  -1.00,
                             -1.00, -0.13, 1.00,  -1.00, 1.87,  -1.00};
  move_operation(x_offset, y_offset, z_offset, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// move model by z test
START_TEST(test_3) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float x_offset = 0, y_offset = 0, z_offset = -43;

  float moved_objData[24] = {1.00,  1.00,  -1.43, 1.00,  -1.00, -1.43,
                             1.00,  -1.00, 0.57,  1.00,  1.00,  -1.43,
                             1.00,  1.00,  -1.43, -1.00, 1.00,  -1.43,
                             -1.00, -1.00, 0.57,  -1.00, 1.00,  -1.43};
  move_operation(x_offset, y_offset, z_offset, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// move model by x,y,z test
START_TEST(test_4) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float x_offset = -50, y_offset = 134, z_offset = -11;

  float moved_objData[24] = {0.50,  2.34, -1.11, 0.50,  0.34, -1.11,
                             0.50,  0.34, 0.89,  0.50,  2.34, -1.11,
                             0.50,  2.34, -1.11, -1.50, 2.34, -1.11,
                             -1.50, 0.34, 0.89,  -1.50, 2.34, -1.11};
  move_operation(x_offset, y_offset, z_offset, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// zoom model by scale test
START_TEST(test_5) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  int scale = 150;

  float moved_objData[24] = {1.50,  1.50,  -1.50, 1.50,  -1.50, -1.50,
                             1.50,  -1.50, 1.50,  1.50,  1.50,  -1.50,
                             1.50,  1.50,  -1.50, -1.50, 1.50,  -1.50,
                             -1.50, -1.50, 1.50,  -1.50, 1.50,  -1.50};
  zoom_operation(scale, scale, scale, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// zoom model by scale test
START_TEST(test_6) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  int scale = 66;

  float moved_objData[24] = {0.66,  0.66,  -0.66, 0.66,  -0.66, -0.66,
                             0.66,  -0.66, 0.66,  0.66,  0.66,  -0.66,
                             0.66,  0.66,  -0.66, -0.66, 0.66,  -0.66,
                             -0.66, -0.66, 0.66,  -0.66, 0.66,  -0.66};
  zoom_operation(scale, scale, scale, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

Suite *test_3dv(void) {
  Suite *s = suite_create("\033[45m-=S21_3D_VIEWER=-\033[0m");
  TCase *tc1_1 = tcase_create("3dv");

  suite_add_tcase(s, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);

  suite_add_tcase(s, tc1_1);
  return s;
}

int main(void) {
  int failed = 0;
  Suite *s21_3dv_test[] = {test_3dv(), NULL};

  for (int i = 0; s21_3dv_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_3dv_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
