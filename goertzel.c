#include <goertzel.h>

int g1, g2, g3, g4;
int found = 1;

float goertzel(int N,int Ft, float* input) {
	
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

void *finding_freq() {
	double elapsed;
	int err;
	usleep(100000);
	start = clock();
	while(1) {
		pthread_mutex_lock(&mutex_f);
		#pragma omp parallel
		{
			g1 = goertzel(2048, freq_up, buffer_f);
			g2 = goertzel(2048, freq_down, buffer_f);
		}
		if ((g1>TH) & 
		   (g2>TH)){
			if(found) {
				//printf("Digito %f encontrado\n", end);
				found = 0;
				system("echo 0 > /sys/class/gpio/gpio17/value");
				dial_num[num_det] = num_jef[num_det];
				num_det++;
				digit = num_jef[num_det];
				set_station();
				start = clock();
			}
		}
		else {
			found = 1;
			system("echo 1 > /sys/class/gpio/gpio17/value");
		}
		pthread_mutex_unlock(&mutex_f);
		pthread_mutex_lock(&mutex_s);
		#pragma omp parallel
		{
			g3 = goertzel(2048, freq_up, buffer_s);
			g4 = goertzel(2048, freq_down, buffer_s);
		}
		if ((g3>TH) & 
		   (g4>TH)){
			if(found) {
				//printf("Digito %f encontrado\n", end);
				found = 0;
				system("echo 0 > /sys/class/gpio/gpio17/value");
				dial_num[num_det] = num_jef[num_det];
				num_det++;
				digit = num_jef[num_det];
				set_station();
				start = clock();
			}
		}
		else {
			found = 1;
			system("echo 1 > /sys/class/gpio/gpio17/value");
		}
		pthread_mutex_unlock(&mutex_s);
		end = clock();
		elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
		if(abs(elapsed) > 3) {
			digit = num_jef[0];
			num_det = 0;
			set_station();
			//printf("Digito %f encontrado\n", digit);
			
		}
		if(num_det == 8) {
			if ((err = snd_pcm_open(&handle_w, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
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
			pthread_create( &thread2, NULL, write_, NULL);
			num_det = 0;
		}
	}
}


void *write_() {
	usleep(100000);
	while((mode==0) & (ch1 != 'q'))
	{	
		system("echo 0 > /sys/class/gpio/gpio17/value");
		pthread_mutex_lock(&mutex_w1);
		(void) snd_pcm_writei(handle_w, buffer_f, 2048);
		pthread_mutex_unlock(&mutex_w1); 
		(void) snd_pcm_writei(handle_w, buffer_s, 2048);

	}
	snd_pcm_close(handle_w);
	system("echo 1 > /sys/class/gpio/gpio17/value");
	usleep(100000);
}

void set_station() {
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
            freq_up = 10000; freq_down = 10000;
            break;
	}
}
unsigned long get_time_usec() {
	
	struct timeval tv;
	gettimeofday(&tv,NULL);
	unsigned long time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;
	return time_in_micros;
}


