#include<iostream>
#include<vector>
#include<string>

using namespace std;

class LeetCode28KMP{

    public:

    void lpsCreate(vector<int> &lps,string s){

        int pre = 0, suf = 1;

        while (suf<s.size())
        {
            //matched
            if (s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                pre++,suf++;
            }
            // not matched
            else{

                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
            
        }
        
    }

    string solution(string haystack,string needle){

        vector<int>lps(needle.size(),0);

        lpsCreate(lps,needle);

        int textIndex = 0, patternIndex = 0;

        string indexReturn = "";
        int result;

        while (textIndex < haystack.size())
        {
            

            //if only a substring is matched
            if (needle[patternIndex] == haystack[textIndex])
            {
                patternIndex++, textIndex++;

                //if complete pattern is matched
                if (patternIndex == needle.size())
                {   
                    result = textIndex - patternIndex;
                    indexReturn += to_string(result) + " ";
                    patternIndex = lps[patternIndex - 1];

                }

            }
            // Not matched
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
        if (indexReturn.size()>0)
        {
            return "found at these indexes "+indexReturn;
        }else{
            return "Not Found in the text";
        }
        
        

    }
};


int main(){

    LeetCode28KMP ltkmp;

    string haystack = "lolButlolhahalol";
    string needle = "lol";
    string indexes = ltkmp.solution(haystack,needle);

    cout<<"The pattern is "<<indexes<<endl;


    return 0;
}