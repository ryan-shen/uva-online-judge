import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			int n = input.nextInt();
			int d = input.nextInt();
			int r = input.nextInt();
			if(n == 0 && d == 0 && r == 0) break;
			int[] arr1 = new int[n];
			int[] arr2 = new int[n];
			for(int i=0; i<n; i++) arr1[i] = input.nextInt();
			for(int i=0; i<n; i++) arr2[i] = -input.nextInt();
			
			Arrays.sort(arr1,0,n);
			Arrays.sort(arr2,0,n);
			
			int sum = 0;
			for(int i=0; i<n; i++) {
				int temp = arr1[i] - arr2[i];
				if(temp > d) {
					sum += (temp - d) * r;
				}
			}
			System.out.println(sum);
		}
		

	}

}
