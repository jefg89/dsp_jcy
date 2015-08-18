#include <ncurses.h>
#define BUFFER_LEN 8192

void menutransmisor();
void gen_tones();
void *menu();

int Fs;
int send;  
float buffer[16] [BUFFER_LEN];
int ch1;
int digit;
