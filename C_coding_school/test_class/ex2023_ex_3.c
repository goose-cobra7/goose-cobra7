#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//create struct
typedef struct parent
{
    char p_name[20];
    char phone[11];
}par;


typedef struct child
{
    char name[20];
    int id;
    char* allergytype;
    par parent;
}child;


int main(int argc, char const *argv[])
{
    char** allergy = (char**)malloc(4*sizeof(char*)); //create mamory array of pointer
    for (size_t i = 0; i < 4; i++)
    {
        allergy[i] = (char*)malloc(20*sizeof(char));//create the memory for the strings
    }
    child* new_child = init_child("eran",123,NULL,"aliza","05411111111");
    return 0;
}

child* init_child(char cname[20], int cid, char** allerg,char pname[20],char phone[11])
{
    child* new_child = (child*)malloc(sizeof(child)); //create new place in mamory
    strcpy(new_child->name,cname); //put name in it
    new_child->id = cid;
    new_child->allergytype = allerg;
    strcpy(new_child->parent.p_name,pname);
    strcpy(new_child->parent.phone,phone);
    return new_child;//return pointer
}