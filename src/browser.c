#include "browser.h"
#include "exit.h"
#include "util.h"
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

void openlink(char *link) {
// Windows implementation
#if defined(_WIN32) || defined(_WIN64)
  ShellExecute(NULL, "open", link, NULL, NULL, SW_SHOWNORMAL);

// Linux implementation
#elif defined(__linux__)
  char *flink = repl_str("xdg-open \"<link>\"", "<link>", link);
  system(flink);
  free(flink);

// MacOS implementation
#elif defined(__APPLE__)
  char *flink = repl_str("xdg-open \"<link>\"", "<link>", link);
  system(flink);
  free(flink);

// BSD implementation
#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
  char *flink = repl_str("xdg-open \"<link>\"", "<link>", link);
  system(flink);
  free(flink);

// If OS is unsupported exit
#else
  exit(UNSUPPORTED_OS);

#endif
}
