#include <stdio.h>
#include <string.h>

void shortName(char name[])
{
    int i, lastSpace = -1;

    // Remove newline added by fgets
    name[strcspn(name, "\n")] = '\0';

    // Find last space
    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
            lastSpace = i;
    }

    // If no space → only one word
    if (lastSpace == -1)
    {
        printf("%s", name);
        return;
    }

    // Print initials
    printf("%c.", name[0]);

    for (i = 1; i < lastSpace; i++)
    {
        if (name[i] == ' ' && name[i + 1] != ' ')
            printf("%c.", name[i + 1]);
    }

    // Print last word
    printf(" %s", &name[lastSpace + 1]);
}

int main()
{
    char name[100];

    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);

    shortName(name);

    return 0;
}