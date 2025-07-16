/*******************************************************************
 * Script 6: Exemplo Integrado - Mini Calculadora Binária
 * Demonstra: Todos os conceitos do Capítulo 2 juntos
 * Executar em: https://www.onlinegdb.com/
 *******************************************************************/

#include <stdio.h>
#include <limits.h>

#define MAX_BITS 16
#define TRUE 1
#define FALSE 0

/* Converte string hexadecimal para inteiro - baseado no exercício 2-3 */
int htoi(char s[]) {
    int i = 0, n = 0;
    
    /* Pula 0x ou 0X opcional */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else
            break;  /* caractere inválido */
        i++;
    }
    return n;
}

/* Imprime número em binário com grupos de 4 bits */
void printBinaryGrouped(unsigned n, int bits) {
    int i;
    for (i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0)
            printf(" ");
    }
}

int main() {
    printf("=== CALCULADORA DE EXPRESSÕES BINÁRIAS ===\n");
    printf("Demonstração completa do Capítulo 2 do K&R\n\n");
    
    /* Entrada de dados (simulada para o online) */
    char hex1[] = "0xFF";
    char hex2[] = "0x3C";
    
    /* Conversão usando nossa htoi */
    unsigned a = htoi(hex1);
    unsigned b = htoi(hex2);
    
    printf("Entrada 1: %s = %u = ", hex1, a);
    printBinaryGrouped(a, 8);
    printf("\n");
    
    printf("Entrada 2: %s = %u = ", hex2, b);
    printBinaryGrouped(b, 8);
    printf("\n\n");
    
    /* Menu de operações */
    printf("=== OPERAÇÕES ARITMÉTICAS ===\n");
    printf("a + b = %u\n", a + b);
    printf("a - b = %u", a - b);
    if ((int)(a - b) < 0)  /* cast para verificar negativo */
        printf(" (underflow em unsigned!)\n");
    else
        printf("\n");
    printf("a * b = %u\n", a * b);
    printf("a / b = %u (divisão inteira)\n", a / b);
    printf("a %% b = %u (resto)\n", a % b);
    
    /* Demonstração de conversões */
    printf("\n=== CONVERSÕES DE TIPO ===\n");
    float fa = a, fb = b;
    printf("Como float: a/b = %.4f\n", fa/fb);
    printf("Com cast:   a/b = %.4f\n", (float)a/b);
    
    /* Operações bitwise */
    printf("\n=== OPERAÇÕES BITWISE ===\n");
    printf("a & b  = %3u = ", a & b);
    printBinaryGrouped(a & b, 8);
    printf(" (AND)\n");
    
    printf("a | b  = %3u = ", a | b);
    printBinaryGrouped(a | b, 8);
    printf(" (OR)\n");
    
    printf("a ^ b  = %3u = ", a ^ b);
    printBinaryGrouped(a ^ b, 8);
    printf(" (XOR)\n");
    
    printf("~a     = %3u = ", (unsigned char)~a);
    printBinaryGrouped(~a & 0xFF, 8);
    printf(" (NOT)\n");
    
    /* Shifts e operadores de atribuição */
    printf("\n=== SHIFTS E ATRIBUIÇÕES ===\n");
    unsigned x = a;  /* cópia para modificar */
    
    printf("x = a = %u\n", x);
    x >>= 4;
    printf("x >>= 4: %u (dividiu por 16)\n", x);
    x <<= 2;
    printf("x <<= 2: %u (multiplicou por 4)\n", x);
    x &= 0x3F;
    printf("x &= 0x3F: %u (manteve apenas 6 bits baixos)\n", x);
    
    /* Expressão condicional */
    printf("\n=== OPERADOR TERNÁRIO ===\n");
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    printf("max(a,b) = %d\n", max);
    printf("min(a,b) = %d\n", min);
    
    /* Exemplo de precedência */
    printf("\n=== PRECEDÊNCIA DE OPERADORES ===\n");
    unsigned result1 = a + b << 2;      /* (a + b) << 2 */
    unsigned result2 = a + (b << 2);    /* a + (b << 2) */
    printf("a + b << 2   = %u (+ tem precedência maior)\n", result1);
    printf("a + (b << 2) = %u (forçado com parênteses)\n", result2);
    
    /* Resumo do sistema */
    printf("\n=== INFORMAÇÕES DO SISTEMA ===\n");
    printf("CHAR_BIT: %d bits por byte\n", CHAR_BIT);
    printf("INT_MAX:  %d\n", INT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    
    /* Nota sobre portabilidade */
    printf("\n/** Nota do K&R: \"C is not specialized to any\n");
    printf("    particular area of application. But its absence\n");
    printf("    of restrictions make it more convenient.\" **/\n");
    
    return 0;
}
