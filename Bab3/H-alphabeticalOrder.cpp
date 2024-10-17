#include <stdio.h>

int main()
{
    char A, B, C;
    scanf("%c %c %c", &A, &B, &C);
    getchar();
    int numA = A;
    int numB = B;
    int numC = C;
    int ans1, ans2, ans3;

    // B D A
    // A B D
    // 3 1 2
    if (numA > numB)
    {
        if (numA > numC)
        {
            ans3 = 1;
            if (numB < numC)
            {
                ans1 = 2;
                ans2 = 3;
            }
            else // numB > numC
            {
                ans1 = 3;
                ans2 = 2;
            }
        }
        else // numA < numC
        {
            ans2 = 1;
            if (numB < numC)
            {
                ans1 = 2;
                ans3 = 3;
            }
            else // numB > numC
            {
                ans1 = 3;
                ans3 = 2;
            }
        }
    }
    else // numA < numB
    {
        if (numA < numC)
        {
            ans1 = 1;
            if (numB < numC)
            {
                ans2 = 2;
                ans3 = 3;
            }
            else // numB > numC
            {
                ans2 = 3;
                ans3 = 2;
            }
        }
        else // numA > numC
        {
            ans2 = 1;
            if (numB < numC)
            {
                ans1 = 2;
                ans3 = 3;
            }
            else // numB > numC
            {
                ans1 = 3;
                ans3 = 2;
            }
        }
    }
    printf("%d %d %d\n", ans1, ans2, ans3);
}