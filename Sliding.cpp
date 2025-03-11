//3206. Alternating Groups I
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[(i+1)%n] && colors[(i+1)%n]!=colors[(i+2)%n]){
                cnt++;
            }
        }

        return cnt;
    }
};

//3208. Alternating Groups II

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]); //to handle wrap around (circular array)
        }

        int result = 0;
        int i = 0;
        int j = 1; //because we have to check index j-1 for checking alterate
        while(j < N) {
            if(colors[j] == colors[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};

//2379. Minimum Recolors to Get K Consecutive Black Blocks

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;

        int ops = k;
        int W = 0;

        while(j < n) {
            if(blocks[j] == 'W') {
                W++;
            }

            if(j - i + 1 == k) {
                ops = min(ops, W);

                if(blocks[i] == 'W') {
                    W--;
                }
                i++;
            }
            j++;
        }

        return ops;
    }
};

//1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int result=0;
        unordered_map<int,int>mp;
        int i=0;
        int j=0;

        while(j<=n){
            char ch=s[j];
            mp[ch]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                result+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }

        return result;
    }
};
