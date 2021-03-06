#include <iostream>
#include<string>
#include<stdlib.h>
#define GRID_SIZE 3
using namespace std;
class Game{
	 
   private :
   	
   	char grid[GRID_SIZE][GRID_SIZE];
   	
   	public:
   
   void check_for_wins()
   {
       const char* winning_moves[8]={
           "123",
           "456",
           "789",
           "147",
           "258",
           "369",
           "159",
           "753"
       };
       
       for(int i=0 ; i<8 ; i++)
       {
            bool winner = true;
            
            char previous_grid ='0';
            
            const char* winning_move= winning_moves[i];
              
                   for(int index=0 ; index <GRID_SIZE ; index++)
                   {
                    char character = winning_move[index];
                    int entered_number= character-'0';
                    int grid_space = entered_number -1;
                    int row = grid_space/GRID_SIZE;
                    int col = grid_space%GRID_SIZE;

            char grid_char= grid[row][col];
            
            if (previous_grid == '0')
            {
                previous_grid= grid_char;
            }else if( previous_grid== grid_char)
            {
                continue;
            }
            else
            {
                winner= false;
                break;
            }
   }
    if(winner)
    {
        cout<<"****************WE HAVE A WINNER****************\n"<<endl;
        
        printf("%c have won the game ^_^ \n", previous_grid);
        exit(0);
        break;
        }
        
       }
   }
   
   void ask_turn()
    {
        
        string input;
        
        while(true)
        {
            cout<<"Where would like to play?\n";
            cin>>input;
            
            if(input != "")
            {
             char entered = input.c_str()[0];
                   if(entered>='1'&&entered<='9')
                                   {
                          int entered_number = entered-'0';
                          int index =entered_number-1;
                                       
                               int row = index / 3;
                               int col = index % 3 ;
                                        
                                    char grid_position=grid[row][col];
                                    
                                    if(grid_position =='X' || grid_position =='O')
                                    {
                                       cout<<"That grid position is already taken!\n"<<endl;
                                    }
                                       else
                                       {
                                           grid[row][col] ='X';
                                           break;
                                       }
                                   }
                                      else {
                                       cout<<"We have to play in range 1-9\n";
                                           }
            }                 
    else
           {
              cout<<"you have to put something \n";  
            }
        }
    }
    
    void computer_player_turn()
    {
        while(true)
        {
        int computer_choice =( rand() %9)+1;
    //    printf(" Computer turn chose %d \n", computer_choice);
           int row =(computer_choice-1)/3;
           int col = (computer_choice-1)%3;
           
           char grid_position= grid[row][col];
           if(grid_position == 'X' || grid_position == 'O'){
               // this grid position already taken 
               continue;
           }
           else {
               printf("The computer takes the %d. \n", computer_choice);
               grid[row][col]='O';
               break;
           }
        }
    }
    
    void generate_grid()
   {
	  int number=1;
   
	 
   
        for(int x=0 ; x<GRID_SIZE ;x++)
    {
        for( int y=0 ; y<GRID_SIZE ; y++)
        {
            grid[x][y]=to_string(number).c_str()[0];
            number+=1;
        }
      }
   }
    
    
    void show_grid()
    
  {
	
        
       printf("\n------------\n");
    for(int x=0 ; x<GRID_SIZE ; x++)
    {
        for( int y=0 ; y<GRID_SIZE ; y++)
        {
            printf(" %c |", grid[x][y]);
        }
        printf("\n------------\n");
      }
    }
};
int main(int argc, char *argv[])
{
  Game a;
  a.generate_grid();
  a.show_grid();
  a.check_for_wins();
  
  while(true)
  {
  a.ask_turn();
  a.check_for_wins();
  
  
  a.computer_player_turn();
  a.show_grid();
  a.check_for_wins();
 
  }
    return 0;
}
