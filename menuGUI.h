#include <ncurses.h>
#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#include <omp.h>
#include <termios.h>
#include <stdio.h>
#include <pthread.h>

void menuDuracion();
void menureceptor();
void menutransmisor();
void gen_tones();
void *menu();

int Fs;
int send;  
float **buffer_2048;
float **buffer_11793;
float **buffer_22562;
float **buffer_33331;
float **buffer_44100;
int ch, ch1;
int mode;
int durationdefaultsize;
int BUFFER_LEN;
