#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;


int main(){

    ifstream f("date.in");
    ofstream g("date.out");
    int n, m, s, x, y, nod;
    f >>n >>m;
    queue <int> c;
    
    int tata[n + 1]; //arbore cu nivele de la radacina
    int vizitat[n + 1];
    for (int i = 1; i <= n; i++) {
        vizitat[i] = 0;
    }
    vector <int> la[n + 1];
    for (int i = 1; i <= m; i++) {
        f >> x >> y;

        la[x].push_back(y);
        la[y].push_back(x);
    }

    f >> s; //nodul de pornire
    int nivel = 0;
    tata[s] = 0; 
    c.push(s);
    vizitat[s] = 1;
    int cate = la[s].size();

    f >> nod; //nodul cautat


   while(c.size() > 0){
        s = c.front();
        int cate = la[s].size();

        for (int i = 0; i < cate; i++) {
            if(vizitat[la[s][i]] == 0){
                vizitat[la[s][i]] = 1;
                c.push(la[s][i]);
                tata[la[s][i]] = s;
            }
            
            
        }
        if(vizitat[nod] == 1){
                g << nod << " ";
                for (int i = tata[nod]; i > 0; i--) {
                    for (int j = 1; j <= n; j++) {
                        if(tata[j] == i - 1 && vizitat[la[i][j]] == 1){
                            g << j;
                            break;
                        }
                    }
                }
                break;
        }
        
        for (int i = 1; i <= n; i++) {
            g << "        " << tata[i];
        }
        
        c.pop();
    }
    
    


    f.close();
    g.close();

    return 0;
}
