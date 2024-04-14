
#include "../Project1/Postfix.h"
#include "../Project1/Stack.h"
#include <stdexcept>

TPostfix::TPostfix(string infx) {
	if (infx.empty())
		throw "Stack is empty";
	infix = infx;
	ToPostfix();
}

string TPostfix::GetInfix() {
	return infix;
}

vector<string> TPostfix::GetPostfix() {
	return postfix;
}

void TPostfix::Parse() {
	string tmp = "";
	bool polynom_flag = false;
	for (char c : infix) {
		switch (c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			if (polynom_flag) {
				tmp += c;
				continue;
			}
			if (!tmp.empty()) {
				lexems.push_back(tmp);
			}
			lexems.push_back(string{ c });
			tmp = "";
			break;
		case '{':
			polynom_flag = true;
			break;
		case '}':
			polynom_flag = false;
			break;
		default:
			tmp += c;
		}
	}
	if (!tmp.empty()) {
		lexems.push_back(tmp);
	}
}

map<char, int>TPostfix::priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

void TPostfix::ToPostfix() {
	Parse();
	MyStack<string> st;
	string stackItem;
	bool operand_flag = false;
	int current_priority;
	for (auto& item : lexems) {
		current_priority = priority[item[0]];
		switch (item[0]) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Pop();
			while (stackItem != "(") {
				postfix.push_back(stackItem);
				stackItem = st.Pop();
			}
			break;
		case '+':
		case '-': 
			if (!operand_flag) {
				postfix.push_back("0");
				current_priority = 4;
			}
		case '*':
		case '/':
			while (!st.IsEmpty()) {
				stackItem = st.Pop();
				if (current_priority <= priority[stackItem[0]]) {
					postfix.push_back(stackItem);
				}
				else {
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
			operand_flag = false;
			break;
		default:
			postfix.push_back(item);
			operand_flag = true;
			break;
		}
	}
	while (!st.IsEmpty()) {
		stackItem = st.Pop();
		postfix.push_back(stackItem);
	}
}

bool isDigitPost(string lec) {
	if (lec >= "0" && lec <= "9") return true;
	else return false;
}

double TPostfix::Calculate(AbstractTable* polynoms, double x, double y, double z) {
	if (polynoms == nullptr) {
		cout << "this table is not inherited from an abstract class" << endl;
		return 0;
	}
	MyStack<double> st;
	double t;
	Polynom p;
	double leftOperand, rightOperand;
	for (const string& lexem : postfix)
	{
		const char c = lexem[0];
		switch (c)
		{
		case '+':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand / rightOperand);
			break;
		default:
			if (isDigitPost(lexem)) st.Push(stod(lexem));
			else {
				p = polynoms->search(lexem);
				t = p.calcPolynom(x, y, z);
				st.Push(t);
			}
			break;
		}
	}
	return st.Pop();
}

ostream& operator<<(ostream& o, TPostfix& p) {
	for (string s : p.postfix) {
		o << s << " ";
	}
	return o;
}