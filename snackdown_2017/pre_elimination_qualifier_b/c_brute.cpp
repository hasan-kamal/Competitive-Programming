/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

#define N 100005
typedef vector<int> vi;

bool is_bit_set(int x, int b){
	return (x & (1<<b)) == 0 ? false : true;
}

int main(){

	int t, n;
	cin >> t;

	char s[2][N];

	while(t--){
		
		cin >> n;
		cin >> s[0];
		cin >> s[1];

		//cout << s[0] << endl;
		//cout << s[1] << endl;

		int min_fence = INT_MAX;
		for(int i = 0; i < (2<<n)-1; i++){
			//bit pattern of i tells our approach

			int num_bits_set = 0;
			for(int j = 0; j < 32; j++){
				if( (i & (1<<j)) != 0)
					num_bits_set++;
			}

			bool valid_soln = false;
			bool applied_horizontal = is_bit_set(i, n - 1);

			//upper row
			bool upper_row_valid = true;
			int last_index = -1;
			for(int x = 0; x < n; x++){
				if(s[0][x] == '*' && last_index > -1){
					
					// some bit in [last_index, x-1] should be set
					bool has_fence = false;
					for(int k = last_index; k < x; k++){
						if(is_bit_set(i, k)){
							has_fence = true;
							break;
						}
					}
					if(!has_fence){
						upper_row_valid = false;
						break;
					}

					last_index = x;
				}else if(s[0][x] == '*'){
					last_index = x;
				}

			}

			//lower row
			bool lower_row_valid = true;
			last_index = -1;
			for(int x = 0; x < n; x++){
				if(s[1][x] == '*' && last_index > -1){
					
					// some bit in [last_index, x-1] should be set
					bool has_fence = false;
					for(int k = last_index; k < x; k++){
						if(is_bit_set(i, k)){
							has_fence = true;
							break;
						}
					}
					if(!has_fence){
						lower_row_valid = false;
						break;
					}

					last_index = x;
				}else if(s[1][x] == '*'){
					last_index = x;
				}
			}

			//inter-row
			bool inter_row_valid = applied_horizontal;
			if(!applied_horizontal){

				last_index = -1;
				for(int x = 0; x < n; x++){

					if(s[0][x] == '*' && s[1][x]=='*'){
						inter_row_valid = false;
						break;
					}

					if( (s[0][x] == '*' || s[1][x]=='*') && last_index > -1){
						
						// some bit in [last_index, x-1] should be set
						bool has_fence = false;
						for(int k = last_index; k < x; k++){
							if(is_bit_set(i, k)){
								has_fence = true;
								break;
							}
						}
						if(!has_fence){
							inter_row_valid = false;
							break;
						}

						last_index = x;
					}else if(s[0][x] == '*' || s[1][x]=='*'){
						last_index = x;
					}

				}


			}

			valid_soln = upper_row_valid && lower_row_valid && inter_row_valid;

			if(valid_soln){
				//cout << "--" << i << endl;
				if(num_bits_set < min_fence)
					min_fence = num_bits_set;
			}
		}

		cout << min_fence << endl;
	}

	return 0;
}