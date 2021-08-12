#include <iostream>
#include <string>

using namespace std;


int main()
{

int tercih;
string t; string odeme;
double hesap=0;
	
	here:
	
	cout<<"Merhaba Erdal restoranta hosgeldiniz"<<endl;
	cout<<"\nMenu : "<<endl;

	cout<<"\nKahvaltiliklar:"<<endl;
	cout<<"1.Yumurta 5 tl "<<endl;
	cout<<"2.Pogaca 7 tl "<<endl;
	cout<<"3.Acma 5 tl "<<endl;
	cout<<"4.Sucuklu Yumurta 15 tl "<<endl;
	cout<<"5.Karisik tost 10 tl "<<endl;


	cout<<"\nEtler "<<endl;
	cout<<"6.Biftek 45 tl "<<endl;
	cout<<"7.Pirzola 70 tl "<<endl;
	cout<<"8.Kaburga 50 tl "<<endl;


	cout<<"\nTavuklar "<<endl;
	cout<<"9.Kori soslu tavuk 35 tl "<<endl;
	cout<<"10.Tavuk pirzola 30 tl "<<endl;
	cout<<"11.Tavuk gogus 30 tl "<<endl;
	
	
	cout<<"Siparisinizin numarisini yaziniz :"<<endl;
	cin>>tercih;
	
	if(tercih==1)
	{
		hesap+=5;
	}
	else if(tercih==2)
	{
		hesap+=7;
	}
	else if(tercih==3)
	{
		hesap+=5;
	}
	else if(tercih==4)
	{
		hesap+=15;
	}
	else if(tercih==5)
	{
		hesap+=10;
	}
	
	else if(tercih==6)
	{
		hesap+=45;
	}
	else if(tercih==7)
	{
		hesap+=70;
	}
	else if(tercih==8)
	{
		hesap+=50;
	}
	
	else if(tercih==9)
	{
		hesap+=35;
	}
	else if(tercih==10)
	{
		hesap+=30;
	}
	else if(tercih==11)
	{
		hesap+=30;
	}
	
	cout<<"Baska siparis vermek ister misiniz? :(evet,hayir)"<<endl;
	cin>>t;
	if(t=="evet")
	{
		goto here;
	}
	
	else if(t=="hayir")
	{
		cout<<"Toplam borcunuz = "<<hesap<<endl;
		cout<<"Odeme sekliniz nedir?"<<endl;
		cout<<"kredi karti icin k nakit icin n ye basin : "<<endl;
		cin>>odeme;
	
		if(odeme=="n")
		{
			cout<<"Tesekkurler,hesabiniz masaniza az sonra geliyor..."<<endl;
		}
		else if(odeme=="k")
		{
			cout<<"Kredi karti bilgilerinizi giriniz:";
			cout<<"Tesekkurler!";
		}
		
	}
	
	
	return 0;
}
