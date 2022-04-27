//2022 4.27 21:57
class Difference{
public:
    vector<int> diff;
    Difference(int length) {
        diff = vector<int>(length, 0);
    }
    
    void operation(int left, int right, int val) {
        diff[left] += val;
        if(right + 1 < diff.size()) diff[right + 1] -= val; // don't forget plus 1!
    }
    
    void integral() {
        for(int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
    }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        Difference* Diff = new Difference(n);
        for(int i = 0; i < bookings.size(); i++) {
            Diff->operation(bookings[i][0] - 1, bookings[i][1] - 1, bookings[i][2]);
        }
        Diff->integral();
        return Diff->diff;
    }
};