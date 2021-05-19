#include<iostream>

using namespace std;

bool check(int qc[][9],int i,int j,int k){
	for(int id=0;id<9;id++){
		if(qc[id][j]==k){
			return false;
		}
	}
	for(int jd=0;jd<9;jd++){
		if(qc[i][jd]==k){
			return false;
		}
	}

	int id,jd;
	if(i>=0 && i<=2){
		id=0;
	}
	else if(i>2 && i<=5){
		id=3;
	}
	else{
		id=6;
	}
	if(j>=0 && j<=2){
		jd=0;
	}
	else if(j>2 && j<=5){
		jd=3;
	}
	else{
		jd=6;
	}

	for(int idd=id;idd<id+3;idd++){
		for(int jdd=jd;jdd<jd+3;jdd++){
			if(qc[idd][jdd]==k)
				return false;
		}
	}

	return true;
}


bool fin(int qf[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(qf[i][j]==0)
				return false;
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<qf[i][j]<<" ";
		}
		cout<<endl;
	}
	return true;
}

void solve(int q[][9],int i,int j){
	if(fin(q)){
		cout<<"done"<<endl;
		exit(0);
	}

	if(q[i][j]==0){
		for(int k=1;k<=9;k++){
			if(!check(q,i,j,k)){
				continue;
			}
			q[i][j]=k;
			if(j+1<9){
				solve(q,i,j+1);
				q[i][j]=0;
			}
			else if(j+1==9 && i+1<9){
				solve(q,i+1,0);
				q[i][j]=0;
			}
			if(fin(q)){
				cout<<"done";
				exit(0);
			}
		}
	}

	else{
		if(j+1<9){
			solve(q,i,j+1);
		}
		else if(j+1==9 && i+1<9){
			solve(q,i+1,0);
		}
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	#endif
	int qu[9][9]={{3,0,6,5,0,8,4,0,0},
				  {5,2,0,0,0,0,0,0,0},
				  {0,8,7,0,0,0,0,3,1},
				  {0,0,3,0,1,0,0,8,0},
			      {9,0,0,8,6,3,0,0,5},
				  {0,5,0,0,9,0,6,0,0},
				  {1,3,0,0,0,0,2,5,0},
				  {0,0,0,0,0,0,0,7,4},
				  {0,0,5,2,0,6,3,0,0}};

	solve(qu,0,0);
	return 0;
}