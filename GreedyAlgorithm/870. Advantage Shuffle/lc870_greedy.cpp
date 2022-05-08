class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        pair<int, int> arr[B.size()];
        //record the position of B
        for(int i = 0; i < B.size(); i++)
            arr[i] = {B[i], i};
        sort(arr, arr + B.size()); // sort the arr via arr[i].first
        sort(A.begin(), A.end());
        // C is the answer
        vector<int> C(A.size(), -1), tmp;
        int pos = 0;
        for(int i = 0; i < B.size(); i++){
            //if A[pos] is smaller than B[i], push all of them into tmp
            while(pos < A.size() && A[pos] <= arr[i].first)
                tmp.push_back(A[pos++]);
            if(pos == A.size())
                break;
            // When A meet B[i], it can send out A[pos] to compare with.
            C[arr[i].second] = A[pos++];
        }
        for(int i = 0; i < B.size(); i ++){
            if(C[i] == -1){
                C[i] = tmp.back();
                tmp.pop_back();
            }
        }
        return C;
    }
};