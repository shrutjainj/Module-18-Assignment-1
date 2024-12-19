#include<iostream>
#include<vector>
using namespace std;
void merging(vector<int>& a, vector<int>& b, vector<int>& resu)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<a.size() && j<b.size())
    {
        if(a[i] > b[j]) resu[k++] = a[i++];
        else resu[k++] = b[j++]; // a[i] < b[j]
    }
    if(i == a.size())
    {
        while(j < b.size())
        {
            resu[k] = b[j];
            k++;
            j++;
        }
    }
    else  while(i < a.size()) resu[k++] = a[i++]; // j == b.size()
}
void mergesort(vector<int> v)
{
    int n = sizeof(v)/sizeof(v[0]);
    int n1 = n/2;
    int n2 = n - n1;
    vector<int> a;
    vector<int> b;
    for(int i=0; i<n1; i++)
    {
        a[i] = v[i];
    }
    for(int j=0; j<n2; j++) b[j] = v[n1 + j];
    mergesort(a);
    mergesort(b);
    merging(a, b, v);
}
int main()
{
    int ar[] = {2,4,4,4,7,5,2,1,8,4,6,9};
    int n = sizeof(ar) / sizeof(ar[0]);
    vector<int> v(ar, ar+n);
     for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
}