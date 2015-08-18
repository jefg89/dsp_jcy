#include <menuGUI.h>
#include <math.h>
 
void menutransmisor() {
     
    //initscr(); // initialize Ncurses
    
    
    //*********************************** Tecla 1 
    WINDOW *w1;
    char list1[16][2] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","*","#"};
    char item1[1];
    int  i1 = 0;
 
    //initscr(); // initialize Ncurses
    w1 = newwin( 3, 5, 1, 30 ); // create a new window (largo,ancho,y,x)
    box( w1, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w1, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[1]);
    mvwprintw( w1, 1, 2, "%s", item1 );
    
    wrefresh( w1 ); // update the terminal screen
    
    //*********************************** Tecla 2 
   
    
    WINDOW *w2;
    
    //initscr(); // initialize Ncurses
    w2 = newwin( 3, 5, 1, 36 ); // create a new window (largo,ancho,y,x)
    box( w2, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w2, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[2]);
    mvwprintw( w2, 1, 2, "%s", item1 );
    
    wrefresh( w2 ); // update the terminal screen
    
   
    
    //*********************************** Tecla 3
   
    
    WINDOW *w3;
    
    //initscr(); // initialize Ncurses
    w3 = newwin( 3, 5, 1, 42 ); // create a new window (largo,ancho,y,x)
    box( w3, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w3, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[3]);
    mvwprintw( w3, 1, 2, "%s", item1 );
    
    wrefresh( w3 ); // update the terminal screen
    
    //*********************************** Tecla A
   
    
    WINDOW *w4;
    
    //initscr(); // initialize Ncurses
    w4 = newwin( 3, 5, 1, 48 ); // create a new window (largo,ancho,y,x)
    box( w4, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w4, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[10]);
    mvwprintw( w4, 1, 2, "%s", item1 );
    
    wrefresh( w4 ); // update the terminal screen
    
    
    //*********************************** Tecla 4
   
    
    WINDOW *w5;
    
    //initscr(); // initialize Ncurses
    w5 = newwin( 3, 5, 5, 30 ); // create a new window (largo,ancho,y,x)
    box( w5, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w5, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[4]);
    mvwprintw( w5, 1, 2, "%s", item1 );
    
    wrefresh( w5 ); // update the terminal screen
    
    
    //*********************************** Tecla 5
   
    
    WINDOW *w6;
    
    //initscr(); // initialize Ncurses
    w6 = newwin( 3, 5, 5, 36 ); // create a new window (largo,ancho,y,x)
    box( w6, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w6, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[5]);
    mvwprintw( w6, 1, 2, "%s", item1 );
    
    wrefresh( w6 ); // update the terminal screen
    
    //*********************************** Tecla 6
   
    
    WINDOW *w7;
    
    //initscr(); // initialize Ncurses
    w7 = newwin( 3, 5, 5, 42 ); // create a new window (largo,ancho,y,x)
    box( w7, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w7, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[6]);
    mvwprintw( w7, 1, 2, "%s", item1 );
    
    wrefresh( w7 ); // update the terminal screen
    
    //*********************************** Tecla B
   
    
    WINDOW *w8;
    
    //initscr(); // initialize Ncurses
    w8 = newwin( 3, 5, 5, 48 ); // create a new window (largo,ancho,y,x)
    box( w8, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w8, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[11]);
    mvwprintw( w8, 1, 2, "%s", item1 );
    
    wrefresh( w8 ); // update the terminal screen
    
    
    //*********************************** Tecla 7
   
    
    WINDOW *w9;
    
    //initscr(); // initialize Ncurses
    w9 = newwin( 3, 5, 9, 30 ); // create a new window (largo,ancho,y,x)
    box( w9, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w9, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[7]);
    mvwprintw( w9, 1, 2, "%s", item1 );
    
    wrefresh( w9 ); // update the terminal screen
    
    
    //*********************************** Tecla 8
   
    
    WINDOW *w10;
    
    //initscr(); // initialize Ncurses
    w10 = newwin( 3, 5, 9, 36 ); // create a new window (largo,ancho,y,x)
    box( w10, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w10, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[8]);
    mvwprintw( w10, 1, 2, "%s", item1 );
    
    wrefresh( w10 ); // update the terminal screen
    
    
    //*********************************** Tecla 9
   
    
    WINDOW *w11;
    
    //initscr(); // initialize Ncurses
    w11 = newwin( 3, 5, 9, 42 ); // create a new window (largo,ancho,y,x)
    box( w11, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w11, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[9]);
    mvwprintw( w11, 1, 2, "%s", item1 );
    
    wrefresh( w11 ); // update the terminal screen
    
    
    
    //*********************************** Tecla C
   
    
    WINDOW *w12;
    
    //initscr(); // initialize Ncurses
    w12 = newwin( 3, 5, 9, 48 ); // create a new window (largo,ancho,y,x)
    box( w12, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w12, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[12]);
    mvwprintw( w12, 1, 2, "%s", item1 );
    
    wrefresh( w12 ); // update the terminal screen
    
    //*********************************** Tecla *
   
    
    WINDOW *w13;
    
    //initscr(); // initialize Ncurses
    w13 = newwin( 3, 5, 13, 30 ); // create a new window (largo,ancho,y,x)
    box( w13, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w13, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[14]);
    mvwprintw( w13, 1, 2, "%s", item1 );
    
    wrefresh( w13 ); // update the terminal screen
    
    
    //*********************************** Tecla 0
   
    
    WINDOW *w14;
    
    //initscr(); // initialize Ncurses
    w14 = newwin( 3, 5, 13, 36 ); // create a new window (largo,ancho,y,x)
    box( w14, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w14, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[0]);
    mvwprintw( w14, 1, 2, "%s", item1 );
    
    wrefresh( w14 ); // update the terminal screen
    
    
    
    //*********************************** Tecla #
   
    
    WINDOW *w15;
    
    //initscr(); // initialize Ncurses
    w15 = newwin( 3, 5, 13, 42 ); // create a new window (largo,ancho,y,x)
    box( w15, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w15, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[15]);
    mvwprintw( w15, 1, 2, "%s", item1 );
    
    wrefresh( w15 ); // update the terminal screen
    
    
    //*********************************** Tecla D
   
    
    WINDOW *w16;
    
    //initscr(); // initialize Ncurses
    w16 = newwin( 3, 5, 13, 48 ); // create a new window (largo,ancho,y,x)
    box( w16, 0, 0 ); // sets default borders for the window
    
    //****Dibuja la ventana del menu
    wattroff( w16, A_STANDOUT );
    sprintf(item1, "%-1s",  list1[13]);
    mvwprintw( w16, 1, 2, "%s", item1 );
    
    wrefresh( w16 ); // update the terminal screen
    
    
    
    
    
    
    
    
    int ch, i = 1;
    noecho(); // disable echoing of characters on the screen
    
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
       
       
       
   
       
    while(( ch = getchar()) != 'q') 
    {
		if(ch == '1')        //**********************************Tecla 1*********************************
		{		
			wattron( w1, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[1]);
			mvwprintw( w1, 1, 2, "%s", item1 );
			wrefresh( w1 ); // update the terminal screen
			digit = 1;
			send = 1; 
			usleep(200000);
			
			wattroff( w1, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[1]);
			mvwprintw( w1, 1, 2, "%s", item1 );
			wrefresh( w1 ); // update the terminal screen	
		}
		else if(ch == '2')        //**********************************Tecla 2*********************************
		{		
			wattron( w2, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[2]);
			mvwprintw( w2, 1, 2, "%s", item1 );
			wrefresh( w2 ); // update the terminal screen
			digit = 2;
			send = 1; 
			usleep(200000);
			
			wattroff( w2, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[2]);
			mvwprintw( w2, 1, 2, "%s", item1 );
			wrefresh( w2 ); // update the terminal screen	
		}
		else if(ch == '3')        //**********************************Tecla 3*********************************
		{		
			wattron( w3, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[3]);
			mvwprintw( w3, 1, 2, "%s", item1 );
			wrefresh( w3 ); // update the terminal screen
			digit = 3;
			send = 1; 
			usleep(200000);
			
			wattroff( w3, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[3]);
			mvwprintw( w3, 1, 2, "%s", item1 );
			wrefresh( w3 ); // update the terminal screen	
		}
		else if(ch == 'A' || ch == 'a')        //**********************************Tecla A*********************************
		{		
			wattron( w4, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[10]);
			mvwprintw( w4, 1, 2, "%s", item1 );
			wrefresh( w4 ); // update the terminal screen
			digit = 10;
			send = 1; 
			usleep(200000);
			
			wattroff( w4, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[10]);
			mvwprintw( w4, 1, 2, "%s", item1 );
			wrefresh( w4 ); // update the terminal screen			
		}
		else if(ch == '4')      //**********************************Tecla 4*********************************
		{		
			wattron( w5, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[4]);
			mvwprintw( w5, 1, 2, "%s", item1 );
			wrefresh( w5 ); // update the terminal screen
			digit = 4;
			send = 1; 
			usleep(200000);
			
			wattroff( w5, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[4]);
			mvwprintw( w5, 1, 2, "%s", item1 );
			wrefresh( w5 ); // update the terminal screen			
		}
		else if(ch == '5')  //**********************************Tecla 5*********************************
		{
			wattron( w6, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[5]);
			mvwprintw( w6, 1, 2, "%s", item1 );
			wrefresh( w6 ); // update the terminal screen
			digit = 5;
			send = 1; 
			usleep(200000);
			
			wattroff( w6, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[5]);
			mvwprintw( w6, 1, 2, "%s", item1 );
			wrefresh( w6 ); // update the terminal screen
		}
		else if(ch == '6')  //**********************************Tecla 6 *********************************
		{
			wattron( w7, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[6]);
			mvwprintw( w7, 1, 2, "%s", item1 );
			wrefresh( w7 ); // update the terminal screen
			digit = 6;
			send = 1; 
			usleep(200000);
			
			wattroff( w7, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[6]);
			mvwprintw( w7, 1, 2, "%s", item1 );
			wrefresh( w7 ); // update the terminal screen
		}
		else if(ch == 'B' || ch == 'b')  //**********************************Tecla B *********************************
		{
			//****Dibuja la ventana del menu
			wattron( w8, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[11]);
			mvwprintw( w8, 1, 2, "%s", item1 );
			wrefresh( w8 ); // update the terminal screen
			digit = 11;
			send = 1; 
			usleep(200000);
			
			//****Dibuja la ventana del menu
			wattroff( w8, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[11]);
			mvwprintw( w8, 1, 2, "%s", item1 );
			wrefresh( w8 ); // update the terminal screen
		}
		else if(ch == '7')  //**********************************Tecla 7 *********************************
		{
			wattron( w9, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[7]);
			mvwprintw( w9, 1, 2, "%s", item1 );
			wrefresh( w9 ); // update the terminal screen
			digit = 7;
			send = 1; 
			usleep(200000);
			
			wattroff( w9, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[7]);
			mvwprintw( w9, 1, 2, "%s", item1 );
			wrefresh( w9 ); // update the terminal screen
		}
		else if(ch == '8')  //**********************************Tecla 8 *********************************
		{
			wattron( w10, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[8]);
			mvwprintw( w10, 1, 2, "%s", item1 );
			wrefresh( w10 ); // update the terminal screen
			digit = 8;
			send = 1; 
			usleep(200000);
			
			wattroff( w10, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[8]);
			mvwprintw( w10, 1, 2, "%s", item1 );
			wrefresh( w10 ); // update the terminal screen
		}
		else if(ch == '9')  //**********************************Tecla 9 *********************************
		{
			wattron( w11, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[9]);
			mvwprintw( w11, 1, 2, "%s", item1 );
			wrefresh( w11 ); // update the terminal screen
			digit = 9;
			send = 1; 
			usleep(200000);
			
			wattroff( w11, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[9]);
			mvwprintw( w11, 1, 2, "%s", item1 );
			wrefresh( w11 ); // update the terminal screen
		}
		else if(ch == 'C' || ch == 'c')  //**********************************Tecla C *********************************
		{
			wattron( w12, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[12]);
			mvwprintw( w12, 1, 2, "%s", item1 );
			wrefresh( w12 ); // update the terminal screen
			digit = 12;
			send = 1; 
			usleep(200000);
			
			wattroff( w12, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[12]);
			mvwprintw( w12, 1, 2, "%s", item1 );
			wrefresh( w12 ); // update the terminal screen
		}
		else if(ch == '*')  //**********************************Tecla * *********************************
		{
			wattron( w13, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[14]);
			mvwprintw( w13, 1, 2, "%s", item1 );
			wrefresh( w13 ); // update the terminal screen
			digit = 14;
			send = 1; 
			usleep(200000);
			
			wattroff( w13, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[14]);
			mvwprintw( w13, 1, 2, "%s", item1 );
			wrefresh( w13 ); // update the terminal screen
		}
		else if(ch == '0')  //**********************************Tecla 0 *********************************
		{
			wattron( w14, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[0]);
			mvwprintw( w14, 1, 2, "%s", item1 );
			wrefresh( w14 );
			digit = 0;
			send = 1; 
			usleep(200000);
			
			wattroff( w14, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[0]);
			mvwprintw( w14, 1, 2, "%s", item1 );
			wrefresh( w14 ); // update the terminal screen
		}
		else if(ch == '#')  //**********************************Tecla # *********************************
		{
			wattron( w15, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[15]);
			mvwprintw( w15, 1, 2, "%s", item1 );
			wrefresh( w15 );
			digit = 15;
			send = 1; 
			usleep(200000);
			
			wattroff( w15, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[15]);
			mvwprintw( w15, 1, 2, "%s", item1 );
			wrefresh( w15 ); // update the terminal screen
		}
		else if(ch == 'D' || ch == 'd')  //**********************************Tecla D *********************************
		{
			wattron( w16, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[13]);
			mvwprintw( w16, 1, 2, "%s", item1 );
			wrefresh( w16 );
			digit = 13;
			send = 1; 
			usleep(200000);
			
			wattroff( w16, A_STANDOUT );
			sprintf(item1, "%-1s",  list1[13]);
			mvwprintw( w16, 1, 2, "%s", item1 );
			wrefresh( w16 ); // update the terminal screen
		}
		else
		{
		}
		
						
	}
	
	
	
	
	
	
    
    delwin( w1 );
    delwin( w2 );
    delwin( w3 );
    delwin( w4 );
    delwin( w5 );
    delwin( w6 );
    delwin( w7 );
    delwin( w8 );
    delwin( w9 );
    delwin( w10 );
    delwin( w11 );
    delwin( w12 );
    delwin( w13 );
    delwin( w14 );
    delwin( w15 );
    delwin( w16 );
    endwin();

	
}




void* menu() {
     
    WINDOW *w;
    char list[2][11] = { "Transmisor", "Receptor"};
    char item[11];
    int f = 0, width = 11;
 
    initscr(); // initialize Ncurses
    w = newwin( 4, 15, 1, 1 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
     
// now print all the menu items and highlight the first one
    for( f=0; f<2; f++ ) {
        if( f == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-11s",  list[f]);
        mvwprintw( w, f+1, 2, "%s", item );
    }
 
    wrefresh( w ); // update the terminal screen
 
    f = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
    while(( ch1 = wgetch(w)) != 'q'){ 
         
                // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-11s",  list[f]); 
            mvwprintw( w, f+1, 2, "%s", item ); 
              // use a variable to increment or decrement the value based on the input.
            switch( ch1 ) {
                case KEY_UP:
                            f--;
                            f = ( f<0 ) ? 1 : f;
                            break;
                case KEY_DOWN:
                            f++;
                            f = ( f>1 ) ? 0 : f;
                            break;
                case KEY_RIGHT:
							if(f==0) {
								keypad( w, FALSE ); // enable keyboard input for the window.
								menutransmisor();
								clear();   // Clean the environment ncurses
								refresh();
								box( w, 0, 0 ); // Draw again the main windows
								refresh(); 
								keypad( w, TRUE ); // enable keyboard input for the window. 
							}
                            break;
            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );
             
            sprintf(item, "%-11s",  list[f]);
            mvwprintw( w, f+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );
    }
 
    delwin( w );
    endwin();
   
}



void gen_tones()
{
	float freq_up, freq_down;
    int i,j;
    #pragma omp parallel for
	
	for(i=0;i<16;i++){
		switch ( i ) {
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
		for(j=0;j<BUFFER_LEN;j++)
			buffer[i][j] = sin(2.0*M_PI*freq_down*j/Fs) + sin(2.0*M_PI*freq_up*j/Fs);
	}
}
