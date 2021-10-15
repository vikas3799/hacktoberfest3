#include<bits/stdc++.h>
using namespace std;

class job{
    public:
    int profit;
    int dead;
};

bool comp(job a, job b){
    return (a.profit > b.profit);
}

int solve(job arr[], int n){
    sort(arr, arr+n, comp);
    
    int max=0;
    for(int i=0; i<n; i++){
        if(max < arr[i].dead)
            max = arr[i].dead;
    }
    vector<int> v, v1;
    int sum = 0;
    for(int i=1; i<=max; i++)
        v.push_back(i);

    for(int i=0; i<n; i++){
        int temp = arr[i].dead;
        for(int j=v.size()-1; j>=0; j--){
            if(v[j] <= temp && v[j] > 0){
                v1.push_back(arr[i].profit);
                v[j] = 0;
                break;
            }
        }
    }
    for(auto i:v1)
        sum += i;
    return sum;
}

int main(){
    int n;
    cout<<"Enter the total number of Jobs\n";
    cin>>n;
    job arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the Profit of the job: ";
        cin>>arr[i].profit;
        
        cout<<endl<<"Enter the deadline of the job: ";
        cin>>arr[i].dead;
        cout<<endl;
    }
    cout<<solve(arr, n);
}