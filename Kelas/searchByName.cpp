#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char nim[15];
    char name[105];
};

int main() {
    Student ppti[] = {
        {"2802540143",  "ADRIEL BERNHARD TANUHARIONO"},
        {"2802538435",  "AGUNG RAMADHAN"},
        {"2802538441",  "ANGGER DHISMA KUSUMA"},
        {"2802539772",  "CLARISSA JESSELYN"},
        {"2802538460",  "DARA CANTIKA FEBRIAN KINASIH"},
        {"2802538492",  "DARREN PRATAMA WIJAYA"},
        {"2802538523",  "DARREN TIMOTIUS RAPHAEL"},
        {"2802540124",  "DELICIA NATHANIA"},
        {"2802538611",  "FANCE SATRIA NUSANTARA"},
        {"2802538624",  "GABRIEL MARTIN PRASONA"},
        {"2802539974",  "HELEN FEBRIYANTO"}
    };


    for (int i = 0; i < 10; i++) {
        if (strcmp(ppti[i].nim, "2802538611") == 0) {
            printf("%s\n", ppti[i].name);
        }
    }

    return 0;
}