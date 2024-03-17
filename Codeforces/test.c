#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct Node Node;
typedef struct Node* Nodeptr;
struct Node{
    int val;
    Nodeptr right;
    Nodeptr left;
};


Nodeptr init(int x){
    Nodeptr head = (Nodeptr)malloc(sizeof(Node));
    head->right = NULL;
    head->left = NULL;
    head->val = x;
    return head;
}

Nodeptr createTree(int* arr, int n){
    
    Nodeptr v[n];
    for(int i=0;i<n;i++){
        if(arr[i] != -1){
            v[i] = init(arr[i]);
        }
    }

    int idx = 0;
    
    while(idx<n){
        if(arr[idx] == -1){
            idx+=1;
            continue;
        }
        if(2*idx+1<n && arr[2*idx+1]!=-1){
            v[idx]->left = v[2*idx+1];
        }
        if(2*idx+2<n && arr[2*idx+2]!=-1){
            v[idx]->right = v[2*idx+2];
        }
        idx+=1;;
    }
    return v[0];
}



bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        return (
            p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)
        );
    }
    
    
int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	Node*p=createTree(a,n);
	Node*q=createTree(b,n);
	if(isSameTree(p,q)){
		printf("%s\n","YES");
	}
	else{
		printf("%s\n","NO");
	}
}