#include <iostream>
#include <string>
using namespace std;

struct ve{
	int mave;
	string loaive,khoihanh;
	float giave;
};

struct node {
	ve data;
	node *next;
	node *prev;
};
struct list{
	node *head;
	node *tail;
};

node* createnode(ve x){
	node *p=new node;
	p->data=x;
	p->next=p->prev=NULL;
	return p;
}
void createlist(list &l){
	l.head=l.tail=NULL;
}

void chencuoi(list &l,node *p){
	if (l.tail==NULL){
		l.head=l.tail=p;
	}
	else{
		p->prev=l.tail;
		l.tail->next=p;
		l.tail=p;
	
	}
}
void nhap(ve &x){
	cout<<"nhap loai ve:";
	getline(cin,x.loaive);
	cout<<"nhap dia diem khoi hanh:";
	getline(cin,x.khoihanh);
	cout<<"nhap ma ve:";
	cin >>x.mave;
	cout<<"nhap gia tien";cin>> x.giave;
	cin.ignore();
	
}

void duyet(list &l){
	node *p=l.head;
	if (l.head==NULL){
		cout<<"loi"<<endl;
	}
	while (p!=NULL){
		cout <<"gia ve la:"<<p->data.giave<<endl;
		cout <<"ma ve la :"<<p->data.mave<<endl;
		cout <<"loai ve la :"<<p->data.loaive<<endl;
		
		p=p->next;
	}
}

void xoadau(list &l){
	if (l.head==NULL){
		return ;
	}
	node *p=l.head;
	if (l.head==l.tail){
		l.head=l.tail=NULL;
	}
	else {
		l.head=l.head->next;
		l.head->prev=NULL;
	}
	delete p;
}


void ktra(list l){
	string x;
//	cin.ignore();
	cout <<"nhap dia diem khoi hanh:";
	getline(cin,x);
	node *p=l.head;
	cout<<"cac ve khoi hanh tu dn la:\n";
	while(p!=NULL){
		if (p->data.khoihanh=="da nang"){
			cout <<"gia ve la:"<<p->data.giave<<endl;
			cout <<"ma ve la :"<<p->data.mave<<endl;
			cout <<"loai ve la :"<<p->data.loaive<<endl;
		}
		p=p->next;
	}
}

int main (){
	int n;
	list(l);
	createlist(l);
	cout <<"nhap so ve :";
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++){
		ve x;
		nhap(x);
		node *p=createnode(x);	
		chencuoi(l,p);
	}
	duyet(l);
	cout<<"---------------\n";
	ktra(l);
	
//	xoadau(l);
//	cout<<"---------------\n";
//	duyet(l);
	
	
	
}

