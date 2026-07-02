class Solution {
public:
    int leftFinder(vector<int>&main , vector<int>&dup , int lo , int hi , int med){
        if(main.size() == 0)return 0;
        if(lo == hi){
            int r = med - lo - 1;
            if(r + 1 < dup.size() && main[lo] > dup[r + 1])return 0;
            return main[lo];
        }
        int mid = (lo + hi) / 2;
        if(mid >= med)return leftFinder(main , dup , lo , mid , med);
        int rem = med - mid - 1;
        if(rem >= dup.size())return leftFinder(main , dup , mid + 1 , hi , med);
        if(dup[rem] <= main[mid]) return leftFinder(main , dup , lo , mid , med);
        return leftFinder(main , dup , mid + 1 , hi , med);
    }   
    int leftFinder(vector<int>&num1 , vector<int>&num2 , int med){
        int one = leftFinder(num1 , num2 , 0 , num1.size() - 1 , med);
        int two = leftFinder(num2 , num1 , 0 , num2.size() - 1 , med);
        return max(one , two);
    } 
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int med = (num1.size() + num2.size());
        if(med % 2 == 1){
            return leftFinder(num1 , num2 , med / 2);
        }
        return ((leftFinder(num1 , num2 , med / 2) + leftFinder(num1 , num2 , (med / 2) - 1)) * 1.00 / 2);
       
    }
};
