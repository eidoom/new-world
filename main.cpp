#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::endl;
using std::cin;
using std::string;
//using std::to_string;
using std::array;

struct line {
    string mesg;
    string *var;
};

class Game {
public:
    static const unsigned int len{6};
    static const unsigned int turns{1};

    string name;
    array <string, turns> dirs;

    array <line, len> story{
            line{"Welcome to the New World.\nI hope you enjoyed your journey here.", nullptr},
            line{"What is your name?", &name},
            line{"Hello " + name + ".\nWell, now that we're acquainted I guess you'll be wanting to be on your way.",
                 nullptr},
            line{"Do you want to go [left] or [right]?", &dirs[0]},
            line{"OK, " + dirs[0] + " it is", nullptr},
			line{"",nullptr},
    };
};

void print(const string mesg) {
    cout << mesg << endl;
}

int main() {
    Game game;
    for (unsigned int i{0}; i < game.len; ++i) {
        print(game.story[i].mesg);
        if (game.story[i].var != nullptr) {
            cin >> *game.story[i].var;
        }
    }
    return 0;
}
