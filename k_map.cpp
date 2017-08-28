/*
	Author:Upendra Singh Bartwal
	
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct node
{
		int x,y;
}node;
typedef struct octate
{
	string minterm;
	node unit[8]; 
}octate;
typedef struct quad
{
	string minterm;
	node unit[4];
}quad;
typedef struct pairr
{
	string minterm;
	node unit[2];
}pairr;
typedef struct one
{
	string minterm;
	node unit;
}one;
int main()
{
	ofstream fp1;
	ifstream fp2;
	string minnterm;
	int i,j,count0,count1,octcount=0,quadcount=0,paircount=0,x,y,k;
	octate oct[8];
	quad arr[24];
	pairr pa[32];
	one u[16];
	int k_map[4][4];
	{
	ifstream cin("input.txt");	
	
	for(i=0;i<8;i++)
	{
		cin>>oct[i].minterm;
		for(j=0;j<8;j++)
		{
			cin>>oct[i].unit[j].x;
			cin>>oct[i].unit[j].y;
		}
	}
	for(i=0;i<24;i++)
	{
		cin>>arr[i].minterm;
		for(j=0;j<4;j++)
		{
			cin>>arr[i].unit[j].x;
			cin>>arr[i].unit[j].y;
		}
	}
	for(i=0;i<32;i++)
	{
		cin>>pa[i].minterm;
		for(j=0;j<2;j++)
		{
			cin>>pa[i].unit[j].x;
			cin>>pa[i].unit[j].y;
		}
	}
	for(i=0;i<16;i++)
	{
		cin>>u[i].minterm;
		cin>>u[i].unit.x;
		cin>>u[i].unit.y;
	}
}
	count0=0;count1=0;
	cout<<"Please enter the 0 and 1 in K-Map of 4X4::Note: it can not handle don't care::\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cin>>k_map[i][j];
			if(k_map[i][j]==1)
			count1++;
			else
			count0++;
		}
	}
	if(count1==16)
	{
		cout<<"Given k_map is tautology";
		return 0;
	}
	if(count0==16)
	{
		cout<<"Given k_map is contradiction";
		return 0;
	}
	fp1.open("output.txt");
	count1=0;
	for(i=0;i<8;i++)
	{
			count1=0;
		for(j=0;j<8;j++)
		{
		
			if(k_map[oct[i].unit[j].x][oct[i].unit[j].y]==1)
			{
				count1++;
			}
		}
		if(count1==8)
		{
			octcount++;
			minnterm=minnterm+"+"+oct[i].minterm;
			for(j=0;j<8;j++)
			{
				fp1<<oct[i].unit[j].x<<" "<<oct[i].unit[j].y<<" ";
			}
			fp1<<endl;
		}
	}
	fp1.close();	
	for(i=0;i<24;i++)
	{
		count1=0;
		for(j=0;j<4;j++)
		{
			if(k_map[arr[i].unit[j].x][arr[i].unit[j].y]==1)
			{
				count1++;
			}
		}
		if(count1==4)
		{
			count1=0;
			for(j=0;j<4;j++)
			{
				
				fp2.open("output.txt");
				for(k=0;k<octcount*8+quadcount*4;k++)
				{
					fp2>>x>>y;
					if(x==arr[i].unit[j].x&&y==arr[i].unit[j].y)
					{
						count1++;
						break;
					}
				}
				fp2.close();
			}
			if(count1<4)
			{
				quadcount++;
				minnterm=minnterm+"+"+arr[i].minterm;
				fp1.open("output.txt",ios_base::app);
				for(j=0;j<4;j++)
			{
				fp1<<arr[i].unit[j].x<<" "<<arr[i].unit[j].y<<" ";
			}
			fp1<<endl;
			fp1.close();
			}
		}
	}	
		
	for(i=0;i<32;i++)
	{
		count1=0;
		for(j=0;j<2;j++)
		{
			if(k_map[pa[i].unit[j].x][pa[i].unit[j].y]==1)
			{
				count1++;
			}
		}
		if(count1==2)
		{
			count1=0;
			for(j=0;j<2;j++)
			{
				
				fp2.open("output.txt");
				for(k=0;k<octcount*8+quadcount*4+paircount*2;k++)
				{
					fp2>>x>>y;
				//	cout<<x<<" "<<y;
					if(x==pa[i].unit[j].x&&y==pa[i].unit[j].y)
					{
						count1++;
						break;
					}
				}
				fp2.close();
			}
			if(count1==0)
			{
				quadcount++;
				minnterm=minnterm+"+"+pa[i].minterm;
				fp1.open("output.txt",ios_base::app);
				for(j=0;j<2;j++)
			{
				fp1<<pa[i].unit[j].x<<" "<<pa[i].unit[j].y<<" ";
			}
			fp1<<endl;
			fp1.close();
			}
		}
	}		
		for(i=0;i<32;i++)
	{
		count1=0;
		for(j=0;j<2;j++)
		{
			if(k_map[pa[i].unit[j].x][pa[i].unit[j].y]==1)
			{
				count1++;
			}
		}
		if(count1==2)
		{
			count1=0;
			for(j=0;j<2;j++)
			{
				
				fp2.open("output.txt");
				for(k=0;k<octcount*8+quadcount*4+paircount*2;k++)
				{
					fp2>>x>>y;
				//	cout<<x<<" "<<y;
					if(x==pa[i].unit[j].x&&y==pa[i].unit[j].y)
					{
						count1++;
						break;
					}
				}
				fp2.close();
			}
			if(count1<2)
			{
				quadcount++;
				minnterm=minnterm+"+"+pa[i].minterm;
				fp1.open("output.txt",ios_base::app);
				for(j=0;j<2;j++)
			{
				fp1<<pa[i].unit[j].x<<" "<<pa[i].unit[j].y<<" ";
			}
			fp1<<endl;
			fp1.close();
			}
		}
	}
		for(i=0;i<16;i++)
		{
			if(k_map[u[i].unit.x][u[i].unit.y]==1)
			{
				count1=0;
				fp2.open("output.txt");
				for(k=0;k<octcount*8+quadcount*4+paircount*2;k++)
				{
					fp2>>x>>y;
					if(x==u[i].unit.x&&y==u[i].unit.y)
					{
						count1++;
						break;
					}
				}
				fp2.close();	
				if(count1==0)
			{
				minnterm=minnterm+"+"+u[i].minterm;
				fp1.open("output.txt",ios_base::app);
				fp1<<u[i].unit.x<<" "<<u[i].unit.y<<" ";
				fp1<<endl;
				fp1.close();
			}
			}
			
	}		
	minnterm=minnterm+'\0';
	cout<<"The minimized SOP expression is::::";
	cout<<minnterm.substr(1,minnterm.size());
	return 0; 
}
