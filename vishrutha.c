#include<stdio.h>
#include<conio.h>
void main()
{
    typedef struct{
      char name[20];
      int marks[5];
    } Student;
     Student students[100];
    FILE *fp;
    int i, j, count = 0;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (count < 100 && fscanf(fp, "%s", students[count].name) == 1) {
        for (j = 0; j <6; j++) {
            if (fscanf(fp, "%d", &students[count].marks[j]) != 1) {
                printf("File format error!\n");
                fclose(fp);
                return 1;
            }
        }
        count++;
    }

    fclose(fp);

    for (i = 0; i < count; i++) {
        printf("Student %d: %s\n", i + 1, students[i].name);
        printf("Marks: ");
        for (j = 0; j <6; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
