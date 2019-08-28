#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
};
node* root = new node;

node* newNode(int val){
    node* temp = new node;
    temp->data = val;
    return temp;
}
void createTree(int arr[]){
    root->data = arr[0];
    root->left = newNode(arr[1]);
    root->right = newNode(arr[2]);
    root->left->left = newNode(arr[3]);
    root->left->right = newNode(arr[4]);
    root->right->left = newNode(arr[5]);
    root->right->right = newNode(arr[6]);
    root->left->left->left = newNode(arr[7]);
    root->left->left->right = newNode(arr[8]);
    root->left->right->left = newNode(arr[9]);
}

void ZigZagTraverse(){
    bool lefttoright = true;

    if(!root)
        return;

    stack<node*> currentLevel;
    stack<node*> nextLevel;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        node* temp = currentLevel.top();
        
        currentLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(lefttoright){
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else{
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if(currentLevel.empty()){
            lefttoright = !lefttoright;
            swap(currentLevel, nextLevel);
        }
    }

}


int main(){
    int arr[10] = {1,2,3,4,5,8,6,7,11,15};
    createTree(arr);
    ZigZagTraverse();
    return 0;
}