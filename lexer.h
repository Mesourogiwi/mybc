#include <stdio.h>

enum {
    ID = 1024,
    DEC,
    OCT,
    HEX,
};

//#define ID 1024
//#define DEC 1025
//#define OCT 1026
//#define HEX 1027
extern int linenum;
extern int gettoken(FILE *);