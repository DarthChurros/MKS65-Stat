#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  printf("%u\n", 7<<1);
  struct stat mf_data;
  stat("makefile", &mf_data);
  printf("File size: %lld B\n", mf_data.st_size);

  printf("Permissions: ");
  char full_perms[] = "rwxrwxrwx";
  char perms[10];
  int i;
  int j = 1;
  for (i = 0; i < 9; i++) {
    perms[sizeof(mode_t) * 4 - i] = '-';
    if (j & mf_data.st_mode) {
      perms[sizeof(mode_t) * 4 - i] = full_perms[sizeof(mode_t) * 4 - i];
    }
    j = j << 1;
  }

  printf("%s\n", perms);

  printf("Last accessed: %s\n", ctime(&mf_data.st_atime));
  return 0;
}
