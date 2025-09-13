#include <stdio.h> 

//GLOBAL VARIABLE 
int A; 
int B; 

//return_type function_name (parameter, ..., ...){ body }
int menu(); //membantu biar int main di atas 
//Utilities -> Mengurangi Coding berulang-ulang 
int next_int();

void handleMenu(int inp);

void menu_artihmatical();

void menu_bitwise();

int main(){
    int inp;
    do{
        inp = menu();
        handleMenu(inp);
    } while(inp != 4);

    printf("bye bye, terima kasih telah menggunakan program, semoga lulus cawu 1 aminnnnnn\n");
    return 0; 
}

int menu(){
    //CTRL + E = DUPLICATE 
    //CTRL + SHIFT + Arrow Key = pindahin whole line 
    int inp; 
    do{
    printf("1. Insert Values\n"); 
    printf("2. Arithmatical Operator\n"); 
    printf("3. Bitwise Operator\n");
    printf("4. Exit Program\n"); 
    printf(">> ");         //biar rapi 
    inp =next_int(); 
    }while(! (inp>0 && inp<5)); 

    return inp; 
}
int next_int (){
    int input; 
    scanf("%d", &input); 
    getchar();              //makan buffer input 

    return input; 
}
void menu_arithmatical(){
    int inp; 
    do{
        printf("1. Penjumlahan\n"); 
        printf("2. Pengurangan\n"); 
        printf("3. Perkalian\n"); 
        printf("4. Pembagian\n"); 
        printf("5. Modulus\n"); 
        printf(">> "); 
        //CTRL + SPASI = AutoComplete 
        inp = next_int(); 
     } while(inp<=0 || inp>=6); 

     switch(inp){
        case 1:
            printf("%d + %d = %d\n", A, B, A+B); 
            break; 
        case 2:
            printf("%d - %d = %d\n", A, B, A-B); 
            break; 
        case 3:
            printf("%d * %d = %d\n", A, B, A*B); 
            break; 
        case 4: 
            printf("%d / %d = %d\n", A, B, A/B); 
            break; 
        case 5: 
            printf("%d %% %d = %d\n", A, B, A%B); 
            break; 
     }

}
void menu_bitwise(){
    int inp; 
    do{
        printf("1. AND Operator\n"); 
        printf("2. OR Operator\n"); 
        printf("3. XOR Operator\n"); 
        printf("4. SHIFT LEFT ONCE Operator\n"); 
        printf("5. SHIFT RIGHT ONCE Operator\n"); 
        printf(">> "); 
        inp=next_int(); 
    } while(inp<=0 || inp>=6); 
    switch(inp){
        case 1: 
            printf("%d & %d = %d\n", A, B, A&B); 
            break; 
        case 2: 
            printf("%d | %d = %d\n", A, B, A|B); 
            break; 
        case 3:
            printf("%d ^ %d = %d\n", A, B, A^B); 
            break; 
        case 4: 
            printf("For A: %d << 1 = %d\n", A, A<<1); 
            printf("For B: %d << 1 = %d\n", B, B<<1); 
            break; 
        case 5: 
            printf("For A: %d >> 1 = %d\n", A, A>>1); 
            printf("For B: %d >> 1 = %d\n", B, B>>1); 
            break; 
    } 
}
void handleMenu(int inp){
    switch(inp){
        case 1:      //menu insert Value 
            printf("A = "); 
            A=next_int(); 

            printf("B = "); 
            B=next_int(); 

            printf("\n\nHasil A = %d dan B = %d\n\n", A, B); 
            break; 
        case 2:      //menu Arithmatical 
            menu_arithmatical(); 


            break; 
        case 3:      //menu Bitwise 
            menu_bitwise(); 


            break; 
        case 4:      //
            break; 
    }
}