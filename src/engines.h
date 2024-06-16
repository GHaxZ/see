#ifndef ENGINES_H
#define ENGINES_H

#define QUERY_PLACEHOLDER "<QUERY>"

// Store information for the google search engine
struct Google {
  char *search_query;
  char separator;
} google = {.search_query = "https://www.google.com/search?q=<QUERY>",
            .separator = '+'};

// Store information for the duckduckgo search engine
struct DuckDuckGo {
  char *search_query;
  char separator;
} duckduckgo = {.search_query = "https://duckduckgo.com/?q=<QUERY>",
                .separator = '+'};

// Store information for the brave search engine
struct Brave {
  char *search_query;
  char separator;
} brave = {.search_query = "https://search.brave.com/search?q=<QUERY>",
           .separator = '+'};
#endif // !ENGINES_H
