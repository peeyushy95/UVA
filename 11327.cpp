/*
   AUTHOR  : Peeyush Yadav
   Problem : 11327
*/
#include<bits/stdc++.h>
using namespace std; typedef long long ll; typedef pair<int,int> grp;
inline ll power(ll a,ll b)     { ll r=1; while(b){ if(b&1) r=r*a    ; a=a*a    ; b>>=1;} return r;}
inline ll power(ll a,ll b,ll m){ ll r=1; while(b){ if(b&1) r=(r*a)%m; a=(a*a)%m; b>>=1;} return r;}
void fast(){	
	#ifdef Megamind
		freopen("inp.txt","r",stdin);
		//freopen("out.txt","w",stdout);
		#define trace(x)            cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
		#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
		#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
	#endif
	
	#define fi 						first
	#define se 						second
	#define mk 						make_pair
	#define pb(x) 					push_back(x)
	#define s(x)                    scanf("%d",&x);
	#define sl(x)                   scanf("%lld",&x);
	#define p(x)                    printf("%d\n",x);
	#define f(a,b,c)                for(int a=b;a<c;a++)
	#define r(a,b,c)				for(int a=b;a>c;a--)
	#define p2(x,y)                 printf("%d %d\n",x,y);
	#define pl(x)                   printf("%lld\n",x);
	#define pl2(x,y)                printf("%lld %lld\n",x,y);
	#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
}
/*........................................................END OF TEMPLATES.......................................................................*/
#define sz 212345
int phi[sz];
ll sum[sz];
void phi1(){
	phi[0]  = 0;
	int maxn = sz;

	sum[1]=2;
	for (int i=1; i<maxn; ++i) phi[i] = i - 1;
	for (int i=2; i<maxn; ++i){
		for (int j=i+i; j<maxn; j+=i)
		         phi[j] -= phi[i];
		sum[i] += sum[i-1] + phi[i];
	}
}

int gcd(int a, int b ){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	fast();
	
	phi1();
	ll k,diff;
	int num;
	
	//p1d(sum,30)
	while(1){
		sl(k)
		
		if(!k) break;
		
		int index = upper_bound(sum,sum + 200005,k)- sum;
		if(sum[index-1] == k) index--;
		diff = k - sum[index-1];
		f(i,0,index+1){
			if(gcd(index,i)==1) diff--;
			if(diff == 0) {
				num = i;
				break;
			}
		}
		
		cout<<num<<"/"<<index<<"\n";
		
	}
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}

