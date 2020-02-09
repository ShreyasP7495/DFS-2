//single stack Solution
//Time Complexity-O(n)
//Space Complexity-O(n)
// Did the code execute on Leetcode? Yes

class Solution {
public:
    string decodeString(string s) {
        string res="";
        stack<char>m;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=']')
            {
                m.push(s[i]);
            }
            else
            {
                string curr="";
                while(m.top()!='[' && isalpha(m.top()))
                {
                    curr=m.top()+curr;
                    m.pop();
                }
                m.pop();
                string temp="";
                while(!m.empty() && isdigit(m.top()))
                {
                    temp=m.top()+temp;
                    m.pop();
                }
                int a=stoi(temp);
                while(a!=0)
                {
                    for(int i=0;i<curr.length();i++)
                    {
                        m.push(curr[i]);
                    }
                    a--;
                }
            }
        }
        while(!m.empty())
        {
            res=m.top()+res;
            m.pop();
        }
        return res;
    }
};