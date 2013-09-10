// author: Gaurav Mangal

#include "disAssemble.h"

/* disAssemble is (surprise) a disassembler for MIPS code. It takes binary 
 * dumps from spim as input and turns them into MIPS instructions based on 
 * a limited set of instructions. The user can set flags for whether they 
 * want R-format, I-format, J-format, or all instructions to be disassembled. 
 *
 * The program uses a different struct to represent each instruction type (and 
 * two structs to represent I-format because some I-format instructions treat 
 * the immediate field as a signed int and others treat it as an unsigned int). 
 * All these structs become part of a union. The program uses fread to read 
 * 32 bits into this union at a time. Each read represents one instruction.
 *
 * Separate functions process the binary form of the instructions. These 
 * functions determine which registers are being referenced (taken from the 
 * spim appendix) and performs calculations to determine target addresses 
 * for branches and jumps.
 */
int
main(int argc, char *argv[])
{
    // name of the program, to be passed into usage function
    char *progName = argv[0];

    // flags for options the user sets
    int rFormat;
    int iFormat;
    int jFormat;

    // number of options processed
    int optind;
    optind = processOpts(argc, argv, &rFormat, &iFormat, &jFormat);

    // decrement number of options processed and increment argv so it points 
    // to the arguments after the options (i.e. the file names)
    argc -= optind;
    argv += optind;

    if (argc == 0)
    {
        // no file name on command line
        fprintf(stderr, "Missing file name\n");
        usage(progName, stderr);
    }

    // holds each instruction as it is read
    union Instruction instruct;

    // i is a loop control variable, programCounter keeps track of the 
    // address of the current instruction. Always starts at 0x 0040 0024
    int i, programCounter;
    for (i = 0; i < argc; i++)
    {
        // print file name
        printf("File '%s' contains:\n", argv[i]);

        // address of first instruction in program
        programCounter = 0x00400024;

        // open the file
        FILE *inputFile;
        inputFile = fopen(argv[i], "r");
        if (inputFile == NULL)
        {
            fprintf(stderr, "Unable to open %s for reading\n", argv[0]);
            usage(progName, stderr);
        }

        // process file
        while (!feof(inputFile))
        {
            // fread returns the number of items it reads, it is being told 
            // to only read one item, so it will keep returning 1 until it 
            // has nothing left to read
            while ((fread(&instruct, sizeof(struct RFormat), 1, inputFile)) 
                    == 1)
            {
                int currentOpCode = instruct.rInstruct.opCode;
                switch(currentOpCode)
                {
                    case 0:
                        // R format, only process if flag is set
                        if (rFormat)
                            rType(programCounter, instruct.rInstruct);
                        break;
                    case 2:
                    case 3:
                        // J format, only process if flag is set
                        if (jFormat)
                            jType(programCounter, instruct.jInstruct);
                        break;
                    default:
                        // I format, only process if flag is set
                        if (iFormat)
                            iType(programCounter, &instruct);
                        break;
                }
                // increment PC before going to next instruction
                programCounter += 0x4;
            }
        }
        printf("\n");

        // close the file
        int result;
        result = fclose(inputFile);
        if (result != 0)
        {
            fprintf(stderr, "Error closing the file\n");
            exit(2);
        }
    }

    return 0;
} // main

/* usage prints information about how to use the program. It can printed to 
 * any file, most commonly stdout or stderr.
 */
void
usage(char *progName, FILE *file)
{
    fprintf(file, "Usage: %s [-r] [-i] [-j] [-a] file [file ...]\n", progName);
    fprintf(file, "  %-13s print this information and exit\n", "--usage");
    fprintf(file, "  %-13s disassemble R-format instructions\n", 
            "-r --Rformat");
    fprintf(file, "  %-13s disassemble I-format instructions\n", 
            "-i --Iformat");
    fprintf(file, "  %-13s disassemble J-format instructions\n", 
            "-j --Jformat");
    fprintf(file, "  %-13s disassemble all instructions\n", 
            "-a --all");

    if (file == stdout)
        exit(0);
    else
        exit(1);
} // function usage
