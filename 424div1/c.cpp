#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1e9 + 6;
int a[105];
int N;
long long K;

int main(){
	scanf("%d%I64d", &N, &K);
	long long l = 1;
	long long r = 1e11;
	for (int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
	}
	while (l!= r){
        printf("%I64d %I64d\n",l,r);
		long long mid = (l + r+1) /2;
		long long temk=0;
		for (int i = 1; i <= N; i++){
			temk += ((a[i] - 1) / mid + 1)*mid - a[i];
		}
		if (temk > K) r = mid-1;
		else l = mid;
	}
	printf("%I64d\n", l);
}
