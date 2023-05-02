#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "lib.h"
 
int main() {
    const char *path = "/path/to/directory";
    double size = get_directory_size(path);

    if (size == 0) {
        printf("Directory %s is empty\n", path);
    } else {
        printf("Directory %s size is %.2f bytes\n", path, size);
        if (size >= 1024 * 1024 * 1024) {
            printf("Directory %s size is %.2f GB\n", path, size / (1024 * 1024 * 1024));
        } else if (size >= 1024 * 1024) {
            printf("Directory %s size is %.2f MB\n", path, size / (1024 * 1024));
        } else if (size >= 1024) {
            printf("Directory %s size is %.2f KB\n", path, size / 1024);
        }
    }
    return 0;
}