// author: Gaurav Mangal

#include "disAssemble.h"
#include <getopt.h>

/* processOpts processes the command line options. The user can set flags 
 * for processing R-format, I-format, J-format, or all instructions.
 *
 * Returns the number of options processed
 */
int
processOpts(int argc, char *argv[], int *rFormat, int *iFormat, int *jFormat)
{
    struct option longopts[] =
    {
        {"usage",       no_argument,    NULL, 'u'},
        {"Rformat",     no_argument,    NULL, 'r'},
        {"Iformat",     no_argument,    NULL, 'i'},
        {"Jformat",     no_argument,    NULL, 'j'},
        {"all",         no_argument,    NULL, 'a'},
        {NULL,          0,              NULL,  0 }
    };

    // name of the program, to be passed to the usage function
    char *progName = argv[0];

    // flags to be set
    *rFormat = 0;
    *iFormat = 0;
    *jFormat = 0;

    int ch;
    while ((ch = getopt_long(argc, argv, "rija", longopts, NULL)) != -1)
    {
        switch(ch)
        {
            case 'u':
                usage(argv[0], stdout);
            case 'r':
                *rFormat = 1;
                break;
            case 'i':
                *iFormat = 1;
                break;
            case 'j':
                *jFormat = 1;
                break;
            case 'a':
                *rFormat = 1;
                *iFormat = 1;
                *jFormat = 1;
                break;
            case '?':
            default:
                usage(progName, stderr);
                break;
        }
    }

    // return number of options processed
    return optind;
} // function processOpts
