#include<stdio.h>
#include<string.h>

#define LIMIT 5001
#define MAX 1050
char num[LIMIT][MAX];
char result[MAX];
char temp[MAX];

char* sum(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen, maxLen;
    int i, j, k;

    if (len1 > len2)
        minLen = len2, maxLen = len1;
    else
        minLen = len1, maxLen = len2;
    int carry = 0;
    for (k = 0, i = len1 - 1, j = len2 - 1; k<minLen; k++, i--, j--)
    {
        int val = (str1[i] - '0') + (str2[j] - '0') + carry;
        result[k] = (val % 10) + '0';
        carry = val / 10;
    }
    while (k < len1)
    {
        int val = str1[i] - '0' + carry;
        result[k] = (val % 10) + '0';
        carry = val / 10;

        k++; i--;
    }
    while (k < len2)
    {
        int val = str2[j] - '0' + carry;
        result[k] = (val % 10) + '0';
        carry = val / 10;

        k++; j--;
    }
    if (carry > 0)
    {
        result[maxLen] = carry + '0';
        maxLen++;
        result[maxLen] = '\0';
    }
    else
    {
        result[maxLen] = '\0';
    }
    i = 0;
    while (result[--maxLen])
    {
        temp[i++] = result[maxLen];
    }
    temp[i] = '\0';
    return temp;
}

void generateFibonacci()
{
    int i;
    num[0][0] = '1'; num[0][1] = '\0';
    num[1][0] = '1'; num[1][1] = '\0';
    for (i = 2; i <= LIMIT; i++)
    {
        strcpy(num[i], sum(num[i - 1], num[i - 2]));
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, K;
    generateFibonacci();
        
    while (scanf("%d", &N)== 1)
    {
        printf("The Fibonacci number for %d is %s\n", N, num[N]);
    }
    return 0;
}
