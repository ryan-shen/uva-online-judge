import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int n = input.nextInt();
			long[] arr = new long[n+1];
			long sum = 0;
			for(int i=1; i<=n; i++) {
				arr[i] = input.nextInt();
				sum += arr[i];
			}
			long avg = sum / n;
			long[] x = new long[n+1];
			long[] c = new long[n];
			c[0] = 0;
			for(int i=1; i<n; i++) {
				c[i] = c[i-1] + arr[i] - avg;
			}
			long[] temp = new long[n+1];
			System.arraycopy(c, 0, temp, 0, n);
			Arrays.sort(temp, 0, n);
			x[1] = temp[n / 2];
			sum = 0;
			for(int i=1; i<=n; i++) {
				x[i] = x[1] - c[i-1];
				sum += Math.abs(x[i]);
			}
			System.out.println(sum);
			
		}

	}

}
