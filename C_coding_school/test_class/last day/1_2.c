#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct par
{
    char p_name[20];
    char phone[11];
}par;

typedef struct child
{
    char name[20];
    unsigned id;
    char **allergytype;
    par parent;
}child;
child *init_child(char cname[20], unsigned id, char **allerytype,char p_name[20],char phone[11]);
int emergency(child **nChild,char *allarg);
void print_child(child *c);


int main() {
    child* children[MAX_CHILDREN];
    char allerg1[] = "Peanuts";
    char allerg2[] = "Milk";
    char allerg3[] = "Peanuts";
    char *allerg_list[] = {allerg1,allerg2,allerg3};
    children[0] = init_child("Alice", 12345, allerg_list, "Bob", "1234567890");

    children[1] = init_child("Charlie", 23456, allerg_list, "David", "0987654321");

    children[2] = init_child("Eve", 34567, allerg_list, "Frank", "1122334455");

    printf("Number of children with Peanuts allergy: %d\n", emergency(children, "Peanuts"));

    return 0;
}

child *init_child(char cname[20], unsigned id, char **allerytype,char p_name[20],char phone[11])
{
    child *new_child = (child*)malloc(sizeof(child));
    strcpy(new_child->name,cname);
    new_child->id = id;
    new_child->allergytype = allerytype;
    strcpy(new_child->parent.p_name,p_name);
    strcpy(new_child->parent.phone,phone);
    return new_child;
}

int emergency(child **nChild,char *allarg)
{
    int i = 0,sum_c = 0;;
    while (nChild[i])
    {
        int j = 0;
        while (nChild[i]->allergytype[j])
        {
            if (strcmp(nChild[i]->allergytype[j],allarg))
            {
                print_child(nChild[i]);
                sum_c++;
                break;
            }
            j++;
        }
        i++;
    }
}

void print_child(child *c)
{
    int i = 0;
    while (c->name[i]!='$')//find the un uncrypt name
    {
        i++;
    }
    i++;
    i = 0; //not crypt for test
    printf("child name: %s\n",c->name+i);
    printf("child id: %d\n",c->id);
    printf("child parent name: %s\n",c->parent.p_name);
    printf("child parent phone num: %s\n",c->parent.phone);
}

