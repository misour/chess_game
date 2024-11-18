#include "chessman.h"

void Chessman::initVariable() {
    // Load the image
//     if (!src.loadFromFile("images/figures.png")){
//        std::cout<<"ERROR::CHESSMAN::iniTexture"<<std::endl; ;
//    }
    if (!src.loadFromFile("images/SFML_GAME_PIECES.png")){
        std::cout<<"ERROR::CHESSMAN::iniTexture"<<std::endl; ;
    }
     // Create the sprite
    this->sprite.setTexture(src);
    this->sprite.setScale(1.75,1.75 );
    this->is_move=false ;
    this->posCase=0;
}
Chessman::Chessman(){
      initVariable();
}
Chessman::~Chessman(){}
//Get Global Bounds
 sf::FloatRect Chessman::getGlobaleBounds() {
     return this->sprite.getGlobalBounds();
 }
 //check instecrtion
 bool Chessman::checkContain(float x,float y){
     return this->getGlobaleBounds().contains(x,y);
 }
//Draw chessman
 void Chessman::render(sf::RenderWindow * target){
     target->draw(this->sprite);
 }
void Chessman::updatePosition(float x, float y){
    this->sprite.setPosition(x,y);
}
//set position case by   X & Y
void Chessman::setPosCaseX_Y(int x,int y){
      this->posCase=x*10+y ;
}
//set position case by   val
void Chessman::setPosCase(int val){
    this->posCase=val;
}
//change etat de mouvement
void Chessman::setmove(bool val){
    this->is_move=val;
}
//get position in cases
int Chessman::getPosCase(){
    return this->posCase;
}
//get etat de mouvement
bool Chessman::getmove() {
    return this->is_move;
}
//Type of mouvement
void Chessman::mouvement(int type ,char c) {
    //TO UP
        if(c=='u'){
        //move directe
        if(type==0){
            this->sprite.move(0.f,-56.f) ;
        }
        //move Right up
        if(type==1){
            this->sprite.move(55.f,-56.f) ;
        }
         //move Left up
        if(type==2){
            this->sprite.move(-55.f,-56.f) ;
        }
    }
    //TO Dawn
    if(c=='d'){
        //move directe
        if(type==0){
            this->sprite.move(0.f,56.f) ;
        }
        //move Right dawn
        if(type==1){
            this->sprite.move(55.f,56.f) ;
        }
         //move Left dawn
        if(type==2){
            this->sprite.move(-55.f,56.f) ;
        }
    }
    if(c=='m'){
    // To Left
      if(type==0){
            this->sprite.move(-56.f,0.f) ;
        }
   //To Right
      if(type==1){
            this->sprite.move(56.f,0.f) ;
        }
    }

 }

void Chessman::updateMovement(char c,int possouris){
    //movement of Rock
    if(c=='r'){
       int lastposition=this->getPosCase();
    int decalage=std::abs(lastposition-possouris);
     if(decalage<8){
        for(int i=0;i<=decalage;i++){
         if(this->getPosCase()+i==possouris ){
         for(int j=0;j<i;j++)
         this->mouvement(1,'m');
         this->setPosCase(this->getPosCase()+i);
         }
    }
       for(int i=decalage;i>0;i--){
             if(this->getPosCase()-i==possouris ){
          for(int j=0;j<i;j++)
          this->mouvement(0,'m');
        this->setPosCase(this->getPosCase()-i);
    }
       }
        }
      else if(lastposition%10==possouris%10) {
           for(int i=0;i<=decalage;i+=10){
         if(this->getPosCase()+i==possouris ){
         for(int j=0;j<i/10;j++)
        this->mouvement(0,'d');
        this->setPosCase(this->getPosCase()+i);
         }
    }
       for(int i=decalage;i>0;i-=10){
             if(this->getPosCase()-i==possouris ){
          for(int j=0;j<i/10;j++)
         this->mouvement(0,'u');
        this->setPosCase(this->getPosCase()-i);
    }
       }

    }
    }
    //movement of Bishop
    if(c=='b'){
   int lastpos=this->getPosCase();
    int decalage=std::abs(this->posCase-possouris);
    bool val=possouris > this->getPosCase();
       if(decalage%9==0){
           if(val){
        for(int i=0;i<decalage/9;i++){
           if(lastpos+i*9+9==possouris){
             for(int j=0;j<=i;j++)
             this->mouvement(2,'d');
         this->setPosCase(this->getPosCase()+i*9+9);
           }
        }
       }
       if(!val){
        for(int i=0;i<decalage/9;i++){
           if(lastpos-i*9-9==possouris){
             for(int j=0;j<=i;j++)
             this->mouvement(1,'u');
         this->setPosCase(this->getPosCase()-i*9-9);
           }
        }
       }
       }
       if(decalage%11==0){
       if(val){
            for(int i=0;i<decalage;i++){
                if(lastpos+i*11+11==possouris){
                    for(int j=0;j<=i;j++)
                   this->mouvement(1,'d');
                this->setPosCase(this->getPosCase()+i*11+11);
                }
            }}
        if(!val){
             for(int i=0;i<decalage/9;i++){
           if(lastpos-i*11-11==possouris){
             for(int j=0;j<=i;j++)
             this->mouvement(2,'u');
         this->setPosCase(this->getPosCase()-i*11-11);
           }
        }
        }
       }
    }
     if(c=='k'){
        if(possouris==this->getPosCase()+1){
        this->mouvement(1,'m');
        this->setPosCase(this->getPosCase()+1);
        }
        if(possouris==this->getPosCase()-1){
             this->mouvement(0,'m');
             this->setPosCase(this->getPosCase()-1);
            }
        if(possouris==this->getPosCase()-10){
             this->mouvement(0,'u');
             this->setPosCase(this->getPosCase()-10);
             }
        if(possouris==this->getPosCase()+10){
             this->mouvement(0,'d');
             this->setPosCase(this->getPosCase()+10);
             }
        if(possouris==this->getPosCase()-9){
             this->mouvement(1,'u');
             this->setPosCase(this->getPosCase()-9);}
        if(possouris==this->getPosCase()+9){
             this->mouvement(2,'d');
             this->setPosCase(this->getPosCase()+9);
             }
         if(possouris==this->getPosCase()-11){
             this->mouvement(2,'u');
             this->setPosCase(this->getPosCase()-11);}
        if(possouris==this->getPosCase()+11){
             this->mouvement(1,'d');
             this->setPosCase(this->getPosCase()+11);
             }

    }
    //movement of Knight
    if(c=='n'){
        //Down Down Right
       if(possouris==this->getPosCase()+21){
        this->mouvement(0,'d');
        this->mouvement(1,'d');
        this->setPosCase(this->getPosCase()+21);
        }
       //Down Down left
        if(possouris==this->getPosCase()+19){
        this->mouvement(0,'d');
        this->mouvement(2,'d');
        this->setPosCase(this->getPosCase()+19);
        }
    //UP UP Down
     if(possouris==this->getPosCase()-21){
        this->mouvement(0,'u');
        this->mouvement(2,'u');
        this->setPosCase(this->getPosCase()-21);
        }
    //UP UP Right
        if(possouris==this->getPosCase()-19){
        this->mouvement(0,'u');
        this->mouvement(1,'u');
        this->setPosCase(this->getPosCase()-19);
        }
    //Right Right Down
            if(possouris==this->getPosCase()+12){
        this->mouvement(1,'m');
        this->mouvement(1,'d');
        this->setPosCase(this->getPosCase()+12);
        }
    //Right Right Up
       if(possouris==this->getPosCase()-8){
        this->mouvement(1,'m');
        this->mouvement(1,'u');
        this->setPosCase(this->getPosCase()-8);
        }

        //Left Left Down
            if(possouris==this->getPosCase()+8){
        this->mouvement(0,'m');
        this->mouvement(2,'d');
        this->setPosCase(this->getPosCase()+8);
        }
    //Left Left Up
       if(possouris==this->getPosCase()-12){
        this->mouvement(0,'m');
        this->mouvement(2,'u');
        this->setPosCase(this->getPosCase()-12);
        }
    }
}

//-----------------------------------------------------------------------------------------
//Class Pawn
//public function
//Constructeur & deconstructeur
 Pawn::Pawn(int type){
     if(type==0){
        this->segment=sf::IntRect(0, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(0, 34, 32, 32) ;
     }
      this->sprite.setTextureRect(this->segment);
      this->initMove();
 }
 Pawn::~Pawn(){}
 //init first move
 void Pawn::initMove() {
     this->first_move=0;
 }
 //Update Movement
int  Pawn::update(int possouris,char c,int occupe){
    int lastposition=this->getPosCase();
    if(c=='d' && this->getmove()){
     this->setmove(false);
      if(this->getPosCase()-20==possouris && !occupe && this->first_move==0){
       this->mouvement(0,'u');
       this->mouvement(0,'u');
        this->setPosCase(this->getPosCase()-20);
        this->first_move++;
    }

    if(this->getPosCase()-10==possouris && !occupe){
       this->mouvement(0,'u');
        this->setPosCase(this->getPosCase()-10);
        this->first_move++;
    }
     if(this->getPosCase()-9==possouris && occupe==1){
        this->mouvement(1,'u');
        this->setPosCase(this->getPosCase()-9);
        this->first_move++;
    }
     if(this->getPosCase()-11==possouris && occupe==1){
         this->mouvement(2,'u');
        this->setPosCase(this->getPosCase()-11);
        this->first_move++;
    }
    }
    if(c=='u' && this->getmove()){
     this->setmove(false);
       if(this->getPosCase()+20==possouris && !occupe &&this->first_move==0){
       this->mouvement(0,'d');
        this->mouvement(0,'d');
        this->setPosCase(this->getPosCase()+20);
        this->first_move++;
    }
    if(this->getPosCase()+10==possouris && !occupe){
       this->mouvement(0,'d');
        this->setPosCase(this->getPosCase()+10);
        this->first_move++;
    }
     if(this->getPosCase()+9==possouris && occupe==2){
        this->mouvement(2,'d');
        this->setPosCase(this->getPosCase()+9);
        this->first_move++;
    }
     if(this->getPosCase()+11==possouris && occupe==2){
         this->mouvement(1,'d');
        this->setPosCase(this->getPosCase()+11);
        this->first_move++;
    }
    }
    return this->getPosCase()==lastposition ? 0 : this->getPosCase() ;
}


//-----------------------------------------------------------------------------------------
//Class Rock
Rock::Rock(int type){
    if(type==0){
        this->segment=sf::IntRect(136, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(136, 34, 32, 32) ;
     }
      this->sprite.setTextureRect(this->segment);
}
Rock::~Rock() {}
//update Rock
int Rock::update(int possouris,char c,int occupe,bool path_is_libre){
    int lastposition=this->getPosCase();
  if(c=='d' && this->getmove() && path_is_libre  && occupe!=2 ){
        this->setmove(false);
        this->updateMovement('r',possouris);
  }
    if(c=='u' && this->getmove() && path_is_libre && occupe!=1){
        this->setmove(false);
        this->updateMovement('r',possouris);
  }

  if(!path_is_libre) return 0;
  else
  return this->getPosCase()==lastposition ? 0 : this->getPosCase() ;
}

//-----------------------------------------------------------------------------------------
//Class Bishop
Bishop::Bishop(int type){
    if(type==0){
        this->segment=sf::IntRect(34, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(34, 34, 32, 32) ;
     }
      this->sprite.setTextureRect(this->segment);
}
Bishop::~Bishop(){}
int Bishop::update(int possouris,char c,int occupe,bool path_is_libre){
    int lastpos=this->getPosCase();
     if(c=='u' && this->getmove() && path_is_libre && occupe!=1 ){
            this->setmove(false);
         this->updateMovement('b',possouris);

     }
     if(c=='d' && this->getmove() && path_is_libre && occupe!=2 ){
           this->setmove(false);
         this->updateMovement('b',possouris);
     }
       if(!path_is_libre) return 0;
  else
  return this->getPosCase()==lastpos ? 0 : this->getPosCase() ;
}
//---------------------------------------------------------------------------------------
//Class Queen
Queen::Queen(int type){
           if(type==0){
        this->segment=sf::IntRect(68, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(68, 34, 32, 32) ;
     }
      this->sprite.setTextureRect(this->segment);
}
Queen::~Queen(){};
int Queen::update(int possouris,char c,int occupe,bool path_is_libre){
    int lastpos=this->getPosCase();
     if(c=='u' && this->getmove() && path_is_libre && occupe!=1 ){
            this->setmove(false);
         this->updateMovement('r',possouris);
         this->updateMovement('b',possouris);

     }
     if(c=='d' && this->getmove() && path_is_libre && occupe!=2 ){
           this->setmove(false);
          this->updateMovement('r',possouris);
         this->updateMovement('b',possouris);
     }
       if(!path_is_libre) return 0;
  else
  return this->getPosCase()==lastpos ? 0 : this->getPosCase() ;
}

// Class King
    King::King(int type){
    if(type==0){
        this->segment=sf::IntRect(102, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(102, 34, 32, 32);
     }
      this->sprite.setTextureRect(this->segment);
    }
    King::~King(){}
    int King::update(int possouris,char c,int occupe){
          int  lastpos=this->getPosCase();
      if(c=='u' && this->getmove()&& occupe!=1 ){
            this->setmove(false);
            this->updateMovement('k',possouris);

     }
     if(c=='d' && this->getmove() && occupe!=2 ){
           this->setmove(false);
          this->updateMovement('k',possouris);
     }

  return this->getPosCase()==lastpos ? 0 : this->getPosCase();

    }

//-----------------------------------------------------------------------------------------
// Class Knight
    Knight::Knight(int type){
         if(type==0){
        this->segment=sf::IntRect(170, 0, 32, 32);
     }
     else {
        this->segment=sf::IntRect(170, 34, 32, 32) ;
     }
      this->sprite.setTextureRect(this->segment);
    }
    Knight::~Knight(){}
    int Knight::update(int possouris,char c,int occupe){
         int  lastpos=this->getPosCase();
      if(c=='u' && this->getmove()&& occupe!=1 ){
            this->setmove(false);
            this->updateMovement('n',possouris);

     }
     if(c=='d' && this->getmove() && occupe!=2 ){
           this->setmove(false);
          this->updateMovement('n',possouris);
     }

  return this->getPosCase()==lastpos ? 0 : this->getPosCase();

    }
