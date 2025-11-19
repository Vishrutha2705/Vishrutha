#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee *employees;
    int num_employee;

    printf("Enter the number of employees: ");
    scanf("%d", &num_employee);

    employees = (struct Employee*)malloc(num_employee * sizeof(struct Employee));

    printf("\nSize of structure Employee: %d bytes\n", (int)sizeof(struct Employee));

    for(int i = 0; i < num_employee; i++) {
        printf("\nEnter the details of employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &employees[i].id);

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Salary (monthly): ");
        scanf("%f", &employees[i].salary);
    }

    printf("\nEmployee Details\n");

    for(int i = 0; i < num_employee; i++) {
        printf("\nEmployee %d base address: %p\n", i + 1, (void*)(employees + i));
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    float annual_expenditure = 0;
    for (int i = 0; i < num_employee; i++) {
        annual_expenditure += employees[i].salary * 12;
    }

    printf("\nTotal Annual Salary Expenditure: %.2f\n", annual_expenditure);

    free(employees);
    return 0;
}
