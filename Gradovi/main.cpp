#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

long long d[1000000];//Distance function

list<pair<int,int> > *graph;



void dijkstra(int root) { // algorithm taken from http://codeforces.com/blog/entry/12908

    set<pair<int,int> > pq;
    /* A set helps insertion and extraction operations in logarithmic time.
     This set maintains (distance,vertex number) pair sorted on basis of distance*/

    set<pair<int,int> > ::iterator it;

    int u,v,wt;

    list<pair<int,int> > :: iterator i;

    d[root]=0;

    pq.insert(pair<int,int>(0,root));

    while(pq.size()!=0){
        it=pq.begin();
        u=it->second;
        pq.erase(it);
        for(i=graph[u].begin(); i!=graph[u].end(); i++)
        {
            v=i->first;
            wt=i->second;
            //Relax u-v edge with weight wt below:
            if(d[v]>d[u]+wt)
            {
                if(d[v]!=1e8)
                {
                    pq.erase(pq.find(pair<int,int>(d[v],v)));
                }
                d[v]=d[u]+wt;
                pq.insert(pair<int,int>(d[v],v));
            }
    //Relax ends

        }

    }
}

void addedge(int src,int des,int wt) {
    //adds two way edge because graph is undirected
    pair<int,int> x;
    x.first=des;
    x.second=wt;
    graph[src].push_front(x);
    x.first=src;
    x.second=wt;
    graph[des].push_front(x);
}

int main() {

    int i;
    int v,e,k,src,des,wt,ggrad;
    vector<int> sgrad;
    // number of cities(vertexes), number of roads, number of special cities
    cin>>v>>e>>k;

    for(i=0;i<k;i++){
        // pick all special cities
        int temp;
        cin >> temp;
        sgrad.push_back(temp);
    }
    //pick destination ( or main city)
    cin >> ggrad;

    //make new graph consisting of road relations
    graph=new list<pair<int,int> >[v+1];

    for(i=0; i<e; i++){
        // add edges to graph
        cin>>src>>des>>wt;
        addedge(src,des,wt);
    }
    long long mapa[v+1][v+1];
    //map vertex to any other vertex min distance ( time ) saves us a lot of computing time
    for(long i=1;i <= v;i++){
        for(int i=0;i <=v;i++){
            d[i] = 1e8;
        }
        dijkstra(i);
        for(long i1=1;i1<=v;i1++){
            mapa[i][i1] = d[i1];
        }
    }


int shortest = numeric_limits<int>::max();
sort(sgrad.begin(), sgrad.end());
 do {
        /*
            Do permutations of special ( must see ) cities to
            get the shortest possible path;
        */
        long s = mapa[1][sgrad[0]]; // from beginning (1) to first special city
        for(int i=0; i<sgrad.size() - 1; i++){
           //from first to second, second to third,..etc
           s += mapa[sgrad[i]][sgrad[i+1]];
        }
        s += mapa[sgrad[sgrad.size()-1]][ggrad]; // from last to main
        if(s <= shortest){
            shortest = s;
        }

 }while(next_permutation(sgrad.begin(),sgrad.end()));
cout << "SHORTEST : " << shortest <<  endl;
//system("PAUSE") you might need this line
return 0;
}
