#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  struct stat mf_data;
  stat("makefile", &mf_data);

  printf("File size: %lld\nPermissions: %o\nLast accessed: %ld\n", mf_data.st_size, mf_data.st_mode, mf_data.st_atime);
  return 0;
}
