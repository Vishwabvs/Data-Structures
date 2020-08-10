// leetcode answer for pascals traingle
// https://leetcode.com/problems/pascals-triangle/

//This function returns a 2D Vector containing pascals triangle
vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        
        if(numRows == 0)
            return result;
        
        vector<int> curr;
        curr.push_back(1);
        result.push_back(curr);
        for(int i=1;i<numRows;i++)
        {
            curr.clear();
            curr.push_back(1);
            for(int j=1;j<i;j++)
            {
                curr.push_back(result[i-1][j-1] + result[i-1][j]);                  
            }
            curr.push_back(1);
            result.push_back(curr);
        }
        return result;
    }
