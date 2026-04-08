#include <bits/stdc++.h>

using namespace std;
struct sv{
	string masv,ten;
	float diem;
};

struct node{
	sv data;
	node *next;
};

struct danhsach{
	node *head;
	node *tail;
};

bool ktr(danhsach l){
	return l.head==NULL ||l.tail==NULL;
}

node*  createnode(sv x){
	node *p=new node;
	if (p!=NULL){
		p->data=x;
		p->next=NULL;
	}
	return p;
}

void createlist(danhsach &l){
	l.head=l.tail=NULL;
}

void chendau(danhsach &l,node *p){
	if (ktr(l)){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head=p;
	}
}

void chencuoi(danhsach &l,node *p){
	if(ktr(l)){
	l.head=l.tail=p;	
	}
	else{
		l.tail->next=p;
		l.tail=p;
	}
}

void xoadau(danhsach &l){
	if(ktr(l)){
		cout<<"danh sach rong!";
		return;
	}
	node *p=l.head;
	if(l.head==l.tail){
		l.head=l.tail=NULL;
	}
	else{
		l.head=l.head->next;
		p->next=NULL;
		delete p;
	}
}

void xoacuoi(danhsach &l){
	if (ktr(l)){
		cout<<"danh sach rong!";
		return;
	}
	node*p=l.tail;
	if (l.head==l.tail){
		l.head=l.tail=NULL;
	}
	else{
		node*q=l.head;
		while(q!=NULL && q!=l.tail){
			q=q->next;
			q->next=NULL;
			l.tail=q;
			
		}
	}
}

string chuanhoaten(string ten){
	
	string res="";
	stringstream ss(ten);
	string world;
	 
	while(ss>>world){
		res+=toupper(world[0]);
		for(int i=1;i<world.length();i++){
			res+=tolower(world[i]);
		} 
		res+=" ";
	} 
	return res;
} 
void duyet(danhsach l){
	for(node*p=l.head;p!=NULL;p=p->next){
		cout<<setw(10)<<p->data.masv<<setw(10)<<chuanhoaten(p->data.ten)<<setw(10)<<p->data.diem<<endl;
	}
}

void timkiem(danhsach l){
	int n; 
	cout<<"hien thi danh sach sv co diem can tim:";
	cin>>n; 
	bool  kt=false; 
	for (node *p=l.head;p!=NULL;p=p->next){
		if (p->data.diem==n){
			cout<<setw(10)<<p->data.masv<<setw(10)<<p->data.ten<<setw(10)<<p->data.diem<<endl; 
			kt=true; 
		} 
	} 
	if(!kt) {
		cout<<"ko co sv co diem "<<n; 
	}
} 




int main(){
	int n;
	cin >>n;
	sv a;
	danhsach l;
	createlist(l);
	
	for( int i=0;i<n;i++){
		
		cout <<"nhap msv:";
		getline(cin>>ws,a.masv);
		cout<<"nhap ten sv:";
		getline(cin>>ws,a.ten);
		cout<<"nhap diem sv:";
		cin>>a.diem;
		
		node *p=createnode(a);
		chencuoi(l,p);
		
	}
	cout <<"thong tin sv:\n"; 
	duyet(l);
	xoadau(l);
	cout<<"danh sach sau khi xoa dau:\n";
	duyet(l); 
	timkiem(l); 
//	for (int i=0;i<n;i++){
//		cout <<a[i].diem<<a[i].masv<<a[i].ten; 
//	} 
}




