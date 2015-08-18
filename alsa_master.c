#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#include <omp.h>
#include <termios.h>
#include <stdio.h>
#include <pthread.h>

#define BUFFER_LEN 8192//44100

static struct termios old, new;
static struct termios g_old_kbd_mode;
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];
float buffer_null [BUFFER_LEN];
int send = 0;
int quit_ctrl = 1;
pthread_t tkc;
int Fs = 44100;             //sampling frequency

char getch(void);
void *key_control();

void gen_tones(int buffer_size, int digit, int Fs, float* input);

int main(void)
{
    int err;
    int j,k;
    
    int digit = 2;

    snd_pcm_t *handle;
    
    for(j = 0; j < BUFFER_LEN; j++) {
		buffer_null[j] = 0;
	}


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
 
	   pthread_create(&tkc, NULL, key_control, NULL);
       while(quit_ctrl) {
			if(send){
				(void) snd_pcm_writei(handle, buffer, BUFFER_LEN);    //sending values to sound driver
				send = 0;
			}
            else (void) snd_pcm_writei(handle, buffer_null, BUFFER_LEN);    //sending values to sound driver
       }
       //printf("Ñauuuuu  %c\n" , getch());
            

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


/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
	tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

char getch(void) 
{
	return getch_(0);
}

static void old_attr(void)
{
    tcsetattr(0, TCSANOW, &g_old_kbd_mode);
}
 
void *key_control() /*key control and reception thread*/
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
        hotkey = getchar(); /*get char without interfere with main program*/
 
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
 
