#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,x,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ans=__gcd(ans,x);
	}
	long long i,s=0;
	for(i=1;i*i<=ans;i++)
		if(ans%i==0)
			s+=2;
	i--;
	if(i*i==ans)
		s--;
	cout<<s<<endl;
	return 0;
}