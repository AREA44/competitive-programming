#include "iostream"
#include "stdio.h"
#include "string.h"
#include "string"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "math.h"
#include "map"
using namespace std;

string a, b;
int c;

string BigNum_add(string a, string b){
	string result = "";
	while (a.size()<b.size()) a = "0" + a;
	while (a.size()>b.size()) b = "0" + b;
	int l=a.size()-1, carry = 0;
	for (int i = l; i >= 0; i--){
		int temp = (a[i] - 48) + (b[i] - 48) + carry;
		result = (char)(temp % 10+48) + result;
		carry = temp/ 10;
	}
	if (carry>0)	result = "1" + result;
	return result;
}

string BigNum_sub(string a, string b){
	string result = "";
	while (a.size()<b.size()) a = "0" + a;
	while (a.size()>b.size()) b = "0" + b;
	int l = a.size()-1, borrow = 0;
	bool neg = false;
	if (a < b){
		swap(a, b);
		neg = true;
	}
	for (int i = l; i >= 0; i--){
		int temp = a[i] - b[i] - borrow;
		if (temp < 0){
			temp += 10;
			borrow = 1;
		}
		else	borrow = 0;
		result = (char)(temp % 10 + 48) + result;
	}
	while (result.size()>1 && result[0] == '0') result.erase(0, 1);
	if (neg == true)	result = "-" + result;
	return result;
}

string BigNum_mul(string a, string b){
	string result = "";
	int la = a.size(), lb = b.size();
	int l = la + lb,carry=0;
	for (int i = l - 1; i >= 0; i--){
		int temp = 0;
		for (int j = la - 1; j >= 0; j--){
			if (i - j <= lb && i - j >= 1)
				temp += (a[j] - 48)*(b[i - j - 1] - 48);
		}
		temp += carry;
		result = (char)(temp % 10 + 48) + result;
		carry = temp / 10;
	}
	while (result.size() >= 1 && result[0] == '0') result.erase(0, 1);
	return result;
}

string BigNum_pow(string a, int b){
	string result = "1";
	for (int i = 1; i <= b; i++)	result = BigNum_mul(result, a);
	return result;
}

string Bignum_div(string s,int number){
    string result;
    int pre=0, cur;
    for(int i=0;i<s.size();i++){
        pre=pre*10+s[i]-'0';
        cur=(char)(pre/number+48);
        result+=cur;
        pre=pre-number*(cur-'0');
    }
    if(pre==0){
        while(result[0]=='0') result.erase(0,1);
        return result;
    }
    else return "-1";
}

int main(){
	cin >> a >> b>>c;
	cout << BigNum_add(a, b) << endl;
	cout << BigNum_sub(a, b) << endl;
	cout << BigNum_mul(a, b) << endl;
	cout << BigNum_pow(a, c) << endl;
	cout << BigNum_div(a, c) << endl;
	return 0;
}
