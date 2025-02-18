// LPS longest prefix suffix 

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int lps(string s){

    vector<int> lps(s.size(),0); //initalizing a vector lps of size equal to the string s with 0 as the default value;

    int pre = 0, suf = 1;

    while (suf < s.size())
    {
        //match
        if (s[pre]==s[suf])
        {
            lps[suf]=pre+1;
            pre++,suf++;
        }
        // Not matched
        else{
            if (pre==0)
            {
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre -1];
            }
            
        }

    }

    for(int i = 0; i < s.size(); i++)
        {   
            cout<<s[i]<<" |";
        }
        cout<<endl;

    for(int i = 0; i < s.size(); i++)
        {   
            cout<<lps[i]<<" |";
        }
        cout<<endl;
    
    return lps[s.size() - 1];
};



int main(){

    string name = "ABCABDABCABDABDAB";
    int length  = lps(name);

    cout<<"Lenght of the proper prefix suffix is : "<<length<<endl;
    return 0;
}