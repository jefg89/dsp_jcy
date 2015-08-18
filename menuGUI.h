#include <ncurses.h>
#define BUFFER_LEN 8192

void menutransmisor();
void gen_tones(int buffer_size, int digit, int Fs, float* input);
void *menu();

int Fs;
int send;  
float buffer [BUFFER_LEN];
int ch1;
