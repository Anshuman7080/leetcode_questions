class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int,pair<bool,int>>mapi;
        
        for(int i=0;i<arr.size();i++){
            mapi[arr[i]]={true,i};
        }
        
        
        for(int i=0;i<arr.size();i++){
            if(mapi[2*arr[i]].first &&  mapi[2*arr[i]].second!=i){
                return true;
            }
        }
        return false;
        
    }
};