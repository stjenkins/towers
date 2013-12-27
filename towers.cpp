/***********************************************************************
*		Towers of Hanoi Editor
*
*		Stephen Jenkins (c) 2013
***********************************************************************/

#include <iostream>
using namespace std;

int main(){
	//pick a level
	int MAX_SIZE;
	while(MAX_SIZE<1||MAX_SIZE>8){cout<<"Pick Level: "; cin>>MAX_SIZE;}
	
	//populate the inital game
	int a[3][MAX_SIZE];
	int top[3]={MAX_SIZE-1,-1,-1};
	for(int i = 0; i < MAX_SIZE; i++){a[0][i]=MAX_SIZE-i; a[1][i]=a[2][i]=9;}
	
	//loop until it is solved
	while(a[2][MAX_SIZE-1]!=1&&a[1][MAX_SIZE-1]!=1){
		
		//display the board
		for(int i = MAX_SIZE-1; i >= 0; i--){
			for(int j = 0; j < 3; j++){
				switch(a[j][i]){
					case 1: cout<<"       #\t\t"; break;
					case 2: cout<<"      ###\t\t"; break;
					case 3: cout<<"     #####\t\t"; break;
					case 4: cout<<"    #######\t\t"; break;
					case 5: cout<<"   #########\t\t"; break;
					case 6: cout<<"  ###########\t\t"; break;
					case 7: cout<<" #############\t\t"; break;
					case 8: cout<<"###############\t\t"; break;
					default: cout<<"       |\t\t"; break;
				}
			}
			cout<<'\n';
		}
		cout<<"    Stack1\t\t     Stack2\t\t     Stack3\n";
		
		//get user input
		int from = 0, to = 0;
		while(from<1||from>3||to<1||to>3){
			cout<<"From ";
			cin>>from;
			cout<<"To ";
			cin>>to;
		}
		from--;
		to--;
		
		//if legal move block
		if(top[to]==-1){
			a[to][top[to]+1]=a[from][top[from]];
			a[from][top[from]]=9;
			top[from]--;
			top[to]++;
		}
		else if(a[from][top[from]]<a[to][top[to]]){
			a[to][top[to]+1]=a[from][top[from]];
			a[from][top[from]]=9;
			top[from]--;
			top[to]++;
		}
	}
	
	cout<<"You Win!\n";
	
	//return
	return 0;
}
