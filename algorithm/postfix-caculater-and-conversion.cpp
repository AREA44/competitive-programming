#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int64 MaxN = 2e6+4;
const int64 inf = 1e9+7;
const int64 base = 1e9+7;

class Calculator{
private:
		bool isOperator(char character){
			if (character == '*' || character == '/' || character == '+' || character == '-') return true;
			return false;
		}

		bool isOperand(char character){
			if (!isOperator(character) && character != '('&&character != ')' && character != ' ') return true;
			return false;
		}

		int compareOperators(char Operator_1, char Operator_2){
			if ((Operator_1 == '*' || Operator_1 == '/') && (Operator_2 == '+' || Operator_2 == '-')) return -1;
			else if ((Operator_1 == '+' || Operator_1 == '-') && (Operator_2 == '*' || Operator_2 == '/')) return 1;
			return 0;
		}

		string InfixToPostfix(string Infix){
			string Postfix;stack<char> Sc;
			for (int i = 0; i < Infix.size(); i++){
				if (isOperand(Infix[i])) Postfix += Infix[i];
				else if (isOperator(Infix[i])){
					while (!Sc.empty() && Sc.top() != '(' && compareOperators(Sc.top(), Infix[i]) <= 0)
					{Postfix += Sc.top();Sc.pop();}
					Sc.push(Infix[i]);
				}
				else if (Infix[i] == '(') Sc.push(Infix[i]);
				else if (Infix[i] == ')'){
					while (!Sc.empty()){
						if (Sc.top() == '('){Sc.pop();break;}
						Postfix += Sc.top();Sc.pop();
					}
				}
			}
			while (!Sc.empty()){Postfix += Sc.top();Sc.pop();}
			return Postfix;
		}

		int performOperator(int charactor_1, int charactor_2, char charactor_3){
			if (charactor_3 == '*') return charactor_1*charactor_2;
			else if (charactor_3 == '/') return charactor_1/charactor_2;
			else if (charactor_3 == '+') return charactor_1 + charactor_2;
			else if (charactor_3 == '-') return charactor_1 - charactor_2;
		}

		int calculator(string Postfix){
			stack<int> Si;
			for (int i = 0; i < Postfix.size(); i++){
				if (isOperand(Postfix[i])) Si.push(Postfix[i] - '0');
				else if (isOperator(Postfix[i])){
					int Operand_2 = Si.top(); Si.pop();
					int Operand_1 = Si.top(); Si.pop();
					Si.push(performOperator(Operand_1, Operand_2, Postfix[i]));
				}
			}
			return Si.top();
		}
public:
	int result(string s){ return calculator(InfixToPostfix(s)); }
};

int main(){
	while (true){
		string s;
		getline(cin, s);
		Calculator Result;
		cout << Result.result(s) << endl;
	}
	return 0;
}
