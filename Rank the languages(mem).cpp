//////注意 !!!
//背起來!!!
#include <iostream>
#include <cstring>
using namespace std;
int dx[]={1,0,-1,0};//4 directions
int dy[]={0,1,0,-1};
char mp[100][100];// save data groups
int kind[30];//save counts of every letter block
int m,n;
void init(){
    for(int i=0; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>mp[i][j];
        }
    }
}

void dfs(int x,int y){ //記好 !!!!!!
    int i,nx,ny;
    char ch=mp[x][y];
    mp[x][y]='.';//mark visited positions as '.' 記好 !!
    for(i = 0 ; i < 4 ; i++){//4方向!!
        nx = x+dx[i];
        ny = y+dy[i];// determine the 4 directions of current position
        if(nx>=0 && nx<m && ny>=0 && ny<n && mp[nx][ny]==ch){// if inside edge && value == edge
            dfs(nx,ny);// run from outside to inside
        }
    }
}

int main(){
    int test_case,amount;
    char ch;
    cin>>test_case;
    for(int c=1 ; c<=test_case ; c++){//從1，方便輸出
        cin>>m>>n;
        amount=0;//記得
        memset(kind,0,sizeof(kind));//initialize to 0 every time //記得
        init();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                ch=mp[i][j];//record current letter
                if(ch>='a'&&ch<='z'){
                    //和dfs()內類似
                    dfs(i,j);//traverse every position , set the successive& same letters as '.' , mark it as visited
                    kind[ch-'a']++;// letter block count++ , after out from dfs
                }
            }
        }
        cout<<"World #"<<c<<"\n";
        while(1){//output amount as the sequence of 26 letters
            for(int i = 0 ; i < 26 ; i++){//記好 !!!
                if(kind[i]>amount){
                    amount = kind[i];
                    ch = 'a'+i;//記得!!
                }
            }
            if(amount==0){
                break;
            }
            else{
                cout<<ch<<": "<<amount<<"\n";
                kind[ch-'a']=0;// turn to 0 , then we can get the second amount
                amount=0;
            }
        }
    }
    return 0;
}