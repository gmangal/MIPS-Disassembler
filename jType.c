// author: Gaurav Mangal

#include "disAssemble.h"

/* jType processes J-format instructions. J-format instructions only have a 
 * 6 bit opcode and a 26 bit target. The 26 bit target becomes a 32 bit 
 * address. This happens by appending two 0s to the end of the target so they 
 * become to least significant bits and appending the 4 most significant bits 
 * of the program counter to the top of the target so they become to most 
 * significant bits.
 *
 * Returns void
 */
void
jType(int PC, struct JFormat jInstruct)
{
    int fullTarget = jInstruct.target;
    fullTarget = fullTarget << 2;
    int mask = 0x10000000;
    mask = mask & PC;
    fullTarget = fullTarget | mask;

    printf("0x%08X ", PC);
    printf("%-8s ", jInstruct.opCode == 2 ? "j" : "jal");
    printf("0x%08X\n", fullTarget);

    return;
} // function jType
