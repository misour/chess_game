#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

#include<iostream>
#include<vector>

using namespace sf;

class Chessman{
protected:
    sf::Texture src ;
    sf::Sprite sprite ;
    sf::IntRect segment ;
    int posCase ;
    bool is_move ;
private :
    void initVariable();
public:

    Chessman();
    virtual ~Chessman();
    void render(sf::RenderWindow * target);
    void updatePosition(float x, float y);
    sf::FloatRect getGlobaleBounds();
    bool checkContain(float x,float y) ;

    //set position by case
    void setPosCaseX_Y(int x,int y);
    void setPosCase(int val);
    //set movement
    void setmove(bool val);
    int getPosCase() ;
    bool getmove();
    //Movement
    void mouvement(int,char) ;
    void updateMovement(char,int);
};
//-----------------------------------------------------------------------------------------
//Class Pawn
class Pawn : public Chessman
{
protected:
private:
    int first_move ;
    void initMove();
public:
    Pawn(int type);
    virtual ~Pawn();
    int update(int,char,int);
};
//-----------------------------------------------------------------------------------------
//Class Rock
class Rock : public Chessman
{
private:
protected:
public :
    Rock(int type);
    int update(int,char,int,bool );
    virtual ~Rock();
};
//-----------------------------------------------------------------------------------------
//Class Bishop
class Bishop : public Chessman
{
private:
protected:
public :
    Bishop(int type);
    int update(int,char,int,bool );
    virtual ~Bishop();
};

//-----------------------------------------------------------------------------------------
// Class Queen
class Queen : public Chessman
{
private:
protected:
public :
    Queen(int type);
    virtual ~Queen();
    int update(int,char,int,bool);

};
//-----------------------------------------------------------------------------------------
// Class King
class King: public Chessman
{
private:
protected:
public :
    King(int type);
    virtual ~King();
    int update(int,char,int);

};
//-----------------------------------------------------------------------------------------
// Class Knight
class Knight : public Chessman
{
private:
protected:
public :
    Knight(int type);
    virtual ~Knight();
    int update(int,char,int);

};
