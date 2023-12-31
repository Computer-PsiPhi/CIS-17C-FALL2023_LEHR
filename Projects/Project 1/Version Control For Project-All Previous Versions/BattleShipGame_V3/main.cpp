
/* 
 * File:   main.cpp
 * Author: 
 * Created on August 21, 2023, 5:46 PM
 */
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

#include "Board.h"

queue<int> randomColumns(){
    
    int numElements=1000;
    
    queue<int> qCol;
    
    queue<int> q;
    
    set<int> setCol;
    
    int *num = new int[numElements]; 
    
    setCol.find(qCol.front());
    
    set<int>::iterator it;
    
    for(int i =0; i<numElements; i++){
        
       num[i] = rand()%10;
        
       int random = rand()%100;
        
       qCol.push(rand()%10);
       
       setCol.insert(random);
       
       q.push(rand()%10); 
    }
    
    qCol.swap(q);
      
    for(int i =0; i<numElements; i++){
        
        it = find(setCol.begin(), setCol.end(), q.front());
        qCol.push(num[*it]);
        q.pop();
    }
    
    delete []num;
    
    return qCol;
};

stack<char> randomRows(){

        int numElements=1000;

        stack<char> rw;// = new stack<char>();
        stack<char> s;// = new stack<char>();
        list<char> a; 
        
        list<char>::reverse_iterator it; 
        
        char data[] = {'A','B','C','D','E','F','G','H','I','J'};
        
        list<char> otherList;
        
        copy(data, data+10, inserter(otherList, otherList.begin()));
        
          list<char>::iterator itr = otherList.begin();
      // copy(data, data + 10,  otherList.begin());
        
//       cout<<"IN function "<<endl;
//         for (auto it = otherList.begin(); it != otherList.end(); ++it)
//        cout << ' ' << *it;
       
    for (int i = 0; i<numElements; i++){

            char r1 = rand()%10+65;

            char r2 = rand()%10+65;
            
            char r3 = rand()%10+65;
           
            a.push_front(r3);  
        
            s.push(r1);
        
            rw.push(r2);

        while(s.top() == rw.top() ){
            
            if(!s.empty()){
                    s.pop();
                    rw.pop();
                    a.clear();
                    otherList.clear();
            }
            while(otherList.size()<10)
                otherList.push_front(rand()%10+65);
            while( rw.empty() || s.empty()){
                s.push(rand()%10+65);
                rw.push(rand()%10+65);
                a.push_front(rand()%10+65);
                otherList.push_front(rand()%10+65);
            }
        }
    }
        
    for(it = a.rbegin(); it!= a.rend(); it++){
         *it=rand()%10+65;
        a.push_back(*it);
        rw.push(a.front());
        rw.push(*it); 
        *it=rand()%10+65;
       cout<<*it<<endl;
       rw.push(*it);
      }
             
    return rw;
};


char *fillOrientation( ){
    
    char *array = new char[100];// = new char[100];
    
    for(int i=0; i < 100; i++){
        if(i%2 == 0)
            array[i]='H';
        else
            array[i]='V';
    }
    
    delete []array;
    
    return array;
}

void clearScreen(){
    
cout << "\033c";

}

void clearScreenChoice(){
    char choice = 0;
    cout<<"\n";
cout << "Do you want to clear screen?"<<endl;
cin>>choice;
choice = toupper(choice);

if (choice == 'Y')
{
cout << "\033c";
}

cout << endl;
}

bool isValidPlacement( char Grid[][10], int r, int c ,char o, int size){
    
   // cout<<Grid[r][c];
//    cout<<"inFunc row "<<r<<endl;
//    cout<<"inFunc c "<<c<<endl;
//    cout<<"in Func orientation "<<o<<endl;
//    cout<<"in func size "<<size<<endl;

    
    if(o == 'H' || o == 'h'){
        for(int i =c; i< c +size; i++){
            if(i >= B_SIZE || Grid[r][i] =='S'){
                //cout<<"ship at :"<<Grid[r][i];
               return false;
            }
        }
            
    }
    else{
        for(int j = r; j<  r+size; j++){
            if(j >= B_SIZE || Grid[j][c] == 'S'){
                //cout<<"ship there too"<<endl;
               return false;
            }
        }
    }
   
    return true;
};

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    stack<char> randRow;
    queue<int> randCol;
   
    randRow = randomRows();
    randCol = randomColumns();
    
    char ort[10] = {'H','V','H','V','H','V','H','V','H','V',};
      
    cout<<" Hello can this be cleared ";
 
    clearScreenChoice();

     const int B_SIZE = 10;

    int shipLength[5] = {2,3,3,4,5};
     map<int, pair<int, char>> ships;
  //  map<ships ,pair<int,char>> stuff;

    // Add ships and their information to the map using the [] operator
    ships[0] = make_pair(5, 'C');
    ships[1] = make_pair(4, 'B');
    ships[2] = make_pair(3, 'R');
    ships[3] = make_pair(3, 'S');
    ships[4] = make_pair(2, 'D');
    
     char Grid[B_SIZE][B_SIZE];

   for(int r=0; r<B_SIZE; r++){
        
        for(int c=0; c<B_SIZE; c++){
            Grid[r][c] = '~';
        }
    } // 
     
     

     for (int i = 0 ; i < 5 ; i++){      
       for(int j = 0 ; j < B_SIZE ; j++){
         cout<<setw(5)<<j;
    }
    
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){
            cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
       
         char row = randRow.top();
       
        int col = randCol.front();
      
        randRow.pop();
        randCol.pop();
//        char row;
//        int col;
        char direction=ort[i];

      //  display();
   
        cout << "\n\nPlacing " << shipLength[i] << "-length ship"<<endl;
        
        cout << "Enter starting coordinates (e.g., A3): ";
       
        //char
        cout<<"249 row: "<<row;
        cout<<" 250 col: "<<col<<endl;
       // cin >>row >> col;
        
       int x = row - 'A';
      
       cout<<"x is "<<x<<endl;
       
       int y = col;
      // cout<<"y "<<y<<endl;
           
       cout<<"direction "<<direction<<endl;
       
        cout << "Enter direction (H for horizontal, V for vertical): \n";
      //  cin >> direction;
        
        
    bool t = isValidPlacement(Grid, x, y, direction, shipLength[i]);
    cout<<boolalpha;
    cout<<"is everything ok: "<<t<<endl;

        for(int j = 0 ; j < shipLength[i] ; j++)
        {   
            
        
      //  if(isValid){
         // cout<<"ships "<<ships[i].second<<endl;
            
             if((direction == 'V' || direction == 'v')) {
                 if(x+shipLength[i] < B_SIZE && Grid[x+j][y] != 'S')
                 Grid[x+j][y] = ships[i].second;
                 else
                     cout<<"Not valid v";
             }
          
        
             if((direction == 'H' || direction == 'h' )){ 
                    
                 if(j+shipLength[i] < B_SIZE && Grid[x][y+j] != 'S')
                 Grid[x][y+j] = ships[i].second;
                 else
                     cout<<"Not valid h";
                // Grid[x][y+j] = 'S';   
                 
      //   }        
                 
            }
        }
    
    
        
    }
     
   //  clearScreen();

    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){

            cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
       
     
    return 0;
}
