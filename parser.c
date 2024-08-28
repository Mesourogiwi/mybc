#include <lexer.h>
#include <parser.h>
int lookahead;

void E(void)
{
    if (lookahead == '+' || lookahead == '-')
    {
        match(lookahead);
    }
_T:

_F:
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

void match(int expected)
{
    if (lookahead == expected)
    {
        lookahead = gettoken(source);
    }
    else
    {
        fprintf(stderr, "token mismatch at line %d\n", linenum);
        exit(-3);
    }
}
