#include<iostream>
  //  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    private :
     ListNode *reverse ( ListNode *Head  ) {
         ListNode * temp = Head  ;
         ListNode * Next = nullptr  ;
         ListNode * Prev = nullptr ;
         while ( temp!=nullptr) {
            Next = temp->next  ;
             temp->next  = Prev ;
             Prev = temp ;
             temp = Next ;
         }
         return  Prev ;
     }

     // addtion of two linked list  
      ListNode *addtion (ListNode* head1  , ListNode*head2   ,  int carry  ) {
        int sum  =  0  ;
      ListNode * temp1  = head1 ;
      ListNode*temp2 = head2  ;
      ListNode * head3 = new ListNode(0) ;
      ListNode *temp3  = head3  ;
      while ( temp1  != nullptr || temp2!=nullptr || carry!= 0  )  {
        sum = carry  ;
        if(temp1 != nullptr) {
            sum = sum+ temp1->val ;
            temp1 = temp1->next  ;
        }
        if ( temp2 != nullptr ){
            sum = sum+ temp2->val ;
            temp2 = temp2->next  ;
        }
        int digit = sum % 10  ;
        carry = sum / 10  ;
        temp3->next  = new ListNode(digit) ;
        temp3 = temp3->next ;
        

      }
      
        return head3->next     ;
} 
//  find length of linked list  
int  len( ListNode*head) {
    int l = 0  ;
    ListNode*temp = head  ;
    while ( temp != nullptr) {
        l++   ;
        temp= temp->next  ;
    }
    return l  ;
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )  return l2  ;
        if (l2 == nullptr) return l1  ;

        ListNode * temp1  = l1  ;
       ListNode *temp2  = l2   ;
            
     int len1  = len(l1) ;
     int len2 = len(l2) ;
     if ( len1 <= len2) {
        ListNode * ans  = addtion ( l1 , l2   ,  0  ) ;
        return ans ;
     }
         if ( len1 > len2) {
        ListNode * ans  = addtion ( l1 , l2   ,  0  ) ;
        return ans ;
     }
        ListNode *result1  = reverse ( l1) ;
        ListNode *result2 = reverse (l2) ;

        // addintion of two linked list  
        ListNode * ans  = addtion ( result1 , result2  ,  0  ) ;

       return ans ;
        
    }
};