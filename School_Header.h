#ifndef _School_Header
#define _School_Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct pupil
{
	char* name;
	float avg;
	int id;
	int grades[5];
	char* courses[5];
	struct pupil* next;
	struct pupil* prev;
}pupil, * Ppupil;

typedef struct class
{
	int num_of_pupils;
	Ppupil head_class;
	Ppupil tail_class;
}class, * Pclass;

typedef struct grade
{
	class classes[8];
	int grade_num_pupils;
}grade, * Pgrade;



int add_new_pupil(Pgrade, int, int);
int del_pupil(Pgrade);
void free_mem(Pgrade);
Pgrade initial_school(Pgrade);
int is_full(Pgrade);
void show_pupil_info(grade g);

#endif