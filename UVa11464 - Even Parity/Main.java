import java.util.*;
public class Main {
	static int[][] arr1 = new int[16][16];
	static int[][] arr2 = new int[16][16];
	static int maxValue = 10000;
	static int n;
	static int minValue;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for(int k=1; k<=test; k++) {
			n = input.nextInt();
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					arr1[i][j] = input.nextInt();
				}
			}
			minValue = maxValue;
			for(int i=0; i<Math.pow(2, n); i++)
				minValue = Math.min(minValue, check(i));
			System.out.print("Case " + k + ": ");
			if(minValue == maxValue) System.out.println(-1);
			else System.out.println(minValue);
		}
	}
	
	public static int check(int num){
		for(int c=0; c<n; c++) {
			if((num & (1<<c)) == (1<<c)) arr2[0][c] = 1;
			else{
				if(arr1[0][c] == 0) arr2[0][c] = 0;
				else return maxValue;
			}
		}
		for(int i=1; i<n; i++) {
			for(int j=0; j<n; j++) {
				int sum = 0;
				if(i > 1) sum += arr2[i-2][j];
				if(j > 0) sum += arr2[i-1][j-1];
				if(j < n-1) sum += arr2[i-1][j+1];
				arr2[i][j] = sum % 2;
				if(arr1[i][j] == 1 && arr2[i][j] == 0) return maxValue;
			}
		}
		int count = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr1[i][j] == 0 && arr2[i][j] == 1) count++;
			}
		}
		return count;
	}

}
