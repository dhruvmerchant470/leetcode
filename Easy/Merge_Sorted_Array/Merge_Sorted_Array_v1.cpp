class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    vector<int>arr3(m+n);
    int i=0,j=0,k=0;
    while(i!=m && j!=n)
    {
        if(arr1[i]>arr2[j])
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
        else 
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
    }
    while(i<m)
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    for(int i=0;i<arr3.size();i++)
    {
        arr1[i]=arr3[i];
    }
    }
};