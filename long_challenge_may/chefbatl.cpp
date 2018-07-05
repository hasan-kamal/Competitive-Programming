/*
	@author Hasan Kamal
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef pair<int, int> ii;
#define N 10
#define T 100

bool even_mode;
ii get_random_move_on_unmarked_nodes(int board[N][N]){
	vector<ii> unmarked_cells_even;
	vector<ii> unmarked_cells_odd;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j]==0){
				if((N*i+j)%2==0)
					unmarked_cells_even.push_back(make_pair(i, j));
				else
					unmarked_cells_odd.push_back(make_pair(i, j));
			}
		}
	}

	int size_even = unmarked_cells_even.size();
	int size_odd = unmarked_cells_odd.size();

	if(size_odd==0 || even_mode){
		int rand_index = rand()%size_even;
		return unmarked_cells_even[rand_index];
	}else if(size_even==0 || !even_mode){
		int rand_index = rand()%size_odd;
		return unmarked_cells_odd[rand_index];
	}

	even_mode = !even_mode;
}

void mark_unmarked(int board[N][N], ii l1, ii l2){
	if(l1.first<0)
		l1.first = 0;
	if(l1.second<0)
		l1.second = 0;
	if(l2.first<0)
		l2.first = 0;
	if(l2.second<0)
		l2.second = 0;

	if(l1.first>=N)
		l1.first = N-1;
	if(l1.second>=N)
		l1.second = N-1;
	if(l2.first>=N)
		l2.first = N-1;
	if(l2.second>=N)
		l2.second = N-1;

	for(int i=l1.first; i<=l2.first; i++){
		for(int j=l1.second; j<=l2.second; j++){
			if(board[i][j]==0)
				board[i][j] = 1;
		}
	}
}

bool is_in_neighbour_freeing_mode;
ii neighour_mode_ship_position;
ii get_intelligent_move(int board[N][N], int last_response, ii last_move){
	if(last_response!=-1){
		if(board[last_move.first][last_move.second]==0)
			board[last_move.first][last_move.second] = 1; //marked as we made last attempt there
	}

	if(is_in_neighbour_freeing_mode && last_response!=3){
		//will try to hit this ship 2nd or more-th time
		//some cell of this ship is still unhit as last_response!=3

		int num_ship_cells_horizontal=0, num_ship_cells_vertical=0;
		
		if(last_response==2){
			board[last_move.first][last_move.second] = 2;
			neighour_mode_ship_position = last_move;
		}else
			board[last_move.first][last_move.second] = 1;

		ii mv = neighour_mode_ship_position;
		if(mv.first-1>=0 && board[mv.first-1][mv.second]==2)
			num_ship_cells_vertical++;
		if(mv.first+1<N && board[mv.first+1][mv.second]==2)
			num_ship_cells_vertical++;
		if(mv.second-1>=0 && board[mv.first][mv.second-1]==2)
			num_ship_cells_horizontal++;
		if(mv.second+1<N && board[mv.first][mv.second+1]==2)
			num_ship_cells_horizontal++;

		if(num_ship_cells_horizontal+num_ship_cells_vertical==0){
			//check around mv-th position and return
			//cout<<"any of four directions will be picked, true"<<endl;
			vector<ii> valid_options;
		
			if(mv.first-1>=0 && board[mv.first-1][mv.second]==0)
				valid_options.push_back(make_pair(mv.first-1, mv.second));
			if(mv.first+1<N && board[mv.first+1][mv.second]==0)
				valid_options.push_back(make_pair(mv.first+1, mv.second));

			if(mv.second-1>=0 && board[mv.first][mv.second-1]==0)
				valid_options.push_back(make_pair(mv.first, mv.second-1));
			if(mv.second+1<N && board[mv.first][mv.second+1]==0)
				valid_options.push_back(make_pair(mv.first, mv.second+1));

			int size = valid_options.size();
			int rand_index = rand()%size;
			return valid_options[rand_index];

		}else if(num_ship_cells_horizontal>0){
			//ship is in horizontal config
			//cout<<"in horizontal config, true"<<endl;
			int i = mv.second;
			while(i>=0 && board[mv.first][i]==2)
				i--;

			int j = mv.second;
			while(j<N && board[mv.first][j]==2)
				j++;

			vector<ii> valid_options;
			if(i>=0 && board[mv.first][i]==0)
				valid_options.push_back(make_pair(mv.first, i));
			if(j<N && board[mv.first][j]==0)
				valid_options.push_back(make_pair(mv.first, j));
			int size = valid_options.size();
			int rand_index = rand()%size;
			return valid_options[rand_index];
		}else{
			//ship is in vertical config
			//cout<<"in vertical config, true"<<endl;
			int i = mv.first;
			while(i>=0 && board[i][mv.second]==2)
				i--;

			int j = mv.first;
			while(j<N && board[j][mv.second]==2)
				j++;

			vector<ii> valid_options;
			if(i>=0 && board[i][mv.second]==0)
				valid_options.push_back(make_pair(i, mv.second));
			if(j<N && board[j][mv.second]==0)
				valid_options.push_back(make_pair(j, mv.second));
			int size = valid_options.size();
			int rand_index = rand()%size;
			return valid_options[rand_index];
		}

	}

	if(last_response==-1){
		//first move of the game, make a random guess
		//cout<<"first move upcoming"<<endl;
		//ii random_move = get_random_move_on_unmarked_nodes(board);
		ii move = ii(4, 4);
		return move;
	}else if(last_response==1){
		//cout<<"random move upcoming"<<endl;
		//the cell you hit is empty or you've hit it already
		board[last_move.first][last_move.second] = 1;
		return get_random_move_on_unmarked_nodes(board);
	}else if(last_response==2){
		//you hit a ship, but it hasn't sunk yet
		//hit this ship first time
		//cout<<"ship hit first time"<<endl;
		board[last_move.first][last_move.second] = 2;
		is_in_neighbour_freeing_mode = true;
		neighour_mode_ship_position = last_move;

		vector<ii> valid_options;
		
		if(last_move.first-1>=0 && board[last_move.first-1][last_move.second]==0)
			valid_options.push_back(make_pair(last_move.first-1, last_move.second));
		if(last_move.first+1<N && board[last_move.first+1][last_move.second]==0)
			valid_options.push_back(make_pair(last_move.first+1, last_move.second));

		if(last_move.second-1>=0 && board[last_move.first][last_move.second-1]==0)
			valid_options.push_back(make_pair(last_move.first, last_move.second-1));
		if(last_move.second+1<N && board[last_move.first][last_move.second+1]==0)
			valid_options.push_back(make_pair(last_move.first, last_move.second+1));

		int size = valid_options.size();
		int rand_index = rand()%size;
		return valid_options[rand_index];

	}else if(last_response==3){
		//you sunk a ship
		//mark all neighbours of this ship marked as well
		//cout<<"sunk a ship, random coming up"<<endl;
		int num_ship_cells_horizontal=0, num_ship_cells_vertical=0;
		ii mv = last_move;

		board[mv.first][mv.second] = 2;

		if(mv.first-1>=0 && board[mv.first-1][mv.second]==2)
			num_ship_cells_vertical++;
		if(mv.first+1<N && board[mv.first+1][mv.second]==2)
			num_ship_cells_vertical++;
		if(mv.second-1>=0 && board[mv.first][mv.second-1]==2)
			num_ship_cells_horizontal++;
		if(mv.second+1<N && board[mv.first][mv.second+1]==2)
			num_ship_cells_horizontal++;

		if(num_ship_cells_horizontal+num_ship_cells_vertical==0){
			//was a battleship
			ii l1(mv.first-1, mv.second-1);
			ii l2(mv.first+1, mv.second+1);
			mark_unmarked(board, l1, l2);
		}else if(num_ship_cells_horizontal>0){
			//was in horizontal config
			int i = mv.second;
			while(i>=0 && board[mv.first][i]==2)
				i--;

			int j = mv.second;
			while(j<N && board[mv.first][j]==2)
				j++;

			ii l1(mv.first-1, i);
			ii l2(mv.first+1, j);
			mark_unmarked(board, l1, l2);
		}else if(num_ship_cells_vertical>0){
			//was in vertical config
			int i = mv.first;
			while(i>=0 && board[i][mv.second]==2)
				i--;

			int j = mv.first;
			while(j<N && board[j][mv.second]==2)
				j++;

			ii l1(i, mv.second-1);
			ii l2(j, mv.second+1);
			mark_unmarked(board, l1, l2);
		}

		is_in_neighbour_freeing_mode = false;

		return get_random_move_on_unmarked_nodes(board);
	}

	return get_random_move_on_unmarked_nodes(board);
}

void disp(char board[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout<<board[i][j];
		cout<<endl;
	}
}

void disp(int board[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout<<board[i][j];
		cout<<endl;
	}
}

int main(){

	int t = T;
	srand(time(NULL));
	while(t--){
		cout<<"1"<<endl;
		
		char my_board[N][N] = {
			{'.','.','.','.','.','.','.','.','.','.'},
			{'.','#','.','#','#','#','.','.','.','.'},
			{'.','#','.','.','.','.','.','.','.','.'},
			{'.','#','.','#','#','#','.','.','.','.'},
			{'.','#','.','.','.','.','.','.','.','.'},
			{'.','.','.','#','.','#','.','.','.','.'},
			{'.','#','.','#','.','#','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.','.'},
			{'.','#','#','.','#','.','#','.','#','.'},
			{'.','.','.','.','.','.','.','.','.','.'}
		};

		int guess_board[N][N] = {
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		};

		disp(my_board);
		cout<<endl;
		int response = -1;
		int k, x, y;
		ii my_move(-1, -1);
		is_in_neighbour_freeing_mode = false;
		even_mode = true;
		while(response!=4 && response!=5){
			//make move
			my_move = get_intelligent_move(guess_board, response, my_move);
			//if(response!=-1)
			//	disp(guess_board);	
			cout<<my_move.first+1<<" "<<my_move.second+1<<endl;
			
			//take response
			cin>>response;
			if(response==1 || response==5){
				cin>>k;
				for(int i=0; i<k; i++)
					cin>>x>>y;
			}
		}
	}

	//cout<<0;

	return 0;
}