#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strpbrk(const char *s, const char *accept);

int main(void)
{
    char *test[11];

    char *test_s1 = "abcd45";
    char *test_s2 = "c";

    test[0] = test_s1;
    test[1] = test_s2;

    char *test_s3 = "6g fh";
    char *test_s4 = " ";

    test[2] = test_s3;
    test[3] = test_s4;

    char *test_s5 = "54577";
    char *test_s6 = "57";

    test[4] = test_s5;
    test[5] = test_s6;

    char *test_s7 = "54577";
    char *test_s8 = "";

    test[6] = test_s7;
    test[7] = test_s8;

    char *test_s9 = "";
    char *test_s10 = "gh";

    test[8] = test_s9;
    test[9] = test_s10;

    char *test_s11 = "";
    char *test_s12 = "";

    test[10] = test_s11;
    test[11] = test_s12;

    for (int i = 0; i < 12; i += 2)
    {          
        printf("my_strpbrk result: %s\n", my_strpbrk(test[i], test[i + 1]));
        printf("strpbrk result: %s\n", strpbrk(test[i], test[i + 1]));
    }

    return 0;
}

char *my_strpbrk(const char *s, const char *accept)
{
    char *rt = NULL;
    int flag = 1;

    for (int i = 0; s[i] != '\0' && flag; i++)
        for (int j = 0; accept[j] != '\0'; j++)
            if (s[i] == accept[j])
            {
                flag = 0;
                rt = (char *) s + i;
            }
    return rt;
}
