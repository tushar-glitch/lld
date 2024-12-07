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

    bool canPlace(int row, int col){
        return (row<board_dimensions && col<board_dimensions && board[row][col] == '_');
    }
    
    bool placeSymbol(int row, int col, char symbol){
        board[row][col] = symbol;
        bool leftDiag = 1, rightDiag = 1, hori = 1, vert = 1;
        for(int i=0;i<board_dimensions;++i){
            if(board[i][i] != symbol) leftDiag = 0;
            if(board[i][board_dimensions-i-1] != symbol) rightDiag = 0;
            if(board[row][i] != symbol) hori = 0;
            if(board[i][col] != symbol) vert = 0;
        }
        return (leftDiag || rightDiag || hori || vert);
    }
    
    bool isBoardFull(){
        for(int i=0;i<board_dimensions;++i){
            for(int j=0;j<board_dimensions;++j) if(board[i][j] == '_') return false;
        }
        return true;
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
      if(boardDimensions > 5 || boardDimensions < 2){
          SetColor(31);
          cout<<"Please enter value between 2 and 5"<<endl;
          SetColor(32);
          goto jump;
      }
      player1.setPlayer(firstName, 'X');
      player2.setPlayer(secondName, 'O');
      board.initialiseBoard(boardDimensions);
  }
  void startGame(){
      string firstName = player1.getName(), secondName = player2.getName();
      cout<<"Board is set! "<<firstName<<" plays X and "<<secondName<<" plays O"<<endl;
      bool firstPlayerTurn = 1, gameEnd = 0;
      while(!gameEnd){
          board.displayBoard();
          string currPlayer = firstPlayerTurn ? firstName : secondName;
          char currSymbol = firstPlayerTurn ? 'X' : 'O';
          cout << currPlayer << " 's turn" << endl;
          placeSym:
          int row, col;
          cin >> row >> col;
          if(!board.canPlace(row, col)){
              cout<<"Invalid coordinates or already occupied"<<endl;
              goto placeSym;
          }
          else{
              bool isWon = board.placeSymbol(row, col, currSymbol);
              if(isWon){
                  board.displayBoard();
                  cout<<currPlayer<<" won!!!!";
                  gameEnd = 1;
              }
              else{
                  if(board.isBoardFull()){
                      board.displayBoard();
                      cout<<"It's a draw!"<<endl;
                      gameEnd = 1;
                  }
              }
          }
          firstPlayerTurn = !firstPlayerTurn;
      }
  }
};

int main(){
    SetColor(32);
    Game game;
    game.setupGame();
    game.startGame();
    ResetColor();
    return 0;
}