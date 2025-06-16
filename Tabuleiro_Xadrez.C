#include <stdio.h>

// Função recursiva da Torre
// Ela vai andar sempre pra cima, o número de casas definido
void moverTorre(int casas) {
    if (casas == 0) return;  // Caso base: quando não tiver mais casa pra andar, para
    printf("Cima\n");        // Mostra na tela o movimento
    moverTorre(casas - 1);   // Chama a função de novo com uma casa a menos
}

// Função recursiva do Bispo - Parte horizontal (andar pra direita)
void moverBispoHorizontal(int passos) {
    if (passos == 0) return;          // Se não tiver mais passos, para
    printf("Direita\n");              // Mostra que andou pra direita
    moverBispoHorizontal(passos - 1); // Chama de novo com um passo a menos
}

// Função recursiva do Bispo - Parte vertical (andar pra cima)
// Aqui, pra cada movimento pra cima, ele faz vários pra direita (usando a função acima)
void moverBispoVertical(int casas) {
    if (casas == 0) return;                    // Caso base
    printf("Cima\n");                          // Mostra o movimento pra cima
    moverBispoHorizontal(casas);               // Faz o movimento pra direita (horizontal) pra cada passo vertical
    moverBispoVertical(casas - 1);             // Chama a função de novo com uma casa a menos
}

// Função recursiva da Rainha
// Pra simplificar, fiz ela andar só pra esquerda
void moverRainha(int casas) {
    if (casas == 0) return;        // Caso base
    printf("Esquerda\n");          // Mostra o movimento
    moverRainha(casas - 1);        // Chama a função de novo
}

// Função para o Cavalo
// Aqui eu usei loops aninhados (um dentro do outro) e condições extras (break, continue)
void moverCavalo() {
    printf("\nMovimentação do Cavalo:\n");
    int linhas = 2;  // O cavalo vai andar duas casas pra cima
    int colunas = 1; // Depois uma casa pra direita

    // Primeiro loop: movimenta pra cima
    for (int i = 0; i < linhas; i++) {
        printf("Cima\n");
    }

    // Segundo loop: movimenta pra direita
    for (int j = 0; j < colunas; j++) {
        printf("Direita\n");
    }

    // Agora um exemplo de loop mais complexo, com continue e break
    printf("\nLoop detalhado do Cavalo:\n");
    for (int i = 0; i < 3; i++) {            // Loop externo (linhas)
        for (int j = 0; j < 3; j++) {        // Loop interno (colunas)
            if (i == 2 && j == 2) {
                break;  // Sai do loop interno antes de terminar, quando chegar nessa condição
            }
            if ((i + j) % 2 == 0) {
                continue;  // Pula pra próxima iteração quando a soma dos índices for par
            }
            printf("Iteração: i=%d, j=%d\n", i, j);  // Mostra os valores de i e j
        }
    }
}

// Função principal (onde o programa começa)
int main() {
    int casasTorre = 3;    // Quantas casas a Torre vai andar
    int casasBispo = 3;    // Quantas casas o Bispo vai andar
    int casasRainha = 4;   // Quantas casas a Rainha vai andar

    // Movimentação da Torre
    printf("\nMovimentação da Torre:\n");
    moverTorre(casasTorre);

    // Movimentação do Bispo
    printf("\nMovimentação do Bispo:\n");
    moverBispoVertical(casasBispo);

    // Movimentação da Rainha
    printf("\nMovimentação da Rainha:\n");
    moverRainha(casasRainha);

    // Movimentação do Cavalo
    moverCavalo();

    return 0;  // Fim do programa
}
