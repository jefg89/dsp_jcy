	#include <stdio.h>
	#include <stdlib.h>
	#include <alsa/asoundlib.h>
	#define BUFFER_LEN 88200
	
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];


	main (int argc, char *argv[])
	{
		int i;
		int k,j;
		int err;
		int frames_read=0;
		
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
                                  44100,
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
		                          44100,
		                          1,
		                          500000)) < 0) {   
		    printf("Playback open error: %s\n", snd_strerror(err));
		    exit(EXIT_FAILURE);


	    }


	
		for (i = 0; i < 5; ++i) {
			frames_read+=snd_pcm_readi (handle, buffer, BUFFER_LEN) ; 
			snd_pcm_writei(slave, buffer, BUFFER_LEN);
				
		}

		/*for (k=0; k<BUFFER_LEN; k++){
			printf("%f \n",buffer[k]);                                   
			    }   */
	
	
		snd_pcm_close (handle);
		snd_pcm_close (slave);
		printf("Leídas %d frames",frames_read);		
		exit (0);
	}
