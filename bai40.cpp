#include<bits/stdc++.h>
#include <string.h>
using namespace std;


class phuongtienGT{ 
	private:
		string hangsx,tenpt;
		int namsx;
		float vmax; 
	public:
	phuongtienGT(){
		hangsx=tenpt="";
		namsx=0;
		vmax=0; 
	} 
	phuongtienGT(string hangsx,string tenpt,int namsx,float vmax){
		this->hangsx=hangsx;
		this->tenpt=tenpt;
		this->namsx=namsx; 
		this->vmax =vmax; 
	}
	
	friend istream &operator >>(istream &i,phuongtienGT &a){
		cout <<"nhap hangsx:";
		getline (i>>ws,a.hangsx) ;
		cout<<"nhao tenpt:";
		getline(i>>ws,a.tenpt);
		cout <<"nhap nam sx:";
		i>>a.namsx;
		cout<<"van toc max";
		i>>a.vmax;
		return i; 
	} 
	friend ostream &operator <<(ostream &o,phuongtienGT &a){
		o <<"xe hang:"<<a.hangsx<<"\tten xe:"<<a.tenpt<<"\tnam sx"<< a.namsx<<"\tvan toc max:"<<a.vmax<<endl;
		return o;
	} 
	float getvmax(){
		return this->vmax;
	}
};

class Oto:public phuongtienGT{
	private :
		int ghe;
		string kieudc;
	public:
		Oto(){
			ghe=0;
			kieudc="";
		}
		Oto(int ghe,string kieudc){
			this->ghe=ghe;
			this->kieudc=kieudc;
		}
		
		friend istream &operator >>(istream &in,Oto &x){
			in>>(phuongtienGT&)x;
			cout <<"nhap ghe ngoi";
			in>>x.ghe;
			cout<<"nhap kieu dc";
			getline(in>>ws,x.kieudc);
			return in;
		}
		friend ostream &operator <<(ostream &out,Oto &x){
			out << (phuongtienGT&)x;
			out<<x.ghe<<" "<<x.kieudc;
			return out;
		}
		float vtcs(){
			return getvmax()/2;
		}
		bool operator <(Oto& y){
			return y.vtcs()<vtcs();
		}
};


int main (){
	
	
	
	
	Oto a[50];
	int n;
	do{
		cout<<"nhap so lg pt:";
		cin>>n;
	}
	while(n<=0);
	
	for (int i=0;i<n;i++){
		cout<<"nhap doi tg thu "<<i+1<<endl;
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		cout<<a[i]<<"\n"<<a[i].vtcs();	
	}
	
	
}
	
	
