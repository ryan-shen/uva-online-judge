import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			String s = input.next();
			String t = input.next();
			int sIndex = 0;
			int tIndex = 0;
			boolean pass = true;
			while(sIndex < s.length()) {
				if(s.charAt(sIndex) == t.charAt(tIndex))
					sIndex++;
				if(++tIndex == t.length() && sIndex != s.length()) {
					pass = false;
					break;
				}
			}
			if(pass) 
				System.out.println("Yes");
			else
				System.out.println("No");
		}

	}

}
