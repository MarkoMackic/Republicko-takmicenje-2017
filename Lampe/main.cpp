#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <unordered_map>


using namespace std;

int izracunajOsvjetljene(vector<vector<int>> *matrica){
    // preracunajmo broj osvjetljenih redova

    int sum = 0;
    int brojKolona = (*matrica)[0].size();
    for(int y=0;y<(*matrica).size();y++){
        int tmpInt=0;
        for(int x=0;x<brojKolona;x++){
            if((*matrica)[y][x] == 1) tmpInt++;
        }

        if(tmpInt == brojKolona){
            sum++;
        }
    }
     return sum;
}
int uradiProces(vector<vector<int>> *matrica){
    if(matrica->size() == 0){
        return -1;
    }
    int brojkolona = (*matrica)[0].size();
    int brojOsvjetljenih[brojkolona];
    int nuleUKoloni[brojkolona];
    for(int i=0;i<brojkolona;i++){
        nuleUKoloni[i] = 0;
    }

    //koliko kolona imamo trenutno osvjetljenih u matrici
    int maxN = izracunajOsvjetljene(matrica);

    for(long x=0;x<brojkolona;x++){
        for(long y=0;y<matrica->size();y++){
            // promjenimo kolonu
            (*matrica)[y][x] = !(*matrica)[y][x];
            if((*matrica)[y][x] == 1){
                // ako je nakon izmjene 1 onda znaci da
                // je bila nula, zabiljezimo
                nuleUKoloni[x]++;
            }
        }
        // takodje provjerimo koliko smo kolona osvjetlili
        // sa ovom promjenom
        brojOsvjetljenih[x] = izracunajOsvjetljene(matrica);

        // vratimo matricu u staro stanje.
        for(long y=0;y<matrica->size();y++){
            (*matrica)[y][x] = !(*matrica)[y][x];
        }
    }

    int idx = -1;
    // pretrazimo da li smo promjenom neke kolone osvjetlili
    // i zabiljezimo tu kolonu za stvarnu promjenu
    for(int i=0;i<brojkolona;i++){
        if(brojOsvjetljenih[i] > maxN){
            maxN = brojOsvjetljenih[i];
            idx = i;
        }
    }
    // ukoliko nismo osvjetlili ni jednu vise kolonu od originala
    // uzecemo kolonu koja ima najvise nula;
    int najviseNula = 0;
    if(idx == -1){
        for(int i=0;i<brojkolona;i++){
            if(nuleUKoloni[i] > najviseNula){
                idx = i;
                najviseNula = nuleUKoloni[i];
            }
        }
    }

    for(int i=0;i<matrica->size();i++){
        (*matrica)[i][idx] = !(*matrica)[i][idx];
    }
}
int main()
{
    int y, x, k;
    cin >> y >> x >> k;
    vector<vector<int>> matrica;

    for(int i=0;i<y;i++){
        vector<int> tempVec;
        for(int i1=0;i1<x;i1++){
            char temp;
            cin >> temp;
            tempVec.push_back((int)temp-48);
        }
        matrica.push_back(tempVec);
    }

    for(int i=0;i<k;i++){
        // provec radimo k puta
        uradiProces(&matrica);
    }
    cout << izracunajOsvjetljene(&matrica);


    return 0;
}
