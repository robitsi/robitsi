class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int rowIndex = 0;

        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int val : mat[i]) {
                count += val; // since values are 0 or 1
            }

            if (count > maxOnes) {
                maxOnes = count;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};
