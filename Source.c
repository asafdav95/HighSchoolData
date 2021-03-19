#define _CRT_SECURE_NO_WARNINGS
#include "School_Header.h"




int main()
{
	grade grades[6];
	Pgrade g = &grades;
	int flag = 1, temp_grade, i, j, temp_class;
	char ans;
	initial_school(g);
	while (flag)
	{
		printf("\nHello! please select an option:\n");
		printf("1) Add a new pupil\n2) Delete pupil's data\n3)See pupil's detail\n");
		printf("Answer: ");
		scanf(" %c", &ans);
		switch (ans)
		{
		case '1':											//Add a new pupil
			printf("Please enter pupil's grade(7-12): ");
			scanf("%d", &temp_grade);
			if (temp_grade > 12 || temp_grade < 7)			//Check if grade is valid
			{
				printf("\nPlease try again but this time enter a valid grade number between 7 to 12 :)\n\n");
				break;
			}
			printf("Please select a class between 1 - 8: ");
			scanf("%d", &temp_class);
			if (temp_class > 8 || temp_class < 1)			//Check if class number is valid
			{
				printf("\nPlease try again but this time enter a valid class number between 1 to 8: )\n\n");
				break;
			}
			if (g->classes[temp_class - 1].num_of_pupils == MAX)
			{
				printf("Sorry this class is full\n");
				printf("We will sign the pupil to class number %d.\n", temp_class = is_full(g));
			}
			if ((i = add_new_pupil(g + temp_grade - 7, temp_grade, temp_class)) == 0)
				printf("Sorry, our school is full\n");
			if (i == -1)
				flag = 0;
			break;
		case '2':
			if (!is_full(g))
				break;
			del_pupil(g);
				break;
		case '3':
			printf("Please enter pupil's grade(7-12): ");
			scanf("%d", &temp_grade);
			show_pupil_info(grades[temp_grade -7]);
			break;
		default:
			flag = 0;
		}


	}
	
	printf("Goodbye!!");
	free_mem(g);

	return 0;
}