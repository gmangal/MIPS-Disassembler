// author: Gaurav Mangal

#include "disAssemble.h"

/* rType processes a subset of R-format instructions. All of these instructions 
 * simply list out instructions (no immediate values or targets), so there 
 * are no extra calculations necessary.
 *
 * Returns void
 */
void
rType(int PC, struct RFormat rInstruct)
{
    // print current program counter
    printf("0x%08X ", PC);

    // char arrays to hold the names of the registers used by the current 
    // instruction
    char rsReg[6];
    char rtReg[6];
    char rdReg[6];

    getRegister(rInstruct.rs, rsReg);
    getRegister(rInstruct.rt, rtReg);
    getRegister(rInstruct.rd, rdReg);

    switch(rInstruct.funct)
    {
        case 0:
            printf("%-8s %s, %s, %u\n", "sll", rdReg, rtReg, rInstruct.shamt);
            break;
        case 2:
            printf("%-8s %s, %s, %u\n", "srl", rdReg, rtReg, rInstruct.shamt);
            break;
        case 3:
            printf("%-8s %s, %s, %u\n", "sra", rdReg, rtReg, rInstruct.shamt);
            break;
        case 8:
            printf("%-8s %s\n", "jr", rsReg);
            break;
        case 12:
            printf("%-8s \n", "syscall");
            break;
        case 32:
            printf("%-8s %s, %s, %s\n", "add", rdReg, rsReg, rtReg);
            break;
        case 33:
            printf("%-8s %s, %s, %s\n", "addu", rdReg, rsReg, rtReg);
            break;
        case 34:
            printf("%-8s %s, %s, %s\n", "sub", rdReg, rsReg, rtReg);
            break;
        case 35:
            printf("%-8s %s, %s, %s\n", "subu", rdReg, rsReg, rtReg);
            break;
        case 36:
            printf("%-8s %s, %s, %s\n", "and", rdReg, rsReg, rtReg);
            break;
        case 37:
            printf("%-8s %s, %s, %s\n", "or", rdReg, rsReg, rtReg);
            break;
        case 38:
            printf("%-8s %s, %s, %s\n", "xor", rdReg, rsReg, rtReg);
            break;
        case 39:
            printf("%-8s %s, %s, %s\n", "nor", rdReg, rsReg, rtReg);
            break;
        case 42:
            printf("%-8s %s, %s, %s\n", "slt", rdReg, rsReg, rtReg);
            break;
        case 43:
            printf("%-8s %s, %s, %s\n", "sltu", rdReg, rsReg, rtReg);
            break;
        default:
            break;

    }

    return;
} // function rType
