#include "starter.h"
#include <SFML/Graphics.hpp>

using namespace sf;

//constructor & destructors
Starter::Starter()
{
    window = new RenderWindow(sf::VideoMode(720,480),"Chess by H.M & I.B",Style::Close | Style::Titlebar);
    setSprites();
    exit=false;
}
Starter::~Starter()
{
    delete  window;
}
bool Starter::get_is_exit()
{
    return exit;
}
void Starter::setSprites()
{
    //bg
    if (! t_background.loadFromFile("images/SFML_GAME_BACKGROUND.png"))
    {
        cout << "ERROR::STARTER::setSprites t_background" << endl;
    }
    s_background.setTexture(t_background);
    //frame
    t_frame.loadFromFile("images/SFML_GAME_FRAME.png");
    s_frame.setTexture(t_frame);

    s_frame.setPosition(0,0);
    s_frame.setPosition(window->getSize().x / 2,window->getSize().y / 2);
    //set origin and centering
    Rect<float> size_frame = s_frame.getGlobalBounds();
    s_frame.setOrigin(Vector2f(size_frame.width/2,size_frame.height/2));

    s_frame.setScale (3.3, 3.3);
    //path indexer
    t_path.loadFromFile("images/filter_path.png");
    s_path.setTexture(t_path);
    s_path.setScale (3, 3);
    s_path.setPosition(0,0);
    //path target
    t_target.loadFromFile("images/filter_target.png");
    s_target.setTexture(t_target );
    s_target.setScale (3, 3);
    s_target.setPosition(0,0);
    //button-start
    //char btn_str_start[]="images/SFML_GAME_BUTTON_START.png";
    t_btn_start.loadFromFile("images/SFML_GAME_BUTTON_START.png");
    s_btn_start.setTexture(t_btn_start);
    s_btn_start.setPosition((window->getSize().x /2) - 70,(window->getSize().y/3) - 50);
    s_btn_start.setScale(3, 3);
    //button-start-hover
    t_btn_start_hover.loadFromFile("images/SFML_GAME_BUTTON_START_HOVER.png");
    s_btn_start_hover.setTexture(t_btn_start_hover);
    s_btn_start_hover.setPosition(s_btn_start.getPosition());
    s_btn_start_hover.setScale(3, 3);
    //button-about
    //char btn_str_start[]="images/SFML_GAME_BUTTON_START.png";
    t_btn_about.loadFromFile("images/SFML_GAME_BUTTON_ABOUT.png");
    s_btn_about.setTexture(t_btn_about);
    s_btn_about.setPosition((window->getSize().x /2) - 70,(window->getSize().y/3) +40);
    s_btn_about.setScale(3, 3);

    //button-about-hover
    t_btn_about_hover.loadFromFile("images/SFML_GAME_BUTTON_ABOUT_HOVER.png");
    s_btn_about_hover.setTexture(t_btn_about_hover);
    s_btn_about_hover.setPosition(s_btn_about.getPosition());
    s_btn_about_hover.setScale(3, 3);
    //button-exit
    //char btn_str_start[]="images/SFML_GAME_BUTTON_START.png";
    t_btn_exit.loadFromFile("images/SFML_GAME_BUTTON_EXIT.png");
    s_btn_exit.setTexture(t_btn_exit);
    s_btn_exit.setPosition((window->getSize().x /2) - 70,(window->getSize().y/3) +130);
    s_btn_exit.setScale(3, 3);

    //button-exit-exit
    t_btn_exit_hover.loadFromFile("images/SFML_GAME_BUTTON_EXIT_HOVER.png");
    s_btn_exit_hover.setTexture(t_btn_exit_hover);
    s_btn_exit_hover.setPosition(s_btn_exit.getPosition());
    s_btn_exit_hover.setScale(3, 3);

    //about section
    t_about_section.loadFromFile("images/SFML_GAME_ABOUT.png");
    s_about_section.setTexture(t_about_section);
    s_about_section.setPosition(0,0);

    s_about_section.setPosition(window->getSize().x / 2,window->getSize().y / 2);
    //set origin and centering
    Rect<float> size_about_section = s_about_section.getGlobalBounds();
    s_about_section.setOrigin(Vector2f(size_about_section.width/2,size_about_section.height/2));
    s_about_section.setScale (3.3, 3.3);

    //avatars
    t_avatar_hicham.loadFromFile("images/AVATAR_HICHAM.png");
    s_avatar_hicham.setTexture(t_avatar_hicham);

    t_avatar_imad.loadFromFile("images/AVATAR_IMAD.png");
    s_avatar_imad.setTexture(t_avatar_imad);
}
void Starter::about()
{
    bool no_click=true;
    while(no_click){
        Event ev;
        while (window->pollEvent(ev))
        {
            if(ev.type == Event::MouseButtonPressed)
            {
                if(ev.key.code == Mouse::Button::Left)
                {
                    no_click =false;
                }
            }
        }
        window->clear(Color::White);
        window->draw(s_background);
        window->draw(s_about_section);
        //position and scale avatars
        s_avatar_hicham.setPosition((window->getSize().x/2)-192/2,window->getSize().y-192/2);
        s_avatar_imad.setPosition((window->getSize().x/2)+192/2,window->getSize().y-192/2);
        s_avatar_hicham.setScale(0.25,0.25);
        s_avatar_imad.setScale(0.25,0.25);

        window->draw(s_avatar_hicham);
        window->draw(s_avatar_imad);
        window->display();
    }
}
void Starter::home_event_lestener(bool (&poq)[3],bool &out)
{
    Event e;
    while (window->pollEvent(e))
    {
        poq[0]=false;
        poq[1]=false;
        poq[2]=false;

        switch(e.type)
        {
        case Event::Closed:
            window->close();
            break;
        case Event::MouseMoved:
            if (s_btn_start_hover.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
            {
                poq[0]=true;
            }
            if (s_btn_about_hover.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
            {
                poq[1]=true;
            }
            if (s_btn_exit_hover.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
            {
                poq[2]=true;
            }
            break;
        case Event::MouseButtonPressed:
            if (e.key.code == Mouse::Button::Left)
            {
                if (s_btn_start.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
                {
                    out=true;
                }
                if (s_btn_about.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
                {
                    about();
                }
                if (s_btn_exit.getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
                {
                    //out=true;
                    out=true;
                    exit=true;
                }
            }
            if (e.key.code == Mouse::Button::Right)
            {
                s_path.setPosition(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y);
                s_target.setPosition(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y);
            }
            break;
        case Event::KeyPressed:
            if(e.key.code == Keyboard::A)
            {
                out=true;
            }
            break;
        default:
            break;
        }
    }
}
void Starter::home()
{

    bool intered=false;
    bool poq[3]= {false,false,false}; //0 start 1 about 2 exit
    bool out=false;

    while ( (window->isOpen()) && !out) // || or && and
    {
        //Event_Lestener
        home_event_lestener(poq,out);

        //drawer
        window->clear(Color::White);

        window->draw(s_background);

        window->draw(s_frame);

        if(!poq[0])
        {
            window->draw(s_btn_start);
        }
        else
        {
            window->draw(s_btn_start_hover);
        }
        if(!poq[1])
        {
            window->draw(s_btn_about);
        }
        else
        {
            window->draw(s_btn_about_hover);
        }
        if(!poq[2])
        {
            window->draw(s_btn_exit);
        }
        else
        {
            window->draw(s_btn_exit_hover);
        }

        window->display();

    }
}
void Starter::run()
{
    home();
}
