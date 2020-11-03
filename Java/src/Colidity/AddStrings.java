package Colidity;

public class AddStrings {

    class Solution {
        public String addStrings(String num1, String num2) {
            StringBuilder res = new StringBuilder();
            int i = num1.length() - 1;
            int j = num2.length() -1;

            int carry = 0;
            while(i>=0 && j>=0){
                int here = num1.charAt(i--) - '0' + num2.charAt(j--) - '0' + carry;
                carry = here / 10;
                here %= 10;
                res.append(here);
            }
            while(i>=0){
                int here = num1.charAt(i--) - '0'+ carry;
                carry = here / 10;
                here %= 10;
                res.append(here);
            }
            while(j>=0){
                int here = num2.charAt(j--) - '0' + carry;
                carry = here / 10;
                here %= 10;
                res.append(here);
            }

            if(carry != 0)
                res.append((char)(carry + '0'));

            return res.reverse().toString();
        }
    }
}
