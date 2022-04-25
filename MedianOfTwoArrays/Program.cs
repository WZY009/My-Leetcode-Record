using System;

namespace MedianOfTwoArrays
{
    class Program
    {
        public static double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int[] num = new int[nums1.Length + nums2.Length];
            MakeList(num, nums1, nums2);
            if (num.Length % 2 == 1)
            {
                return (double)num[(num.Length - 1) / 2];
            }
            else
                return (double)(num[(num.Length - 1) / 2] + num[(num.Length - 1) / 2 + 1]) / 2;

        }
        public static void MakeList(int[] num, int[] nums1, int[] nums2)
        {
            int i = 0, j = 0;
            int k = 0;
            while (i < nums1.Length && j < nums2.Length)
            {
                if (nums1[i] <= nums2[j])
                {
                    num[k] = nums1[i];
                    i++;
                    k++;
                }
                else
                {
                    num[k] = nums2[j];
                    j++;
                    k++;
                }
            }
            if (i == nums1.Length  && j != nums2.Length )
            {
                while (j < nums2.Length)
                {
                    num[k] = nums2[j];
                    j++;
                    k++;
                }
            }
            else if (j == nums2.Length  && i != nums1.Length )
            {
                while (i < nums1.Length)
                {
                    num[k] = nums1[i];
                    i++;
                    k++;
                }
            }
        }
        static void Main(string[] args)
        {
            int[] array1 = {1,2};
            int[] array2 = {3,4};
            Console.WriteLine(FindMedianSortedArrays(array1,array2));
        }
    }
}
