#include <iostream>
#include <algorithm>

using namespace std;
bool sort_function (int i,int j) { return (i<j); }
int main()
{
    int sum = 0;
    int n;
    cin >> n;
    vector<int> brojevi;
    for(int i = 0; i < n ; i++){
        int temp;
        cin >>temp;
        brojevi.push_back(temp);
    }
    sort(brojevi.begin(), brojevi.end(), sort_function);
    for(vector<int>::iterator it = brojevi.end()-1;it>=brojevi.begin();--it){
        if(*it % 2 == 0 ){
            sum += *it;
            brojevi.erase(it);
        }
    }
    if(brojevi.size() % 2 == 0){
        for(vector<int>::iterator it = brojevi.begin(); it != brojevi.end(); it++){
            sum+= *it;
        }
    }else{

        for(vector<int>::iterator it = brojevi.begin()+1; it != brojevi.end(); it++){
            sum+= *it;
        }
    }
    cout << sum << endl;
    return 0;
}
