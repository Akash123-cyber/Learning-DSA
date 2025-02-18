#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
//Find the index of the first Occurrence of the pattern(needle) in the string haystack


class LeetCode28{

    public:

    void lpsCreate(vector<int> &lps,string s){

        int pre = 0, suf = 1;
    
        while (suf<s.size())
        {
            //matched
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++,suf++;
            }
    
            // Not Matched
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre = lps[pre -1];
                }
            }
        }
        
    
    }
    
    int strStr(string haystack, string needle){

            vector<int> lps(needle.size(),0);

            lpsCreate(lps,needle);

            int textIndex = 0, patternIndex = 0;

            while (patternIndex<needle.size() && textIndex < haystack.size())
            {   
                //matched
                if (needle[patternIndex]==haystack[textIndex])
                {
                    patternIndex++, textIndex++;
                }

                //not matched
                else{
                    if (patternIndex == 0)
                    {
                        textIndex++;
                    }
                    else{
                        patternIndex = lps[patternIndex - 1];
                    }
                    
                }
                
            }

            //match exists in the text string
                        // OR
            // needle is found in the haystack
            if (patternIndex == needle.size())
            {
                return textIndex - patternIndex;
            }

            //needle not found in teh haystack
            return -1;
            
            
        }
};


int main(){


    LeetCode28 lt;

    string haystack = "lolButLol";
    string needle = "Lol";

    int index = lt.strStr(haystack,needle);

    if (index == -1)
    {
        cout<<"Needle not found in the haystack"<<endl;
    }else{
        cout<<"Needle is found at the index: "<<index<<" in haystack: "<<haystack<<" and needle name is : "<<needle<<endl;
    }
    

    return 0;
}