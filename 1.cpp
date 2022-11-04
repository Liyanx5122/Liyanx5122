#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long inty;
const inty M=998244353;
const int N=1000000;
inty jc[N+10],cf[N+10],ny[N+10],a[N+10],b[N+10];
int t,k;
char str[N+10];
inty ppow(inty a,inty b){
	inty ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
			ans%=M;
		}
		b>>=1;
		a*=a;
		a%=M;
	}
	return ans;
}
inty c(int n,int m){
	if(n<m)return 0;
	return jc[n]*ny[m]%M*ny[n-m]%M;
}
signed main(){
	cf[0]=jc[0]=1;
	for(int i=1;i<=N;i++){
		jc[i]=jc[i-1]*i%M;
		cf[i]=cf[i-1]*10%M;
	}
	ny[N]=ppow(jc[N],M-2);
	for(int i=N-1;i>=0;i--){
		ny[i]=ny[i+1]*(i+1)%M;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&k,str+1);
		int n=strlen(str+1);
		a[0]=b[0]=0;
		if(k>=2)a[0]=1;
		if(k>=1)b[0]=1;
		for(int i=1;i<n;i++){
			a[i]=(a[i-1]*2-c(i-1,k-2))%M;
			b[i]=(b[i-1]*2-c(i-1,k-1))%M;
		}
		inty sum=0,tp=str[n]-'0',ans;
		ans=tp*b[n-1];
		for(int i=n-1;i>=1;i--){
			tp=str[i]-'0';
			sum+=a[i-1]*cf[n-i-1]%M;
			sum%=M;
			ans+=tp*(b[i-1]*cf[n-i]+sum);
			ans%=M;
		}
		printf("%lld\n",ans);
	}
}
/*
1
3
100

*/
