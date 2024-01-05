#ifndef OBJ_PARSER
#define OBJ_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../backend.h"

ObjData parse_obj(const char *file_path, double *parse_flag);

#endif 
