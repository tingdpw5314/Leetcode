#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include <sstream>


using namespace std;
const int size =9;

template<typename T>
void PrintItvector(vector<vector<T> >& a){
	for(int i = 0; i < a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template<typename T>
void PrintItvector(vector<T>& a){
	for(int i = 0; i < a.size(); i++){
			cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<typename T>
void PrintIt(T (&a)[size][size], int size){
	for(int i = 0; i < size; i++){
		for(int j=0; j<size; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


string IntToString(int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 /*
   ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
*/


    ListNode* swapPairs(ListNode* head) {
        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;
        head = Dummy;
        while(head->next!= NULL and head->next->next != NULL){
            ListNode *n1 = head->next, *n2 = head->next->next;
            head->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            head = n1;
        }  
        return Dummy->next;
    }



int main(){
	vector<int> a = {1,2,3,4};
	ListNode* head = new ListNode(a[0]);
	ListNode* tail = head;
	ListNode* ans;

	for(int i = 1; i<a.size(); i++){
		ListNode* tail1 = new ListNode(a[i]);
		tail->next = tail1;
		tail = tail->next;


	}

	ans = swapPairs(head);
	while(ans){
		cout<<ans->val<<" ";
		ans=ans->next;
	}
	cout<<endl;

	return EXIT_SUCCESS;
}