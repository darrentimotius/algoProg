#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct data {
    char nim[15];
    char name[100];
    int solved;
    int pinalty;
};

void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data arr[], int l, int h) {
    int r = (rand() % (h - l)) + l;
    swap(&arr[r], &arr[h]);

    int i = l - 1;
    data pivot = arr[h];
    for (int j = l; j < h; j++) {
        if (arr[j].solved > pivot.solved || 
        (arr[j].solved == pivot.solved && arr[j].pinalty < pivot.pinalty) || 
        (arr[j].solved == pivot.solved && arr[j].pinalty == pivot.pinalty && strcmp(arr[j].nim, pivot.nim) < 0)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quick (data arr[], int l, int h) {
    if (l >= h) return;
    int pivot = partition(arr, l, h);

    quick(arr, pivot + 1, h);
    quick(arr, l, pivot - 1);
}

int main() {
    data arr[] = {
        {"2802540143", "ADRIEL BERNHARD TANUHARIONO"},
        {"2802538435", "AGUNG RAMADHAN"},
        {"2802538441", "ANGGER DHISMA KUSUMA"},
        {"2802539772", "CLARISSA JESSELYN"},
        {"2802538460", "DARA CANTIKA FEBRIAN KINASIH"},
        {"2802538492", "DARREN PRATAMA WIJAYA"},
        {"2802538523", "DARREN TIMOTIUS RAPHAEL"},
        {"2802540124", "DELICIA NATHANIA"},
        {"2802538611", "FANCE SATRIA NUSANTARA"},
        {"2802538624", "GABRIEL MARTIN PRASONA"},
        {"2802539974", "HELEN FEBRIYANTO"},
        {"2802540130", "JAZZY"},
        {"2802540250", "JONEA KRISTIAWAN"},
        {"2802538681", "KENT NATHANAEL"},
        {"2802539822", "KEVIN JIOVANNI KUSLIN"},
        {"2802540004", "KEVIN TANWIPUTRA"},
        {"2802538694", "LEONARDO ALEXANDER WIJAYA"},
        {"2802539841", "LYNEL ANGELICA MADELYN"},
        {"2802538712", "M. QAISHAR ARIF NAVARINO"},
        {"2802540023", "NATHANIEL CHRISTODEO PANGET"},
        {"2802539860", "NI NYOMAN DIAH SARASWATI DEVITRI"},
        {"2802539892", "NICHOLAS WILLIAM"},
        {"2802540055", "OKTAVIANUS KIMMY YONATA"},
        {"2802538744", "OLIVIA THE"},
        {"2802540572", "ONG, CORNELLIUS JASON FERNANDO"},
        {"2802540585", "RIO DWI OKTAVIANTO"},
        {"2802538750", "SAMUDRA BRYANDHIKA PRAKOSO"},
        {"2802539753", "SAMUEL CHRISTIAN CHANDRA"},
        {"2802538334", "SIDNEY LIAS"},
        {"2802538340", "SYARIFANA AMALIA PUTRI"},
        {"2802538353", "THEODORUS YURIPUTRA WIBISONO"},
        {"2802540156", "VINCENT TANAKA"},
        {"2802540162", "WILSON HANDOJO"},
        {"2802538391", "YAUW LINDA APRILLY SURYANI HARTA"},
        {"2802539942", "YOSUA WIBISONO GOZALI"},
    };

    for (int i = 0; i < 35; i++) {
        arr[i].solved = rand() % 4;
        arr[i].pinalty = (rand() % 12 + 1) * 5;
        printf("%s %35s %d %d\n", arr[i].nim, arr[i].name, arr[i].solved, arr[i].pinalty);
    }
    printf("\n\n");

    srand(time(0));

    quick(arr, 0, 35 - 1);

    data a = arr[0];
    int rank = 0;
    for (int i = 0; i < 35; i++) {
        if (i == 0) 
            rank = 1;
        else if (arr[i].solved != arr[i - 1].solved || arr[i].pinalty != arr[i - 1].pinalty) 
            rank = i + 1;
        printf("%2d %s %35s %d %d\n", rank, arr[i].nim, arr[i].name, arr[i].solved, arr[i].pinalty);
    }
    return 0;
}