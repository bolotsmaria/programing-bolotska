#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "lib.h"

double get_directory_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    double size = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            size += get_directory_size(filepath);
        } else {
            size += (double) statbuf.st_size;
        }
    }
    closedir(dir);
    return size;
}
