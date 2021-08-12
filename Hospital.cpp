#include<iostream>

using namespace std;

class Person
{
	private:
		string name;
		string surname;
		int age;
		int starvationRate;
	public:
		Person(string n, string s, int a)
		{
			name=n;
			surname=s;
			age=a;
			starvationRate=100;
		}
		
		string getName()
		{
			return name;
		}
		
		string getSurname()
		{
			return surname;
		}
		
		string getFullname()
		{
			return name+" "+surname;
		}
		
		int getAge()
		{
			return age;
		}
		
		void setAge(int value)
		{
			age=value;
		}
		
		int getStarvationRate()
		{
			return starvationRate;
		}
		
		void setStarvationRate(int value)
		{
			starvationRate=value;
		}
		
		virtual bool CheckStarvation()
		{
			if(starvationRate<20)
				return true;
				
			return false;
		}
		
		virtual ~Person()
		{
			cout<<getFullname()<<" is left the hospital"<<endl;
		}
};


class Patient:public Person
{
	private:
		string illnessName;
		
	public:
		Patient(string n, string s, int a,string i):Person(n,s,a),illnessName(i)
		{
		}
		
		string getIllnessName()
		{
			return illnessName;
		}
		
		void setIllnessName(string value)
		{
			illnessName=value;
		}
		
		bool CheckStarvation()
		{
			if(getStarvationRate()<50)
				return true;
				
			return false;
		}
		
		void takeACare()
		{
			setStarvationRate(getStarvationRate()-15);
			if(CheckStarvation())
				cout<<"Patient: "<<getFullname()<<" is hungry!"<<endl;
		}
		
		~Patient()
		{
			cout<<getFullname()<<" was discharged!"<<endl;
		}
};

class Employee:public Person
{
	private:
		int employeeID;
	public:
		Employee(string n, string s, int a,int e):Person(n,s,a),employeeID(e)
		{
		}
		
		int getEmployeeID()
		{
			return employeeID;
		}
		
		bool CheckStarvation()
		{
			if(getStarvationRate()<20)
				return true;
				
			return false;
		}
		
		virtual void CheckPatient(Patient &p)
		{
			setStarvationRate(getStarvationRate()-5);
			cout<<"Patient named "<<p.getFullname()<<" is checking!"<<endl;
			if(CheckStarvation())
				cout<<getFullname()<<" is starving"<<endl;
		}
		
		virtual ~Employee()
		{
			cout<<getFullname()<<" is quit the job!"<<endl;
		}
};

class Nurse:public Employee
{
	public:
		Nurse(string n, string s, int a,int e):Employee(n,s,a,e)
		{
		}
	
		void CheckPatient(Patient &p)
		{
			setStarvationRate(getStarvationRate()-10);
			cout<<"Patient named "<<p.getFullname()<<" is checking!"<<endl;
			p.takeACare();
			cout<<getFullname()<<" took care of the patient."<<endl;
			if(CheckStarvation())
				cout<<getFullname()<<" is starving"<<endl;
			cout<<endl;
		}
		
		~Nurse()
		{
			cout<<getFullname()<<" is quit being Nurse!"<<endl;
		}	
		
};

class Doctor:public Employee
{
	public:
		Doctor(string n, string s, int a,int e):Employee(n,s,a,e)
		{
		}
	
		void CheckPatient(Patient &p)
		{
			setStarvationRate(getStarvationRate()-5);
			cout<<"Patient named "<<p.getFullname()<<" is checking!"<<endl;
			p.takeACare();
			cout<<getFullname()<<" gives medicine to patient."<<endl;
			if(CheckStarvation())
				cout<<getFullname()<<" is starving"<<endl;
				
			cout<<endl;
		}
		
		~Doctor()
		{
			cout<<getFullname()<<" is quit being Doctor!"<<endl;
		}	
		
};


main()
{
	Doctor doc("Johnny","Depp", 56, 150717);
	Nurse nurse("Lauren","Jackson",38,971371);
	Patient patient("Stephen","Curry",32,"something");
	

	
	cout<<"All people in hospital:"<<endl;
	cout<<doc.getFullname()<<endl;
	cout<<nurse.getFullname()<<endl;
	cout<<patient.getFullname()<<endl;
	cout<<endl;
	cout<<"All employees works:"<<endl<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<nurse.getFullname()<<endl;
		nurse.CheckPatient(patient);
		cout<<doc.getFullname()<<endl;
		doc.CheckPatient(patient);
	}
	cout<<endl;

}
