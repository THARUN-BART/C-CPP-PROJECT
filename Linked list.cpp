#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
void display(Node*head) {
    Node* temp=head;
    while(temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}
Node* covertArr2Ll(vector <int> arr) {
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size(); ++i) {
        Node* temp=new Node(arr[i]);
        mover-> next=temp;
        mover=temp;
    }
    return head;
}
int lengthLl(Node* head) {
    int cnt=0;
    Node* temp=head;

    while(temp) {

        temp=temp->next;
        cnt++;
    }
    return cnt;
}

Node* DeleteHead(Node* head) {
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* DeleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* RemoveK(Node* head,int k) {
    if (head==NULL) return head;
    if (k==1) {
        Node* temp=head;
        head=temp->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node*temp=head;
    Node*prev=NULL;

    while(temp) {
        cnt++;
        if(cnt==k) {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* RemoveEle(Node* head,int val) {
    if (head==NULL) return head;
    if (head->data==val) {
        Node* temp=head;
        head=temp->next;
        delete temp;
        return head;
    }

    Node*temp=head;
    Node*prev=NULL;

    while(temp) {

        if(temp->data==val) {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* InsertHead(Node* head,int val) {
    return new Node(val,head);

}

Node* InsertTail(Node* head,int val) {
    if(head==NULL) return new Node(val,head);
    Node* temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    Node *node=new Node(val);
    temp->next=node;
    return head;
}
Node* InsertK(Node* head,int k,int el) {
    if(head==NULL) {
        if(k==1) {
            return new Node(el);
        }
        else {
            return head;
        }
    }
    if(k==1) {
        Node* newHead=new Node(el,head);
        return newHead;
    }
    int cnt=0;
    Node* temp=head;
    while(temp) {
        cnt++;
        if(cnt==(k-1)) {
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* InsertVal(Node*head,int val,int el) {
    if(head==NULL) return NULL;
    if(head->data==val) {
        return new Node(el,head);
    }
    Node* temp=head;
    while(temp) {
        if(temp->next->data==val) {
            Node* x=new Node(el,temp->next);
            temp=temp->next;
            break;
        }
        temp=temp->next;
    }
    return head;

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node* head = covertArr2Ll(arr);

    int choice;
    while (true) {
        cout <<"\t--LINKED LIST OPERATIONS--" "\n1. Display the linked list\n2. Insert at Head\n3. Insert at Tail\n4. Insert at K\n";
        cout << "5. Insert Before Value\n6. Delete Head\n7. Delete Tail\n";
        cout << "8. Delete at K\n9. Delete by Value\n10. Length\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout<<"Exiting from the Linked List";
            break;
        }


        int val, k;
        switch (choice) {
        case 1:
            display(head);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            head = InsertHead(head, val);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> val;
            head = InsertTail(head, val);
            break;
        case 4:
            cout << "Enter position and value: ";
            cin >> k >> val;
            head = InsertK(head, k, val);
            break;
        case 5:
            cout << "Insert value before which value? Enter both: ";
            cin >> k >> val;
            head = InsertVal(head, k, val);
            break;
        case 6:
            head = DeleteHead(head);
            break;
        case 7:
            head = DeleteTail(head);
            break;
        case 8:
            cout << "Enter position to delete: ";
            cin >> k;
            head = RemoveK(head, k);
            break;
        case 9:
            cout << "Enter value to delete: ";
            cin >> val;
            head = RemoveEle(head, val);
            break;
        case 10:
            cout << "Length: " << lengthLl(head) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}