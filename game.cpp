#include "game.h"

//private function
void Game::initVariables()
{
    window = nullptr; //pour l'affirmation
    if (! t_image.loadFromFile("images/SFML_GAME_BACKGROUND.png"))
    {
        cout << "ERROR::GAME::iniVariables BOARD" << endl;
    }
    s_background.setTexture( t_image);

    if (! t_board.loadFromFile("images/SFML_GAME_BOARD.png"))
    {
        cout << "ERROR::GAME::iniVariables BOARD" << endl;
    }
    //char btn_str_start[]="images/SFML_GAME_BUTTON_START.png";
    if (! t_btn_exit.loadFromFile("images/SFML_GAME_BUTTON_EXIT.png"))
    {
        cout << "ERROR::GAME::iniVariables EXIT" << endl;
    }

    //button-exit-exit
   if (! this->t_btn_exit_hover.loadFromFile("images/SFML_GAME_BUTTON_EXIT_HOVER.png"))
    {
        cout << "ERROR::GAME::iniVariables EXIT_HOVER" << endl;
    }

    s_btn_exit.setTexture(t_btn_exit);
    s_btn_exit.setPosition(600,400);
    s_btn_exit.setScale(1.5,1.5);

    s_board.setTexture( t_board);

    s_board.setPosition(30,5);
    s_board.setScale(1.75,1.75);
    tour=tour;
}
//initializer window
void Game::initwindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(504,504),"CHESS",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}
//initializer Pawnd
void Game::iniPawnd()
{
    for(int i=0; i<8; i++)
    {
        this->PawndUP.push_back(new Pawn(0));
        this->PawndDawn.push_back(new Pawn(1));
        PawndUP[i]->updatePosition(56*i+41,16+56);
        PawndUP[i]->setPosCaseX_Y(2,i+1);

        PawndDawn[i]->updatePosition(56*i+41,16+56*6);
        PawndDawn[i]->setPosCaseX_Y(7,i+1);
    }
}
//intializer Tableau
void Game::iniTab()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(i==1 || i==0)
                this->Tab[i][j]=1;
            else  if(i==6 || i==7)
                this->Tab[i][j]=2;
            else  this->Tab[i][j]=0;
        }
    }
}
//initializer Rock
void Game::iniRock()
{
    for(int i=0; i<2; i++)
    {
        this->RockUP.push_back(new Rock(0));
        this->RockDawn.push_back(new Rock(1));
        RockUP[i]->updatePosition(56*i*7+41,16);
        RockUP[i]->setPosCaseX_Y(1,i*7+1);

        RockDawn[i]->updatePosition(56*i*7+41,16+56*7);
        RockDawn[i]->setPosCaseX_Y(8,i*7+1);
    }
}
//initializer Bishop
void Game::iniBishop()
{
    for(int i=0; i<2; i++)
    {
        this->BishopUP.push_back(new Bishop(0));
        this->BishopDawn.push_back(new Bishop(1));
        BishopUP[i]->updatePosition(56*i*3+41+56*2,16);
        BishopUP[i]->setPosCaseX_Y(1,i*3+3);

        BishopDawn[i]->updatePosition(56*i*3+41+56*2,16+56*7);
        BishopDawn[i]->setPosCaseX_Y(8,i*3+3);
    }
}
//initializer Queen
void Game::iniQueen()
{
    this->QueenUP.push_back(new Queen(0));
    this->QueenDawn.push_back(new Queen(1));
    QueenUP[0]->updatePosition(56*3+41,16);
    QueenUP[0]->setPosCaseX_Y(1,4);

    QueenDawn[0]->updatePosition(56*3+41,16+56*7);
    QueenDawn[0]->setPosCaseX_Y(8,4) ;
}
//initializer King
void Game::iniKing()
{
    this->KingUP.push_back(new King(0));
    this->KingDawn.push_back(new King(1));
    KingUP[0]->updatePosition(56*4+41,16);
    KingUP[0]->setPosCaseX_Y(1,5);

    KingDawn[0]->updatePosition(56*4+41,16+56*7);
    KingDawn[0]->setPosCaseX_Y(8,5) ;
}
//initializer Knight
void Game::iniKnight()
{
    for(int i=0; i<2; i++)
    {
        this->KnightUP.push_back(new Knight(0));
        this->KnightDawn.push_back(new Knight(1));
        KnightUP[i]->updatePosition(56*i*5+56+41,16);
        KnightUP[i]->setPosCaseX_Y(1,i*5+2);

        KnightDawn[i]->updatePosition(56*i*5+56+41,16+56*7);
        KnightDawn[i]->setPosCaseX_Y(8,i*5+2);
    }
}
//constructor & destructors
Game::Game(RenderWindow *win)
{
    this->initVariables();
    //this->initwindow();
    window=win;
    this->iniPawnd();
    this->iniTab();
    this->iniRock();
    this->iniBishop();
    this->iniQueen();
    this->iniKing();
    this->iniKnight();
}
Game::~Game()
{
    delete this->window ;
    //delete Pawnd
    for(auto *e : this->PawndUP)
    {
        delete e ;
    }
    for(auto *e : this->PawndDawn)
    {
        delete e ;
    }
    //delete Rock()
    for(auto *e : this->RockDawn)
    {
        delete e ;
    }
    for(auto *e : this->RockUP)
    {
        delete e ;
    }
    //delete Bishop
    for(auto *e : this->BishopDawn)
    {
        delete e;
    }
    for(auto *e : this->BishopUP)
    {
        delete e;
    }
    //delete Queen
    for(auto *e : this->QueenDawn)
    {
        delete e;
    }
    for(auto *e : this->QueenUP)
    {
        delete e;
    }
    //delete King
    for(auto *e : this->KingUP)
    {
        delete e;
    }
    for(auto *e : this->KingDawn)
    {
        delete e;
    }

}
//accessors
int Game::getCase()
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(*this->window);
    float posY,posX ;
    for(int i=0; i<8; i++)
    {
        posY =26.f + i*57;
        if(localPosition.y>=posY && localPosition.y<posY+57.f)
        {
            for(int j=0; j<8; j++)
            {
                posX = 26.f + j*57;
                if(localPosition.x>=posX && localPosition.x<posX+57.f)
                {
                    return ((1+i)*10)+(j+1);
                }
            }
        }
    }
    return 0 ;
}
//Function
void Game::pollEvents()
{
    //Event Polling
    sf::Event ev ;

    while(this->window->pollEvent(ev))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(*this->window);
        switch(ev.type)
        {

        case sf::Event::Closed :
            this->window->close();
            break;
        case Event::MouseButtonPressed :
            if (ev.mouseButton.button == sf::Mouse::Button::Left)
            {
                if(s_btn_exit.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y)){
                    exit=true;
                }
                this->make_move(localPosition);
            }
            break;
        case sf::Event::MouseButtonReleased :
            this->updateChessman();
            break;
        case sf::Event::MouseMoved:
            if(s_btn_exit.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y)){
                    s_btn_exit.setTexture(t_btn_exit_hover);
                }else{s_btn_exit.setTexture(t_btn_exit);}
            break;
        default :
            break ;
        }

    }
}
//determiner si case est libre or not
int Game::caseOcuppe(int pos)
{
    int j= pos%10 ;
    int i=((pos %100)-j)/10;
    return this->Tab[i-1][j-1];
}
//Update Pawnd
void Game::updatePawnd()
{
    for(unsigned i=0; i<max(PawndDawn.size(),PawndUP.size()); i++)
    {
        //Down
        if(!tour){
        int  lastpos =PawndDawn[i]->getPosCase();
        int newpos=PawndDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            this->tour=true ;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
        }
        }
        //--------------------------------------------------------------
        //up
        if(tour){
       int lastpos =PawndUP[i]->getPosCase();
       int newpos=PawndUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
            tour =false ;
        }

    }
}
}
//Update Rock
void Game::updateRock()
{
    for(unsigned i=0; i<max(RockDawn.size(),RockUP.size()); i++)
    {
        int  lastpos,newpos;
        if(!tour){
          lastpos =RockDawn[i]->getPosCase();
          newpos=RockDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'r'));
        if(newpos!=0)
        {
            tour=true;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
        }
        }
        //--------------------------------------------------------------
        //up
        if(tour){
        lastpos=RockUP[i]->getPosCase();
        newpos=RockUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'r'));
        if(newpos!=0)
        {
            tour=false;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
        }
        }

    }
}
//Update Bishop
void Game::updateBishop()
{
    int  lastpos,newpos;
    for(unsigned i=0; i<max(BishopDawn.size(),BishopUP.size()); i++)
    {
        if(!tour){
          lastpos =BishopDawn[i]->getPosCase();
          newpos=BishopDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'b'));
        if(newpos!=0)
        {
            tour=true ;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
        }
        }
        //--------------------------------------------------------------
        //up
        if(tour){
        lastpos=BishopUP[i]->getPosCase();
        newpos=BishopUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'b'));
        if(newpos!=0)
        {
            tour=false ;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
        }
        }
    }
}
//Update Queen
void Game::updateQueen()
{
    for(unsigned i=0; i<max(QueenDawn.size(),QueenUP.size()); i++)
    {
        int  lastpos,newpos;
        if(!tour){
          lastpos =QueenDawn[i]->getPosCase();
          newpos=QueenDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'q'));
        if(newpos!=0)
        {
            tour=true;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
        }
        }
        //--------------------------------------------------------------
        //up
        if(tour){
        lastpos=QueenUP[i]->getPosCase();
        newpos=QueenUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()),this->path_is_libre(lastpos,this->getCase(),'q'));
        if(newpos!=0)
        {
            tour=false;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
        }
        }
    }
}
//Update King
void Game::updateKing()
{
    for(unsigned i=0; i<max(KingDawn.size(),KingUP.size()); i++)
    {
        int  lastpos,newpos;
         if(!tour){
          lastpos =KingDawn[i]->getPosCase();
         newpos=KingDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            tour=true;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
        }
         }
        //--------------------------------------------------------------
        //up
         if(tour){
        lastpos=KingUP[i]->getPosCase();
        newpos=KingUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            tour=false ;
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
        }
         }
    }
}
//Update Knight
void Game::updateKnight()
{
    for(unsigned i=0; i<max(KnightDawn.size(),KnightUP.size()); i++)
    {
        int  lastpos,newpos;
         if(!tour){
         lastpos =KnightDawn[i]->getPosCase();
          newpos=KnightDawn[i]->update(this->getCase(),'d',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'u');
            tour=true;
        }
         }

        //--------------------------------------------------------------
        //up
         if(tour){
        lastpos=KnightUP[i]->getPosCase();
        newpos=KnightUP[i]->update(this->getCase(),'u',this->caseOcuppe(this->getCase()));
        if(newpos!=0)
        {
            this->updateTab(lastpos,newpos);
            this->KillChessman(lastpos,newpos,'d');
            tour=false;
        }
         }
    }

}
//update Chessman
void Game::updateChessman()
{
    if(this->getCase()>0)
    {
        this->updatePawnd();
        this->updateRock();
        this->updateBishop();
        this->updateQueen();
        this->updateKing();
        this->updateKnight();
    }
}
//Kill Pawnd
void Game::KillPawnd(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<PawndUP.size(); j++)
        {
            if(newpos==PawndUP[j]->getPosCase())
            {
                delete this->PawndUP[j] ;
                this->PawndUP.erase(this->PawndUP.begin() + j);
            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<PawndDawn.size(); j++)
        {
            if(newpos==PawndDawn[j]->getPosCase())
            {
                delete this->PawndDawn.at(j);
                this->PawndDawn.erase(this->PawndDawn.begin() + j);
            }
        }
    }
}
//Kill Rock
void Game::KillRock(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<RockUP.size(); j++)
        {
            if(newpos==RockUP[j]->getPosCase())
            {
                delete this->RockUP[j];
                this->RockUP.erase(this->RockUP.begin() + j);

            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<RockDawn.size(); j++)
        {
            if(newpos==RockDawn[j]->getPosCase())
            {
                delete this->RockDawn[j] ;
                this->RockDawn.erase(this->RockDawn.begin() + j);
            }
        }
    }
}
//Kill Bishop
void Game::killBishop(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<BishopUP.size(); j++)
        {
            if(newpos==BishopUP[j]->getPosCase())
            {
                delete this->BishopUP[j];
                this->BishopUP.erase(this->BishopUP.begin() + j);

            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<BishopDawn.size(); j++)
        {
            if(newpos==BishopDawn[j]->getPosCase())
            {
                delete this->BishopDawn[j] ;
                this->BishopDawn.erase(this->BishopDawn.begin() + j);
            }
        }
    }
}
//Kill Queen
void Game::killQueen(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<QueenUP.size(); j++)
        {
            if(newpos==QueenUP[j]->getPosCase())
            {
                delete this->QueenUP[j];
                this->QueenUP.erase(this->QueenUP.begin() + j);

            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<QueenDawn.size(); j++)
        {
            if(newpos==QueenDawn[j]->getPosCase())
            {
                delete this->QueenDawn[j] ;
                this->QueenDawn.erase(this->QueenDawn.begin() + j);
            }
        }
    }
}
//Kill King
void Game::killKing(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<KingUP.size(); j++)
        {
            if(newpos==KingUP[j]->getPosCase())
            {
                delete this->KingUP[j] ;
                this->KingUP.erase(this->KingUP.begin() + j);
            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<KingDawn.size(); j++)
        {
            if(newpos==KingDawn[j]->getPosCase())
            {
                delete this->KingDawn[j] ;
                this->KingDawn.erase(this->KingDawn.begin() + j);
            }
        }
    }
}
//Kill Knight
void Game::killKnight(int lastpos,int newpos,char c)
{
    if(c=='u')
    {
        for(unsigned j=0; j<KnightUP.size(); j++)
        {
            if(newpos==KnightUP[j]->getPosCase())
            {
                delete this->KnightUP[j];
                this->KnightUP.erase(this->KnightUP.begin() + j);

            }
        }
    }
    if(c=='d')
    {
        for(unsigned j=0; j<KnightDawn.size(); j++)
        {
            if(newpos==KnightDawn[j]->getPosCase())
            {
                delete this->KnightDawn[j] ;
                this->KnightDawn.erase(this->KnightDawn.begin() + j);
            }
        }
    }
}
//Kill Chessman
void Game::KillChessman(int lastpos,int newpos,char c)
{
    this->KillPawnd(lastpos,newpos,c);
    this->KillRock(lastpos,newpos,c);
    this->killBishop(lastpos,newpos,c);
    this->killQueen(lastpos,newpos,c);
    this->killKing(lastpos,newpos,c);
    this->killKnight(lastpos,newpos,c);
}
void Game::make_move(sf::Vector2i localPosition )
{
    //Check Pawnd
    for(unsigned i=0; i<PawndDawn.size(); i++)
    {
        if(PawndDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            PawndDawn[i]->setmove(true);
        }
    }
    for(unsigned i=0; i<PawndUP.size(); i++)
    {
        if(PawndUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            PawndUP[i]->setmove(true);
        }
    }
    //Check Rock
    for(unsigned i=0; i<RockDawn.size(); i++)
    {
        if(RockDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            RockDawn[i]->setmove(true);
        }
    }
    for(unsigned i=0; i<RockUP.size(); i++)
    {
        if(RockUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            RockUP[i]->setmove(true);
        }
    }
    // Check Bishop
    for(unsigned i=0; i<BishopDawn.size(); i++)
    {
        if(BishopDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            BishopDawn[i]->setmove(true);

        }
    }
    for(unsigned i=0; i<BishopUP.size(); i++)
    {
        if(BishopUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            BishopUP[i]->setmove(true);
        }
    }
    // Check Queen
    for(unsigned i=0; i<QueenDawn.size(); i++)
    {
        if(QueenDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            QueenDawn[i]->setmove(true);

        }
    }
    for(unsigned i=0; i<QueenUP.size(); i++)
    {
        if(QueenUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            QueenUP[i]->setmove(true);
        }
    }
    //Check King
    for(unsigned i=0; i<KingDawn.size(); i++)
    {
        if(KingDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            KingDawn[i]->setmove(true);
        }
    }
    for(unsigned i=0; i<KingUP.size(); i++)
    {
        if(KingUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            KingUP[i ]->setmove(true);
        }
    }
    //Check Knight
    for(unsigned i=0; i<KnightDawn.size(); i++)
    {
        if(KnightDawn[i]->checkContain(localPosition.x,localPosition.y))
        {
            KnightDawn[i]->setmove(true);

        }
    }
    for(unsigned i=0; i<KnightUP.size(); i++)
    {
        if(KnightUP[i]->checkContain(localPosition.x,localPosition.y))
        {
            KnightUP[i]->setmove(true);
        }
    }

}
//update Tableau
void Game::updateTab(int lastpos, int newpos)
{
    int j= lastpos%10 ;
    int i=((lastpos %100)-j)/10;
    int pos=this->Tab[i-1][j-1] ;
    this->Tab[i-1][j-1]=0;
    j= newpos%10 ;
    i=((newpos %100)-j)/10;
    this->Tab[i-1][j-1]=pos ;

}
//determiner path est disponible
bool Game::path_is_libre(int pos1,int pos2,char c)
{
    int declage=std::abs(pos1-pos2);
    if(c=='r' || c=='q')
    {
        if(declage<8)
        {
            for(int i=std::min(pos1,pos2)+1; i<std::max(pos1,pos2); i++)
            {
                if(this->caseOcuppe(i))
                    return false ;
            }
            return true;
        }
        else
        {
            if(pos1%10==pos2%10)
            {
                for(int i=std::min(pos1,pos2)+10; i<std::max(pos1,pos2); i+=10)
                {
                    if(this->caseOcuppe(i))
                        return false ;
                }
                return true ;
            }
        }
    }
    if(c=='b' || c=='q')
    {
        if(declage%9==0)
        {
            for(int i=std::min(pos1,pos2)+9; i<std::max(pos1,pos2); i+=9)
            {
                if(this->caseOcuppe(i))
                    return false ;
            }
            return true ;
        }
        if(declage%11==0)
        {
            for(int i=std::min(pos1,pos2)+11; i<std::max(pos1,pos2); i+=11)
            {
                if(this->caseOcuppe(i))
                    return false ;
            }
            return true ;
        }
    }
    return false;

}
void Game::update()
{
    this->pollEvents();
}
//draw game
void Game::render()
{
    // clear old object
    this->window->clear();
    //draw game objects
    this->window->draw(this->s_background);
    this->window->draw(s_board);
    this->window->draw(s_btn_exit);


    //Draw Pawnd
    for(auto *e : this->PawndUP)
    {
        e->render(this->window);
    }
    for(auto *e : this->PawndDawn)
    {
        e->render(this->window);
    }
    //Draw Rock
    for(auto *e : this->RockDawn)
    {
        e->render(this->window);
    }
    for(auto *e : this->RockUP)
    {
        e->render(this->window);
    }
    //draw Bishop
    for(auto *e : this->BishopDawn)
    {
        e->render(this->window);
    }
    for(auto *e : this->BishopUP)
    {
        e->render(this->window);
    }
    //Draw Queen
    for(auto *e : this->QueenDawn)
    {
        e->render(this->window);
    }
    for(auto *e : this->QueenUP)
    {
        e->render(this->window);
    }
    //Draw King
    for(auto *e : this->KingDawn)
    {
        e->render(this->window);
    }
    for(auto *e : this->KingUP)
    {
        e->render(this->window);
    }
    //Draw Knight
    for(auto *e : this->KnightDawn)
    {
        e->render(this->window);
    }
    for(auto *e : this->KnightUP)
    {
        e->render(this->window);
    }
    this->window->display();

}
//run game
void Game::run()
{
    while(window->isOpen() && !exit)
    {
        //Update
        this->update();
        //Render
        this->render();
    }
    cout << "run exit" << endl;
}
void Game::reset(){
    delete this->KnightDawn[0] ;
    KnightUP.erase(KnightUP.begin() + 0);
    this->KnightUP.push_back(new Knight(0));


    /*for(int i=0; i<8; i++)
    {
        if(PawndUP.size()==8){

        }
        this->PawndUP.push_back(new Pawn(0));

        if(PawndDawn.size()==8){

        }
        this->PawndDawn.push_back(new Pawn(1));

        PawndUP[i]->updatePosition(56*i+41,16+56);
        PawndUP[i]->setPosCaseX_Y(2,i+1);

        PawndDawn[i]->updatePosition(56*i+41,16+56*6);
        PawndDawn[i]->setPosCaseX_Y(7,i+1);
    }*/
    delete this->KnightDawn[1] ;
    this->KnightDawn.erase(this->KnightDawn.begin() + 1);
    this->iniKnight();
}
