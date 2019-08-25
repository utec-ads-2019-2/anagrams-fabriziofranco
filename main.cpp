#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

string transform(string palabra){
    transform(palabra.begin(),palabra.end(),palabra.begin(),[](char letra){return tolower(letra);});
    sort(palabra.begin(),palabra.end());
    return palabra;}

int main() {
    string palabra; map<string,int> cantidad; vector<string> limpias;
    while(cin>>palabra && palabra!="#"){
        string temp=palabra;
        palabra=transform(palabra);
        cantidad[palabra]++;
        if(cantidad[palabra]==1)
            limpias.push_back(temp);
        else if(cantidad[palabra]>1){
            for(int i=0;i<limpias.size();i++){
                string temp2 = transform(limpias[i]);
                if(temp2==palabra)
                    limpias.erase(limpias.begin()+i); } } }
    sort(limpias.begin(),limpias.end());
    for(auto & limpia : limpias)
        cout<<limpia<<endl;
    return EXIT_SUCCESS;}
