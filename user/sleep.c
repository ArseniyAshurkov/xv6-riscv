// Shell.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

// Parsed command representation
int
main(int argc, char *argv[])
{
  int ticks = atoi(argv[1]);
  sleep(ticks);
  exit(0);
}