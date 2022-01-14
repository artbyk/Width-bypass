#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>    
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int n,m,s;
    cin>>n>>m>>s;
    if(m == s){
        cout<<0;
        return 0;
    }
    int **arr = new int*[n];
    for(int i =0;i<n;i++){
        arr[i] = new int[n];
        for(int q = 0; q< n;q++){
            cin>>arr[i][q];
        }
    }
    vector<int> vec;
    vector<int> vec_buf;
    vec_buf.push_back(0);
    vec.push_back(m-1);
    int buf, flag = 0;
    std::vector<int>::iterator it;
    while(true){
        buf = vec[flag];
        for(int i = 0; i< n;i++){
            if(arr[buf][i] == arr[i][buf] && arr[buf][i] == 1){
                if(i == (s-1)){
                    cout<<1+vec_buf[flag];
                    return 0;
                }
                it = find(vec.begin(), vec.end(), i);
                if(it != vec.end()){
                    continue;
                }
                else{
                    vec.push_back(i);
                    vec_buf.push_back(vec_buf[flag] + 1);
                }
            }
        }
        if(flag >= vec.size()){
            cout<<0;
            return 0;
        }
        flag++;
    }
    for(int i =0;i<n;i++){
        delete[] arr[i];
    }
}
