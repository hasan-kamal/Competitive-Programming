#include <iostream>
using namespace std;

long long gcd(long long x, long long y){
	if(y!=0){
		long long rem=x%y;
		while(rem!=0){
			x=y;
			y=rem;
			rem=x%y;
		}
	}

	return y;
}

long long min(long long x, long long y){
	if(x<y)
		return x;
	else
		return y;
}

int main(){

	long long t, s, e1, e2, v1, v2, lcm, minimum, ans;
	cin>>t;

	while(t--){
		cin>>s>>e1>>e2>>v1>>v2;
		
		if(v1*v2<=0)
			cout<<"1"<<endl;
		else{
			if(v1<0){
				v1*=-1;
				v2*=-1;

				e1=s+s-e1;
				e2=s+s-e2;

				//cout<<e1<<" "<<e2<<" "<<v1<<" "<<v2<<endl;
			}
			lcm=v1*v2/gcd(v1, v2);
			minimum=min(e1-s, e2-s);
			ans=minimum/lcm +1;//They always have one cake-piece together since they start from the same position



			if(e1<e2){
				
				if((e1-s)%lcm!=0){
					//last point abruptly cake left
					if((e1-s)%v2==0)
						ans+=1;
				}


			}else if(e2<e1){

				if((e2-s)%lcm!=0){

					if((e2-s)%v1==0)
						ans+=1;

				}

			}else{

				if((e1-s)%lcm!=0)
					ans+=1;

			}

			

			cout<<ans<<endl;
		}

	}

	return 0;
}