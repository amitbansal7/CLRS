/*

	Find subarray with maximum sum.
	Time complexity :O(n*logn)

*/
import java.util.*;
public class MaximumSubarray {

	public static int[] find_max_crossing_subarray(int[] A, int lo, int mid,int hi)
	{
		int left_sum = -1000000;
		int sum = 0;
		int max_left = 0;

		for(int i=mid;i>=lo;i--)
		{
			sum += A[i];
			if(sum > left_sum)
			{
				left_sum = sum;
				max_left = i;
			}
		}
		int right_sum = -1000000;
		int max_right = 0;
		sum = 0;
		for(int i=mid+1;i<hi;i++)
		{
			sum += A[i];
			if(sum > right_sum)
			{
				right_sum = sum;
				max_right = i;
			}
		}
		return new int[]{max_left, max_right, right_sum + left_sum};
	}

	public static int[] find_maximum_subarray(int[] A, int lo, int hi)
	{
		if(lo==hi)
			return new int[]{lo, hi, A[lo]};

		int mid = (lo+hi)/2;

		int[] left = find_maximum_subarray(A, lo, mid);
		int[] right = find_maximum_subarray(A, mid+1, hi);
		int[] cross = find_max_crossing_subarray(A, lo, mid, hi);

		if(left[2] >= right[2] && left[2] >= cross[2])
			return left;
		else if(right[2] >= left[2] && right[2] >= cross[2])
			return right;
		else
			return cross;
	}

	public static void main(String[] args) {
		int[] A = new int[] {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,-7};

		int[] res = find_maximum_subarray(A, 0, A.length-1);

		System.out.printf("Maximum subarray is %d, from index %d to %d.\n", res[2], res[0], res[1]);
	}

}
