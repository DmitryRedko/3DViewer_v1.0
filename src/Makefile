CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
OS = $(shell uname)
TEST_FILE_NAME = s21_tests.c
TEST_LIBS = s21_tests.o
TEST_FLAGS = -lcheck

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
endif

all: gcov_report

install:
	cd back; make install 
	cd back; mv s21_SmartCalc ../

uninstall:
	cd back; make uninstall
	rm -rf s21_SmartCalc 

dist: 
	cd back; make dist
	cd back; mv s21_SmartCalc1.0.0.tar.gz ../
	

tests: $(TEST_FILE_NAME)
	# $(CC) ${CFLAGS} ${TEST_FILE_NAME} backend/parser/s21_parser.c ${TEST_FLAGS} -o s21_tests --coverage
	$(CC) ${CFLAGS} s21_tests.c backend/parser/s21_parser.c backend/operations/s21_arithmetic.c -lcheck -lsubunit -lm -o s21_tests --coverage
	./s21_tests

gcov_report: tests
	lcov -t "s21_tests" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM ./s21_tests
	# cd back; make clean

check: tests
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	clang-format -style=google -i *.c *.h
	make test

clang_n:
	clang-format -n --style=Google *.[ch] 
	clang-format -n --style=Google ./backend/operations/*.[ch] 
	clang-format -n --style=Google ./backend/parser/*.[ch]  
	clang-format -n --style=Google ./backend/viewer/*.[ch] ./backend/viewer/*.cpp 

clang_i:
	clang-format -i --style=Google *.[ch] 
	clang-format -i --style=Google ./backend/operations/*.[ch] 
	clang-format -i --style=Google ./backend/parser/*.[ch]  
	clang-format -i --style=Google ./backend/viewer/*.[ch] ./backend/viewer/*.cpp 
