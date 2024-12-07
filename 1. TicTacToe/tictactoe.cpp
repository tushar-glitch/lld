#include<iostream>
#include<vector>
#include<string>
using namespace std;

void SetColor(int textColor)
{
    cout << "\033[" << textColor << "m";
}

void ResetColor() { cout << "\033[0m"; }

class Board{
    vector<vector<char>> board;
    int board_dimensions;
    public:
    void initialiseBoard(int boardDimensions){
        board_dimensions = boardDimensions;
        for(int i=0;i<board_dimensions;++i){
            vector<char> board_row;
            for(int j=0;j<board_dimensions;++j){
                board_row.push_back('_');
            }
            board.push_back(board_row);
        }
    }
    void displayBoard(){
        for(int i=0;i<board_dimensions;++i){
            for(int j=0;j<board_dimensions;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

class Player{
  string name;
  char symbol;
  
  public:
  void setPlayer(string Name, char sym){
      name = Name;
      symbol = sym;
  }
  string getName(){
      return name;
  }
};

class Game{
  Player player1, player2;
  Board board;
  
  public:
  void setupGame(){
      string firstName, secondName;
      int boardDimensions;
      cout<<"Enter first player name : ";
      cin>>firstName;
      cout<<"Enter second player name : ";
      cin>>secondName;
      jump:
      cout<<"Enter dimensions of board(max:5) : ";
      cin>>boardDimensions;
      if(boardDimensions > 5){
          SetColor(31);
          cout<<"Please enter value between 2 and 5"<<endl;
          SetColor(32);
          goto jump;
      }
      player1.setPlayer(firstName, 'X');
      player2.setPlayer(secondName, 'O');
      board.initialiseBoard(boardDimensions);
    //   board.displayBoard();
  }
  void startGame(){
      cout<<"Board is set! "<<player1.getName()<<" plays X and "<<player2.getName()<<" plays O"<<endl;
    //   cout<<""
  }
};

int main(){
    SetColor(32);
    Game game;
    game.setupGame();
    ResetColor();
    return 0;
}