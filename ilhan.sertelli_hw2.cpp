//Ilhan Sertelli

#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

string formatcheck(string a);
string parser(string b);
string correct(string a, string b, string c, string d);
string joker();
string compare(string a, string b);

string formatcheck(string a) {
	// Check if the input is written in the correct format or not
	string sign1, sub1, sub2, sub3, num1, num2, num3, before, operatorstr;
	int  len, operatorp, operatorm, operatormain, sign2, sign3, sign4, sign5, sign6, sign7, sign8, equal;
	string error = "Wrong input format! You got -10 penalty points for this math expression."; 

	sign1 = a.substr(0,1);
	len = a.length();

	if (a.length() < 5) {
		return error;
	}

	else if (a.find("=") < 3) {
		return error;
	}

	else if (a.find("=") != a.rfind("=")) {
		return error;
	}

	else if ((a.find("+") == string::npos) && (a.find("-") == string::npos)) {
		return error;
	}

	else {

		if ((sign1 != "+") && (sign1 != "-")) {
			operatorp = a.find("+", 1);
			operatorm = a.find("-", 1);

			if (operatorp == string::npos) {
				operatormain = a.find("-", 1);
			}
											
			else if (operatorm == string::npos) {
				operatormain = a.find("+", 1);
			}

			else if ((operatorp < operatorm)) {
				operatormain = operatorp;
			}

			else if ((operatorm < operatorp)) {
				operatormain = operatorm;
			}  
		}

		else {
			operatorp = a.find("+", 1);
			operatorm = a.find("-", 1);

			if ((operatorp == 1) || (operatorm == 1)) {
				return error;
			}

			else {

				if (operatorp == string::npos) {
					operatormain = operatorm;
				}

				else if (operatorm == string::npos) {
					operatormain = operatorp;
				}

				else {
					if (operatorp < operatorm) {
						operatormain = operatorp;
					}

					else if (operatorm < operatorp) {
						operatormain = operatorm;
					}
				}
			}			
		}
		
		equal = a.find("=");
		num1 = a.substr(0, operatormain);
		num2 = a.substr(operatormain + 1, (equal - operatormain - 1));
		num3 = a.substr(equal + 1);
		sub1 = num1.substr(0, 1);
		sub2 = num2.substr(0, 1);
		sub3 = num3.substr(0, 1);
		operatorstr = a.at(operatormain);

		if ((num1 == "") || (num2 == "") || (num3 == "")) {
			return error;
		}

		else {
			if (sub1 == "+") {
				if ((itoa(atoi(num1)).length() + 1) != num1.length()) {
					return error;
				}
			}
			else if (sub1 == "-") {
				if (itoa(atoi(num1)) != num1) {
					return error;
				}
			}
			else if ((sub1 != "+") && (sub1 != "-")) { 
				if (itoa(atoi(num1)) != num1) {
					return error;
				}
			}
			if (sub2 == "+") { 
				if ((itoa(atoi(num2)).length() + 1) != num2.length()) {
					return error;
				}
			}
			else if (sub2 == "-") {
				if (itoa(atoi(num2)) != num2) {
					return error;
				}
			}
			else if ((sub2 != "+") && (sub2 != "-")) {
				if (itoa(atoi(num2)) != num2) {
					return error;
				}
			}
			if (sub3 == "+") {
				if ((itoa(atoi(num3)).length() + 1) != num3.length()) {
					return error;
				}
			}
			else if (sub3 == "-") {
				if (itoa(atoi(num3)) != num3) {
					return error;
				}
			}
			else if ((sub3 != "+") && (sub3 != "-")) {
				if (itoa(atoi(num3)) != num3) {
					return error;
				}
			}				
		}
	}
	return "i";
}

string parser(string b) {
	string sign1, num1, num2, num3, equalstr, operatorstr;
	int operatormain, operatorp, operatorm, equal;

	equal = b.find("=");
	equalstr = b.at(equal);
	sign1 = b.substr(0, 1);

	if (((sign1) != "+") && (sign1 != "-")) {
		operatorp = b.find("+");
		operatorm = b.find("-");

		if (operatorp == string::npos) {
			operatormain = b.find("-", 1);
		}											
		else if (operatorm == string::npos) {
			operatormain = b.find("+", 1);
		}
		else if ((operatorp < operatorm)) {
			operatormain = operatorp;				
		}
		else if ((operatorm < operatorp)) {
			operatormain = operatorm;		  
		}
	}

	else {
		operatorp = b.find("+", 1);
		operatorm = b.find("-", 1);

		if (operatorp == string::npos) {
			operatormain = operatorm;
		}
		
		else if (operatorm == string::npos) {
			operatormain = operatorp;
		}

		else {
			if (operatorp < operatorm) {
				operatormain = operatorp;
			}

			else if (operatorm < operatorp) {
				operatormain = operatorm;
			}
		}
	}

	num1 = b.substr(0, operatormain);
	num2 = b.substr(operatormain + 1, (equal - operatormain - 1));
	num3 = b.substr(equal + 1, (b.length() - equal - 1));
	equalstr = b.at(equal);
	operatorstr = b.at(operatormain);

	return correct(num1, operatorstr, num2, num3);
}  

string correct(string a, string b, string c, string d) {
	int num1, num2, num3, answer;
	string correct = "Correct answer! You got 25 points for this math expression.";
	string wrong, answerstr;

	num1 = atoi(a);
	num2 = atoi(c);
	num3 = atoi(d);
	
	if (b == "+") {
		answer = num1 + num2;

		if (answer == num3) {
			return correct;
		}
		else {
			answerstr = itoa(answer);
			wrong = "Sorry! The answer should have been: " + answerstr + ". You got ";
			return wrong;
			
		}
	}

	else if (b == "-") {
		answer = num1 - num2;

		if (answer == num3) {
			return correct;
		}
		else {		
			answerstr = itoa(answer);
			wrong = "Sorry! The answer should have been: " + answerstr + ". You got ";
			return wrong;		
		}
	}
	return "";
} 

string joker() {
	string ask = "Wrong!\nWould you like to use your joker option to correct the answer? ";
	return ask;
}

string compare(string a, string b) {
	string before1, before2, error;
	error = "Wrong input format! You got -10 penalty points for this math expression.";

	before1 = a.substr(0, a.find("="));
	before2 = b.substr(0, a.find("="));

	if (before1 != before2) {
		return error;
	}
	else {
		return parser(b);
	}
	return "";
}

int main() {
	int attempt = 1;
	int totalpoint = 0;
	string mainstr, choice, lowerchoice, otherstr;
	
	//take the main input from the user
	cout << "Please enter question #1 and its answer: ";
	cin >> mainstr;

	if (formatcheck(mainstr) != "Wrong input format! You got -10 penalty points for this math expression.") {
		if ((parser(mainstr) != "Correct answer! You got 25 points for this math expression.")) {
			if (attempt == 1) {
				cout << joker();
				cin >> choice;
				ToLower(choice);
				if (choice == "yes") {
					attempt = 0;
					cout << "Please enter the expression again: ";
					cin >> otherstr;
					if (formatcheck(otherstr) != "i") {
						totalpoint -= 10;
						cout << "Wrong input format! You got -10 penalty points for this joker option." << endl;
						cout << endl;
					}
					else {
						if (compare(mainstr, otherstr) == "Correct answer! You got 25 points for this math expression.") {
							totalpoint += 25;
							cout << "Correct answer! You got 25 points for this joker option." << endl;
							cout << endl;
						}
						else {
							cout << parser(otherstr) << "-10 penalty points for this joker option." << endl;
							cout << endl;
							totalpoint -= 10;
						}
					}
				}
				else if (choice == "no") {
					cout << parser(mainstr)<< "0 points for this math expression." << endl;
					cout << endl;
				}
			}
			else {
				cout << parser(mainstr) << "0 points for this math expression." << endl;
				cout << endl;
			}
		}
		else {
			cout << parser(mainstr) << endl;
			cout << endl;
			totalpoint += 25;
		}
	}

	else {
		cout << formatcheck(mainstr);
		cout << endl;
		cout << endl;
		totalpoint -= 10;
	}

	cout << "Please enter question #2 and its answer: ";
	cin >> mainstr;

	if (formatcheck(mainstr) != "Wrong input format! You got -10 penalty points for this math expression.") {
		if ((parser(mainstr) != "Correct answer! You got 25 points for this math expression.")) {
			if (attempt == 1) {
				cout << joker();
				cin >> choice;
				ToLower(choice);
				if (choice == "yes") {
					attempt = 0;
					cout << "Please enter the expression again: ";
					cin >> otherstr;
					if (formatcheck(otherstr) != "i") {
						totalpoint -= 10;
						cout << "Wrong input format! You got -10 penalty points for this joker option." << endl;
						cout << endl;
					}
					else {
						if (compare(mainstr, otherstr) == "Correct answer! You got 25 points for this math expression.") {
							totalpoint += 25;
							cout << "Correct answer! You got 25 points for this joker option." << endl;
							cout << endl;
						}
						else {
							cout << parser(otherstr) << "-10 penalty points for this joker option." << endl;
							cout << endl;
							totalpoint -= 10;
						}
					}
				}
				else if (choice == "no") {
					cout << parser(mainstr) << "0 points for this math expression." << endl;
					cout << endl;
				}
			}
			else {
				cout << parser(mainstr) << "0 points for this math expression." << endl;
				cout << endl;
			}
		}
		else {
			cout << parser(mainstr) << endl;
			cout << endl;
			totalpoint += 25;
		}
	}

	else {
		cout << formatcheck(mainstr);
		cout << endl;
		cout << endl;
		totalpoint -= 10;
	}

	cout << "Please enter question #3 and its answer: ";
	cin >> mainstr;

	if (formatcheck(mainstr) != "Wrong input format! You got -10 penalty points for this math expression.") {
		if ((parser(mainstr) != "Correct answer! You got 25 points for this math expression.")) {
			if (attempt == 1) {
				cout << joker();
				cin >> choice;
				ToLower(choice);
				if (choice == "yes") {
					attempt = 0;
					cout << "Please enter the expression again: ";
					cin >> otherstr;
					if (formatcheck(otherstr) != "i") {
						totalpoint -= 10;
						cout << "Wrong input format! You got -10 penalty points for this joker option." << endl;
						cout << endl;
					}
					else {
						if (compare(mainstr, otherstr) == "Correct answer! You got 25 points for this math expression.") {
							totalpoint += 25;
							cout << "Correct answer! You got 25 points for this joker option." << endl;
							cout << endl;
						}
						else {
							cout << parser(otherstr) << "-10 penalty points for this joker option." << endl;
							cout << endl;
							totalpoint -= 10;
						}
					}
				}
				else if (choice == "no") {
					cout << parser(mainstr) << "0 points for this math expression." << endl;
					cout << endl;
				}
			}
			else {
				cout << parser(mainstr) << "0 points for this math expression." << endl;
				cout << endl;
			}
		}
		else {
			cout << parser(mainstr) << endl;
			cout << endl;
			totalpoint += 25;
		}
	}

	else {
		cout << formatcheck(mainstr);
		cout << endl;
		cout << endl;
		totalpoint -= 10;
	}

	cout << "Please enter question #4 and its answer: ";
	cin >> mainstr;

	if (formatcheck(mainstr) != "Wrong input format! You got -10 penalty points for this math expression.") {
		if ((parser(mainstr) != "Correct answer! You got 25 points for this math expression.")) {
			if (attempt == 1) {
				cout << joker();
				cin >> choice;
				ToLower(choice);
				if (choice == "yes") {
					attempt = 0;
					cout << "Please enter the expression again: ";
					cin >> otherstr;
					if (formatcheck(otherstr) != "i") {
						totalpoint -= 10;
						cout << "Wrong input format! You got -10 penalty points for this joker option." << endl;
						cout << endl;
					}
					else {
						if (compare(mainstr, otherstr) == "Correct answer! You got 25 points for this math expression.") {
							totalpoint += 25;
							cout << "Correct answer! You got 25 points for this joker option." << endl;
							cout << endl;
						}
						else {
							cout << parser(otherstr) << "-10 penalty points for this joker option." << endl;
							cout << endl;
							totalpoint -= 10;
						}
					}
				}
				else if (choice == "no") {
					cout << parser(mainstr) << "0 points for this math expression." << endl;
					cout << endl;
				}
			}
			else {
				cout << parser(mainstr) << "0 points for this math expression." << endl;
				cout << endl;
			}
		}
		else {
			cout << parser(mainstr) << endl;
			cout << endl;
			totalpoint += 25;
		}
	}

	else {
		cout << formatcheck(mainstr);
		cout << endl;
		cout << endl;
		totalpoint -= 10;
	}

	if (totalpoint < 0) {
		totalpoint = 0;
	}

	cout << "End of the program. You got " << totalpoint << " points in total." << endl;
	
	return 0;
}

