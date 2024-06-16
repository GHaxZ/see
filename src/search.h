#ifndef SEARCH_H
#define SEARCH_H
// Create a search string using google
char *goosrch(char *query);
// Create a search string using duckduckgo
char *ddgsrch(char *query);
// Create a search string using brave
char *bravesrch(char *query);

// Build a search string using the specified query and separator
char *buildsrchstr(char *query, char separator);

#endif // !SEARCH_H
