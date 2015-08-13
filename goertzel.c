#include "goertzel.h"

float goertzel(int N,int Ft,int Fs, float* input)
{
    int     k, i;
    float   floatN;
    float   omega, sine, cosine, q0, q1, q2, power;

    float   scalingFactor = N / 2.0;

    floatN = (float) N;
    k = (int) (0.5 + ((floatN * Ft) / Fs));
    omega = (2.0 * M_PI * k) / floatN;
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

int finding_freq(int buffer_size, int digit, int Fs, float* input)
{
	int freq_up, freq_down;
	switch ( digit ) {
        case 0:        
            freq_up = 1336; freq_down = 941;  
            break;
        case 1:
			freq_up = 1209; freq_down = 697;         
            break;
        case 2:          
            freq_up = 1336; freq_down = 697;
            break;
        case 3:         
            freq_up = 1477; freq_down = 697;
            break;
        case 4:        
            freq_up = 1209; freq_down = 770;
            break;
        case 5:        
            freq_up = 1336; freq_down = 770;
            break;
        case 6:        
            freq_up = 1477; freq_down = 770;
            break;
        case 7:        
            freq_up = 1209; freq_down = 852;
            break;
        case 8:        
            freq_up = 1336; freq_down = 852;
            break;
        case 9:        
            freq_up = 1477; freq_down = 852;
            break;
        case 10:   /* A */ 
            freq_up = 1633; freq_down = 697;
            break;
        case 11:   /* B */     
            freq_up = 1633; freq_down = 770;
            break;
        case 12:   /* C */     
            freq_up = 1633; freq_down = 852;
            break; 
        case 13:   /* D */    
            freq_up = 1333; freq_down = 941;
            break;
        case 14:   /* * */    
            freq_up = 1209; freq_down = 941;
            break;
        case 15:   /* # */      
            freq_up = 1477; freq_down = 941;
            break;
        default:   /*Any*/       
            freq_up = 0; freq_down = 0;
            break;
    }
    float g1, g2;
    #pragma omp parallel
    {
		g1 = goertzel(buffer_size, freq_up , Fs, input);
		g2 = goertzel(buffer_size, freq_down , Fs, input);
	}
    if ((g1>3000) & 
       ((g2>3000))){
    /*if ((goertzel(N, freq_up , Fs, input)>3000) & 
       ((goertzel(N, freq_down , Fs, input)>3000))){*/
		return 1;
	   }
	else
		return 0;
}
/*
int main(){

	int buffer_size = 96410000;
	int Fs = 44100;
	float floatFs;
	int digit =9;
	floatFs = (float) Fs;
	
	float *input;
	input = (float *)malloc(buffer_size*sizeof(float));
	int i;
	
	#pragma omp parallel for
	for(i=0;i<buffer_size;i++){
		input[i] = 1*sin(2.0*M_PI*1477.0*i/floatFs) + 2*sin(2.0*M_PI*852.0*i/floatFs);
	}
	if(finding_freq( buffer_size,  digit, Fs, input))
		printf("digito %d encontrado\n", digit);
	return 0;
}*/

