import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			int n = input.nextInt();
			if(n == 0) break;
			int[] arr = new int[n];
			for(int i=0; i<n; i++) {
				arr[i] = input.nextInt();
			}
			
			int[] x = new int[n];
			x[0] = 0;
			for(int i=1; i<n; i++) {
				x[i] = x[i-1] + arr[i-1];
			}
			
			long sum = 0;
			for(int i=1; i<n; i++) {
				sum += Math.abs(x[i]);
			}
			System.out.println(sum);
		}
		
	}

}
