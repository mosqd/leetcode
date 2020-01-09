/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
 */

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows || numRows == 1) {
            return s;
        }
        int d = (numRows - 1) * 2;
        string ans(n, '\0');
        int j = 0;
        int len = d-2;
        int k = 0;
        int i = 0;
        for (i = 0; i < n; i+=d) {
            ans[k++] = s[i];
        }
        for (i = 1; i < numRows-1; i++) {
            ans[k++] = s[i];
            j = i;
            while (j+len < n) {
                ans[k++] = s[j+len];
                if (j+d < n) {
                    ans[k++] = s[j+d];
                } else {
                    break;
                }

                j += d;
            }
            len -= 2;
        }
        for (i = numRows-1; i < n; i+=d) {
            ans[k++] = s[i];
        }
        return ans;
    }
};

/**
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows || numRows == 1) {
            return s;
        }
        int cols = (n / (numRows*2-2)) * (numRows - 1);
        int tmp = n % (numRows*2-2);
        if (tmp > 0) {
            cols++;
            if (tmp > numRows) {
                cols += tmp - numRows;
            }
        }
        vector<char> v(cols, '\0');
        vector<vector<char> > vv(numRows, v);
        int downIndex = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < numRows && j < cols && k < n) {
            for (i = 0; i < numRows && k < n; i++) {
                vv[i][j] = s[k++];
            }
            if (k == n) {
                break;
            }
            i -= 2;
            j++;
            for (; i > 0 && k < n; i--, j++) {
                vv[i][j] = s[k++];
            }
        }
        k = 0;
        for (i = 0; i < numRows; i++) {
            for (j = 0; j < cols; j++) {
                if (vv[i][j] != '\0') {
                    s[k++] = vv[i][j];
                }
            }
        }
        return s;
    }
};
*/
