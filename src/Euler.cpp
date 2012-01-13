//============================================================================
// Name        : Euler.cpp
// Author      : Yongsung Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//convert macro for #11
//#define SIZE_DATA	20 //for 11
#define SIZE_DATA	50 //for 13
#define GET_X(x)	x%SIZE_DATA+1
#define GET_Y(x)	x/SIZE_DATA+1
#define GET_I(x,y)	(x-1)+(y-1)*SIZE_DATA
#define MAX			20
#define UNIT		4

bool chek_primenumber(int x);
bool check_pal(int x);
int get_max_product(int x,int y,int);

int count_number_of_divider(int t);
int get_triangle(int i);

int get_column_sum(int x, int size);

unsigned long problem_14(unsigned long x);

int add_path(unsigned char *path, int length, int current_count);
void get_large_sum(unsigned char* num_1, unsigned char* num_2, unsigned char* result, int size);

#define MAX_ROW	100 + 1
int get_max_route_b_to_t(int data[][MAX_ROW], int i);
int get_max_route_t_to_b(int data[][MAX_ROW]);
int get_max_route_b_to_t_2(int data[][MAX_ROW]);

unsigned long get_days(int year, int month, int day);

int get_sum_of_divisors(int n);

int comparisonFunctionString(const void *a, const void *b);
int is_abundant(int n);
void get_next_digits(unsigned char * current_num);
int comparisonFunctionInt(const void *a, const void *b);
int get_repeat_number(int n);
int formula(int a, int b);

int data[] = {
					7,3,1,6,7,1,7,6,5,3,1,3,3,0,6,2,4,9,1,9,2,2,5,1,1,9,6,7,4,4,2,6,5,7,4,7,4,2,3,5,5,3,4,9,1,9,4,9,3,4,
					9,6,9,8,3,5,2,0,3,1,2,7,7,4,5,0,6,3,2,6,2,3,9,5,7,8,3,1,8,0,1,6,9,8,4,8,0,1,8,6,9,4,7,8,8,5,1,8,4,3,
					8,5,8,6,1,5,6,0,7,8,9,1,1,2,9,4,9,4,9,5,4,5,9,5,0,1,7,3,7,9,5,8,3,3,1,9,5,2,8,5,3,2,0,8,8,0,5,5,1,1,
					1,2,5,4,0,6,9,8,7,4,7,1,5,8,5,2,3,8,6,3,0,5,0,7,1,5,6,9,3,2,9,0,9,6,3,2,9,5,2,2,7,4,4,3,0,4,3,5,5,7,
					6,6,8,9,6,6,4,8,9,5,0,4,4,5,2,4,4,5,2,3,1,6,1,7,3,1,8,5,6,4,0,3,0,9,8,7,1,1,1,2,1,7,2,2,3,8,3,1,1,3,
					6,2,2,2,9,8,9,3,4,2,3,3,8,0,3,0,8,1,3,5,3,3,6,2,7,6,6,1,4,2,8,2,8,0,6,4,4,4,4,8,6,6,4,5,2,3,8,7,4,9,
					3,0,3,5,8,9,0,7,2,9,6,2,9,0,4,9,1,5,6,0,4,4,0,7,7,2,3,9,0,7,1,3,8,1,0,5,1,5,8,5,9,3,0,7,9,6,0,8,6,6,
					7,0,1,7,2,4,2,7,1,2,1,8,8,3,9,9,8,7,9,7,9,0,8,7,9,2,2,7,4,9,2,1,9,0,1,6,9,9,7,2,0,8,8,8,0,9,3,7,7,6,
					6,5,7,2,7,3,3,3,0,0,1,0,5,3,3,6,7,8,8,1,2,2,0,2,3,5,4,2,1,8,0,9,7,5,1,2,5,4,5,4,0,5,9,4,7,5,2,2,4,3,
					5,2,5,8,4,9,0,7,7,1,1,6,7,0,5,5,6,0,1,3,6,0,4,8,3,9,5,8,6,4,4,6,7,0,6,3,2,4,4,1,5,7,2,2,1,5,5,3,9,7,
					5,3,6,9,7,8,1,7,9,7,7,8,4,6,1,7,4,0,6,4,9,5,5,1,4,9,2,9,0,8,6,2,5,6,9,3,2,1,9,7,8,4,6,8,6,2,2,4,8,2,
					8,3,9,7,2,2,4,1,3,7,5,6,5,7,0,5,6,0,5,7,4,9,0,2,6,1,4,0,7,9,7,2,9,6,8,6,5,2,4,1,4,5,3,5,1,0,0,4,7,4,
					8,2,1,6,6,3,7,0,4,8,4,4,0,3,1,9,9,8,9,0,0,0,8,8,9,5,2,4,3,4,5,0,6,5,8,5,4,1,2,2,7,5,8,8,6,6,6,8,8,1,
					1,6,4,2,7,1,7,1,4,7,9,9,2,4,4,4,2,9,2,8,2,3,0,8,6,3,4,6,5,6,7,4,8,1,3,9,1,9,1,2,3,1,6,2,8,2,4,5,8,6,
					1,7,8,6,6,4,5,8,3,5,9,1,2,4,5,6,6,5,2,9,4,7,6,5,4,5,6,8,2,8,4,8,9,1,2,8,8,3,1,4,2,6,0,7,6,9,0,0,4,2,
					2,4,2,1,9,0,2,2,6,7,1,0,5,5,6,2,6,3,2,1,1,1,1,1,0,9,3,7,0,5,4,4,2,1,7,5,0,6,9,4,1,6,5,8,9,6,0,4,0,8,
					0,7,1,9,8,4,0,3,8,5,0,9,6,2,4,5,5,4,4,4,3,6,2,9,8,1,2,3,0,9,8,7,8,7,9,9,2,7,2,4,4,2,8,4,9,0,9,1,8,8,
					8,4,5,8,0,1,5,6,1,6,6,0,9,7,9,1,9,1,3,3,8,7,5,4,9,9,2,0,0,5,2,4,0,6,3,6,8,9,9,1,2,5,6,0,7,1,7,6,0,6,
					0,5,8,8,6,1,1,6,4,6,7,1,0,9,4,0,5,0,7,7,5,4,1,0,0,2,2,5,6,9,8,3,1,5,5,2,0,0,0,5,5,9,3,5,7,2,9,7,2,5,
					7,1,6,3,6,2,6,9,5,6,1,8,8,2,6,7,0,4,2,8,2,5,2,4,8,3,6,0,0,8,2,3,2,5,7,5,3,0,4,2,0,7,5,2,9,6,3,4,5,0
};

int data_11[] = {
					8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
					49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00,
					81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65,
					52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91,
					22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
					24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
					32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
					67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
					24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
					21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
					78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92,
					16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
					86, 56, 0, 48, 35, 71, 89, 7, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
					19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40,
					4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
					88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
					4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
					20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
					20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
					1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48
};

int data_13[] = {
	3,7,1,0,7,2,8,7,5,3,3,9,0,2,1,0,2,7,9,8,7,9,7,9,9,8,2,2,0,8,3,7,5,9,0,2,4,6,5,1,0,1,3,5,7,4,0,2,5,0,
	4,6,3,7,6,9,3,7,6,7,7,4,9,0,0,0,9,7,1,2,6,4,8,1,2,4,8,9,6,9,7,0,0,7,8,0,5,0,4,1,7,0,1,8,2,6,0,5,3,8,
	7,4,3,2,4,9,8,6,1,9,9,5,2,4,7,4,1,0,5,9,4,7,4,2,3,3,3,0,9,5,1,3,0,5,8,1,2,3,7,2,6,6,1,7,3,0,9,6,2,9,
	9,1,9,4,2,2,1,3,3,6,3,5,7,4,1,6,1,5,7,2,5,2,2,4,3,0,5,6,3,3,0,1,8,1,1,0,7,2,4,0,6,1,5,4,9,0,8,2,5,0,
	2,3,0,6,7,5,8,8,2,0,7,5,3,9,3,4,6,1,7,1,1,7,1,9,8,0,3,1,0,4,2,1,0,4,7,5,1,3,7,7,8,0,6,3,2,4,6,6,7,6,
	8,9,2,6,1,6,7,0,6,9,6,6,2,3,6,3,3,8,2,0,1,3,6,3,7,8,4,1,8,3,8,3,6,8,4,1,7,8,7,3,4,3,6,1,7,2,6,7,5,7,
	2,8,1,1,2,8,7,9,8,1,2,8,4,9,9,7,9,4,0,8,0,6,5,4,8,1,9,3,1,5,9,2,6,2,1,6,9,1,2,7,5,8,8,9,8,3,2,7,3,8,
	4,4,2,7,4,2,2,8,9,1,7,4,3,2,5,2,0,3,2,1,9,2,3,5,8,9,4,2,2,8,7,6,7,9,6,4,8,7,6,7,0,2,7,2,1,8,9,3,1,8,
	4,7,4,5,1,4,4,5,7,3,6,0,0,1,3,0,6,4,3,9,0,9,1,1,6,7,2,1,6,8,5,6,8,4,4,5,8,8,7,1,1,6,0,3,1,5,3,2,7,6,
	7,0,3,8,6,4,8,6,1,0,5,8,4,3,0,2,5,4,3,9,9,3,9,6,1,9,8,2,8,9,1,7,5,9,3,6,6,5,6,8,6,7,5,7,9,3,4,9,5,1,
	6,2,1,7,6,4,5,7,1,4,1,8,5,6,5,6,0,6,2,9,5,0,2,1,5,7,2,2,3,1,9,6,5,8,6,7,5,5,0,7,9,3,2,4,1,9,3,3,3,1,
	6,4,9,0,6,3,5,2,4,6,2,7,4,1,9,0,4,9,2,9,1,0,1,4,3,2,4,4,5,8,1,3,8,2,2,6,6,3,3,4,7,9,4,4,7,5,8,1,7,8,
	9,2,5,7,5,8,6,7,7,1,8,3,3,7,2,1,7,6,6,1,9,6,3,7,5,1,5,9,0,5,7,9,2,3,9,7,2,8,2,4,5,5,9,8,8,3,8,4,0,7,
	5,8,2,0,3,5,6,5,3,2,5,3,5,9,3,9,9,0,0,8,4,0,2,6,3,3,5,6,8,9,4,8,8,3,0,1,8,9,4,5,8,6,2,8,2,2,7,8,2,8,
	8,0,1,8,1,1,9,9,3,8,4,8,2,6,2,8,2,0,1,4,2,7,8,1,9,4,1,3,9,9,4,0,5,6,7,5,8,7,1,5,1,1,7,0,0,9,4,3,9,0,
	3,5,3,9,8,6,6,4,3,7,2,8,2,7,1,1,2,6,5,3,8,2,9,9,8,7,2,4,0,7,8,4,4,7,3,0,5,3,1,9,0,1,0,4,2,9,3,5,8,6,
	8,6,5,1,5,5,0,6,0,0,6,2,9,5,8,6,4,8,6,1,5,3,2,0,7,5,2,7,3,3,7,1,9,5,9,1,9,1,4,2,0,5,1,7,2,5,5,8,2,9,
	7,1,6,9,3,8,8,8,7,0,7,7,1,5,4,6,6,4,9,9,1,1,5,5,9,3,4,8,7,6,0,3,5,3,2,9,2,1,7,1,4,9,7,0,0,5,6,9,3,8,
	5,4,3,7,0,0,7,0,5,7,6,8,2,6,6,8,4,6,2,4,6,2,1,4,9,5,6,5,0,0,7,6,4,7,1,7,8,7,2,9,4,4,3,8,3,7,7,6,0,4,
	5,3,2,8,2,6,5,4,1,0,8,7,5,6,8,2,8,4,4,3,1,9,1,1,9,0,6,3,4,6,9,4,0,3,7,8,5,5,2,1,7,7,7,9,2,9,5,1,4,5,
	3,6,1,2,3,2,7,2,5,2,5,0,0,0,2,9,6,0,7,1,0,7,5,0,8,2,5,6,3,8,1,5,6,5,6,7,1,0,8,8,5,2,5,8,3,5,0,7,2,1,
	4,5,8,7,6,5,7,6,1,7,2,4,1,0,9,7,6,4,4,7,3,3,9,1,1,0,6,0,7,2,1,8,2,6,5,2,3,6,8,7,7,2,2,3,6,3,6,0,4,5,
	1,7,4,2,3,7,0,6,9,0,5,8,5,1,8,6,0,6,6,0,4,4,8,2,0,7,6,2,1,2,0,9,8,1,3,2,8,7,8,6,0,7,3,3,9,6,9,4,1,2,
	8,1,1,4,2,6,6,0,4,1,8,0,8,6,8,3,0,6,1,9,3,2,8,4,6,0,8,1,1,1,9,1,0,6,1,5,5,6,9,4,0,5,1,2,6,8,9,6,9,2,
	5,1,9,3,4,3,2,5,4,5,1,7,2,8,3,8,8,6,4,1,9,1,8,0,4,7,0,4,9,2,9,3,2,1,5,0,5,8,6,4,2,5,6,3,0,4,9,4,8,3,
	6,2,4,6,7,2,2,1,6,4,8,4,3,5,0,7,6,2,0,1,7,2,7,9,1,8,0,3,9,9,4,4,6,9,3,0,0,4,7,3,2,9,5,6,3,4,0,6,9,1,
	1,5,7,3,2,4,4,4,3,8,6,9,0,8,1,2,5,7,9,4,5,1,4,0,8,9,0,5,7,7,0,6,2,2,9,4,2,9,1,9,7,1,0,7,9,2,8,2,0,9,
	5,5,0,3,7,6,8,7,5,2,5,6,7,8,7,7,3,0,9,1,8,6,2,5,4,0,7,4,4,9,6,9,8,4,4,5,0,8,3,3,0,3,9,3,6,8,2,1,2,6,
	1,8,3,3,6,3,8,4,8,2,5,3,3,0,1,5,4,6,8,6,1,9,6,1,2,4,3,4,8,7,6,7,6,8,1,2,9,7,5,3,4,3,7,5,9,4,6,5,1,5,
	8,0,3,8,6,2,8,7,5,9,2,8,7,8,4,9,0,2,0,1,5,2,1,6,8,5,5,5,4,8,2,8,7,1,7,2,0,1,2,1,9,2,5,7,7,6,6,9,5,4,
	7,8,1,8,2,8,3,3,7,5,7,9,9,3,1,0,3,6,1,4,7,4,0,3,5,6,8,5,6,4,4,9,0,9,5,5,2,7,0,9,7,8,6,4,7,9,7,5,8,1,
	1,6,7,2,6,3,2,0,1,0,0,4,3,6,8,9,7,8,4,2,5,5,3,5,3,9,9,2,0,9,3,1,8,3,7,4,4,1,4,9,7,8,0,6,8,6,0,9,8,4,
	4,8,4,0,3,0,9,8,1,2,9,0,7,7,7,9,1,7,9,9,0,8,8,2,1,8,7,9,5,3,2,7,3,6,4,4,7,5,6,7,5,5,9,0,8,4,8,0,3,0,
	8,7,0,8,6,9,8,7,5,5,1,3,9,2,7,1,1,8,5,4,5,1,7,0,7,8,5,4,4,1,6,1,8,5,2,4,2,4,3,2,0,6,9,3,1,5,0,3,3,2,
	5,9,9,5,9,4,0,6,8,9,5,7,5,6,5,3,6,7,8,2,1,0,7,0,7,4,9,2,6,9,6,6,5,3,7,6,7,6,3,2,6,2,3,5,4,4,7,2,1,0,
	6,9,7,9,3,9,5,0,6,7,9,6,5,2,6,9,4,7,4,2,5,9,7,7,0,9,7,3,9,1,6,6,6,9,3,7,6,3,0,4,2,6,3,3,9,8,7,0,8,5,
	4,1,0,5,2,6,8,4,7,0,8,2,9,9,0,8,5,2,1,1,3,9,9,4,2,7,3,6,5,7,3,4,1,1,6,1,8,2,7,6,0,3,1,5,0,0,1,2,7,1,
	6,5,3,7,8,6,0,7,3,6,1,5,0,1,0,8,0,8,5,7,0,0,9,1,4,9,9,3,9,5,1,2,5,5,7,0,2,8,1,9,8,7,4,6,0,0,4,3,7,5,
	3,5,8,2,9,0,3,5,3,1,7,4,3,4,7,1,7,3,2,6,9,3,2,1,2,3,5,7,8,1,5,4,9,8,2,6,2,9,7,4,2,5,5,2,7,3,7,3,0,7,
	9,4,9,5,3,7,5,9,7,6,5,1,0,5,3,0,5,9,4,6,9,6,6,0,6,7,6,8,3,1,5,6,5,7,4,3,7,7,1,6,7,4,0,1,8,7,5,2,7,5,
	8,8,9,0,2,8,0,2,5,7,1,7,3,3,2,2,9,6,1,9,1,7,6,6,6,8,7,1,3,8,1,9,9,3,1,8,1,1,0,4,8,7,7,0,1,9,0,2,7,1,
	2,5,2,6,7,6,8,0,2,7,6,0,7,8,0,0,3,0,1,3,6,7,8,6,8,0,9,9,2,5,2,5,4,6,3,4,0,1,0,6,1,6,3,2,8,6,6,5,2,6,
	3,6,2,7,0,2,1,8,5,4,0,4,9,7,7,0,5,5,8,5,6,2,9,9,4,6,5,8,0,6,3,6,2,3,7,9,9,3,1,4,0,7,4,6,2,5,5,9,6,2,
	2,4,0,7,4,4,8,6,9,0,8,2,3,1,1,7,4,9,7,7,7,9,2,3,6,5,4,6,6,2,5,7,2,4,6,9,2,3,3,2,2,8,1,0,9,1,7,1,4,1,
	9,1,4,3,0,2,8,8,1,9,7,1,0,3,2,8,8,5,9,7,8,0,6,6,6,9,7,6,0,8,9,2,9,3,8,6,3,8,2,8,5,0,2,5,3,3,3,4,0,3,
	3,4,4,1,3,0,6,5,5,7,8,0,1,6,1,2,7,8,1,5,9,2,1,8,1,5,0,0,5,5,6,1,8,6,8,8,3,6,4,6,8,4,2,0,0,9,0,4,7,0,
	2,3,0,5,3,0,8,1,1,7,2,8,1,6,4,3,0,4,8,7,6,2,3,7,9,1,9,6,9,8,4,2,4,8,7,2,5,5,0,3,6,6,3,8,7,8,4,5,8,3,
	1,1,4,8,7,6,9,6,9,3,2,1,5,4,9,0,2,8,1,0,4,2,4,0,2,0,1,3,8,3,3,5,1,2,4,4,6,2,1,8,1,4,4,1,7,7,3,4,7,0,
	6,3,7,8,3,2,9,9,4,9,0,6,3,6,2,5,9,6,6,6,4,9,8,5,8,7,6,1,8,2,2,1,2,2,5,2,2,5,5,1,2,4,8,6,7,6,4,5,3,3,
	6,7,7,2,0,1,8,6,9,7,1,6,9,8,5,4,4,3,1,2,4,1,9,5,7,2,4,0,9,9,1,3,9,5,9,0,0,8,9,5,2,3,1,0,0,5,8,8,2,2,
	9,5,5,4,8,2,5,5,3,0,0,2,6,3,5,2,0,7,8,1,5,3,2,2,9,6,7,9,6,2,4,9,4,8,1,6,4,1,9,5,3,8,6,8,2,1,8,7,7,4,
	7,6,0,8,5,3,2,7,1,3,2,2,8,5,7,2,3,1,1,0,4,2,4,8,0,3,4,5,6,1,2,4,8,6,7,6,9,7,0,6,4,5,0,7,9,9,5,2,3,6,
	3,7,7,7,4,2,4,2,5,3,5,4,1,1,2,9,1,6,8,4,2,7,6,8,6,5,5,3,8,9,2,6,2,0,5,0,2,4,9,1,0,3,2,6,5,7,2,9,6,7,
	2,3,7,0,1,9,1,3,2,7,5,7,2,5,6,7,5,2,8,5,6,5,3,2,4,8,2,5,8,2,6,5,4,6,3,0,9,2,2,0,7,0,5,8,5,9,6,5,2,2,
	2,9,7,9,8,8,6,0,2,7,2,2,5,8,3,3,1,9,1,3,1,2,6,3,7,5,1,4,7,3,4,1,9,9,4,8,8,9,5,3,4,7,6,5,7,4,5,5,0,1,
	1,8,4,9,5,7,0,1,4,5,4,8,7,9,2,8,8,9,8,4,8,5,6,8,2,7,7,2,6,0,7,7,7,1,3,7,2,1,4,0,3,7,9,8,8,7,9,7,1,5,
	3,8,2,9,8,2,0,3,7,8,3,0,3,1,4,7,3,5,2,7,7,2,1,5,8,0,3,4,8,1,4,4,5,1,3,4,9,1,3,7,3,2,2,6,6,5,1,3,8,1,
	3,4,8,2,9,5,4,3,8,2,9,1,9,9,9,1,8,1,8,0,2,7,8,9,1,6,5,2,2,4,3,1,0,2,7,3,9,2,2,5,1,1,2,2,8,6,9,5,3,9,
	4,0,9,5,7,9,5,3,0,6,6,4,0,5,2,3,2,6,3,2,5,3,8,0,4,4,1,0,0,0,5,9,6,5,4,9,3,9,1,5,9,8,7,9,5,9,3,6,3,5,
	2,9,7,4,6,1,5,2,1,8,5,5,0,2,3,7,1,3,0,7,6,4,2,2,5,5,1,2,1,1,8,3,6,9,3,8,0,3,5,8,0,3,8,8,5,8,4,9,0,3,
	4,1,6,9,8,1,1,6,2,2,2,0,7,2,9,7,7,1,8,6,1,5,8,2,3,6,6,7,8,4,2,4,6,8,9,1,5,7,9,9,3,5,3,2,9,6,1,9,2,2,
	6,2,4,6,7,9,5,7,1,9,4,4,0,1,2,6,9,0,4,3,8,7,7,1,0,7,2,7,5,0,4,8,1,0,2,3,9,0,8,9,5,5,2,3,5,9,7,4,5,7,
	2,3,1,8,9,7,0,6,7,7,2,5,4,7,9,1,5,0,6,1,5,0,5,5,0,4,9,5,3,9,2,2,9,7,9,5,3,0,9,0,1,1,2,9,9,6,7,5,1,9,
	8,6,1,8,8,0,8,8,2,2,5,8,7,5,3,1,4,5,2,9,5,8,4,0,9,9,2,5,1,2,0,3,8,2,9,0,0,9,4,0,7,7,7,0,7,7,5,6,7,2,
	1,1,3,0,6,7,3,9,7,0,8,3,0,4,7,2,4,4,8,3,8,1,6,5,3,3,8,7,3,5,0,2,3,4,0,8,4,5,6,4,7,0,5,8,0,7,7,3,0,8,
	8,2,9,5,9,1,7,4,7,6,7,1,4,0,3,6,3,1,9,8,0,0,8,1,8,7,1,2,9,0,1,1,8,7,5,4,9,1,3,1,0,5,4,7,1,2,6,5,8,1,
	9,7,6,2,3,3,3,1,0,4,4,8,1,8,3,8,6,2,6,9,5,1,5,4,5,6,3,3,4,9,2,6,3,6,6,5,7,2,8,9,7,5,6,3,4,0,0,5,0,0,
	4,2,8,4,6,2,8,0,1,8,3,5,1,7,0,7,0,5,2,7,8,3,1,8,3,9,4,2,5,8,8,2,1,4,5,5,2,1,2,2,7,2,5,1,2,5,0,3,2,7,
	5,5,1,2,1,6,0,3,5,4,6,9,8,1,2,0,0,5,8,1,7,6,2,1,6,5,2,1,2,8,2,7,6,5,2,7,5,1,6,9,1,2,9,6,8,9,7,7,8,9,
	3,2,2,3,8,1,9,5,7,3,4,3,2,9,3,3,9,9,4,6,4,3,7,5,0,1,9,0,7,8,3,6,9,4,5,7,6,5,8,8,3,3,5,2,3,9,9,8,8,6,
	7,5,5,0,6,1,6,4,9,6,5,1,8,4,7,7,5,1,8,0,7,3,8,1,6,8,8,3,7,8,6,1,0,9,1,5,2,7,3,5,7,9,2,9,7,0,1,3,3,7,
	6,2,1,7,7,8,4,2,7,5,2,1,9,2,6,2,3,4,0,1,9,4,2,3,9,9,6,3,9,1,6,8,0,4,4,9,8,3,9,9,3,1,7,3,3,1,2,7,3,1,
	3,2,9,2,4,1,8,5,7,0,7,1,4,7,3,4,9,5,6,6,9,1,6,6,7,4,6,8,7,6,3,4,6,6,0,9,1,5,0,3,5,9,1,4,6,7,7,5,0,4,
	9,9,5,1,8,6,7,1,4,3,0,2,3,5,2,1,9,6,2,8,8,9,4,8,9,0,1,0,2,4,2,3,3,2,5,1,1,6,9,1,3,6,1,9,6,2,6,6,2,2,
	7,3,2,6,7,4,6,0,8,0,0,5,9,1,5,4,7,4,7,1,8,3,0,7,9,8,3,9,2,8,6,8,5,3,5,2,0,6,9,4,6,9,4,4,5,4,0,7,2,4,
	7,6,8,4,1,8,2,2,5,2,4,6,7,4,4,1,7,1,6,1,5,1,4,0,3,6,4,2,7,9,8,2,2,7,3,3,4,8,0,5,5,5,5,6,2,1,4,8,1,8,
	9,7,1,4,2,6,1,7,9,1,0,3,4,2,5,9,8,6,4,7,2,0,4,5,1,6,8,9,3,9,8,9,4,2,2,1,7,9,8,2,6,0,8,8,0,7,6,8,5,2,
	8,7,7,8,3,6,4,6,1,8,2,7,9,9,3,4,6,3,1,3,7,6,7,7,5,4,3,0,7,8,0,9,3,6,3,3,3,3,0,1,8,9,8,2,6,4,2,0,9,0,
	1,0,8,4,8,8,0,2,5,2,1,6,7,4,6,7,0,8,8,3,2,1,5,1,2,0,1,8,5,8,8,3,5,4,3,2,2,3,8,1,2,8,7,6,9,5,2,7,8,6,
	7,1,3,2,9,6,1,2,4,7,4,7,8,2,4,6,4,5,3,8,6,3,6,9,9,3,0,0,9,0,4,9,3,1,0,3,6,3,6,1,9,7,6,3,8,7,8,0,3,9,
	6,2,1,8,4,0,7,3,5,7,2,3,9,9,7,9,4,2,2,3,4,0,6,2,3,5,3,9,3,8,0,8,3,3,9,6,5,1,3,2,7,4,0,8,0,1,1,1,1,6,
	6,6,6,2,7,8,9,1,9,8,1,4,8,8,0,8,7,7,9,7,9,4,1,8,7,6,8,7,6,1,4,4,2,3,0,0,3,0,9,8,4,4,9,0,8,5,1,4,1,1,
	6,0,6,6,1,8,2,6,2,9,3,6,8,2,8,3,6,7,6,4,7,4,4,7,7,9,2,3,9,1,8,0,3,3,5,1,1,0,9,8,9,0,6,9,7,9,0,7,1,4,
	8,5,7,8,6,9,4,4,0,8,9,5,5,2,9,9,0,6,5,3,6,4,0,4,4,7,4,2,5,5,7,6,0,8,3,6,5,9,9,7,6,6,4,5,7,9,5,0,9,6,
	6,6,0,2,4,3,9,6,4,0,9,9,0,5,3,8,9,6,0,7,1,2,0,1,9,8,2,1,9,9,7,6,0,4,7,5,9,9,4,9,0,1,9,7,2,3,0,2,9,7,
	6,4,9,1,3,9,8,2,6,8,0,0,3,2,9,7,3,1,5,6,0,3,7,1,2,0,0,4,1,3,7,7,9,0,3,7,8,5,5,6,6,0,8,5,0,8,9,2,5,2,
	1,6,7,3,0,9,3,9,3,1,9,8,7,2,7,5,0,2,7,5,4,6,8,9,0,6,9,0,3,7,0,7,5,3,9,4,1,3,0,4,2,6,5,2,3,1,5,0,1,1,
	9,4,8,0,9,3,7,7,2,4,5,0,4,8,7,9,5,1,5,0,9,5,4,1,0,0,9,2,1,6,4,5,8,6,3,7,5,4,7,1,0,5,9,8,4,3,6,7,9,1,
	7,8,6,3,9,1,6,7,0,2,1,1,8,7,4,9,2,4,3,1,9,9,5,7,0,0,6,4,1,9,1,7,9,6,9,7,7,7,5,9,9,0,2,8,3,0,0,6,9,9,
	1,5,3,6,8,7,1,3,7,1,1,9,3,6,6,1,4,9,5,2,8,1,1,3,0,5,8,7,6,3,8,0,2,7,8,4,1,0,7,5,4,4,4,9,7,3,3,0,7,8,
	4,0,7,8,9,9,2,3,1,1,5,5,3,5,5,6,2,5,6,1,1,4,2,3,2,2,4,2,3,2,5,5,0,3,3,6,8,5,4,4,2,4,8,8,9,1,7,3,5,3,
	4,4,8,8,9,9,1,1,5,0,1,4,4,0,6,4,8,0,2,0,3,6,9,0,6,8,0,6,3,9,6,0,6,7,2,3,2,2,1,9,3,2,0,4,1,4,9,5,3,5,
	4,1,5,0,3,1,2,8,8,8,0,3,3,9,5,3,6,0,5,3,2,9,9,3,4,0,3,6,8,0,0,6,9,7,7,7,1,0,6,5,0,5,6,6,6,3,1,9,5,4,
	8,1,2,3,4,8,8,0,6,7,3,2,1,0,1,4,6,7,3,9,0,5,8,5,6,8,5,5,7,9,3,4,5,8,1,4,0,3,6,2,7,8,2,2,7,0,3,2,8,0,
	8,2,6,1,6,5,7,0,7,7,3,9,4,8,3,2,7,5,9,2,2,3,2,8,4,5,9,4,1,7,0,6,5,2,5,0,9,4,5,1,2,3,2,5,2,3,0,6,0,8,
	2,2,9,1,8,8,0,2,0,5,8,7,7,7,3,1,9,7,1,9,8,3,9,4,5,0,1,8,0,8,8,8,0,7,2,4,2,9,6,6,1,9,8,0,8,1,1,1,9,7,
	7,7,1,5,8,5,4,2,5,0,2,0,1,6,5,4,5,0,9,0,4,1,3,2,4,5,8,0,9,7,8,6,8,8,2,7,7,8,9,4,8,7,2,1,8,5,9,6,1,7,
	7,2,1,0,7,8,3,8,4,3,5,0,6,9,1,8,6,1,5,5,4,3,5,6,6,2,8,8,4,0,6,2,2,5,7,4,7,3,6,9,2,2,8,4,5,0,9,5,1,6,
	2,0,8,4,9,6,0,3,9,8,0,1,3,4,0,0,1,7,2,3,9,3,0,6,7,1,6,6,6,8,2,3,5,5,5,2,4,5,2,5,2,8,0,4,6,0,9,7,2,2,
	5,3,5,0,3,5,3,4,2,2,6,4,7,2,5,2,4,2,5,0,8,7,4,0,5,4,0,7,5,5,9,1,7,8,9,7,8,1,2,6,4,3,3,0,3,3,1,6,9,0
};

void euler_1(void)
{
	// #1. find sum of multiples of 3 or 5 below 1000
	int n, result = 0;

	//find multiples of 3 or 5
	for(n=0; n<1000 ; n++)
	{
		//check multiple of 3
		if((n%3 == 0) || (n%5 == 0))
		{
			result = result + n;
		}
	}

	printf("result : %d\n", result);
}

void euler_2(void)
{

	// #2.
	// find sum of odd terms of pibonachi sequence under 4000000
		double result=0;
		int pibona_seq[1000];
		int i, j;

		pibona_seq[0] = 1;
		pibona_seq[1] = 2;

		for(i=2 ; i<1000 ; i++)
		{
			pibona_seq[i] = pibona_seq[i-2] + pibona_seq[i-1];

			if(pibona_seq[i] > 4000000)
				break;
		}

		for(j=0; j<i ; j++)
		{
			if((pibona_seq[j])%2 == 0)
			{
				result = result + pibona_seq[j];
			}

		}

		printf("%lf\n", result);
}

void euler_3(void)
{
	//#3. get the largest prime number can devide 600851475143
	int i;

	for(i=1; i<(600851475143/2) ; i++)
	{
		if(chek_primenumber(i))
		{
			if(600851475143%i == 0)
			{
				printf("%d can divide 600851475143\n",i);
			}
		}
	}

	printf("%d\n",i);
}

void euler_4(void)
{
	//#4. get largest pal.... number by multiple of three digits
	int i, j, multi, result = 0;

	for(i=100; i<1000; i++)
	{
		for(j=100; j<1000 ; j++)
		{
			multi = i * j;
			if(check_pal(multi))
			{
				if(result < multi)
				{
					result = multi;
					printf("Found! %d\n", result);
				}
			}
		}
	}
}

void euler_5(void)
{
	//#5,
	int i, n=20;

	while(1)
	{
		n++;
		for(i=1 ; i<21 ; i++)
		{
			if( n%i != 0)
			{
				i = 99;
			}
		}
		if(i!=100)
		{
			printf("result is %d\n", n);
			break;
		}
	}
}

void euler_6(void)
{
	//#6
	int i;
	double sum_of_square = 0, square_of_sum = 0;

	for(i=1;i<101; i++)
	{
		sum_of_square = i*i + sum_of_square;
	}

	square_of_sum = (((1+100)*100)/2)*(((1+100)*100)/2);

	printf("result is: %f\n", square_of_sum - sum_of_square);
}

void euler_7(void)
{
	//#7, find 10001th prime number
	unsigned int i=0, j=0;

	for(;;)
	{
		i++;
		if(chek_primenumber(i) == 1)
		{
			j++;
			printf("found %uth umber! --- %u\n", j, i);
			if(j==10001)
			{
				break;
			}
		}
		else
		{
			//do nothing
		}
	}
}

void euler_8(void)
{
	//#8. big multi
	int i, result = 0, temp;

	for(i=0; i<996; i++)
	{
		temp = data[i] * data[i+1] * data[i+2] * data[i+3] * data[i+4];
		if(result < temp)
		{
			result = temp;
		}
	}
	printf("result is %d\n",result);
}

void euler_9(void)
{
	//#9. a+b+c=1000, a^2+b^2=c^2, abc=?
	double i, j, k;
	double a, b, c;

	for(i=1; i<1000; i++)
	{
		for(j=1; j<1000; j++)
		{
			k = 1000 - i - j;
			if(k>0)
			{
				printf("check a=%f, b=%f, c=%f\n", i, j, k);
				if(i*i + j*j == k*k)
				{
					a=i;
					b=j;
					c=k;

					i=10000;
					j=10000;
					k=10000;
				}
				else if(i*i + k*k == j*j)
				{
					a=i;
					b=j;
					c=k;
					i=10000;
					j=10000;
					k=10000;
				}
				else if(j*j + k*k == i*i)
				{
					a=i;
					b=j;
					c=k;
					i=10000;
					j=10000;
					k=10000;
				}
			}
		}
	}

	printf("restult is %f\n", a*b*c);
	printf("a=%f, b=%f, c=%f\n", a, b, c);
}

void euler_10(void)
{
	//#10, sum of all prime number under 1000000
	int i;
	double sum = 0;

	for(i=1; i<2000001 ; i++)
	{
		if(chek_primenumber(i))
		{
			sum = sum + i;
			printf("prime number is %d, current sum is %f\n",i, sum);
		}
	}

	printf("result is %f \n", sum);
}

void euler_11(void)
{
	//#11. maximum product all directions (vertical, horizental, diagonal)
	int x, y;
	double result = 0;
	double temp;

	for(x=1;x<MAX-UNIT+2;x++)
	{
		for(y=1;y<MAX-UNIT+2;y++)
		{
			temp = get_max_product(x,y,UNIT);
			if(result < temp)
				result = temp;
		}
	}

	printf("result is %f \n", result);
}

void euler_12(void)
{
	//#12. get triangle number which has 500 dividers
	int triangle;
	int i = 0, n_divider = 0, max = 0;

	while(1)
	{
		i++;
		triangle = get_triangle(i);
		n_divider = count_number_of_divider(triangle);
		if(max < n_divider)
			max = n_divider;
		printf("currnet max : %d\n", max);
		if(500 <= n_divider)
			break;
	}

	printf("result is %d \n", triangle);
}

void euler_13(void)
{
//#13. first 10 digit of sum of data_13
	int i;
	int carry[2] = {0, 0};
	int sum;
	int result[52];

	for(i=1; i<=50 ; i++)
	{
		sum = get_column_sum(i, SIZE_DATA) + carry[0];

		carry[0] = carry[1] + (sum%100) / 10;
		carry[1] = sum / 100;

		result[i-1] = sum%10;

		if(i==50)
		{
			result[50] = carry[0];
			result[51] = carry[1];
		}
	}

	for(i=51; i>=0; i--)
	{
		printf("%d",result[i]);
	}
	printf("\n");
}

void euler_14(void)
{
	//#14. the longest chain
	unsigned long i;
	unsigned long j = 0;
	unsigned long k = 0;
	unsigned long count = 1;
	unsigned long max = 0;
	unsigned long longest = 0;
	int* lookuptable;

	lookuptable = (int*)malloc(sizeof(int)*8000000);
	memset(lookuptable, 0, sizeof(int)*8000000 );

	for(k=2; k<1000000; k++)
	{
		i = k;
		while(1)
		{
			j = problem_14(i);

			if(j<8000000)
			{
				if(lookuptable[j]!=0)
				{
					count = count + lookuptable[j];
					break;
				}
			}
			else
			{
				count = count + 1;
			}

//			printf("%ld\r", count);
			if(j==1)
			{
				break;
			}
			else
			{
				i = j;
			}

		}
		printf("\ncount is %ld", count);
		lookuptable[k] = count;
		if(max < count)
		{
			max = count;
			longest = k;
		}
		printf(", max term is: %ld, max start number is : %ld\n", max, longest);
		count = 1;
	}
}

void euler_15(void)
{
	//#15. find number of path. 20X20
//#15-1, this method is too heavy..
/*
#define MAX_WIDTH	10
	unsigned char path[MAX_WIDTH+1] = {0,};
	int checked = 0;
	unsigned long count = 0;

	while(1)
	{
		checked = add_path(path, MAX_WIDTH, checked);

		if(checked==(MAX_WIDTH/2))
		{
			count = count + 1;

			printf("---- found path : count is %ld\r", count);
		}
		else if(checked==MAX_WIDTH)
		{
			break;
		}
	}

	printf("result is %ld\n", count);
*/

//#15-2, The second method.. I found it finally.. TT
#define WIDTH	20
#define HEIGHT	20
#define LENGTH	WIDTH+HEIGHT
	int x, y;
	unsigned long count_matrix[WIDTH+1][HEIGHT+1] = {{0,},};

	for(x=0; x<=WIDTH; x++)
	{
		count_matrix[x][0] = 1;
		count_matrix[0][x] = 1;
	}


	for(x=1; x<=WIDTH; x++)
	{
		for(y=1; y<=HEIGHT; y++)
		{
			count_matrix[x][y] = count_matrix[x-1][y] + count_matrix[x][y-1];
		}
	}


	printf("number of path is %ld\n",count_matrix[WIDTH][HEIGHT]);
}

void euler_16(void)
{
//#16 2^10000 = n, sum of digit that consist of n
	unsigned char result[100000] = {0,};
	int i, sum = 0;

	result[0] = 2;

	for(i=1; i<1000; i++)
	{
		get_large_sum(result,result,result, 100000);
	}

	for(i=0; i<1000; i++)
	{
		sum = sum + result[i];
		printf("%d", result[i]);
	}

	cout << endl;
	cout << "result is " << sum << endl;
}

void euler_17(void)
{
	//#17 count letters

	//"one"3, "two"3, "three"5, "four"4, "five"4, "six"3, "seven"5, "eight"5, "nine"4, "ten"3,
	//"eleven"6, "twelve"6, "thirteen"8, "fourteen"8,"fifteen"7,"sixteen"7, "seventeen"9, "eighteen"8, "nineteen"8, "twenty"6,
	//"thirty"6, "forty"5, "fifty"5, "sixty"5,"seventy"7, "eighty"6, "ninety"6, "hundred"7, "thousand"8, "and"3
	int count_1_19[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	int count_10_90[10] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
	int count_100 = 7;
	int count_1000 = 8;
	int count_and = 3;

	int i, temp, temp1, temp2, temp3, temp4;
	unsigned int count = 0;


	for(i=1 ; i<=1000; i++)
	{
		temp = i/1000;
		temp2 = (i-temp*1000)/100;
		temp3 = (i-(temp*1000)-(temp2*100));

		if(temp != 0)
		{
			//1000자리수 계산
			count = count + count_1_19[temp]+ count_1000;
		}
		if(temp2 != 0)
		{
			//100자리수 계산
			count = count + count_1_19[temp2] + count_100;
		}
		if(temp3 != 0)
		{
			if(temp2 != 0)
			{
				//and count
				count = count + count_and;
			}
			if((temp3 < 20) && (temp3 != 10))
			{
				//1-19 , not 10
				count = count + count_1_19[temp3];
			}
			else if(temp3%10 == 0)
			{
				//10, 20, 30, 40, 50, 60, 70, 80, 90
				temp1 = temp3/10;
				count = count + count_10_90[temp1];
			}
			else
			{
				temp1 = temp3/10;
				temp4 = temp3%10;
				count = count + count_10_90[temp1] + count_1_19[temp4];
			}
		}
	}

	cout << count << endl;
}

void euler_18_67(void)
{
	//#18 & 67, find max sum path in pyramid
	int i, j=0, k=1;
	int data[MAX_ROW][MAX_ROW] = {{0,},};
	int max = 0;
	int sum = 0;

	FILE* fp;
	//fp = fopen("data_18.txt","r");
	fp = fopen("triangle.txt","r");

	if(fp==NULL)
	{
		cout << "data file not found!" << endl;
	}

	//initial data
	for(i=1 ; i<=MAX_ROW; i++)
	{
		for(k=1; k<=i ; k++)
		{
			j = fscanf(fp, "%d", &data[k][i]);
			if(j==-1)
			{
				break;
				j = i;
			}
		}
	}

	//find maximum sum route from bottom to top
	for(i=1; i<MAX_ROW; i++)
	{
		sum = get_max_route_b_to_t(data, i);
		if(sum > max)
		{
			max = sum;
		}
	}

	//find maximum sum route from top to bottom
	sum = get_max_route_t_to_b(data);
	if(sum > max)
	{
		max = sum;
	}

	cout << "max is : " << max << endl;

	//find maximum sum route form bottom to top 2nd

	sum = get_max_route_b_to_t_2(data);
	cout << "result is : " << data[1][1] << endl;

	fclose(fp);
}

void euler_19(void)
{
//#19, count the month start of Sunday in 20th century
	//week - 7
	//month : 1(31) 2(28) 3(31) 4(30) 5(31) 6(30) 7(31) 8(31) 9(30) 10(31) 11(30) 12(31)
	//2 : year%4 == 0 -> 29, year%400 == 0 -> 29
	unsigned long days = 0;
	int result = 0;
	int y, m;

	for(y=1901; y<=2000; y++)
	{
		for(m=1; m<=12; m++)
		{
			days = get_days(y, m, 1);
			if(days%7 == 0)
			{
				result = result + 1;
			}
		}
	}

	cout << result << endl;
}

void euler_20(void)
{
	//#20, sum of all digits consist result of 10!
	unsigned char result[100000] = {0,};
	unsigned char temp[100000] = {0,};
	int i, j, sum = 0;
	unsigned int k;

	temp[0] = 1;

	for(i=1; i<101; i++)
	{
		for(k=0 ; k<sizeof(result) ; k++)
		{
			result[k] = 0;
		}

		for(j=1; j<=i; j++)
		{
			get_large_sum(result,temp,result, 100000);
		}

		for(k=0 ; k<sizeof(result) ; k++)
		{
			temp[k] = result[k];
		}
	}

	for(i=1000; i>=0 ; i--)
	{
		printf("%d", result[i]);
		if(i%50==0)
		{
			cout << endl;
		}
		sum = sum + result[i];
	}

	cout << endl;

	cout << "sum is : " << sum << endl;
}

void euler_21(void)
{
//#21. get the sum of all the amicable numbers under 10000
	int i;
	int temp1, sum = 0;

	for(i=1; i<=10000 ; i++)
	{
		temp1 = get_sum_of_divisors(i);

		if((temp1 != i) && (get_sum_of_divisors(temp1) == i))
		{
			cout << i << ", ";
			sum = sum + i;
		}
	}

	cout << endl;
	cout << "sum is : " << sum << endl;
}

void euler_22(void)
{
//#22. get score of name
	// names[][20], names[0] = {marry}...
	#include "names.txt"
	int i, j;
	int size_name, each_score;
	unsigned long score = 0;

	size_name = sizeof(names)/sizeof(names[0]);

	qsort((void *)names, size_name, sizeof(names[0]), comparisonFunctionString);

	for(i=0; i<size_name; i++)
	{
//		cout << names[i] << endl;
		each_score = 0;
		for(j=0 ; j<20 ; j++)
		{
			if(names[i][j] != 0)
			{
				each_score = each_score + names[i][j] - 64;
			}
		}
//		cout << each_score << endl;
		score = score + (i+1)*each_score;
	}

	cout << "total score is: " << score << endl;
}

void euler_23(void)
{
//#23. sum of all the positive integers which cannot be written as the sum of two abundant numbers
	int i;
	int n;
	unsigned long sum = 0;

	for(n=1 ; n<28123 ; n++)
	{
		for(i=1; i<n; i++)
		{
			if(is_abundant(i)==1)
			{
				if(is_abundant(n - i) == 1)
				{
					i = 77777;
				}
			}
		}

		if(i==77778)
		{
			//cout << n << " is sum of two abundant.." << endl;
		}
		else
		{
			sum = sum + n;
			cout << n << " can not be sum of two abundant..." << endl;
		}
	}

	cout << endl << "sum is " << sum << endl;
}

void euler_24(void)
{
//#24. the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9
	int i, j;

	unsigned char digits[10] = {9,8,7,6,5,4,3,2,1,0};

	for(j=0 ; j<1000000 ; j++)
	{
		cout << j+1 << " : ";
		for(i=9; i>=0; i--)
		{
			printf("%d",digits[i]);
		}
		cout << endl;

		get_next_digits(digits);
	}
}

void euler_25(void)
{
//#25. Get the first term in the Fibonacci sequence to contain 1000 digit
	int i, n = 3;

	unsigned char F_num[10000] = {0,};
	unsigned char temp[10000] = {0,};
	unsigned char temp2[10000] = {0,};

	F_num[0] = 1;
	temp[0] = 1;

	while(1)
	{

		for(i=0; i<10000; i++)
		{
			temp2[i] = F_num[i];
		}

		get_large_sum(F_num, temp, F_num, 10000);

		cout << n << " : ";
		for(i=10; i>=0 ; i--)
		{
			printf("%d",F_num[i]);
		}
		cout << endl;

		if(F_num[999] != 0)
		{
			break;
		}

		for(i=0; i<10000; i++)
		{
			temp[i] = temp2[i];
		}

		n = n + 1;
	}

	for(i=1000; i>=0 ; i--)
	{
		printf("%d",F_num[i]);
	}
	cout << endl;

	cout << "result is "<< n << endl;
}

void euler_26(void)
{
//#26. Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part
	int i;
	int result;
	int max = 0;
	int max_num = 0;

	for(i=1; i<=1000; i++)
	{
		result = get_repeat_number(i);
		cout << i << " : " << result << endl;

		if(max < result)
		{
			max = result;
			max_num = i;
		}
	}

	cout << "Max recurring cycle is " << max << endl;
	cout << "The number is " << max_num << endl;
}

void euler_27(void)
{
//#27.  Find the product of coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n,
//      starting with n = 0.
//		n^2 + an + b , where |a| < 1000 and |b| < 1000
	int a, b;
	int result = 0;
	int max = 0;
	int max_product = 0;
	int max_a;
	int max_b;

	for(a=-1000 ; a<=1000 ; a++)
	{
		for(b=-1000 ; b<=1000 ; b++)
		{
			result = formula(a, b);
			if(max < result)
			{
				max = result;
				max_product = a * b;
				max_a = a;
				max_b = b;
			}
		}
	}

	cout << max << endl;
	cout << max_product << endl;
	cout << max_a << " , " << max_b << endl;
}

int euler_28(int size)
{
	int i = 1, j;
	int sum = 1;
	int	skip_count = 2;

	while( i < size*size )
	{
		for(j=0 ; j<4 ; j++)
		{
			i = i + skip_count;
			sum = sum + i;
		}
		skip_count = skip_count + 2;
	}

	return sum;
}

int euler_29(void)
{
	//second test
	//third test, commit to local new branch
	///jfakljafljafklj
	//forth..
	//fifth
	//sixth
	//seventh
	return 0;
}

int main() {

//	cout << euler_28(1001) << endl;

	cout << "end" << endl;
	return 0;
}

//for #27
int formula(int a, int b)
{
	int n = 0;

	while(1)
	{
		if(chek_primenumber(n*n + a*n + b) == 1)
		{
			n = n + 1;
		}
		else
		{
			break;
		}
	}
	return n;
}

//for #26
int get_repeat_number(int n)
{
	int i;
	int count = 0;
	int result = 1;
	int old_result[1000] = {0,};
	int positional_number;
	int match = 0;

	old_result[0] = 1;

	if(n>=1000)
	{
		positional_number = 4;
	}
	else if(n>=100 && n<=999)
	{
		positional_number = 3;
	}
	else if(n>=10 && n<=99)
	{
		positional_number = 2;
	}
	else if(n>=1 && n<=9)
	{
		positional_number = 1;
	}
	else
	{
		cout << "error!!" << endl;
	}

	while(1)
	{
		count = count + 1;
		result = (int)(result * pow(10,positional_number))%n;
		if(result == 0)
		{
			break;
		}
		else
		{
			positional_number = 1;
			for(i=0; i<count ; i++)
			{
				if(result == old_result[i])
				{
					match = 1;
					break;
				}
			}

			if(match == 1)
			{
				break;
			}

			old_result[count] = result;
			continue;
		}
	}

	if(match == 0)
	{
		return 0; //no repeat
	}
	else
	{
		return count-i;
	}
}

//for #24
void get_next_digits(unsigned char * current_num)
{
	int n;
	int i;
	unsigned char temp[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	for(n=0 ; n<9 ; n++)
	{
		if(current_num[n+1] > current_num[n])
		{
			continue;
		}
		else
		{
			for(i=0 ; i<=n+1 ; i++)
			{
				temp[i] = current_num[i];
			}
			qsort((void *)temp, 10, sizeof(temp[0]), comparisonFunctionInt);

			for(i=0 ; i<10 ; i++)
			{
				if(current_num[n+1] == temp[i])
				{
					current_num[n+1] = temp[i+1];
					temp[i+1] = -1;
					break;
				}
			}

			qsort((void *)temp, 10, sizeof(temp[0]), comparisonFunctionInt);

			for(i=n ; i>=0 ; i--)
			{
				current_num[i] = temp[n-i];
			}

			break;

		}
	}
}

//for #23
int comparisonFunctionInt(const void *a, const void *b) {

  if (*(unsigned char*)a <  *(unsigned char*)b) return -1;
  if (*(unsigned char*)a == *(unsigned char*)b) return  0;

  return 1;
}

int is_abundant(int n)
{
	int sum, i;
	sum = 0;

	for(i=1 ; i<(n * 0.5+1) ; i++)
	{
		if(n%i == 0)
		{
			sum = sum + i;
		}
	}


	if(sum > n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//for #22 string comparison rule
int comparisonFunctionString(const void *a, const void *b) {
  return( strcmp( (char *)a, (char *)b) );
}

//for #21 get sum of divisors
int get_sum_of_divisors(int n)
{
	int i;
	int sum = 0;

	for(i=1 ; i<(n/2+1) ; i++)
	{
		if(n%i == 0)
		{
			sum = sum + i;
		}
	}

	return sum;
}

//for #19
unsigned long get_days(int year, int month, int day)
{
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	unsigned long days = 0;
	int i;

	days = days + (year - 1900) * 365;

	//add 1 day, leap-year
	for(i=1900 ; i<year; i=i+4)
	{
		days = days + 1;

		if(i%100 == 0)
		{
			days = days - 1;
			if(i%400 == 0)
			{
				days = days + 1;
			}
		}
	}

	//add months
	for(i=1; i<month; i++)
	{
		days = days + months[i];
	}

	if(month > 2)
	{
		if(year%4 == 0)
		{
			days = days + 1;

			if(year%100 == 0)
			{
				days = days -1;

				if(year%400 == 0)
				{
					days = days +1;
				}
			}
		}
	}

	//add day
	days = days + day;

	return days;
}

//for 18 & 67
int get_max_route_b_to_t_2(int data[][MAX_ROW])
{
	int j, k;
	int sum = 0;

	for(j=MAX_ROW-2 ; j>0 ; j--)
	{
		for(k=1 ; k<=j ; k++)
		{
			if(data[k][j+1] > data[k+1][j+1])
			{
				data[k][j] = data[k][j] + data[k][j+1];
			}
			else
			{
				data[k][j] = data[k][j] + data[k+1][j+1];
			}
		}
	}

	return sum;
}


int get_max_route_t_to_b(int data[][MAX_ROW])
{
	int j, x=1;
	int sum = 0;

	sum = sum + data[1][1];
	cout << data[1][1] << " ";

	for(j=2 ; j<MAX_ROW ; j++)
	{
		if(data[x][j] > data[x+1][j])
		{
			sum = sum + data[x][j];
			cout << data[x][j] << " ";
		}
		else
		{
			sum = sum + data[x+1][j];
			cout << data[x+1][j] << " ";
			x = x + 1;
		}
	}

	cout << " : " << sum << endl;
	return sum;
}

int get_max_route_b_to_t(int data[][MAX_ROW], int i)
{
	int j;
	int sum = 0;

	sum = sum + data[i][MAX_ROW-1];
	cout << data[i][MAX_ROW-1] << " ";

	for(j=MAX_ROW-2; j>0; j--)
	{
		if(i == 1)
		{
			sum = sum + data[i][j];
			cout << data[i][j] << " ";
		}
		else if(i == j+1)
		{
			sum = sum + data[i-1][j];
			cout << data[i-1][j] << " ";
			i = i-1;
		}
		else
		{
			if(data[i][j] > data[i-1][j])
			{
				sum = sum + data[i][j];
				cout << data[i][j] << " ";
			}
			else
			{
				sum = sum + data[i-1][j];
				cout << data[i-1][j] << " ";
				i = i-1;
			}
		}
	}

	cout << " : " << sum << endl;

	return sum;
}

//for 16
void get_large_sum(unsigned char* num_1, unsigned char* num_2, unsigned char* result, int size)
{
	int i;
	unsigned char temp_result[100000] = {0,};
	unsigned char carry = 0, temp;

	for(i=0 ; i<size; i++)
	{
		temp = num_1[i] + num_2[i] + carry;
		temp_result[i] = temp % 10;
		carry = temp / 10;
	}

	for(i=0 ; i< size; i++)
	{
		result[i] = temp_result[i];
	}

}

//for #15
int add_path(unsigned char *path, int length, int current_count)
{
	int i;
	int one_count = 0;

	one_count = current_count;

	if(path[1] == 0)
	{
		path[1] = 1;
		one_count = one_count + 1;
	}
	else if(path[1] == 1)
	{
		for(i=1 ; i<=length ; i++)
		{
			if(path[i] == 0)
			{
				path[i] = 1;
				one_count = one_count + 1;
				break;
			}
			else if(path[i] == 1)
			{
				path[i] = 0;
				one_count = one_count - 1;
			}
		}
	}

	return one_count;
}

//for #14
unsigned long problem_14(unsigned long x)
{
	if(x == 1)
	{
		return 1;
	}
	if(x%2 == 0)
	{
		x = x/2;
	}
	else
	{
		x = x*3+1;
	}

//	printf("%ld, ",x);
	return x;
}

// for #13
int get_column_sum(int x, int size)
{
	int sum=0;
	int i;

	for(i=1; i<=100; i++)
	{
		sum = sum + data_13[GET_I(size-x+1,i)];
	}

	printf("%d, th sum is %d\n", x, sum);

	return sum;
}

//count number of divider
int count_number_of_divider(int t)
{
	int count = 0;
	int i, last_divider = 1;

	for(i=2 ; i<t ; i++)
	{
		if(t%i == 0)
		{
			if(i*last_divider == t)
			{
				break;
			}
			else if(i*i == t)
			{
				count = count + 1;
				break;
			}
			else
			{
				count = count + 2;
			}
			last_divider = i;
		}
	}

	printf("%d has %d dividers.. ", t, count+1);
	return count+1;
}

//get i'th triangle number
int get_triangle(int i)
{
	int sum = 0;

	sum = (0.5)*((1+i)*i);

	return sum;
}

//get max product in whole directions for #11
int get_max_product(int x,int y,int u)
{
	double max=0;
	int i, j;
	double product=1;

	//check horizental
	for(i=0; i<u; i++)
	{
		for(j=0; j<u; j++)
		{
			product = product * data_11[GET_I(x+j, y+i)];
			printf("%d\n", data_11[GET_I(x+j, y+i)]);
		}
		if(max < product)
			max = product;

		printf("%f.0\n",product);
		product=1;
	}
	//check vertical
	for(i=0; i<u; i++)
	{
		for(j=0; j<u; j++)
		{
			product = product * data_11[GET_I(x+i, y+j)];
			printf("%d\n",data_11[GET_I(x+i, y+j)]);
			if(max < product)
				max = product;
		}
		if(max < product)
			max = product;

		printf("%f.0\n",product);
		product=1;
	}
	//check diagonal 1
	for(i=0; i<u ; i++)
	{
		product = product * data_11[GET_I(x+i, y+i)];
		printf("%d\n",data_11[GET_I(x+i, y+i)]);
	}
	if(max < product)
		max = product;

	printf("%f.0\n",product);
	product=1;
	//check diagonal 2
	for(i=0; i<u ; i++)
	{
		product = product * data_11[GET_I(x+u-i-1, y+i)];
		printf("%d\n",data_11[GET_I(x+u-i-1, y+i)]);
	}
	if(max < product)
		max = product;

	printf("%f.0\n",product);
	product=1;

	return max;
}

//prime number check function for #3
bool chek_primenumber(int x)
{
	int i;

	if(x<2)
		return 0;

	if((x%2 == 0) && (x!=2))
		return 0;

	for(i=3; i<(x^(1/2)) ; i=i+2)
	{
		if(x%i == 0)
			return 0;
	}
	//printf("%d is prime number.\n",x);
	return 1;
}

bool check_pal(int x)
{
	if(x<100000)
	{
		if((x/10000) == (x%10))
		{
			x = (x - (x/10000)*10000)/10;
			if((x/1000) == (x%10))
			{
				return 1;
			}
		}
	}
	else
	{
		if((x/100000) == (x%10))
		{
			x = (x - (x/100000)*100000)/10;
			if((x/1000) == (x%10))
			{
				x = (x - (x/1000)*1000)/10;
				if((x/10) == (x%10))
				{
					return 1;
				}
			}
		}
	}

	return 0;

}
