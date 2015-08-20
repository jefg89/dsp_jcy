#include <stdlib.h> 
#include <alsa/asoundlib.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#define BUFFER_LEN 1024

#define TH 50

int ch, ch1;
float buffer_f [BUFFER_LEN];
float buffer_s [BUFFER_LEN];
int freq_up, freq_down;
snd_pcm_t *handle_w;
snd_pcm_t *handle_r;
int Fs;
int digit;
int sync_;

pthread_mutex_t mutex_f, mutex_s, mutex_w1, mutex_w2;

float goertzel(int N,int Ft, float* input);
void *finding_freq();
void *write_();
unsigned long get_time_usec();
