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

void title(const string mesg) {
	print("# " + mesg);
}

class Game {
	private:
		unsigned int chapNum{1};
		const unsigned int nameMaxLen{6};
		const string separator{":"};
		string host{"Figure"};
		string name{"You"};
		vector<char> dirs;

	public:
		string intToStr(const unsigned int num) {
			switch(num) {
				case 1:
					return "one";
				case 2:
					return "two";
				case 3:
					return "three";
				case 4:
					return "four";
				case 5:
					return "five";
				case 6:
					return "six";
				default:
					return "";
			}
		}

		void chapter() {
			title("Chapter " + intToStr(chapNum++));	
		}

		void say(const string mesg) {
			string tmp{host + separator};
			for (unsigned int i{0}; i <= nameMaxLen - host.size(); ++i) {
				tmp += " ";
			}
			print(tmp + mesg);
		}

		void ask(const string question) {
			say(question);
			cout << name + separator;
			for (unsigned int i{0}; i <= nameMaxLen - name.size(); ++i) {
				cout << " ";
			}
		}

		void setName() {
			string tmp;
			cin >> tmp;
			while (tmp.size() > nameMaxLen) {
				say("Sorry, people round here don't have names with more than " + intToStr(nameMaxLen) + " letters.");
				ask("Better choose a local name so you fit in, eh?");
				cin >> tmp;
			}
			name = tmp;
		}

		string getName() {
			return name;
		}

		string getHost() {
			return host;
		}

		void setHost(const string hostName) {
			host = hostName;
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

	game.chapter();

	print(
			"You arrive at the gate. "
			"The sky hangs heavy not far above. "
			"A solemn figure stands before you. "
			"They draw a breath of the stale air to address you."
			);


	game.say("Welcome to the New World.");
	game.say("I do hope you enjoyed your journey here.");
	string theHost{"Host"};
	game.say("I am " + theHost + ".");
	game.setHost(theHost);
	game.ask("May I take your name?");
	game.setName();
	game.say("Hello " + game.getName() + ".");
	game.say("Well, now that we're acquainted I guess you'll be wanting to be on your way.");

	print(
			theHost + " lifts a limp arm to gesture behind them. "
			"The gate peels open, the screech of ancient steel echoing around you. "
			"You feel the air pressure rise as a wave of sticky warmth rolls over you. "
			"You pass through the aperture."
		 );

	game.chapter();

	// game.ask("Would you prefer to go [l]eft or [r]ight?");
	// game.setDir();
	// game.say("OK, " + game.getDir(0) + " it is.");
	// game.say("");

	return 0;
}
