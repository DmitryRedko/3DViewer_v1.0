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
  float xMov = 25;
  float yMov = 0;
  float zMov = 0;

  float moved_objData[24] = {1.25,  1.00,  -1.00, 1.25,  -1.00, -1.00,
                             1.25,  -1.00, 1.00,  1.25,  1.00,  -1.00,
                             1.25,  1.00,  -1.00, -0.75, 1.00,  -1.00,
                             -0.75, -1.00, 1.00,  -0.75, 1.00,  -1.00};
  move_operation(xMov, yMov, zMov, &objData, &baseData);

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
  float xMov = 0, yMov = 87, zMov = 0;

  float moved_objData[24] = {1.00,  1.87,  -1.00, 1.00,  -0.13, -1.00,
                             1.00,  -0.13, 1.00,  1.00,  1.87,  -1.00,
                             1.00,  1.87,  -1.00, -1.00, 1.87,  -1.00,
                             -1.00, -0.13, 1.00,  -1.00, 1.87,  -1.00};
  move_operation(xMov, yMov, zMov, &objData, &baseData);

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
  float xMov = 0, yMov = 0, zMov = -43;

  float moved_objData[24] = {1.00,  1.00,  -1.43, 1.00,  -1.00, -1.43,
                             1.00,  -1.00, 0.57,  1.00,  1.00,  -1.43,
                             1.00,  1.00,  -1.43, -1.00, 1.00,  -1.43,
                             -1.00, -1.00, 0.57,  -1.00, 1.00,  -1.43};
  move_operation(xMov, yMov, zMov, &objData, &baseData);

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
  float xMov = -50, yMov = 134, zMov = -11;

  float moved_objData[24] = {0.50,  2.34, -1.11, 0.50,  0.34, -1.11,
                             0.50,  0.34, 0.89,  0.50,  2.34, -1.11,
                             0.50,  2.34, -1.11, -1.50, 2.34, -1.11,
                             -1.50, 0.34, 0.89,  -1.50, 2.34, -1.11};
  move_operation(xMov, yMov, zMov, &objData, &baseData);

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

// open not *.obj file
START_TEST(test_7) {
  const char model_file[] = "s21_test.c";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  ck_assert_int_eq(parse_flag, FAIL);

  int scale = 66;
  zoom_operation(scale, scale, scale, &objData, &baseData);

  // model_destructor(&objData);
  // model_destructor(&baseData);
}
END_TEST

// open NULL file
START_TEST(test_8) {
  const char model_file[] = "not_existed_file";
  // const char model_file[] = "";
  // const char model_file[] = NULL;

  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  ck_assert_int_eq(parse_flag, FAIL);

  int scale = 66;
  zoom_operation(scale, scale, scale, &objData, &baseData);

  // model_destructor(&objData);
  // model_destructor(&baseData);
}
END_TEST

// rotate model by x test
START_TEST(test_9) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 45;
  float yRot = 0;
  float zRot = 0;

  float moved_objData[24] = {1,  1.41421345027257,      -0.000563088061833805,
                             1,  -0.000563088061833805, -1.41421345027257,
                             1,  -1.41421345027257,     0.000563088061833805,
                             1,  1.41421345027257,      -0.000563088061833805,
                             1,  1.41421345027257,      -0.000563088061833805,
                             -1, 1.41421345027257,      -0.000563088061833805,
                             -1, -1.41421345027257,     0.000563088061833805,
                             -1, 1.41421345027257,      -0.000563088061833805};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by -x test
START_TEST(test_10) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = -45;
  float yRot = 0;
  float zRot = 0;

  float moved_objData[24] = {1	,	0.000563088061833805	,	-1.41421345027257	,	1	,	-1.41421345027257	,	-0.000563088061833805	,	1	,	-0.000563088061833805	,	1.41421345027257	,	1	,	0.000563088061833805	,	-1.41421345027257	,	1	,	0.000563088061833805	,	-1.41421345027257	,	-1	,	0.000563088061833805	,	-1.41421345027257	,	-1	,	-0.000563088061833805	,	1.41421345027257	,	-1	,	0.000563088061833805	,	-1.41421345027257
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by y test
START_TEST(test_11) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 0;
  float yRot = 80;
  float zRot = 0;

  float moved_objData[24] = {-0.810339363756687	,	1	,	-1.15902981650448	,	-0.810339363756687	,	-1	,	-1.15902981650448	,	1.15902981650448	,	-1	,	-0.810339363756687	,	-0.810339363756687	,	1	,	-1.15902981650448	,	-0.810339363756687	,	1	,	-1.15902981650448	,	-1.15902981650448	,	1	,	0.810339363756687	,	0.810339363756687	,	-1	,	1.15902981650448	,	-1.15902981650448	,	1	,	0.810339363756687
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by -y test
START_TEST(test_12) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 0;
  float yRot = -80;
  float zRot = 0;

  float moved_objData[24] = {1.15902981650448	,	1	,	0.810339363756687	,	1.15902981650448	,	-1	,	0.810339363756687	,	-0.810339363756687	,	-1	,	1.15902981650448	,	1.15902981650448	,	1	,	0.810339363756687	,	1.15902981650448	,	1	,	0.810339363756687	,	0.810339363756687	,	1	,	-1.15902981650448	,	-1.15902981650448	,	-1	,	-0.810339363756687	,	0.810339363756687	,	1	,	-1.15902981650448
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by z test
START_TEST(test_13) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 0;
  float yRot = 0;
  float zRot = 345;

  float moved_objData[24] = {1.22689766607904	,	0.703364853379667	,	-1	,	0.703364853379667	,	-1.22689766607904	,	-1	,	0.703364853379667	,	-1.22689766607904	,	1	,	1.22689766607904	,	0.703364853379667	,	-1	,	1.22689766607904	,	0.703364853379667	,	-1	,	-0.703364853379667	,	1.22689766607904	,	-1	,	-1.22689766607904	,	-0.703364853379667	,	1	,	-0.703364853379667	,	1.22689766607904	,	-1
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by -z test
START_TEST(test_14) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 0;
  float yRot = 0;
  float zRot = -234;

  float moved_objData[24] = {-1.39725730164863	,	0.218339261218873	,	-1	,	0.218339261218873	,	1.39725730164863	,	-1	,	0.218339261218873	,	1.39725730164863	,	1	,	-1.39725730164863	,	0.218339261218873	,	-1	,	-1.39725730164863	,	0.218339261218873	,	-1	,	-0.218339261218873	,	-1.39725730164863	,	-1	,	1.39725730164863	,	-0.218339261218873	,	1	,	-0.218339261218873	,	-1.39725730164863	,	-1
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by x,y,z test
START_TEST(test_15) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 360;
  float yRot = -360;
  float zRot = 360;

  float moved_objData[24] = {0.999969577768162	,	0.993629460999417	,	-1.00636044127945	,	0.993619298692592	,	-1.00635031134264	,	-0.999989870011799	,	1.00001012993681	,	-1.00000003226707	,	0.999989837693175	,	0.999969577768162	,	0.993629460999417	,	-1.00636044127945	,	0.999969577768162	,	0.993629460999417	,	-1.00636044127945	,	-1.00001012993681	,	1.00000003226707	,	-0.999989837693175	,	-0.999969577768162	,	-0.993629460999417	,	1.00636044127945	,	-1.00001012993681	,	1.00000003226707	,	-0.999989837693175
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

  for (unsigned int i = 0; i < objData.vertexCount; i++) {
    float diff = moved_objData[i] - objData.vertices[i];
    ck_assert_float_lt(diff, EPS);
  }

  model_destructor(&objData);
  model_destructor(&baseData);
}
END_TEST

// rotate model by x,y,z test
START_TEST(test_16) {
  const char model_file[] = "models/cube.obj";
  int parse_flag = 0;
  ObjData objData = parse_obj(model_file, &parse_flag);
  ObjData baseData = parse_obj(model_file, &parse_flag);
  float xRot = 123;
  float yRot = 234;
  float zRot = 345;

  float moved_objData[24] = {-1.56976515764164	,	0.731971542452076	,	-0.00741693296804724	,	0.0235244642926441	,	1.42657369868314	,	0.982005133288651	,	0.43195450416401	,	-0.423370403627964	,	1.62301349583555	,	-1.56976515764164	,	0.731971542452076	,	-0.00741693296804724	,	-1.56976515764164	,	0.731971542452076	,	-0.00741693296804724	,	-0.43195450416401	,	0.423370403627964	,	-1.62301349583555	,	1.56976515764164	,	-0.731971542452076	,	0.00741693296804724	,	-0.43195450416401	,	0.423370403627964	,	-1.62301349583555
};
  rotate_operation(xRot, yRot, zRot, &objData, &baseData);

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
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  tcase_add_test(tc1_1, test_10);
  tcase_add_test(tc1_1, test_11);
  tcase_add_test(tc1_1, test_12);
  tcase_add_test(tc1_1, test_13);
  tcase_add_test(tc1_1, test_14);
  tcase_add_test(tc1_1, test_15);
  tcase_add_test(tc1_1, test_16);

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
