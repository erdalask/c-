#include <iostream>

using namespace std;



int main()
{
	
double gdp[100];
int year;	
double growth;
int count=0;
int decision;

	cout<<"What would you like to do?"<<endl;
	cout<<"1-Calculate World Gdp Projection"<<endl;
	cout<<"2-Calculate Turkey's Gdp Projection"<<endl;
	cin>>decision;
	
	if(decision==1)
	{	
	cout<<"What year is it?"<<endl;
	cin>>year;
	
	cout<<"How much is world gdp at that year? : "<<endl;
	cin>>gdp[0];	
	
	cout<<"How many years you want to learn? : "<<endl;
	cin>>count;

	cout<<"What is the anually growth"<<endl;
	cin>>growth;
	
	

for(int i=0;i<=count;)
{

	
	cout<<"Year : "<<year+i<<endl;
	cout<<"World Gdp : "<<gdp[i]<<endl;	
	cout<<endl;
	i++;
	gdp[i] = ((gdp[i-1] * growth) / 100) + gdp[i-1];  
	
}

	}




	else if(decision==2)
	{
	cout<<"What year is it?"<<endl;
	cin>>year;
	
	cout<<"How much is Turkey's' gdp at that year? : "<<endl;
	cin>>gdp[0];
		
	cout<<"How many years you want to learn? : "<<endl;
	cin>>count;

	cout<<"What is the anually growth"<<endl;
	cin>>growth;


for(int i=0;i<=count;)
{

	
	cout<<"Year : "<<year+i<<endl;
	cout<<"Turkey's 'Gdp : "<<gdp[i]<<endl;	
	
	i++;
	gdp[i] = ((gdp[i-1] * growth) / 100) + gdp[i-1];  
	
}

	} 	


	
}


