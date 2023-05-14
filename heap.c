#include<stdio.h>
#include<stdlib.h>

int M = 10;
int *T; // declarando T como ponteiro

int n = 0;

void subir(int i){
    int j = i/2;
    if(j >= 1){
        if(T[i] > T[j]){
            int aux = T[i];
            T[i] = T[j];
            T[j] = aux;
            subir(j);
        }
    }
}


void inserir(int chave){
    if(n < M){
        T[n+1] = chave;
        n++;
    }
    subir(n);
}




void descer(int i){
    int j = 2*i;
    if(j <= n){
        if(j+1 <= n && T[j+1] > T[j]){
            j++;
        }
        if(T[i] < T[j]){
            int aux = T[i];
            T[i] = T[j];
            T[j] = aux;
            descer(j);
        }
    }
}
int remover(){
    if(n > 0){
        int max = T[1];
        T[1] = T[n];
        n--;
        descer(1);
        return max;
    } else {
        printf("Heap vazia!\n");
        return -1;
    }
}
int main(){
    T = (int*) malloc((M+1) * sizeof(int)); // alocando memória para T

    inserir(4);
    inserir(8);
    inserir(2);
    inserir(10);
    inserir(5);
    inserir(1);
    inserir(7);
    inserir(3);

    printf("Heap atual:\n");
    for(int i=1; i<=n; i++){
        printf("%d ", T[i]);
    }
    printf("\n");

    int max = remover();
    printf("Removido o elemento %d\n", max);

    printf("Heap atual:\n");
    for(int i=1; i<=n; i++){
        printf("%d ", T[i]);
    }
    printf("\n");

    max = remover();
    printf("Removido o elemento %d\n", max);

    printf("Heap atual:\n");
    for(int i=1; i<=n; i++){
        printf("%d ", T[i]);
    }
    printf("\n");

    free(T); // liberando a memória alocada para T

    return 0;
}