#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#include <omp.h>
#include <termios.h>
#include <stdio.h>
#include <pthread.h>
#include <menuGUI.h>


static struct termios old, new;
static struct termios g_old_kbd_mode;
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;

float buffer_null [BUFFER_LEN];
int quit_ctrl = 1;
pthread_t tkc;
           //sampling frequency


int main(void)
{
	
    int err;
    int j,k;
    
    digit=2;
    snd_pcm_t *handle;
    send = 0;
    Fs = 44100;
  
    for(j = 0; j < BUFFER_LEN; j++) {
		buffer_null[j] = 0;
	}
	gen_tones();

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
                                  100000)) < 0) {   
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);


    }
 
	   pthread_create(&tkc, NULL, menu, NULL);
       while(ch1 != 'q') {
			if(send){
				(void) snd_pcm_writei(handle, buffer[digit], BUFFER_LEN);    //sending values to sound driver
				send = 0;
			}
            else (void) snd_pcm_writei(handle, buffer_null, BUFFER_LEN);    //sending values to sound driver
       }
       //printf("Ñauuuuu  %c\n" , getch());
            

    snd_pcm_close(handle);
    return 0;

}




/*void *key_control() /*key control and reception thread
    {
    int hotkey;
    static char init;
    struct termios new_kbd_mode;
 
    if(init)
        return;
       // put keyboard (stdin, actually) in raw, unbuffered mode
    tcgetattr(0, &g_old_kbd_mode);
    memcpy(&new_kbd_mode, &g_old_kbd_mode, sizeof(struct termios));
       
    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_kbd_mode);
    atexit(old_attr);
     
    while (quit_ctrl)
    {
        hotkey = getchar(); // get char without interfere with main program
 
        if (hotkey == (int) '1')
        {
			gen_tones(BUFFER_LEN, 1, Fs, buffer);
			send = 1; 
        }
        else if (hotkey == (int) '2')
        {
			gen_tones(BUFFER_LEN, 2, Fs, buffer);
			send = 1; 
        }
        else if (hotkey == (int) '3')
        {
			gen_tones(BUFFER_LEN, 3, Fs, buffer); 
			send = 1;  
        }
        else if (hotkey == (int) '4')
        {
			gen_tones(BUFFER_LEN, 4, Fs, buffer);  
			send = 1; 
        }
        else if (hotkey == (int) 'q' || hotkey == (int) 'Q')
        {
            quit_ctrl=0;
        }
        usleep(1000);   
    }
     pthread_exit(NULL);  
}
*/
 
