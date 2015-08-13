#include <stdlib.h>  
#include <stdio.h>
#include <math.h>
#include <omp.h>

float goertzel(int N,int Ft,int Fs, float* input);
int finding_freq(int buffer_size, int digit, int Fs, float* input);
