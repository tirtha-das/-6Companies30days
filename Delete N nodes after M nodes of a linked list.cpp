struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* newHead = new Node(-1);
        Node* prev = newHead;
        
        int cnt = 0;
        int skip = 1;
        
        while(head!=NULL){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            cnt++;
            if(skip){
                prev->next = temp;
                prev=prev->next;
                if(cnt==m){
                    skip=0;
                    cnt=0;
                }
            }else if(cnt==n){
                skip=1;
                cnt=0;
            }
        }
        
        return newHead->next;
        
    }
};