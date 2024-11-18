#include "game.h"


int main()
{
    Starter start;
    //cout << "Got start constructor()" <<endl;
    start.run();
    cout << "got start construct()" << endl;

    Game game(start.window);
    cout << "got game construct()" << endl;

    //tester(start.window);
    while(!game.get_is_exit() && !start.get_is_exit()){
        game.set_is_exit(false);
        cout << "got set_is_exit()" << endl;
      //game.reset();

        //game.save_score() in the run function
        game.run();
    }
    cout << "while exit" << endl;

    exit(0);
    //return 0; won't work
}
