#include <iostream>
#include <string>
//#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
//using std::to_string;
//using std::array;
using std::vector;

//struct line {
//    string mesg;
//    string *var;
//};

void print(const string mesg) {
	cout << mesg << endl;
}

class Game {
	private:
		string name;
		vector<char> dirs;

	public:
		void setName() {
			cin >> game.name;
		}

		string getName() {
			return name;
		}

		void setDir() {
			char tmp;
			cin >> tmp;
			while (!(tmp == 'l' || tmp == 'r')) {
				print("Sorry, you can only go [l]eft or [r]ight. Which would you like?");
				cin >> tmp;
			}	
			dirs.push_back(tmp);
		}

		string getDir(const unsigned int num) {
			switch(dirs[num]) {
				case 'l':
					return "left";
				case 'r':
					return "right";
				default:
					return "";
			}
		}

};

int main() {
	Game game;

	print("Welcome to the New World.\nI hope you enjoyed your journey here.");
	print("What is your name?");
	game.setName;
	print("Hello " + game.getName() + ".\nWell, now that we're acquainted I guess you'll be wanting to be on your way.");
	print("Do you want to go [l]eft or [r]ight?");
	game.setDir();
	print("OK, " + game.getDir(0) + " it is.");
	print("");

	return 0;
}
