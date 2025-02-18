#include<iostream>
#include<string>

using namespace std;

// Complexity Analysis of Naive algorithm for Pattern Searching:
// Best Case: O(n)
// When the pattern is found at the very beginning of the text (or very early on).
// The algorithm will perform a constant number of comparisons, typically on the order of O(n) comparisons, where n is the length of the pattern.

// Worst Case: O(n^2)
// When the pattern doesn’t appear in the text at all or appears only at the very end.
// The algorithm will perform O((n-m+1)*m) comparisons, where n is the length of the text and m is the length of the pattern.
// In the worst case, for each position in the text, the algorithm may need to compare the entire pattern against the text
void search(string& pat, string& txt){
    int M = pat.size();
    int N = txt.size();

    // A Loop to slide the pat[] one by one
    for (int i = 0; i <= N - M; i++) //N - M because we don't need to travel the whole string we have to stop just before the last M characters
    {//cause those last M characters will be matched by the innerLoop and if we don't stop the outer loop (loop for text string) then it will go to the end character 
        // of the string and the nested loop will try to access the characters beyond the last character which doesn't exist so it will results in a error
        
        // NOTE:: 
        // Number of possible starting positions:
        // We can start comparing from index 0 to n-m (since we need enough characters left to match the pattern)
        // This gives us (n-m+1) starting positions
        
        int j;
        //for current index i, check for pattern match
        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
            {
                break;
            }
            
        }

        if(j==M){
            cout<<"Pattern found at index "<<i<<endl;
        }
        
    }
    
}

int main(){
    // Example 1
    string txt1 = "AABAACAADAABAABA";
    string pat1 = "AABA";
    cout<<"Example 1: "<<endl;
    search(pat1, txt1);

    // Example 2
    string txt2 = "agd";
    string pat2 = "g";
    cout<<"\nExample 2:  "<<endl;
    search(pat2, txt2); 

    return 0;

}