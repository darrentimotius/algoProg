#include <stdio.h>

int main()
{
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    int ans = -1;
    if ((k - x) == (y - k))
    {
        if ((k - x) >= 0)
        {
            ans = k - x;
        }
        // ans = k - x;
    }
    printf("%d\n", ans);
}