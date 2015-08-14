#include "goertzel.h"
	
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
pthread_t thread1, thread2;

void *finding_freq();

	int main (int argc, char *argv[])
	{
		int i;
		int k,j;
		int err;
		Fs = 44100;
		digit = 2 ;
		sync_ = 1;
		
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
		
		//unsigned long get_time_buffer_f, get_time_buffer_s;
		
		while(1) {
			//get_time_buffer_f = get_time_usec();
			snd_pcm_readi (handle, buffer_f, BUFFER_LEN) ; 
			pthread_create( &thread1, NULL, finding_freq,NULL);
			//printf("Time buffer_f = %lu\n", get_time_usec() - get_time_buffer_f);
			
			//get_time_buffer_s = get_time_usec();
			snd_pcm_readi (handle, buffer_s, BUFFER_LEN);
			pthread_create( &thread2, NULL, finding_freq,NULL);
			//printf("Time buffer_s = %lu\n", get_time_usec() - get_time_buffer_s);
		}
		
		snd_pcm_close (handle);
		snd_pcm_close (slave);	
		
		(void) pthread_join(thread1, NULL);
		(void) pthread_join(thread2, NULL);
		return 0;
	}
