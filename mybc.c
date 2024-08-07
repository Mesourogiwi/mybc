#include <stdio.h>
#include <parser.h>
#include <lexer.h>

FILE *source;

int main() {
    source = stdin;
    lookahead = gettoken(source);
    return 0;
}