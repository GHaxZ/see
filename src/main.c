#include "./search.h"
#include "./util.h"
#include "browser.h"
#include "exit.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  printf("%s\n", goosrch("how to do a backflip"));
  printf("%s\n", ddgsrch("what is 2 + 2"));
  printf("%s\n", bravesrch("why did I decide to write this crap in C"));

  openlink(goosrch("Please open google :)"));
  openlink(ddgsrch("Please open duckduckgo :)"));
  openlink(bravesrch("Please open brave :)"));

  return SUCCESS;
}
