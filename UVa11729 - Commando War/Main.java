import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int count = 1;
		while(true) {
			int n = input.nextInt();
			if(n == 0) break;
			int[] B = new int[n];
			int[] J = new int[n];
			for(int i=0; i<n; i++) {
				B[i] = input.nextInt();
				J[i] = input.nextInt();
			}
			for(int i=0; i<n-1; i++) {
				for(int j=i+1; j<n; j++) {
					if(J[i] < J[j]) {
						int temp = B[i];
						B[i] = B[j];
						B[j] = temp;
						temp = J[i];
						J[i] = J[j];
						J[j] = temp;
					}
				}
			}
			int timeline = 0;
			int baseline = 0;
			for(int i=0; i<n; i++) {
				if(baseline + B[i] + J[i] > timeline) {
					timeline = baseline + B[i] + J[i];
				}
				baseline += B[i];
			}
			System.out.println("Case " + count + ": " + timeline);
			count++;
		}
	}

}
