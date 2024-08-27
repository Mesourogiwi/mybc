#include <lexer.h>
#include <parser.h>
int lookahead;

/*
LL(1) grammar:

E -> ['+'|'-'] T R
T -> F Q
F -> (E) | DEC | ID
R -> +T R | -T R | <>
Q -> *F Q | /F Q | <>
*/

// E -> [oplus] T
void E(void)
{
    if (lookahead == '+' || lookahead == '-')
    {
        match(lookahead);
    }
_T:
_F:
    F();
    if (lookahead == '*' || lookahead == '/')
    {
        match(lookahead);
        goto _F;
    }
    if (lookahead == '+' || lookahead == '-')
    {
        match(lookahead);
        goto _T;
    }
}

// F -> (E) | DEC | ID
void F(void)
{
    switch (lookahead)
    {
    case '(':
        match('(');
        E();
        match(')');
        break;
    case HEX:
        match(HEX);
        break;
    case OCT:
        match(OCT);
        break;
    case DEC:
        match(DEC);
        break;
    default:
        match(ID);
    }
}

void match(int expected)
{
    if (lookahead == expected)
    {
        lookahead = gettoken(source);
    }
    else
    {
        fprintf(stderr, "token mismatch\n");
        exit(-3);
    }
}
