#include <iostream>
using namespace std;

constexpr int g_consoleLines{ 25 };

namespace UserInput{
    bool isValidCommand(char ch){
        return ch == 'w'||ch == 'a'||ch == 's'||ch == 'd'||ch == 'q';
    }
    
    char getUserCommand(){
        char ch;
        while(1){
            cin>>ch;
            if(isValid(ch)) break;
        }
        return ch;
    }
    
}

class Tile{
    int _num;
    public:
    Tile(int num = 0):_num{num}{};
    
    friend ostream& operator<<(ostream&, const Tile&);
    
    bool isEmpty(){
        return _num;
    }
    
    int getNum(){
        return _num;
    }
};

ostream& operator<<(ostream& out, const Tile& tile){
    if(tile._num){
        out<<tile._num<<"   ";
    }
    else{
        out<<" "<<"   ";
    }
    return out;
}

class Board{
    private:
    static const int _boardSize = 4;
    Tile board[_boardSize][_boardSize] = {{Tile{1}, Tile{2}, Tile{3}, Tile{4}}, 
                                    {Tile{5}, Tile{6}, Tile{7}, Tile{8}},
                                    {Tile{9}, Tile{10}, Tile{11}, Tile{12}},
                                    {Tile{13}, Tile{14}, Tile{15}, Tile{0}}};
    public:
    friend ostream& operator<<(ostream&, Board&);
};

ostream& operator<<(ostream& out, Board& tiles){
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(tiles.board[i][j].getNum()){
                if(tiles.board[i][j].getNum() > 9)
                    out<<tiles.board[i][j].getNum()<<"  ";
                else 
                    out<<tiles.board[i][j].getNum()<<"   ";
            }
            else 
                out<<" "<<"   ";
            if(j == 3) out<<"\n";
        }
    }
    return out;
}

int main()
{
    Board board{};
    std::cout << board;
    return 0;
}