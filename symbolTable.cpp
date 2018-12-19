//Symbol Table with simple hashing and pointer

#include<bits/stdc++.h>
using namespace std;

map<int,string>mp;
struct symTable{
    string ss;
    struct symTable *next;
} *table;
struct symTable *head[100];

void initialize(){
    for(int i=0;i<100;i++)
        head[i]=NULL;
}

void _insert(int i, string s){
    //cout<<"inside of insert "<<i<<endl;
    table=(struct symTable*) malloc(sizeof(struct symTable));
    table->ss=s;
    table->next=NULL;

    if(head[i]==NULL){
        head[i]=(struct symTable*) malloc(sizeof(struct symTable));
        head[i]=table;
        return ;
    }
    struct symTable *temp=(struct symTable*) malloc(sizeof(struct symTable));
    temp=head[i];

    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=table;
}

void _update(int i, string neo, string old){

    if(head[i]==NULL){
        printf("List is empty\n");
        return ;
    }

    struct symTable *temp=(struct symTable*) malloc(sizeof(struct symTable));
    temp=head[i];

    while(temp->ss!=old && temp->next!=NULL)
        temp=temp->next;

    if(temp->ss==old){
        cout<<old<<" is replaced with "<<neo<<"."<<endl;
        temp->ss=neo;
    }
    else
        printf("Existing data is not found\n");
}

void _delete( int i, string s ){

    if(head[i]==NULL){
        printf("List is empty\n");
        return ;
    }

    struct symTable *temp=(struct symTable*) malloc(sizeof(struct symTable));
    struct symTable *prev=(struct symTable*) malloc(sizeof(struct symTable));
    temp=head[i];

    while(temp->ss!=s && temp->next!=NULL){
        prev=temp;
        temp=temp->next;

    }

    if(temp->ss==s){
        prev->next=temp->next;
        cout<<s<<" is deleted."<<endl;
    }
    else
        printf("Existing data is not found\n");
}

void show(){

    struct symTable *temp=(struct symTable*) malloc(sizeof(struct symTable));
    for(int i=0; i<100; i++){
        temp=head[i];
        if(temp==NULL){
            continue;
        }
        cout<<">>> All "<<mp[i]<<" >>>"<<endl;
        while(temp->next!=NULL){
            cout<<temp->ss<<", ";
            temp=temp->next;
        }
        cout<<temp->ss<<endl;
    }

}

void _search(int i,string s){

    if(head[i]==NULL){
        printf("List is empty\n");
        return ;
    }

    struct symTable *temp=(struct symTable*) malloc(sizeof(struct symTable));
    temp=head[i];

    while(temp->ss!=s && temp->next!=NULL)
        temp=temp->next;

    if(temp->ss==s)
        cout<<"Data: "<<s<<" is found"<<endl;
    else
        printf("Data not found\n");
}

int getHashKey(string str){
    int val=0;
    for(auto s:str)
        val+=s;

    return val%99;
}


int main()
{
    initialize();
    string s1,s2,s3;
    int index;
    while(1){
        int n;
        printf("Select an operation from the below:\n");
        printf("\t <1> Insert\n\t <2> Update\n\t <3> Delete\n\t <4> Show\n\t <5> Search\n\t <6> Exit\n");
        printf("Enter the option number :: ");
        scanf("%d",&n);
        //======================

        switch(n){
        case 1:
            printf("Enter your input for insert(new:name) ::> ");
            cin>>s1>>s2;
            index=getHashKey(s2);
            mp[index]=s2;
            _insert(index,s1);
            break;
        case 2:
            printf("Enter your input for Update (new:existing:name)::> ");
            cin>>s1>>s2>>s3;
            index=getHashKey(s3);
            _update(index,s1,s2);
            break;
        case 3:
            printf("Enter your input for Delete (data:name) ::> ");
            cin>>s1>>s2;
            index=getHashKey(s2);
            _delete(index,s1);
            break;
        case 4:
            show();
            break;
        case 5:
            printf("Enter your input for Search (data:name) ::> ");
            cin>>s1>>s2;
            index=getHashKey(s2);
            _search(index,s1);
            break;
        default:
            exit(0);
        }
        cin.ignore();
    }
    return 0;
}
