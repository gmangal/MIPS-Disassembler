// author: Gaurav Mangal

#include "disAssemble.h"

/* iType disassembles some I-format MIPS instructions. Unlike the functions 
 * for R-format and J-format instructions, this one has a pointer to a 
 * union as an argument instead of simply a struct. This is because iType has 
 * to distinguish between instructions that want a signed immediate value and 
 * instructions that want an unsigned immediate value. The struct for each 
 * situation is in the union, but the various cases determine which struct 
 * is necessary.
 *
 * The target for the branch instructions (beq and bne) is calculated by 
 * shifting the signed immediate value to the left 2 places and then adding 
 * it to the PC. No calculations are necessary for the other I-format 
 * instructions.
 *
 * Returns void
 */
void
iType(int PC, union Instruction *instruct)
{
    // print current program counter
    printf("0x%08X ", PC);

    // char arrays to hold the names of the two registers used in I-format 
    // instructions
    char rsReg[6];
    char rtReg[6];

    getRegister(instruct->iInstruct.rs, rsReg);
    getRegister(instruct->iInstruct.rt, rtReg);

    // temp is used for temporary calculations, imm is used for instructions 
    // that want an unsigned immediate value, immSigned is used for 
    // instructions that want a signed immediate value
    int temp;
    unsigned int imm = instruct->iInstruct.immediate;
    signed int immSigned = instruct->iInstructSigned.immediate;
    switch (instruct->iInstruct.opCode)
    {
        case 4:
            temp = immSigned;
            temp = temp << 2;
            temp = temp + PC;
            printf("%-8s %s, %s, 0x%08X\n", "beq", rsReg, rtReg, temp);
            break;
        case 5:
            temp = immSigned;
            temp = temp << 2;
            temp = temp + PC;
            printf("%-8s %s, %s, 0x%08X\n", "bne", rsReg, rtReg, temp);
            break;
        case 8:
            printf("%-8s %s, %s, ", "addi", rtReg, rsReg);
            printf("%d", immSigned);
            printf("\n");
            break;
        case 9:
            printf("%-8s %s, %s, %u\n", "addiu", rtReg, rsReg, imm);
            break;
        case 10:
            printf("%-8s %s, %s, %d\n", "slti", rtReg, rsReg, immSigned);
            break;
        case 12:
            printf("%-8s %s, %s, %u\n", "andi", rtReg, rsReg, imm);
            break;
        case 13:
            printf("%-8s %s, %s, %u\n", "ori", rtReg, rsReg, imm);
            break;
        case 14:
            printf("%-8s %s, %s, %u\n", "xori", rtReg, rsReg, imm);
            break;
        case 15:
            printf("%-8s %s, %u\n", "lui", rtReg, imm);
            break;
        case 32:
            printf("%-8s %s, %d(%s)\n", "lb", rtReg, immSigned, rsReg);
            break;
        case 33:
            printf("%-8s %s, %d(%s)\n", "lh", rtReg, immSigned, rsReg);
            break;
        case 35:
            printf("%-8s %s, %d(%s)\n", "lw", rtReg, immSigned, rsReg);
            break;
        case 40:
            printf("%-8s %s, %d(%s)\n", "sb", rtReg, immSigned, rsReg);
            break;
        case 41:
            printf("%-8s %s, %d(%s)\n", "sh", rtReg, immSigned, rsReg);
            break;
        case 43:
            printf("%-8s %s, %d(%s)\n", "sw", rtReg, immSigned, rsReg);
            break;
        default:
            break;
    }

    return;
} // function iType
