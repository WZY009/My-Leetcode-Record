class UF{
private:
    int count;
    int number;
    int* parent;
    int* rank;
public:
    UF(int n) {
        count = n;
        number = n;
        rank = new int[n];
        parent = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    ~UF(){
        delete [] parent;
        delete [] rank;
    }
    
    int find(int p) {
        if(p < 0 || p >= number) return -1; 
        if(parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }
    
    void unionUF(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        if(rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if(rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }
    
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    
    int getCount() {
        return count;
    }
    
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF* uf = new UF(n);
        for(vector<int> edge : edges) {
            uf->unionUF(edge[0], edge[1]);
        }
        return uf->getCount();
    }
};