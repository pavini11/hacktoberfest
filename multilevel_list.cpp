#include<iostream>
using namespace std;

class Node
{
public:
int data;

Node *next;
Node *pre;
Node *down;
};

Node *flattenList(Node *node) {
if(node == 0)
return NULL;
static Node *last;
last = node;
Node *next = node -> next;
if(node -> down)
node -> next = flattenList(node -> down);
if(next) {
last -> next = flattenList(next);
return node;
}
}

void print(Node *head) {
while(head) {
cout << head -> data << " ";
head = head -> next;
}
}

Node* newNode(int new_data) {
Node* new_node = new Node;
new_node -> data = new_data;
new_node -> next = new_node -> pre = new_node -> down = NULL;
return new_node;
}

int main() {
Node* head = newNode(1);
head -> next = newNode(2);
head -> next -> pre = head;
head -> next -> next = newNode(3);
head -> next -> next -> pre = head -> next;
head -> next -> next -> down = newNode(7);
head -> next -> next -> down -> next = newNode(8);
head -> next -> next -> down -> next -> pre = head -> next -> next -> down;
head -> next -> next -> next = newNode(4);
head = flattenList(head);
print(head);
}

