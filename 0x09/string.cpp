#include <iostream>
using namespace std;


int valid(char name[]){
    for(int i = 0; name[i] != '\0'; i++){
        if(!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
            return 0;
    }
    return 1;
}

void reverseS(char *string){
   int l = 0, i = 0, s = 0;
   char t;
   while(string[l] != '\0'){
       l++;
   }
   s = l;
   l = l-1;
   while(i < l){
       t = string[i];
       string[i] = string[l];
       string[l] = t;
       i++;
       l--;
   }
   string[s] = '\0'; 
}

void display(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        cout << string[i];
        i++;
    }
    cout << endl;
}

void compareString(char *a, char *b){
    int i = 0, j = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i])
            break;
        i++;
        j++;
    }
    if(a[i] == b[i]) cout << "equal" << endl;
    else if(a[i] < b[i]) cout << "first string smaller" << endl;
    else cout << "second string smaller" << endl;
}

int palindrome(char *s){
    int i = 0, j = 0; 
    int t = 1;
    while(s[j] != '\0')
        j++;
    j--;

    while(i < j){
        if(s[i] != s[j]){
            t = 0;
            break;
        }
        i++;
        j--;
    }
    return t;
}

void findDup(char *s){
    int htab[26] = {0};
    int l = 0, i = 0;
    while(s[l] != '\0')
        l++;
    l--;

    while(i <= l){
        htab[s[i]-97]++;
        i++;
    }

    for(int i = 0; i < 26; i++){
        if(htab[i] > 0){
            cout << (char) (i + 97) << ": " << htab[i] << " x times" << endl;
        }
    }

}

//find duplicate using bit operation
void findDup2(char *s){
    int bit = 0, x = 0;
    for(int i = 0; s[i] != '\0'; i++){
        x = 1;
        x = x << (s[i] - 97); 
        if((x & bit) > 0){
            cout << "Duplicate: " << s[i] << endl;
        }else{
            bit = x | bit;
        }
    }
}

//consider lowercase only
//doesn't care about repeats
void checkAnagram(char *a, char *b){
    int aBit = 0, x = 0;
    int bBit = 0;
    for(int i = 0; a[i] != '\0'; i++){
        x = 1;
        x = x << (a[i] - 97);
        if((x & aBit) != 1)
            aBit = aBit | x;
    }

    for(int i = 0; b[i] != '\0'; i++){
        x = 1;
        x = x << (b[i] - 97);
        if((x & bBit) != 1)
            bBit = bBit | x;
    }
    if(aBit == bBit)  
        cout << "It is an anagram" << endl;
    else 
        cout << "It is not an anagram" << endl;


}

//take repeating into consideration
void checkAnagram2(char *a, char *b){
    int hash[26] = {0};
    for(int i = 0; a[i] != '\0'; i++){
        hash[a[i]-97]++;
    }
    for(int i = 0; b[i] != '\0'; i++){
        hash[b[i]-97]--;
        if(hash[b[i] - 97] < 0){
            cout << "Not an anagram" << endl;
            return;
        }
    }
    cout << "anagram" << endl;
}

void permutation(char *s, int k){
    static int f[10] = {0};
    static char res[10];
    int i;
    if(s[k] == '\0'){
        res[k] == '\0';
        cout << res << endl;
    }else{
        for(i = 0; s[i] != '\0'; i++){
            if(f[i] == 0){
                res[k] = s[i];
                f[i] = 1;
                permutation(s, k+1);
                f[i] = 0;
            }

        }
    }
}


int main(){
    char name[] = "thangsuan";
    char name2[] = "thrngsuan";
    cout << (palindrome(name) ? "Palindrome" : "Not Palindrome") << endl;
    checkAnagram2(name, name2);
    char perm[] = "abc";
    permutation(perm, 0);
    return 0;
}
