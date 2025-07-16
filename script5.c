/*******************************************************************
 * Script 5: Incremento, Decremento e Operadores de Atribuição
 * Demonstra: Pré/pós incremento e funções clássicas do K&R
 * Executar em: https://www.onlinegdb.com/
 *******************************************************************/

#include <stdio.h>
#include <string.h>

/* squeeze: remove todos os c de s - K&R p.47 */
void squeeze(char s[], int c) {
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* strcat: concatena t ao fim de s - K&R p.48 */
void my_strcat(char s[], char t[]) {
    int i, j;
    
    i = j = 0;
    while (s[i] != '\0')  /* encontra fim de s */
        i++;
    while ((s[i++] = t[j++]) != '\0')  /* copia t */
        ;
}

int main() {
    printf("=== PRÉ vs PÓS INCREMENTO/DECREMENTO ===\n");
    
    int n = 5;
    int a, b;
    
    printf("n inicial = %d\n\n", n);
    
    /* Pós-incremento */
    a = n++;
    printf("a = n++:  a = %d, n = %d (usa n, depois incrementa)\n", a, n);
    
    /* Pré-incremento */
    b = ++n;
    printf("b = ++n:  b = %d, n = %d (incrementa n, depois usa)\n", b, n);
    
    /* Com decremento */
    printf("\nn = %d\n", n);
    a = n--;
    printf("a = n--:  a = %d, n = %d\n", a, n);
    b = --n;
    printf("b = --n:  b = %d, n = %d\n", b, n);
    
    /* Em contexto onde só o efeito importa */
    printf("\n=== QUANDO NÃO FAZ DIFERENÇA ===\n");
    int i;
    printf("for com i++: ");
    for (i = 0; i < 5; i++)
        printf("%d ", i);
    
    printf("\nfor com ++i: ");
    for (i = 0; i < 5; ++i)
        printf("%d ", i);
    printf("\n(Resultado idêntico!)\n");
    
    /* Demonstração da função squeeze */
    printf("\n=== FUNÇÃO squeeze DO K&R ===\n");
    char str1[] = "Hello, World!";
    printf("Original: \"%s\"\n", str1);
    squeeze(str1, 'l');
    printf("Após squeeze(str, 'l'): \"%s\"\n", str1);
    
    /* A elegância do pós-incremento em squeeze */
    char str2[] = "programming";
    printf("\nProcesso de squeeze(\"programming\", 'm'):\n");
    int j = 0;
    for (i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != 'm') {
            printf("  str[%d] = str[%d] ('%c')\n", j, i, str2[i]);
            str2[j++] = str2[i];
        }
    }
    str2[j] = '\0';
    printf("Resultado: \"%s\"\n", str2);
    
    /* Operadores de atribuição compostos */
    printf("\n=== OPERADORES DE ATRIBUIÇÃO ===\n");
    int x = 10;
    printf("x = %d\n", x);
    
    x += 5;   printf("x += 5:   x = %d\n", x);
    x -= 3;   printf("x -= 3:   x = %d\n", x);
    x *= 2;   printf("x *= 2:   x = %d\n", x);
    x /= 4;   printf("x /= 4:   x = %d\n", x);
    x %= 5;   printf("x %%= 5:   x = %d\n", x);
    
    /* Com bitwise */
    unsigned y = 0xFF;
    printf("\ny = 0x%02X\n", y);
    y &= 0x0F;  printf("y &= 0x0F:  y = 0x%02X\n", y);
    y |= 0x30;  printf("y |= 0x30:  y = 0x%02X\n", y);
    y >>= 2;    printf("y >>= 2:    y = 0x%02X\n", y);
    
    /* Demonstração de strcat */
    printf("\n=== FUNÇÃO strcat (NOSSA VERSÃO) ===\n");
    char dest[50] = "Hello, ";
    char src[] = "World!";
    
    printf("Antes:  dest = \"%s\"\n", dest);
    printf("        src  = \"%s\"\n", src);
    my_strcat(dest, src);
    printf("Depois: dest = \"%s\"\n", dest);
    
    /* O perigo da ordem de avaliação */
    printf("\n=== CUIDADO: ORDEM INDEFINIDA ===\n");
    int arr[5] = {10, 20, 30, 40, 50};
    i = 2;
    /* NÃO FAÇA ISSO: */
    /* arr[i] = i++; */  /* Comportamento indefinido! */
    printf("arr[i] = i++ é INDEFINIDO - não use!\n");
    
    return 0;
}
