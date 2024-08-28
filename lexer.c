#include <ctype.h>
#include <stdio.h>
#include <lexer.h>

#define MAXIDLEN 32

char lexeme[MAXIDLEN + 1];
// ID = [A-Za-z][A-Za-z0-9]*
// Ex: abacaXI123
int isID(FILE *tape)
{
	int head = getc(tape);

	if (isalpha(head))
	{
		while (isalnum(head = getc(tape)))
			;
		ungetc(head, tape);
		return ID;
	}

	ungetc(head, tape);
	return 0;
}

// DEC = [1-9][0-9]* | 0
// 1234567890
// 0012 = 0 0 12
int isDEC(FILE *tape)
{
	int head = getc(tape);

	if (isdigit(head))
	{
		if (head == '0')
		{
			printf("dec");
			return DEC;
		}
		while (isdigit(head = getc(tape)))
			;
		ungetc(head, tape);
		return DEC;
	}
	ungetc(head, tape);
	return 0;
}

// ^[0][xX]?[0-9a-fA-F]+$
int isHEX(FILE *tape)
{
	int head = getc(tape);

	if (isdigit(head))
	{
		if (head == '0')
		{

			head = getc(tape);

			if (head == 'x' || head == 'X')
			{
				while (isxdigit(head = getc(tape)))
					;
				ungetc(head, tape);
				printf("é um hexadecimal\n");
				return HEX;
			}
			ungetc(head, tape);
		}
	}
	ungetc('0', tape);
	return 0;
}

// ^0[oO]?[0-7]+$
int isOCT(FILE *tape)
{
	int head = getc(tape);

	if (head == '0')
	{

		head = getc(tape);

		if (head == 'o' || head == 'O')
		{
			while (head >= '0' && head <= '7')
				head = getc(tape);
			ungetc(head, tape);
			printf("é um octadecimal\n");
			return OCT;
		}
		ungetc(head, tape);
	}
	ungetc('0', tape);
	return 0;
}

void skipspaces(FILE *tape)
{
	int head;

	while (isspace(head = getc(tape)))
	{
		if (head == '\n')
		{
			linenum++;
		}
	};

	ungetc(head, tape);
}

int gettoken(FILE *source)
{
	int token;
	skipspaces(source);
	if ((token = isID(source)))
		return token;
	if ((token = isHEX(source)))
		return token;
	if ((token = isOCT(source)))
		return token;
	if ((token = isDEC(source)))
		return token;
	token = getc(source);
	return token;
}
