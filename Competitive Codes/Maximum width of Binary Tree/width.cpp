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

int width(){
    
    int w = 0;

    if(!root)
        return w;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int var = q.size();
        if(w < var)
            w = var;

        for(int i=1;i<=var;i++){
            node* temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return w;
}


int main(){
    int arr[10] = {1,2,3,4,5,8,6,7,11,15};
    createTree(arr);
    int w = width();
    cout<<endl<<w<<endl;
    return 0;
}