#include "./argparse.h"
#include "exit.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
// TODO: Include windows implementation
#include "./lib/getopt.h"
#else
#include <unistd.h>
#endif

// INFO: There is no cross platform library for getting cli args, so I have to
// to either implement my own or include a implementation for other platforms

// INFO: There seem to be implementations for windows, maybe use those:
// https://www.cnblogs.com/hustcat/articles/1516816.html
// https://github.com/Chunde/getopt-for-windows

// TODO: Write cli parser

static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"google", no_argument, 0, 'g'},
    {"duckduckgo", no_argument, 0, 'd'},
    {"brave", no_argument, 0, 'b'},
    {0, 0, 0, 0} // Terminate the array with a zero-filled entry
};

void parseargs(int argc, char *args[]) {
  // If there were no cli arguments supplied
  if (argc < 2) {
    usage(argc, args);
    exit(MISSING_ARGUMENTS);
  }

  int opt;
  int option_index = 0;

  while ((opt = getopt_long(argc, args, "hgdb", long_options, &option_index)) !=
         -1) {
    switch (opt) {
    case 'h':
      usage(argc, args);
      exit(SUCCESS);
      break;
    case 'g':
      printf("Search Google\n");
      break;
    case 'd':
      printf("Search DuckDuckGo\n");
      break;
    case 'b':
      printf("Search Brave\n");
      break;
    default:
      usage(argc, args);
      exit(MALFORMED_ARGUMENTS);
    }
  }
}

void usage(int argc, char *args[]) {
  printf("Usage for %s:"
         "\n\t[-h | --help] Display this help dialogue"
         "\n\t[-g | --google] Search with Google"
         "\n\t[-d | --duckduckgo] Search with DuckDuckGo"
         "\n\t[-b | --brave] Search with Brave",
         args[0]);
}
