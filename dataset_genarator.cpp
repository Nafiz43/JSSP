#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=500;

	for (int i = 0; i <= 9; ++i)
	{
		std::string s1="dataset_";
		s1.push_back((char)(i+'0'));
		s1=s1+ ".txt";
	//	cout<<s1<<endl;
		freopen(s1.c_str(),"w",stdout);
		cout<<n<<endl;
		for (int i = 1; i <= n; i++)
		{
			int p=rand()%100;
			int q=p+rand()%(1000-p);
			
			cout<<i<<" "<<p<<" "<<q<<endl;
		}
	}
	
	//cout<<"Imtiaz"<<endl;


}
