#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next = NULL;
};
node* start1 = NULL;
node* start2 = NULL;

node* newNode(int var){
    node* temp = new node;
    temp->data = var;
    return temp;
}

void createList(int arr[], int n, int var){
    node* temp;
    if(var == 1){
        start1 = newNode(arr[0]);
        temp = start1;
    }
    else if(var == 2){
        start2 = newNode(arr[0]);
        temp = start2;
    }
    
    for(int i=1;i<n;i++){
        temp->next = newNode(arr[i]);
        temp = temp->next;
    }
}

void insert(){
    node* list1 = start1;
    node* list2 = start2;

    while(list1 && list2){
        node* temp = newNode(list1->data);
        node* list2next = list2->next;
        list2->next = temp;
        temp->next = list2next;

        list2 = list2next;
        list1 = list1->next;
        start1=list1;
    }
}

void printList(int var){
    node* temp;
    if(var == 1)
        temp = start1;
    else if(var == 2)
        temp = start2;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    cout<<"Enter number of nodes of linked list 1 :- ";
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cout<<"Enter value "<<i+1<<" :- ";
        cin>>arr1[i];
    }
    createList(arr1, n1, 1);

    cout<<"Enter number of nodes of linked list 2 :- ";
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cout<<"Enter value "<<i+1<<" :- ";
        cin>>arr2[i];
    }
    createList(arr2, n2, 2);

    insert();
    printList(1);
    printList(2);

}