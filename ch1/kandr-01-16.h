#ifndef KANDR_01_16
#define KANDR_01_16

#define DEFAULT_BUFSIZE 100
int kandr_getline(FILE* stream, char** line, int* buf_size);
int longest_line(FILE* stream, char** line);

#endif

