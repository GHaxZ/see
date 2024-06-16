#include "./search.h"
#include "./engines.h"
#include "./util.h"
#include <stdlib.h>

char *goosrch(char *query) {
  char *srchstr = buildsrchstr(query, google.separator);
  return repl_str(google.search_query, QUERY_PLACEHOLDER, srchstr);
}

char *ddgsrch(char *query) {
  char *srchstr = buildsrchstr(query, duckduckgo.separator);
  return repl_str(duckduckgo.search_query, QUERY_PLACEHOLDER, srchstr);
}

char *bravesrch(char *query) {
  char *srchstr = buildsrchstr(query, brave.separator);
  return repl_str(brave.search_query, QUERY_PLACEHOLDER, srchstr);
}

char *buildsrchstr(char *query, char separator) {
  char *temp;
  char *srchstr = (char *)malloc(1); // Allocate initial memory for the string
  srchstr[0] = '\0';                 // Initialize the string

  for (temp = query; *temp != '\0'; temp++) {
    if (*temp == ' ') {
      srchstr = appendc(srchstr, separator);
    } else {
      srchstr = appendc(srchstr, *temp);
    }
  }

  return srchstr;
}
