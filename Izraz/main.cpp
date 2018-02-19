#include <iostream>
#include <string>
using namespace std;

long long finalni_broj;
bool znak = true;

void uradiPostupak(string broj){
   //cout << "POSTUPAK ZA BROJ " << broj << " " << znak << endl;
   if(broj.length() == 0){return;}
   if(znak){
    finalni_broj += stoll(broj);
   }else{
    finalni_broj -= stoll(broj);
   }
}
int main()
{
    string ulaz;
    string broj = "";

    getline(cin, ulaz);

    for(char& c: ulaz){
        //cout << c << endl;
        if(isdigit(c)){
            if(znak){
              broj+=c;
            }else{
              finalni_broj -= (int)c - 48;
              //cout << "HELLO " <<  (int)c - 48 << endl;
              broj = "";
              znak = true;
            }
        }else if(c == '+'){
            uradiPostupak(broj);
            znak=true;
            broj = "";
        }else if(c == '-'){
            uradiPostupak(broj);
            znak = false;
            broj = "";
        }else{
          continue;
        }
    }
    uradiPostupak(broj);
    cout << finalni_broj;


    return 0;
}
