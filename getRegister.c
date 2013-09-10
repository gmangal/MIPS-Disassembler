// author: Gaurav Mangal

#include "disAssemble.h"

/* getRegister takes a regber representing a register and turns it into 
 * the string representation of that register based on the table in the 
 * spim appendix. For example, register 31's string form is $ra. The string 
 * form is placed into the char array that is passed in as a parameter so 
 * that the string can be used elsewhere in the program.
 *
 * Returns void
 */
void 
getRegister(int reg, char regName[6])
{
    switch (reg)
    {
        case 0:
            sprintf(regName, "$zero");
            break;
        case 1:
            sprintf(regName, "$at");
            break;
        case 2:
            sprintf(regName, "$v0");
            break;
        case 3:
            sprintf(regName, "$v1");
            break;
        case 4:
            sprintf(regName, "$a0");
            break;
        case 5:
            sprintf(regName, "$a1");
            break;
        case 6:
            sprintf(regName, "$a2");
            break;
        case 7:
            sprintf(regName, "$a3");
            break;
        case 8:
            sprintf(regName, "$t0");
            break;
        case 9:
            sprintf(regName, "$t1");
            break;
        case 10:
            sprintf(regName, "$t2");
            break;
        case 11:
            sprintf(regName, "$t3");
            break;
        case 12:
            sprintf(regName, "$t4");
            break;
        case 13:
            sprintf(regName, "$t5");
            break;
        case 14:
            sprintf(regName, "$t6");
            break;
        case 15:
            sprintf(regName, "$t7");
            break;
        case 16:
            sprintf(regName, "$s0");
            break;
        case 17:
            sprintf(regName, "$s1");
            break;
        case 18:
            sprintf(regName, "$s2");
            break;
        case 19:
            sprintf(regName, "$s3");
            break;
        case 20:
            sprintf(regName, "$s4");
            break;
        case 21:
            sprintf(regName, "$s5");
            break;
        case 22:
            sprintf(regName, "$s6");
            break;
        case 23:
            sprintf(regName, "$s7");
            break;
        case 24:
            sprintf(regName, "$t8");
            break;
        case 25:
            sprintf(regName, "$t9");
            break;
        case 26:
            sprintf(regName, "$k0");
            break;
        case 27:
            sprintf(regName, "$k1");
            break;
        case 28:
            sprintf(regName, "$gp");
            break;
        case 29:
            sprintf(regName, "$sp");
            break;
        case 30:
            sprintf(regName, "$fp");
            break;
        case 31:
            sprintf(regName, "$ra");
            break;
    }

    return;

} // function getRegister
