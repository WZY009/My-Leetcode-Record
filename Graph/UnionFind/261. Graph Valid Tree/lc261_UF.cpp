// 2022 6.7 18:52
// 2022 6.7 19:07
class UF{
 private:
    int count;
    int* rank;
    int* parent;

public: 
    UF(int n) {
        count = n;
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    ~UF() {
        delete [] rank;
        delete [] parent;
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
    bool getConnected(int p, int q) {
        return find(p) == find(q);
    }
};
class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        UF* uf = new UF(n);
        for(const vector<int>& edge : edges) {
            if(!uf->getConnected(edge[0], edge[1])) uf->unionUF(edge[0], edge[1]);
            else return false;
        }
        if(uf->getCount() != 1) return false;
        return true;
    }
};