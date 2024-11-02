
class Solution {
public:
    bool isCircularSentence(string sentence) {
      
         int first=sentence[0];
        int last=sentence[sentence.length()-1];
        
        vector<pair<char,char>>arr;
        arr.push_back(make_pair(first,last));
        
    for(int i=0;i<sentence.length();i++){
        if(sentence[i]==' '){
            arr.push_back(make_pair(sentence[i-1],sentence[i+1]));
        }
    }
      
        
        for(int i=0;i<arr.size();i++){
            if(arr[i].first !=arr[i].second){
                return false;
            }
        }
        
        return true;
        
    }
};