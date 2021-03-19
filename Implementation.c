#include "School_Header.h"

//This function adds a new pupil's info to the system
int add_new_pupil(Pgrade g, int temp_grade, int class_number)
{
	Pgrade temp_g = g;
	Ppupil new;
	char temp_name[20];
	char* name, *course_name;
	int i;
	float avg = 0;
	if (!is_full(temp_g))										//Check if the school is full
	{
		printf("Sorry our school is at it's full capacity\n");
		return 0;
	}

	printf("Please enter pupil's name: ");
	scanf("%s", temp_name);
	name = (char*)malloc(strlen(temp_name) + 1);
	if (!name)
	{
		printf("New name allocation error (func add_new_pupil)\n");
		return -1;
	}
	name = strcpy(name ,temp_name);

	if ((temp_g + temp_grade- 7)->classes[class_number - 1].head_class == NULL)				//Creating a new class
	{
		new = (Ppupil)malloc(sizeof(pupil));
		if (!new)
		{
			printf("New pupil memory allocation error\n");
			return -1;
		}
		printf("Please enter course's name and it's grade of %s (5 courses):\n", temp_name);
		for (i = 0; i < 5; i++)
		{
			printf("Course number %d and grade: ", i + 1);
			scanf("%s %d", temp_name, &(new->grades[i]));
			avg += new->grades[i];
			course_name = (char*)malloc(strlen(temp_name) + 1);
			if (!course_name)
			{
				printf("New course name allocation error (func add_new_pupil)\n");
				return -1;
			}
			course_name = strcpy(course_name ,temp_name);
			new->courses[i] = course_name;
		}
		printf("Please enter pupil's id: ");
		scanf("%d", &(new->id));
		new->name = name;
		new->avg = avg / 5;
		new->next = NULL;
		new->prev = NULL;
		temp_g->classes[class_number - 1].head_class = new;
		temp_g->classes[class_number - 1].tail_class = new;
		temp_g->classes[class_number - 1].num_of_pupils++;
		return class_number;

	}
	else																//Adding pupil to a class
	{
		while ((temp_g + temp_grade - 7)->classes[class_number - 1].head_class->next != NULL)
		{
			(temp_g + temp_grade - 7)->classes[class_number - 1].head_class = (g + temp_grade - 7)->classes[class_number - 1].head_class->next;
		}
		new = (Ppupil)malloc(sizeof(pupil));
		if (!new)
		{
			printf("New pupil memory allocation error\n");
			return -1;
		}
		printf("Please enter course's name and it's grade of %s (5 courses):\n", temp_name);
		for (i = 0; i < 5; i++)
		{
			printf("Course number %d and grade: ", i + 1);
			scanf("%s %d", temp_name, &(new->grades[i]));
			avg += new->grades[i];
			course_name = (char*)malloc(strlen(temp_name) + 1);
			if (!course_name)
			{
				printf("New course name allocation error (func add_new_pupil)\n");
				return -1;
			}
			course_name = strcpy(course_name, temp_name);
			new->courses[i] = course_name;
		}
		printf("Please enter pupil's id: ");
		scanf("%d", &(new->id));
		new->name = name;
		new->avg = avg / 5;
		new->prev = (temp_g + temp_grade- 7)->classes[class_number - 1].head_class;
		(temp_g + temp_grade - 7)->classes[class_number - 1].head_class->next = new;
		new->next = NULL;
		g->classes[class_number - 1].tail_class = new;
		g->classes[class_number - 1].num_of_pupils++;
		return class_number;
	}

}



//This function deletes pupil's info from the system
int del_pupil(Pgrade g)
{
	Pgrade temp_g = g;
	Ppupil p_del;
	char name[50];
	int class_num, grade_num, d;
	printf("Please enter the name of the puppil tou wish to delete: ");
	scanf("%s", name);
	printf("Now enter the pupil's grade and then his/hers class number: ");
	scanf("%d %d", &grade_num, &class_num);
	if ((temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils == 0) 
	{
		printf("This class is empty\n");
		return 1;
	}
	if ((temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils == 1)		//in case there is only one pupil
	{
		free((temp_g + grade_num - 7)->classes[class_num - 1].head_class->name);
		free((temp_g + grade_num - 7)->classes[class_num - 1].head_class);
		(temp_g + grade_num - 7)->classes[class_num - 1].head_class = NULL;
		(temp_g + grade_num - 7)->classes[class_num - 1].tail_class = NULL;
		(temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils = 0;
		return 1;
	}
	if (!strcmp((temp_g + grade_num - 7)->classes[class_num - 1].head_class->name, name))		//in case the pupil is the first pupil
	{
		p_del = (temp_g + grade_num - 7)->classes[class_num - 1].head_class;
		(temp_g + grade_num - 7)->classes[class_num - 1].head_class = p_del->next;
		free(p_del->name);
		free(p_del);
		(temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils--;
		return 1;
	}
	if (!strcmp((temp_g + grade_num - 7)->classes[class_num - 1].tail_class->name, name))		//in case the pupil is at the tail
	{
		p_del = (temp_g + grade_num - 7)->classes[class_num - 1].tail_class;
		p_del->prev->next = NULL;
		(temp_g + grade_num - 7)->classes[class_num - 1].tail_class = p_del->prev;
		free(p_del);
		(temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils--;
		return 1;
	}
	while (!strcmp((temp_g + grade_num - 7)->classes[class_num - 1].head_class->name, name))		//in case the pupil is in the middle
	{
		if ((temp_g + grade_num - 7)->classes[class_num - 1].head_class->next->next == NULL)
		{
			printf("This pupil isn't in our school.\n");
			return 0;
		}
		(temp_g + grade_num - 7)->classes[class_num - 1].head_class = (temp_g + grade_num - 7)->classes[class_num - 1].head_class->next;
	}
	
		p_del = (temp_g + grade_num - 7)->classes[class_num - 1].head_class;
		p_del->prev->next = p_del->next;
		p_del->next->prev = p_del->prev;
		free(p_del->name);
		free(p_del);
		(temp_g + grade_num - 7)->classes[class_num - 1].num_of_pupils--;
		return 1;

}



//This function initializes the school from zero
Pgrade initial_school(Pgrade g)
{
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 8; j++)
		{
			(g + i)->classes[j].head_class = NULL;
			(g + i)->classes[j].tail_class = NULL;
			(g + i)->classes[j].num_of_pupils = 0;
		}
		(g + i)->grade_num_pupils = 0;
	}
}




//This function frees all the malloc memory
void free_mem(Pgrade g)
{
	int i, j;
	Ppupil temp_p;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 8; j++)
		{
			while (g[i].classes[j].head_class!= NULL)
			{
				temp_p = g[i].classes[j].head_class;
				(g + i)->classes[j].head_class = g[i].classes[j].head_class->next;
				temp_p->next = NULL;
				temp_p->prev = NULL;
				free(temp_p->name);
				for (i = 0; i < 5; i++)
					free(temp_p->courses[i]);
				free(temp_p);
			}
			g->classes[i].head_class = NULL;
			g->classes[i].tail_class = NULL;
			g->classes[i].num_of_pupils = 0;
		}
	}
	g = NULL;

}





//This function tells weather the grade is full or returns the number of class that has a free spot
int is_full(Pgrade g)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (g->classes[i].num_of_pupils < MAX)
			return i + 1;
	}
	return 0;
}



//This function shows a certein pupil's info
void show_pupil_info(grade g) 
{
	int temp_class;
	char name[50];
	printf("Please select a class between 1 - 8: ");
	scanf("%d", &temp_class);
	if (temp_class > 8 || temp_class < 1)			//Check if class number is valid
	{
		printf("\nPlease try again but this time enter a valid class number between 1 to 8: )\n\n");
		return;
	}
	printf("Please enter the name of the puppil you wish to show his/gers info: ");
	scanf("%s", name);
	if (g.classes[temp_class - 1].num_of_pupils == 0)											//If the class is empy
	{
		printf("Sorry, no such pupil in this class\nTry again :)\n");
		return;
	}
	if (g.classes[temp_class- 1].num_of_pupils == 1 && strcmp(g.classes[temp_class - 1].head_class->name, name) == 0)		//If the class has 1 pupil
	{
		printf("Pupil's name: %s\n", name);
		printf("Pupil's id: %d\n", g.classes[temp_class - 1].head_class->id);
		printf("Pupil's avg: %.2lf\n", g.classes[temp_class - 1].head_class->avg);
		return;
	}
	while (g.classes[temp_class - 1].head_class != NULL)
	{
		if (!strcmp(g.classes[temp_class - 1].head_class->name, name))			//This is the pupil
		{
			printf("Pupil's name: %s\n", name);
			printf("Pupil's id: %d\n", g.classes[temp_class - 1].head_class->id);
			printf("Pupil's avg: %.2lf\n", g.classes[temp_class - 1].head_class->avg);
			return;
		}
		g.classes[temp_class - 1].head_class = g.classes[temp_class - 1].head_class->next;
	}
	
	printf("Sorry, no such pupil in this class\nTry again :)\n");
	return;
}

