// header file for disAssemble

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct JFormat {
    signed int target:26;
    unsigned int opCode:6;
};

struct IFormat {
    unsigned int immediate:16;
    unsigned int rt:5;
    unsigned int rs:5;
    unsigned int opCode:6;
};

struct IFormatSigned {
    signed int immediate:16;
    unsigned int rt:5;
    unsigned int rs:5;
    unsigned int opCode:6;
};

struct RFormat {
    unsigned int funct:6;
    unsigned int shamt:5;
    unsigned int rd:5;
    unsigned int rt:5;
    unsigned int rs:5;
    unsigned int opCode:6;
};

union Instruction {
    struct RFormat rInstruct;
    struct IFormat iInstruct;
    struct IFormatSigned iInstructSigned;
    struct JFormat jInstruct;
};

// function prototypes
void usage(char *progName, FILE *file);
int processOpts(int argc, char *argv[], int *rFormat, int *iFormat, 
        int *jFormat);
void jType(int PC, struct JFormat jInstruct);
void iType(int PC, union Instruction *instruct);
void rType(int PC, struct RFormat rInstruct);
void getRegister(int reg, char regName[6]);
