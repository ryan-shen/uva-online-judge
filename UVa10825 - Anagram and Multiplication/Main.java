import java.util.*;
public class Main {

	static int m;
	static int n;
	static int[] num;
	static int[][] permute;
	static int permuteIndex;
	static int[] numCount;
	static int[] tempNumCount;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			m = input.nextInt();
			n = input.nextInt();
			if(m == 0 && n == 0) break;
			
			boolean pass = false;
			for(int i=1; i<n; i++) {
				num = new int[m+1];
				numCount = new int[n];
				permute = new int[Factorial(m-1)+1][m+1];
				for(int j=1; j<=m; j++) {
					num[j] = i * j % n;
					numCount[num[j]]++;
				}
				permuteIndex = 1;
				Permutation(2,m);
				permuteIndex = 1;
				while(permuteIndex < permute.length) {
					if(check()) {
						pass = true;
						break;
					}
					permuteIndex++;
				}
				if(pass)
					break;
			}
			
			if(pass) 
				for(int i=m; i>0; i--) {
					if(i == 1)
						System.out.print(permute[permuteIndex][i]);
					else
						System.out.print(permute[permuteIndex][i] + " ");
				}	
			else
				System.out.print("Not found.");
			System.out.println();
		}
	}
	public static boolean check() {
		for(int i=2; i<=m; i++) {
			tempNumCount = new int[n];
			int temp = 0;
			for(int j=1; j<=m; j++) {
				temp += permute[permuteIndex][j] * i;
				int digit = temp % n;
				if(++tempNumCount[digit] > numCount[digit]) {
					return false;
				}
				temp /= n;
			}
			if(temp != 0) 
				return false;
		}
		return true;
	}
	public static void Permutation(int from, int to) {
		if(from == to) {
			for(int i=1; i<=m; i++)
				permute[permuteIndex][i] = num[i];
			permuteIndex++;
		}
		for(int i=from; i<=to; i++) {
			Swap(from, i);
			Permutation(from+1, to);
			Swap(from, i);
		}
	}
	public static void Swap(int a, int b) {
		int temp = num[a];
		num[a] = num[b];
		num[b] = temp;
	}
	public static int Factorial(int x) {
		int sum = 1;
		while(x > 1) {
			sum *= x;
			x--;
		}
		return sum;
	}
}
