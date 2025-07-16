/*******************************************************************
 * Script 2: Constantes e Enumerações
 * Demonstra: Diferentes formas de constantes, escape sequences e enums
 * Executar em: https://www.onlinegdb.com/
 *******************************************************************/

#include <stdio.h>

#define PI 3.14159265359
#define MAX_BUFFER 1024
#define NEWLINE '\n'
#define MESSAGE "Hello, World!"

/* Enumerações do K&R */
enum boolean { NO, YES };

enum escapes { 
    BELL = '\a', 
    BACKSPACE = '\b', 
    TAB = '\t',
    VTAB = '\v',
    RETURN = '\r' 
};

enum months { 
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC 
};

int main() {
    printf("=== CONSTANTES INTEIRAS ===\n");
    
    /* Mesma constante em diferentes bases */
    printf("Decimal 31:     %d\n", 31);
    printf("Octal 037:      %d\n", 037);
    printf("Hex 0x1F:       %d\n", 0x1F);
    printf("Hex 0x1f:       %d\n", 0x1f);
    
    /* Sufixos de tipo */
    printf("\n=== SUFIXOS DE TIPO ===\n");
    printf("42:    tipo int,           valor %d\n", 42);
    printf("42L:   tipo long,          valor %ld\n", 42L);
    printf("42U:   tipo unsigned,      valor %u\n", 42U);
    printf("42UL:  tipo unsigned long, valor %lu\n", 42UL);
    
    /* Constantes de caractere */
    printf("\n=== CONSTANTES DE CARACTERE ===\n");
    printf("'A':    valor decimal %d, caractere '%c'\n", 'A', 'A');
    printf("'\\n':   valor decimal %d (newline)\n", '\n');
    printf("'\\t':   valor decimal %d (tab)\n", '\t');
    printf("'\\x41': valor decimal %d, caractere '%c'\n", '\x41', '\x41');
    printf("'\\101': valor decimal %d, caractere '%c'\n", '\101', '\101');
    
    /* A diferença crítica entre char e string */
    printf("\n=== 'x' vs \"x\" ===\n");
    printf("'x':  é um int com valor %d\n", 'x');
    printf("\"x\": é um array de %lu chars\n", sizeof("x"));
    
    /* Concatenação de strings */
    printf("\n=== CONCATENAÇÃO DE STRINGS ===\n");
    char *msg = "Hello, " "World" "!";  /* compile-time concatenation */
    printf("Três strings viram uma: %s\n", msg);
    
    /* Enumerações */
    printf("\n=== ENUMERAÇÕES ===\n");
    enum boolean done = NO;
    printf("NO = %d, YES = %d\n", NO, YES);
    printf("JAN = %d, FEB = %d, DEC = %d\n", JAN, FEB, DEC);
    printf("BELL = %d, TAB = %d\n", BELL, TAB);
    
    /* Escape sequences em ação */
    printf("\n=== ESCAPE SEQUENCES ===\n");
    printf("Bell: \a(você pode não ouvir no browser)\n");
    printf("Tab:\tTexto\ttabulado\n");
    printf("Quotes: \"aspas duplas\" e \'aspas simples\'\n");
    printf("Backslash: \\\n");
    
    return 0;
}
