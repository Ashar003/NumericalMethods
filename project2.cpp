#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>       /* exp */
#include <thread> 
#include<string.h>
#include <future>
#include <mutex>
using namespace std;

struct Node {
	int data;
     int datad;
     int temp;
	Node* next;
};
struct Node2 {
	int data2;
    int datad2;
    int temp2;
	Node2* next2;
};

void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
};
void addNode2(struct Node2 *head, int n) {
	Node2 *newNode = new Node2;
	newNode->data2 = n;
	newNode->next2 = NULL;

	Node2 *cur = head;
	while(cur) {
		if(cur->next2 == NULL) {
			cur->next2 = newNode;
			return;
		}
		cur = cur->next2;
	}
};



//ISSUE HERE IS with !NULL, we need to get the head value for when it's at null
long double energyDifference(int tid, int B, int C, struct Node *head){
//    std::cout << "in energydifference " << tid << std::endl;

long double energy = 0.0;
long double energy2 = 0.0;
long double energyDifferencex = 0.0;
//    struct Node* list;
   Node *list = head;
   int headData = list->data;
   int count = 0;
// std::cout << " after assignment \n " << tid << std::endl;
   while (list->next != NULL ) { 
    count++;
    list->datad= list->data;
    list = list->next; 
    // if(list->next != NULL){
    energy = energy + (-1*((B*(list->datad))+C*(list->datad)*(list->data)));
    energy2 = energy2 + (1*((B*(list->datad))+C*(list->datad)*(list->data))); //spin
    
    // std::cout << " after equation " << tid << "BREAK" << count << std::endl;
//    } 
    //  std::cout << " after equation " << tid << "BREAK" << count << std::endl;
   }
//    std::cout << " energydifference computation \n " << tid << std::endl;
 
    energyDifferencex = energy - energy2;
    return energyDifferencex;
}


float magnetizationPerSpin(int n, struct Node *head ){
    //  cout<<n;
long double m = 0.0;
// double answer = 0.0;
//    struct Node* list;
   Node *list = head;
   while (list != NULL) { 
    //   cout<< list->data <<" "; 
     
         m=m+(list->data);
        //  cout<< m <<"sum"; 
        //  m=m*(1/n);
      list = list->next; 
    //   if(list == NULL) cout<<m<<n<<endl;
   }
    // cout<< m <<endl; 
    double c = (float(n));
    //  cout<<m<<" "<<c<<" "<<endl;
   double b=(float(m))/(c);
    //  cout<<b<<" "<<n<<" "<<endl;
   return b; 
  
} 

float magnetizationPerSpinDos(int n,struct Node2 *head  ){
long double m = 0.0;
// double answer = 0.0;
//    struct Node2* list;
   Node2 *list = head;
   while (list != NULL) { 
    //   cout<< list->data2 <<" "; 
    
         m=m+(list->data2);
       
         
      list = list->next2; 
    //   if(list == NULL) cout<<m<<n<<endl;
   }
 //    cout<< m <<"co UNNo"; //
 double c = (float(n));
double b=(float(m))/(c);
//  cout<<m<<""<<c<<""<<endl;

    // cout<< m <<"co UNNo"; //
   return b; 
} 


long double correlationPerSpinDos( int n, struct Node2 *head ){
    
long double m = 0.0;

 //  struct Node2* list;
   Node2 *list = head;
   list = list->next2;
   int temp = list->data2;
    // list2 = head.next;
   while (list->next2 != NULL) { 
    //   cout<< list->data2 <<" "; 
    
      list->data2= list->datad2;
    list = list->next2;
         m=m+((list->data2)*(list->datad2));
         
   if(list->next2 == NULL){
        m=m+((list->data2)*(temp));

   }
   }
    //  cout<< m <<"co UNNo"; 
  double b=m*(1.0/n);
    //  cout<< m <<"co DUNNo"; 
   return b; 
}



    
    


long double correlationPerSpin( int n, struct Node *head ){
    //  cout<<n;
long double m = 0.0;
  //struct Node* list;
   Node *list = head;
    // list2 = head.next;
     list = list->next;
   int temp = list->data;
   while (list->next != NULL) { 
    //   cout<< list->data <<" "; 
    
      list->datad= list->data;
    list = list->next;
         m=m+((list->data)*(list->datad));
        //  cout<< m <<"co UNNo"; 
        //  m=m*(1/n);
    //   list = list->next; 
    //   list2 = list2->next;
    if(list->next == NULL){
        m=m+((list->data)*(temp));
   }
   }
    //  cout<< m <<"co UNNo"; 
    double b=m*(1.0/n);
    //    cout<<n ;
   return b; 
}







void flip(bool W, struct Node *head, struct Node2 *head2){
    
   
    // struct Node* list;
    // list = head;
    Node *list = head;
    // list2 = head2;
    // while (list != NULL) {
        while(list != NULL) {
    //    cout<< list->data <<" "; 
       if(list->data == 1){
         
        if(W){ addNode2(head2, -1);}
        else{list->data = -1;};
       }
       else if( list->data == -1){
             if(W){ addNode2(head2, 1);}
         else{list->data = 1;};
       }
       list = list->next;
    //    list = list->next2;  



}

}

void flipDos(struct Node2 *head){
    
   
    // struct Node2* list;
    Node2 *list = head;
    
    // list2 = head2;
    while (list != NULL) { 
    //    cout<< list->data <<" "; 
       if(list->data2 == 1){
        list->data2 = -1;
        // insert2(-1);
       }
       else if( list->data2 == -1){
            // insert2(1);
            list->data2 = 1;
       }
       list = list->next2;
    //    list = list->next2;  



}
}



void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}
void initNode2(struct Node2 *head,int n){
	head->data2 = n;
	head->next2 =NULL;
}
void metropolis(int v, int m[], int c[], int tid, int n, int B, int C, int T, int hoot){

struct Node *newHead;
	struct Node *head = new Node;
    initNode(head, 0);

    struct Node2 *newHead2;
	struct Node2 *head2 = new Node2;
    initNode2(head2, 0);
// struct Node* head = NULL;  
// struct Node2* head2 = NULL;  
    // double *m , *c;
    // mT--;
    bool Node1 = true;
    bool which = true;
    long double magnet = 0.0;
    long double correlation = 0.0;
   double magMea = 0.0;
    double corMea = 0.0;
    //    int cT= mT;
    v++;
       int i = rand() % n+1; // uniform pseudorandom number
    //    double m [T];
    //    double c [T];

    for(int a= 0; a<n; a++){ // 100 spins, 100 1s . call to function insert 
        // std::cout << "Launched forloop " << tid << std::endl;
        if( C >= 0){
            addNode(head,1);
        }
        else if(C < 0) {
        
            if(i % 2 == 1){
        addNode(head,-1);
        }
        else{ addNode(head,1);};
    }

    }
// std::cout << "finished forloop \n" << tid << std::endl;

    flip(true, head, head2);
    // std::cout << "flip complete \n " << tid << std::endl;

    long double now = energyDifference(tid, B, C, head);
    // std::cout << "enerydifference complete \n " << tid << "THIS IS VALUE OF NOW\n"<<now<<"Kjfj"<<std::endl;
    double p = 0.0;

    if(now < 0){ 
         Node1= false;} 
    else if(now> 0){  
        p = exp((-1*now)/T);
         int r = rand() % +1;
    
    if ( r< p){ 
        Node1 = false;
    }
    else{
        Node1= true;
        };
    };

   
    

    int f = rand() % 10;
    // cout<<f<<"THIS IF F"<<endl;
int flips = n*f;

if(Node1 != true){
    for(int x =0; x<flips; x++)
     flipDos(head2); }
else{
    for(int x =0; x<flips; x++) 
    flip(false,head,head2);
}


        //    std::cout << "are we there yet? \n " << tid << std::endl;
        if(Node1 != true){
            // cout<<n;
            float  magnet = magnetizationPerSpinDos(n, head2);
            // cout<<n;
             cout<<magnet<<"Mag\n";
            // cout<<n;
        float correlation = correlationPerSpinDos(n, head2);
        // cout<<n;
         cout<<correlation<<"corU\n";
     }
     
else{
     float magnet = magnetizationPerSpin(n, head);
    //  cout<<n;
     cout<<magnet<<"Maj\n";
    // cout<<n;
    float correlation = correlationPerSpin(n, head);
    // cout<<n;
     cout<<correlation<<"\n";
}   


// std::cout << "might be there now? \n " << tid << "THIS SHOULD BE magnet\n" << magnet << "THIS SHOULD BE correlation\n" << correlation << std::endl;

    // m[mT--]= magnet;
    // magMea= magMea+ ((1/mT)*m[v]);
    // c[cT--]= correlation;
    // corMea= corMea+ ((1/mT)*m[v]);


// display();
          

    //   cout<<hoot<<"Metropolois of thread"<<tid<<endl;
};







void call_from_thread(int tid, int n, int B, int C, int T) { //gets called every time a thread is asked for
    // double mA [T];
    //    double cA [T];
    
     int m = 10;
    double magMea = 0.0;
    double corMea = 0.0;
    double gMagMean  = 0.0;
    double gCorMean = 0.0;
     int * mA = new (nothrow) int[m];
    int * cA = new (nothrow) int[m];
     int g=0;
       int v = -1;

    // std::cout << "Launched by thread \n" << tid << std::endl;
  
    while(g != m){
         
        // std::cout << "Launched metropolis \n" << tid<<"MOM"<<g << std::endl;
        metropolis(v, mA,cA, tid, n, B, C, T, g);
        g++;
        
    }
std::cout << "ended by thread " << tid << std::endl;

for(int h=0; h<m; h++){
    // cout<<mA[h]<<"MA\n"<<cA[h]<<"CA\n"<<endl;
    magMea= magMea+ ((1/m)*mA[h]);
    corMea= corMea+ ((1/m)*cA[h]);
}

for(int y=0; y<T; y++){
    gMagMean = gMagMean + ((1/T)* mA[y] );
    gCorMean = gCorMean + ((1/T)* cA[y] );
}

std::cout << "metropolis terminated...boop " << tid << std::endl;




}




// const int num_threads = 1000; //Number of threads





int main()
{
    int n,B,C,T;
    cout << "Enter inputs for n\n"<<endl;
    cin >> n;
     cout << "Enter input B \n"<<endl;
     cin >> B ;
      cout << "Enter input C \n"<<endl;
      cin >>  C;
       cout << "Enter input T\n"<<endl;
       cin >> T;


//        std::future<std::future<mp::cpp_int>, threads> futures;
// std::array<mp::cpp_int, threads> results;
// for (auto i = 1; i <= threads; ++i) {
//     futures[i - 1] = std::async(std::launch::async, thread_fact, test, i);
// }
// for (auto i = 0; i < threads; ++i) {
//     results[i] = futures[i].get();
// }
// std::mutex myMutex;
    
    const int num_threads = T;
    // std::thread t[num_threads];
    // std::launch::async;
    
    // for (int i = 0; i < num_threads; i++) {
    //       t[i] = std::thread(call_from_thread, i, n, B, C, T);
    //    }
for (int i = 0; i < num_threads; i++) {
    //  std::lock_guard<std::mutex> guard(myMutex);
        //   std::async(std::launch::async, [call_from_thread()]{ i, n, B, C, T; });
        //    std::future<int> result( std::async([](i, n, B, C, T;) { return m + n;} , 2, 4));
std::async(std::launch::async, [i, n, B, C, T]{ call_from_thread(i, n, B, C, T); });
       }
       std::cout << "Launched from the main\n";

       //Join the threads with the main thread
            //     for (int i = 0; i <T; ++i) {
            //     t[i].join();
            // }

    return 0;

}


