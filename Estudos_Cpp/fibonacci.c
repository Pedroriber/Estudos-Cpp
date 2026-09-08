#include <stdio.h>
#include <time.h>

long long fib(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;

    long long anterior = 0, atual = 1, prox = 0;
    for (int i = 2; i < n; i++) {
        prox = anterior + atual;
        anterior = atual;
        atual = prox;
    }
    return prox;
}

long long fib_rec(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Função auxiliar para converter o tempo decorrido para milissegundos
double calcular_ms(struct timespec inicio, struct timespec fim) {
    double segundos = fim.tv_sec - inicio.tv_sec;
    double nanossegundos = fim.tv_nsec - inicio.tv_nsec;
    return (segundos * 1000.0) + (nanossegundos / 1000000.0);
}

int main(void) {
    while (1) {
        int n; // Teste com n = 40
        printf("Entre com o n-esimo numero de fibonacci: \n");
        scanf_s("%d", &n);
        struct timespec inicio, fim;

        // Medição do Fib Iterativo
        timespec_get(&inicio, TIME_UTC);
        long long res1 = fib(n);
        timespec_get(&fim, TIME_UTC);
        double tempo_iterativo = calcular_ms(inicio, fim);

        // Medição do Fib Recursivo
        timespec_get(&inicio, TIME_UTC);
        long long res2 = fib_rec(n);
        timespec_get(&fim, TIME_UTC);
        double tempo_recursivo = calcular_ms(inicio, fim);

        printf("Fibonacci para n = %d:\n", n);
        printf("Iterativo: resultado = %lld | tempo = %.4f ms\n", res1, tempo_iterativo);
        printf("Recursivo: resultado = %lld | tempo = %.4f ms\n", res2, tempo_recursivo);
        printf("--------------------------------------------------------\n");
    }
}