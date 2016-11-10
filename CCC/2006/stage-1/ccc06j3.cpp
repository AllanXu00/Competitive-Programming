#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <algorithm>

#pragma warning(disable:4996)

using std::cin;
using std::endl;
using std::cout;
using std::vector;

typedef std::pair<int, int> intpair; //first is category, second is num seconds

std::map<char, intpair> buttons;

#define mp(x, y) (std::make_pair(x, y))

void initialize() { //most of the work is here
	buttons['a'] = mp(2, 1);
	buttons['b'] = mp(2, 2);
	buttons['c'] = mp(2, 3);
	buttons['d'] = mp(3, 1);
	buttons['e'] = mp(3, 2);
	buttons['f'] = mp(3, 3);
	buttons['g'] = mp(4, 1);
	buttons['h'] = mp(4, 2);
	buttons['i'] = mp(4, 3);
	buttons['j'] = mp(5, 1);
	buttons['k'] = mp(5, 2);
	buttons['l'] = mp(5, 3);
	buttons['m'] = mp(6, 1);
	buttons['n'] = mp(6, 2);
	buttons['o'] = mp(6, 3);
	buttons['p'] = mp(7, 1);
	buttons['q'] = mp(7, 2);
	buttons['r'] = mp(7, 3);
	buttons['s'] = mp(7, 4);
	buttons['t'] = mp(8, 1);
	buttons['u'] = mp(8, 2);
	buttons['v'] = mp(8, 3);
	buttons['w'] = mp(9, 1);
	buttons['x'] = mp(9, 2);
	buttons['y'] = mp(9, 3);
	buttons['z'] = mp(9, 4);
	buttons['-'] = mp(0, 1);
}

int main() {
	initialize();
	std::string input;
	while (1) {
		cin >> input;
		if (input == "halt") {
			break;
		}

		int result = buttons[input[0]].second;
		for (int a = 1; a < input.size(); a++) {
			result += buttons[input[a]].second;
			if (buttons[input[a]].first == buttons[input[a - 1]].first){
				result += 2;
			}
		}
		cout << result << endl;

	}
}
