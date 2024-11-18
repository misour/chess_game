#ifndef STARTER_H
#define STARTER_H
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include <iostream>

using namespace std ;
using namespace sf ;

class Starter {
private:

    //Variables
        //bg
    Sprite s_background;    Texture t_background;
    Sprite s_frame;     Texture t_frame;
        //path
    Sprite s_path;      Texture t_path;
    Sprite s_target;    Texture t_target;
        //btn
    Sprite s_btn_start;     Texture t_btn_start;
    Sprite s_btn_start_hover;   Texture t_btn_start_hover;
    Sprite s_btn_exit;      Texture t_btn_exit;
    Sprite s_btn_exit_hover;    Texture t_btn_exit_hover;
    Sprite s_btn_about;     Texture t_btn_about;
    Sprite s_btn_about_hover;   Texture t_btn_about_hover;

        //avatars
    Sprite s_avatar_hicham;     Texture t_avatar_hicham;
    Sprite s_avatar_imad;     Texture t_avatar_imad;
        //about-section
    Sprite s_about_section;     Texture t_about_section;




    bool exit;


    //Sprite s_btn_setting;

    //int counter;

    //private function
    void setSprites();

public:
    //constructor & destructors
    Starter();
    ~Starter();  //it was virtual so ask your partner why
    //Getter window
    RenderWindow * window;

    bool get_is_exit();
    //function
    void run();//con home()
    void home(); //about() exit-event start()
    void home_event_lestener(bool (&poq)[3],bool &out);

    void about();
    //should contain all the drawing methods

};



#endif // Starter_H

