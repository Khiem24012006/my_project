#include <bits/stdc++.h> 

using namespace std;



string chuanhoa(string ten){
	string res="";
	stringstream ss(ten);
	string world;
	while (ss>> world){
		res+=toupper(world[0]);
		for (int i=1;i<world.length();i++){
			res+=tolower(world[i]);
		}
		res+=" ";
	}
	return res;
} 

bool checkempty(string ns){
	stringstream ss(ns);
	string ngay,thang,nam;
	getline(ss,ngay,'/');
	getline(ss,thang,'/');
	getline(ss,nam);
	if (ngay==""|| thang==""||nam==""){
		return false;
	}
	return true;
}

string chuanhoangaysinh(string ns){
	stringstream ss(ns);
	string ngay,thang,nam;
	getline(ss,ngay,'/');
	getline(ss,thang,'/');
	getline(ss,nam);
	
	if (ngay.length()==1){
		ngay="0"+ngay;
	}
	if (thang.length()==1){
		thang="0"+thang;
	}
	return ngay+"/"+thang+"/"+nam;
}



class nguoi{
	private:
	string madd,ten; 
	static int dem; 
	public:
	nguoi(){
		madd=ten=""; 
	} 
	~nguoi(){
	} 
	
//	void nhap(){
//		cout <<"nhap ma dinh danh:";
//		getline(cin>>ws,madd);
//		cout<<"nhap ten:";
//		getline(cin>>ws,ten);
//	} 
//	void xuat(){
//		cout <<setw(10)<<madd<<setw(10)<<ten<<endl; 
//	} 


	friend istream& operator >>(istream& in, nguoi &x){
		dem++; 
		x.madd="nv"+string(3-to_string(dem).length(),'0')+to_string(dem); 
		cout<<"nhap ten:";
		getline (in>>ws,x.ten); 
		return in;
	} 
	friend ostream& operator <<(ostream& xuat,nguoi x){
		xuat<<x.madd<<setw(10)<<chuanhoa(x.ten)<<setw(10); 
		return xuat;
	} 
	string getmadd(){
		return this->madd;
	} 	
}; 




int nguoi::dem=0; 
class nhanvien:public nguoi{
	private :
	string ns;
	float hsl;
	static float pc;
	public :
	nhanvien(){
		ns="";
		hsl=0; 
	} 
	nhanvien(string ns,float hsl){
		this->ns=ns;
		this->hsl=hsl; 
	} 
	~nhanvien(){
	} 
	friend istream& operator>>(istream &in,nhanvien &x){
		in>>static_cast<nguoi&>(x) ;
		cout <<"nhap nam sinh:";
		in>>x.ns;
		cout<<"nhap hsl:";
		in>>x.hsl; 
		return in;
	} 
	friend ostream& operator <<(ostream &out,nhanvien &x){
		out<<static_cast<nguoi&>(x) ;
		out<<setw(10)<<chuanhoangaysinh(x.ns)<<setw(10)<<x.hsl;
		return out;
	}
	
	
	float tinhluong(){
		return hsl*1550+pc; 
	} 
	bool operator <(nhanvien &x){
		return this->tinhluong()<x.tinhluong(); 
	} 
	bool operator == (nhanvien &x){
		return this->getmadd()==x.getmadd() ;
	}
	 
}; 
float  nhanvien::pc=100; 



string hienthimadd(nhanvien a[],int n){
	string k;
	cout<<"nhap madd can tim:";
	cin>>k;
	bool found=false;
	for (int i=0;i<n;i++){
		if (a[i].getmadd()==k){
			cout<<a[i]<<endl; 
			found= true; 
		} 	
	} 
	if (!found){
			cout <<"ko co doi tg nao!" ;
		} 
} 

void timkiemluong(nhanvien a[],int n){
	float k; 
	cout<<"nhap luong muon tim:";
	cin  >>k;
	bool found =false;
	for (int i=0;i<n;i++){
		if (a[i].tinhluong()==k){
			cout <<a[i]<<endl;
			found=true; 
		} 
	} 
	if (!found ){
		cout <<"ko co ai co luong "<<k<<endl; 
	} 
} 




int main (){
//	nguoi x;
//	x.nhap();
//	x.xuat(); 
//	cin>>x;
//	cout<<x; 
int n;
 
do{
	cout<<"\nnhap so luong sv:"; 
	cin>>n; 
} 
while(n<=0);
nhanvien a[n];
for (int i=0;i<n;i++){
	cout <<"nhap thong tin nhan vien "<<i+1<<endl; 
	cin>>a[i]; 
} 
sort(a,a+n); 
cout<<"thong tin nhan vien vua nhap:\n"; 
cout<<"madd"<<setw(10)<<"ten"<<setw(10)<<"nam sinh"<<setw(10)<<"he so luong"<<endl; 
for (int i=0;i<n;i++){
	cout <<a[i]<<setw(10)<<a[i].tinhluong()<<endl; 
} 
//hienthimadd(a ,n); 
timkiemluong(a,n); 
} 
