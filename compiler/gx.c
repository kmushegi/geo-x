/*
 *  compiler/gx.h
 * 
 *  Copyleft (C) 2015  Geo-X Team
 *
 * Main source file of იქ-C compilator. 
 */


/* Util includes */
#include "../utils/stdinc.h"
#include "../utils/strops.h"
#include "../utils/errex.h"
#include "../utils/slog.h"
#include "../utils/info.h"

/* Local includes */
#include "mdefs.h"
#include "parser.h"


/* Files */
typedef struct {
    char input[PATH_MAX];
    char output[PATH_MAX];
} UserInputX;


/* 
 * init_uix - Initialize user input struct variables.
 * Argument uix is pointer of UserInputX structure.
 */
void init_uix(UserInputX *uix)
{
    bzero(uix->input, sizeof(uix->input));
    bzero(uix->output, sizeof(uix->output));
    strcpy(uix->output, "შედეგი");
}


/* 
 * parse_arguments - Parse arguments from user input.
 * Argument uix is pointer of UserInputX structure.
 */
static int parse_arguments(int argc, char *argv[], UserInputX *uix)
{
    int c;
    while ( (c = getopt(argc, argv, "i:o:h1")) != -1) {
        switch (c) {
        case 'i':
            strcpy(uix->input, optarg);
            break;
        case 'o':
            strcpy(uix->output, optarg);
            break;
        case 'h':
        default:
            usage(argv[0]);
            return -1;
        }
    }

    return 0;
}


/* Main function of compiler */
int main(int argc, char *argv[]) 
{
    /* Used variables */
    UserInputX uix;

    /* Greet users */
    greet("იქ->C კომპილატორი");

    /* Initialize user input vars */
    init_uix(&uix);

    /* Check valid args */
    if (argv[1] == NULL) 
    {
        slog(0, SLOG_ERROR, "მიუთითეთ დასაკომპილირებელი ფაილი.");
        usage(argv[0]);
        return 0;
    }

    /* Parse Commandline Arguments */
    if (parse_arguments(argc, argv, &uix)) return 0;

    /* Some debug line */
    slog(0, SLOG_LIVE, "მიმდინარეობს კომპილაცია: %s -> %s", uix.input, uix.output);
}