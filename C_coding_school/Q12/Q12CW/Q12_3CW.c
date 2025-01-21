#include <stdio.h>

#define user_name_str_size 31 //30 + \0
#define email_name_str_size 31 //30 + \0
#define password_size 9 //8 + \0

typedef struct User_Private {
    char name[user_name_str_size];
    int age;
    char email[email_name_str_size];
    char password[password_size];
}User;
User get_user();
void print_user(User user);
int main()
{
    User user = get_user();
    print_user(user);
    return 0;
}

User get_user()
{
    User user;
    printf("please enter username: ");
    scanf("%s", &*user.name);
    printf("please enter age: ");
    scanf("%d", &user.age);
    printf("please enter email: ");
    scanf("%s", &*user.email);
    printf("please enter password: ");
    scanf("%s", &*user.password);
    return user;
}

void print_user(User user)
{
    printf("Name: %s\nAge: %d\nEmail: %s\nPassword: %s\n", user.name, user.age, user.email, user.password);
}
