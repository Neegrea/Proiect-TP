#include <stdio.h>
#include<math.h>

int prim(int N) {
    if (N <= 1)
        return 0;//caz pt 1 si 0
    for (int i = 2; i <= N / 2; i++) {
        if (N % i == 0)
            return 0; //daca n se divide cu un nr pana la jumatatea lui nu este prim
    }
    return 1;//daca n nu se divide cu nici un numar pana la jumatatea este prim
}
//aceasta functie verifica daca un numar este prim

int circular(int N) {
    int NumCifre = 0;
    int var = N;
    //luam o variabila egala cu numarul pentru a-i calcula numarul de cifre
    while (var != 0) {
        var /= 10;
        NumCifre++;
    }
    //cu acest while calculam numarul de cifre al numarului
    var = N;
    //egalam din nou cu N pentru a rotii cifrele acestuia 
    for (int i = 0; i < NumCifre; ++i) {
        if (!prim(var))
            return 0;
        int UltimaCifra = var % 10;
        var = UltimaCifra * pow(10, NumCifre - 1) + var / 10;
        //variabila devine urmatoarea rotatie a numarului N
        //adica variabila va fi numarul N incepand cu ultima cifra si continuand cu restul( 123 -> 312) 
    }
    return 1;
}
//aceasta functie verifica daca un nr e circular prim

void cautare(int N) {
    printf("Numerele prime circulare mai mici decat %d sunt:\n", N);
    for (int i = 2; i < N; ++i) {
        if (circular(i))
            printf("%d ", i);
    }
}
//aceasta functie cauta toate numerele circulare prime mai mici decat N

int main() {
    int N;
    do {
        printf("Introduceti valoarea lui N: ");
        scanf("%d", &N);
    } while (N<0 || N>10000);
    cautare(N);
    return 0;
}