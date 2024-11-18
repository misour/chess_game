#ifndef GAME_H
#define GAME_H
#include "starter.h"
#include "chessman.h"

using namespace std ;
using namespace sf ;
class Game
{
private:
//Variables
    sf::Texture t_image ;
    sf::Sprite s_background ;
    sf::Texture t_board ;
    sf::Sprite s_board;

    Sprite s_btn_exit;      Texture t_btn_exit; Texture t_btn_exit_hover;

    bool exit;
    bool tour ;
    int Tab[8][8];
//Pawn
    std::vector<Pawn*> PawndUP ;
    std::vector<Pawn*> PawndDawn ;
//Rock
    std::vector<Rock*> RockUP ;
    std::vector<Rock*> RockDawn ;
//Bishop
    std::vector<Bishop*> BishopUP ;
    std::vector<Bishop*> BishopDawn ;
//Queen
    std::vector<Queen*> QueenUP;
    std::vector<Queen*> QueenDawn;
//King
    std::vector<King*>  KingUP;
    std::vector<King*>  KingDawn;
//Knight
    std::vector<Knight*>  KnightUP;
    std::vector<Knight*>  KnightDawn;
//window
    sf::RenderWindow * window ;
//private function
    void initVariables();
    void initwindow();
    void iniPawnd();
    void iniRock();
    void iniBishop();
    void iniQueen();
    void iniKing();
    void iniKnight();
    void iniTab();
public:
    //constructor & destructors
    Game(RenderWindow *win);
    virtual  ~Game();
    //accessors
    int getCase();
    //function
    void updateTab(int lastpos, int newpos);
    void pollEvents();
    int caseOcuppe(int pos);
    void make_move(sf::Vector2i localPosition );
    void updatePawnd();
    void updateRock();
    void updateBishop();
    void updateQueen();
    void updateKing();
    void updateKnight();
    void updateChessman();
    //Kill Chesman
    void KillPawnd(int,int,char);
    void KillRock(int,int,char);
    void killBishop(int,int,char);
    void killQueen(int,int,char);
    void killKing(int,int,char);
    void killKnight(int,int,char);
    void KillChessman(int,int,char);
    bool path_is_libre(int pos1,int pos2,char c);
    void update();
    void render();
    void run();
    //game reset
    void reset();
    bool get_is_exit(){return exit;}
    void set_is_exit(bool b){exit=b;}

};

#endif // GAME_H

