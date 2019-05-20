
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 2018.5.20 10:00
int main(void){
	string s[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

	while(!cin.eof()){
		string str;
		cin>>str;

		int x = 0;
		for(unsigned int i=0;i<str.size();++i){
			x += (str[i]-'0');
		} // x 整形

		stack<int> st;
		while(x!=0){
			st.push(x%10);//求余后压入栈
			x /= 10;//x除10
		}

		// out
		while(!st.empty()){
			cout<<s[st.top()];
			st.pop();
			if(!st.empty()){
				cout<<" ";
			}else{
				cout<<endl;
			}
		}
	}
	return 0;
}
