class Solution {
public:
    bool valid(char ch){
    if((ch<='z' && ch>='a') || (ch<='Z' && ch>='A') || (ch<='9' && ch>='0')){
        return 1;
    }
    else {
        return 0;
    }
    
}

char small(char ch){
    if(ch<='z' && ch>='a' || (ch<='9' && ch>='0')){
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}
bool isPalindrome(string s)
{
    if(s.length()==1 && !valid(s[0])){
        return 1;
    }
    int i=0;
    int j=s.length()-1;
    while(i<=j){
        while(!valid(s[i])){
            i++;
            if(i>s.length()){
                break;
            }
        }
        while(!valid(s[j])){
            j--;
            if(j<0){
                break;
            }
        }
        if(small(s[i])==small(s[j])){
            i++;
            j--;
        }
        else {
            return 0;
        }
        
    }
    return 1;
}
};