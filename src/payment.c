#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define NAME_LENGTH 32

typedef struct
{
    char name[NAME_LENGTH];
    float spent; // the amount of money they spent
} Person;

bool read_size(size_t *s);
bool read_float(float *f);
void read_string(char *s, size_t n);

int main()
{

    printf("How many people: ");
    size_t count = 0;
    while (read_size(&count) != true)
        printf("Invalid response. How many people: ");
    printf("%lu people\n", count);

    printf("What is the conversion rate: ");
    float conversion;
    while (read_float(&conversion) != true)
        printf("Invalid conversion. Conversion :");

    printf("\rNow enter each persons information\n");
    Person people[count];
    for (size_t i = 0; i < count; i++)
    {
        printf("Person %lu\n", i);
        printf("\tName: ");
        read_string(people[i].name, NAME_LENGTH);
        printf("\tAmount Spent: ");
        while (read_float(&people[i].spent) != true)
            printf("Invalid amount. Please try again.\n\t Amount Spent: ");
        printf("Person %lu Complete.\n", i);
    }

    for (size_t i = 0; i < count; i++)
    {
        for (size_t n = 0; n < count; n++)
        {
            float owed = people[i].spent / count - people[n].spent / count;
            if (owed > 0.001)
                printf(
                    "%s owes %s $%.2f\n",
                    people[n].name,
                    people[i].name,
                    owed * conversion);
        }
    }

    return 0;
}

bool read_size(size_t *s)
{
    char buf[64];
    fgets(buf, sizeof(buf), stdin);
    for (char *c = buf; *c != '\0'; c++)
    {
        if (!(isspace(*c) || isdigit(*c)))
            return false;
    }
    *s = atol(buf);
    return true;
}

bool read_float(float *f)
{

    char buf[64];
    fgets(buf, sizeof(buf), stdin);
    for (char *c = buf; *c != '\n'; c++)
    {
        if (!(isspace(*c) || isdigit(*c) || *c == '.'))
            return false;
    }
    *f = atof(buf);
    return true;
}
void read_string(char *s, size_t n)
{
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    for (size_t i = 0; (n == 0 || i < n) && buf[i] != '\0'; i++)
    {
        s[i] = buf[i];
        if (buf[i] == '\n')
            s[i] = '\0';
    }
}
