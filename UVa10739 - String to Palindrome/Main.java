import java.util.*;
public class Main {
	static int[][] arr;
	static String s;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for(int k=1; k<=test; k++) {
			s = input.next();
			arr = new int[s.length()][s.length()];
			for(int i=0; i<s.length(); i++) Arrays.fill(arr[i], -1);
			for(int i=0; i<s.length(); i++) {
				arr[i][i] = 0;
			}
			for(int i=0; i<s.length()-1; i++) {
				if(s.charAt(i) == s.charAt(i+1)) arr[i][i+1] = 0;
				else arr[i][i+1] = 1;
			}
			
			System.out.println("Case " + k + ": " + dp(0,s.length()-1));
		}
	}
	
	public static int dp(int start, int end) {
		if(start > end) return Integer.MAX_VALUE;
		if(arr[start][end] == -1) {
			if(s.charAt(start) == s.charAt(end)) return dp(start+1, end-1);
			arr[start][end] = Math.min(Math.min(dp(start+1, end), dp(start, end-1)), dp(start+1, end-1)) + 1;
		}
		return arr[start][end];

	}

}
