class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        vector<int>sum_list;
        bool result = false;
        
        while ( true ) {
            while ( n != 0 ) {
                int n_ = n % 10;
                sum += n_ * n_;
                n = n / 10;
            }
            
            if ( sum == 1 ) {
                result = true;
                break;
            }
            auto itr = find(sum_list.begin(), sum_list.end(), sum);
            if (itr != sum_list.end()) {
                result = false;
                break;
            }
            sum_list.push_back(sum);
            n = sum;
            sum = 0;
        }
        return result;
    }
};
