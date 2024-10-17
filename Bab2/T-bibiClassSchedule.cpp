#include <stdio.h>

int main() {
    char input[11];
    double hour1, hour2, min1, min2;
    scanf("%s %lf:%lf-%lf:%lf", input, &hour1, &min1, &hour2, &min2);
    getchar();
    printf("%s %02.0lf:%02.0lf-%02.0lf:%02.0lf\n", input, hour1 - 1, min1, hour2 - 1, min2);

    scanf("%s %lf:%lf-%lf:%lf", input, &hour1, &min1, &hour2, &min2);
    getchar();
    printf("%s %02.0lf:%02.0lf-%02.0lf:%02.0lf\n", input, hour1 - 1, min1, hour2 - 1, min2);

    scanf("%s %lf:%lf-%lf:%lf", input, &hour1, &min1, &hour2, &min2);
    getchar();
    printf("%s %02.0lf:%02.0lf-%02.0lf:%02.0lf\n", input, hour1 - 1, min1, hour2 - 1, min2);
    
    scanf("%s %lf:%lf-%lf:%lf", input, &hour1, &min1, &hour2, &min2);
    getchar();
    printf("%s %02.0lf:%02.0lf-%02.0lf:%02.0lf\n", input, hour1 - 1, min1, hour2 - 1, min2);
    
    scanf("%s %lf:%lf-%lf:%lf", input, &hour1, &min1, &hour2, &min2);
    getchar();
    printf("%s %02.0lf:%02.0lf-%02.0lf:%02.0lf\n", input, hour1 - 1, min1, hour2 - 1, min2);

    return 0;
}