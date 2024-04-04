import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(true) {
			int n = input.nextInt();
			int m = input.nextInt();
			if(n == 0 && m == 0) break;
			int[] arr1 = new int[n];
			int[] arr2 = new int[m];
			for(int i=0; i<n; i++) arr1[i] = input.nextInt();
			for(int i=0; i<m; i++) arr2[i] = input.nextInt();
			if(n > m) {
				System.out.println("Loowater is doomed!");
				continue;
			}
			Arrays.sort(arr1);
			Arrays.sort(arr2);
			int sum = 0;
			int i = 0;
			int j = 0;
			while(i < n && j < m) {
				if(arr1[i] <= arr2[j]) {
					sum += arr2[j];
					i++;
					j++;
				}
				else j++;
			}
			if(i >= n) System.out.println(sum);
			else System.out.println("Loowater is doomed!");
		}
		
	}

}
