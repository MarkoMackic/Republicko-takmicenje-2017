#include <iostream>
#include <algorithm>

using namespace std;
bool sort_function (int i,int j) { return (i<j); }
int main()
{
    long long sum = 0;
    int n;
    cin >> n;
    vector<long long> brojevi;
    for(int i = 0; i < n ; i++){
        long long temp;
        cin >>temp;
        brojevi.push_back(temp);
    }
    sort(brojevi.begin(), brojevi.end(), sort_function);
    for(vector<long long>::iterator it = brojevi.end()-1;it>=brojevi.begin();--it){
        if(*it % 2 == 0 ){
            sum += *it;
            brojevi.erase(it);
        }
    }
    if(brojevi.size() % 2 == 0){
        for(vector<long long>::iterator it = brojevi.begin(); it != brojevi.end(); it++){
            sum+= *it;
        }
    }else{

        for(vector<long long>::iterator it = brojevi.begin()+1; it != brojevi.end(); it++){
            sum+= *it;
        }
    }
    cout << sum << endl;
    return 0;
}
