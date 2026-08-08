class Solution {
public:
    vector<int>piles;
    int parbe(int mid , int h){
        int cnt = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            cnt += ((piles[i] + mid - 1) / mid);
            if(cnt > h)return 0;
        }
       
        return 1;
    }
    int bin(int lo , int hi , int h){
        if(lo == hi)return lo;
        int mid = lo + (hi - lo) / 2;
        if(parbe(mid , h))return bin(lo , mid , h);
        return bin(mid + 1 , hi , h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles = piles;
        return bin(1 , 1e9 , h);
    }
};
