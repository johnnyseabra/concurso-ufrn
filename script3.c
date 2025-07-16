/*******************************************************************
 * Script 3: Conversões de Tipo e Cast
 * Demonstra: Conversões implícitas, explícitas e armadilhas
 * Executar em: https://www.onlinegdb.com/
 *******************************************************************/

#include <stdio.h>

/* Função atoi do K&R */
int atoi(char s[]) {
    int i, n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* Função lower do K&R (ASCII only) */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {
    printf("=== CONVERSÕES IMPLÍCITAS (AUTOMÁTICAS) ===\n");
    
    /* Promoção em expressões mistas */
    int i = 10;
    float f = 3.14f;
    double d = 2.718;
    
    printf("int %d + float %.2f = %.2f (tipo float)\n", i, f, i + f);
    printf("float %.2f + double %.3f = %.3f (tipo double)\n", f, d, f + d);
    
    /* A armadilha clássica da divisão inteira */
    printf("\n=== DIVISÃO INTEIRA vs FLOAT ===\n");
    int dividendo = 7, divisor = 2;
    
    printf("7 / 2 (ambos int)     = %d\n", dividendo / divisor);
    printf("7.0 / 2 (float / int) = %.2f\n", 7.0 / divisor);
    printf("(float)7 / 2          = %.2f\n", (float)dividendo / divisor);
    printf("7 / (float)2          = %.2f\n", dividendo / (float)divisor);
    
    /* Truncamento em atribuições */
    printf("\n=== TRUNCAMENTO EM ATRIBUIÇÕES ===\n");
    float pi = 3.14159;
    int truncated = pi;  /* perde parte fracionária */
    printf("float %.5f → int %d (perdeu .14159)\n", pi, truncated);
    
    /* Overflow em conversões */
    int big = 300;
    char small = big;  /* overflow! */
    printf("\nint %d → char %d (overflow!)\n", big, small);
    
    /* Conversões char ↔ int */
    printf("\n=== CONVERSÕES CHAR ↔ INT ===\n");
    char str[] = "12345";
    int num = atoi(str);
    printf("String \"%s\" → int %d (usando atoi)\n", str, num);
    
    char upper = 'H';
    char lower_c = lower(upper);
    printf("'%c' → '%c' (usando lower)\n", upper, lower_c);
    
    /* Demonstração do perigo signed/unsigned */
    printf("\n=== PERIGO: COMPARAÇÕES SIGNED/UNSIGNED ===\n");
    int neg = -1;
    unsigned int pos = 1;
    
    printf("-1 < 1U ? %s\n", (neg < pos) ? "true" : "false");
    /* Depende do tamanho dos tipos! */
    
    /* Hierarquia de conversão */
    printf("\n=== HIERARQUIA DE CONVERSÃO ===\n");
    printf("char → int → long → float → double\n");
    
    char c = 'A';
    int ic = c;        /* char para int */
    long lc = ic;      /* int para long */
    float fc = lc;     /* long para float */
    double dc = fc;    /* float para double */
    
    printf("'A' → %d → %ld → %.1f → %.1f\n", ic, lc, fc, dc);
    
    return 0;
}
