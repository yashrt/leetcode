class Solution {
public:
    int helper(vector<int>& A, vector<int>& B, int num) {
        int countA = 0, countB = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if(A[i] != num && B[i] != num)
                return -1;
            
            if(A[i] != num)
                countA++;
            
            if(B[i] != num)
                countB++;
        }
        return min(countA, countB);
        
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res1 = helper(A, B, A[0]);
        int res2 = helper(A, B, B[0]);
        
        if( res1 == -1 && res2 == -1)
            return -1;
        else if (res1 != -1 && res2 != -1)
            return min(res1, res2);
        else if( res1 != -1 && res2 == -1)
            return res1;
        else
            return res2;
    }
};
