#include <lexer.h>
#include <ctype.h>
#include <stdio.h>

// ID = [A-Za-z][A-Za-z0-9]*
// Ex> abacaXI123
int isID(FILE *tape) {
    int head = getc(tape);

    if(isalpha(head)) {
        while(isalnum(head = getc(tape)));
        ungetc(head, tape);
        return ID;
    }

    ungetc(head, tape);
    return 0;
}

int gettoken(FILE *source) {
    if (isID(source)) printf("It's an ID\n");
    else printf("Not found\n");
}