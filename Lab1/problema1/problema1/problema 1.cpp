#include <cstdio>

int convertire(char s[])
{
    int nr = 0, i;
    for (i = 0; s[i]; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            s[i] += nr * 10 + s[i] - '0';
        else
            return 0;
    }
    return nr;
}

int main()
{
    FILE* fp;
    fp = fopen("ini.txt", "r");
    char nr[256];
    int s = 0;
    if (fp)
    {
        while (fscanf(fp, "%s", nr) != EOF)
        {
            s += convertire(nr);
        }
    }
    else
        printf("nu merge");
    printf("suma e: %i", s);
    return 0;
}