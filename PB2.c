#include <stdio.h>
#include <string.h>

#define max 100000 //definim lungimea maxima a sirului pentru a fi mai usor de scris

int verificare(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
//functia aceasta ne ajuta sa detectam orice caracter care nu e litera sau cifra
int LiteraMare(char* cuv) {
    return (cuv[0] >= 'A' && cuv[0] <= 'Z');
}
//verificam ca prima litera din cuvant sa fie litera mare
void blurare(char* sir, int LungimeSir, int K, char CaracterSpecial) {
    int i, j;
    char cuv[max]; // pentru a memora cuvintele
    int LungimeCuv = 0; // lungimea cuvantului
    for (i = 0; i <= LungimeSir; i++) {
        if (verificare(sir[i])) {
            cuv[LungimeCuv++] = sir[i];
        }
        //cu acest if adaugam literele unui cuvant intr un sir
        else {
            cuv[LungimeCuv] = '\0'; // terminam cuvantul cu caracterul null
            if (LungimeCuv > 0 && LiteraMare(cuv)) {
                for (j = 0; j < K; j++) {
                    printf("%c", CaracterSpecial);
                }
            }
            //daca cuvantul are litera mare se printeaza caracterul special de k ori
            else {
                printf("%s", cuv);
            }
            //daca nu incepe cu litera mare se printeaza cuvantul
            LungimeCuv = 0;//resetam lungimea la 0, pentru a construi alt cuvant
            printf("%c", sir[i]);
            //iar aici afisam caracterul care nu este litera sau cifra
            //pentru a pastra propozitia identica
        }
        
    }
}

int main() {
    char sir[max];
    int K;
    char CaracterSpecial;

    printf("Introduceti sirul de caractere: ");
    fgets(sir, max, stdin);

    do {
        printf("Introduceti numarul K: ");
        scanf("%d", &K);
     } while (K > 200);
    
    printf("Introduceti caracterul special: ");
    scanf(" %c", &CaracterSpecial);
    blurare(sir, strlen(sir), K, CaracterSpecial);

    return 0;
}