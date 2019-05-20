//把A分成三部分：P前面  *  P和T中间  =  T后面
#include <iostream>
#include <string>
using namespace std;
bool judge(string s)
{
	int a[5] = { 0 };//a用来存储各个字符的出现次数
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != 'P'&& s[i] != 'A' && s[i] != 'T')return false;//PTA 都不存在
		if (s[i] == 'P')
		{
			a[0]++;
			if (a[1] != 0 || a[0] > 1)//如果P后跟的是T或a出现过多次，则匹配失败
				return false;
		}
		else if (s[i] = 'T')
		{
			a[1]++;
			if (a[0] == 0 || a[1] > 1)//如果T前没有A，或者T出现过多次，则失败
				return false;

		}
		else
		{
			if (a[0] == 0 && a[1] == 0)//如果之前PT都未出现，则将A放到记录数组的第三位上，a位于P之前
				a[2]++;
			else if (a[0] != 0 && a[1] == 0)//如果之前P出现，T未出现，则将a放入第四个记录处,a位于P之后T之前
				a[3]++;
			else
				a[4]++;	//a位于T之后
		}

	}
	if (a[0] == 0 || a[1] == 0 || a[3] == 0) {
		return false;
	}
	else if (a[3] * a[2] != a[4])//P前面  *  P和T之间 = T后面
		return false;
	else
		return true;
}
int main()
{
	int n;
	cin >> n;
	for (int i=0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (judge(s)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
