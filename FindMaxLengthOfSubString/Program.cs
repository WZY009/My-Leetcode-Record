using System;
using System.Collections;

namespace FindMaxLengthOfSubString
{
    class Program
    {
        static public int LengthOfLongestSubstring1(string s)
        {
            int subLength = 0;
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = i; j < s.Length; j++)
                {
                    if (NotRepeated(s, i, j))
                        subLength = Math.Max(subLength, j - i + 1);
                }
            }
            return subLength;
        }
        static public bool NotRepeated(string s, int start, int end)
        {
            int[] chars = new int[128];
            for (int i = start; i <= end; i++)
            {
                char letter = s[i];
                chars[letter] = chars[letter]+ 1;
                if (chars[letter] > 1)
                    return false;
            }
            return true;
        }

        static public int LengthOfLongestSubstring2(string s)
        {
            int answer = 0;
            for(int i = 0; i < s.Length; ++i)
            {
                int[] seen = new int[128];
                int j = i;
                while(j<s.Length && IsSeen(seen[s[j]]))                
                    seen[Convert.ToInt32(s[j++])]++;               
                answer = Math.Max(answer, j - i);
            }
            return answer;
        }
        static public bool IsSeen (int a)
        {
            if (a == 0)
                return true;
            else
                return false;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(LengthOfLongestSubstring2("abcabcbb"));
            //Console.WriteLine(IsSeen(2));
            Console.Read();
        }

    }
}

