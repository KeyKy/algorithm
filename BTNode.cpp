#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

class BTNode{
public:
	char data;
	BTNode *lchild, *rchild;
	BTNode(){
		lchild = NULL;
		rchild = NULL;
	}
	~BTNode(){
		if(lchild != NULL){
			delete lchild;
		}
		if(rchild != NULL){
			delete rchild;
		}
	}
};

BTNode * createBTTreeByString(const char *chr){
	int length = strlen(chr);
	char c = chr[0]; int j = 0;
	int k = 1;
	BTNode *st[MAX_SIZE]; int top = -1;
	BTNode *b = NULL, *p;
	while(c != '\0'){
		switch(c){
		case '(': k=1;st[++top]=p; break;
		case ',': k=2; break;
		case ')': top--; break;
		default:{
			p = new BTNode(); p->data = c; p->lchild = p->rchild = NULL;
			if(b == NULL)
				b = p;
			else{
				switch(k){
				case 1: st[top]->lchild = p; break;
				case 2: st[top]->rchild = p; break;
				}
			}
		}
		}
		j++;
		c = chr[j];
	}
	return b;
}

void preOrder_unrec(BTNode *head){
	BTNode *st[MAX_SIZE], *tmp; int top = -1;
	st[++top] = head;
	while(top != -1){
		tmp = st[top--];
		cout << tmp->data << ' ';
		if(tmp->rchild != NULL)
			st[++top] = tmp->rchild;
		if(tmp->lchild != NULL)
			st[++top] = tmp->lchild;
	}
	cout << endl;
}

void inOrder_unrec(BTNode *head){
	BTNode *st[MAX_SIZE], *curr = head; int top = -1;
	while(curr != NULL || top != -1){
		while(curr != NULL){
			st[++top] = curr;
			curr = curr->lchild;
		}
		curr = st[top--];
		cout << curr->data << ' ';
		curr = curr->rchild;
	}
	cout << endl;
}

void postOrder_unrec(BTNode *head){
	BTNode *st1[MAX_SIZE], *st2[MAX_SIZE]; int top1 = -1, top2 = -1;
	st1[++top1] = head;
	while(top1 != -1){
		BTNode *tmp = st1[top1--];
		st2[++top2] = tmp;
		if(tmp->lchild != NULL)
			st1[++top1] = tmp->lchild;
		if(tmp->rchild != NULL)
			st1[++top1] = tmp->rchild;
	}
	while(top2 != -1){
		cout << st2[top2--]->data << ' ';
	}
	cout << endl;
}

int main(){
	char ch[100];
	BTNode *head = NULL;
	while(cin >> ch){
		head = createBTTreeByString(ch);	
		preOrder_unrec(head);
		inOrder_unrec(head);
		postOrder_unrec(head);

		delete head;
	}

}