#include<stdio.h>

struct pulau{
    int x1, x2, y1, y2;
};

struct player{
    int x, y;
};

int main(){
    pulau arr[105];
    player ppti[105];

    int s, n, d;
    scanf("%d", &s);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
    }

    scanf("%d", &d);

    for(int i = 0; i < d; i++){
        scanf("%d %d",&ppti[i].x, &ppti[i].y);
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < d; j++){
            if(arr[i].x1 <= ppti[j].x && ppti[j].x <= arr[i].x2 && arr[i].y1 <= ppti[j].y && ppti[j].y <= arr[i].y2){
                flag = 1;
                break;
            }
        }
        if(flag == 0) count++;
    }
    printf("%d\n", count);
    return 0;
}