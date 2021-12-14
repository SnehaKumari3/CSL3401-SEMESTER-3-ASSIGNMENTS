#include <stdio.h>

void MinMax(char str[100])
{
    int cons = 0, ch = 0, vowel = 0, word = 0, space = 0, i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
         str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || 
         str[i] == 'u' || str[i] == 'U')
        {
            vowel++;
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            cons++;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            cons++;
        }
        else if (str[i] == ' ')
        {
            space++;
        }
    }
    word = space + 1;
    ch = i - space;
    printf("vowels= %d ,consonants= %d ,characters= %d ,words= %d and space= %d", vowel,
           cons, ch, word, space);
}

int main()
{
    char str[100];
    printf("Enter a string:\n");
    scanf("%[^\n]s", str);
    MinMax(str);
    return 0;
}