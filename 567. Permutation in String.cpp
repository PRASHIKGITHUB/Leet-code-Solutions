class Solution
{
public:
    bool CheckEqual(int a[26],int b[26])
    {
        int i = 0;
        while (i < 26)
        {
            if (a[i] != b[i])
            {
                return 0;
            }
            i++;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2)
    {
        int count1[26] = {0};
        int i = 0;
        while (i < s1.length())
        {
            int index = s1[i] - 'a';
            count1[index]++;
            i++;
        }
        //traverse s2 string in window of size of s1 length and compare
        // running for first window
        int j = 0;
        int windowSize = s1.length();
        int count2[26] = {0};
        while (j < windowSize && j<s2.length())  //j<s2.length() if for if s2 is less than s1;
        {
            int index = s2[j] - 'a';
            count2[index]++;
            j++;
        }

        if (CheckEqual(count1, count2))
        {
            return 1;
        }

        // aage wali windows
        while (j < s2.length())
        {
            char newChar = s2[j];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[j - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            j++;
            if (CheckEqual(count1, count2))
            {
                return 1;
            }
        }
        return 0;
    }
};