#include <stdlib.h> 
#include <alsa/asoundlib.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#define BUFFER_LEN 1024

#define TH 100
int mode;
int ch, ch1;
float buffer_f [2048];
float buffer_s [2048];
int freq_up, freq_down;
snd_pcm_t *handle_w;
snd_pcm_t *handle_r;
int Fs;
int digit;
int sync_;
int num_det;
int dial_num[8];
clock_t start, end;
int num_jef[8];

pthread_t tkc, thread1, thread2;

pthread_mutex_t mutex_f, mutex_s, mutex_w1, mutex_w2;

float goertzel(int N,int Ft, float* input);
void *finding_freq();
void *write_();
unsigned long get_time_usec();
void set_station();
