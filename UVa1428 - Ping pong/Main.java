import java.util.*;
public class Main {
	static int[] bit = new int[100005];
	static int n;
	static int maxValue;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while(test-- > 0) {
			n = input.nextInt();
			int[] arr = new int[n+1];
			int[] lx = new int[n+1];
			int[] rx = new int[n+1];
			maxValue = 100005;
			for(int i=1; i<=n; i++) {
				arr[i] = input.nextInt();
				maxValue = Math.max(maxValue, arr[i]);
			}
			Arrays.fill(bit, 0);
			for(int i=1; i<=n; i++) {
				add(arr[i], 1);
				lx[i] = sum(arr[i] - 1);
				//System.out.println("lx[" + i + "] = " + lx[i]);
			}
			Arrays.fill(bit, 0);
			for(int i=n; i>0; i--) {
				add(arr[i], 1);
				rx[i] = sum(arr[i] - 1);
				//System.out.println("rx[" + i + "] = " + rx[i]);
			}
			long total = 0;
			for(int i=1; i<=n; i++) {
				total += lx[i] * (n - i - rx[i]) + (i - 1 - lx[i]) * rx[i];
				//System.out.println(lx[i] * (n - i - rx[i]) + (i - 1 - lx[i]) * rx[i]);
			}
			System.out.println(total);
		}

	}
	
	public static void add(int x, int d) {
		while(x <= maxValue) {
			bit[x] += d;
			x += lowbit(x);
		}
	}
	
	public static int sum(int x) {
		int total = 0;
		while(x > 0) {
			total += bit[x];
			x -= lowbit(x);
		}
		return total;
	}
	
	public static int lowbit(int x) {
		return x & (-x);
	}

}
