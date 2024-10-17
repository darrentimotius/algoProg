#include <stdio.h>

int main() {
    long long int testCase;
    scanf("%lld", &testCase);

    for (long long int i = 1; i <= testCase; i++) {
        long long int totalPlate, capacity, alrHave;
        scanf("%lld %lld %lld", &totalPlate, &capacity, &alrHave);

        long long int largest = 0;
        for (long long int j = 0; j < totalPlate; j++) {
            long long int plate;
            scanf("%lld", &plate);
            if (plate == capacity) largest = plate;
            else if (plate >= largest && plate <= capacity) largest = plate;
        }
        if (largest >= alrHave && largest <= capacity) {
            printf("Case #%lld: %lld\n", i, largest);
        } else {
            printf("Case #%lld: %lld\n", i, alrHave);
        }
    }
    return 0;
}