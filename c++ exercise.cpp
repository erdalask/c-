#include <iostream>
#include <string>


using namespace std;


 class animal{
	//defining base class
	public:
	string name;
	string diet;
	float dailycalories;
	float expectedlifetime;
	
	

	
	animal(string nam, string dit, float dacalo,float explife)
	{
			//constructor of animal class
		expectedlifetime = 0;
		nam=name;
		dit=diet;
		dacalo=dailycalories;
		explife=expectedlifetime;
		
	}
	
	
	virtual	void display()
	{
			//virtual function1
			cout<<"Name is : ",name;
        		cout<<"Diet : ",diet;
        				cout<<"Expected lifetime is : ",expectedlifetime;
		
	}
	
virtual	float calculateExpectedLifeTime()
	{
			//virtual function2
	}
	
	
};

 class mammal: public animal{
		//declared inherited class
        mammal(string name, string dit, float dacalo,float explife, float brainsize):animal(name, dit, dacalo, explife)
		{
          this -> brainsize = brainsize;
        }

    public:
        float brainsize;
        
        
        void display()
        {
        	cout<<"Name is : ",name;
        		cout<<"Diet : ",diet;
        			cout<<"brainsize is : ",brainsize;
        				cout<<"Expected lifetime is : ",expectedlifetime;
		}
        
        
  	float calculateExpectedLifeTime(float x)
	{
		expectedlifetime = (x * 20.0) / dailycalories;
		return x;
		
	}
        
        
        
        
        
};
		
		
class bird: public animal{
		//declared other inherited class
	 bird(string name, string dit, float dacalo,float explife, float wingsize):animal(name, dit, dacalo, explife)
		{
          this -> wingsize = wingsize;
        }

    public:
        float wingsize;


 void display()
        {
        	cout<<"Name is : ",name;
        		cout<<"Diet : ",diet;
        			cout<<"wing size is : ",wingsize;
        				cout<<"Expected lifetime is : ",expectedlifetime;
		}
        
        
        	float calculateExpectedLifeTime(float y)
	{
		expectedlifetime = (y * 10.0) / dailycalories;
		return y;
	
	}
	
};





int main()
{

	int i;
/*	bird b[10];
	mammal m[10];
*/	

	string name[10],diet[10];
	float brainsize[10],dailcalshould[10],dailcaltak[10],wingsize[10],expectedlifetime[10];
	
	char input;
	int menuchoice;
	int animalchoice;
	
	
		
	
	for(i=0;i<100;i++)
	{	//creating the menu as wanted.
		here:
		cout<<"What would you like to do?(1- to add animal,2- to remove last added animals 3-display all : ";
		cin>>menuchoice;
		if(menuchoice==1)
		{
		cout<<"Which species do you want to add? (1 for mammals,2 for birds";
		cin>>animalchoice;
		if(animalchoice==1)
		{
			
			cout<<"Enter its name : ";
			cin>>name[i];
			cout<<"Enter its diet : ";
			cin>>diet[i];
			cout<<"Enter its brain size : ";
			cin>>brainsize[i];
			cout<<"Enter daily calories it should take : ";
			cin>>dailcalshould[i];
			cout<<"Enter daily calories it takes : ";
			cin>>dailcaltak[i];
				//calculateExpectedLifeTime(float dailcaltake[i]);
				i++; //increase i by one at the end of the loop to initialize to next array
		}
	else if(animalchoice==2)
		{
			cout<<"Enter its name : ";
			cin>>name[i];
			cout<<"Enter its diet : ";
			cin>>diet[i];
			cout<<"Enter its brain size : ";
			cin>>wingsize[i];
		
			cout<<"Enter daily calories it should take : ";
			cin>>dailcalshould[i];
			cout<<"Enter daily calories it takes : ";
			cin>>dailcaltak[i];
				//calculateExpectedLifeTime(float dailcaltake[i]);
				i++; 	//increase i by one at the end of the loop to initialize to next array
		}
			
		}
		
		else if(menuchoice==2)
		{
			//x=2;
			
			if(name[i]!=name[i]) 
			{
			
			}
			
		
		
	    }
	    
	    	else if(menuchoice==3)
		{	//displaying all animals
			int j;
		cout<<"\nAll animals in stack:\n";
		for(j=0;j<i;j++)
		{
			cout<<j+1<<".animal\n";
			cout<<" \nname : "<<name[j];
			cout<<" \ndiet : "<<diet[j];
			cout<<" \nbrain size :"<<brainsize[j];
			cout<<" \nwing size :"<<wingsize[j];
	
			cout<<"\nexpected life time :";
		}
	    }
		cout<<"\nEnter e for exit : ";
		cin>>input;
		if(input== 'e' || input=='E')
		{
			cout<<"Thank you";
			break;
		}
		
		else goto here;
	}
	
	
	
	
 	
	return 0;
}
