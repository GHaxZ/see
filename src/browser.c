#include "browser.h"
#include "util.h"
#include <stdlib.h>

void openlink(char *link) {
// Windows implementation
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
  ShellExecute(NULL, "open", link, NULL, NULL, SW_SHOWNORMAL);
#endif

// Linux and MacOS implementation
#if defined(__linux__) || defined(__APPLE__)
  char *flink = repl_str("xdg-open \"<LINK>\"", "<LINK>", link);
  system(flink);
  free(flink); // Free dynamically allocated memory
#endif
}
