#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct // type def gives the name
{              // struct combines both of them
    string name; // inside gives the attributes to it
    string number;
}
person; // the result is how you want it to be called in main

int main(void)
{
    person people[3]; // use the new word as a data type

    people[0].name = "Carter"; // use . to acces each type of data inside
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if(strcmp(people[i].name, name) == 0) // when comparing do it too
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

