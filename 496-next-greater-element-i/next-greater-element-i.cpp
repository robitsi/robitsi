class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;  
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge.count(num) ? nge[num] : -1);
        }

        return result;
        
    }
};