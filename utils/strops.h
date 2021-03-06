/*
 *  utils/strops.h
 * 
 *  Copyleft (C) 2015  Sun Dro (a.k.a. kala13x)
 *
 * This header includes string operations.
 */


/* For include header in CPP code */
#ifdef __cplusplus
extern "C" {
#endif


/*
 * strsrc - Search string in another string. If string is 
 * found, function returns 1, else 0 or -1. Argument str is 
 * string to search and srch is string we want search for.
 */
int strsrc(char *str, char *srch);


/*
 * strrep - Replace string with another string in whole buffer. Argument 
 * orig is whole buffer, rep is string which we want to replace and with 
 * is new string which we want to save. Return value is whole buffer with 
 * replaced strings, it must be freed with free() after usage.
 */
char *strrep(char *orig, char *rep, char *with);


/* For include header in CPP code */
#ifdef __cplusplus
}
#endif