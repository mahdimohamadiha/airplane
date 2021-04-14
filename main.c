#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char create_win(WINDOW *win);

char create_win2(WINDOW *win2);

void create_win3(WINDOW *win3 ,char *name);

void create_win4(WINDOW *win4);

void start(char move_key , WINDOW *win4 , int y_airplane , int x_airplane , int y_obstacle2 , int x_obstacle2 , int High_score ,
    int y_obstacle , int x_obstacle , int y_arrow_point , int x_arrow_point , int max_arrow_point , int y_arrow , int x_arrow , int airplane_code);

void airplane_displacement(int move_key , int y_airplane , int *x_airplane , int airplane_code);

int shoot_arrow(int *max_arrow_point , int arrow_key , int x_airplane , int y_arrow , int x_arrow ,
    int *y_obstacle ,int *x_obstacle , int *y_obstacle2 , int *x_obstacle2 , int score);

int loss(char move_key , WINDOW *win4 , int y_airplane , int x_airplane , int y_obstacle2 , int x_obstacle2 , int High_score ,
    int y_obstacle , int x_obstacle , int y_arrow_point , int x_arrow_point , int max_arrow_point , int y_arrow , int x_arrow , int airplane_code ,
    int key_start_again , int score);

void select_airplane(int y_airplane , int x_destroy , int airplane_code);

void speed(int score);

int max_arrowPoint(int max_arrow_point);

void airplane(int y_airplane , int x_airplane);

void airplane2(int y_airplane , int x_airplane);

void airplane3(int y_airplane , int x_airplane);

void clean_airplane(int y_clean , int x_clean);

void clean_arrow(int y_clean , int x_clean);

void clean_obstacle(int y_clean , int x_clean);

void destroymood(int y_destroy , int x_destroy);

int obstacle(int *y_obstacle , int *x_obstacle , int score);

int obstacle2(int *y_obstacle2 , int *x_obstacle2 , int score);

void arrow(int y_arrow , int x_arrow);

void arrow_point(int *y_arrow_point , int *x_arrow_point);

void arrow_notice();

void clear_arrow_notice();

void loss_notice(WINDOW *win4);

void clear_loss_notice();

void main(){

    initscr();

    curs_set(0);
    refresh();
    int y_airplane = 31;
    int x_airplane = 63;
    int y_obstacle = 1;
    int x_obstacle = 95;
    int y_obstacle2 = 1;
    int x_obstacle2 = 85;
    char move_key;
    int y_arrow = 30;
    int x_arrow = 75;
    int High_score = 0;
    int y_arrow_point = 1;
    int x_arrow_point = 75;
    int max_arrow_point = 0;
    char airplane_code;

    WINDOW *win;
    airplane_code = create_win(win);

    WINDOW *win4;
    create_win4(win4);

    start(move_key, win4 , y_airplane, x_airplane , y_obstacle2 , x_obstacle2 ,
    High_score , y_obstacle , x_obstacle , y_arrow_point , x_arrow_point ,
    max_arrow_point , y_arrow , x_arrow , airplane_code);
}

char create_win(WINDOW *win){
    
    char airplane_code;
    char name;
    usleep(500000);
    refresh();
    win = newwin(10 , 50 , 14 , 48);
    refresh();
    box(win , 0 , 0);
    wrefresh(win);
    usleep(800000);
    win = newwin(5 , 42 , 18 , 52);
    refresh();
    box(win , 0 , 0);
    wrefresh(win);
    mvprintw(16 , 57 , "--::WELCOME TO AIRPLANE GAME::--");
    usleep(850000);
    mvprintw(20 , 55 , "Enter Your Name:");
    refresh();
    scanw("%s" , &name);
    clear();

    WINDOW *win2;
    airplane_code = create_win2(win2);

    WINDOW *win3;
    create_win3(win3, &name);

    return airplane_code;
}

char create_win2(WINDOW *win2){

    char airplane_code='f';   
    usleep(500000);
    win2 = newwin(20 , 66 , 9 , 40);
    refresh();
    box(win2 , 0 , 0);
    wrefresh(win2);          
    usleep(800000);                  
    win2 = newwin(18 , 62, 10, 42); 
    refresh();
    box(win2, 0 , 0);            
    wrefresh(win2); 
    usleep(1000000);
    mvprintw(13 , 60 , "*||CHOOSE YOUR AIRPLANE||*");
    airplane(17 , 48);
    mvprintw(24 , 52 , "A");
    airplane2(17 , 68);
    mvprintw(24 , 72 , "B");
    airplane3(17 , 87);
    mvprintw(24 , 91 , "C");
    noecho();
    while(airplane_code!='a'&&airplane_code!='b'&&airplane_code!='c'){
    airplane_code = (char)getch();
    }
    clear();
    return airplane_code;             
}

void create_win3(WINDOW *win3 ,char *name){    
                           
    win3 = newwin(38 , 40, 0,0); 
    refresh();                  
    box(win3, 0 , 0);            
    wrefresh(win3);
    usleep(1000000);   
    win3 = newwin(3 , 38 , 1 ,1);
    refresh();
    box(win3 , 0 , 0);
    wrefresh(win3);
    usleep(1100000);
    win3 = newwin(12 , 38 , 5 , 1);
    refresh();
    box(win3 , 0 , 0);
    wrefresh(win3);
    usleep(1200000);
    win3 = newwin(10 , 38 , 17 , 1);
    refresh();
    box(win3 , 0 , 0);
    wrefresh(win3);
    usleep(1300000);
    win3 = newwin(10 , 38 , 27 , 1);
    refresh();
    box(win3 , 0 , 0);
    wrefresh(win3);
    usleep(1400000);
    mvprintw(20 , 2 , "____________________________________");
    mvprintw(21 , 2 , "====================================");
    mvprintw(29 , 8 , "--  You must have ten  --"); 
    mvprintw(30 , 8 , "--arrow points to shoot--");
    mvprintw(32 , 12 , "ARROW POINT : 0");
    mvprintw(2 , 9 , "<<- NAME : %s ->>" , name);         
}

void create_win4(WINDOW *win4){ 
                                 
    win4 = newwin(38 , 110, 0, 40); 
    refresh();                  
    box(win4, 0 , 0);            
    wrefresh(win4);              
}

void start(char move_key , WINDOW *win4 , int y_airplane , int x_airplane , int y_obstacle2 , int x_obstacle2 , int High_score ,
    int y_obstacle , int x_obstacle , int y_arrow_point , int x_arrow_point , int max_arrow_point , int y_arrow , int x_arrow , int airplane_code){
    
    int score = 0;
    char key_start_again;
    char arrow_key;
    
    select_airplane(8 , 16 , airplane_code);
    while (1){
    speed(score);
    select_airplane(y_airplane , x_airplane , airplane_code);
    score = obstacle(&y_obstacle , &x_obstacle , score);
    
    if(score >= 300){  

    score = obstacle2(&y_obstacle2 , &x_obstacle2 , score); 
    }      
    arrow_point(&y_arrow_point , &x_arrow_point);

        airplane_displacement(move_key , y_airplane , &x_airplane , airplane_code);

        if(x_airplane - 3 <= x_arrow_point-4 && x_arrow_point-4 <= x_airplane + 3 && y_airplane + 2 <= y_arrow_point && y_arrow_point <= y_airplane + 5 ){
        
        max_arrow_point = max_arrowPoint(max_arrow_point);
    }

        score = shoot_arrow(&max_arrow_point , arrow_key , x_airplane , y_arrow , x_arrow ,
        &y_obstacle , &x_obstacle , &y_obstacle2 , &x_obstacle2 , score);
        
    score = loss(move_key, win4 , y_airplane , x_airplane , y_obstacle2 , x_obstacle2 ,
    High_score , y_obstacle , x_obstacle , y_arrow_point , x_arrow_point , max_arrow_point ,
    y_arrow , x_arrow , airplane_code , key_start_again , score);
}

}

void airplane_displacement(int move_key , int y_airplane , int *x_airplane , int airplane_code){

    nodelay(stdscr, 1);    
    move_key = (char)getch();
    
    if (move_key == 'd' && *x_airplane < 137 || move_key == 'D' && *x_airplane < 137)
    {
        *x_airplane +=4;
        refresh();
        clean_airplane(y_airplane , *x_airplane -4);
        select_airplane(y_airplane , *x_airplane , airplane_code);
    }
    if (move_key == 'a' && *x_airplane > 45 || move_key == 'A' && *x_airplane > 45)
    {
        *x_airplane -= 4;
        refresh();
        clean_airplane(y_airplane , *x_airplane );
        select_airplane(y_airplane , *x_airplane , airplane_code);
    }
}

int shoot_arrow(int *max_arrow_point , int arrow_key , int x_airplane , int y_arrow , int x_arrow ,
    int *y_obstacle ,int *x_obstacle , int *y_obstacle2 , int *x_obstacle2 , int score){

    if(*max_arrow_point == 10){
        arrow_notice();
        nodelay(stdscr, 1);
        arrow_key = (char)getch();
        if (arrow_key == 'f' || arrow_key == 'F'){  
            x_arrow = x_airplane;
            while(y_arrow < 31 && y_arrow > 0){
            usleep(5000); 
            arrow(y_arrow , x_arrow);     
            y_arrow -= 1;
            if(*x_obstacle - 4 <= x_arrow+3 && x_arrow+3 <= *x_obstacle + 9 && *y_obstacle == y_arrow){

                *y_obstacle = 1;
                *x_obstacle = rand() % 97 + 41;
                destroymood(y_arrow , x_arrow);
                usleep(100000);
                clean_obstacle(y_arrow , x_arrow-5);
                score += 50;
                mvprintw(19 , 13 , " SCORE : %d" , score);
                refresh();
            }
            if (*x_obstacle2 - 3 <= x_arrow+3 && x_arrow+3 <= *x_obstacle2 + 9 && *y_obstacle2 == y_arrow && score >= 300){
     
                *y_obstacle2 = 1;
                *x_obstacle2 = rand() % 89 + 41;
                destroymood(y_arrow , x_arrow);
                usleep(100000);
                clean_obstacle(y_arrow , x_arrow-5);
                score += 50;
                mvprintw(19 , 13 , " SCORE : %d" , score);
                refresh();
            }   }
            if (y_arrow <= 0){
                clean_arrow(y_arrow+1 , x_arrow);
                *max_arrow_point = 0;
                y_arrow = 30;
                clear_arrow_notice();
            }   }   }return score;   
            }

int loss(char move_key , WINDOW *win4 , int y_airplane , int x_airplane , int y_obstacle2 , int x_obstacle2 , int High_score ,
    int y_obstacle , int x_obstacle , int y_arrow_point , int x_arrow_point , int max_arrow_point , int y_arrow , int x_arrow , int airplane_code ,
    int key_start_again , int score){

    if (x_airplane - 8 <= x_obstacle2 && x_obstacle2 <= x_airplane + 8 && y_airplane  <= y_obstacle2 + 1 && y_obstacle2 <= y_airplane + 6 || 
        x_airplane - 10 <= x_obstacle && x_obstacle <= x_airplane + 7  && y_airplane  <= y_obstacle && y_obstacle <= y_airplane + 5)
    {
        max_arrow_point = 0;
        y_arrow = 30;
        loss_notice(win4);
        destroymood(y_airplane , x_airplane);
        nodelay(stdscr, 0);
        key_start_again = (char)getch();
        if (key_start_again == 'c' || key_start_again == 'C')
        {
            clean_airplane(y_airplane , x_airplane);
            int y_airplane = 31;
            int x_airplane = 63;
            int y_obstacle = 1;
            int x_obstacle = 95;
            int y_obstacle2 = 1;
            int x_obstacle2 = 85;
            char move_key;
            clear_loss_notice();
            if (High_score < score)
            {
                High_score = score;
                mvprintw(23 , 12 , "HIGH SCORE : %d ", High_score);
                refresh();
            }
            
            start(move_key, win4 , y_airplane, x_airplane , y_obstacle2 , x_obstacle2 , High_score , y_obstacle , x_obstacle , y_arrow_point , x_arrow_point , max_arrow_point , y_arrow , x_arrow , airplane_code);
            
        }   }return score;
        }  

void select_airplane(int y_airplane , int x_destroy , int airplane_code){

    switch (airplane_code)
        {
        case 'a':
            airplane(y_airplane , x_destroy);    
            break;
        case 'b':
            airplane2(y_airplane , x_destroy); 
            break;
        case 'c':
            airplane3(y_airplane , x_destroy);
            break;    
        }    
}

void speed(int score){

    if(score<50) usleep(100000);
    if(score>=50&&score<100) usleep(80000);
    if(score>=100&&score<200) usleep(60000);
    if(score>=200&&score<400) usleep(40000);
    if(score>=400) usleep(30000);
}

int max_arrowPoint(int max_arrow_point){

    if (max_arrow_point < 10){
        max_arrow_point++;
        
        mvprintw(32 , 12 , "ARROW POINT : %d ", max_arrow_point);
        refresh();
    }
    return max_arrow_point;
}

void airplane(int y_airplane , int x_airplane) {

    mvprintw(y_airplane ,    x_airplane , "    ^    ");
    mvprintw(y_airplane + 1, x_airplane , "   | |   ");
    mvprintw(y_airplane + 2, x_airplane , "  ||*||  ");
    mvprintw(y_airplane + 3, x_airplane , " /  0  \\");
    mvprintw(y_airplane + 4, x_airplane , "|--| |--|");
    mvprintw(y_airplane + 5, x_airplane , "  /|||\\ ");
    refresh();
}

void airplane2(int y_airplane , int x_airplane) {

    mvprintw(y_airplane ,    x_airplane , "    ^    ");
    mvprintw(y_airplane + 1, x_airplane , "   | |   ");
    mvprintw(y_airplane + 2, x_airplane , " ^/|*|\\^");
    mvprintw(y_airplane + 3, x_airplane , " / | | \\");
    mvprintw(y_airplane + 4, x_airplane , "/__-|-__\\");
    mvprintw(y_airplane + 5, x_airplane , " |/`+'\\| ");
    refresh();
}

void airplane3(int y_airplane , int x_airplane) {

    mvprintw(y_airplane ,    x_airplane , "    |     ");
    mvprintw(y_airplane + 1, x_airplane , "   _A_    ");
    mvprintw(y_airplane + 2, x_airplane , "|_/|#|\\_|");
    mvprintw(y_airplane + 3, x_airplane , "|__| |__| ");
    mvprintw(y_airplane + 4, x_airplane , " * |I| *  ");
    mvprintw(y_airplane + 5, x_airplane , "   /I\\   ");
    refresh();
}

void clean_airplane(int y_clean , int x_clean){
 
    mvprintw(y_clean ,    x_clean , "             ");
    mvprintw(y_clean + 1, x_clean , "             ");
    mvprintw(y_clean + 2, x_clean , "             ");
    mvprintw(y_clean + 3, x_clean , "             ");
    mvprintw(y_clean + 4, x_clean , "             ");
    mvprintw(y_clean + 5, x_clean , "             ");
    refresh();
}

void clean_arrow(int y_clean , int x_clean){
 
    mvprintw(y_clean ,    x_clean , "         ");
    mvprintw(y_clean + 1, x_clean , "         ");
    mvprintw(y_clean + 2, x_clean , "         ");
    refresh();
}

void clean_obstacle(int y_clean , int x_clean){
 
    mvprintw(y_clean ,    x_clean , "                    ");
    mvprintw(y_clean + 1, x_clean , "                    ");
    mvprintw(y_clean + 2, x_clean , "                    ");
    mvprintw(y_clean + 3, x_clean , "                    ");
    mvprintw(y_clean + 4, x_clean , "                    ");
    mvprintw(y_clean + 5, x_clean , "                    ");
    refresh();  
}

void destroymood(int y_destroy , int x_destroy){

    mvprintw(y_destroy     , x_destroy , "     _  ");
    mvprintw(y_destroy + 1 , x_destroy , "    (  ) ");
    mvprintw(y_destroy + 2 , x_destroy , " ( `  ). )");
    mvprintw(y_destroy + 3 , x_destroy , "(_, _(  ,_)");
    refresh();
}

int obstacle(int *y_obstacle , int *x_obstacle , int score){

    if(*y_obstacle<37)  mvprintw(*y_obstacle    , *x_obstacle , "           ");
    if(*y_obstacle<36)  mvprintw(*y_obstacle + 1, *x_obstacle , " /\\\\   //\\");
    if(*y_obstacle<35)  mvprintw(*y_obstacle + 2, *x_obstacle , " \\  \\ /  /");
    if(*y_obstacle<34)  mvprintw(*y_obstacle + 3, *x_obstacle , "  \\|{.}|/ ");
    if(*y_obstacle<33)  mvprintw(*y_obstacle + 4, *x_obstacle , "   \\|V|/  ");
    if(*y_obstacle<32)  mvprintw(*y_obstacle + 5, *x_obstacle , "    \\./   ");
    refresh();
    *y_obstacle += 1;
    if(*y_obstacle == 37){
        *y_obstacle = 1;
        *x_obstacle = rand() % 97 + 41;
        score++;
        mvprintw(19 , 13 , " SCORE : %d" , score);
        refresh();
    }
    return score;
}

int obstacle2(int *y_obstacle2 , int *x_obstacle2 , int score){

    if(*y_obstacle2<36)  mvprintw(*y_obstacle2 + 1, *x_obstacle2 , "          ");
    if(*y_obstacle2<35)  mvprintw(*y_obstacle2 + 2, *x_obstacle2 , "   ___    ");
    if(*y_obstacle2<34)  mvprintw(*y_obstacle2 + 3, *x_obstacle2 , "   \\|/   ");
    if(*y_obstacle2<33)  mvprintw(*y_obstacle2 + 4, *x_obstacle2 , " __| |__  ");
    if(*y_obstacle2<32)  mvprintw(*y_obstacle2 + 5, *x_obstacle2 , "|___0___| ");
    if(*y_obstacle2<31)  mvprintw(*y_obstacle2 + 6, *x_obstacle2 , "   _V_    ");
    refresh();
    *y_obstacle2 += 1;
    if(*y_obstacle2 == 36){
        *y_obstacle2 = 1;
        *x_obstacle2 = rand() % 89 + 41;
        score++;
        mvprintw(19 , 13 , " SCORE : %d" , score);
        refresh();
    }
    return score;
}

void arrow(int y_arrow , int x_arrow){

    mvprintw(y_arrow ,    x_arrow+3 , "/\\");
    mvprintw(y_arrow + 1, x_arrow+3 , "||");
    mvprintw(y_arrow + 2, x_arrow+3 , "||");
    mvprintw(y_arrow + 3, x_arrow+3 , "  ");
    refresh();
}

void arrow_point(int *y_arrow_point , int *x_arrow_point){

    if(*y_arrow_point<37) mvprintw(*y_arrow_point    , *x_arrow_point , " ");
    if(*y_arrow_point<36) mvprintw(*y_arrow_point + 1, *x_arrow_point , "*");
    *y_arrow_point +=1;
    if(*y_arrow_point == 37){
        *y_arrow_point = 1;
        *x_arrow_point = rand() % 97 + 41;
    }
}

void arrow_notice(){

    
    mvprintw(33 , 12 , "Hold F to shoot");
    refresh();
}

void clear_arrow_notice(){

    mvprintw(32 , 8 , "                     ");
    mvprintw(33 , 8 , "                     ");
    mvprintw(32 , 12 , "ARROW POINT : 0");
    refresh();
}

void loss_notice(WINDOW *win4){

    mvprintw(7  , 2 , "                                    ");
    mvprintw(8  , 2 , "                                    ");
    mvprintw(9  , 2 , "                                    ");
    mvprintw(10 , 2 , "                                    ");
    mvprintw(11 , 2 , "                                    ");
    mvprintw(12 , 2 , "                                    ");
    mvprintw(13 , 2 , "                                    ");     
    create_win4(win4);
    mvprintw(7  , 11 , "||== YOU LOST ==||");
    mvprintw(8  , 2  , "____________________________________");
    mvprintw(9  , 2  , "LILILILILILILILILILILILILILILILILILI");
    mvprintw(12 , 7  , "| Press C to continue and |");
    mvprintw(13 , 7  , "|  press Ctrl+C to exit   |");
    mvprintw(25 , 11 , "                    ");
    refresh();
}
void clear_loss_notice(){

    mvprintw(7  , 2 , "                                    ");
    mvprintw(8  , 2 , "                                    ");
    mvprintw(9  , 2 , "                                    ");
    mvprintw(10 , 2 , "                                    ");
    mvprintw(11 , 2 , "                                    ");
    mvprintw(12 , 2 , "                                    ");
    mvprintw(13 , 2 , "                                    ");
    mvprintw(19 , 2 , "                                    ");
    mvprintw(32 , 12 , "ARROW POINT : 0");
    refresh();
}
