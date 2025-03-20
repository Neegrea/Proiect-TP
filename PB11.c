#include <stdio.h>

void reuniune(int A[], int lungimeA, int B[], int lungimeB) {
    int i = 0, j = 0;
    while (i < lungimeA && j < lungimeB) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        }
        //daca elem din A e mai mic se afiseaza, si se trece la urmatorul elem
        else if (A[i] > B[j]) {
            printf("%d ", B[j]);
            j++;
        }
        //daca cel din B este mai mic se afiseaza, si se trece la urmatorul elem
        else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
        //daca acestea sunt egale se afiseaza si ambele trec la urmatorul elem
    }
    while (i < lungimeA) {
        printf("%d ", A[i]);
        i++;
    }
    //daca in multimea B nu mai sunt elem de verificat, se afiseaza toate ramase din A
    while (j < lungimeB) {
        printf("%d ", B[j]);
        j++;
    }
    //acelasi lucru in cazul multimii B
}

void intersectie(int A[], int lungimeA, int B[], int lungimeB) {
    int i = 0, j = 0;
    while (i < lungimeA && j < lungimeB) {
        if (A[i] < B[j]) {
            i++;
        }
        else if (A[i] > B[j]) {
            j++;
        }
        //prin aceste if uri mergem la urmatorul element din multime, daca unul este mai mic decat celalalt,
        //bazandu ne pe faptul ca multimiile sunt in ordine crescatoare
        else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
        //daca elementele sunt egale se afiseaza elementul si ambele contoare trec la urmatorul element
    }
}

void diferenta(int A[], int lungimeA, int B[], int lungimeB) {
    //functia face diferenta A-B
    //astfel prima multime pe care o scriem in functia e cea din care scadem
    int i = 0, j = 0;
    while (i < lungimeA && j < lungimeB) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        }
        //cu acest if se verifica daca elementul din A este mai mic decat cel din B
        //astfel este clar ca nu sunt egale iar cel din A nu se afla in multimea B
        else if (A[i] > B[j]) {
            j++;
        }
        //daca elem din A este mai mare crestem j ul pentru
        //a verifica daca se afla sau nu in B
        else {
            i++;
            j++;
        }
        //in cazul in care elem sunt egale se trece in ambele multimi la urmatorul element
    }
    while (i < lungimeA) {
        printf("%d ", A[i]);
        i++;
    }
    //in cazul in care B ajunge la ultimul element
    //se vor afisa toate elementele ramase in A, acestea nefiind in B
}

int main() {
    int A[100], B[100];
    int lungimeA, lungimeB;
    printf("Introduceti nr de elemente din multimi:");
    scanf("%d", &lungimeA);
    lungimeB = lungimeA;
    printf("Introduceti matricea A:\n");
    for (int i = 0; i<lungimeA; i++) 
    {
        printf("Elementul %d:", (i+1));
        scanf("%d",&A[i]);
    }
    
    printf("Introduceti matricea B:\n");
    for (int i = 0; i < lungimeB; i++)
    {
        printf("Elementul %d:", (i + 1));
        scanf("%d", &B[i]);
    }


    printf("Reuniunea: ");
    reuniune(A, lungimeA, B, lungimeB);
    printf("\n");

    printf("Intersectia: ");
    intersectie(A, lungimeA, B, lungimeB);
    printf("\n");

    printf("Diferenta A-B: ");
    diferenta(A, lungimeA, B, lungimeB);
    printf("\n");

    printf("Diferenta B-A: ");
    diferenta(B, lungimeB, A, lungimeA);
    printf("\n");

    return 0;
}