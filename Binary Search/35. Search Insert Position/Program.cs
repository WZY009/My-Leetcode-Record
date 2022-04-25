using System;

namespace _35._Search_Insert_Position
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = { 1,2,3,4,5,6,7 };
            Console.WriteLine(SearchInsert(numbers,5));
        }
        public static int SearchInsert(int[] nums, int target)
        {
            //use binary search to find to correct position 
            //firstly we should locate the middle of the array      
            int left = 0;
            int right = nums.Length;//set up left and right index to check whether it is equal or not
            int middle = (left + right) / 2;
            while (true)
            {
                if (nums[middle] == target || left == right)
                    return middle;
                if (nums[0] > target)
                    return left;
                if (nums[nums.Length-1] < target)
                    return nums.Length;
                else
                {
                    if (nums[middle] > target)
                        right = middle;
                    else
                        left = middle;
                    middle = (right + left) / 2;
                }
            }

        }
    }
}
