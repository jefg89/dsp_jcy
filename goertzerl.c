#include <stdlib.h>  
#include <stdio.h>
#include <math.h>

# define pi 3.141592654
float goertzel(int N,int Ft,int Fs, float* input)
{
    int     k, i;
    float   floatN;
    float   omega, sine, cosine, q0, q1, q2, power;

    float   scalingFactor = N / 2.0;

    floatN = (float) N;
    k = (int) (0.5 + ((floatN * Ft) / Fs));
    omega = (2.0 * pi * k) / floatN;
    sine = sin(omega);
    cosine = 2.0 *cos(omega);

    q0=0;
    q1=0;
    q2=0;

    for(i=0; i<N; i++)
    {
        q0 = cosine * q1 - q2 + input[i];
        q2 = q1;
        q1 = q0;
    }

    power = (q2 *q2 + q1 * q1 - cosine * q1 * q2) / scalingFactor;
    return power;
}

int main(){

	int buffer_size = 64100;
	int Fs = 44100;
	float floatFs;

	floatFs = (float) Fs;
	
	float *input;
	input = (float *)malloc(buffer_size*sizeof(float));

	int i;

	for(i=0;i<buffer_size;i++){
		input[i] = 1*sin(2.0*pi*450.0*i/floatFs) + 2*sin(2.0*pi*925.0*i/floatFs);
	}

	printf("%f\n",goertzel(buffer_size,450,Fs, input));
	return 0;
}
