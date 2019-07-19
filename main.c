#include <stdio.h>
#include <math.h> //Calcula o exponencial.
#include <locale.h> //Aceita a ortografia da ligua portuguesa.
#include <stdlib.h>
#include <ctype.h>
/* Projeto desenvolvido por
 * Abel Menezes
 *
 * Direitos reservados
 * #taUtologia
 *
 */

int cont = 0;
int *p;

typedef enum boolean {//Definição de um novo tipo Bool que retorna verdadeiro ou falso
    true = 1, false = 0
} bool;

int fatorial(int a)//Faz o fatorial do numero.
{
    int fat;
    for (fat = 1; a > 1; a--) {
        fat = fat * a;
    }
    return fat;
}

void imprime(int R) {//Função que servira para imprimir as combinações
    printf("\n(%d): ", cont);
    int i;
    for (i = 0; i < R; i++) {
        printf("%d ", p[i]);
    }
}

void iniciaPermuta(int *vet, int N, int R) {//Inicia as condições iniciais para a Permutação
    p = malloc(N * sizeof (int));
    permutacao(vet, 0, N, R); //Chamada da função principal
}

void iniciaPermutaRep(int *vet, int N, int R) {//Inicia as condições iniciais para a Permutação com repetição
    p = malloc(N * sizeof (int));
    permutacaoRep(vet, 0, N, R); //Chamada da função principal
}

void iniciaCombinacao(int *vet, int N, int R) {//Inicia as condições iniciais para a Combinação com repetição
    p = malloc(N * sizeof (int));
    combinacao(vet, 0, N, R); //Chamada da função principal
}

void iniciaCombinacaoRep(int *vet, int N, int R) {//Inicia as condições iniciais para a Combinação com repetição
    p = malloc(N * sizeof (int));
    combinacaoRep(vet, 0, N, R); //Chamada da função principal
}

void permutacao(int *vet, int limite, int N, int R) {
    if (limite == R) {
        cont++;
        imprime(R);
    }
    else {
        int i;
        for (i = 0; i < N; i++) {
            bool achou = false;
            int j;
            for (j = 0; j < limite; j++) {

                if (p[j] == vet[i]) {
                    achou = true;
                }
            }
            if (!achou) {
                p[limite] = vet[i];
                permutacao(vet, limite + 1, N, R);
            }
        }
    }
}

void permutacaoRep(int *vet, int limite, int N, int R) {
    if (limite == R) {
        cont++;
        imprime(R);
    }
    else {
        int i;
        for (i = 0; i < N; i++) {

            p[limite] = vet[i];
            permutacaoRep(vet, limite + 1, N, R);

        }
    }
}

void combinacao(int *vet, int limite, int N, int R) {
    if (limite == R) {
        cont++;
        imprime(R);
    }
    else {
        int i;
        for (i = 0; i < N; i++) {
            bool achou = false;
            int j;
            for (j = 0; j < N; j++) {
                int h;
                for (h = 0; h < N; h++) {

                    if (p[h] == vet[i] && p[j] != p[i] && p[h] != p[j]) {
                        achou = true;
                    }
                }
            }
            if (!achou) {
                p[limite] = vet[i];
                combinacao(vet, limite + 1, N, R);
            }
        }
    }
}

void combinacaoRep(int *vet, int limite, int N, int R) {
    if (limite == R) {
        cont++;
        imprime(R);
    }
    else {
        int i;
        for (i = 0; i < N; i++) {
            bool achou = false;
            int j;
            for (j = 0; j < N; j++) {
                int h;
                for (h = 0; h < N; h++) {

                    if (p[h] == vet[i] && p[j] == vet[h] && p[h] == vet[j]) {
                        achou = true;
                    }
                }
            }
            if (!achou) {
                p[limite] = vet[i];
                combinacaoRep(vet, limite + 1, N, R);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int num, n, r, divisor, dividendo, *vetor, conta;
    char ordem, repeticao;
    FILE *arquivo = fopen("APS_MatematicaDiscreta.txt", "a");

    if (arquivo == NULL)
        printf("Não foi possível abrir o aqruivo!");

    printf("---------APS de Matemática Discreta---------\nDigite os dados:\n");
    scanf("%c %c %d %d", &ordem, &repeticao, &n, &r);
    ordem = toupper(ordem);
    repeticao = toupper(repeticao);

    if (repeticao != 'S' && ordem != 'N') {
        if ((n > 10) || (r > n)) {
            printf("> ERRO <");
            return 0;
        }//vai verifcar se os parametros de números digitados são válidos, se não estiverrem irá fechar o programa.
    }
    vetor = malloc(n * sizeof (int));
    for (conta = 1; conta <= n; conta++)vetor[conta - 1] = conta;

    if (ordem == 'S' && repeticao == 'S')//Caso I.
    {
        num = pow(n, r);

        printf("O resultado é > %d <", num);
        fprintf(arquivo, "\nCaso I: Ordem 'Sim' e Repetição 'Sim'.");
        fprintf(arquivo, "\nEntradas: N = %d, R = %d.", n, r);
        fprintf(arquivo, "\nO resultado é >> %d <<", num);
        iniciaPermutaRep(vetor, n, r);

    }
    else if (ordem == 'S' && repeticao == 'N')//Caso II.
    {
        dividendo = fatorial(n);
        divisor = fatorial(n - r);
        num = dividendo / divisor;
        printf("O resultado é > %d <", num);
        fprintf(arquivo, "\nCaso II: Ordem 'Sim' e Repetição 'Não'.");
        fprintf(arquivo, "\nEntradas: N = %d, R = %d.", n, r);
        fprintf(arquivo, "\nO resultado é >> %d <<", num);
        iniciaPermuta(vetor, n, r);

    }
    else if (ordem == 'N' && repeticao == 'S')//Caso III.
    {
        dividendo = fatorial(n + r - 1);
        divisor = fatorial(r) * fatorial(n - 1);
        num = dividendo / divisor;
        printf("O resultado é > %d <", num);
        fprintf(arquivo, "\nCaso III: Ordem 'Não' e Repetição 'Sim'.");
        fprintf(arquivo, "\nEntradas: N = %d, R = %d.", n, r);
        fprintf(arquivo, "\nO resultado é >> %d <<", num);
        iniciaCombinacaoRep(vetor, n, r);

    }
    else if ((ordem == 'N' && repeticao == 'N'))//Caso VI.
    {
        dividendo = fatorial(n);
        divisor = fatorial(r) * fatorial(n - r);
        num = dividendo / divisor;
        printf("O resultado é > %d <", num);
        fprintf(arquivo, "\nCaso VI: Ordem 'Não' e Repetição 'Não'.");
        fprintf(arquivo, "\nEntradas: N = %d, R = %d.", n, r);
        fprintf(arquivo, "\nO resultado é >> %d <<", num);
        iniciaCombinacao(vetor, n, r);

    }
    else {
        printf("> ERRO <");
    }
    fprintf(arquivo, "\n_____________________________________\n");
    fclose(arquivo);
    printf("\n");
    system("pause");
    return 0;
}
