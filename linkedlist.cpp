#include <iostream>
using namespace std;

struct Node {
int num;
Node *next;
};

struct Node *head = NULL;

void insertNode(int n) {
struct Node *new_node = new Node;
new_node -> num = n;
new_node -> next = head;
head = new_node;
return;
}

void display() {
if (head == 0) {
cout << "Empty" << endl;
return;
}
struct Node *temp = head;
while (temp != NULL) {
cout << temp -> num << " ";
temp = temp -> next;
}
cout << endl;
return;
}

void deleteItem(){
if (head == NULL) {
cout << "List is empty" << endl;
return;
}
cout << head -> num << " is removed" << endl;
head = head -> next;
return;
}

int main()
{
display();
insertNode(0);
insertNode(20);
insertNode(30);
insertNode(40);
insertNode(50);
display();
deleteItem();
deleteItem();
deleteItem();
deleteItem();
deleteItem();
display();
return 0;
}
