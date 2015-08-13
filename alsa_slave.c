	#include "goertzel.h"
	#include <alsa/asoundlib.h>
	#define BUFFER_LEN 44100
	
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];
int Fs = 44100;

	int main (int argc, char *argv[])
	{
		int i;
		int k,j;
		int err;
		int frames_read=0;
		int digit = 2 ;
		
		snd_pcm_t *handle;
		snd_pcm_hw_params_t *hw_params;
		snd_pcm_t *slave;
		
	
		if ((err = snd_pcm_open (&handle, device, SND_PCM_STREAM_CAPTURE, 0)) < 0) {

			exit (1);
		}
		   
		
		if ((err = snd_pcm_set_params(handle,
                                  SND_PCM_FORMAT_FLOAT,
                                  SND_PCM_ACCESS_RW_INTERLEAVED,
                                  1,
                                  Fs,
                                  1,
                                  500000)) < 0) {   
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
                   }

		
	 if ((err = snd_pcm_open(&slave, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
		    printf("Playback open error: %s\n", snd_strerror(err));
		    exit(EXIT_FAILURE);
	    }

	    if ((err = snd_pcm_set_params(slave,
		                          SND_PCM_FORMAT_FLOAT,
		                          SND_PCM_ACCESS_RW_INTERLEAVED,
		                          1,
		                          Fs,
		                          1,
		                          500000)) < 0) {   
		    printf("Playback open error: %s\n", snd_strerror(err));
		    exit(EXIT_FAILURE);


	    }


	
		while(1) {
			frames_read+=snd_pcm_readi (handle, buffer, BUFFER_LEN) ; 
			//snd_pcm_writei(slave, buffer, BUFFER_LEN);
			if(finding_freq(BUFFER_LEN, digit, Fs, buffer))
				printf("%d Aparecio!!!!!\n",digit);
				
		}


		/*for (k=0; k<BUFFER_LEN; k++){
			printf("%f \n",buffer[k]);                                   
			    }   */
	
	
		snd_pcm_close (handle);
		snd_pcm_close (slave);
		printf("Leídas %d frames\n",frames_read);		
		return 0;
	}

/*
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
}*/
