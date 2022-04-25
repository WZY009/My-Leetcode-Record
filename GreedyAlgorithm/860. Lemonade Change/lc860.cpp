class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBalance = 0;
        int tenBalance = 0;
        for(int i = 0; i < bills.size(); i++) {
            switch (bills[i]) {
                case 5 : 
                    fiveBalance++;
                    break;
                case 10:
                    tenBalance++;
                    if(fiveBalance > 0) 
                        fiveBalance--;                    
                    else return false;
                    break;
                case 20:
                    if(tenBalance > 0 && fiveBalance > 0) {
                        tenBalance--;
                        fiveBalance--;
                    }
                    else if(fiveBalance > 2) {
                        fiveBalance -=3;
                    }
                    else return false;
                    break;
            }
             
        }
        return true;
    }
};