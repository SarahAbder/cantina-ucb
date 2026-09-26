#include <stdio.h>

int pedidosRealizados = 0;
int itensVendidos = 0;
float faturamentoBruto = 0;
float descontosConcedidos = 0;
float faturamentoFinal = 0;

// apresentam as funcoes antes do main.
void mostrarLinha(void);
void mostrarMenu(void);
void mostrarCardapio(void);
void novoPedido(void);
void calculadora(void);
void simularDesconto(void);
void mostrarRelatorio(void);
float precoProduto(int codigo);
float calcularDesconto(float total);
float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
int main(void) {
    int opcao;
    do {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
            return 0;
        }
        switch (opcao) {
            case 1:
                novoPedido();
                break;
            case 2:
                calculadora();
                break;
            case 3:
                simularDesconto();
                break;
            case 4:
                mostrarRelatorio();
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}

void mostrarLinha(void) {
    int i;
    for (i = 0; i < 30; i++) {
        printf("=");
    }
    printf("\n");
}


// MENU PRINCIPAL

void mostrarMenu(void) {
    printf("\n");
    mostrarLinha();
    printf("         CANTINA UCB\n");
    mostrarLinha();
    printf("1 - Novo pedido\n");
    printf("2 - Calculadora rapida\n");
    printf("3 - Simular desconto\n");
    printf("4 - Relatorio da sessao\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}


// CARDAPIO

void mostrarCardapio(void) {
    printf("\n=========== CARDAPIO ===========\n");
    printf("1 - Sanduiche      R$ 12.00\n");
    printf("2 - Refrigerante   R$  6.00\n");
    printf("3 - Suco           R$  8.00\n");
    printf("4 - Salgado        R$  7.00\n");
    printf("5 - Cafe           R$  4.00\n");
    printf("================================\n");
}


// PRECO DOS PRODUTOS

float precoProduto(int codigo) {
    switch (codigo) {
        case 1:
            return 12.00;
        case 2:
            return 6.00;
        case 3:
            return 8.00;
        case 4:
            return 7.00;
        case 5:
            return 4.00;
        default:
            return 0;
    }
}


// DESCONTO

float calcularDesconto(float total) {
    if (total >= 100)
        return total * 0.15f;
    else if (total >= 60)
        return total * 0.10f;
    else if (total >= 30)
        return total * 0.05f;
    else
        return 0;
}


// NOVO PEDIDO

void novoPedido(void) {
    char nome[100];
    int codigo;
    int quantidade;
    int continuar;
    int itensPedido = 0;
    float preco;
    float subtotal;
    float total = 0;
    float desconto;
    float totalFinal;
    printf("\n========== NOVO PEDIDO ==========\n");
    
    printf("Nome do cliente: ");
    if (scanf(" %99[^\n]", nome) != 1) {
        printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
        return;
    }
    do {
        mostrarCardapio();
        
        do {
            printf("Codigo do produto: ");
            if (scanf("%d", &codigo) != 1) {
                printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
                return;
            }
            if (codigo < 1 || codigo > 5) {
                printf("Codigo invalido! Digite de 1 a 5.\n");
            }
        } while (codigo < 1 || codigo > 5);

        
        do {
            printf("Quantidade: ");
            if (scanf("%d", &quantidade) != 1) {
                printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
                return;
            }
            if (quantidade <= 0) {
                printf("Quantidade invalida!\n");
            }
        } while (quantidade <= 0);

        preco = precoProduto(codigo);
        subtotal = preco * quantidade;
        total = total + subtotal;
        itensPedido = itensPedido + quantidade;

        printf("Subtotal: R$ %.2f\n", subtotal);

        // adicionar outro produto
        do {
            printf("Adicionar outro item? 1-Sim / 0-Nao: ");
            if (scanf("%d", &continuar) != 1) {
                printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
                return;
            }
            if (continuar != 0 && continuar != 1) {
                printf("Opcao invalida!\n");
            }
        } while (continuar != 0 && continuar != 1);

    } while (continuar == 1);

    desconto = calcularDesconto(total);
    totalFinal = total - desconto;

    printf("\n======= RESUMO DO PEDIDO =======\n");
    printf("Cliente: %s\n", nome);
    printf("Itens registrados: %d\n", itensPedido);
    printf("Total bruto: R$ %.2f\n", total);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Total final: R$ %.2f\n", totalFinal);
    printf("Pedido registrado com sucesso!\n");

    // atualizar relatorio
    pedidosRealizados++;
    itensVendidos = itensVendidos + itensPedido;
    faturamentoBruto = faturamentoBruto + total;
    descontosConcedidos = descontosConcedidos + desconto;
    faturamentoFinal = faturamentoFinal + totalFinal;
}




float somar(float a, float b) {
    return a + b;
}




float subtrair(float a, float b) {
    return a - b;
}




float multiplicar(float a, float b) {
    return a * b;
}




float dividir(float a, float b) {
    return a / b;
}


// CALCULADORA

void calculadora(void) {
    int opcao;
    float a;
    float b;
    float resultado;
    do {
        printf("\n========= CALCULADORA =========\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
            return;
        }

        if (opcao >= 1 && opcao <= 4) {
            printf("Primeiro numero: ");
            if (scanf("%f", &a) != 1) {
                printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
                return;
            }
            printf("Segundo numero: ");
            if (scanf("%f", &b) != 1) {
                printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
                return;
            }
        }

        switch (opcao) {
            case 1:
                resultado = somar(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 2:
                resultado = subtrair(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 3:
                resultado = multiplicar(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 4:
                if (b == 0) {
                    printf("Nao e permitido dividir por zero.\n");
                } else {
                    resultado = dividir(a, b);
                    printf("Resultado: %.2f\n", resultado);
                }
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}




void simularDesconto(void) {
    float valor;
    float desconto;
    float valorFinal;
    int porcentagem;
    printf("\n====== SIMULAR DESCONTO ======\n");

    do {
        printf("Valor da compra: R$ ");
        if (scanf("%f", &valor) != 1) {
            printf("Entrada invalida ou encerrada. Use numeros nos campos numericos.\n");
            return;
        }
        if (valor <= 0) {
            printf("Valor invalido!\n");
        }
    } while (valor <= 0);

    desconto = calcularDesconto(valor);
    valorFinal = valor - desconto;

    // O desconto dividido pelo valor informa a taxa aplicada.
    porcentagem = (int)((desconto / valor) * 100 + 0.5f);

    printf("Faixa encontrada: %d%%\n", porcentagem);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", valorFinal);
}


// RELATORIO

void mostrarRelatorio(void) {
    printf("\n========= RELATORIO =========\n");
    printf("Pedidos realizados: %d\n",
           pedidosRealizados);
    printf("Itens vendidos: %d\n",
           itensVendidos);
    printf("Faturamento bruto: R$ %.2f\n",
           faturamentoBruto);
    printf("Descontos concedidos: R$ %.2f\n",
           descontosConcedidos);
    printf("Faturamento final: R$ %.2f\n",
           faturamentoFinal);
    printf("=============================\n");
}
