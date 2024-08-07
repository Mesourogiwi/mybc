#include <lexer.h>
#include <parser.h>
int lookahead;
/*
LL(1) grammar

E -> T R
T -> F Q
F -> (E) | DEC | ID
R -> +T R | -T R | <>
Q -> *F Q | /F Q | <>
*/

// E -> T R
void E(void) { T(); R(); }

// T -> F Q
void T(void) { F(); Q(); }

//F -> (E) | DEC | ID
void F(void) {
    switch(lookahead) {
        case '(':
            match('('); E(); match(')');
            break;
        case DEC:
            match(DEC);
            break;
        default:
            match(ID);
    }
}

//R -> +T R | -T R | <>
void R(void) {
        switch(lookahead) {
        case '+':
            match('+'); T(); R();
            break;
        case '-':
            match('-'); T(); R();
            break;
        default:
            ;
    }
}

//Q -> *F Q | /F Q | <>
void Q(void) {
        switch(lookahead) {
        case '*':
            match('*'); T(); R();
            break;
        case '/':
            match('/'); T(); R();
            break;
        default:
            ;
    }
}

void match(int expected) {
    if (lookahead == expected) {
        lookahead = gettoken(source);
    } else {
        fprintf(stderr, "token mismatch");
        exit(-3);
    }
}