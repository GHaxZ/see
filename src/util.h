#ifndef UTIL_H
#define UTIL_H
// Append a character to a string
char *appendc(char *str, char c);

// Append a string to another string
char *appendstr(char *str, char *app);

void *arrappend(void *arr, void *app);

// Replace the all occurrences of a string within another string with the
// specified string
char *repl_str(char *str, char *from, char *to);

#endif // !UTIL_H
