/*******************************************************************
 * Script 1: Tipos de Dados e Limites
 * Demonstra: Tamanhos, limites e portabilidade
 * Executar em: https://www.onlinegdb.com/
 ******************************************************************/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== TIPOS INTEIROS E SEUS LIMITES ===\n\n");
    
    /* Tamanhos em bytes */
    printf("Tamanhos dos tipos inteiros:\n");
    printf("  sizeof(char)  = %lu byte(s)\n", sizeof(char));
    printf("  sizeof(short) = %lu byte(s)\n", sizeof(short));
    printf("  sizeof(int)   = %lu byte(s)\n", sizeof(int));
    printf("  sizeof(long)  = %lu byte(s)\n", sizeof(long));
    
    /* Limites de cada tipo */
    printf("\nLimites dos tipos signed:\n");
    printf("  char:  %d a %d\n", CHAR_MIN, CHAR_MAX);
    printf("  short: %d a %d\n", SHRT_MIN, SHRT_MAX);
    printf("  int:   %d a %d\n", INT_MIN, INT_MAX);
    printf("  long:  %ld a %ld\n", LONG_MIN, LONG_MAX);
    
    printf("\nLimites dos tipos unsigned:\n");
    printf("  unsigned char:  0 a %u\n", UCHAR_MAX);
    printf("  unsigned short: 0 a %u\n", USHRT_MAX);
    printf("  unsigned int:   0 a %u\n", UINT_MAX);
    printf("  unsigned long:  0 a %lu\n", ULONG_MAX);
    
    /* Demonstração de overflow */
    printf("\n=== DEMONSTRAÇÃO DE OVERFLOW ===\n");
    unsigned char uc = 255;
    signed char sc = 127;
    
    printf("unsigned char uc = 255\n");
    printf("uc + 1 = %u\n", (unsigned char)(uc + 1));  /* wrap around para 0 */
    
    printf("\nsigned char sc = 127\n");
    printf("sc + 1 = %d\n", (signed char)(sc + 1));     /* overflow para -128 */
    
    /* Tipos de ponto flutuante */
    printf("\n=== TIPOS DE PONTO FLUTUANTE ===\n");
    printf("float:  %lu bytes, %d dígitos de precisão\n", 
           sizeof(float), FLT_DIG);
    printf("double: %lu bytes, %d dígitos de precisão\n", 
           sizeof(double), DBL_DIG);
    
    /* Demonstração de precisão */
    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;
    
    printf("\nDemonstração de precisão:\n");
    printf("1/3 como float:  %.20f\n", f);
    printf("1/3 como double: %.20f\n", d);
    
    return 0;
}
