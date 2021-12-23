/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

struct ii{
	int x, y;
};

int maximum(int x, int y){
	return x>y?x:y;
}

int minimum(int x, int y){
	return x<y?x:y;
}

bool intersect_non_empty(int x1, int x2, int y1, int y2){
	if(x1>x2){
		int temp = x1;
		x1 = x2;
		x2 = temp;
	}

	if(y1>y2){
		int temp = y1;
		y1 = y2;
		y2 = temp;
	}

	int max_l = maximum(x1, y1);
	int min_r = minimum(x2, y2);

	return max_l<=min_r;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		ii p1, p2, q1, q2;
		cin>>p1.x>>p1.y>>p2.x>>p2.y;
		cin>>q1.x>>q1.y>>q2.x>>q2.y;
		bool p_horizontal = (p1.y==p2.y)?true:false;
		bool q_horizontal = (q1.y==q2.y)?true:false;

		bool is_valid;
		if(p_horizontal && q_horizontal){
			if(p1.y!=q1.y)
				is_valid = false;
			else if(intersect_non_empty(p1.x, p2.x, q1.x, q2.x))
				is_valid = true;
			else
				is_valid = false;
		}else if(!p_horizontal && !q_horizontal){
			if(p1.x!=q1.x)
				is_valid = false;
			else if(intersect_non_empty(p1.y, p2.y, q1.y, q2.y))
				is_valid = true;
			else
				is_valid = false;
		}else{
			if(!p_horizontal){
				ii temp1 = p1;
				ii temp2 = p2;
				
				p1 = q1;
				p2 = q2;

				q1 = temp1;
				q2 = temp2;
			}
			//p horizontal and q vertical
			bool b1 = ((p1.y==q1.y||p1.y==q2.y)&&(p1.x==q1.x));
			bool b2 = ((p2.y==q1.y||p2.y==q2.y)&&(p2.x==q1.x));
			if(b1 || b2)
				is_valid = true;
			else
				is_valid = false;

			//corner-case
			if(p1.x==p2.x){
				//p is single-block length
				if(p1.x==q1.x && intersect_non_empty(p1.y, p2.y, q1.y, q2.y)){
					//if(!is_valid)
					//	cout<<"hello"<<endl;
					is_valid = true;
				}
			}
		}

		if(is_valid)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}

	return 0;
}