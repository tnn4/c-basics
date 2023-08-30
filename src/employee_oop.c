// Example of how to do OOP classes in pure C
// C lacks automatic memory management e.g. garbage collection
// So you are responsible for allocating enough memory so data will fit
// and freeing memory to prevent memory leaks
// OOP languages do a lot of work for you but that comes at a loss of control and cpu cycles

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// custom error codes
#define NO_ERROR             0
#define NO_OBJECT_ERROR      1
#define INVALID_EMP_NO_ERROR 2

typedef struct{           // class Employee { <-- Java equivalent
    int  id; //    private int    employee_number;
    char *name;           //    private String name;
    char *department;     //    private String department;
} Employee_struct;        // }

// Define a pointer type for this structure

typedef Employee_struct *Employee_ptr;

// Equivalent to the new keyword in OOP
Employee_ptr Employee_new() {
    Employee_ptr em = (Employee_ptr) malloc (sizeof(Employee_struct));
    return em;
}

int Employee_delete(Employee_ptr em) {
    free(em);
    return NO_ERROR;
}

// These are getter/setter methods


int Employee_setId(Employee_ptr em, int n) {
    if (em == NULL) return NO_OBJECT_ERROR;
    else if (n < 1) return INVALID_EMP_NO_ERROR;
    else {
        em -> id = n;
        return NO_ERROR;
    } 
}

// You _can_ access the data w/ em->id BUT
// This enforces error checking
int Employee_getId(Employee_ptr em) {
    if (em == NULL) return NO_OBJECT_ERROR;
    else return em->id;
}

int Employee_setName(Employee_ptr em, char *name) {
    if (em==NULL) return NO_OBJECT_ERROR;
    else {
        em->name=name;
        return NO_ERROR;
    }
}

// see: https://stackoverflow.com/questions/63474154/how-do-i-return-an-error-code-in-c-when-the-return-type-of-the-function-doesnt
// pass a pointer of the struct to be returned
int Employee_getName(Employee_ptr em){
    if (em == NULL) return NO_OBJECT_ERROR;
    else if (em->name == NULL) {
        return NO_OBJECT_ERROR;
    }
    else {
        return NO_ERROR;
    }
}

int Employee_setDepartment(Employee_ptr em, char *dpt) {
    if (em==NULL) return NO_OBJECT_ERROR;
    else {
        em->department=dpt;
        return 0;
    }
}

int Employee_greet(Employee_ptr em) {
    if (em == NULL) return NO_OBJECT_ERROR;
    else {
        printf("Hi, I'm %s from %s.\n", em->name, em->department);
        return NO_ERROR;
    }
}

int main(){
    Employee_ptr em1 = Employee_new();
    Employee_setName(em1, "Bob");
    Employee_setDepartment(em1, "accounting");
    printf("Employee Name: %s\n", em1->name);
    Employee_greet(em1);
    Employee_delete(em1);
}