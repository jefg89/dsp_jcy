#include <menuGUI.h>
#include <goertzel.h>

static struct termios old, new;
static struct termios g_old_kbd_mode;
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;

float buffer_null[1024];

pthread_t tkc, thread1, thread2;

int main(void)
{
	
    int err;
    int j,k;
    
    digit=2;
    send = 0;
    Fs = 44100;     //sampling frequency
    durationdefaultsize = 0;
    mode = 1;
  
    for(j = 0; j < 1024; j++) {
		buffer_null[j] = 0;
	}
	/*for(j = 1024; j < 11793; j++) {
		buffer_null_11793[j] = 0;
		buffer_null_22562[j] = 0;
		buffer_null_33331[j] = 0;
		buffer_null_44100[j] = 0;
	}
	for(j = 11793; j < 22562; j++) {
		buffer_null_22562[j] = 0;
		buffer_null_33331[j] = 0;
		buffer_null_44100[j] = 0;
	}
	for(j = 22562; j < 33331; j++) {
		buffer_null_33331[j] = 0;
		buffer_null_44100[j] = 0;
	}
	for(j = 33331; j < 44100; j++) {
		buffer_null_44100[j] = 0;
	}*/
	buffer_2048 = (float **) malloc(sizeof(float*) * 16);
	buffer_11793 = (float **) malloc(sizeof(float*) * 16);
	buffer_22562 = (float **) malloc(sizeof(float*) * 16);
	buffer_33331 = (float **) malloc(sizeof(float*) * 16);
	buffer_44100 = (float **) malloc(sizeof(float*) * 16);

	for(k=0; k<16;k++){
		buffer_2048[k] = (float *) malloc(sizeof(float) * 2048 );
		buffer_11793[k] = (float *) malloc(sizeof(float) * 11793 );
		buffer_22562[k] = (float *) malloc(sizeof(float) * 22562 );
		buffer_33331[k] = (float *) malloc(sizeof(float) * 33331 );
		buffer_44100[k] = (float *) malloc(sizeof(float) * 44100 );
	}
	gen_tones(buffer_2048, 2048);
	gen_tones(buffer_11793, 11793);
	gen_tones(buffer_22562, 22562);
	gen_tones(buffer_33331, 33331);
	gen_tones(buffer_44100, 44100);

	pthread_create(&tkc, NULL, menu, NULL);
	while (ch1 != 'q') {
		if(mode) {
			if ((err = snd_pcm_open(&handle_w, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
					printf("Playback open error: %s\n", snd_strerror(err));
					exit(EXIT_FAILURE);
			}

			if ((err = snd_pcm_set_params(handle_w,
										  SND_PCM_FORMAT_FLOAT,
										  SND_PCM_ACCESS_RW_INTERLEAVED,
										  1,
										  Fs,
										  1,
										  100000)) < 0) {   
					printf("Playback open error: %s\n", snd_strerror(err));
					exit(EXIT_FAILURE);


			}
			while(ch1 != 'q') {
				if(send){
					switch( durationdefaultsize ) {
						case 0:
									(void) snd_pcm_writei(handle_w, buffer_2048[digit], 2048);    //sending values to sound driver
									break;
						case 1:
									(void) snd_pcm_writei(handle_w, buffer_11793[digit], 11793);    //sending values to sound driver
									break;
						case 2:
									(void) snd_pcm_writei(handle_w, buffer_22562[digit], 22562);    //sending values to sound driver
									break;
						case 3:
									(void) snd_pcm_writei(handle_w, buffer_33331[digit], 33331);    //sending values to sound driver
									break;
						case 4:
									(void) snd_pcm_writei(handle_w, buffer_44100[digit], 44100);    //sending values to sound driver
									break;
						default:
									break;
					}
				send = 0;
				}
				else (void) snd_pcm_writei(handle_w, buffer_null, 1024);    //sending values to sound driver
			}
			snd_pcm_close(handle_w);
			//sleep(1);
		}
		else {
			if ((err = snd_pcm_open (&handle_r, device, SND_PCM_STREAM_CAPTURE, 0)) < 0) {
				exit (1);
			}
			if ((err = snd_pcm_set_params(handle_r,
									  SND_PCM_FORMAT_FLOAT,
									  SND_PCM_ACCESS_RW_INTERLEAVED,
									  1,
									  Fs,
									  1,
									  100000)) < 0) {   
				printf("Playback open error: %s\n", snd_strerror(err));
				exit(EXIT_FAILURE);
					   }
			pthread_create( &thread1, NULL, finding_freq, NULL);
			while(ch1 != 'q') { 
				pthread_mutex_lock(&mutex_f);
				pthread_mutex_unlock(&mutex_s);
				//pthread_mutex_lock(&mutex_w1);		
				(void) snd_pcm_readi(handle_r, buffer_f, BUFFER_LEN); 
				
				//pthread_mutex_unlock(&mutex_w1);
				pthread_mutex_lock(&mutex_s);
				pthread_mutex_unlock(&mutex_f);
				(void) snd_pcm_readi(handle_r, buffer_s, BUFFER_LEN);

			}
			snd_pcm_close(handle_r);
			//sleep(1);
		}
	}
    return 0;
}
 
