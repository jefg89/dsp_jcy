#include <stdlib.h> 
#include <alsa/asoundlib.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define BUFFER_LEN 2048
#define TH 200

float buffer_f [BUFFER_LEN];
float buffer_s [BUFFER_LEN];
int Fs;
int digit;
int sync_;

float goertzel(int N,int Ft, float* input);
void *finding_freq();
unsigned long get_time_usec();
