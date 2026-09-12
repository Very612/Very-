#include<bits/stdc++.h>
using namespace std;
string s1;
void judge(int n){
	s1="\033["+to_string(n)+"A";
}
class Read{
public:
	int n,cn,m;
	vector<pair<int,int>>c,d;
	vector<vector<char>>a,b;
	void init(){ 
		cout<<"请输入二值矩阵的半径大小: ";
		cin>>n;    judge(n); 
		cout<<"请输入二值矩阵："<<'\n';
		a.assign(n,vector<char>(n));
		for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]=='1') c.push_back({i,j});
			}
		}
		cout<<"请输入结构元素的半径大小: ";
		cin>>m;
		cout<<"请输入结构元素："<<'\n';
		b.assign(m,vector<char>(m));
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				cin>>b[i][j];
				if(b[i][j]=='1'){ d.push_back({i-(m-1)/2,j-(m-1)/2});}
			}
		}
	}
};
class Dilation{
	Read d1;
public:
	Dilation(Read& x):d1(x){}
	void copy(Read& x){d1=x;}
	void ass(Read& x){x=d1;}
	void DIL(){
		for(int i=0;i<d1.n;i++){
			for(int j=0;j<d1.n;j++){
				d1.a[i][j]=='1' ? cout<<"■" : cout<<"□";
			}
			cout<<'\n';
		}
		sleep(1);
		cout <<s1;
		vector<pair<int,int>>dd;
		for(auto i : d1.c){
			int t1=i.first,t2=i.second;
			for(auto j : d1.d){
				int x=j.first+t1,y=j.second+t2;
				if(x>=0&&x<d1.n&&y>=0&&y<d1.n&&d1.a[x][y]!='1'){
					d1.a[x][y]='1';
					dd.push_back({x,y});
				}
			}
		}
		for(auto o : dd){
			d1.c.push_back({o.first,o.second});
		}
		for(int i=0;i<d1.n;i++){
			for(int j=0;j<d1.n;j++){
				d1.a[i][j]=='1' ? cout<<"■" : cout<<"□";
			}
			cout<<'\n';
		}
	}
};
class Erosion{
	Read e;
public:
	Erosion(Read& x):e(x){}
	void copy(Read& x){e=x;}
	void ass(Read& x){x=e;}
	void ERO(){
		for(int i=0;i<e.n;i++){
			for(int j=0;j<e.n;j++){
				e.a[i][j]=='1' ? cout<<"■" : cout<<"□";
			}
			cout<<'\n';
		}
		sleep(1);
		cout <<s1;
		map<pair<int,int>,bool>q;
		for(auto i : e.c){
			int t1=i.first,t2=i.second;
			for(auto j : e.d){
				int x=j.first+t1,y=j.second+t2;
				if(x>=0&&x<e.n&&y>=0&&y<e.n){
					if(e.a[x][y]!='1'){
						q[{t1,t2}]=1;
						break;
					}
				}else{
					q[{t1,t2}]=1;
					break;
				}
			}
		}
		for(int i=0;i<e.n;i++){ 
			for(int j=0;j<e.n;j++){

				if(q[{i,j}]){
					e.c.erase(remove(e.c.begin(),e.c.end(),make_pair(i,j)),e.c.end());
					e.a[i][j]='0';
					cout<<"□";continue;
				}
				e.a[i][j]=='1'? cout<<"■" : cout<<"□";
			}
			cout<<'\n';
		}
	}
};
int main(){
	Read c;
	while(1){
		string s,s1;
		c.init();
		Dilation a1(c);Erosion b1(c);
		while(s!="break"){
			cout<<"选择膨胀还是腐蚀:(D/E/跳出break): ";
			cin>>s;
			if(s=="D"||s=="d"){
				a1.copy(c);
				a1.DIL();a1.ass(c);
				continue;
			}
			if(s=="E"||s=="e"){
				b1.copy(c);
				b1.ERO();b1.ass(c);
				continue;
			}
			if(s!="e"&&s!="E"&&s!="D"&&s!="d"){
				cout<<"错误输入,请重新输入"<<'\n';
				continue;
			}
		}
	   bool i=0;
	   	while(1){
			cout<<"需要结束进程吗:(Y/N)";cin>>s1;
			if(s1=="Y"||s1=="y"){i=1;break;}
			if(s1=="N"||s1=="n"){break;}
			if(s1!="Y"&&s1!="N"&&s1!="y"&&s1!="n"){
				cout<<"错误输入,请重新输入:"<<'\n';
				continue;
			}
		}
		if(i)break;
	}
}
