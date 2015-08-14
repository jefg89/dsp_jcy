#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#include <omp.h>
#include <conio.h>
#define BUFFER_LEN 44100//44100

static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];

void gen_tones(int buffer_size, int digit, int Fs, float* input);

int main(void)
{
    int err;
    int j,k;
    
    int Fs = 2048;             //sampling frequency
    int digit = 2;

    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;


    // ERROR HANDLING

    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
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

        gen_tones(BUFFER_LEN, digit, Fs, buffer);   

        while(1){
            frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);    //sending values to sound driver
            getch();
            }

    snd_pcm_close(handle);
    return 0;

}

void gen_tones(int buffer_size, int digit, int Fs, float* input)
{
	float freq_up, freq_down;
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
    int i;
    #pragma omp parallel for
	for(i=0;i<buffer_size;i++){
		input[i] = sin(2.0*M_PI*freq_down*i/Fs) + sin(2.0*M_PI*freq_up*i/Fs);
	}
}
