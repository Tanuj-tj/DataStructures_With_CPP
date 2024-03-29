#include<bits/stdc++.h>
using namespace std;

class LowerTriangular{

    private:
        int *A;  // A[n][n]
        int n; // nxn

    public:
        LowerTriangular(){
            n=2;
            A=new int[2*(2+1)/2];
        }
        LowerTriangular(int n){
            this->n = n;
            A = new int[n*(n+1)/2];  // No. of non zero elememnts
        }
        ~LowerTriangular(){
            delete[]A;
        }
        void set(int i,int j,int x);
        int get(int i,int j);
        void Display();
        int getDimension(){return n;}
};

void LowerTriangular::set(int i,int j,int x){
    if(i>=j)
        A[i*(i-1)/2+j-1] = x;
}

int LowerTriangular::get(int i,int j){
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}

void LowerTriangular::Display(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0"<<" ";
        }
        cout<<endl;
    }   
}

int main(){

    int d;
    cout<<"Enter Dimensions : ";
    cin>>d;

    LowerTriangular lm(d);

    int x;
    cout<<"Enter All Elements : "<<endl;
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            lm.set(i,j,x);
        }
    }
    
    cout<<"All elements : "<<endl;
    lm.Display();
    return 0;
}