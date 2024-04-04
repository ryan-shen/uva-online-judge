import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			int row = input.nextInt();
			int col = input.nextInt();
			if(row == 0 && col == 0) break;
			int[] rowCount = new int[21];
			int[] colCount = new int[21];
			for(int i=0; i<row; i++) {
				int n = input.nextInt();
				rowCount[n]++;
			}
			for(int i=0; i<col; i++) {
				int n = input.nextInt();
				colCount[n]++;
			}
			int total = 0;
			for(int i=1; i<=20; i++)
				total += Math.max(rowCount[i], colCount[i]) * i;
			System.out.println(total);		
		}
	}

}
