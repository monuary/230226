#include<iostream>
using namespace std;

class SoSimple
{
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple(const SoSimple& copy) :num(copy.num) { cout << "Called SoSimple(const SoSimple&copy)" << endl; }
	SoSimple& AddNum(int n) { num += n; return*this; }
	void ShowData() { cout << "num: " << num << endl; }
};
SoSimple SimpleFuncObj(SoSimple ob) { cout << "return 이전" << endl; return ob; }	//ob=obj; -> SimpleFuncObj=ob;(return ob에서)

int main()
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();	//num이 2개. obj.num과 SimpleFuncObj.num
	return 0;
}