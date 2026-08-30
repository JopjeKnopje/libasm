#ifndef LIBASM_H
#define LIBASM_H

#include <stdint.h>
#include <sys/types.h>

ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, const void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
char* ft_strcpy(char *dest, const char *src);
#endif
