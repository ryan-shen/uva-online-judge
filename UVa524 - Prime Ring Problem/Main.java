import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = 1;
		while(input.hasNext()) {
			int n = input.nextInt();
			int[] arr = new int[n+1];
			arr[1] = 1;
			if(t > 1) System.out.println();
			System.out.println("Case " + (t++) + ":");
			func(n, 2, arr);
		}
	}
	
	public static void func(int n, int layer, int arr[]) {
		if(layer > n) return;
		for(int i=2; i<=n; i++) {
			int sameFlag = 0;
			
			arr[layer] = i;
			if(!isPrime(arr[layer] + arr[layer-1])) continue;
			if(layer == n) {
				if(!isPrime(arr[layer] + arr[1])) continue;
			}
			for(int j=1; j<layer; j++) {
				if(arr[j] == arr[layer]) {
					sameFlag = 1;
					break;
				};
			}
			if(sameFlag == 1) continue;
			func(n, layer+1, arr);
			if(layer == n) {
				for(int j=1; j<=n; j++) {
					if(j == 1) System.out.print(arr[j]);
					else System.out.print(" " + arr[j]);
				}
				System.out.println();
			}
		}
	}
	
	public static boolean isPrime(int x) {
		for(int i=2; i<=Math.sqrt(x); i++) {
			if(x % i == 0) return false;
		}
		return true;
	}

}
