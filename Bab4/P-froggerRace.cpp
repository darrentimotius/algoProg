#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int finishLine;
        scanf("%d", &finishLine);

        int position = 0, jumpDistance = 1, jumps = 0;
        for (int i = 0; i < 1;) {
            if (position < finishLine) {
                position += jumpDistance;
                jumpDistance++;
                jumps++;
            } else {
                break;
            }
        }
        // while (position < finishLine) {
        //     position += jumpDistance;
        //     jumpDistance++;
        //     jumps++;
        // }
        printf("Case #%d: %d\n", i, jumps);
    }
    return 0;
}