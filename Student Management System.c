#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//================ STRUCT =================
typedef struct Student
{
    int id;
    char name[50];
    float marks;
} Student;

//================ ARRAY =================
Student students[MAX];
int count = 0;

//================ STACK =================
Student stackArr[MAX];
int top = -1;

//================ LINKED LIST =================
typedef struct Node
{
    Student data;
    struct Node *next;
} Node;

Node *head = NULL;

//================ LINE =================
void line()
{
    printf("--------------------------------------\n");
}

//================ STACK PUSH =================
void push(Student s)
{
    if (top < MAX - 1)
    {
        top++;
        stackArr[top] = s;
    }
}

//================ STACK POP =================
Student pop()
{
    return stackArr[top--];
}

//================ LINKED LIST ADD =================
void addRecent(Student s)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = s;
    newNode->next = head;
    head = newNode;
}

//================ ADD STUDENT =================
void addStudent()
{
    Student s;

    if (count == MAX)
    {
        printf("Database Full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count] = s;
    count++;

    addRecent(s);

    printf("Student Added Successfully!\n");
}

//================ DISPLAY =================
void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("No Student Found!\n");
        return;
    }

    line();
    printf("All Students\n");
    line();

    for (i = 0; i < count; i++)
    {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        line();
    }
}

//================ SEARCH =================
void searchStudent()
{
    int id, i, found = 0;

    printf("Enter ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Student Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Student Not Found!\n");
    }
}

//================ UPDATE =================
void updateStudent()
{
    int id, i;

    printf("Enter ID to Update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("Updated Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

//================ DELETE =================
void deleteStudent()
{
    int id, i, j;

    printf("Enter ID to Delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            push(students[i]);

            for (j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            printf("Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

//================ UNDO DELETE =================
void undoDelete()
{
    if (top == -1)
    {
        printf("Nothing to Undo!\n");
        return;
    }

    students[count] = pop();
    count++;

    printf("Undo Successful!\n");
}

//================ RECENT STUDENTS =================
void recentStudents()
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("No Recent Students!\n");
        return;
    }

    line();
    printf("Recently Added Students\n");
    line();

    while (temp != NULL)
    {
        printf("ID: %d\n", temp->data.id);
        printf("Name: %s\n", temp->data.name);
        printf("Marks: %.2f\n", temp->data.marks);
        line();

        temp = temp->next;
    }
}

//================ MAIN =================
int main()
{
    int choice;

    while (1)
    {
        line();
        printf(" STUDENT MANAGEMENT SYSTEM\n");
        line();

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Undo Delete\n");
        printf("7. Recent Students\n");
        printf("8. Exit\n");

        line();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            undoDelete();
            break;

        case 7:
            recentStudents();
            break;

        case 8:
            printf("Program Ended.\n");
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
