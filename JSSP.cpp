#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char key[15][10]={"if","else","else if","for","while","int","char","float","double","void","break"};
char op1[10]={'+','-','*','/','='};
char op2[10][10]={"++","--","<=",">=","==","!="};
ofstream operate("operator.txt");
ofstream fun("function.txt");

ofstream keyt("keyword.txt");

ofstream identi("identifier.txt");


string line[1000];
class symbolinfo
{
	public:
	char *symname;
	char *type;
	symbolinfo()
	{
		symname=new char[100];
		type=new char[100];
	}
	void print()
	{
		cout<<"("<<symname<<","<<type<<") ";
	}
};

char * checker(char name[100],int nline)
{
	char *ret=new char[100];
	int l=strlen(name);
	if(l==1)
	{
		int f=0;
		for(int i=0;i<5;i++)
		{
			if(op1[i]==name[0])
			{
				f=1;
				ret="operator";
				break;
			}
			
		}
		if(f==0)
		{
			ret="identifier";
		}
	}
	else if(l==2)
	{
		int f=0;
		for(int i=0;i<5;i++)
		{
			if(strcmp(op2[i],name)==0)
			{
				f=1;
				ret="operator";
				break;
			}	
			
		}
		if(f==0)
			{
				if(strcmp(name,"if")==0)
				{
					ret="keyword";
				}
				else
				{
					ret="identifier";
				}
			}
	}
	else 
	{
		int f=0;
		for(int i=0;i<=10;i++)
		{
			
			if(strcmp(name,key[i])==0)
			{
				f=1;
				ret="keyword";
			}
		}
		if(f==0)
		{
			int ind=0;
			int limit=line[nline].size();
			int c=0;
			for(int j=0;j<limit;j++)
			{
				
				if(name[c]==line[nline].at(j))
				{
					c++;
					//cout<<name[c]<<c<<" "<<j<<endl;
				}
				else
				{
					c=0;
				}
				if(c==strlen(name)-1)
				{
					ind=j;
					break;
				}
				//cout<<name[c]<<c<<" "<<strlen(name)<<endl;
			}
			cout<<ind<<endl;
			for(int j=ind;j<limit;j++)
			{
				//cout<<line[nline].at(j)<<" ";
				if(line[nline].at(j)=='(')
				{
					//cout<<"ok"<<endl;
					f=1;
					ret="function";
					break;
				}
			}
			if(f==0)
			{
				ret="identifier";
			}
			
		}
	}
	return ret;
}
class table
{
	public:
	list<symbolinfo> tab[120];
	void fprint()
	{
		list<symbolinfo> :: iterator it2;
		for(int i=0;i<=100;i++)
		{
			//cout<<"hello"<<endl;
			if(tab[i].size()>0)
			{
				cout<<(i+1)<<"-->  ";
				for(it2=tab[i].begin();it2!=tab[i].end();it2++)
				{
					it2->print();
				}
				cout<<endl;
			}
			
		}
	}
	
};

int hash(char str[])
{
	
   	int n,m;
    n=4+1;
	m=3+1;
	double s=0;
	for(int i=0;i<strlen(str);i=i+2)
	{
			double s1=0;
			s1=(double)str[i]/pow(2,n);
			s=s+s1;	
		
	}
	s=s*pow(2,m);
	int r=(int)s%101;
	return r;

}
table t;


void insert(symbolinfo v,int line)
{
//	cout<<"previous"<<endl;
//		t.fprint();
	symbolinfo var;
	var=v;
	//cout<<"calling"<<endl;
	
	int l=strlen(var.symname);
	
	if(l!=0)
	{
		
		
		int pos=hash(var.symname);
		int len=t.tab[pos].size();
		int f=0;
		{
			if(strcmp(var.type,"operator")==0)
			{
				operate<<var.symname<<"  "<<(line+1)<<endl;
			}
			else if(strcmp(var.type,"function")==0)
			{
				fun<<var.symname<<"  "<<(line+1)<<endl;
			}
			else if(strcmp(var.type,"keyword")==0)
			{
				keyt<<var.symname<<"  "<<(line+1)<<endl;
			}
			else if(strcmp(var.type,"identifier")==0)
			{
				identi<<var.symname<<"  "<<(line+1)<<endl;
			}

			t.tab[pos].push_back(var);
			
			int vsize=t.tab[pos].size();
			var.print();
			cout<<" found at line "<<(line+1)<<endl;
			var.print();
			cout<<" inserted at position "<<"("<<pos+1<<","<<vsize<<")"<<endl;
		}
		t.fprint();
	}
	
	cout<<endl;
	cout<<endl;
	
}

int main()
{
	ifstream input("sample input.txt");
	
	
	char *name=new char[100];
	
	while(getline(input,line[k]))
	{
		k++;
	}
	
	
	for(int i=0;i<k;i++)
	{
	//	cout<<"line "<<(i+1)<<" ";
		f=0;
		pflag=0;
		int l=line[i].size();
		for(int j=0;j<l;j++)
		{
			symbolinfo var;
			
			//cout<<j<<" ";
			//t.fprint();
			char ch=line[i].at(j);
			if(ch>='0' && ch<='9')
			{
				
			}
			else
			{
					if(line[i].at(j)=='#')
				{
					break;
				}	
			if(line[i].at(j)!=' ')
			{
				f=1;
			//	cout<<name<<endl;
			}
			if(f==1)
			{
				int nlen=0;
				if(pflag==1 && ch==34)
				{
					pflag=0;
				}
				else if(ch==34)
				{
					pflag=1;
				}
				 else if(pflag==0 && (ch==' ' || ch=='(' || ch==',' || ch==')' || ch=='{' || ch=='}'|| ch==';'))
				{
					
					//t.fprint();
					symbolinfo var;
					int c=0;
					for(int i=0;i<cc1;i++)
					{
						if(name[i]==' ')
						{
							
						}
						else
						{
							var.symname[c]=name[i];
							c++;
						}
						
					}
					var.symname[c]='\0';
					//t.fprint();
					
					cc1=0;
					int clen=strlen(var.symname);
					//cout<<clen<<endl;
					if(clen==0)
					{
						
					}
					else if(clen==4)
					{
						
						if(strcmp(var.symname,"else")==0)
						{
						///	cout<<"hello there"<<endl;
							var.symname[4]=line[i].at(j);
							var.symname[5]=line[i].at(j+1);
							var.symname[6]=line[i].at(j+2);
							var.symname[7]='\0';
						//	cout<<"printing "<<var.name<<endl;
							if(strcmp(var.symname,"else if")==0)
							{
								var.type="keyword";
								insert(var,i);
								j++;
								j++;
								j++;
							}
							else
							{
								var.type=checker(var.symname,i);
								insert(var,i);
							}
							
						}
						else
						{
							var.type=checker(var.symname,i);
							insert(var,i);
						}
						
					}
					else
					{
//						
						var.type=checker(var.symname,i);
						insert(var,i);
//						cout<<"after"<<endl;
//						t.fprint();
					}
				}
				else if(pflag==0)
				{
					//cout<<"printing ch "<<ch<<endl;
					
					if(ch=='+' || ch=='-' || ch=='=' || ch=='*' || ch=='/' || ch=='>' || ch=='<' || ch=='%')
					{
						symbolinfo var;
						for(int i=0;i<cc1;i++)
						{
							var.symname[i]=name[i];
						}
						var.symname[cc1]='\0';
						var.type=checker(var.symname,i);
						insert(var,i);
					
						//if(j<l-1)
						{
						///	
							cc1=0;
							char ch1=line[i].at(j+1);
							name[cc1]=ch;
							cc1++;
							name[cc1]=ch1;
							cc1++;
							name[cc1]='\0';
								int f=0;
							//cout<<name<<endl;	
							for(int i=0;i<5;i++)
							{
								if(strcmp(op2[i],name)==0)
								{
									f=1;
								//	cout<<"hello"<<endl;
									break;
								}	
								
							}
							if(f==1)
							{
								symbolinfo var;
								for(int i=0;i<2;i++)
								{
									var.symname[i]=name[i];
								}
								var.symname[2]='\0';
								var.type="operator";
								j++;
								insert(var,i);
							}
							else
							{
								symbolinfo var;
								var.symname[0]=name[0];
								var.symname[1]='\0';
								var.type="operator";
								insert(var,i);
							}
							
						}
						
						cc1=0;
					
					}
					else
					{
						if(ch==9)
						{
							
						}
						else
						{
							name[cc1]=ch;
							cc1++;
						}
						
					}
					
				//	cout<<"( "<<ch<<" )";
					
					
				}
				
					
			}
			}
		
			
		}
		cout<<endl;
	}


}