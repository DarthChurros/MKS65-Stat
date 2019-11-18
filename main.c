#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat mf_data;
  stat("makefile", &mf_data);
  printf("File size: %lld B\n", (long long)(mf_data.st_size));

  printf("Permissions: ");
  char perms[11];
  strcpy(perms, "-rwxrwxrwx");
  int i;
  int j = 1;
  for (i = 0; i < 9; i++) {
    if (!(j & mf_data.st_mode)) {
      perms[9 - i] = '-';
    }
    j = j << 1;
  }

  printf("%s\n", perms);

  printf("Last accessed: %s\n", ctime(&mf_data.st_atime));
  return 0;
}
