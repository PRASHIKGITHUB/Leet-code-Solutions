class Solution
{
public:
    string removeDuplicates(string s)
    {
        while (s.length() != 0)
        {

            bool flag = true;
            for (int i = 0; i < s.length() - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    s.erase(i, 2);
                    if (s.size() == 0)
                    {
                        return s;
                    }
                    flag = false;
                    i--;
                }
            }
            if (flag == true)
            {
                return s;
            }
        }

        return s;
    }
};