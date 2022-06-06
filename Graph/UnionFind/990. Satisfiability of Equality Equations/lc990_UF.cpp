// 2022 6.6 16：27(After viewing the answer!)
// 2022 6.6 16:38 (Work out with one WA)
class UF{
private:
    int count;
    int* rank;
    int* parent;
public:
    UF(int n) {
        count = n;
        rank = new int[n];
        parent = new int[n];
        for(int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    ~UF() {
        delete [] parent;
        delete [] rank;
    }
    int find(int p) {
        if(parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }
    void unionUF(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        if(rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else if(rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else {
            parent[rootP] = rootQ;
            rank[rootQ]++;
        }
        count--;
    }
    int getCount() {
        return count;
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF* uf = new UF(26);
        for(const string& s : equations) {
            if(s[1] == '=') {
                uf->unionUF(s[0] - 'a', s[3] - 'a');
            }
            else {
                if(uf->isConnected(s[0] - 'a', s[3] - 'a')) return false;
            }
        }
        // if the test example is ["a==b","b!=c","c==a"], you have to check the unequal relationship again!
        for(const string& s : equations) {
            if(s[1] == '!') {
                if(uf->isConnected(s[0] - 'a', s[3] - 'a')) return false;
            }
        }
        return true;
    }
};