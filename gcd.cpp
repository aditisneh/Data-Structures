#include<iostream>
using namespace std;

	int gcd(int a,int b)
	{
        int anot;
		if(b==0)
		return a;
		anot = a%b;
		return gcd(b,anot);
	}
	int main(){
	
	int x,y;
	cin>>x;
	cin>>y;
	cout<<gcd(x,y);
	return 0;
}
