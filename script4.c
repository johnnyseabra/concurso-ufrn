/*******************************************************************
 * Script 4: Operadores Bitwise
 * Demonstra: Manipulação de bits, máscaras e funções do K&R
 * Executar em: https://www.onlinegdb.com/
 *******************************************************************/

#include <stdio.h>

/* getbits: retorna n bits da posição p - K&R p.49 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* bitcount: conta bits 1 em x - K&R p.50 */
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

/* Função auxiliar para imprimir em binário */
void printBinary(unsigned n, int bits) {
    unsigned mask = 1 << (bits - 1);
    while (mask) {
        printf("%d", (n & mask) ? 1 : 0);
        mask >>= 1;
    }
}

int main() {
    printf("=== OPERADORES BITWISE ===\n\n");
    
    unsigned a = 0xF0;  /* 11110000 */
    unsigned b = 0x3C;  /* 00111100 */
    
    printf("a = 0x%02X = ", a); printBinary(a, 8); printf("\n");
    printf("b = 0x%02X = ", b); printBinary(b, 8); printf("\n\n");
    
    /* AND bit a bit */
    printf("a & b  = 0x%02X = ", a & b); 
    printBinary(a & b, 8); 
    printf(" (AND: ambos devem ser 1)\n");
    
    /* OR bit a bit */
    printf("a | b  = 0x%02X = ", a | b); 
    printBinary(a | b, 8); 
    printf(" (OR: pelo menos um deve ser 1)\n");
    
    /* XOR bit a bit */
    printf("a ^ b  = 0x%02X = ", a ^ b); 
    printBinary(a ^ b, 8); 
    printf(" (XOR: devem ser diferentes)\n");
    
    /* NOT bit a bit */
    printf("~a     = 0x%02X = ", (unsigned char)~a); 
    printBinary(~a & 0xFF, 8); 
    printf(" (NOT: inverte todos os bits)\n");
    
    /* Shifts */
    printf("\n=== OPERAÇÕES DE SHIFT ===\n");
    unsigned x = 0x0F;  /* 00001111 */
    printf("x      = 0x%02X = ", x); printBinary(x, 8); printf("\n");
    printf("x << 2 = 0x%02X = ", x << 2); printBinary(x << 2, 8); 
    printf(" (multiplica por 4)\n");
    printf("x >> 2 = 0x%02X = ", x >> 2); printBinary(x >> 2, 8); 
    printf(" (divide por 4)\n");
    
    /* Máscaras comuns */
    printf("\n=== MÁSCARAS ÚTEIS ===\n");
    unsigned n = 0xABCD;
    printf("n = 0x%04X\n", n);
    printf("n & 0xFF   = 0x%04X (byte baixo)\n", n & 0xFF);
    printf("n & 0xFF00 = 0x%04X (byte alto)\n", n & 0xFF00);
    printf("n & ~0xF   = 0x%04X (zera nibble baixo)\n", n & ~0xF);
    
    /* Diferença entre & e && */
    printf("\n=== & (bitwise) vs && (logical) ===\n");
    int p = 1, q = 2;
    printf("p = %d, q = %d\n", p, q);
    printf("p & q  = %d (AND bit a bit)\n", p & q);
    printf("p && q = %d (AND lógico)\n", p && q);
    
    /* Demonstração da função getbits */
    printf("\n=== FUNÇÃO getbits DO K&R ===\n");
    unsigned val = 0xF2;  /* 11110010 */
    printf("val = 0x%02X = ", val); printBinary(val, 8); printf("\n");
    printf("getbits(val, 4, 3) = %u ", getbits(val, 4, 3));
    printf("(3 bits da posição 4)\n");
    
    /* Demonstração da função bitcount */
    printf("\n=== FUNÇÃO bitcount DO K&R ===\n");
    unsigned test = 0xA5;  /* 10100101 */
    printf("test = 0x%02X = ", test); printBinary(test, 8); printf("\n");
    printf("Número de bits 1: %d\n", bitcount(test));
    
    return 0;
}
